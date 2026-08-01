#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPower2(int x) {
    
    int mask = (x & ( x + (~0) ));
    
    return !(mask) & !!x & !(x >> 31);
    
}

int main() {

    int x;

    printf("Enter Number (X): ");
    scanf("%d", &x);

    printf("Is Power of 2: %d\n", isPower2(x));

}