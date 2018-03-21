#include <iostream>

using namespace std;

//�Ϲ� ��� ȣ��
bool match(const string& w,const string& s){
	int i = 0;

	//��Ī�Ǹ� ���� �ø���.
	while(w[i] == s[i] || w[i] == '?' && i < s.size() && i < w.size())	i++;

	//��� ���ڿ��� ��Ī�� ������ �� �����Ѵ�.
	if(i == w.size())
		if(i == s.size())
			return true;

	if(w[i] == '*'){// *�� ���� ��쿡�� ��� ��츦 Ž���Ѵ�.
		for(int skip = 0;skip + i < s.size(); skip++){
			if(match(w.substr(i + 1),s.substr(skip + i)))
				return true;
		}
	}
	//�ʿ�. 
	return false;
}

//�޸������̼�
int cache[101][101];
string W,S;

int match2(int w, int s){
	
	//���� �����Ǵ��� �Ǻ��ϱ�
	while(W[w] == S[s] || W[w] == '?' && w < W.size() && s < S.size())
	{ 
		w++; s++;
	}
	
	//��� ���� �Ǿ� �� �о��� �� Ȯ���ϱ�
	if(w == W.size())
		if(s == S.size())
			return 1;

	int *ret = &cache[w][s];
	
	//�̹� ���� �κ� ó���ϱ�
	if(*ret != -1) return *ret;

	//*�ϰ�� ���� ��� �κ� �ݺ��Ͽ� Ȯ���� ó���ϱ�.
	if(W[w] == '*')
		for(int skip = 0; skip + s < S.size(); s++){
			if(match2(w+1,s+skip))
				return 1;
		}

	return 0;
}

int match3(int w, int s){
	
	//���о��� ��
	if(w == W.size())
		if(s == S.size())
			return 1;

	int *ret = &cache[w][s];

	//�ϳ��� �б�
	if(W[w] == S[s] || W[w] == '?' && w < W.size() && s < S.size())
		return *ret = match3(++w,++s);
	
	//�̹� ���Ǿ��� ��
	if(*ret != -1) 
		return *ret;

	//'*'�� ������ ��
	if(W[w] == '*')
		if(match3(w+1,s) || match3(w,s+1)/*�̺κ��� for���� ��ü�� �� �ְ� �����.*/ && s < S.size())
			return 1;

	return 0;
}

//�޸������̼� �õ� ������ �߸� ®��.
//int cache[101][101];
//
//int match2(const string& w, const string& s){
//	int w_cnt = 0;
//	int s_cnt = 0;
//	
//	//��Ī�Ǹ� ���� �ø���.
//	while(w[w_cnt] == s[s_cnt] || w[w_cnt] == '?' && s_cnt < s.size() && w_cnt < w.size())	{
//		w_cnt++;
//		s_cnt++;
//	}
//
//	//��� ���ڿ��� ��Ī�� �������� Ȯ�� �� �����Ѵ�.
//	if(w_cnt == w.size())
//		if(s_cnt == s.size())
//			return 1;
//
//	int *ret = &cache[w_cnt][s_cnt]; 
//	//�̹� ó���� ����̸� return�Ѵ�.
//	if(*ret != -1)
//		return *ret;
//
//	if(w[w_cnt] == '*'){// *�� ���� ��쿡�� ��� ��츦 Ž���Ѵ�.
//		for(int skip = 0; skip + s_cnt < s.size(); skip++){
//			if(match(w.substr(w_cnt + 1),s.substr(skip + s_cnt)))
//				return 1;
//		}
//	}
//
//	return 0;
//}