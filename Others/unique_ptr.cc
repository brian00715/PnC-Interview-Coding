template <typename T> class UniquePtr
{
private:
    T *ptr;

public:
    UniquePtr() : ptr(nullptr)
    {
    }

    explicit UniquePtr(T *obj) : ptr(obj)
    {
    }

    // 禁用拷贝构造函数
    UniquePtr(const UniquePtr &other) = delete;

    // 禁用拷贝赋值运算符
    UniquePtr &operator=(const UniquePtr &other) = delete;

    // 移动构造函数
    UniquePtr(UniquePtr &&other) noexcept : ptr(other.ptr)
    {
        other.ptr = nullptr;
    }

    // 移动赋值运算符
    UniquePtr &operator=(UniquePtr &&other) noexcept
    {
        if (this != &other)
        {
            reset();
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    ~UniquePtr()
    {
        reset();
    }

    void reset(T *obj = nullptr)
    {
        if (ptr) { delete ptr; }
        ptr = obj;
    }

    T &operator*() const
    {
        return *ptr;
    }

    T *operator->() const
    {
        return ptr;
    }

    T *get() const
    {
        return ptr;
    }
};
