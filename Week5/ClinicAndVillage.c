#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPossible(int population[], int n, int k, double maxLoad)
{
    int clinics = 0;

    for (int i = 0; i < n; i++)
    {
        int needed = (int)ceil(population[i] / maxLoad);

        clinics += needed;

        if (clinics > k)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int n;

    printf("Size of Array: ");
    scanf("%d", &n);

    int population[n];

    printf("Enter populations:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &population[i]);
    }

    int k;

    printf("No of Clinics: ");
    scanf("%d", &k);

    // Find maximum population
    int max = population[0];

    for (int i = 1; i < n; i++)
    {
        if (population[i] > max)
        {
            max = population[i];
        }
    }

    double low = 0.0;
    double high = (double)max;

    // Floating-point binary search
    while (high - low > 1e-7)
    {
        double mid = low + (high - low) / 2.0;

        if (isPossible(population, n, k, mid))
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }

    printf("Minimum maximum load: %.2f\n", high);
}