#include <stdio.h>
#include <stdlib.h>
#include <io.h> //windows
//#include <unistd.h> //linux

void ft_is_negative(int n){
    char negativo = 'N';
    char positivo = 'P';
    n < 0 ? write(1, &(char){'N'}, sizeof(char)) : write(1, &(char){'P'}, sizeof(char));
}

int main(){
    int n = 0;
    ft_is_negative(n);
    return 0;
}