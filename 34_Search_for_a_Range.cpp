class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> r(2,-1);
        if(nums.size()==0) {
            return r;
        }
        auto l = lower_bound(nums.begin(), nums.end(), target);
        auto h = upper_bound(nums.begin(), nums.end(), target);
        if(*l!=target) return r;
        r[0] = l - nums.begin();
        r[1] = h - nums.begin() - 1;
        return r;
        
    }
};