#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "f.h"
#define MAX 50
int main(){
music*ar=NULL;
int n=0;
int c;
do{
	printf("1.Добавить песню\n");
	printf("2.Удалить песню\n");
	printf("3.Вывод на экран список песен\n");
	printf("4.Поиск песни\n");
	printf("5.Изменить данные о песни\n");
	printf("6.Выход\n");
	printf("Ваш выбор: ");
	scanf("%i",&c);
	printf("\n");
switch(c){
	case 1:
		input(&ar,&n);
		print(ar,n);
		save("music.txt",ar,n);
		break;
	case 2:
		int in;
		printf("Введите индекс песни для удаления:");
		scanf("%i",&in);
		delet(&ar,&n,in-1);
		print(ar,n);
                save("music.txt",ar,n);
                break;
	case 3:
		print(ar,n);
                break;
	case 4:
		search(&ar,n);
		break;
	case 5:
		edit(ar,n);
                save("music.txt",ar,n);
                print(ar,n);
		break;
	case 6:
		break;
	default:
		printf("Неверный выбор. Попробуйте снова.\n");
                while (getchar() != '\n' || c>6){
                	printf("Введите ещё раз\n");
                	printf("c= ");
                	scanf("%i", &c);
        	}
		break;
	}
}while(c!=6);
free(ar);
return 0;
}
