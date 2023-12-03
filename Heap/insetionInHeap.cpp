//1 indexed heap
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
int main(){
    Heap h;
    h.arr[0]=-1;

}
