.PHONY: clean

CXX_STD = -std=c++17
WARNINGS = -Wall -Wextra -Werror -Wpedantic -pedantic-errors
OPTIMIZE =
DEBUG =
LIB_DIR = lib
LIBRARIES = -lsfml-graphics -lsfml-window -lsfml-system -lm
LIB_INCLUDES = -I${LIB_DIR}/tileson/include

EXEC_NAME = adventure
EXEC_DIR = bin
EXEC = ${EXEC_DIR}/${EXEC_NAME}
OBJ_DIR = obj
SRC_DIR = src
INC_DIR = src

MAIN_OBJ = ${OBJ_DIR}/main.o
MAIN_SRC = ${SRC_DIR}/main.cxx
GAME_ENGINE_HXX = ${INC_DIR}/GameEngine.hxx
GAME_ENGINE_OBJ = ${OBJ_DIR}/GameEngine.o
GAME_ENGINE_SRC = ${SRC_DIR}/GameEngine.cxx
INPUT_HANDLER_HXX = ${INC_DIR}/InputHandler.hxx
INPUT_HANDLER_OBJ = ${OBJ_DIR}/InputHandler.o
INPUT_HANDLER_SRC = ${SRC_DIR}/InputHandler.cxx
RENDERER_HXX = ${INC_DIR}/Renderer.hxx
RENDERER_OBJ = ${OBJ_DIR}/Renderer.o
RENDERER_SRC = ${SRC_DIR}/Renderer.cxx
SPRITE_LOADER_HXX = ${INC_DIR}/SpriteLoader.hxx
SPRITE_LOADER_OBJ = ${OBJ_DIR}/SpriteLoader.o
SPRITE_LOADER_SRC = ${SRC_DIR}/SpriteLoader.cxx

all: debug

release: DEBUG = -DNDEBUG
release: OPTIMIZE = -O3
release: ${EXEC_DIR} ${OBJ_DIR} ${EXEC}

debug: DEBUG = -DDEBUG -g
debug: OPTIMIZE = -Og
debug: ${EXEC_DIR} ${OBJ_DIR} ${EXEC}

${EXEC}: ${MAIN_OBJ} ${GAME_ENGINE_OBJ} ${RENDERER_OBJ} ${SPRITE_LOADER_OBJ} ${INPUT_HANDLER_OBJ}
	${CXX} -o $@ $^ ${LIBRARIES}

${MAIN_OBJ}: ${MAIN_SRC} ${GAME_ENGINE_HXX} ${INPUT_HANDLER_HXX} ${RENDERER_HXX} ${SPRITE_LOADER_HXX}
	${CXX} -c -o $@ $< ${LIB_INCLUDES} ${CXX_STD} ${WARNINGS} ${OPTIMIZE} ${DEBUG}

${GAME_ENGINE_OBJ}: ${GAME_ENGINE_SRC} ${GAME_ENGINE_HXX}
	${CXX} -c -o $@ $< ${LIB_INCLUDES} ${CXX_STD} ${WARNINGS} ${OPTIMIZE} ${DEBUG}

${INPUT_HANDLER_OBJ}: ${INPUT_HANDLER_SRC} ${INPUT_HANDLER_HXX}
	${CXX} -c -o $@ $< ${LIB_INCLUDES} ${CXX_STD} ${WARNINGS} ${OPTIMIZE} ${DEBUG}

${RENDERER_OBJ}: ${RENDERER_SRC} ${RENDERER_HXX}
	${CXX} -c -o $@ $< ${LIB_INCLUDES} ${CXX_STD} ${WARNINGS} ${OPTIMIZE} ${DEBUG}

${SPRITE_LOADER_OBJ}: ${SPRITE_LOADER_SRC} ${SPRITE_LOADER_HXX}
	${CXX} -c -o $@ $< ${LIB_INCLUDES} ${CXX_STD} ${WARNINGS} ${OPTIMIZE} ${DEBUG}

${EXEC_DIR}:
	mkdir -p ${EXEC_DIR}

${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

clean:
	rm -f ${EXEC_DIR}/* ${OBJ_DIR}/*.o
