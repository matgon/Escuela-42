#include <unistd.h>

void ft_putstr(char *str){
    int i = 0;
    while(str[i]) write(1, str[i++], sizeof(char));
}

int main(){
    char *str = "Hola mundooo.";

    ft_putstr(str);
}
