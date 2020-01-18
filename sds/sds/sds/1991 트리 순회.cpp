#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

struct Node {
	int leftchild;
	int rightchild;
};

Node node[26];

void print1(int r) {
	printf("%c", r + 'A');
	if (node[r].leftchild != -1)
		print1(node[r].leftchild);
	if (node[r].rightchild != -1)
		print1(node[r].rightchild);
}

void print2(int r) {
	if (node[r].leftchild != -1)
		print2(node[r].leftchild);
	printf("%c", r + 'A');
	if (node[r].rightchild != -1)
		print2(node[r].rightchild);


}

void print3(int r) {
	if (node[r].leftchild != -1)
		print3(node[r].leftchild);
	if (node[r].rightchild != -1)
		print3(node[r].rightchild);
	printf("%c", r + 'A');
}


int main() {
	int n;
	scanf("%d\n", &n);

	
	for (int i = 0; i < n; i++) {
		char a[2], b[2], c[2];
		scanf("%s%s%s", a,b,c);
		//printf("%c %c %c\n", a[0], b[0], c[0]);
		
		if (b[0] != '.') {
			node[a[0] - 'A'].leftchild = b[0] - 'A';
		}
		else {
			node[a[0] - 'A'].leftchild = -1;
		}
		
		if (c[0] != '.') {
			node[a[0] - 'A'].rightchild = c[0] - 'A';
		}
		else {
			node[a[0] - 'A'].rightchild = -1;
		}
		
	}

	
	print1(0);
	printf("\n");
	print2(0);
	printf("\n");
	print3(0);
	
	return 0;
}

