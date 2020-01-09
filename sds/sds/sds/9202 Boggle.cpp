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

		//탐색
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

ACM  ACMA 구분? 
isEnd 표시 -> count올림 

dfs 탐색 

같은 단어를 여러번 찾은 경우에는 한번만 찾은 것으로 생각 -> isHit 한번 찾으면 hit체크해버리기

isEnd거나 isHit일 때 종료 조건 
매번 tree순회하면서 clearhit method 재귀함수로 짜면 쉬움 
 
5
ICPC
ACM
CONTEST
GCPC
PROGRAMM



classTrie{
  TrieNode root = new TrieNode()
  
  void insert(String word)
  
  bool containNode(String word) //현재 문제에서는 필요없음 
  	return current.isEnd;
  
}

class TrieNode{
	TrieNode[] children=new TrieNode[26]
}



DFS
방문
체크인
if도착했는가 
else
 for -> 갈 수 있는 곳
	if 갈 수 있는가
		방문
체크아웃 


search(int x, int y, int depth, TrieNode trie) -> search(x,y,1,t.root.children[map[y][x]]) 
visit 체크 
string build 현재 만들어진 글자

if trie가 isEnd && trie.isHit==false
isHit 체크 
점수 합 
갯수
문자를 찾은 답 


visited false
string delete  


answer에서 제일 긴 문자, 길이 같으면  알파벳순으로 
-> answer 하나만 들고 있으면 되지 않나라고 생각하지만 다 넣어놓고 최종적으로 정렬통해서 출력하는게 낫다.
 

*/
