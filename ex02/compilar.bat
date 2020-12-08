mkdir obj
mkdir dist

gcc -c src\brinquedos.c -Iinclude -o obj\brinquedos.o
gcc -c src\uteis.c -Iinclude -o obj\uteis.o
gcc -c src\main.c -Iinclude -o obj\main.o

gcc obj\brinquedos.o obj\uteis.o obj\main.o -o dist\estoque.exe