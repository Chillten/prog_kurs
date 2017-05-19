#ifndef PROG_KURS_FUNCTIONS_H
#define PROG_KURS_FUNCTIONS_H

int cleanString(char *s);
int isChar(char c);
void findAllPolindroms(char *s, int N, int R[2][N + 1]);
void printPolindroms(char *s, int N, int R[2][N + 1]);
int min(int a, int b);
int max(int a, int b);
#endif //PROG_KURS_FUNCTIONS_H
