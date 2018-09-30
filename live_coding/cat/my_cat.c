#include <sys/types.h>
#include <unistd.h>
#include <inttypes.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

static void usage(char *progname){
	fprintf(stderr, "Usage: %s [ file ]\n", progname);
	exit(1);
}

int main(int argc, char *argv[]){
	uint8_t buf[4096];
	ssize_t nread;
	int fd = STDIN_FILENO; 
	char ch;
	FILE *fp;

	if(argc > 2){
		fd = open(argv[1], O_RDONLY);
		if(fd < 0){
		fprintf(stderr, "cannot open %s: %s\n", argv[1], strerror(errno));
		usage(argv[0]);
		exit(1);
		}
	}
	
 	fp = fopen("argv[1]", "r");
    while (fscanf(fp,"%c", &ch) != EOF){
        fprintf(fp, "%d", ch); 
    }
    fclose(fp);

	while ((nread = read(0, buf, sizeof(buf))) > 0)
		write(1, buf, nread);

	return 0;

}

