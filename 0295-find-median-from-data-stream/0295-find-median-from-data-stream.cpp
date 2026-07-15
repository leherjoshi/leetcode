class MedianFinder {
public:
    //vector<int>v;
    // int n;
   // priority_queue<int>large;
  //  priority_queue<int,vector<int>,greater<int>>small;



    MedianFinder() {
        
    }
   vector<int> v;

void addNum(int num) {
    auto it = lower_bound(v.begin(), v.end(), num);
    v.insert(it, num);
}

double findMedian() {
    int n = v.size();

    if (n % 2)
        return v[n/2];

    return (v[n/2] + v[n/2-1]) / 2.0;
}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */