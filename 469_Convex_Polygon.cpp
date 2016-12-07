class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        if (points.size() < 3) return false;
        int res = -1;
        for (int i = 0; i < points.size(); i++) {
            auto pre = i == 0 ? points.back() : points[i - 1];
            auto after = i == points.size() - 1 ? points[0] : points[i + 1];
            int x1 = points[i][0] - pre[0], y1 = points[i][1] - pre[1];
            int x2 = after[0] - points[i][0], y2 = after[1] - points[i][1];
            int flag = x1 * y2 - x2 * y1;
            if (res == -1) {
                if (flag) res = flag > 0;
            }
            else if (res != flag > 0) return false;
        }
        return true;
    }
};