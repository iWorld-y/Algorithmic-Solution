package 力扣;

import java.util.*;

class Calculate {
    private Stack<Integer> numStack = new Stack<>();
    private Stack<Character> operStack = new Stack<>();
    private HashMap<Character, Integer> operPrecedence = new HashMap<>();

    private boolean isDigit(char ch) {
        return '0' <= ch && ch <= '9';
    }

    private boolean priority(char operInStack, char operInExp) {
        return this.operPrecedence.get(operInStack) <= this.operPrecedence.get(operInExp);
    }

    private void calc(Stack<Integer> numStack, Stack<Character> operStack) {
        int rigthNum = numStack.pop(), leftNum = numStack.pop();
        char op = operStack.pop();
        int ans = 0;
        switch (op) {
            case '+':
                ans = leftNum + rigthNum;
                break;
            case '-':
                ans = leftNum - rigthNum;
                break;
            case '*':
                ans = leftNum * rigthNum;
                break;
            case '/':
                ans = leftNum / rigthNum;
                break;
            default:
                break;
        }
        numStack.push(ans);
    }

    public int calculate(String s) {
        this.operPrecedence.put('+', 0);
        this.operPrecedence.put('-', 0);
        this.operPrecedence.put('*', 1);
        this.operPrecedence.put('/', 1);
        char[] expression = s.toCharArray();
        for (int i = 0; i < expression.length; ) {
            if (this.isDigit(expression[i])) {
                // 字符串数字部分转 int
                int tempNum = 0;
                for (; i < expression.length && this.isDigit(expression[i]); i++) {
                    tempNum = tempNum * 10 + expression[i] - '0';
                }
                numStack.push(tempNum);
            } else if (expression[i] != ' ') {
                // 字符串 操作符
                while (operStack.size() != 0 && this.priority(operStack.peek(), expression[i])) {
                    this.calc(numStack, operStack);
                }
                operStack.push(expression[i++]);
            }
        }
        while (operStack.size() != 0) {
            this.calc(numStack, operStack);
        }
        return numStack.pop();
    }
}

class 计算器_面试题16_26 {
    public static void main(String[] args) {
        Calculate c = new Calculate();
        System.out.println(c.calculate("14/3*2"));
        System.out.println(c.calculate("3+2*2"));
        System.out.println(c.calculate(" 3/2 "));
        System.out.println(c.calculate(" 3+5 / 2 "));
    }
}