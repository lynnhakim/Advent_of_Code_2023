#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    vector<string> arr;
    vector<vector<string>> winningNums;
    vector<vector<string>> myNums;
    string line;
    ifstream myfile("data.txt");

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            arr.push_back(line);
        }
        myfile.close();
    }

    for (int i = 0; i < arr.size(); i++) {
        size_t pos = arr[i].find("|");
        string firstPart = arr[i].substr(8, pos -9);
        string secondPart = arr[i].substr(pos + 2);

        stringstream ss1(firstPart);
        stringstream ss2(secondPart);
        string num;
        vector<string> winning;
        vector<string> my;

        while (ss1 >> num) {
            winning.push_back(num);
        }
        winningNums.push_back(winning);

        while (ss2 >> num) {
            my.push_back(num);
        }
        myNums.push_back(my);
    }
    /*
    for (int i = 0; i < winningNums.size(); i++) {
        cout << "Winning Numbers for Card " << i + 1 << ": ";
        for (const auto& num : winningNums[i]) {
            cout << num << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < myNums.size(); i++) {
        cout << "Your Numbers for Card " << i + 1 << ": ";
        for (const auto& num : myNums[i]) {
            cout << num << " ";
        }
        cout << endl;
    }
    */
    int points;
    vector<int> total(winningNums.size(),1) ;
    for (int i = 0; i < myNums.size(); i++) {
        points = 0;
        for (int j = 0; j < myNums[i].size(); j++) {
            if (find(winningNums[i].begin(), winningNums[i].end(), myNums[i][j]) != winningNums[i].end())
                points++;
        }
        //cout << points<<endl;
        for (int l = 0; l < total[i]; l++){
    
            for (int k = i + 1; k <= i + points; k++) {

                total[k]++;
            }

        }
        
    }
    int sum=0;
    for (int i = 0; i < total.size(); i++) {
        sum+=total[i];
    }
    cout << sum;
}

