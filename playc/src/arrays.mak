#	Makefile for array1 and dynArray

#	Written by: Cathy Bishop, September 16, 2014.

CC		=	gcc

CFLAGS	=	-Werror -I ../include 
LDFLAGS	=	

# Headers

HEADERS	=	../include/arrayUtils.h
HEADERS2 =	../include/arrayUtils.h ../include/dynamicArrayUtils.h

# Source files

UTILSOURCE	=	arrayUtils.c
UTILSOURCE2	=	arrayUtils.c dynamicArrayUtils.o
SOURCE		=	array1.c ${UTILSOURCE}
SOURCE2		=	dynArray.c ${UTILSOURCE2}

# List all of the object files

UTILOBJECTS	=   arrayUtils.o
UTILOBJECT	=	arrayUtils.o dynamicArrayUtils.o
OBJECTS		=	array1.o ${UTILOBJECTS}
OBJECTS2	=	dynArray.o ${UTILOBJECT}

# Specify the source with main and the executable file name

all: ${HOME}/bin/array1 ${HOME}/bin/dynArray

${HOME}/bin/array1: ${OBJECTS} arrays.mak ${HEADERS}
	 ${CC} ${LDFLAGS} -o $@ ${OBJECTS} 
${HOME}/bin/dynArray: ${OBJECTS2} arrays.mak ${HEADERS2}
	 ${CC} ${LDFLAGS} -o $@ ${OBJECTS2}

clean:
	rm -r ${OBJECTS} ${HOME}/bin/array1
	rm -r ${OBJECTS2} ${HOME}/bin/dynArray

.SUFFIXES:
.SUFFIXES: .c .o .h

%.o : %.h 
%.o : %.c ;  ${CC} ${CFLAGS} -c $< -o $@ 

