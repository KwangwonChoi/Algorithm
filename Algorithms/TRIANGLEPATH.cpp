#include <iostream>
#define max(x,y) x > y ? x : y
#define N 10 

int board[N][N];

//����Լ� ���
int pathSum(int y, int x){
	
	if(y == N-1)
		return board[y][x];

	return max(pathSum(y+1,x), pathSum(y+1,x+1)) + board[y][x];
}

//�޸������̼�
int cache[N][N];

int pathSum2(int y, int x){
	int *ret = &cache[y][x];

	if(y == N-1)
		return *ret = board[y][x];

	if(*ret != -1)
		return *ret;

	return *ret = max(pathSum(y+1,x), pathSum(y+1,x+1)) + board[y][x];
}
