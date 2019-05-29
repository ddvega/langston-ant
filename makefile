CXX = g++
CXXFLAGS = -std=c++0x -Wall -g -pedantic-errors


OBJS = main.o Menu.o Ant.o Doodlebug.o Critter.o Validate.o Game.o
SRCS = main.cpp Menu.cpp Ant.cpp Doodlebug.cpp Critter.cpp Validate.cpp Game.cpp
HEADERS = Menu.hpp Ant.hpp Doodlebug.hpp Critter.hpp Validate.hpp Game.hpp

TARGET = prey

all: $(TARGET)

${TARGET}: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o ${TARGET}
	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
	
zip:
	zip Project_Group_39.zip -D *.*pp *.pdf makefile

clean: 
	rm -rf ${TARGET} ${OBJS}
