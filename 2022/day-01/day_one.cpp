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
    vector<int> elf_calorie_counts = parse_input("input.txt");
    vector<int> top_three;

    while (top_three.size() < 3) {
        int max = 0;
        int max_index = 0;

        for (int i = 0; i < elf_calorie_counts.size(); i++) {
            int value = elf_calorie_counts[i];

            if (value > max) {
                max = value;
                max_index = i;
            }
        }

        elf_calorie_counts.erase(elf_calorie_counts.begin() + max_index);
        top_three.push_back(max);

        cout << top_three.size() << ": " << max << "\n";
    }

    int final_count = 0;
    for (int i = 0; i < top_three.size(); i++) {
        final_count += top_three[i];
    }

    cout << "Top Three Total: " << final_count << "\n";

    return 0;
}
