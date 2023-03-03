#include "util.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




// int main(int argc, char **argv){

//     char * hex = binary_to_hex("hello", 6);
//     printf("Hex: %s\n", hex);
//     printf("size of hex: %d\n",strlen(hex));

//     void * bin = hex_to_binary("68 65 6c 6c 6f", strlen(hex));
//     printf("\nbin: %s\n", bin);
//     free(hex);
//     free(bin);
// }


char *binary_to_hex(void *data, ssize_t n){
    char *ret = malloc(sizeof(char) *(3 * n));
    n--;
    n*=3;
    int i = 0;
    int j = 0;
    
    while(i < n){
        
        sprintf(ret+i, "%02x", *(char *)(data+ j));
        i+=2;
        j+=1;

        if(j % 16 == 0){
            sprintf(ret+i, "\n");
            i++;
        }
        sprintf(ret + i, " ");
        i++;
      
    }
    
    return ret;
}



void *hex_to_binary(char *hex, ssize_t n){
    void *ret = malloc(sizeof(char) * n);
    int *arr= malloc(sizeof(int) * n);
    int i = 0;
    int s = 0;
    // printf("n: %d\n", n);
    

    // converts hex to int array
    while(hex[i] != (char) ('\0')){
        if(hex[i] >= '0' && hex[i]<= '9'){
            arr[s] = (int)(hex[i]-'0');
            s++;
        }
        else if(hex[i] >= 'a' && hex[i]<='f'){
            arr[s] = (int)(hex[i]-'a' + 10);
            s++;
        }
        else if(hex[i] >= 'A' && hex[i]<='F'){
            arr[s] = (int)(hex[i]-'A' + 10);
            s++;
        }
        else if(hex[i] == ' '){}
        else{
            free(ret);
            printf("Error: invalid hex");
            return NULL;
        }
        i++;        
    }

    int j = 0;
    int k = 0;
    // uses int array to set hex value
    while(j < n){
        *(char *)(ret + j) = (char)(arr[k] * 16 + arr[k+1]);
       // printf("%s", (ret+ j));
        j ++;
        k+=2;
    }
    // printf("\nret: ",ret);
    return ret;

}

