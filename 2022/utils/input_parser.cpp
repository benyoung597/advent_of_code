#include "input_parser.h"

vector<string> parse_input(string file_path) {
    vector<string> lines;

    string line;
    ifstream file (file_path);

    if (file.is_open()) {
        while (getline(file, line)) {
            lines.push_back(line);
        }
    }

    return lines;
}
