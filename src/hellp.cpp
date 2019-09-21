#include <bitset>
#include <iostream>
using namespace std;
int main() {
    bitset<2> b;
    b.set(0);
    for (int i = 0; i < 2; ++i)
        cout << b[i] << endl;
    return 0;
}
