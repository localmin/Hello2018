#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int main(void) {
    char ch[4096];
    read(0, ch, sizeof(ch));
    printf("%s\n", ch);
    return 0;
}
