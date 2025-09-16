#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    int n;

    cout << "write n: " << endl;
    cin >> n;

    long long sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += pow(i, i);
    }

    cout << sum;

    // ѕотому что long long до +9 223 372 036 854 775 807, а последнее число при n=100 равно 10^200

     return 0;
}
