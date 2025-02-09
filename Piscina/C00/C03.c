#include <stdio.h>
#include <stdlib.h>
#include <io.h> //windows
//#include <unistd.h> //linux

void ft_print_numbers(void){
    for(unsigned int i=48; i<58; i++){
        write(1, &i, sizeof(unsigned int));
    }
}

int main(){
    ft_print_numbers();
    return 0;
}