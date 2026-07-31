#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fitBits(int x,int n){

    int shifts=32+(~n+1);
    int extended=(x<<shifts)>>shifts;
    return !(extended^x);
}
int main(){

    int x;
    int y;
    printf("Enter number (X): ");
    scanf("%d",&x);
    printf("Enter number (Y): ");
    scanf("%d",&y);
    printf("Can be Represented (1=YES) (0=NO): \n");
    printf("%d",fitBits(x,y));

}