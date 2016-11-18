class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int j, size=nums.size();
        if(size<3) return false;
        int dpIndex[size]{-1};
        vector<int> findMin(nums.begin(), nums.end());
        for(int i=1;i<size;++i)
            findMin[i] = min(findMin[i], findMin[i-1]);

        for(int i=1;i<size;++i) {
            j=i-1;
            while(j!=-1&&nums[j]<=nums[i])
                j = dpIndex[j];
            dpIndex[i]=j;
        }
        for(int i=2;i<size;++i) {
            j=dpIndex[i];
            if(j>0&&findMin[j-1]<nums[i]) 
                return true;
        }
        return false;
    }
};