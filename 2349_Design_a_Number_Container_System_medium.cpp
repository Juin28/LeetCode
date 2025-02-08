class NumberContainers {
private:
    unordered_map<int, int> indexToNumber;
    unordered_map<int, set<int> > numberToIndex; 
public:
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if (indexToNumber.find(index) != indexToNumber.end()) {
            int oldNumber = indexToNumber[index];
            numberToIndex[oldNumber].erase(index);
        }

        indexToNumber[index] = number;
        numberToIndex[number].insert(index);
    }
    
    int find(int number) {
        if (numberToIndex.find(number) != numberToIndex.end() && !numberToIndex[number].empty()) {
            return *numberToIndex[number].begin();
        }

        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

