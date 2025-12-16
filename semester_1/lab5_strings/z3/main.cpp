#include <iostream>
#include <string>

bool CheckPunkt(char c){
    return c == '.' || c == ',' || c == '?' || c == '!' || c == ';' || c == '-' || c == ':';
}

int main()
{
    std::string str;

    std::cout << "Write line with words and punctuation marks (. , : ; ! ? -): " << std::endl;
    getline(std::cin, str);

    int n;
    std::cout << "How many biggest words do you need: " << std::endl;
    std::cin >> n;

    int k[100][2];
    int w = 0;
    int index = 0;

    for(int i = 0; i <= str.length(); i++) {
        if(i == str.length() || str[i] == ' ' || CheckPunkt(str[i])) {
            if(i > index) {
                k[w][0] = index;
                k[w][1] = i - index;
                w++;
            }
            index = i + 1;
        }
    }

    for(int i = 1; i < w; i++) {
        int key0 = k[i][0];
        int key1 = k[i][1];
        int j = i - 1;

        while(j >= 0 && k[j][1] < key1) {
            k[j+1][0] = k[j][0];
            k[j+1][1] = k[j][1];
            j--;
        }
        k[j+1][0] = key0;
        k[j+1][1] = key1;
    }

    std::string result;
    int count;
    if(n < w) count = n;
    else count = w;

    for(int i = 0; i < count; i++) {
        if(i > 0) {
            result += " ";
        }
        result += str.substr(k[i][0], k[i][1]);
    }

    std::cout << "Top " << n << " longest words: " << result << std::endl;

    return 0;
}
