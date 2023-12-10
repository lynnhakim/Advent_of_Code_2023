#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <string>
#include <unordered_map>

using namespace std;
unordered_map<string, int> wordMap = {
        {"one", 1}, {"two", 2}, {"three", 3}, {"eight", 8},
        {"four", 4}, {"five", 5}, {"six", 6},
        {"seven", 7}, {"nine", 9}
};

int wordToInt(const string& input) {
    unordered_map<int, size_t> foundPositions; // Map to store the positions of found numbers

    for (const auto& entry : wordMap) {
        size_t pos = input.find(entry.first);
        if (pos != string::npos) {
            foundPositions[entry.second] = pos; // Store the position of the found number
        }
    }

    if (!foundPositions.empty()) {
        size_t minPos = numeric_limits<size_t>::max();
        int selectedNumber = -1;

        for (const auto& entry : foundPositions) {
            if (entry.second < minPos) {
                minPos = entry.second;
                selectedNumber = entry.first;
            }
        }

        return selectedNumber;
    }

    return -1; // Return -1 if no number is found
}

int main() {
    vector<vector<int>> allNums;
    ifstream file("day1.txt");
    string line;

    while (getline(file, line)) {
        vector<int> numsInLine;
       

        if (isdigit(line.front())) {
            numsInLine.push_back(line.front() - '0');
        }
        //string subline = line;
        while (line.size() > 3) {
            int number = wordToInt(line);
            if (number != -1)
                numsInLine.push_back(number);


            line = line.substr(1);
        }
        
        for (char ch: line) {
            if (isdigit(ch)) {
                numsInLine.push_back(ch - '0');
            }

        }
        if (isdigit(line.back())) {
            numsInLine.push_back(line.back() - '0');
        }

        if (numsInLine.empty()) {
            for (char ch : line) {
                if (isdigit(ch)) {
                    numsInLine.push_back(ch - '0');

                }
            }
        }
        allNums.push_back(numsInLine);

    }

    int total = 0;
    for (int i = 0; i < allNums.size(); i++) {
        for (int j = 0; j < allNums[i].size(); j++) {
            cout << allNums[i][j] << ' ';
        }
        cout << endl;
    }



    for (int i = 0; i < allNums.size(); i++) {
        int perLine = 0;
        for (int j = 0; j < allNums[i].size(); j++) {
            int n = allNums[i].size() - 1;
            perLine = allNums[i][0] * 10 + allNums[i][n];
        }
        total += perLine;
    }
    cout << total;

    return 0;
}