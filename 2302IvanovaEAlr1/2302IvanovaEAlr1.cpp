#include <iostream>

using namespace std;


struct Node
{
    int data;
    Node* next;
};

class List
{
private:
    Node* head;
    int size;

public:

    List()
    {
        head = NULL;
        size;
    }
    ~List() {
        Node* current = head;
        Node* next;

        while (current != NULL) {
            next = current->next;
            delete current;
            current = next;
        }
    }


    void push_back(int data) //1.добавление в конец списка
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else {
            Node* current = head;

            while (current->next != NULL)
            {
                current = current->next;
            }

            current->next = newNode;
        }

        size++;
    }

    void push_front(int data) //2.добавление в начало списка
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        size++;
    }


    void pop_back() //3.удаление последнего элемента
    {
        if (head == NULL)
        {
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
        }
        else
        {
            Node* current = head;

            while (current->next->next != NULL)
            {
                current = current->next;
            }

            delete current->next;
            current->next = NULL;
        }

        size--;
    }

    void pop_front() //4.удаление первого элемента
    {
        if (head == NULL)
        {
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void add_element(int index, int data) //5.добавление элемента по индексу
    {
        if (index < 0 || index > size) {
            return;
        }

        if (index == 0) {
            push_front(data);
        }
        else if (index == size)
        {
            push_back(data);
        }
        else
        {
            Node* newNode = new Node;
            newNode->data = data;

            Node* current = head;

            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
            size++;
        }
    }
    Node* getelement(int index) //6 получение элемента по индексу
    {
        int i = 0;
        Node* tmp = head;
        while (i != index) {
            tmp = tmp->next;
            i++;
        }
        return tmp;
    }


    void delete_element(int index) //7 удаление элемента по индексу
    {
        if (index < 0 || index >= size)
        {
            return;
        }

        if (index == 0)
        {
            pop_front();
        }
        else if (index == size - 1)
        {
            pop_back();
        }
        else
        {
            Node* current = head;

            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }

            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
        }
    }


    int getsize() //8. получение размера списка
    {
        return size;
    }

    void clear() //9 очистка списка
    {
        Node* current = head;
        Node* next;

        while (current != NULL) {
            next = current->next;
            delete current;
            current = next;
        }
        cout << "Элементы списка:\n" << "Список пуст\n";
        head = NULL;
        size = 0;
    }


    void replace(int index, int data) //10 замена элемента по индексу на передаваемый
    {
        if (index < 0 || index >= size) {
            return;
        }

        Node* current = head;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        current->data = data;
    }


    bool empty() //11 проверка на пустоту
    {
        if (head == NULL)
            return  true;
        else
            return false;
    }


    void reverse()  //12 меняет порядок в списке на обратный
    {
        Node* prev = NULL;
        Node* current = head;
        Node* next;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }


    void insertList(int index, List& otherList) //13 вставка другого списка с индекса
    {
        if (index < 0 || index > size) {
            return;
        }

        if (otherList.empty())
        {
            return;
        }

        if (index == 0) {
            Node* otherHead = otherList.head;
            otherList.head = NULL;
            Node* current = head;
            head = otherHead;

            while (otherHead->next != NULL)
            {
                otherHead = otherHead->next;
            }

            otherHead->next = current;
            size += otherList.size;
        }
        else if (index == size)
        {
            Node* otherHead = otherList.head;
            otherList.head = NULL;
            Node* current = head;

            while (current->next != NULL)
            {
                current = current->next;
            }

            current->next = otherHead;
            size += otherList.size;
        }
        else
        {
            Node* current = head;

            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }

            Node* otherHead = otherList.head;
            otherList.head = NULL;
            Node* next = current->next;
            current->next = otherHead;

            while (otherHead->next != NULL)
            {
                otherHead = otherHead->next;
            }

            otherHead->next = next;
            size += otherList.size;
        }
    }



    void insertListEnd(List& otherList) //14.
    {
        insertList(size, otherList);
    }
    void insertListBegin(List& otherList)//15.
    {
        insertList(0, otherList);
    }
    bool containsList(List& otherList)//16.проверка на содержание другого списка в списке
    {
        if (otherList.empty())

            return true;

        else
            return false;
    }
    void out_list()
    {
        Node* tmp = head;
        cout << "Элементы списка:\n";
        while (tmp != nullptr)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << "\n\n";
    }

    int findFirst(List list) {
        int index = 0, index_tmp = 0;
        int index2 = 1;
        while (index < size) {
            if (getelement(index) == list.getelement(0)) {
                if (list.getsize() == 1) return index;

                index_tmp = ++index;
                while (index < size) {
                    if (getelement(index)->data == list.getelement(index2)->data) {
                        index++;
                        index2++;
                        if (index2 == list.getsize()) return (index_tmp - 1);
                    }
                    else {
                        index = index_tmp;
                        index2 = 1;
                        break;
                    }
                }
            }
            index++;
        }

        return 4;
    }

    int findLast(List otherList) //18
    {
        if (otherList.getsize() > size) {
            return -1;
        }

        Node* current = head;
        Node* otherCurrent = otherList.head;
        int index = 0;
        int lastIndex = 15;

        while (current != NULL) {
            if (current == otherCurrent) {
                if (otherCurrent->next == NULL) {
                    lastIndex = index - otherList.getsize() + 1;
                }
                otherCurrent = otherCurrent->next;
            }
            else {
                otherCurrent = otherList.head;
            }
            current = current->next;
            index++;
        }

        return lastIndex;
    }


    void permutation(int ind1, int ind2) //19.обмен двух элементов
    {
        Node* tmp1 = getelement(ind1);
        Node* tmp2 = getelement(ind2);
        int tmp = tmp1->data;
        tmp1->data = tmp2->data;
        tmp2->data = tmp;
    }
};

