mkdir obj
mkdir dist

gcc -c src\validar.c -Iinclude -o obj\validar.o
gcc -c src\jogo.c -Iinclude -o obj\jogo.o
gcc -c src\main.c -Iinclude -o obj\main.o

gcc obj\validar.o obj\jogo.o obj\main.o -o dist\jogodavelha.exe