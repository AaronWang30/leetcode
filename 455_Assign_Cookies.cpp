//solution 1 heap
class Solution {
public:
    bool cmp(int a, int b) {
    return a>b;
    }  
    int findContentChildren(vector<int>& g, vector<int>& s) {//g->children, s->cookie
        if(!g.size()||!s.size()) return 0;
        make_heap(g.begin(),g.end(), cmp);
        make_heap(s.begin(), s.end(), cmp);
        int cnt(0);
        int temps, tempg;
        while(!s.empty()&&!g.empty()) {
             pop_heap(s.begin(), s.end(), cmp);
             temps=s.back();
             s.pop_back();
             pop_heap(g.begin(), g.end(), cmp);
             tempg=g.back();
             g.pop_back();
             if(tempg<=temps) ++cnt; 
             else {
                 while(tempg>temps&&!s.empty()) {
                    pop_heap(s.begin(), s.end(), cmp);
                    temps=s.back();
                    s.pop_back();
                 }
                 if(tempg<=temps) ++cnt;
             }
        }
        return cnt; 
    }
};
//solution 2 sort

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {//g->children, s->cookie
        if(s.empty()||g.empty()) return 0;
        int cnt(0), pointA(0), pointB(0);
        stable_sort(g.begin(), g.end());
        stable_sort(s.begin(), s.end());
        while(pointA<g.size()&&pointB<s.size()) {
            if(s[pointB]>=g[pointA]) {
                ++pointA;
                ++pointB;
                ++cnt;
            } else ++pointB;
        }
        return cnt; 
    }
};