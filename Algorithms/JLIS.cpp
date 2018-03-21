#include <iostream>
#define max(x,y) x > y ? x : y

//���� ���ذ� �� �Ȱ���.

using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int n, m, A[100], B[100];
int cache[101][101];

int JLIS(int idxA, int idxB) {
	//�޸������̼�
	int& ret = cache[idxA + 1][idxB + 1];
	if (ret != -1) return ret;
	
	//A[idxA],B[idxB]�� �����ϹǷ� 2���� �׻� �ִ�.
	ret = 2;
	long long a = (idxA == -1 ? NEGINF : A[idxA]);
	long long b = (idxB == -1 ? NEGINF : B[idxB]);
	long long maxElement = max(a, b);

	//�������Ҹ� ã�´�
	for (int nxtA = idxA + 1; nxtA < n; ++nxtA)
		if (maxElement < A[nxtA])
			ret = max(ret, JLIS(nxtA, idxB) + 1);
	for (int nxtB = idxB + 1; nxtB < m; ++nxtB)
		if (maxElement < B[nxtB])
			ret = max(ret, JLIS(idxA, nxtB));

	return ret;
}