#include <iostream>

using namespace std;

int doublefact(int k) {

    if (k != 1) return k * doublefact(k-2);
    else return 1;

}

int main()
{
    int n;
    cout << "Write n: " << endl;
    cin >> n;

    int even_n = n/2*2, odd_n = n - (n % 2 == 0);

    int sum_even_num = (n != 1) * (2+even_n)*even_n/4;
    int mult_odd_num = doublefact(odd_n);

    cout << "sum even num is " << sum_even_num << endl;
    cout << "mult odd num is " << mult_odd_num << endl;


    return 0;
}
