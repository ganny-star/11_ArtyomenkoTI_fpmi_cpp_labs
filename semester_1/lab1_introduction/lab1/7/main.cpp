#include <iostream>

using namespace std;

int main()
{

    int n;

    cout << "How many numbers: " << endl;
    cin >> n;

    cout << "Writ numbers: ";
    int k, k_min, k_max, sum = 0;

    cin >> k;
    k_min = k;
    k_max = k;
    sum += k;

    for(int i = 1; i < n; i++) {
        cin >> k;
        if(k_min > k) k_min = k;
        if(k_max < k) k_max = k;
        sum += k;
    }

    cout << "Average: " << 1.0*sum/n << endl;
    cout << "Min: " << k_min << endl;
    cout << "Max: " << k_max << endl;

    return 0;
}
