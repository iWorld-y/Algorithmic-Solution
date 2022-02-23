package 力扣;

import java.util.Arrays;

public class 丢失的数字_268 {
}

class missingNumber {
	public int missingNumber(int[] nums) {
		int len = nums.length;

		if (len == 1 && nums[0] != 1) {
			return 1;
		}
		int sum = (1 + len) * len / 2;
		// int numsSum = Arrays.stream(nums).sum();
		int numsSum = 0;
		for (int num : nums) {
			numsSum += num;
		}
		return sum - numsSum;
	}
}