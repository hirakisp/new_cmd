CC      = gcc
CFLAGS  =
LDFLAGS =
LIBS    =
INCLUDE = -I ./include

SRC_ROOT = ./
OBJ_ROOT = ./obj
TARGET_DIR = ./

TARGET_NAME = $(notdir $(shell pwd)).exe

SRC_DIRS = $(shell find $(SRC_ROOT) -type d)
OBJ_DIRS = $(addprefix $(OBJROOT)/, $(SRC_DIRS))

SRCS = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))
OBJS = $(addprefix $(OBJ_ROOT)/, $(SRCS:.c=.o))
DEPENDS = $(patsubst %.o,%.d, $(OBJS))

TARGET = $(TARGET_DIR)/$(TARGET_NAME)

all:$(TARGET)

$(TARGET):$(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LIBS) $(INCLUDE)

$(OBJ_ROOT)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -rf $(OBJ_ROOT) $(TARGET_NAME)

.PHONY: all clean

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPENDS)
endif
