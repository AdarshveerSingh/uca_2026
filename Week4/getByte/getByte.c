#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getByte(int x, int n) {
    
    return (x >> (n << 3)) & 0xFF;

}

int main() {

    int x;
    int n;

    printf("Enter Number (X): ");
    scanf("%d", &x);

    printf("Enter Byte to get (0-3): ");
    scanf("%d", &n);

    printf("Byte %d: 0x%X\n", n, getByte(x, n));


}