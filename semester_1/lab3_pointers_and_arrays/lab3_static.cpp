#include <bits/stdc++.h>
// solve task with usage of
// static arrays
int main() {
    //std::random_device rd;
    std::mt19937 gen(14881488); // Какой у Вас любимый сид????))))

    int n;
    std::cout << "How many elements?" << std::endl;
    std::cin >> n;

    int arr[n];

    int rand;
    std::cout << "Random or not (1 if yes/0 if no)?" << std::endl;
    std::cin >> rand;

    if (rand == 1) {
        int bottom_border, top_border;
        std::cout << "Write bottom and top border: ";
        std::cin >> bottom_border >> top_border;
        std::uniform_int_distribution<int> dist(bottom_border, top_border);

        std::cout << "Elements: ";
        for(int i = 0; i < n; i++) {
            int x = dist(gen);
            std::cout << x << ' ';
            arr[i] = x;
        }

    std::cout << std::endl;

    }

    else {
        std::cout << "Write elements: ";
        for(int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            arr[i] = x;
        }
    }

    int min_abs = arr[0];

    for(int i = 0; i < n; i++) {
            if(abs(arr[i]) < abs(min_abs)) min_abs = arr[i];
        }

    std::cout << "The smallest module number is " << min_abs << std::endl;

    int sum = 0;
    bool is0 = false;

    for(int i = 0; i < n; i++) {
            if(arr[i] == 0) is0 = true;
            if(arr[i] != 0) sum += arr[i];
            else sum = 0;

        }

    if (is0) std::cout << "Sum of elements after last 0 is " << sum << std::endl;
    else std::cout << "There are no 0 element" << std::endl;

    int arr_copy[n];
    for(int i = 0; i < n; i++) {
            arr_copy[i] = arr[i];
    }

    for(int i = 0; i < n; i++) {
            if (i < n / 2 + n % 2) {
                arr[i] = arr_copy[2*i];
            }
            else {
                arr[i] = arr_copy[(i - n / 2 + n % 2) * 2 + 1];
            }
        }
        std::cout << "In first places numbers with even index: ";
        for(int i = 0; i < n; i++) {
            std::cout << arr[i] << ' ';
        }


    return 0;
}
