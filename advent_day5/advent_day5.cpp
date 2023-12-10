#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

long long func(vector<vector<long long>> vec, long long seed) {
    long long destination;
    long long sourceStart;
    long long range;
    long long sourceEnd;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            destination = vec[i][0];
            sourceStart = vec[i][1];
            range = vec[i][2];
            sourceEnd = sourceStart + range - 1;

            if (seed >= sourceStart && seed <= sourceEnd) {
                seed = destination + (seed - sourceStart);
                return seed;
            }
        }
    }

    return seed;
}

int main() {

    ifstream inputFile("day5_test.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    vector<vector<long long>> seedToSoil;
    vector <vector<long long>> soilToFert;
    vector <vector<long long>> fertToWater;
    vector <vector<long long>> waterToLight;
    vector <vector<long long>> lightToTemp;
    vector <vector<long long>> tempToHumid;
    vector <vector<long long>> humidToLoc;

    string line;

    int i = 0;


    while (getline(inputFile, line)) {

        istringstream iss(line);
        long long value;
        vector<long long> valuesInLine;

        while (iss >> value) {
            valuesInLine.push_back(value);
        }

        switch (i) {
        case 1:
            seedToSoil.push_back(valuesInLine);
            break;
        case 2:
            soilToFert.push_back(valuesInLine);
            break;
        case 3:
            fertToWater.push_back(valuesInLine);
            break;
        case 4:
            waterToLight.push_back(valuesInLine);
            break;
        case 5:
            lightToTemp.push_back(valuesInLine);
            break;
        case 6:
            tempToHumid.push_back(valuesInLine);
            break;
        case 7:
            humidToLoc.push_back(valuesInLine);
            break;
        }

        if (line.empty()) {
            i++;
            getline(inputFile, line);
        }

        
      
    }
     
    
    vector <long long> seeds = { 79, 14, 55 ,13 };
  // vector <long long> seeds = { 3082872446, 316680412 ,2769223903, 74043323, 4131958457 ,99539464, 109726392, 353536902, 619902767, 648714498, 3762874676, 148318192, 1545670780, 343889780 ,4259893555, 6139816 ,3980757676 ,20172062 ,2199623551 ,196958359 };
    vector<long long > maps;
    long long start;
    long long count;
    for (long long i = 0; i < seeds.size(); i+=2) {
        start = seeds[i];
        count = seeds[i + 1];
        for (long  s = start; s < start + count; s++) {
            
            long long seed;
         
            seed = s;
            std::cout << seed << ' ';
            seed = func(seedToSoil, seed);
            std::cout << seed << " ";

            seed = func(soilToFert, seed);
            std::cout << seed << " ";

            seed = func(fertToWater, seed);
            std::cout << seed << " ";

            seed = func(waterToLight, seed);
            std::cout << seed << " ";

            seed = func(lightToTemp, seed);
            std::cout << seed << " ";

            seed = func(tempToHumid, seed);
            std::cout << seed << " ";

            seed = func(humidToLoc, seed);

            std::cout << seed << " ";
            std::cout << endl;
            if (find(maps.begin(), maps.end(), seed) == maps.end())
                maps.push_back(seed);       
        }
    }
       
   
    std::cout << "\nMin Element = "
        << *min_element(maps.begin(), maps.end()); 
   

    inputFile.close();

}
