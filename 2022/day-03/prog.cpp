#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../utils/input_parser.h"

using namespace std;

int main() {
    vector<string> input = parse_input("day-03/input.txt");

    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << "\n";
    }
}
