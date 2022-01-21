#include <iostream>
#include <string>
using namespace std;
template<typename T>
class MyVector {
public:
    MyVector()
    {
        cap = alloc;
        vector = (T*)malloc(sizeof(T) * alloc);
        elem_num = 0;
    };

    void push_back(const T &data);
    void pop_back();

    bool empty() const;
    size_t size() const;
    size_t capacity() const;
    T &operator[](size_t pos);

    ~MyVector();
private:
    T *vector = nullptr;
    size_t cap;
    size_t elem_num;
    const int alloc = 20;
};

template<typename T>
MyVector<T>::~MyVector() {
    free(vector);
}

template<typename T>
void MyVector<T>::push_back(const T &data) {
    if (elem_num < cap) 
    {
        *(vector + elem_num) = data;
        elem_num++;
    }
    else 
     {
        vector = (T*)realloc(vector, sizeof(T) * cap * 2);
        cap *= 2;

        if (vector) {
            *(vector + elem_num) = data;
            elem_num++;
        }
    }
}

template<typename T>
void MyVector<T>::pop_back() {
    if (empty())
        return;
    elem_num--;
}

template<typename T>
T &MyVector<T>::operator[](size_t pos) 
{
    if (pos >= 0 &&  pos <= elem_num)
        return *(this->vector + pos);
    throw std::out_of_range("Out of bounds element access");
}

template<typename T>
size_t MyVector<T>::capacity() const 
{
    return cap;
}

template<typename T>
bool MyVector<T>::empty() const {
    return elem_num == 0;
}

template<typename T>
size_t MyVector<T>::size() const {
    return elem_num;
}

struct MyClass {
    int num;
    double num2;
};

int main() {
    MyVector<MyClass> m1;

    m1.push_back({1, 1.1});
    m1.push_back({1, 1.2});
    m1.push_back({1, 1.3});
    m1.push_back({1, 1.4});

    for (size_t i = 0; i < m1.size(); ++i) {
        cout << m1[i].num << ", " << m1[i].num2 << endl;
    }

    cout << "/ ------------------- /" << endl;
    m1.pop_back();
    m1.pop_back();

    for (size_t i = 0; i < m1.size(); ++i) {
        cout << m1[i].num << ", " << m1[i].num2 << endl;
    }

    return 0;
}
