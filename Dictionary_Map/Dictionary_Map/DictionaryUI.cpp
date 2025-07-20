#include "DictionaryUI.h"
#include <iostream>
using namespace std;

DictionaryUI::DictionaryUI() {
    loadFromFile();
}

void DictionaryUI::run() {
    int choice;
    do {
        menu();
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: addWord(); break;
        case 2: removeWord(); break;
        case 3: editWord(); break;
        case 4: findWord(); break;
        case 5: showAll(); break;
        case 6: saveToFile(); break;
        case 7: loadFromFile(); break;
        case 0: cout << "Exiting program\n"; break;
        default: cout << "Invalid choice, try again\n";
        }
    } while (choice != 0);
}

void DictionaryUI::menu() {
    cout << "\n--- Dictionary Menu ---\n";
    cout << "1. Add word\n";
    cout << "2. Remove word\n";
    cout << "3. Edit word\n";
    cout << "4. Find word\n";
    cout << "5. Show all words\n";
    cout << "6. Save to file\n";
    cout << "7. Load from file\n";
    cout << "0. Exit\n";
}

void DictionaryUI::addWord() {
    string word, translation;
    cout << "Enter word: ";
    getline(cin, word);
    cout << "Enter translation: ";
    getline(cin, translation);
    dict.addWord(word, translation);
    cout << "Added.\n";
}

void DictionaryUI::removeWord() {
    string word;
    cout << "Enter word to remove: ";
    getline(cin, word);
    if (dict.removeWord(word))
        cout << "Removed\n";
    else
        cout << "Word not found\n";
}

void DictionaryUI::editWord() {
    string word;
    cout << "Enter word to edit: ";
    getline(cin, word);
    if (dict.findWord(word)) {
        string translation;
        cout << "Enter new translation: ";
        getline(cin, translation);
        dict.editWord(word, translation);
        cout << "Updated\n";
    }
    else {
        cout << "Word not found\n";
    }
}

void DictionaryUI::findWord() {
    string word;
    cout << "Enter word to find: ";
    getline(cin, word);
    dict.printWord(word);
}

void DictionaryUI::showAll() {
    dict.printAll();
}

void DictionaryUI::saveToFile() {
    if (dict.saveToFile(filename))
        cout << "Saved to file\n";
    else
        cout << "Error saving file\n";
}

void DictionaryUI::loadFromFile() {
    if (dict.loadFromFile(filename))
        cout << "Loaded from file\n";
    else
        cout << "Error loading file or file does not exist\n";
}
