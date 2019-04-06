#ifndef UTILS_H
#define UTILS_H

#define INDEX   0
#define POINTER 1

#define LAST    0
#define MID     1
#define MD5     2
#define RAND    3

#define REC     0
#define TAIL    1


void swap(int *a, int *b);
int randInt(int min, int max);
int* generateIntArray(int n, int min, int max);
void printArray(int *arr, int n);
int isSorted(int *arr, int n);

#endif