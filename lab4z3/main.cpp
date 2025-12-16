#include <bits/stdc++.h>



std::mt19937 gen(14881488);
std::uniform_real_distribution<double> dist(-10, 10);


void RandomFilling(double* p, int& n) {
    for(int i = 0; i < n; i++) {
        p[i] = dist(gen);
    }
}

void ManualFilling(double* p, int& n) {
    for(int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
}

int main()
{


    int n;
    std::cout << "Write n: " << std::endl;
    std::cin >> n;

    double x[n], y[n];

    int random = 0;
    std::cout << "Random or not (1/0): " << std::endl;
    std::cin >> random;

    if (random == 1) {
        RandomFilling(x, n);
        RandomFilling(y, n);
    }
    else if(random == 0) {
        std::cout << "Write all x vectors: " << std::endl;
        ManualFilling(x, n);

        std::cout << "Write all y vectors: " << std::endl;
        ManualFilling(y, n);
    }



    double matrix[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matrix[i][j] = 1. / (x[i] + y[j]);
        }
    }

    std::cout << "Matrix:" << std::endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for(int j = 0; j < n; j++) {
        double columnSum = 0;
        for(int i = 0; i < n; i++) {
            columnSum += matrix[i][j];
        }
        std::cout << "Column " << j + 1 << ": " << columnSum << std::endl;
    }

    return 0;


    return 0;
}
