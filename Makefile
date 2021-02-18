CC = gcc -Wall
Output = crypto-tools
Obj_files =  main.o caesar.o enigma.o vigenere.o clearInputBuffer.o readFileInString.o readOneChar.o readString.o writeStringInFile.o

$(Output): $(Obj_files)
		$(CC) -o $@ $^

$(Obj_files):
		$(CC) -c $<

main.o : ./src/main.c
caesar.o : ./src/caesar/caesar.c
enigma.o : ./src/enigma/enigma.c
vigenere.o : ./src/vigenere/vigenere.c

clearInputBuffer.o : ./src/lib/clearInputBuffer.c
readFileInString.o : ./src/lib/readFileInString.c
readOneChar.o : ./src/lib/readOneChar.c
readString.o : ./src/lib/readString.c
writeStringInFile.o : ./src/lib/writeStringInFile.c

all: clean $(Output) run

clean:
		rm $(Obj_files) $(Output) -f

run:
		./$(Output)