class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        if (left >= right)
            return;

        vector<int> leftPart(nums.begin() + left, nums.begin() + mid + 1);
        vector<int> rightPart(nums.begin() + mid + 1, nums.begin() + right + 1);

        int leftIdx = 0;
        int rightIdx = 0;
        int numsIdx = left;

        while (leftIdx < leftPart.size() && rightIdx < rightPart.size()) 
        {
            if (leftPart[leftIdx] <= rightPart[rightIdx]) 
            {
                nums[numsIdx++] = leftPart[leftIdx++];
            } 
            else 
            {
                nums[numsIdx++] = rightPart[rightIdx++];
            }
        }

        while (leftIdx < leftPart.size()) 
        {
            nums[numsIdx++] = leftPart[leftIdx++];
        }

        while (rightIdx < rightPart.size()) 
        {
            nums[numsIdx++] = rightPart[rightIdx++];
        }
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return;

        int mid = (left + right) >> 1;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    };

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};