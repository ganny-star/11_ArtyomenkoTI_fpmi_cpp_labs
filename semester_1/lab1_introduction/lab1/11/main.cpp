#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, i;
    cout << "Input integer number: " << endl;
    cin >> n;

    for(i = 0; ; i++) {

        if (pow(2, i) > n) break;

    }

    cout << "Num in binary system: ";

    for(int j = i; j > 0; j-- ) {

        cout << n%(int)pow(2, j)/(int)pow(2, j-1);

    }

    for(i = 0; ; i++) {

        if (pow(16, i) > n) break;

    }

    cout << endl << "Num in 16-digit system: ";

    for(int j = i; j > 0; j-- ) {

        int k = n%(int)pow(16, j)/(int)pow(16, j-1);
        if (k == 10) cout << 'A';
        else if (k == 11) cout << 'B';
        else if (k == 12) cout << 'C';
        else if (k == 13) cout << 'D';
        else if (k == 14) cout << 'E';
        else if (k == 15) cout << 'F';
        else cout << k;

    }

    return 0;
}
