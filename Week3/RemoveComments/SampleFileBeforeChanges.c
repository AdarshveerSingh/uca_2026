#include <stdio.h>

// This is a single-line comment

int main() {

    int a = 10; // Variable declaration

    /*
        This is a
        multi-line comment
    */

    printf("Hello World\n");

    printf("// This is NOT a comment\n");

    printf("/* Neither is this */\n");

    char slash = '/';
    char star = '*';

    char quote = '\"';
    char single = '\'';

    // Another comment

    if (a > 5) {
        printf("Value = %d\n", a); /* Inline comment */
    }

    printf("String with escaped quote: \"Hello\"\n");

    printf("String with // and /* inside it */\n");

    /*
    Another
    Multi-line
    Comment
    */

    return 0;
}