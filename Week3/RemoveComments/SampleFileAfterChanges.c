#include <stdio.h>



int main() {

    int a = 10; 

    

    printf("Hello World\n");

    printf("// This is NOT a comment\n");

    printf("/* Neither is this */\n");

    char slash = '/';
    char star = '*';

    char quote = '\"';
    char single = '\'';

    

    if (a > 5) {
        printf("Value = %d\n", a); 
    }

    printf("String with escaped quote: \"Hello\"\n");

    printf("String with // and /* inside it */\n");

    

    return 0;
}