//KMP solution slow
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int M = str.size();
        int lps[M];
        int len(0), i(1);
        lps[0] = 0;
        while (i < M) {
            if (str[i] == str[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0)
                    len = lps[len-1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    return (lps[M-1]>0 && M%(M-lps[M-1]) == 0);
    }
};
//Factor solution much slower
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int len = str.length();
        if(len < 2) {
            return false;
        }
        for(int i=2;i<=len; i++) {
            if(len%i == 0) {
                if(check(str, i)) return true;
            }
        }
        return false;
    }
    
    bool check(string str, int repeat) {
        int len = str.length();
        string subby = str.substr(0, len/repeat);
        for(int i = 0; i < len; i++) {
            if(str[i] != subby[i%(len/repeat)]) {
                return false;
            }
        }
        return true;
    }
};