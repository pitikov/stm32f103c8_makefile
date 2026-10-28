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

BUILD_DIR 		    := $(PROJECT_DIR)/build
OBJ_DIR		    	:= $(BUILD_DIR)/.obj
DEST_DIR            := $(BUILD_DIR)/target

SRC_DIR  		    := $(PROJECT_DIR)/src

# -------------------------------------------------------------------------
# --------              Цели сборки проекта                         -------
# -------------------------------------------------------------------------

TARGET_ELF		    := $(DEST_DIR)/$(PROJECT_NAME).elf
TARGET_BIN		    := $(TARGET_ELF:.elf=.bin)
TARGET_MAP		    := $(TARGET_ELF:.elf=.map)

default: $(TARGET_ELF) $(TARGET_BIN)



# -------------------------------------------------------------------------
# --------              Правила сборки проекта                      -------
# -------------------------------------------------------------------------

.SILENT: $(DEST_DIR) $(OBJ_DIR)


$(TARGET_ELF): $(OBJECTS) $(DEST_DIR)
	$(ECHO) "Компановка $@ из ${OBJECTS}"
	$(LD) -o $@ $(OBJECTS) $(LD_FLAGS) $(LD_DEBUG) $(LD_LIBS) $(LD_DEFS)

$(DEST_DIR):
	$(MKDIR) $@

$(OBJ_DIR):
	$(MKDIR) $@
