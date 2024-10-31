class MyHashSet {
private:
    vector<int> keys;

public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        auto keyIt = find(keys.begin(), keys.end(), key);
        if (keyIt == keys.end()) {
            keys.push_back(key);
        }
    }
    
    void remove(int key) {
        auto keyIt = find(keys.begin(), keys.end(), key);
        if (keyIt != keys.end()) {
            keys.erase(keyIt);
        }
    }
    
    bool contains(int key) {
        auto keyIt = find(keys.begin(), keys.end(), key);
        return (keyIt != keys.end());
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

