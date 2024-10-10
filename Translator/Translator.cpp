#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_WORDS = 1000;

int main() {
    // Print the author's name and UAID
    cout << "Author: Dylan Pallasigui\n";
    
    // read English-Spanish text file
    ifstream infile("english_spanish.txt");

    //create empty array for English and Spanish words
    string english_words[MAX_WORDS];
    string spanish_words[MAX_WORDS];

    // iterate over lines in file, then add English and Spanish words to arrays
    int i = 0;
    string line;
    while (getline(infile, line)) {
        string english_word = line.substr(0, line.find(' '));
        string spanish_word = line.substr(line.find_last_of(' ') + 1);
        english_words[i] = english_word;
        spanish_words[i] = spanish_word;
        i++;
    }

    // display menu and get user input
    int option = 0;
    while (option != 1 && option != 2) {
        cout << "Please choose one of the following options:" << endl;
        cout << "1. Translate from English to Spanish" << endl;
        cout << "2. Translate from Spanish to English" << endl;
        cin >> option;
        if (option != 1 && option != 2) {
            cout << "Invalid option entered. Please try again." << endl;
        }
    }

    if (option == 1) {
        // translate from English to Spanish
        string input_word;
        cout << "Enter an English word: ";
        cin >> input_word;

        // find index of input word in English words array
        int index = -1;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (english_words[i] == input_word) {
                index = i;
                break;
            }
        }

        // if input word in dictionary, output its Spanish translat
        if (index != -1) {
            cout << input_word << " in Spanish is: " << spanish_words[index] << endl;
        } else {
            cout << "Could not find the word \"" << input_word << "\" in the English dictionary." << endl;
        }
    } else if (option == 2) {
        // translate from Spanish to English
        string input_word;
        cout << "Enter a word in Spanish: ";
        cin >> input_word;

        // find index of input word in Spanish words array
        int index = -1;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (spanish_words[i] == input_word) {
                index = i;
                break;
            }
        }

        // if input word in dictionary, output English translation
        if (index != -1) {
            cout << input_word << " in English is: " << english_words[index] << endl;
        } else {
            cout << "Could not find the word \"" << input_word << "\" in the Spanish dictionary." << endl;
        }
    }

    return 0;
}