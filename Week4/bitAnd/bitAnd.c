#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int bitAnd(int x,int y){

    return ~(~(x)|~(y));
}
int main(){

    int x;
    int y;
    printf("Enter number (X): ");
    scanf("%d",&x);
    printf("Enter number (Y): ");
    scanf("%d",&y);
    printf("X & Y: \n");
    printf("%d",bitAnd(6,5));

}