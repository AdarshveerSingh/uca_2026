#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findFourOccuring(int arr[], int n){

    int result = 0;

    for (int bit = 0; bit < 32; bit++){

        int count = 0;

        for (int i = 0; i < n; i++){

            if (arr[i] & (1 << bit)){

                count++;
            }
        }

        if (count % 3 != 0){

            result |= (1 << bit);
        }
    }

    return result;
}

int main(){

    int arr[] = {1, 2, 3, 4, 1, 2, 4, 1, 2, 3, 4, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", findFourOccuring(arr, n));

}