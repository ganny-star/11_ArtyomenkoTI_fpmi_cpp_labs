#include <iostream>

using namespace std;

int doublefact(int k) {

    if (k != 1 && k != 0) return k * doublefact(k-2);
    else return 1;

}

int main()
{

    int k;

    cout << "Write k: " << endl;
    cin >> k;

    cout << "k!! = " << doublefact(k);

    return 0;
}
