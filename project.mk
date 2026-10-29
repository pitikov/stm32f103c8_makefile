# ----------------- binutils и используемые системные утилиты -----------------

BINUTILS			?= arm-none-eabi

CC					:= $(BINUTILS)-gcc
CXX					:= $(BINUTILS)-g++
LD					:= $(BINUTILS)-gcc
AS					:= $(BINUTILS)-as
OBJCOPY				:= $(BINUTILS)-objcopy
OBJDUMP				:= $(BINUTILS)-objdump

MKDIR				:= mkdir -p -m 0764
RM					:= rm -rf
ECHO				:= @echo

# ----------------- Каталоги проекта -----------------

PROJECT_DIR			:= $(dir $(lastword $(MAKEFILE_LIST)))

BUILD_DIR 		    := $(PROJECT_DIR)build
OBJ_DIR		    	:= $(BUILD_DIR)/.obj
DEST_DIR            := $(BUILD_DIR)/target

SRC_DIR  		    := $(PROJECT_DIR)src
CMSIS_DIR           := $(PROJECT_DIR)CMSIS

CORE_INC_DIR		:= $(CMSIS_DIR)/Core
DEVICE_DIR          := $(PROJECT_DIR)STM32F10x
DEVICE_INC_DIR		:= $(DEVICE_DIR)/Include
DEVICE_SRC_DIR      := $(DEVICE_INC_DIR:Include=Source)

# -------------------------------------------------------------------------
# --------              Цели сборки проекта                         -------
# -------------------------------------------------------------------------

TARGET_ELF		    := $(DEST_DIR)/$(PROJECT_NAME).elf
TARGET_BIN		    := $(TARGET_ELF:.elf=.bin)
TARGET_MAP		    := $(TARGET_ELF:.elf=.map)

OBJECTS             += $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%.o, $(wildcard $(SRC_DIR)/*.[c,cpp,S]))
OBJECTS				+= $(patsubst $(DEVICE_SRC_DIR)/%, $(OBJ_DIR)/%.o, $(wildcard $(DEVICE_SRC_DIR)/*.c))

default: $(TARGET_ELF) $(TARGET_BIN)

clean:
	$(ECHO) "Очистка проекта $(PROJECT_NAME)"
	$(RM) -Rf $(BUILD_DIR)

# -------------------------------------------------------------------------
# --------          Флаги архитектуры целевой платформы             -------
# -------------------------------------------------------------------------

ARCH				+= -mcpu=cortex-m3
ARCH				+= -mlittle-endian
ARCH				+= -march=armv7-m
ARCH				+= -mthumb
ARCH				+= -msoft-float

# -------------------------------------------------------------------------
# --------              Макроопределения компиляции                 -------
# -------------------------------------------------------------------------
ifeq ($(DEBUG_BUILD), true) 
C_DEFS				+= DEBUG
endif

C_DEFS				+= HSE_VALUE=$(HSE_VALUE)
C_DEFS				+= LSE_VALUE=$(LSE_VALUE)

C_DEFINES			= $(foreach d,$(C_DEFS),-D$d)

# -------------------------------------------------------------------------
# --------              Флаги компиляции C файлов                   -------
# -------------------------------------------------------------------------

C_FLAGS				+= -MD
C_FLAGS				+= $(ARCH)


# -------------------------------------------------------------------------
# --------                   Флаги компановщика                     -------
# -------------------------------------------------------------------------

LD_SCRIPT			:= $(DEVICE_INC_DIR:Include=Config)/stm32f103c8_gcc.ld

LD_FLAGS			+= $(ARCH)
LD_FLAGS			+= -Wl,-Map=$(TARGET_MAP)
LD_FLAGS			+= -Wl,-T$(LD_SCRIPT)

ifeq ($(DEBUG_BUILD), true)
LD_FLAGS			+= --specs=rdimon.specs
else
LD_FLAGS			+= --specs=nano.specs
endif

# -------------------------------------------------------------------------
# --------              Макроопределения компоновщика               -------
# -------------------------------------------------------------------------

LD_DEFINES			+= -Wl,--defsym=ROM_BASE=0x08000000
LD_DEFINES			+= -Wl,--defsym=RAM_SIZE=20K
LD_DEFINES			+= -Wl,--defsym=RAM_BASE=0x20000000
LD_DEFINES		    += -Wl,--defsym=ROM_SIZE=64K
LD_DEFINES			+= -Wl,--defsym=HEAP_SIZE=$(HEAP_SIZE)
LD_DEFINES			+= -Wl,--defsym=STACK_SIZE=$(STACK_SIZE)

# -------------------------------------------------------------------------
# --------          Каталоги поиска файлов декларации API           -------
# -------------------------------------------------------------------------

INCDIRS 			+= $(SRC_DIR)
INCDIRS				+= $(CORE_INC_DIR)
INCDIRS				+= $(DEVICE_INC_DIR)

INCLUDES			:= $(foreach i,$(INCDIRS),-I$i)

# -------------------------------------------------------------------------
# --------              Правила сборки проекта                      -------
# -------------------------------------------------------------------------

$(TARGET_BIN): $(TARGET_ELF)
	$(ECHO) "Бинарное копирование $< в $@"
	$(OBJCOPY) -Obinary $< $@

$(TARGET_ELF): $(OBJECTS) $(DEST_DIR)
	$(ECHO) "Компановка $@ из ${OBJECTS}"
	$(LD) -o $@ $(OBJECTS) $(LD_FLAGS) $(LD_DEBUG) $(LD_LIBS) $(LD_DEFINES)

$(OBJ_DIR)/%.c.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	$(ECHO) "Компиляция C-файла '$<' в объектный файл '$@'"
	$(CC) -c $< -o $@ $(C_FLAGS) $(C_DEFINES) $(C_DEBUG) $(INCLUDES)

$(OBJ_DIR)/%.c.o: $(DEVICE_SRC_DIR)/%.c $(OBJ_DIR)
	$(ECHO) "Компиляция C-файла '$<' в объектный файл '$@'"
	$(CC) -c $< -o $@ $(C_FLAGS) $(C_DEFINES) $(C_DEBUG) $(INCLUDES)

$(DEST_DIR):
	$(MKDIR) $@

$(OBJ_DIR):
	$(MKDIR) $@

include $(wildcard $(OBJ_DIR)/*.d)

.SILENT: $(DEST_DIR) $(OBJ_DIR)
.SILENT: clean

.PHONY: clean
.PHONY: erase