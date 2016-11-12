class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, short> h; //hashmap
        vector<int> r; //return vector
        for(auto &i: nums1) 
            if(h[i]==0) h[i]++;
        for(auto &i: nums2) 
            if(h[i]--==1) 
                r.push_back(i);
        return r;
    }
};