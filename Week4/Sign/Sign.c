#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sign(int x){

    return (x>>31) | !!x; 

}

int main(){

    int x;
    printf("Enter number (X): ");
    scanf("%d",&x);
    printf("Sign : ");
    printf("%d",sign(x));
}