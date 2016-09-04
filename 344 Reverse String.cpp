class Solution {
public:
	string reverseString(string s) {
		int n = s.size();
		string str(n, ' ');
		for (int i = 0; i < n; i++) {
			str[n - 1 - i] = s[i];
		}
		return str;
	}
	string reverseString(string s) {
		std::reverse(s.begin(), s.end());
		return s;
	}
};