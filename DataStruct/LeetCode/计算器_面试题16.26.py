class Solution:
    def __init__(self):
        self.operatorPrecedence = {'+': 0, '-': 0, '*': 1, '/': 1}

    def calculate(self, expression: str) -> int:
        numStack = []
        operStack = []
        i = 0
        while (i < len(expression)):
            if (expression[i] == ' '):
                i += 1
                continue
            elif (expression[i].isdigit()):
                tempNum = 0
                while (i < len(expression) and expression[i].isdigit()):
                    tempNum = tempNum * 10 + ord(expression[i]) - ord('0')
                    i += 1
                numStack.append(tempNum)
            else:
                while (len(operStack) != 0 and self.priority(operStack[-1], expression[i])):
                    # 操作符栈不为空, 且栈中的操作符优先级低于当前 i 指向的操作符
                    self.calc(numStack, operStack)
                operStack.append(expression[i])
                i += 1
        while (len(operStack) != 0):
            self.calc(numStack, operStack)
        return numStack.pop()

    def priority(self, operInStack: str, operInExp: str) -> bool:
        return self.operatorPrecedence[operInStack] >= self.operatorPrecedence[operInExp]

    def calc(self, numStack: list, operStack: list) -> None:
        rightNum = numStack.pop()
        leftNum = numStack.pop()
        op = operStack.pop()
        ans = 0
        if (op == '+'):
            ans = leftNum + rightNum
        elif (op == '-'):
            ans = leftNum - rightNum
        elif (op == '*'):
            ans = leftNum * rightNum
        elif (op == '/'):
            ans = leftNum / rightNum
        ans = int(ans)
        numStack.append(ans)


s = Solution()
print(s.calculate("14/3*2"))
print(s.calculate("3+2*2"))
print(s.calculate(" 3/2 "))
print(s.calculate(" 3+5 / 2 "))
