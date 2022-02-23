package 力扣;

import java.util.ArrayList;
import java.util.List;

public class 最长公共前缀_14 {
    public static void main(String[] args) {
        String[] strs = new String[]{"reflower", "flow", "flight"};
        longestCommonPrefix l = new longestCommonPrefix();
        System.out.println(l.longestCommonPrefix(strs));
    }
}

class longestCommonPrefix {
    public String longestCommonPrefix(String[] strs) {
        StringBuilder ans = new StringBuilder();
        int minLen = Integer.MAX_VALUE;
        for (String s : strs) {
            minLen = Math.min(minLen, s.length());
        }
        for (int col = 0, up = 0; col < minLen; col++) {
            for (int down = 0; down < strs.length; down++) {
                if (strs[up].charAt(col) != strs[down].charAt(col)) {
                    return ans.toString();
                }
            }
            ans.append(strs[up].charAt(col));
        }
        return ans.toString();
    }
}