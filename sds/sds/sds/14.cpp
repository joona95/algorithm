/*
#include <cstdio>
#include <vector>

using namespace std;

class minHeap{
	public:
	vector<int> heap;
	
	
	void heap_insert(int x){
		heap.push_back(x);
		
		int idx=heap.size()-1;

		
		while(idx>0){
			int parent=(idx-1)/2;
			if(heap[parent]>heap[idx]){
				int tmp=heap[idx];
				heap[idx]=heap[parent];
				heap[parent]=tmp;
				idx=parent;
			}
			else{
				break;
			}
		}
		
	}
	
	void heap_delete(){
		if(heap.size()==0){
			printf("0\n");
		}
		else{	
			printf("%d\n",heap[0]);
			
			heap[0]=heap[heap.size()-1];
			heap.pop_back();
			int idx=0;
			
			while(idx<heap.size()){
				int left_c=(idx+1)*2-1, right_c=(idx+1)*2;
				int minChild;
				if(left_c<heap.size()&&right_c<heap.size()){
					if(heap[left_c]<=heap[right_c]){
						minChild=left_c;
					}
					else{
						minChild=right_c;
					}
				}
				else if(left_c<heap.size()&&right_c>=heap.size()){
					minChild=left_c;
				}
				else if(left_c>=heap.size()&&right_c<heap.size()){
					minChild=right_c;
				}
				else{
					break;
				}
				
				if(heap[idx]>heap[minChild]){
					int tmp=heap[idx];
					heap[idx]=heap[minChild];
					heap[minChild]=tmp;
					idx=minChild;
				}
				else{
					break;
				}
			}
		}
	}

};

int main(){
	int n;
	scanf("%d",&n);
	minHeap h=minHeap();
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		
		if(x==0){
			h.heap_delete();
		}
		else{
			h.heap_insert(x);
		}
	}
	
	return 0;
}
*/

/*
0  1 2 
1 2 3
10 1 
*/
