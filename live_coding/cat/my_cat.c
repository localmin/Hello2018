#include <sys/types.h>
#include <unistd.h>
#include <inttypes.h>
#include <fcntl.h>

int main(int argc, char **argv){
    uint8_t buf[4096];
    ssize_t nread;
    while((nread = read(0, buf, sizeof(buf))) > 0)
        write(1, buf, nread);
    return 0;
}