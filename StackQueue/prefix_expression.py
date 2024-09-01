def evaluate_prefix(expression):
    stack = []
    operators = set(["+", "-", "*", "/"])

    # 从右向左扫描表达式
    for token in reversed(expression.split()):
        if token in operators:
            # 弹出栈顶的两个操作数
            operand1 = stack.pop()
            operand2 = stack.pop()

            # 计算并将结果压入栈中
            if token == "+":
                result = operand1 + operand2
            elif token == "-":
                result = operand1 - operand2
            elif token == "*":
                result = operand1 * operand2
            elif token == "/":
                result = operand1 / operand2

            stack.append(result)
        else:
            # 将操作数压入栈中
            stack.append(int(token))

    # 栈顶元素即为最终结果
    return stack.pop()


# 测试
expression = "- + * 2 3 * 5 4 9"
result = evaluate_prefix(expression)
print("前缀表达式的值为:", result)
