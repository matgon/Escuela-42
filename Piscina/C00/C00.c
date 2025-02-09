#include <stdio.h>
#include <stdlib.h>
#include <io.h> //windows
//#include <unistd.h>//linux

void ft_putchar(char c){
    write(1, &c, sizeof(char));
}

int main(){
    char c = 'V';
    ft_putchar(c);
    return 0;
}