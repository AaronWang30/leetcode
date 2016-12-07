class Solution {
public:
    int countSegments(string s) {
        int cnt(0);
        if(s.empty()) return cnt;
        bool flag(false);
        for(int i=0;i<s.size();++i) {
            if(s[i]!=' ') {
                flag=true;
            }
            if(s[i]==' '&&flag) {
                flag = false;
                ++cnt;
            }
        }
        if(flag) ++cnt;
        return cnt;
    }
};