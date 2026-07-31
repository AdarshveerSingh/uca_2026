#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int bang(int x){

    int mask=(x | (~x+1));
    return (mask >> 31) + 1; 

}

int main(){

    int x;
    printf("Enter number (X): ");
    scanf("%d",&x);
    printf("Bang : ");
    printf("%d",bang(x));
}