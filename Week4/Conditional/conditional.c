#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int conditional(int x,int y,int z){

    int mask = ~(!x)+1;
    
    return ( y & ~mask ) | ( z & mask );

}
int main(){

    int x;
    int y;
    int z;
    printf("Enter number (X): ");
    scanf("%d",&x);
    printf("Enter number (Y): ");
    scanf("%d",&y);
    printf("Enter number (Z): ");
    scanf("%d",&z);
    printf("Condition ( X ? Y : Z ) : \n");
    printf("%d",conditional(x,y,z));

}