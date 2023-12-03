#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <regex>
#include <vector>
#include <limits>

using namespace std;

int searchInput(regex, regex);

#define FILENAME "input.txt"                     
#define FIRST_DIG "\\d"                         
#define LAST_DIG "\\d(?!.*\\d)"                   
#define FIRST_NUM "(?:zero|one|two|three|four|five|six|seven|eight|nine|\\d)"
#define LAST_NUM "(?:(?!.+(?:zero|one|two|three|four|five|six|seven|eight|nine|\\d)))(?:zero|one|two|three|four|five|six|seven|eight|nine|\\d)"

int main () {
    regex firstdig(FIRST_DIG);
    regex lastdig(LAST_DIG);
    regex firstnum(FIRST_NUM);
    regex lastnum(LAST_NUM);
    int sum;
    int choice;

    cout << "Choose Search Mode:\n\n"
         << "1. Excusively Digits\n\n"
         << "2. Include Written Numbers\n\n";
    cin >> choice;

    while (cin.fail() || (choice != 1 && choice != 2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Input. Enter 1 or 2: ";
        cin >> choice;
    }

    if (choice == 1) {
        cout << "Sum: " << searchInput(firstdig, lastdig) << endl;
    }
    else if (choice == 2) {
        cout << "Sum: " << searchInput(firstnum, lastnum) << endl;
    }

    return 0;
}

int searchInput(regex first_R, regex last_R) {
    string line;
    string first;
    string last;
    vector<string> lines;
    ifstream infile;
    int sum = 0;
    int* arr;
    smatch temp;

    unordered_map<string, string> wordnum_map;

    wordnum_map["zero"]  = "0";
    wordnum_map["one"]   = "1";
    wordnum_map["two"]   = "2";
    wordnum_map["three"] = "3";
    wordnum_map["four"]  = "4";
    wordnum_map["five"]  = "5";
    wordnum_map["six"]   = "6";
    wordnum_map["seven"] = "7";
    wordnum_map["eight"] = "8";
    wordnum_map["nine"]  = "9";

    infile.open(FILENAME);

    if (!infile.is_open()) {
        cerr << "Error Opening File: " << FILENAME << "\n";
        exit(EXIT_FAILURE);
    }

    while (getline(infile, line)) {
        lines.push_back(line);
    }

    infile.close();

    arr = new int[lines.size()];

    for (int i = 0; i < lines.size(); i++) {
        if (regex_search(lines.at(i), temp, first_R)) {
            first = temp.str();
        }

        if (regex_search(lines.at(i), temp, last_R)) {
            last = temp.str();
        }

        if (first.length() != 1) {
            first = wordnum_map[first];
        }

        if (last.length() != 1) {
            last = wordnum_map[last];
        }

        arr[i] = stoi(first + last);

        cout << "First: " << first << endl;
        cout << "Last: " << last << endl;

        cout << arr[i] << endl;

        first.clear();
        last.clear();
    }

    for (int i = 0; i < lines.size(); i++) {
        sum += arr[i];
    }

    return sum;
}