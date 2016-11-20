class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int size = nums.size();
        if(size == 0 || size == 1) return 0;
        stable_sort(nums.begin(), nums.end());
        int median = nums[nums.size()/2];
        int cnt(0);
        for(auto i:nums)
            cnt+=abs(i-median);
        return cnt;
    }
};