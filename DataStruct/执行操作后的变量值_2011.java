package 力扣;

import java.util.*;

public class 执行操作后的变量值_2011 {
    public static void main(String[] args) {
        Solution2011 s = new Solution2011();
        System.out.println(s.finalValueAfterOperations(new String[]{"X++","++X","--X","X--"}));
    }
}

class Solution2011 {
    public int finalValueAfterOperations(String[] operations) {
        int x = 0;
        for (var op : operations) {
            if (op.contains("+")) {
                x++;
            } else {
                x--;
            }
        }
        return x;
    }
}