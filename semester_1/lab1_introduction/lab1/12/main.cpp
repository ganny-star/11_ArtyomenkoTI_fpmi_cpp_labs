#include <iostream>

using namespace std;

int main()
{
    int k, n;

    cout << "Input day of the week (1-7): " << endl;
    cin >> k;

    cout << "Input days in month (1-99): " << endl;
    cin >> n;

     for(int i = 1, p = 1; i < 8; i++) {

        if(i == k) {
            cout << p << ' ';
            p++;
            k++;
        }
        else cout << '  ';
     }

    return 0;
}
