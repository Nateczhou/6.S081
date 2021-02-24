#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE *ifp, FILE *ofp) {
    // open the first with r
    int c;
    while ((c = getc(ifp)) != EOF) {
        putc(c, ofp);
    }
    // write to the second
}

int main(int argc, char *argv[]) 
{
    // understand: print file in shell
    // check if file exists, open then print, then close
    FILE *fp;
    if (argc == 1) {
        // print error
        filecopy(stdin, stdout);
    } else {
        while (--argc > 0) {
            // if file is null
            if ((fp = fopen(*++argv, "r")) == NULL) {
                // print error
                fprintf(stderr, "cannot open file\n");
                exit(1);
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    if (ferror(stdout)) {
        fprintf(stderr, "error writing to stdout\n");
        exit(2);
    }
    exit(0);
}

