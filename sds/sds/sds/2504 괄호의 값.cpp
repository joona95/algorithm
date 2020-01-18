
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

struct elem{
	int type;
	char c;
	int num;
};

int main(){
	
	char str[35];
	scanf("%s", str);
	
	stack<elem> s;
	for(int i=0;i<strlen(str);i++){
		switch(str[i]){
			case '(':{
				//printf("(\n");
				elem t;
				t.type=0;
				t.c=str[i];
				s.push(t);
				break;
			}
			case '[':{
				//printf("[\n");
				elem t;
				t.type=0;
				t.c=str[i];
				s.push(t);
				break;
			}
			case ')':{
				if(s.empty()){
					printf("0");
					return 0;
				}
				//printf(")\n");
				elem top = s.top();
				s.pop();
				int result=0;
				while(top.type!=0||top.c!='('){
					result+=top.num;
					if(s.empty()){
						printf("0");
						return 0;
					}
					top=s.top();
					s.pop();	
					
					//***
					if(top.type==0&&top.c!='('){
						printf("0");
						return 0;
					}

				}
				
				if(result==0)
					result=2;
				else if(result!=0)
					result*=2;		
				
				//printf("%d\n",result);
				
				elem t;
				t.type=1;
				t.num=result;
				s.push(t);
				
				break;
			}
			case ']':{
                if(s.empty()){
					printf("0");
					return 0;
				}
				//printf("]\n");
				elem top = s.top();
				s.pop();
				int result=0;
				while(top.type!=0||top.c!='['){
					result+=top.num;
					if(s.empty()){
						printf("0");
						return 0;
					}
				
					top=s.top();
					s.pop();

					//***
					if(top.type==0&&top.c!='['){
						printf("0");
						return 0;
					}
				}
			
				if(result==0)
					result=3;
				else if(result!=0)
					result*=3;
				
				//printf("%d\n",result);
				
				elem t;
				t.type=1;
				t.num=result;
				s.push(t);
				
				break;
			}
		}
	}
	
	int result=0;
	while(!s.empty()){
		elem e= s.top();
		s.pop();
		
		if(e.type!=0){
			result+=e.num;
		}
		else{
			printf("0");
			return 0;
		}
	}
	
	printf("%d",result);
	
	return 0;
}


//예외 처리에서 문제생김 
/*
숫자인지
글자인지-> 글자면 '('/'[' 인지 아닌지 
if else 더 깔끔하게 가능
 
*/

/*
(()[[]])([])()[][]

(
((
pop
(2
(2[
(2[[
pop
(2[3
pop
pop
(29
pop
(11
pop
22
22([
pop
22(3
pop
22 6
28

ERROR
(남아있을것 


반례
()([[[]]) 

*/
