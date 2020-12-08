mkdir obj
mkdir dist

gcc -c src\conjuntos.c -Iinclude -o obj\conjuntos.o
gcc -c src\uteis.c -Iinclude -o obj\uteis.o
gcc -c src\main.c -Iinclude -o obj\main.o

gcc obj\conjuntos.o obj\uteis.o obj\main.o -o dist\conjuntos.exe