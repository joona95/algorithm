#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int main() {
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF) {
		printf("%d\n", a + b);
	}

	return 0;
}

/*
���� �׽�Ʈ���̽� �� �־����� ���� ��!

1.
while(scanf("%d %d", &a, &b)==2){}
2.
while(scanf("%d %d", &a, &b)!=EOF){}
3.
while(scanf("%d %d", &a, &b)!=-1 || scanf("%d %d", &a, &b)>0){}
EOF�� ��� -1�� ���ǵǾ� ����.
4.
while(true){
	if(cin.eof()==true){break;}
}
*/