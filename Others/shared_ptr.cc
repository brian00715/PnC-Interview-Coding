template <typename T> class SharedPtr
{
private:
    T *ptr;
    unsigned *count;

    void release()
    {
        if (--(*count) == 0)
        {
            delete ptr;
            delete count;
        }
    }

public:
    // default constructor
    SharedPtr() : ptr(nullptr), count(new unsigned(0))
    {
    }

    // constructor
    explicit SharedPtr(T *obj) : ptr(obj), count(new unsigned(1))
    {
    }

    // copy constructor
    SharedPtr(const SharedPtr<T> &obj) : ptr(obj.ptr), count(obj.count)
    {
        ++(*count);
    }

    // 移动构造函数
    SharedPtr(SharedPtr &&other) noexcept : ptr(other.ptr), count(other.count)
    {
        other.ptr = nullptr;
        other.count = nullptr;
    }

    // destructor
    ~SharedPtr()
    {
        release();
    }

    // 拷贝运算符
    SharedPtr &operator=(const SharedPtr &other)
    {
        if (this != &other)
        {
            release();
            ptr = other.ptr;
            count = other.count;
            ++(*count);
        }
        return *this;
    }

    // 移动赋值运算符
    SharedPtr &operator=(SharedPtr &&other) noexcept
    {
        if (this != &other)
        {
            release();
            ptr = other.ptr;
            count = other.count;
            other.ptr = nullptr;
            other.count = nullptr;
        }
        return *this;
    }

    // * operator
    T &operator*() const
    {
        return *ptr;
    }

    // -> operator
    T *operator->() const
    {
        return ptr;
    }

    // get the current reference count
    unsigned get_count() const
    {
        return *count;
    }

    // get the managed pointer
    T *get() const
    {
        return ptr;
    }
};
