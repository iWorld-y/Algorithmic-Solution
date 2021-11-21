package 力扣;

public class 买卖股票的最佳时机2_122 {
    public static void main(String[] args) {
        maxProfit m = new maxProfit();
        System.out.println(m.maxProfit(new int[]{7, 1, 5, 3, 6, 4}));
    }
}

class maxProfit {
    public int maxProfit(int[] prices) {
        int len = prices.length;
        int ans = 0;
        for (int i = 1; i < len; i++) {
            ans += Math.max(prices[i] - prices[i - 1], 0);
        }
        return ans;
    }
}