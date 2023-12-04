//Heapifying the single index
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
int main(){
    Heap h;
    h.arr[0]=-1;
    vector<int> v={-1, 12,50,60,30,40,52};
    heapify(v,1);
}
