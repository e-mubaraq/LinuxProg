#	Makefile for generateRandom

#	Written by: Cathy Bishop, September 16, 2014.

CC		=	gcc

CFLAGS	=	-Werror -I ../include 
LDFLAGS	=	

# Headers

HEADERS	=	 ../include/myfuncts.h

# Source files

UTILSOURCE	=	myfuncts.h
SOURCE		=	generateRandom.c ${UTILSOURCE}

# List all of the object files

UTILOBJECTS	=	myfuncts.o 
OBJECTS		=	generateRandom.o ${UTILOBJECTS}

# Specify the source with main and the executable file name

all: generateRandom

generateRandom: ${OBJECTS} random.mak ${HEADERS}
	 ${CC} ${LDFLAGS} -o $@ ${OBJECTS} -lm

clean:
	rm -r ${OBJECTS} generateRandom

.SUFFIXES:
.SUFFIXES: .c .o .h

%.o : %.h 
%.o : %.c ;  ${CC} ${CFLAGS} -c $< -o $@ 

