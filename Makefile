PROJECT_NAME			?= $(shell basename $(PWD))

STACK_SIZE				:= 1024
HEAP_SIZE				:= 2048

DEBUG_BUILD				:= true

HSE_VALUE				:= 8000000
LSE_VALUE				:= 32768

# GDB_SRV				[openocd,pyocd,jlink]
GDB_SRV					:= jlink

include project.mk