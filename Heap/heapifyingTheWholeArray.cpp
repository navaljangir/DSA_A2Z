#include<iostream>
#include<vector>
using namespace std;
class Heap{
    public:
    int arr[101];
    int size;
    Heap(){
        size= 0;
    }
    void insert(int val){
        size = size+1;
        int index = size;
        arr[index]=val;
        while(index>1){
            int parentIndex = index/2;
            if(arr[index]>arr[parentIndex]){
            swap(arr[parentIndex] , arr[index]);
            index = parentIndex;
        }
            else{
                break;
            }
        }
    }
    int deletion(){
        int ans = arr[1];
        swap(arr[1], arr[size]);
        int index = 1;
        size--;
        while(index<size){
            int largest = index;
            int left = 2*index;
            int right = 2*index+1;
            if(left<=size && arr[left]>arr[largest]){
                largest = left;
            }
            if(right<=size && arr[right]>arr[largest]){
                largest = right;
            }
            if(index==largest){
                break;
            }else{
                swap(arr[index] , arr[largest]);
                ans = arr[largest];
                index= largest;
            }
        }
        return ans;
    }
    
};
void heapify(vector<int>&v,int index){
        // int n = v.size()-1;
        int largest = index;
        int left = 2*index;
        int right = 2* index+1;
        if(left<v.size() && v[largest]<v[left]){
            largest = left;
        }
        if(right<v.size() && v[largest]<v[right]){
            largest = right;
        }
        if(largest!=index){
            swap(v[largest]  ,v[index]);
            index = largest;
            heapify(v,index);
        }
    }
    void buildHeap(vector<int>& v){
        for(int i = (v.size()-1)/2;i>0;i--){
            heapify(v, i);
        }
    }
int main(){
    Heap h;
    h.arr[0]=-1;
    vector<int> v={-1, 30,60,70 , 100,55,80};
    buildHeap(v);
    for(int i=1;i<v.size();i++)
        cout<<v[i]<<" ";
}

//Think of the array like this 
//Input:    30
//      /       \ 
//     60       70
//    /  \     /  
//   100  55  80


//Output : 100
//       /     \ 
//     60      80
//    /  \    /  
//   30  55  70
