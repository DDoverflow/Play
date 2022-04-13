#include <iostream>
using namespace std;

class  Space {
public:
    istream &operator>>(istream &);
    ostream &operator<<(ostream &);
private:
    int x, y, z;
};

istream & Space::operator>>(istream &input) {
    cout << "please enter x, y, z: ";
    input >> this->x >> this->y >> this->z;
    return input;
}

ostream & Space::operator<<(ostream &output) {
    cout << "x, y, z: ";
    output << "(" << this->x << "," << this->y << "," << this->z << ")" << endl;
    return output;
}

int main() {
    Space matter;
    matter.operator>>(cin);
    matter.operator<<(cout);
    return 0;
}