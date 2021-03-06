# This is a simple Makefile coordinating the build process of binaries in this
# project.
#
# This is configured to output build-specific files (including binaries) into
# files separate from the source paths, keeping the source tree clean:
#  - object files are created in $(BUILD_DIR), defined below
#  - binary files are created in $(BIN_DIR), defined below
# Those directories are created if they don't exist, and are deleted when
# running the make target.
#
# In order to test that you have a functioning C++ build toolchain, run:
# $> make hello
#
# In order to compile all binaries defined in this project, run:
# $> make all
#
# Cleanup build directories (including binaries) by running:
# $> make clean
#

# -----------------------------------------------------------------------------
#  Variable definitions

CC 					:= g++
LD      		:= g++

BUILD_DIR 	:= build/obj
BIN_DIR 		:= build
SRC_DIR  		:= src
CFLAGS 			:= -g -Wall -std=c++17

SRCS 				:= src/tripos.cpp src/query.cpp
# OBJS is generated from $(SRCS) by replacing the .cpp extension with .o:
OBJS 				:= $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
INCLUDES 		:= -Iinclude -Isrc

# -----------------------------------------------------------------------------
#  Make rules below, modify with care

vpath %.cpp $(SRC_DIR)

# this defines template rules for all object files
define make-goal
$1/%.o: %.cpp | checkdirs
	$(CC) $(INCLUDES) $(CFLAGS) -c $$< -o $$@
endef

# those rules are run irrespective if a file taking the name of the target
# (all, checkdirs, clean, ...) exists in the filesystem
.PHONY: all checkdirs clean hello query

# create build and binary directories
checkdirs: $(BUILD_DIR) $(BIN_DIR)
 
$(BUILD_DIR):
	@mkdir -p $@

$(BIN_DIR):
	@mkdir -p $@

# call this target to build everything
all: checkdirs $(BIN_DIR)/query $(BIN_DIR)/hello

# one-word binary targets for "hello" and "query"
hello: $(BIN_DIR)/hello
query: $(BIN_DIR)/query

# the following rule does both the compilation and the linking of the sample
# hello binary in a single command
$(BIN_DIR)/hello: src/hello.cpp | checkdirs
	$(CC) $(INCLUDES) $(CFLAGS) -o $@ $?

# for query, linking and compilation is done separately. Here is the linking,
# dependent on all the object files having been created by the rule generated by
# calling make-goal at the end of this makefile
$(BIN_DIR)/query: $(OBJS) | checkdirs
	$(LD) $(CFLAGS) -o $@ $^

# remove build traces, including binaries
clean:
	@rm -rf $(BUILD_DIR)
	@rm -rf $(BIN_DIR)

# compile sources to generate object files into $(BUILD_DIR)
$(foreach bdir,$(BUILD_DIR),$(eval $(call make-goal,$(bdir))))
