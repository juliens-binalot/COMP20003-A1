#Makefile

dict1: dict1.o bst1.o athleteData.o
	gcc -Wall -o dict1 dict1.o bst1.o athleteData.o

dict1.o: dict1.c bst1.h athleteData.h
	gcc -c -Wall dict1.c

bst1.o: bst1.c bst1.h athleteData.h
	gcc -c -Wall bst1.c

#athleteData.o: athleteData.c athleteData.h
#	gcc -c -Wall athleteData.c

dict2: dict2.o bst2.o athleteData.o
	gcc -Wall -o dict2 dict2.o bst2.o athleteData.o

dict2.o: dict2.c bst2.h athleteData.h
	gcc -c -Wall dict2.c

bst2.o: bst2.c bst2.h athleteData.h
	gcc -c -Wall bst2.c

athleteData.o: athleteData.c athleteData.h
	gcc -c -Wall athleteData.c
