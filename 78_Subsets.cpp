//Solution 1
class Solution {
public:
vector<vector<int> > subsets(vector<int> &S) {
	vector<vector<int> > res(1, vector<int>());
	sort(S.begin(), S.end());
	
	for (int i = 0; i < S.size(); i++) {
		int n = res.size();
		for (int j = 0; j < n; j++) {
			res.push_back(res[j]);
			res.back().push_back(S[i]);
		}
	}

	return res;
  }
};
//Solution 2
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort (S.begin(), S.end());
        int elem_num = S.size();
        int subset_num = 1 << elem_num;
        vector<vector<int> > subset_set (subset_num, vector<int>());
        for (int i = 0; i < elem_num; i++)
            for (int j = 0; j < subset_num; j++)
                if ((j >> i) & 1)
                    subset_set[j].push_back (S[i]);
        return subset_set;
    }
};