#include <bits/stdc++.h>
// solve task with usage of
// dymanic arrays
int main() {

    std::mt19937 gen(14881488);


    int n;
    std::cout << "How many elements?" << std::endl;
    std::cin >> n;

    double* arr = new double[n];


    int rand;
    std::cout << "Random or not (1 if yes/0 if no)?" << std::endl;
    std::cin >> rand;

    if (rand == 1) {
        int bottom_border, top_border;
        std::cout << "Write bottom and top border: ";
        std::cin >> bottom_border >> top_border;
        std::uniform_real_distribution<double> dist(bottom_border, top_border);

        std::cout << "Elements: ";
        for(int i = 0; i < n; i++) {
            double x = dist(gen);
            std::cout << x << ' ';
            arr[i] = x;
        }

    std::cout << std::endl;

    }

    else {
        std::cout << "Write elements: ";
        for(int i = 0; i < n; i++) {
            double x;
            std::cin >> x;
            arr[i] = x;
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int same = 0;
        for(int j = 0; j < i; j++) {
                //std::cout << arr[i] << ' ' << arr[j] << std::endl;
            if(arr[i] == arr[j]) {
                same = 1;
                break;
            }
        }

        if (same == 0) cnt++;

    }

    std::cout << "Number of different elements is " << cnt << std::endl;

    for(int i = 0; i < n; i++)  {
        int j;
        double sum = 0;
        if (arr[i] > 0) {
            flag = false
            for(j = i + 1; arr[j] <= 0 && j < n; j++) {
                sum += arr[j];
                if(j == n - 1) flag = true;
            }
            if(flag) break;
            if(j != i + 1) std::cout << "Sum between first and second positive num is " << sum;
            else std::cout << "No num between first and second positive num";
            break;
        }
        cout << "There are no positive elements";
    }

     delete[] arr;



    return 0;
}
