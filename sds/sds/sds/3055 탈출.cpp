/*
#include <cstdio>
#include <queue>

using namespace std;

int mx[]={-1,1,0,0};
int my[]={0,0,-1,1};
char arr[55][55];
bool visited[55][55];
int count[55][55];

int main(){
	int r,c;
	scanf("%d %d\n",&r,&c);
	
	queue<pair<int,int>> q;
	
	for(int i=0;i<r;i++){
		for(int j=0;j<=c;j++){
			char c;
			scanf("%c", &c);
			if(c!='\n'){
				arr[i][j]=c;
			}
			
			if(c=='*'){
				q.push(make_pair(i,j));
			}
			else if(c=='S'){
				q.push(make_pair(i,j));
			}
		}
	}
	
	
	while(!q.empty()){

		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		visited[x][y]=true;
		int cnt=count[x][y];
		//printf("x:%d y:%d\n",x,y);
		
		if(arr[x][y]=='D'){
			printf("%d", cnt);
			return 0;
		}
		else if(arr[x][y]=='S'){
			for(int i=0;i<4;i++){
				int tx=x+mx[i];
				int ty=y+my[i];
				
				if(0<=tx&&tx<r&&0<=ty&&ty<c){
					if(arr[tx][ty]!='X'&&arr[tx][ty]!='*'){
						if(visited[tx][ty]!=true){
							if(arr[tx][ty]!='D')
								arr[tx][ty]='S';
							visited[tx][ty]=true;
							count[tx][ty]=cnt+1;
							q.push(make_pair(tx,ty));
						}
					}
				}
			}
		}
		else if(arr[x][y]=='*'){
			for(int i=0;i<4;i++){
				int tx=x+mx[i];
				int ty=y+my[i];
				
				if(0<=tx&&tx<r&&0<=ty&&ty<c){
					if(arr[tx][ty]=='.'){
						if(visited[tx][ty]!=true){
							arr[tx][ty]='*';
							visited[tx][ty]=true;
							count[tx][ty]=cnt+1;
							q.push(make_pair(tx,ty));
						}
					}
					else if(arr[tx][ty]=='S'){
						if(count[tx][ty]==cnt+1){
							arr[tx][ty]='*';
						}
					}
				}
			}
		}
	
	}


	printf("KAKTUS\n");

	
	return 0;
}

*/
