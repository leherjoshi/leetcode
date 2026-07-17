class FreqStack {
public:
unordered_map<int,int>freq;
unordered_map<int,stack<int>>groupby;
int maxFreq=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        int f=++freq[val];
        maxFreq=max(maxFreq,f);
        groupby[f].push(val);
    }
    
    int pop() {
        int key=groupby[maxFreq].top();
        groupby[maxFreq].pop();
        freq[key]--;
        if(groupby[maxFreq].empty())maxFreq--;
        return key;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */