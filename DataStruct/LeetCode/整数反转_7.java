package leetcode;

public class 整数反转_7 {
    public static void main(String[] args) {
        System.out.println(new Solution2().reverse(-2147483648));
        System.out.println(new Solution2().reverse(-1534236469));
        System.out.println(new Solution2().reverse(123));
    }
}

class Solution2 {
    //    public int reverse(int x) {
//        try {
//            int ans = Integer.parseInt(new StringBuffer(Math.abs(x) + "").reverse().toString());
//            return x > 0 ? ans : -ans;
//        } catch (Exception e) {
//            return 0;
//        }
//    }
    public int reverse(int x) {
//        if (Integer.MIN_VALUE >= x || x >= Integer.MAX_VALUE) {
//            return 0;
//        } else {
        int ans = 0, num = Math.abs(x), xLen = (num + "").length();
        for (int i = xLen; i > 0; i--) {
            ans += num % 10 * Math.pow(10, i - 1);
            if (-2147483648 >= ans || ans >= 2147483647) {
                return 0;
            }
            num /= 10;
        }
        return x > 0 ? ans : -ans;
//        }
    }
}