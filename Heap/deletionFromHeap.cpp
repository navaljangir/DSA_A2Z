//T.C - O(logn) 
//T.C for finding the largest element in an array = O(1)
#include<iostream>
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
int main(){
    Heap h;
    h.arr[0]=-1;

}
