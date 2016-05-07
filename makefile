FILEMAIN = fightclub
FILE1 = fightercreation
FILE2 = fighters
FILE3 = fights
OUTPUTNAME = fightclub

CFLAGS=-std=c++11 -O -g -Wall -Werror
CC=g++

all: ${OUTPUTNAME}

debug: CFLAGS += -DDEBUG
debug: all

memcheck: all
		G_SLICE=always-malloc G_DEBUG=gc-friendly  valgrind -v --tool=memcheck --leak-check=full --num-callers=40 --log-file=valgrind.log ./${OUTPUTNAME}

${FILEMAIN}.o: ${FILEMAIN}.cpp
		${CC} ${CFLAGS} -c ${FILEMAIN}.cpp

${FILE1}.o: ${FILE1}.cpp
		${CC} ${CFLAGS} -c ${FILE1}.cpp

${FILE2}.o: ${FILE2}.cpp
		${CC} ${CFLAGS} -c ${FILE2}.cpp		
		
${FILE3}.o: ${FILE3}.cpp
		${CC} ${CFLAGS} -c ${FILE3}.cpp
		
${OUTPUTNAME}: ${FILEMAIN}.o ${FILE1}.o ${FILE2}.o ${FILE3}.o  
		${CC} ${CFLAGS} ${FILEMAIN}.o ${FILE1}.o ${FILE2}.o ${FILE3}.o -o ${OUTPUTNAME}

clean:
		rm -f ${OUTPUTNAME} *.o ${OUTPUTNAME}.tar.gz valgrind.log

tar: clean
		tar -czvf ./${OUTPUTNAME}.tar.gz *.cpp *.h makefile
