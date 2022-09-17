package leetcode;

public class 范围求和2_598 {
    public static void main(String[] args) {
        maxCount m = new maxCount();
        int[][] arr = new int[][]{};
        System.out.println(m.maxCount(3, 3, arr));
    }
}

class maxCount {
    public int maxCount(int m, int n, int[][] ops) {
        for (int[] op : ops) {
            m = m < op[0] ? m : op[0];
            n = n < op[1] ? n : op[1];
        }
        return m * n;
    }
}