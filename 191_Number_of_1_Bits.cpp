//By 1's
class Solution {
public:
	int hammingWeight(uint32_t n) {
    	int cnt(0);
    	while (n!=0) {
        	n &= (n - 1);
        	++cnt;
    	}
    	return cnt;
	}
};
//By digit
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt(0);
        while(n!=0) {
            cnt+=n & 1;
            n = n >> 1;
        }
        return cnt;
    }
};