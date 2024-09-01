#include <iostream>
#include <vector>

// 分区函数，使用第一个元素作为基准元素，双指针法
int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[low]; // 选择第一个元素作为基准
    int left = low + 1;   // 左指针从第二个元素开始
    int right = high;     // 右指针从最后一个元素开始

    while (true)
    {
        while (left <= right && arr[right] > pivot) { right--; }
        while (left <= right && arr[left] < pivot) { left++; }

        // 如果左指针超过右指针，结束循环
        if (left > right) { break; }

        std::swap(arr[left], arr[right]);
    }

    // 交换基准元素与右指针所指的元素
    std::swap(arr[low], arr[right]);

    return right;
}

void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // 找到基准元素的位置

        quickSort(arr, low, pi - 1);  // 对基准元素左边的部分排序
        quickSort(arr, pi + 1, high); // 对基准元素右边的部分排序
    }
}


// 非递归版本
void quickSortNoRecur(std::vector<int> &arr, int low, int high) {}

int main()
{
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    std::cout << "排序后的数组: ";
    for (int i = 0; i < n; i++) { std::cout << arr[i] << " "; }
    std::cout << std::endl;
    return 0;
}
