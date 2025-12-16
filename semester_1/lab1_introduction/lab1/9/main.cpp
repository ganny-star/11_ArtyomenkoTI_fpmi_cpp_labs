#include <iostream>

using namespace std;

int main()
{
    cout << "Write palindrom (No mistakes): " << endl;
    int n;
    cin >> n;

    if (n/1000 == n%10 && n%1000/100 == n%100/10)
        cout << "Good job!";
    else
        cout << "very baaad(((";

    return 0;
}
