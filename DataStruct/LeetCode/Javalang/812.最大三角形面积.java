/*
 * @lc app=leetcode.cn id=812 lang=java
 *
 * [812] 最大三角形面积
 */

// @lc code=start
class Solution {
    private double distance(int x1, int y1, int x2, int y2) {
        return Math.sqrt(Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2));
    }

    private boolean isLegal(int a, int b, int c) {
        return a + b >= c || a + c >= b || b + c >= a;
    }

    public double largestTriangleArea(int[][] points) {
        double ans = 0;
        int len = points.length;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                for (int k = j + 1; k < len; k++) {
                    double a = this.distance(points[i][0], points[i][1], points[j][0], points[j][1]);
                    double b = this.distance(points[j][0], points[j][1], points[k][0], points[k][1]);
                    double c = this.distance(points[i][0], points[i][1], points[k][0], points[k][1]);
                    if (!this.isLegal((int) a, (int) b, (int) c)) {
                        continue;
                    }
                    double p = (a + b + c) / 2;
                    double heron = Math.sqrt(p * Math.abs(p - a) * Math.abs(p - b) * Math.abs(p - c));
                    ans = Math.max(ans, heron);
                }
            }
        }
        return ans;
    }
}
// @lc code=end
