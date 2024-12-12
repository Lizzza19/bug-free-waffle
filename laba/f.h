#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
typedef struct music{
char titles [MAX];
char artist [MAX];
char album [MAX];
}music;
void input(music**ar,int*n);
void save(const char*filename,music*ar,int n);
void add(music**ar,int*n);
void delet(music** ar, int* n, int in);
void search(music**ar, int n);
void print(music*ar, int n);
void edit(music* ar, int n);
void load(char*filename,music**ar,int*n);
