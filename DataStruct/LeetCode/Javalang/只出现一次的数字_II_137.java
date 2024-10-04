package leetcode;

public class 只出现一次的数字_II_137 {
    public static void main(String[] args) {
        aNumberThatAppearsOnlyOnce a = new aNumberThatAppearsOnlyOnce();
        System.out.println(a.singleNumber(new int[]{0, 1, 0, 1, 0, 1, 99}));
    }
}

class aNumberThatAppearsOnlyOnce {
    public int singleNumber(int[] nums) {
        int ans = nums[0];
        for (int num : nums) {
            ans ^= num;
        }
        return ans;
    }
}