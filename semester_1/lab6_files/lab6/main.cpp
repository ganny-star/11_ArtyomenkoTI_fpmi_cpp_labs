#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

int countWords(const std::string& line) {
    int count = 0;
    bool word = false;

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ' ') {
            word = false;
        } else if (!word) {
            count++;
            word = true;
        }
    }

    return count;
}

void analyzeFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw ("Error: cannot open file " + filename);
    }

    std::vector<std::pair<int, std::string>> linesWithWordCount;
    std::string line;
    int maxWordCount = 0;

    while (std::getline(file, line)) {
        int wordCount = countWords(line);
        linesWithWordCount.push_back({wordCount, line});

        if (wordCount > maxWordCount) {
            maxWordCount = wordCount;
        }
    }

    file.close();

    if (linesWithWordCount.empty()) {
        throw "File is empty!";
    }

    std::vector<std::string> resultLines;

    for (const auto& pair : linesWithWordCount) {
        if (pair.first == maxWordCount) {
            resultLines.push_back(pair.second);
        }
    }

    std::cout << "Maximum words: " << maxWordCount << std::endl;
    std::cout << "Lines with maximum words: " << resultLines.size() << std::endl;
    std::cout << std::endl;

    std::cout << "First 10 lines with max words" << std::endl;
    int outputCount = std::min(10, (int)resultLines.size());

    for (int i = 0; i < outputCount; i++) {
        std::cout << resultLines[i] << std::endl;
    }

    if (resultLines.size() > 10) {
        std::cout << "... and " << (resultLines.size() - 10) << " more lines" << std::endl;
    }
}

int main() {
    try {
    analyzeFile("input.txt");
    }
    catch (const char* msg) {
        std::cout << msg;
    }
    return 0;
}
