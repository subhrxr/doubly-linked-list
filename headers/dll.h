#include <iostream>
using namespace std;
class dll
{
private:
    dll *head;
    dll *tail;
    int value;
    int size;
    dll *next;
    dll *prv;

public:
    dll(int value)
    {
        this->value = value;
        this->next = nullptr;
        this->prv = nullptr;
    }

    dll()
    {
        head = new dll(-1);
        tail = new dll(-1);
        head->next = tail;
        tail->prv = head;
        size = 0;
    }

    void insert(int value)
    {
        if (!head)
        {
            cout << "failure! head does not exist\n";
            return;
        }

        dll *x = new dll(value);
        x->next = head->next;
        x->prv = head;
        x->next->prv = x;
        head->next = x;
        size++;
    }

    void remove()
    {
        if (tail->prv == head)
        {
            cout << "failure! cannot remove head\n";
            return;
        }

        dll *x = tail->prv;

        tail->prv = x->prv;
        x->prv->next = tail;

        delete x;
        size--;
    }

    void remove(int index)
    {
        if (index > size)
        {
            cout << "failure! this element cannot be accessed as size < index\n";
            return;
        }

        dll *temp = head;
        while (index--)
            temp = temp->next;

        temp->next->prv = temp->prv;
        temp->prv->next = temp->next;

        delete temp;
        size--;
    }

    void remove(dll *x)
    {
        x->next->prv = x->prv;
        x->prv->next = x->next;

        delete x;
    }

    void print_list()
    {
        dll *temp = head->next;

        while (temp != tail)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }

        cout << endl;
        delete temp;
    }

    friend std::ostream &operator<<(std::ostream &stream, const dll &obj)
    {
        dll *temp = obj.head->next;

        if (obj.size == 0)
        {
            stream << "list empty\n";
            return stream;
        }
        int size = obj.size;
        while (size--)
        {
            stream << temp->value << " ";
            temp = temp->next;
        }

        stream << endl;
        return stream;
    }
};
