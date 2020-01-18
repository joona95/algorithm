#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>

char cmd[100005][5];
int num[100005];
long long s[1005];

int main(){
	while(true){
		int cnt=0, num_cnt=0;
		
			
		while(true){
			
			char s[5];
			scanf("%s", &s);
			strcpy(cmd[cnt],s);				
		
						
			if(cmd[cnt][3]=='\n'||cmd[cnt][3]==' ')
				cmd[cnt][3]='\0';
			
			if(strcmp(cmd[cnt], "END")==0 || strcmp(cmd[cnt], "QUIT")==0){
				break;
			}
			else if(strcmp(cmd[cnt], "NUM")==0){
				scanf("%d\n", &num[num_cnt]);
				num_cnt++;
			}
		
			//printf("%s\n", cmd[idx]);
			cnt++;
		
		}
		

		if(strcmp(cmd[cnt],"QUIT")==0){
			break;
		}


		int n;
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			int v;
			scanf("%d", &v);
			
			bool err=false; 
			
			int idx=0, num_i=0;
			s[idx]=v;
		
			for(int i=0;i<cnt;i++){
				char *tmp;
				tmp=cmd[i];
				if(strcmp(cmd[i], "NUM")==0){	
					idx++;
					s[idx]=num[num_i];				
					//printf("%d\n", num[num_i]);
					num_i++;
				}
				else if(strcmp(tmp, "POP")==0){
					if (idx < 0) {
						err = true;
						break;
					}
					idx--;
				}
				else if(strcmp(tmp, "INV")==0){
					if (idx < 0) {
						err = true;
						break;
					}
					s[idx]=s[idx]*(-1);
				}
				else if(strcmp(tmp, "DUP")==0){
					if (idx < 0) {
						err = true;
						break;
					}
					s[idx+1]=s[idx];
					idx++;
				}
				else if(strcmp(tmp, "SWP")==0){
					if(idx<1){
						err=true;
						break;
					}
					int tmp=s[idx];
					s[idx]=s[idx-1];
					s[idx-1]=tmp;
				}
				else if(strcmp(tmp, "ADD")==0){
					if(idx<1|| abs(s[idx])>1000000000){
						err=true;
						break;
					}
					s[idx-1]=s[idx-1]+s[idx];
					idx--;
				}
				else if(strcmp(tmp, "SUB")==0){
					if(idx<1|| abs(s[idx])>1000000000){
						err=true;
						break;
					}
					s[idx-1]=s[idx-1]-s[idx];
					idx--;
				}
				else if(strcmp(tmp, "MUL")==0){
					if(idx<1|| abs(s[idx])>1000000000){
						err=true;
						break;
					}
					s[idx-1]=s[idx-1]*s[idx];
					idx--;
				}
				else if(strcmp(tmp, "DIV")==0){
					if(idx<1|| s[idx]==0|| abs(s[idx])>1000000000){
						err=true;
						break;
					}
					s[idx-1]=s[idx-1]/s[idx];
					idx--;
				}
				else if(strcmp(tmp, "MOD")==0){
					if(idx<1||s[idx]==0|| abs(s[idx])>1000000000){
						err=true;
						break;
					}
					s[idx-1]=s[idx-1]%s[idx];
					idx--;
				}
			
				//printf("%s %d\n",tmp, s[idx]);
			}	
			
			
			if(idx!=0||abs(s[idx])>1000000000|| err==true){
				printf("ERROR\n");
			}
			else{
				printf("%d\n",s[idx]);
			}
		}
		
		printf("\n");
	}
	return 0;
}



/*
1 10 50
1 10 2502


*/
