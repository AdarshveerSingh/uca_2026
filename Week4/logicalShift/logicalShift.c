#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int logicalShift(int x, int n) {

    int mask = ~(((1 << 31) >> n) << 1);

    return (x >> n) & mask;
}

int main() {

    int x;
    int n;
    printf("Enter Hex Number (X): ");
    scanf("%x", &x);         

    printf("Enter No of Shifts (N): ");
    scanf("%d", &n);

    printf("After Logical Shift by %d: 0x%08X\n", n, logicalShift(x, n));


}