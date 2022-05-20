#include <iostream>
#include <vector>
using namespace std;

int main() {
    string matter = "0";
    for (int num = 1; num <= 3; num++)
        matter.insert(matter.begin(), '1');
    cout << matter << endl;
    return 0;
}