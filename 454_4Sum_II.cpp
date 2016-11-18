//Hashmap O(n^2)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int size = A.size();
        int temp;
        if(!size) return 0;
        int cnt(0);
        unordered_map<int, int> first;
        unordered_map<int, int> second;
        for(int i=0;i<size;++i) {
            for(int j=0;j<size;++j) {
                ++first[A[i]+B[j]];
                ++second[C[i]+D[j]];
            }
        }
        for(auto x:first) {
            cnt+=x.second*second[-x.first];
        }
        return cnt;
    }
};
//Divide O(n^2)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int size = A.size();
        int temp;
        if(!size) return 0;
        int cnt(0);
        size = size * size;
        vector<int> first(size);
        vector<int> second(size);
        for(auto &i:A) {
            for(auto &j:B) {
                first[cnt++] = i+j;
            }
        }
        cnt=0;
        for(auto &i:C) {
            for(auto &j:D) {
                second[cnt++] = i+j;
            }
        }
        cnt=0;
        sort(first.begin(), first.end());
        sort(second.begin(), second.end());
        cnt=0;
        for(int i=0;i<size;++i) {
                    auto p1 = lower_bound(second.begin(), second.end(), -first[i]);
                    auto p2 = upper_bound(second.begin(), second.end(), -first[i]);
                    cnt+=p2-p1;
        }
        return cnt;
    }
};