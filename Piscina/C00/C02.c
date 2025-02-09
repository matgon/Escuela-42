#include <stdio.h>
#include <stdlib.h>
#include <io.h> //windows
//#include <unistd.h> //linux

void ft_print_alphabet(void){
    for(unsigned int i = 122; i>96; i--){
        write(1, &i, sizeof(char));
    }
}

int main(){
    ft_print_alphabet();
    return 0;
}