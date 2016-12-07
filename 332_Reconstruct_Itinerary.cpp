class Solution {
private:
    int size;
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, map<string, int>> h;
        for(auto x:tickets) 
            ++h[x.first][x.second];
        size = tickets.size()+1;
        vector<string> r;
        r.reserve(size);
        dfs("JFK",r,h);
        return r;
    }
    void dfs(const string &cur, vector<string> &r, unordered_map<string, map<string, int>> &h) {
        r.push_back(cur);
        for(auto &next: h[cur]) {
            if(next.second>0) {
                --next.second;
                dfs(next.first, r, h);
                if(r.size()==size) return ;
                else ++next.second;
            }

        }
        if(r.size()!=size)
            r.pop_back();
    }
};