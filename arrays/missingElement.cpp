#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr = {1,3,5,3,4};
    for(int i = 0; i<arr.size();i++){
        if(arr[arr[i]-1]>=0){
            arr[abs(arr[i])-1]=-1*arr[abs(arr[i])-1];
        }
    }
    for(int i = 0; i<arr.size();i++){
        if(arr[i]>0){
            cout<<i+1<<" ";
        }
    }
}
