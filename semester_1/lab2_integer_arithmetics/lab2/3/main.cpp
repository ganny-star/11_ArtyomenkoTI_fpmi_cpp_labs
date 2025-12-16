#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, k_min = 10, i;

    cout << "Write num: " << endl;
    cin >> n;

     for(i = 1; pow(10, i-1) <= n; i++) {

     int k = n % (int)pow(10, i) / (int)pow(10, i-1);
     if(k < k_min && k != 0) k_min = k;

 }
    n = n*10 + k_min + k_min * pow(10, i);

    cout << n;


    return 0;
}
