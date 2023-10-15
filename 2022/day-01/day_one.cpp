#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> parse_input(string file_path) {
    vector<int> values;

    string line;
    ifstream file (file_path);

    if (file.is_open()) {
        int running_count = 0;

        while (getline(file, line) && !file.eof()) {
            if (line == "") {
                values.push_back(running_count);
                running_count = 0;
            } else {
                running_count += stoi(line);
            }
        }
    }

    file.close();

    return values;
}

int main() {
    printf("hello world\n"); 

    vector<int> elf_calorie_counts = parse_input("input.txt");

    int max = 0;

    for (int i = 0; i < elf_calorie_counts.size(); i++) {
        if (elf_calorie_counts[i] > max) {
            max = elf_calorie_counts[i];
        }
    }

    cout << "Highest amount of calories: " << max << "\n";

    return 0;
}
