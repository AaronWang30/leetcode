class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> r;
        if(n==0) return r;
        r.resize(n);
        for(int i=1;i<=n;++i) {
            if(i%3==0) {
                r[i-1] += "Fizz";
            }
            if(i%5==0) {
                r[i-1] += "Buzz";
            }
            if(r[i-1].size()==0) {
                r[i-1] += to_string(i);
            }
        }
        return r;
    }
};