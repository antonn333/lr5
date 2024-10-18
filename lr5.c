#include "stdafx.h"

#include <stdio.h>
#include <limits.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main(){
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	int n, **G=NULL, *deg = NULL, *loop = NULL;
	int size = 0;
	printf("введите кол-во вершин: ");
	scanf("%d", &n);

	deg = (int*)malloc(n * sizeof(int));
	loop = (int*)malloc(n * sizeof(int));

	G = (int**)malloc(n * sizeof(int*));

	for(int i = 0; i < n; i++){
		deg[i]=0;
		loop[i]=0;
		G[i] = (int*)malloc(n * sizeof(int));
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
		G[i][j] = 0;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			G[i][j] = rand()%2;
		}
	}

    printf("\nматрица смежности G:\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
			size += G[i][j];
		}
	}

	printf("\nразмер графа: %d \n ", size);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
			if(i==j){
				deg[i] += 2*G[i][j];
				loop[i] += 2*G[i][j];
			}
			else{
				deg[i] += G[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (deg[i] - loop[i] == 0){
			printf("вершина %d изолирована", i);
		}
		if (deg[i] - loop[i] == 1){
			printf("вершина %d кольцевая", i);
		}
		if (deg[i] - loop[i] == n){
			printf("вершина %d доминирующая", i);
		}
	}

    for (int i = 0; i < n; i++) {
        free(G[i]);
    }
    free(G);

	getchar();
	getchar();
	return 0;
}