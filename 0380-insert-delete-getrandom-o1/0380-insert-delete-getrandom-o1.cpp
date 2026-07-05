class RandomizedSet {
private:
    unordered_map<int,int> indexInfo;
    vector<int> v;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(indexInfo.find(val) != indexInfo.end()) return false;
        v.push_back(val);
        indexInfo[val] = v.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(indexInfo.find(val) == indexInfo.end()) return false;
        int index = indexInfo[val];
        indexInfo[v[v.size() - 1]] = index;
        indexInfo.erase(val);
        swap(v[index],v[v.size() - 1]);
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        int r = rand() % v.size();
        return v[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */