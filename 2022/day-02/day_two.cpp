#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int WIN = 6;
const int DRAW = 3;
const int LOSE = 0;

const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;

char choose_hand(char opponent_hand, char desired_outcome) {
    switch (desired_outcome) {
        case 'X':
            if (opponent_hand == 'A') return 'C';
            if (opponent_hand == 'B') return 'A';
            if (opponent_hand == 'C') return 'B';
            break;
        case 'Y':
            return opponent_hand;
        case 'Z':
            if (opponent_hand == 'A') return 'B';
            if (opponent_hand == 'B') return 'C';
            if (opponent_hand == 'C') return 'A';
    }

    cout << "Should never be here" << "\n";
    return 'A';
}

vector<string> parse_input(string file_path) {
    vector<string> rounds;

    string line;
    ifstream file (file_path);

    if (file.is_open()) {
        while (getline(file, line)) {
            char opponent_hand = line.at(0);
            char desired_outcome = line.at(2);

            char outcome = choose_hand(opponent_hand, desired_outcome);

            string updated_line = string(1, opponent_hand) + " " + string(1, outcome);
            rounds.push_back(updated_line);
        }

        file.close();
    }

    return rounds;
}

int get_action_score(char action) {
    switch (action) {
        case 'A':
        case 'X':
            return ROCK;
        case 'B':
        case 'Y':
            return PAPER;
        case 'C':
        case 'Z':
            return SCISSORS;
        default:
            return 0;
    }
}

// The a input is the opponent. The b input is you
int calculate_round_output(char a, char b) {
    int opponent = get_action_score(a);
    int you = get_action_score(b);

    switch (opponent) {
        case ROCK:
            if (you == PAPER) return WIN + you;
            if (you == SCISSORS) return LOSE + you;
            if (you == ROCK) return DRAW + you;
        case PAPER:
            if (you == SCISSORS) return WIN + you;
            if (you == ROCK) return LOSE + you;
            if (you == PAPER) return DRAW + you;
        case SCISSORS:
            if (you == ROCK) return WIN + you;
            if (you == PAPER) return LOSE + you;
            if (you == SCISSORS) return DRAW + you;
    }

    return 0;
}

int main() {
    vector<string> rounds = parse_input("input.txt");
    int total_score = 0;

    for (int i = 0; i < rounds.size(); i++) {
        char opponent_action = rounds[i].at(0);
        char your_action = rounds[i].at(2);

        int round_score = calculate_round_output(opponent_action, your_action);
        total_score += round_score;
    }

    cout << "Your total score: " << total_score << "\n";

    return 0;
}
