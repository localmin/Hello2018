#include <sys/types.h>
#include <unistd.h>
#include <inttypes.h>
#include <fcntl.h>

int main(int argc, char **argv){
    uint8_t buf[4096];// 4096 = (0x1000)_16t uint8_t: unsigned short int :16bit
    ssize_t nread; //size_tはmallocに渡される引数の型であり、ssize_tはread()とwrite()の戻り値の型です
    
    int fd = open(argv[1], O_RDONLY);

    while((nread = read(fd, buf, sizeof(buf))) > 0)
        write(1, buf, nread);
    return 0;
}