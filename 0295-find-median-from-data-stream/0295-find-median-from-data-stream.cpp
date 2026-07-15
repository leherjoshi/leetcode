class MedianFinder {
public:
    // vector<int>num;
    // int n;
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

        if(large.size()>small.size()+1){
            small.push(large.top());
            large.pop();
        }else if(large.size()<small.size()){
            large.push(small.top());
            small.pop();
        }
    }
    
    double findMedian() {
        if(large.size()>small.size())return large.top();
        return (small.top()+large.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */