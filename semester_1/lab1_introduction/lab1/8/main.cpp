#include <iostream>

using namespace std;

int main()
{
    double a1, a2, a3, k = 0;

    cout << "Write 10 numbers:" << endl;
    cin >> a1 >> a2 >> a3;
    if (a1 < a2) k++;
    if (a1 > a2 && a2 < a3) k++;

    for(int i = 3; i < 10; i++) {

        a1 = a2;
        a2 = a3;
        cin >> a3;
        if(a2 < a1 && a2 < a3) k++;

    }

    if (a3 < a2) k++;

    cout << k;

    return 0;
}
