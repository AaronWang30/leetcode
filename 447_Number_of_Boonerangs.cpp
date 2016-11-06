class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        
        int s = points.size(), cnt=0;
        long dis;
        for(int i=0;i<s;++i) {
            unordered_map<long, int> h(s);
            for(int j=0;j!=i,j<s;++j) {
                 dis = (points[i].first - points[j].first) * (points[i].first - points[j].first)
                    + (points[i].second -  points[j].second) * (points[i].second -  points[j].second);
                ++h[dis];
            }
            for(auto &x:h) {
            cnt+=x.second*(x.second-1);
            }
        }
       
    return cnt;
        
    }
};