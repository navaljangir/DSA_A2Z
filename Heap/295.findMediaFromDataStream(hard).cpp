class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int> , greater<int>> minHeap;
    double median = 0 ;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size() == minHeap.size()){
            if(num>median){
                minHeap.push(num);
                median = (double)minHeap.top();
            }else{
                maxHeap.push(num);
                median = (double)maxHeap.top();
            }
        }else if(minHeap.size() > maxHeap.size()){
            if(num>median){
                int element = minHeap.top();
                minHeap.pop();
                maxHeap.push(element);
                minHeap.push(num);
                median = (double)(minHeap.top() + maxHeap.top())/2;
            }else{
                maxHeap.push(num);
                median = (double)(minHeap.top() + maxHeap.top())/2;
            }
        }else{
            //maxHeap.size > minHeap.size
            if(num>median){
                minHeap.push(num);
                median = (double)(minHeap.top() + maxHeap.top())/2;
            }else{
                int element = maxHeap.top();
                maxHeap.pop();
                minHeap.push(element);
                maxHeap.push(num);
                median = (double)(minHeap.top() + maxHeap.top())/2;
            }
        }
    }
    
    double findMedian() {
        return median;
    }
};
