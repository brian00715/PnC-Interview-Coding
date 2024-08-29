def convolve2d(input_matrix, kernel):
    input_size = len(input_matrix)
    kernel_size = len(kernel)

    output_size = input_size - kernel_size + 1

    output = [[0] * output_size for _ in range(output_size)]

    for i in range(output_size):
        for j in range(output_size):
            sum = 0
            for k in range(kernel_size):
                for l in range(kernel_size):
                    sum += input_matrix[i + k][j + l] * kernel[k][l]
            output[i][j] = sum

    return output


# 示例：定义输入和卷积核
input_matrix = [[1, 2, 3, 0], [0, 1, 2, 3], [3, 0, 1, 2], [2, 3, 0, 1]]

kernel = [[2, 0], [0, 1]]

# 调用函数
result = convolve2d(input_matrix, kernel)
for row in result:
    print(row)
