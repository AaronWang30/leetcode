class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char, int> h;
        vector<string> v(s.size()+1,""); 
        string r;//return string
        for(char i:s) 
            ++h[i];
            
        for(auto x:h) 
            v[x.second].append(x.second, x.first);
            
        for(int i=s.size();i>0;--i) {
                 r+=v[i];
        }

        return r;
    }
};