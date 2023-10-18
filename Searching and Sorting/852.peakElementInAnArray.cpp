class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i =0 ; 
        int j = arr.size()-1;
        int ans =-1;
        int mid = i + (j-i)/2;
        while(i<j){
            if(mid+1<arr.size() && arr[mid]>arr[mid+1] && arr[mid]){
                ans = mid;
                j= mid;
            }else{
                i = mid+1;
            }
            mid= i+(j-i)/2;
        }
        return ans;
    }
};
