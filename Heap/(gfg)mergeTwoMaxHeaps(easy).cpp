class Solution{
    public:
    void insertIntoHeap(vector<int>& a, int val){
        a.push_back(val);
        int index= a.size()-1;
        int parentIndex = (index-1)/2;
        while(index>=0){
            parentIndex = (index-1)/2;
            if(a[parentIndex]<a[index]){
                swap(a[parentIndex] , a[index]);
                index = parentIndex;
            }else{
                break;
            }
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        for(int i =0 ; i<b.size();i++){
            insertIntoHeap(a, b[i]);
        }
        return a;
    }
};
