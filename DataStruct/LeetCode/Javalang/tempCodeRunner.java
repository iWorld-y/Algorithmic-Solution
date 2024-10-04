import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=1608 lang=java
 *
 * [1608] 特殊数组的特征值
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

public class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.largestTriangleArea(new int[][]{{1, 1}, {1, 3}, {3, 1}, {3, 3}, {2, 2}}));
        System.out.println("\n\n\n" + s.largestTriangleArea(new int[][]{
                {-35, 19}, {40, 19}, {27, -20}, {35, -3}, {44, 20}, {22, -21}, {35, 33}, {-19, 42}, {11, 47}, {11, 37}
        }));
    }
}