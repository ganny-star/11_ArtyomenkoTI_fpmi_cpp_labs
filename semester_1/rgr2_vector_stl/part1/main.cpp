#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <set>

using namespace std;

int main() {
    vector<int> v;
    int x;

    cout << "Enter numbers (end with non-number): ";
    while (cin >> x) {
        v.push_back(x);
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (v.empty()) {
        cout << "Empty vector." << endl;
        return 0;
    }

    int total = accumulate(v.begin(), v.end(), 0);
    cout << "1. Sum: " << total << endl;
    cout << "2. Count: " << v.size() << endl;

    int t;
    cout << "\nEnter number to count: ";
    cin >> t;
    int cnt = count(v.begin(), v.end(), t);
    cout << "3. Count of " << t << ": " << cnt << endl;

    int n;
    cout << "\nEnter n for 'greater than n': ";
    cin >> n;
    int cnt_gt = count_if(v.begin(), v.end(), [n](int x) { return x > n; });
    cout << "4. Count > " << n << ": " << cnt_gt << endl;

    int avg = total / v.size();
    replace(v.begin(), v.end(), 0, avg);
    cout << "5. Zeros replaced with avg: " << avg << endl;
    cout << "   Vector: ";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i != v.size() - 1) cout << ", ";
    }
    cout << endl;

    int a, b;
    cout << "\nEnter start index (0-" << v.size() - 1 << "): ";
    cin >> a;
    cout << "Enter end index (" << a << "-" << v.size() - 1 << "): ";
    cin >> b;

    if (a < 0) a = 0;
    if (b >= v.size()) b = v.size() - 1;
    if (a > b) swap(a, b);

    int range_sum = accumulate(v.begin() + a, v.begin() + b + 1, 0);
    for_each(v.begin(), v.end(), [range_sum](int &x) { x += range_sum; });
    cout << "6. Added range sum [" << a << "," << b << "]: " << range_sum << endl;
    cout << "   Vector: ";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i != v.size() - 1) cout << ", ";
    }
    cout << endl;

    int mx = *max_element(v.begin(), v.end());
    int mn = *min_element(v.begin(), v.end());
    int diff = mx - mn;

    vector<int> v2 = v;
    for_each(v2.begin(), v2.end(), [diff](int &x) {
        if (abs(x) % 2 == 0) {
            x = diff;
        }
    });
    cout << "7. Even abs replaced with diff: " << diff << endl;
    cout << "   Vector: ";
    for (size_t i = 0; i < v2.size(); ++i) {
        cout << v2[i];
        if (i != v2.size() - 1) cout << ", ";
    }
    cout << endl;

    vector<int> v3 = v2;
    set<int> seen;
    vector<int> res;

    for (int val : v3) {
        int m = abs(val);
        if (seen.find(m) == seen.end()) {
            res.push_back(val);
            seen.insert(m);
        }
    }

    cout << "8. Removed duplicate abs values" << endl;
    cout << "   Vector: ";
    for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i];
        if (i != res.size() - 1) cout << ", ";
    }
    cout << endl;

    return 0;
}
