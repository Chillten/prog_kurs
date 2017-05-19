#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

#include "functions.h"


int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Invalid args\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (!fp) {
        printf("File open error\n");
        return 1;
    }

    char *s = NULL;
    size_t len;
    ssize_t bytes_read = getdelim(&s, &len, '\0', fp);

    if (bytes_read != -1) {
        int N = bytes_read;
        printf("file:\n%s\n", s);
        cleanString(s);
        printf("clean string:\n%s\n", s);
        N = slen(s);

        int R[2][N + 1];

        findAllPolindroms(s, N, R);
        printf("\nPolinoms:\n");
        printPolindroms(s, N, R);

        return 0;
    }
    else {
        printf("File read error\n");
        return 1;
    }
}