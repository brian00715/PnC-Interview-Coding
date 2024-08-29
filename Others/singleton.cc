#include <iostream>
#include <mutex>

class Singleton
{
public:
    // 禁用拷贝构造函数和赋值操作符
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

    // 获取单例实例的静态方法
    static Singleton &getInstance()
    {
        // 使用局部静态变量，C++11 保证了线程安全
        static Singleton instance;
        return instance;
    }

    void someMethod() { std::cout << "Singleton method called!" << std::endl; }

private:
    // 私有构造函数，防止直接实例化
    Singleton() { std::cout << "Singleton constructor called!" << std::endl; }

    // 可选的析构函数（如果需要做一些清理工作）
    ~Singleton() { std::cout << "Singleton destructor called!" << std::endl; }
};

int main()
{
    // 获取单例实例
    Singleton &s1 = Singleton::getInstance();
    Singleton &s2 = Singleton::getInstance();

    // 调用单例的方法
    s1.someMethod();

    // 验证 s1 和 s2 是否为同一个实例
    if (&s1 == &s2) { std::cout << "s1 and s2 are the same instance." << std::endl; }
    else { std::cout << "s1 and s2 are different instances." << std::endl; }

    return 0;
}
