class ProductOfNumbers {
private:
    vector<int> numsProduct;
    vector<int> zeroIndexes;

public:
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if (num == 0) {
            int zeroIndex = numsProduct.size();
            zeroIndexes.push_back(zeroIndex);
        }

        int newProduct = 0;

        if (!numsProduct.empty()) {
            int lastNum = numsProduct.back();
            if (lastNum == 0) {
                newProduct = num;
            } else {
                newProduct = numsProduct.back() * num;
            }
        } else {
            newProduct = num;
        }

        numsProduct.push_back(newProduct);
    }

    int getProduct(int k) {
        int n = numsProduct.size();
        int excludedIndex = n - k - 1;
        int zeroIndexesN = zeroIndexes.size();

        for (int i = zeroIndexesN - 1; i >= 0; --i) {
            if (zeroIndexes[i] > excludedIndex) {
                return 0;
            }
        }

        if (n == k) {
            return numsProduct.back();
        }

        int overallProduct = numsProduct.back();
        int excludedProduct = numsProduct[n - k - 1];
        int product = 0;

        if (excludedProduct == 0) {
            product = overallProduct;
        } else {
            product = overallProduct / excludedProduct;
        }

        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
