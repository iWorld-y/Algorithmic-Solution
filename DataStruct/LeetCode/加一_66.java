package leetcode;

public class 加一_66 {
}

class plusOne {
    public int[] plusOne(int[] digits) {
        int len = digits.length;
        if (digits[len - 1] != 9) {
            digits[len - 1]++;
            return digits;
        } else {
            int maxNine = 0;
            for (int i = len - 1; i >= 0; i--) {
                if (digits[i] != 9) {
                    break;
                }
                maxNine++;
            }
            if (maxNine == len) {
                int[] arr = new int[len + 1];
                arr[0] = 1;
                for (int i = 1; i <= len; i++) {
                    arr[i] = 0;
                }
                return arr;
            } else {
                digits[len - maxNine - 1]++;
                for (int i = len - maxNine; i < len; i++) {
                    digits[i] = 0;
                }
                return digits;
            }
        }
    }
}