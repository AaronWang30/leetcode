class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()) return "";
        int i(0);
        while(0!=strs[0].size()) {
            for(int j=0; j<strs.size()-1; ++j) {
                if(i==strs[j].size()||strs[j+1][i]!=strs[j][i])
                    return strs[0].substr(0,i);
            }
            if(++i==strs[0].size()) return strs[0];
        }
        return "";
    }
};