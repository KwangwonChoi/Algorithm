#include <iostream>
//cache�� ���� �ʱ�ȭ �صд�. ���� -1�� �Ѵ�.
//memset�� �̿��Ͽ� �ʱ�ȭ �ϸ� ����.
int cache[101][101];

int bino(int n, int r){
	//ret�� ������ reference�̴�.
	int *ret = &cache[n][r];

	//������ʿ� ���� �����Ѵ�.
	if(n == r || r == 0) return 1;

	//������ �� ���� ����� ���� ������ ���� ��ȯ�Ѵ�.
	if(*ret != -1) return *ret;

	//������ ����Ѵ�.
	return *ret = bino(n-1,r-1) + bino(n-1,r);
}