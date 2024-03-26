#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

// Zadanie 1
string removeDigits(const string &text) {
    string result = text;
    for (int i = 0; i < result.length(); ++i) {
        if (isdigit(result[i])) {
            result.erase(i, 1);
            i--; // Zmniejszenie i o jeden ze względu na zmniejszenie długości stringa
        }
    }
    return result;
}

// Zadanie 2
string swapCase(const string &text) {
    string result = text;
    for (int i = 0; i < result.length(); ++i) {
        if (isupper(result[i])) {
            result[i] = tolower(result[i]);
        } else if (islower(result[i])) {
            result[i] = toupper(result[i]);
        }
    }
    return result;
}

// Zadanie 3
string capitalizeWords(const string &text) {
    string result = text;
    bool makeUpper = true;
    for (int i = 0; i < result.length(); ++i) {
        if (makeUpper && isalpha(result[i])) {
            result[i] = toupper(result[i]);
            makeUpper = false;
        } else if (isspace(result[i])) {
            makeUpper = true;
        }
    }
    return result;
}

// Zadanie 4
string replaceWord(const string &text, const string &target, const string &replacement) {
    string result = text;
    size_t pos = result.find(target);
    while (pos != string::npos) {
        result.replace(pos, target.length(), replacement);
        pos = result.find(target, pos + replacement.length());
    }
    return result;
}

// Zadanie 5
bool isPalindrome(const string &word) {
    // a. Sprawdzanie w pętli
    int length = word.length();
    for (int i = 0; i < length / 2; ++i) {
        if (word[i] != word[length - 1 - i]) {
            return false;
        }
    }
    return true;

    // b. Używając std::reverse
    // string reversedWord = word;
    // reverse(reversedWord.begin(), reversedWord.end());
    // return word == reversedWord;
}

int main() {
    // Zadanie 1
    string input1 = "aaaa77a777 b76 c7 dddd6";
    cout << "Zadanie 1: " << removeDigits(input1) << endl;

    // Zadanie 2
    string input2 = "Lorem Ipsum Dolor Sit Amet";
    cout << "Zadanie 2: " << swapCase(input2) << endl;

    // Zadanie 3
    string input3 = "Lorem ipsum dolor sit amet";
    cout << "Zadanie 3: " << capitalizeWords(input3) << endl;

    // Zadanie 4
    string input4 = "Filip to moje imie. Drugi Filip. A tu Filip trzeci.";
    string target = "Filip";
    string replacement = "Sebastian";
    cout << "Zadanie 4: " << replaceWord(input4, target, replacement) << endl;

    // Zadanie 5
    string input5 = "kajak";
    cout << "Zadanie 5a: " << input5 << " - " << (isPalindrome(input5) ? "palindrom" : "nie palindrom") << endl;

    string input6 = "oko";
    cout << "Zadanie 5b: " << input6 << " - " << (isPalindrome(input6) ? "palindrom" : "nie palindrom") << endl;

    return 0;
}
