mkdir obj
mkdir dist

gcc -c src\contatos.c -Iinclude -o obj\contatos.o
gcc -c src\uteis.c -Iinclude -o obj\uteis.o
gcc -c src\arqtxt.c -Iinclude -o obj\arqtxt.o
gcc -c src\main.c -Iinclude -o obj\main.o

gcc obj\contatos.o obj\uteis.o obj\arqtxt.o obj\main.o -o dist\agenda.exe