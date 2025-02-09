#include <stdio.h>
#include <stdlib.h>
#include <io.h>//windows
//#include <unistd.h>//linux

void ft_print_combn(int n){
    char* comb = (char*) malloc(n*sizeof(char));
    for (int i = 0; i < n; i++){
        comb[i] = '0' + i;
    }
    int finished = 0;
    int i = n - 1;
    while(!finished){
        write(1, comb, n*sizeof(char));
        
        while(comb[i]==9+'0' || comb[i]==10-(n-i)+'0'){
            i--;
        }
        if(i<0){
            finished = 1;
        }else{
            comb[i]++;
            for(int j = i+1; j<n;j++){
                comb[j]=comb[j-1]+1;
            }
        }
    }
    free(comb);
}

int main(){
    int n = 9;
    ft_print_combn(n);
    return 0;
}