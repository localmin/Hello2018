//#define _GNU_SOURCE
// getline はもともとGNU拡張だが標準化された
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    FILE* fp = NULL;
    if(argc < 2){
        fp = stdin;
    }else{
        fp = fopen(argv[1], "rb");
    }
    char** lines = NULL;
    int num_lines = 0;
    char* line = NULL;
    size_t len = 0;
    for(; getline(&line, &len, fp) > 0; line = NULL){
        num_lines++;
        lines = (char**)realloc(lines, sizeof(char*) * num_lines);
        lines[num_lines - 1] = line;
    }
    fclose(fp);

    int i;
    for(i = 0; i < num_lines; i++){
        printf("%s", lines[i]);
    }
    return 0;
}
