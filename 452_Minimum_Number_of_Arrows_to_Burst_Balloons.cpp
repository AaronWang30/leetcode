class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int cnt(0);
        sort(points.begin(),points.end(),
            [](pair<int, int> p, pair<int, int> q){ return p.first < q.first || (p.first == q.first && p.second < q.second); });
        for(int i=0;i<points.size();++i) {
            int p(points[i].second);
            int j(++i);
            while(j<points.size()&&points[j].first<=p) { 
                p = min(p, points[j].second);
                ++j;
            }
            ++cnt;
            i=--j;
        }
        return cnt;
        
    }
};