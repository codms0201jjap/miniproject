run: main.c mbti.o
	gcc -o run main.c mbti.o
mbti.o: mbti.c mbti.h
	gcc -c mbti.c -o mbti.o
clean:
	rm *.o run
