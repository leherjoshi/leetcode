class MedianFinder {
public:
    priority_queue<int>large;
    priority_queue<int,vector<int>,greater<int>>small;
   
    MedianFinder() {
        
    }
    
    void addNum(int num) {
    
       if(large.empty()||num<=large.top()){
            large.push(num);
       }else{
            small.push(num);
       } 

       if(large.size() > small.size() + 1){
            small.push(large.top());
            large.pop();
        }

        if(small.size() > large.size()){
            large.push(small.top());
            small.pop();
        }
    
    }
    
    double findMedian() {
        if(large.size()==small.size())return (large.top()+small.top())/2.0;
        return large.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */