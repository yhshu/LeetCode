/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector <Point> &points) {
        const int size = points.size();
        int res = 0;
        for (int i = 0; i < size; i++) {
            map<pair<int, int>, int> lines;
            int samePoint = 0; // 相同点数
            int vertical = 0; // 斜率不存在的垂直直线
            int localmax = 0;
            for (int j = i + 1; j < size; j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    samePoint++;
                    continue;
                } else if (points[j].x == points[i].x)
                    vertical++;
                else {
                    int x = points[j].x - points[i].x;
                    int y = points[j].y - points[i].y;
                    int gcd = GCD(x, y);
                    x /= gcd;
                    y /= gcd;
                    lines[make_pair(x, y)]++;
                    localmax = max(lines[make_pair(x, y)], localmax);
                }
                localmax = max(vertical, localmax);
            }
            res = max(res, localmax + samePoint + 1); // +1 是加上自身
        }
        return res;
    }

private:
    int GCD(int a, int b) {
        if (!b)
            return a;
        else return GCD(b, a % b);
    }
};