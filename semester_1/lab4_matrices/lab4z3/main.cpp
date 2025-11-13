#include <iostream>
#include <random>
#include <cmath>
#include <iomanip>

const int MAX_SIZE = 100;

void input_check(){
    if(!std::cin) {
        throw "Input Error";
    }
}

std::uniform_real_distribution<double> RandomBorders(){
    double bottom_border, top_border;
    std::cout << "Write bottom and top border: ";
    std::cin >> bottom_border;
    input_check();
    std::cin >> top_border;
    input_check();

    return std::uniform_real_distribution<double>(bottom_border, top_border);
}

void InsertRandArray(double (&arr)[MAX_SIZE], const int SIZE, std::mt19937& gen, std::uniform_real_distribution<double>& dist) {
    for(int i = 0; i < SIZE; i++ ) {
        arr[i] =  dist(gen);
    }
}

void InsertUserArray(double (&arr)[MAX_SIZE], const int SIZE){
    for(int i = 0; i < SIZE; i++ ) {
        std::cin >> arr[i];
        input_check();
    }
}

void PrintArray(double (&arr)[MAX_SIZE], const int SIZE) {
    for(int i = 0; i < SIZE; i++ ) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl << std::endl;
}

void InsertKashiMatrix(double (&matrix)[MAX_SIZE][MAX_SIZE],const double (&x_vector)[MAX_SIZE],const double (&y_vector)[MAX_SIZE], const int SIZE)
{
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(x_vector[i] + y_vector[j] == 0) {
                std::cout << "Kashi Matrix can't be created with this vectors." << std::endl;
                throw "Arithmetic Error";
            }
            matrix[i][j] = 1 / (x_vector[i] + y_vector[j]);
        }
    }
}

void PrintMatrix(double (&matrix)[MAX_SIZE][MAX_SIZE], const int SIZE) {
    std::cout << std::fixed << std::setprecision(5);
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            std::cout << std::setw(8) << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void PrintSumColumns(double (&matrix)[MAX_SIZE][MAX_SIZE], const int SIZE) {
    std::cout << std::endl;
    for(int j = 0; j < SIZE; j++) {
        double SumColumn = 0;
        for(int i = 0; i < SIZE; i++) {
            SumColumn += matrix[i][j];
        }
        std::cout << "Sum elements of the " << j + 1 << " column: " << SumColumn << std::endl;
    }
}

int main()
{


    try
    {

    std::mt19937 gen(14881488);

    int n;
    std::cout << "How many elements in each vector?" << std::endl;
    std::cin >> n;
    input_check();

    double x[MAX_SIZE], y[MAX_SIZE];

    int rand;
    std::cout << "Random or not (1 if yes/no 1 if no)?" << std::endl;
    std::cin >> rand;
    input_check();

    if (rand == 1) {
        auto dist = RandomBorders();

        InsertRandArray(x, n, gen, dist);
        InsertRandArray(y, n, gen, dist);

        std::cout << "Elements X vector: ";
        PrintArray(x, n);
        std::cout << "Elements Y vector: ";
        PrintArray(y, n);
    }
    else {
        std::cout << "Write X vector elements: ";
        InsertUserArray(x, n);

        std::cout << "Write Y vector elements: ";
        InsertUserArray(y, n);
    }

    double KashiMatrix[MAX_SIZE][MAX_SIZE];

    InsertKashiMatrix(KashiMatrix, x, y, n);
    PrintMatrix(KashiMatrix, n);

    PrintSumColumns(KashiMatrix, n);


    }
    catch (const char* msg)
    {

        std::cout << msg;
    }



    return 0;
}
