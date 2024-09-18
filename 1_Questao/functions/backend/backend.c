#include <stdio.h>
#include <string.h>

#include "./backend.h"

char* convertePalavra(char v[]){

    char temp[50];
    strcpy(temp,v);

    for(int i=0;temp[i] != '\0';i++){
        if(temp[i] >= 'A' && temp[i] <= 'Z') temp[i] += 32;
    }

    return temp;
}

int comparaString(char v1[],char v2[]){
    return strcmp(convertePalavra(v1),convertePalavra(v1));
}
