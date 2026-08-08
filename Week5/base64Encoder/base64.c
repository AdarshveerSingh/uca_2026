#include <stdio.h>
#include <string.h>

char base64[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

void base64Encode(char input[], char output[])
{
    int len = strlen(input);
    int i = 0;
    int j = 0;

    while (i < len)
    {
        unsigned char a = input[i++];
        unsigned char b = 0;
        unsigned char c = 0;

        int bytes = 1;

        if (i < len)
        {
            b = input[i++];
            bytes++;
        }

        if (i < len)
        {
            c = input[i++];
            bytes++;
        }

        int value = (a << 16) | (b << 8) | c;

        output[j++] = base64[(value >> 18) & 63];
        output[j++] = base64[(value >> 12) & 63];

        if (bytes >= 2)
            output[j++] = base64[(value >> 6) & 63];
        else
            output[j++] = '=';

        if (bytes == 3)
            output[j++] = base64[value & 63];
        else
            output[j++] = '=';

    }

    output[j] = '\0';
}

int main()
{
    char input[1000];
    char output[2000];

    printf("Enter string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    base64Encode(input, output);

    printf("Base64: %s\n", output);

    return 0;
}