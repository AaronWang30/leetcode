class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream s1(version1), s2(version2);
        int v1, v2;
        string str1, str2;
        while(true) {
            v1 = 0;
            v2 = 0;
            if(getline(s1, str1, '.'))
                v1 = stoi(str1);
            if(getline(s2, str2, '.'))
                v2 = stoi(str2);
            if(!s1 && !s2) return 0;
            if(v1 > v2) return 1;
            if(v1 < v2) return -1;
        }
        return 0;
    }
};