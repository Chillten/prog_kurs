#include <sys/types.h>
#include "strings.h"
#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

int cleanString(char *s)
{
    int i = 0;
    int nextChar = 0;
    u_int32_t size = slen(s);
    while (i < size && nextChar < size) {
        if (isChar(s[i])) {
            i++;
        }
        else {
            nextChar = i;
            while (!isChar(s[nextChar]) && nextChar < size) {
                nextChar++;
            }
            if (nextChar == size) {
                s[i] = '\0';
                return i;
            }
            else {
                s[i] = s[nextChar];
                s[nextChar] = '#';
                i++;
            }
        }
    }

}

int isChar(char c)
{
    return ((c >= 'a' && c <= 'z')
        || (c >= 'A' && c <= 'Z')
    ) ? 1 : 0;
}

void findAllPolindroms(char *s, int N, int R[2][N + 1])
{
    int i, j, k, rp;
    for (j = 0; j <= 1; j++) {
        R[j][0] = rp = 0;
        for (i = 0; i < N; i += k) {
            while (s[i - rp - 1] == s[i + j + rp]) {
                rp++;
            }
            R[j][i] = rp;
            k = 1;
            while ((R[j][i - k] != rp - k) && (k < rp)) {
                R[j][i + k] = min(R[j][i - k], rp - k);
                k++;
            }
            rp = max(rp - k, 0);
        }
    }
}

void printPolindroms(char *s, int N, int R[2][N + 1])
{
    char *buff = malloc(8);
    int size = 8;
    int i, j, rp;

    for (i = 0; i < N; i++) {
        for (j = 0; j <= 1; j++)
            for (rp = R[j][i]; rp > 0; rp--) {
                if (size < 2 * rp + j) {
                    buff = realloc(buff, 2 * rp + j);
                    size = 2 * rp + j;
                }
                    memcpy(buff, s + i - rp, 2 * rp + j);
                    buff[2 * rp + j] = '\0';
                    if(scmp(buff, "") != 0) {
                        printf("%s\n", buff);
                    }
            }
    }
    free(buff);
}

int min(int a, int b)
{
    return a > b ? b : a;
}

int max(int a, int b)
{
    return a > b ? a : b;
}