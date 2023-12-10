#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    ifstream file("day6.txt"); // Open the file
    vector<int> time;
    vector<int> distance;
    

    if (file.is_open()) {
        int val;
        while (file >> val) {
            if (time.size() ==4) {
                distance.push_back(val);
            }
            else {
                time.push_back(val);
            }
        }
        file.close(); // Close the file
    }
    else {
        std::cout << "Unable to open file";
        return 1;
    }
    vector<vector<int>> alldist;
    int dist;
    for (int i = 0; i < time.size(); i++) {
        vector< int> mydist;

        for (int j = 1; j < time[i]; j++) {

            dist = (time[i] - j) * j;
            if (dist > distance[i]) {
                mydist.push_back(dist);
                
            }
        }
        alldist.push_back(mydist);
    }


    int total = 1;

    for (int i = 0; i < alldist.size(); i++) {
        total *= alldist[i].size();
    }
    cout << total<<endl;
    for (int i = 0; i < alldist.size(); i++) {
        for (int j = 0; j < alldist[i].size(); j++) {
            cout << alldist[i][j] << ' ';
        }
        cout << endl;
    }
    // Print the time and distance vectors
    std::cout << "Time: ";
    for (int t : time) {
        std::cout << t << " ";
    }
    std::cout << std::endl;

    std::cout << "Distance: ";
    for (int d : distance) {
        std::cout << d << " ";
    }
    std::cout << std::endl;

    return 0;
}
