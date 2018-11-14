#include <stdio.h>

int main(void) {
    char ch[30];
    fread(ch, sizeof(char), 5,  stdin);
    printf("%s\n", ch);
    return 0;
}
