//O(min(n,m)) space
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m > n) return uniquePaths(n, m);
        vector<int> cur(m, 1);
        for(int i=1;i<n;++i) {
            for(int j=1;j<m;++j) 
                cur[j] += cur[j-1];
        }
        return cur[m-1];
    }
}; 