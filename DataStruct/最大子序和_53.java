package 力扣;

public class 最大子序和_53 {
    public static void main(String[] args) {
        MaximalSubsequenceSum solution = new MaximalSubsequenceSum();
        int temp = solution.maxSubArray(new int[]{-2, 1, -3, 4, -1, 2, 1, -5, 4});
        System.out.println(temp);
    }
}

class MaximalSubsequenceSum {
    public int maxSubArray(int[] nums) {
        int max = nums[0], sum = 0;
        for (int num : nums) {
            if (sum > 0) {
                sum += num;
            } else {
                sum = num;
            }
            max = Math.max(max, sum);
        }
        return max;
    }
}