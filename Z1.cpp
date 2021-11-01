#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

int max_size = 6, i, j, start;
int* DIST = (int*)malloc(max_size * sizeof(int));

void BSFD(int st, int** b, int num_of_elem, int* vis) {
	queue<int> Q;
	int t;
	Q.push(st);
	vis[st] = 0;

	while (!Q.empty())
	{
		t = Q.front();
		Q.pop();
		printf("%d ", t + 1);
		for (int i = 0; i < num_of_elem; i++)
		{
			if (b[t][i] == 1 && vis[i] == -1)
			{
				vis[i] = vis[t] + 1;
				Q.push(i);
			}
		}
	}

}


void DSFD(int st, int** b, int num_of_elem, int* visited) {
	stack <int> Q;
	int t;
	for (i = 0; i < max_size; i++)
	{
		visited[i] = -1;
	}
	Q.push(st);
	visited[st] = 0;
	while (!Q.empty())
	{
		t = Q.top();
		Q.pop();
		printf("%d ", t + 1);
		for (int i = 0; i < num_of_elem; i++)
		{
			if (b[t][i] == 1 && visited[i] == -1)
			{
				Q.push(i);
				visited[i] = visited[t] + 1;
			}
		}
	}
}


void DSFD_Recr(int st, int** b, int num_of_elem, int* visited) {
	int i;
	printf("%d ", st + 1);
	for (i = 0; i < num_of_elem; i++)
	{
		if (b[st][i] == 1 and visited[i] == -1)
		{
			visited[i] = visited[st] + 1;
			DSFD_Recr(i, b, num_of_elem, visited);
		}
	}
}

int main() {

	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int** a = new int* [max_size];
	for (i = 0; i < max_size; i++)
	{
		a[i] = new int[max_size];
	}

	for (i = 0; i < max_size; i++)
	{
		for (j = i + 1; j < max_size; j++)
		{
			a[i][j] = rand() % 2;
			a[j][i] = a[i][j];
		}
	}

	for (i = 0; i < max_size; i++)
	{
		DIST[i] = -1;
		for (j = 0; j < max_size; j++)
		{
			if (i == j)
				a[i][j] = 0;
			printf("%2d", a[i][j]);
		}
		printf("\n");
	}

	printf("\nÏîèñê ðàññòîÿíèé îáõîäîìì â øèðèíó\ncòàðòîâàÿ âåðøèíà - ");
	scanf_s("%d", &start);
	BSFD(start - 1, a, max_size, DIST);
	printf("\nÐàññòîÿíèå èç ïåðâîé:\n");
	for (i = 0; i < max_size; i++) {
		printf("äî %d = %d\n", i + 1, DIST[i]);
		DIST[i] = -1;
	}

	printf("\nÏîèñê ðàññòîÿíèé îáõîäîìì â ãëóáèíó\ncòàðòîâàÿ âåðøèíà - ");
	scanf_s("%d", &start);
	DSFD(start - 1, a, max_size, DIST);
	printf("\nÐàññòîÿíèå èç ïåðâîé:\n");
	for (i = 0; i < max_size; i++) {
		printf("äî %d = %d\n", i + 1, DIST[i]);
		DIST[i] = -1;
	}


	printf("\nÏîèñê ðàññòîÿíèé îáõîäîìì â ãëóáèíó ðåêóðñèåé\ncòàðòîâàÿ âåðøèíà - ");
	scanf_s("%d", &start);
	DIST[start - 1] = 0;
	DSFD_Recr(start - 1, a, max_size, DIST);
	printf("\nÐàññòîÿíèå èç ïåðâîé:\n");
	for (i = 0; i < max_size; i++) {
		printf("äî %d = %d\n", i + 1, DIST[i]);
		DIST[i] = -1;
	}

}