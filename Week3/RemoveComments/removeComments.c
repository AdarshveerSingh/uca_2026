#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    FILE *input = fopen("SampleFileBeforeChanges.c", "r");
    FILE *output = fopen("SampleFileAfterChanges.c", "w");

    if (input == NULL) {
        printf("Unable to open input file.\n");
        return 1;
    }

    if (output == NULL) {
        printf("Unable to create output file.\n");
        fclose(input);
        return 1;
    }

    int ch, next;

    while ((ch = fgetc(input)) != EOF) {

        if (ch == '"') {
            fputc(ch, output);

            while ((ch = fgetc(input)) != EOF) {
                fputc(ch, output);

                if (ch == '\\') {
                    ch = fgetc(input);
                    if (ch == EOF)
                        break;
                    fputc(ch, output);
                }
                else if (ch == '"') {
                    break;
                }
            }
        }

        else if (ch == '\'') {
            fputc(ch, output);

            while ((ch = fgetc(input)) != EOF) {
                fputc(ch, output);

                if (ch == '\\') {
                    ch = fgetc(input);
                    if (ch == EOF)
                        break;
                    fputc(ch, output);
                }
                else if (ch == '\'') {
                    break;
                }
            }
        }

        else if (ch == '/') {

            next = fgetc(input);

            if (next == '/') {

                while ((ch = fgetc(input)) != EOF && ch != '\n');

                if (ch == '\n')
                    fputc('\n', output);
            }

            else if (next == '*') {

                int prev = 0;

                while ((ch = fgetc(input)) != EOF) {

                    if (prev == '*' && ch == '/')
                        break;

                    prev = ch;
                }
            }

            else {

                fputc(ch, output);

                if (next != EOF)
                    ungetc(next, input);
            }
        }

        else {
            fputc(ch, output);
        }
    }

    fclose(input);
    fclose(output);

    printf("Comments removed successfully.\n");

    return 0;
}