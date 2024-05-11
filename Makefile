.PHONY: clean

CXX_STD = -std=c++17
WARNINGS = -Wall -Wextra -Werror -Wpedantic -pedantic-errors
OPTIMIZE = -Og
DEBUG = -DDEBUG -g
LIB_DIR = lib
LIBS =
LIB_INCLUDES = -I${LIB_DIR}/include

EXEC_NAME = adventure
EXEC_DIR = bin
EXEC = ${EXEC_DIR}/${EXEC_NAME}
OBJ_DIR = obj
SRC_DIR = src

MAIN_OBJ = ${OBJ_DIR}/main.o
MAIN_SRC = ${SRC_DIR}/main.cxx

all: ${EXEC}

${EXEC_DIR}:
	mkdir -p ${EXEC_DIR}

${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

${EXEC}: ${MAIN_OBJ}
	${CXX} -o $@ $^

${MAIN_OBJ}: ${MAIN_SRC} ${OBJ_DIR}
	${CXX} -c -o $@ $< ${LIB_INCLUDES} ${CXX_STD} ${WARNINGS} ${OPTIMIZE} ${DEBUG}

clean:
	rm -f ${EXEC_DIR}/* ${OBJ_DIR}/*.o
