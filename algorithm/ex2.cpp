#include <iostream>
using namespace std;

int min(int a, int b) {
	if (a > b) return b;
	else return a;
}
void qSort(int* arr, int left, int right) {
	int pivot = arr[(left + right) / 2];
	int low = left;
	int high = right;
	while (low <= high) {
		while (arr[low] < pivot)
			low++;
		while (arr[high] > pivot)
			high--;
		if (low <= high) {
			int tmp = arr[low];
			arr[low] = arr[high];
			arr[high] = tmp;
			low++;
			high--;
		}
	}

	if (left < high)
		qSort(arr, left, high);
	if (high < right)
		qSort(arr, low, right);
}

void merge(int* arr, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int length = right - left + 1;
	int* sort = new int[length];

	int k = left;
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j])
			sort[k++] = arr[i++];
		else
			sort[k++] = arr[j++];
	}

	if (i <= mid) {
		for (int l = i; l <= mid; l++) {
			sort[k++] = arr[l];
		}
	}
	else {
		for (int l = j; l <= right; l++) {
			sort[k++] = arr[l];
		}
	}

	for (int l = left; l <= right; l++) {
		arr[l] = sort[l];
	}
}

void mSort(int* arr, int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		mSort(arr, left, mid);
		mSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}


int main() {
	/*
	int n;
	cin >> n;

	int* arr = new int[n + 1];
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	for (int i = 4; i <= n; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 3 == 0)
			arr[i] = min(arr[i], arr[i/3]+1);
		if (i % 2 == 0)
			arr[i] = min(arr[i], arr[i/2]+1);
	}
	cout << arr[n] << endl;
	*/

	/*
	int t;
	cin >> t;
	int* n = new int[t + 1];
	int max = 0;
	for (int i = 0; i < t; i++) {
		cin >> n[i];
		if (max < n[i])
			max = n[i];
	}

	int* arr = new int[max + 1];
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i <= max; i++) {
		arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
	}
	
	for (int i = 0; i < t; i++) {
		cout << arr[n[i]] << endl;
	}*/

	/*
	int n;
	cin >> n;
	long long *arr = new long long [n + 1];
	arr[1] = 1;
	arr[2] = 1;

	for (int i = 3; i <= n; i++) {
		arr[i] = arr[i - 2] + arr[i - 1];
	}

	cout << arr[n] << endl;
	*/

	/*
	long long int n;
	long long int result = 0;

	cin >> n;

	long long  int** arr;

	arr = new long long int* [n + 1];

	for (int i = 0; i < n + 1; i++) {
		arr[i] = new long long int[2];
	}

	arr[1][0] = 1;
	arr[1][1] = 1;
	//arr[2][0] = 2;
	//arr[2][1] = 1;

	if (n >= 3) {
		for (int i = 3; i <= n; i++) {
			arr[i][0] = arr[i - 1][0] + arr[i - 1][1];
			arr[i][1] = arr[i - 1][0];
		}
	}

	//   for(int i = 1; i < n+1; i++){
	//      for(int j = 0; j < 2; j++){
	//      cout << arr[i][j] << " ";
	//      }
	//      cout << endl;
	//   }

	cout << arr[n][1] << endl;
	*/

	/*
	int t;
	cin >> t;
	int* result[2];
	result[0] = new int[t];
	result[1] = new int[t];

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int* arr[2];
		arr[0] = new int[n];
		arr[1] = new int[n];
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < n; k++)
				cin >> arr[j][k];
		}

		result[0][i] = arr[0][0];
		result[1][i] = arr[1][0];
		for (int j = 0; j < n - 2;) {
			int row = 0;
			if (arr[1][j + 1] + arr[0][j + 2] < arr[1][j + 2]) {
				result[0][i] += arr[1][j + 2];
				row = 1;
				j += 2;
				if (j + 2 < n && arr[0][j + 1] + arr[1][j + 2] > arr[0][j + 2]) {
					result[0][i] += arr[0][j + 1];
					row = 0;
					j++;
				}
				else if (j + 2 < n && arr[0][j + 1] + arr[1][j + 2] < arr[0][j + 2]) {
					result[0][i] += arr[0][j + 2];
					row = 0;
					j+=2;
				}
			}
			else {
				result[0][i] += arr[1][j + 1];
				row = 1;
				j++;
				if (j + 2 < n && arr[0][j + 1] + arr[1][j + 2] > arr[0][j + 2]) {
					result[0][i] += arr[0][j + 1];
					row = 0;
					j++;
				}
				else if (j + 2 < n && arr[0][j + 1] + arr[1][j + 2] < arr[0][j + 2]) {
					result[0][i] += arr[0][j + 2];
					row = 0;
					j+=2;
				}
			}
			cout << "j: " << j << endl;
			if (j + 1 == n - 1 && row == 1)
				result[0][i] += arr[0][j + 1];
			else if (j + 1 == n - 1 && row == 0)
				result[0][i] += arr[1][j + 1];
			cout << result[0][i] << endl;
		}

		for (int j = 0; j < n - 2;) {
			int row = 1;
			if (arr[0][j + 1] + arr[1][j + 2] < arr[0][j + 2]) {
				result[1][i] += arr[0][j + 2];
				row = 0;
				j += 2;
				if (j + 2 < n && arr[1][j + 1] + arr[0][j + 2] > arr[1][j + 2]) {
					result[1][i] += arr[1][j + 1];
					row = 1;
					j++;
				}
				else if (j + 2 < n && arr[1][j + 1] + arr[0][j + 2] < arr[1][j + 2]) {
					result[1][i] += arr[1][j + 2];
					row = 1;
					j+=2;
				}
			}
			else {
				result[1][i] += arr[0][j + 1];
				row = 0;
				j++;
				if (j + 2 < n && arr[1][j + 1] + arr[0][j + 2] > arr[1][j + 2]) {
					result[1][i] += arr[1][j + 1];
					row = 1;
					j++;
				}
				else if (j + 2 < n && arr[1][j + 1] + arr[0][j + 2] < arr[1][j + 2]) {
					result[1][i] += arr[1][j + 2];
					row = 1;
					j+=2;
				}
			}
			cout << "j: " << j << endl;
			if (j + 1 == n - 1 && row == 0)
				result[1][i] += arr[1][j + 1];
			else if (j + 1 == n - 1 && row == 1)
				result[1][i] += arr[0][j + 1];
			cout << result[1][i] << endl;
		}
	}

	for (int i = 0; i < t; i++) {
		if (result[0][i] > result[1][i])
			cout << result[0][i] << endl;
		else
			cout << result[1][i] << endl;
	}
	*/

/*
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int* arr[2];
		for (int j = 0; j < 2; j++) {
			arr[j] = new int[n + 1];
			for (int k = 1; k <= n; k++)
				cin >> arr[j][k];
		}

		int* dp[2];
		for (int j = 0; j < 2; j++)
			dp[j] = new int[n + 1];
		dp[0][0] = 0;
		dp[1][0] = 0;
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];

		for (int j = 2; j <= n; j++) {
			if (dp[1][j - 1] > dp[1][j - 2]) {
				dp[0][j] = dp[1][j - 1] + arr[0][j];
			}
			else {
				dp[0][j] = dp[1][j - 2] + arr[0][j];
			}

			if (dp[0][j - 1] > dp[0][j - 2]) {
				dp[1][j] = dp[0][j - 1] + arr[1][j];
			}
			else {
				dp[1][j] = dp[0][j - 2] + arr[1][j];
			}
		}

		if (dp[0][n] > dp[1][n]) {
			cout << dp[0][n] << endl;
		}
		else {
			cout << dp[1][n] << endl;
		}
	}
	*/
	/*
    int n;
    cin >>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin >>arr[i];
    
	//qSort(arr, 0, n - 1);
	mSort(arr, 0, n - 1);
    
	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
		*/



	return 0;
}