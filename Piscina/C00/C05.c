#include <stdio.h>
#include <stdlib.h>
#include <io.h>//windows
// #include <unistd.h>//linux

void ft_print_comb(void){
    char comb[3];
    for (comb[0]='0';comb[0]<='9';comb[0]++){
        for (comb[1] = comb[0]+1;comb[1]<='9';comb[1]++){
            for (comb[2]=comb[1]+1;comb[2]<='9';comb[2]++){
                    write(1, comb, 3* sizeof(char));
                    if(comb[0] != '7' || comb[1]!='8' || comb[2]!='9') write(1, &(char[]){", "}, 2*sizeof(char));
            }
        }    
    }
    
}

int main(){
    ft_print_comb();
    return 0;
}