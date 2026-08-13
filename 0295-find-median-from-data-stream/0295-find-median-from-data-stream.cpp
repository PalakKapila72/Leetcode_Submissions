class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    MedianFinder() {  
    }
    
    void addNum(int num) {
        minheap.push(num);
        if(!minheap.empty() && !maxheap.empty()){
            int val1=maxheap.top();
            int val2=minheap.top();
            if(val1>val2){
                maxheap.pop();
                minheap.pop();
                maxheap.push(val2);
                minheap.push(val1);
            }
        }
        int siz1=maxheap.size();
        int siz2=minheap.size();
        if(siz1<siz2){
            maxheap.push(minheap.top());
            minheap.pop();
        }       
    }
    
    double findMedian() {
        int siz1=maxheap.size();
        int siz2=minheap.size();
        double median=0.0;
        if(siz1==siz2){
             median=(maxheap.top()+minheap.top())/2.0;
        }
        else{
            median=maxheap.top();
        }
        return median;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */