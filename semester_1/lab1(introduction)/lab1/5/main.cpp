#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int m, n;

    cout << "Write m and n: " << endl;
    cin >> m >> n;

    for (int i = 1; i <= min(m, n); i++) {

        if (m % i == 0 && n % i == 0) cout << i << ' ';

    }


    return 0;
}
