build:
	g++ -g -Wall -o lanParty src\main.c src\cerinta1.c src\cerinta2.c src\cerinta3.c src\cerinta4.c
run:
	.\lanParty
clean:
	rm -f *.o lanParty.exe
