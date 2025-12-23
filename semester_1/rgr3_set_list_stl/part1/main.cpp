#include <iostream>
#include <set>
#include <vector>

std::vector<int> sieveOfEratosthenes(int N) {
    std::set<int> numbers;
    std::vector<int> primes;

    if (N < 2) return primes;

    for (int i = 2; i <= N; ++i) {
        numbers.insert(i);
    }

    while (!numbers.empty()) {
        int current = *numbers.begin();
        primes.push_back(current);

        for (int multiple = current; multiple <= N; multiple += current) {
            numbers.erase(multiple);
        }
    }

    return primes;
}

int main() {
    int N;
    std::cout << "Write N: ";
    std::cin >> N;

    std::vector<int> primes = sieveOfEratosthenes(N);

    std::cout << "Prime numbers up to " << N << ":\n";
    for (int prime : primes) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}
