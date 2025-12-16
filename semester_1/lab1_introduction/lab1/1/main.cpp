#include <iostream>

using namespace std;

int main()
{
    cout << "Write a, b and d: " << endl;
    int a, b, d;
    cin >> a >> b >> d;

    if (a % 3 != 0 && d % 3 == 0) return 0;

    for(int a0 = a; a0 <= b; a0 += d) {

        if(a0 % 3 == 0) cout << a0 << " ";

    }

    return 0;
}
