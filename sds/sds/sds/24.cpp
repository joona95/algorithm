/*
#include <cstdio>

bool arr[1000001];


int main(){

	for(int i=3;i<=1000000;i+=2){
		if(arr[i]==false){
			
			int num=i*2;
			while(num<=1000000){
				if(arr[num]==false){
					arr[num]=true;//배수 지워주기 
				}
				num+=i;
			}
		}
	}
	


	
	
	for(int i=0;i<100000;i++){
		int n;
		scanf("%d",&n);
		if(n==0){
			break;
		}

	
		int a, b;
		bool find=false;
		for(int j=3;j<=1000000;j+=2){
			//arr범위 넘어감 n-j 음 
			if(arr[j]==false&&n-j>2&&arr[n-j]==false){

				a=j;
				b=n-j;

				find=true;
				break;
	
			}
		}
		

		if(find==false)
			printf("Goldbach's conjecture is wrong.\n");
		else
			printf("%d = %d + %d\n",n,a,b);

	}
	
	
	return 0;
}
*/

