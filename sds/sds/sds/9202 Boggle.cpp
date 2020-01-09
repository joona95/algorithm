#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int mx[] = { -1,-1,-1,0,0,1,1,1 };
int my[] = { -1,0,1,-1,1,-1,0,1 };

char boggle[5][5];
bool visited[5][5];
int score;
int cnt;
string find_str = "";
vector<string> find_w;

class Node {
public:
	Node **child;
	bool isEnd;
	bool isHit;

	Node() {
		child = new Node*[26];
		for (int i = 0; i < 26; i++) {
			child[i] = NULL;
			isEnd = false;
			isHit = false;
		}
	}

};

class Trie {
public:
	Node root;

	Trie() {
	}

	void insert(char* word) {

		Node* cur = &root;
		for (int i = 0; i < strlen(word); i++) {
			if (!cur->child[word[i] - 'A']) {
				cur->child[word[i] - 'A'] = new Node();
				cur = cur->child[word[i] - 'A'];
			}
			else {
				cur = cur->child[word[i] - 'A'];
			}
		}
		cur->isEnd = true;


	}



};


void search(int x, int y, int idx, Node* n) {
	visited[y][x] = true;
	char c[2];
	c[0]= boggle[y][x];
	c[1] = '\0';
	find_str.append(c);
	//printf("%s\n", find_str.c_str());

	if (n->child[boggle[y][x] - 'A'] && n->child[boggle[y][x] - 'A']->isEnd == true && n->child[boggle[y][x] - 'A']->isHit == false) {
		int len = find_str.length();
		if (len == 8) {
			score += 11;
		}
		else if (len == 7) {
			score += 5;
		}
		else if (len == 6) {
			score += 3;
		}
		else if (len == 5) {
			score += 2;
		}
		else if (len == 4 || len == 3) {
			score += 1;
		}

		find_w.push_back(find_str);
		n->child[boggle[y][x] - 'A']->isHit = true;
		cnt++;
	}

	if (idx == 8) {
	}
	else {
		if (n->child[boggle[y][x] - 'A']) {
			for (int i = 0; i < 8; i++) {
				int targetX = x + mx[i];
				int targetY = y + my[i];

				if (0 <= targetX && targetX < 4 && 0 <= targetY && targetY < 4) {
					if (!visited[targetY][targetX] && n->child[boggle[y][x] - 'A']->child[boggle[targetY][targetX] - 'A']) {
						search(targetX, targetY, idx + 1, n->child[boggle[y][x] - 'A']);
					}
				}

			}

		}
	}

	find_str.erase(idx);
	visited[y][x] = false;
}


void clearHit(Node *r) {

	if (r->isHit == true) {
		r->isHit = false;
	}

	if (r) {
		for (int i = 0; i < 26; i++) {
			if (r->child[i]) {
				//printf("%c\n", i + 'A');
				clearHit(r->child[i]);
			}
		}
	}

}

bool cmp(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return a.length() > b.length();
	}
}


int main() {
	int w;
	scanf("%d", &w);

	Trie t;

	for (int i = 0; i < w; i++) {
		char word[10];
		scanf("%s", word);

		t.insert(word);
	}

	int b;
	scanf("%d", &b);
	for (int i = 0; i < b; i++) {
		score = 0;
		cnt = 0;

		for (int k = 0; k < 4; k++) {
			char s[5];
			scanf("%s", s);
			for (int j = 0; j < 4; j++) {
				boggle[k][j] = s[j];
			}
		}

		//Ž��
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				search(k, j, 0, &t.root);
			}
		}

		sort(find_w.begin(), find_w.end(), cmp);

		/*
		for (int j = 0; j < find_w.size(); j++) {
			printf("%s ", find_w[j].c_str());
		}*/

		printf("%d %s %d\n", score, find_w[0].c_str(), cnt);
		clearHit(&t.root);
		find_w.clear();

	}


	return 0;
}


/*
Boggle 

ACM  ACMA ����? 
isEnd ǥ�� -> count�ø� 

dfs Ž�� 

���� �ܾ ������ ã�� ��쿡�� �ѹ��� ã�� ������ ���� -> isHit �ѹ� ã���� hitüũ�ع�����

isEnd�ų� isHit�� �� ���� ���� 
�Ź� tree��ȸ�ϸ鼭 clearhit method ����Լ��� ¥�� ���� 
 
5
ICPC
ACM
CONTEST
GCPC
PROGRAMM



classTrie{
  TrieNode root = new TrieNode()
  
  void insert(String word)
  
  bool containNode(String word) //���� ���������� �ʿ���� 
  	return current.isEnd;
  
}

class TrieNode{
	TrieNode[] children=new TrieNode[26]
}



DFS
�湮
üũ��
if�����ߴ°� 
else
 for -> �� �� �ִ� ��
	if �� �� �ִ°�
		�湮
üũ�ƿ� 


search(int x, int y, int depth, TrieNode trie) -> search(x,y,1,t.root.children[map[y][x]]) 
visit üũ 
string build ���� ������� ����

if trie�� isEnd && trie.isHit==false
isHit üũ 
���� �� 
����
���ڸ� ã�� �� 


visited false
string delete  


answer���� ���� �� ����, ���� ������  ���ĺ������� 
-> answer �ϳ��� ��� ������ ���� �ʳ���� ���������� �� �־���� ���������� �������ؼ� ����ϴ°� ����.
 

*/
