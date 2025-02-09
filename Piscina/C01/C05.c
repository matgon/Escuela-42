#include <stdlib.h>
#include <stdio.h>

void ft_putstr(char *str){
    int i = 0;
    while(str[i]) printf("%c\n", str[i++]);
}

int main(){
    char *str = "Hola mundooo.";

    ft_putstr(str);
}