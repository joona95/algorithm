
#include <cstdio>
#include <vector>

using namespace std;

class maxHeap{
public:
	vector<int> heap;
	
	maxHeap(){
		heap.push_back(0);
	}
	
	void heap_insert(int x){
		heap.push_back(x);
		
		int idx=heap.size()-1;
		while(idx>1){
			int parent = idx/2;
			if(heap[parent]<heap[idx]){
				int tmp=heap[idx];
				heap[idx]=heap[parent];
				heap[parent]=tmp;
				
				idx=parent;
			}
			else{
				break;
			}
		}
		
		for(int i=1;i<heap.size();i++)
			printf("%d ",heap[i]);
		printf("\n");
	}	
	
	void heap_delete(){
		if(heap.size()==1){
			printf("0\n");
		}
		else{
			printf("%d\n",heap[1]);
			heap[1]=heap[heap.size()-1];
			heap.pop_back();
			
			int idx=1;
			while(idx<heap.size()){
				int left_c=idx*2, right_c=idx*2+1;
				int maxChild;
				if(left_c<heap.size()&&right_c<heap.size()){
					if(heap[left_c]<heap[right_c]){
						maxChild=right_c;
					}
					else{
						maxChild=left_c;
					}
				}
				else if(left_c<heap.size()&&right_c>=heap.size()){
					maxChild=left_c;
				}
				else if(left_c>=heap.size()&&right_c<heap.size()){
					maxChild=right_c;
				}
				else{
					break;
				}
				
				if(heap[maxChild]>heap[idx]){
					int tmp=heap[idx];
					heap[idx]=heap[maxChild];
					heap[maxChild]=tmp;
					
					idx=maxChild;
				}
				else{
					break;
				}
			}
			
			
		}
		
		for(int i=1;i<heap.size();i++)
			printf("%d ",heap[i]);
		printf("\n");
	}
};

int main(){
	int n;
	scanf("%d", &n);
	
	maxHeap h=maxHeap();
	
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


