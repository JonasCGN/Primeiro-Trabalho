#include <stdio.h>
#include <string.h>

#include "./backend.h"

int comparaString(char v1[],char v2[]){
    char temp1[50],temp2[50];

    strcpy(temp1,v1);
    strcpy(temp2,v2);

    for(int i=0;temp1[i] != '\0';i++){
        if(temp1[i] >= 'A' && temp1[i] <= 'Z') temp1[i] += 32;
    }

    for(int i=0;temp2[i] != '\0';i++){
        if(temp2[i] >= 'A' && temp2[i] <= 'Z') temp2[i] += 32;
    }

    return strcmp(temp1,temp2);
}
