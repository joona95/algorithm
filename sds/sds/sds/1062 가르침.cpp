
#include <cstdio>
#include <cstdlib>
#include <cstring>

char *word[50];
bool visited[26];
int count, max=0;
int n,k;

void DFS(int v){
	visited[v]=true;
	count++;
	

	if(count==k){
		int cnt=0;
		for(int i=0;i<n;i++){
			int len=0;
			for(int j=4;j<strlen(word[i])-4;j++){
				if(visited[word[i][j]-'a']==true){
					len++;
				}
				else
					break;
			}
			
			if(len==strlen(word[i])-8){
				cnt++;
			}
		}
		
		
		if(max<cnt){
			max=cnt;
		}	

	}
	else{
		
		for(int i=v+1;i<26;i++){
			if(visited[i]!=true){
				DFS(i);
			}
		}


	}
	
	count--;
	visited[v]=false;
}

int main(){
	scanf("%d%d",&n,&k);
	
	for(int i=0;i<n;i++){
		char c[20];
		scanf("%s", &c);
		
		word[i]=(char*)malloc(strlen(c)+1);
		strcpy(word[i],c);
	}
	
	visited['a'-'a']=true;
	visited['n'-'a']=true;
	visited['t'-'a']=true;
	visited['i'-'a']=true;
	visited['c'-'a']=true;
		

	if(k==5){
		int cnt=0;
		for(int i=0;i<n;i++){
			int len=0;
			for(int j=4;j<strlen(word[i])-4;j++){
				if(visited[word[i][j]-'a']==true){
					len++;
				}
				else
					break;
			}
			
			if(len==strlen(word[i])-8){
				cnt++;
			}
		}
		
		if(max<cnt){
			max=cnt;
		}	
	}
	
	for(int i=0;i<26;i++){
		
		count=5;
		
		if(visited[i]!=true)
			DFS(i);
	}
	
	printf("%d\n",max);
	
	for(int i=0;i<n;i++){
		free(word[i]);
	}
	
	return 0;
}



/*
anta tica -> antic

rc
hello
car

//k==5일때 dfs실행없이 가능하게 
antatica
antactica
antaaatica

*/
