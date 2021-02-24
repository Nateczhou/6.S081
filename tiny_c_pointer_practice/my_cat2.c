#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) 
{
    int fd, n;
    char buf[64];


    if (argc == 1) {
        while ((n = read(0, buf, 64)) > 0)
            write(1, buf, n);
    } else {
        while (--argc > 0) {
            if ((fd = open(*++argv, O_RDONLY, 0))) {
                while ((n = read(fd, buf, 64)) > 0) {
                    write(1, buf, n);
                }
                close(fd);
            } 
        }
    }
    exit(0);
}