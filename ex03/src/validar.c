#include "validar.h"

#include <stdio.h>
#include <stdlib.h>


int ValidarSimbolo(char simbolo){
    if (simbolo == 'X' || simbolo == 'O')
        return 1;
    else
        return 0;
}

int Validar(int x, int y){
    int valido = 0;
    if(x >= 0 && x < 4){
        if(y >= 0 && y < 4)
            valido = 1;
    }
    return valido;
}
