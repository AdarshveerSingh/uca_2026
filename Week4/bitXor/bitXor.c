#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int bitXor(int x,int y){

    return ~(~(~x & y) & ~(x & ~y));
}
int main(){

    int x;
    int y;
    printf("Enter number (X): ");
    scanf("%d",&x);
    printf("Enter number (Y): ");
    scanf("%d",&y);
    printf("X & Y: \n");
    printf("%d",bitXor(x,y));

}