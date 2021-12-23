class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;

        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int mid;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) { // 0 ... mid is asc, note that mid could be 0
                if (nums[0] <= target && target < nums[mid]) 
                    right = mid - 1;
                else 
                    left = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[n-1]) // mid ... (n-1) is asc
                    left = mid + 1;
                else 
                    right = mid - 1;
            }
        }
        return -1;
    }
};
