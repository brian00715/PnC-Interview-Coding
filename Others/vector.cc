#include <iostream>
#include <stdexcept>

template <typename T> class Vector
{
public:
    Vector() : _size(0), _capacity(1), _data(new T[1])
    {
    }

    ~Vector()
    {
        delete[] _data;
    }

    void push_back(const T &value)
    {
        if (_size == _capacity) { resize(2 * _capacity); }
        _data[_size] = value;
        ++_size;
    }

    void pop_back()
    {
        if (_size == 0) { throw std::out_of_range("Vector is empty"); }
        --_size;
    }

    T &operator[](size_t index)
    {
        if (index >= _size) { throw std::out_of_range("Index out of bounds"); }
        return _data[index];
    }

    const T &operator[](size_t index) const
    {
        if (index >= _size) { throw std::out_of_range("Index out of bounds"); }
        return _data[index];
    }

    size_t size() const
    {
        return _size;
    }

    size_t capacity() const
    {
        return _capacity;
    }

    void resize(size_t new_capacity)
    {
        T *new_data = new T[new_capacity];
        for (size_t i = 0; i < _size; ++i)
        {
            new_data[i] = _data[i];
        }
        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;
    }

private:
    size_t _size;     // 当前元素个数
    size_t _capacity; // 容量
    T *_data;         // 存储数据的指针
};

int main()
{
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "Vector elements: ";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Vector size: " << vec.size() << std::endl;
    std::cout << "Vector capacity: " << vec.capacity() << std::endl;

    vec.pop_back();
    std::cout << "After pop_back, size: " << vec.size() << std::endl;

    return 0;
}