int main()
{

    setlocale(LC_ALL, "ru");

    List l, l2, l3, l4;

    l.push_back(7);
    l.push_back(10);
    l.push_back(234);
    l.push_back(49);
    l.push_back(5);
    l.out_list();
    cout << "1.добавление в конец списка:\n\n";
    l.push_back(12);
    l.out_list();
    cout << "2.добавление в начало списка:\n\n";
    l.push_front(90);
    l.out_list();
    cout << "3.удаление последнего элемента:\n\n";
    l.pop_back();
    l.out_list();
    cout << "4.удаление первого элемента:\n\n";
    l.pop_front();
    l.out_list();
    cout << "5.добавление элемента по индексу:\n\n";
    l.add_element(2, 98);
    l.out_list();
    cout << "6. получение элемента по индексу:\n\n" << l.getelement(3) << "\n\n";
    cout << "7.удаление элемента по индексу:\n\n";
    l.delete_element(1);
    l.out_list();
    cout << "8. получение размера списка :\n\n" << "размер = " << l.getsize() << "\n\n";
    cout << "9.очистка списка:\n\n";
    l.clear();
    l.push_back(7);
    l.push_back(10);
    l.push_back(234);
    l.push_back(49);
    l.push_back(5);
    cout << "\n\n";
    l.out_list();
    cout << "10.замена элемента по индексу на передаваемый:\n\n";
    l.replace(2, 6);
    l.out_list();
    cout << "11. проверка на пустоту:\n\n";
    if (l.empty())
        cout << "Список пуст\n\n";
    else
        cout << "В списке есть элементы\n\n";

    cout << " 12. меняет порядок в списке на обратный:\n\n";
    l.reverse();
    l.out_list();
    cout << "другой список\n";
    l2.push_back(2);
    l2.push_back(8);
    l2.push_back(24);
    l2.push_back(4);
    l2.push_back(0);
    l2.out_list();
    cout << " 13. вставка другого списка начиная с индекса :\n\n";
    l.insertList(1, l2);
    l.out_list();
    l3.push_back(1);
    l3.push_back(2);
    l3.push_back(3);
    cout << " 14. вставка другого списка в конец :\n\n";
    l.insertListEnd(l3);
    l.out_list();
    l4.push_back(0);
    l4.push_back(0);
    l4.push_back(0);
    cout << " 15. вставка другого списка в начало :\n\n";
    l.insertListBegin(l4);
    l.out_list();
    cout << " 16. проверка на содержание другого списка в списке :\n\n";

    if (l.containsList(l2))
        cout << "Содержит\n\n";
    else
        cout << "Не содержит\n\n";
    cout << " 17.поиск первого вхождения:\n\n";

    cout << l.findFirst(l2) << "\n\n";

    cout << " 18. поиск последнего вхождения:\n\n";

    cout << l.findLast(l3) << "\n\n";
    cout << " 19.обмен двух элементов:\n\n";
    l.permutation(0, 5);
    l.out_list();

    return 0;
}