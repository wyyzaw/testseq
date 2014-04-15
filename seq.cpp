#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define MAX_SIZE 5000
#define INF 1e8
#define index(i, j) (n * i) + j


int dist[MAX_SIZE][MAX_SIZE];
int *dists;
int n;


void floyd_warshall() {
	int i, j, k;

	for (k = 0; k < n; ++k) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

void doPrint() {
	int i, j, k;
	freopen("c:\\seqout.txt","w",stdout);
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
	 freopen("CON", "w", stdout);
}
void load() {
	int i, j, tmp;
	char name[15];
	printf("input file: ");
	scanf("%s", name);
	freopen(name, "r", stdin);
	printf("\n");

	scanf("%d", &n);

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j){
			scanf("%d", &tmp);
			if (tmp == -1) tmp = INF;
			dist[i][j] = tmp;
		}
	}

}
int main() {
	clock_t start,finish;
    double totaltime;
    start=clock();
	int i, j;
	load();
	floyd_warshall();
	doPrint();
	finish=clock();
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
	printf("That tooks %f secodes\n", totaltime);
	while(1){}
}
