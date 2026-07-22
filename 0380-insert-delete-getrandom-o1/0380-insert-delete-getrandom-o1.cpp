class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int>vec;
    int i=0;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }      
         mp[val]=i;
         vec.push_back(val);
         i++;
        return true;
    }
    
    bool remove(int val) {
         if(mp.find(val)==mp.end()){
            return false;
        }      
        int key = mp[val];
            swap(vec[key], vec[i-1]);

            mp[vec[key]] = key;   // missing

            vec.pop_back();
            mp.erase(val);
            i--;
        
        return true;
    }
    
    
    int getRandom() {
        int idx = rand() % vec.size();
            return vec[idx];


    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */