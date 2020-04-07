#	Makefile for program1 and program2

#	Written by: Cathy Bishop, September 16, 2014.

CC		=	gcc

CFLAGS	=	-Werror -I ../include 
LDFLAGS	=	

# Headers

HEADERS	=	../include/utils1.h ../include/utils2.h
HEADERS2 =	../include/myfuncts.h

# Source files

UTILSOURCE	=	utils1.c utils2.c 
UTILSOURCE2	=	myfuncts.c
SOURCE		=	program1.c ${UTILSOURCE}
SOURCE2		=	program2.c ${UTILSOURCE2}

# List all of the object files

UTILOBJECTS	=	utils1.o utils2.o 
UTILOBJECT	=	myfuncts.o
OBJECTS		=	program1.o ${UTILOBJECTS}
OBJECTS2	=	program2.o ${UTILOBJECT}

# Specify the source with main and the executable file name

all: ${HOME}/bin/program1 ${HOME}/bin/program2

${HOME}/bin/program1: ${OBJECTS} programs.mak ${HEADERS}
	 ${CC} ${LDFLAGS} -o $@ ${OBJECTS} 
${HOME}/bin/program2: ${OBJECTS2} programs.mak ${HEADERS2}
	 ${CC} ${LDFLAGS} -o $@ ${OBJECTS2} -lm

clean:
	rm -r ${OBJECTS} ${HOME}/bin/program1
	rm -r ${OBJECTS2} ${HOME}/bin/program2

.SUFFIXES:
.SUFFIXES: .c .o .h

%.o : %.h 
%.o : %.c ;  ${CC} ${CFLAGS} -c $< -o $@ 

