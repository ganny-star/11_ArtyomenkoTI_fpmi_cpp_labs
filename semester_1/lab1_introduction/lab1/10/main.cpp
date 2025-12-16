#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Write palindrom (No mistakes): " << endl;
    int n;
    bool status = true;
    cin >> n;

    for(int i = 0; i < 3; i++) {
        if(n%(int)pow(10, 6-i)/(int)pow(10, 5-i) == n%(int)pow(10, i+1)/(int)pow(10, i)) continue;
        status = false;
        break;
    }

    if (status)
        cout << "Good job!";
    else
        cout << "very baaad(((";
    return 0;
}
