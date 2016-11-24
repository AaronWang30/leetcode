class Solution {
private: 
    unordered_set<string> s;
    unordered_map<string, unordered_map<string, double>> h;
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> r;
        for(int i=0; i < equations.size();++i) {
            h[equations[i].first].insert(make_pair(equations[i].second, values[i]));
            if(values[i]!=0)
                h[equations[i].second].insert(make_pair(equations[i].first,1/values[i]));
        }
        for(auto x:queries) {
            s.clear();
            double result = check(x.first, x.second);
            if(result!=0) r.push_back(result);
            else r.push_back(-1);
        }
        return r;
    }
    double check(string a, string b) {
        if(h[a].find(b)!=h[a].end()) return h[a][b];
        else {
            for(auto x:h[a]) {
                if(s.find(x.first)==s.end()) {
                    s.insert(x.first);
                    double temp = check(x.first, b);
                    if(temp!=0) return x.second*temp;
                }
            }
        }
        return 0;
    }
};