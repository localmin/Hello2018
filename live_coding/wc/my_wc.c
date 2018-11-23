#include <stdio.h>
#include <stdlib.h>

int nlines = 0;

static void wc(FILE *in, char *filename){
    char buf[4096];
    int nl = 0;

    size_t nread;
    while((nread = fread(buf, 1, sizeof(buf), in)) > 0)
        for(size_t i = 0; i < nread; i++)
            if(buf[i] == '\n')
                nl++;

    if(filename)
        printf("%d %s\n", nl, filename);
    else
        printf("%d \n", nl);

    nlines += nl;

}

int main(int argc, char **argv){
    if(argc == 1){
        wc(stdin, NULL);
        exit(0);    
    }

    for(char **p = argv + 1; *p; p++){
        FILE *in = fopen(*p, "r");
        if(!in){
            perror("fopen");
            exit(1);
        }
        wc(in, *p);
    }

    if(argc > 2)
        printf("%d\n", nlines);
    return 0;
}
