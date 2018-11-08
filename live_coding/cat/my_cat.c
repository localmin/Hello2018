#include <sys/types.h>
#include <inttypes.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv){
    uint8_t buf[4096];// 4096 = (0x1000)_16t uint8_t: unsigned short int :16bit
    ssize_t nread; //size_tはmallocに渡される引数の型であり、ssize_tはread()とwrite()の戻り値の型です
    int fd = STDIN_FILENO; 

    if(argc > 1){
        fd = open(argv[1], O_RDONLY);//file opne fdは成功したらファイルハンドル，エラー時は-1を返す

        if(fd < 0){
            fprintf(stderr, "can not open %s : %s\n", argv[1], strerror(errno));
        // perror はvoidを返す(error messageは標準エラー出力), strerrorは文字列を返す
        // printfは出力先をstdoutに固定している 
            exit(1);
        }
    }
    while((nread = read(fd, buf, sizeof(buf))) > 0) //ファイルディスクリプタを読み込む
        write(1, buf, nread);
    return 0;
}
