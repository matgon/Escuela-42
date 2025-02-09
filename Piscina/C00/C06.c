#include <stdio.h>
#include <stdlib.h>
#include <io.h>//windows
//#include <unistd.h>//linux

void ft_print_comb2(void){
    char primero[2]="00", segundo[2]="00";
    while(primero[0] != '9' || primero[1] != '9'){
        segundo[0] = primero[0];
        segundo[1] = primero[1];
        while(segundo[0] != '9' || segundo[1] !='9'){
            if(segundo[1]=='9'){
                segundo[1]='0';
                segundo[0]++;
            }
            else segundo[1]++;
            write(1, &primero, 2*sizeof(char));
            write(1, &(char){' '}, sizeof(char));
            write(1, &segundo, 2*sizeof(char));
            if((primero[0] !='9' || primero[1] !='8') || (segundo[0] !='9' || segundo[1] != '9')) write(1, &(char[]){", "}, 2* sizeof(char));
        }
        if(primero[1]=='9'){
            primero[1]='0';
            primero[0]++;
        }
        else primero[1]++;
    }
}

int main(){
    ft_print_comb2();
    return 0;
}