#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "f.h"
#define MAX 50
void input(music**ar,int*n){
        printf("Количество записей: ");
        scanf("%i", n);
        while (getchar() != '\n' || *n<=0){
                printf("Введите ещё раз\n");
                printf("n= ");
                scanf("%i", n);
        }
        *ar=(music*)calloc(*n,sizeof(music));
        if(*ar==NULL){
                printf("Error");
                return;
        }
        for(int i=0; i<*n; i++){
                printf("Название песни:");
                scanf("%49s", (*ar)[i].titles);
                printf("Исполнитель:");
                scanf("%49s", (*ar)[i].artist);
                printf("Альбом:");
                scanf("%49s", (*ar)[i].album);
        }
}
void save(const char*filename,music*ar,int n){
        FILE*f=fopen(filename,"w");
        if(!f){
                printf("Error\n");
                return;
        }
        fprintf(f,"%i\n",n);
        for(int i=0; i<n; i++){
                fprintf(f,"%s %s %s\n",ar[i].titles,ar[i].artist,ar[i].album);
        }
        fclose(f);
}
void add(music**ar,int*n){
        if(*n<=0){
                printf("Error");
                return;
        }
        *ar=(music*)calloc((*n+1),sizeof(music));
        if (*ar == NULL) {
                printf("Error\n");
                return;
        }
        printf("Название песни:");
        scanf("%s", (*ar)[*n].titles);
        printf("Исполнитель:");
        scanf("%s", (*ar)[*n].artist);
        printf("Альбом:");
        scanf("%s", (*ar)[*n].album);
}
void delet(music** ar, int* n, int in){
        if (in < 0 || in > *n || getchar() != '\n'){
                printf("Неверный индекс\n");
                return;
        }
        for(int i = in; i < *n - 1; i++){
                (*ar)[i] = (*ar)[i + 1];
        }
        *n-=1;
        *ar = (music*)realloc(*ar, (*n) * sizeof(music));
        printf("Песня успешно удалена\n");
}
void search(music**ar, int n){
        int r;
        printf("1-Поиск по названию песни,2-Поиск по исполнителю,3-Поиск по альбому\n");
        printf("r= ");
        scanf("%i",&r);
        while (getchar() != '\n' || r<=0){
                printf("Введите ещё раз\n");
                printf("r= ");
                scanf("%i", &r);
        }
        int k=1;
        switch(r){
                case 1:
                        char title[MAX];
                        printf("Введите название песни\n");
                        scanf("%s",title);
                        for (int i=0;i<n;i++){
                                if(!strcmp((*ar)[i].titles,title)){
                                        printf("%s %s %s\n",(*ar)[i].titles,(*ar)[i].artist,(*ar)[i].album);
                                        k=0;
                                }
                        }
                        if(k){
                                printf("Ничего не удалось найти\n");
                                return;
                        };
                        break;
                case 2:
                        char artists[MAX];
                        printf("Введите исполнителя\n");
                        scanf("%s",artists);
                        for (int i=0;i<n;i++){
                                if(!strcmp((*ar)[i].artist,artists)){
                                        printf("%s %s %s\n",(*ar)[i].titles,(*ar)[i].artist,(*ar)[i].album);
                                        k=0;
                                }
                        }
                        if(k){
                                printf("Ничего не удалось найти\n");
                                return;
                        }
                        break;
                case 3:
                        char albums[MAX];
                        printf("Введите альбом\n");
                        scanf("%s",albums);
                        for (int i=0;i<n;i++){
                                if(!strcmp((*ar)[i].album,albums)){
                                        printf("%s %s %s\n",(*ar)[i].titles,(*ar)[i].artist,(*ar)[i].album);
                                        k=0;
                                }
                        }
                        if(k){
                                 printf("Ничего не удалось найти\n");
                                 return;
                        };
                        break;
                default:
                        while (r>3){
                                printf("Введите ещё раз\n");
                                printf("r= ");
                                scanf("%i", &r);
                        }
                        break;
        }
}
void print(music*ar, int n){
        if(ar==NULL || n<=0){
                printf("Нет записей\n");
                return;
        }
        printf("Песни:\n");
        for(int i=0; i<n; i++){
                printf("%s %s %s\n", ar[i].titles, ar[i].artist, ar[i].album);
        }
}
void edit(music* ar, int n) {
        int in;
        printf("Введите номер песни для редактирования: ");
        scanf("%i", &in);
        if (in < 1 || in > n || getchar() != '\n'){
                ("Некорректный номер песни.\n");
                return;
        }
        in--;
        printf("Редактирование песни:\n");
        printf("Новое название песни: ");
        scanf("%49s", ar[in].titles);
        printf("Новый исполнитель: ");
        scanf("%49s", ar[in].artist);
        printf("Новый альбом: ");
        scanf("%49s", ar[in].album);
        printf("Песня успешно отредактирована.\n");
}
void load(char*filename,music**ar,int*n){
        FILE* f = fopen(filename, "r");
        if (!f){
                printf("Ошибка открытия файла");
                return;
        }
        if(fscanf(f,"%i",n)!=1){
                fclose(f);
                return;
        }
        if(*n<=0){
                fclose(f);
                return;
        }
        *ar=(music*)calloc(*n,sizeof(music));
        for(int i=0;i<*n;i++){
                if(fscanf(f,"%s %s %s\n",(*ar)[i].titles,(*ar)[i].artist,(*ar)[i].album)!=3)
                break;
        }
        fclose(f);
}
