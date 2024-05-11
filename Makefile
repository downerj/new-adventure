.PHONY: clean

CXX_STD = -std=c++17
WARNINGS = -Wall -Wextra -Werror -Wpedantic -pedantic-errors
OPTIMIZE =
DEBUG =
LIB_DIR = lib
LIBRARIES = -lsfml-graphics -lsfml-window -lsfml-system -lm
LIB_INCLUDES = -I${LIB_DIR}/include

EXEC_NAME = adventure
EXEC_DIR = bin
EXEC = ${EXEC_DIR}/${EXEC_NAME}
OBJ_DIR = obj
SRC_DIR = src

MAIN_OBJ = ${OBJ_DIR}/main.o
MAIN_SRC = ${SRC_DIR}/main.cxx

release: DEBUG = -DNDEBUG
release: OPTIMIZE = -O3
release: ${EXEC_DIR} ${OBJ_DIR} ${EXEC}

debug: DEBUG = -DDEBUG -g
debug: OPTIMIZE = -Og
debug: ${EXEC_DIR} ${OBJ_DIR} ${EXEC}

${EXEC}: ${MAIN_OBJ}
	${CXX} -o $@ $^ ${LIBRARIES}

${MAIN_OBJ}: ${MAIN_SRC}
	${CXX} -c -o $@ $< ${LIB_INCLUDES} ${CXX_STD} ${WARNINGS} ${OPTIMIZE} ${DEBUG}

${EXEC_DIR}:
	mkdir -p ${EXEC_DIR}

${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

clean:
	rm -f ${EXEC_DIR}/* ${OBJ_DIR}/*.o
