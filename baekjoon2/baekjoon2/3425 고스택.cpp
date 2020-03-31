#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

int arr[1005];
char command[100005][5];
int num[100005];

int main() {

	char cmd[5];

	scanf("%s", cmd);

	while (strcmp(cmd, "QUIT") != 0) {
		
		
		int c_idx = 0, n_idx = 0;
		while (strcmp(cmd, "END") != 0) {
			strcpy(command[c_idx], cmd);
			c_idx++;

			if (strcmp(cmd, "NUM") == 0) {
				int a;
				scanf("%d", &a);
				num[n_idx] = a;
				n_idx++;
			}

			scanf("%s", cmd);
		}

		
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int v;
			scanf("%d", &v);
			int s_idx = 0;
			arr[s_idx] = v;
			s_idx++;

			bool error = false;
			int n_idx2 = 0;
			for (int j = 0; j < c_idx; j++) {
				if (strcmp(command[j], "NUM") == 0) {
					arr[s_idx] = num[n_idx2];
					n_idx2++;
					s_idx++;
				}
				else if (strcmp(command[j], "POP") == 0) {
					if (s_idx < 1) {
						error = true;
						break;
					}
					s_idx--;
				}
				else if (strcmp(command[j], "INV") == 0) {
					if (s_idx < 1) {
						error = true;
						break;
					}
					arr[s_idx - 1] = arr[s_idx - 1] * (-1);
				}
				else if (strcmp(command[j], "DUP") == 0) {
					if (s_idx < 1) {
						error = true;
						break;
					}
					
					arr[s_idx] = arr[s_idx - 1];
					s_idx++;
				}
				else if (strcmp(command[j], "SWP") == 0) {
					if (s_idx < 2) {
						error = true;
						break;
					}

					int tmp = arr[s_idx - 1];
					arr[s_idx - 1] = arr[s_idx - 2];
					arr[s_idx - 2] = tmp;
				}
				else if (strcmp(command[j], "ADD") == 0) {
					if (s_idx < 2) {
						error = true;
						break;
					}

					long long int result = (long long int)arr[s_idx - 1] + arr[s_idx - 2];
					
					if (result > 1000000000 || result < -1000000000) {
						error = true;
						break;
					}

					arr[s_idx - 2] = result;
					s_idx--;
				}
				else if (strcmp(command[j], "SUB") == 0) {
					if (s_idx < 2) {
						error = true;
						break;
					}

					long long int result= (long long int)arr[s_idx - 2] - arr[s_idx - 1];

					if (result > 1000000000 || result < -1000000000) {
						error = true;
						break;
					}

					arr[s_idx - 2] = result;
					s_idx--;
				}
				else if (strcmp(command[j], "MUL") == 0) {
					if (s_idx < 2) {
						error = true;
						break;
					}

					long long int result = (long long int)arr[s_idx - 2] * arr[s_idx - 1];

					if (result > 1000000000 || result < -1000000000) {
						error = true;
						break;
					}

					arr[s_idx - 2] = result;
					s_idx--;
				}
				else if (strcmp(command[j], "DIV") == 0) {
					if (s_idx < 2 || arr[s_idx-1]==0) {
						error = true;
						break;
					}

					arr[s_idx - 2] = arr[s_idx - 2] / arr[s_idx - 1];
					s_idx--;
				}
				else if (strcmp(command[j], "MOD") == 0) {
					if (s_idx < 2 || arr[s_idx-1]==0) {
						error = true;
						break;
					}

					arr[s_idx - 2] = arr[s_idx - 2] % arr[s_idx - 1];
					s_idx--;
				}
			}

			if (s_idx == 1 && error==false) {
				printf("%d\n", arr[s_idx - 1]);
			}
			else {
				printf("ERROR\n");
			}
		}

		printf("\n");

		scanf("%s", cmd);
	}

	return 0;
}

/*
sub에서도 -1000000000-1=-1000000001 같은 경우 생기므로 절댓값 판단 필요
long long int  = int*int 가 되니 int값이 저장되는 경우 생겨버림 
long long ing  =  (long long ing) int * int 필요했다.

*/