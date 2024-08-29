#include "../header.hpp"

class LinkList
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node(int data) : data(data), next(nullptr) {}
    };
    Node *head;

public:
    LinkList()
    {
        head = nullptr;
    }

    void append(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *p = head;
        // find the last node
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = newNode;
    }

    bool insert_after(int target_data, int new_data)
    {
        Node *newNode = new Node(new_data);
        if (head == nullptr)
        {
            head = newNode;
            return true;
        }
        Node *p = head;
        while (p != nullptr)
        {
            if (p->data == target_data)
            {
                newNode->next = p->next;
                p->next = newNode;
                return true;
            }
            p = p->next;
        }
        return false;
    }

    bool insert_before(int target_data, int new_data)
    {
        Node *newNode = new Node(new_data);
        if (head == nullptr)
        {
            head = newNode;
            return true;
        }
        Node *p = head;
        while (p->next != nullptr)
        {
            if (p->next->data == target_data)
            {
                newNode->next = p->next;
                p->next = newNode;
                return true;
            }
            p = p->next;
        }
        return false;
    }

    bool del(int data)
    {
        if (head == nullptr)
        {
            return true;
        }
        Node *p = head;
        while (p->next != nullptr)
        {
            p = p->next;
            if (p->next->data == data)
            {
                Node *tmp = p->next;
                p->next = p->next->next;
                delete tmp;
                return true;
            }
        }
        return false;
    }

    void print()
    {
        Node *p = head;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    LinkList l;
    // append random numbers
    vector<int> numbers = {65, 89, 96, 16, 60, 43, 34, 20, 82};
    for (int i = 0; i < numbers.size(); i++)
    {
        l.append(numbers[i]);
    }
    l.print();

    // insert after
    cout << "insert 100 after 16: " << endl;
    cout << "before: ";
    l.print();
    cout << "after: ";
    l.insert_after(16, 100);
    l.print();

    // insert before
    cout << "insert 200 before 16: " << endl;
    cout << "before: ";
    l.print();
    cout << "after: ";
    l.insert_before(16, 200);
    l.print();

    // delete
    cout << "delete 20:" << endl;
    cout << "before: ";
    l.print();
    cout << "after: ";
    l.del(20);
    l.print();

    // append
    cout << "append 300:" << endl;
    cout << "before: ";
    l.print();
    cout << "after: ";
    l.append(300);
    l.print();
    return 0;
}
