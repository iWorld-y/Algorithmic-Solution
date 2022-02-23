package 力扣;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class 猜数字游戏_299 {
    public static void main(String[] args) {
        getHint g = new getHint();
        System.out.println(g.getHint("1123", "0111"));
    }
}

class getHint {

    public String getHint(String secret, String guess) {
        int bulls = 0, cows = 0;
        int[] se = new int[10];
        int[] gu = new int[10];

        for (int i = 0; i < secret.length(); i++) {
            if (secret.charAt(i) == guess.charAt(i)) {
                bulls++;
            } else {
                se[secret.charAt(i) - '0']++;
                gu[guess.charAt(i) - '0']++;
            }
        }

        for (int i = 0; i < 10; i++) {
            cows += Math.min(se[i], gu[i]);
        }
        StringBuilder builder = new StringBuilder();
        builder.append(bulls).append('A').append(cows).append('B');
        return builder.toString();
    }
}