#include <iostream>
using namespace std;

template<typename undef1>
class  MyArray {
public:
    MyArray() {}
    MyArray(int size): Capacity(size) {this->arr = new undef1[Capacity];}
    MyArray(MyArray<undef1> &matter);
    MyArray<undef1> &operator=(const MyArray<undef1> &matter);
    ~MyArray();
    void Add_point(undef1 value);
    void Del_point();
    void Show();
    undef1 Get_Ele(int index);
    void Show_inform();
private:
    undef1 *arr;
    int Capacity;
    int length = 0;
};

template<typename undef1>
MyArray<undef1>::MyArray(MyArray<undef1> &matter) {
    this->length = matter.length;
    this->Capacity = matter.Capacity;
    this->arr = new undef1[matter.Capacity];
    for (int i = 0; i < matter.length; i++)
        this->arr[i] = matter.arr[i];
}

template<typename undef1>
MyArray<undef1>::~MyArray() {
    if (this->arr != nullptr) {delete[] this->arr;  this->arr = nullptr;}
}

template<typename undef1>
void MyArray<undef1>::Add_point(undef1 value) {
    if (this->length == this->Capacity) cout << "arr is full!" << endl;
    else {this->arr[this->length] = value;  this->length++;}
}

template<typename undef1>
void MyArray<undef1>::Del_point() {
    if (this->length == 0) {cout << "Array is empty" << endl;  return;}
    this->length--;
    cout << "already delete: " << this->arr[this->length] << endl;
}

template<typename undef1>
undef1 MyArray<undef1>::Get_Ele(int index) {
    if (index >= this->length) {cout << "index have trouble" << endl;}
    else return this->arr[index];
}

template<typename undef1>
void MyArray<undef1>::Show_inform() {
    cout << "length: " << this->length << endl;
    cout << "Capacity: " << this->Capacity << endl;
}

template<typename undef1>
void MyArray<undef1>::Show() {
    cout << "arr：";
    for (int k = 0; k < this->length; k++)
        cout << this->arr[k] << "  ";
    cout << endl;
}

template<typename undef1>
MyArray<undef1> &MyArray<undef1>::operator=(const MyArray<undef1> &matter) {
    this->length = matter.length;
    this->Capacity = matter.Capacity;
    this->arr = new undef1[matter.Capacity];
    for (int k = 0; k < matter.length; k++)
        this->arr[k] = matter.arr[k];
    return *this;
}

class  Node {
public:
    Node() {}
    Node(string name, int age): name(name), age(age) {}
    string name;
    int age;
};

ostream &operator<<(ostream &out, Node &matter) {
    out << matter.name << "\t" << matter.age << endl;
    return out;
}


int main() {
    MyArray<Node> matter(10);
    for (int k = 0; k < 10; k++)
        matter.Add_point(Node("Jack", k + 10));
    for (int k = 0; k < 5; k++)
        matter.Del_point();
    matter.Show();
    matter.Show_inform();
}

