#include <stdio.h>
#include <stdlib.h>
#include <io.h> //windows
//#include <unistd.h> //linux

void recursion(int n){
    int resto;
    if(n>0){
        recursion(n/10);
        write(1, &(char){'0'+n%10}, sizeof(char));
    }
}

void ft_putnbr(int nb){
    int aux = nb;
    char *ret;
    if(nb>=0){
        recursion(nb);
    }
    else{
        write(1, &(char){'-'}, sizeof(char));
        recursion(nb*-1);
    }
}

int main(){
    ft_putnbr(-4234);
    return 0;
}