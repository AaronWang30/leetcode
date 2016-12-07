class Solution {
public:
    int climbStairs(int n) {
        if(n==0||n==1) return 1;
        int prev(0), cur(1), temp(0);
        for(int i=0;i<n;++i) {
            temp = prev + cur;
            prev = cur;
            cur = temp;
        }
        return temp;
    }
};