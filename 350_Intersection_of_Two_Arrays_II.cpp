//9ms
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return intersect(nums2, nums1);
        unordered_map<int, short> h;
        vector<int> r;
        for(auto &i:nums1) {
            ++h[i];
        }
        for(auto &i:nums2){
            if(h[i]>0) {
                r.push_back(i);
                --h[i];
            }
        }
        return r;
    }
};