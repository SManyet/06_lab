#include <iostream>
#include <fstream>

#include "Stack.h"
#include "Queue.h"

using namespace std;

// func for processing each char in book contents
bool processChar(char letter, Book &book, bool prevCRLF) {
    int asciiIndex = (int) letter - 65;
    if (letter == ' ') {    // checks for whitespace
        book.wordCount++;
        return false;
    } else if (letter == '\n') {    // checks for CRLF
        book.lineCount++;
        if (!prevCRLF) {
            book.wordCount++;
        }
        return true;
    } else if (0 <= asciiIndex && asciiIndex <= 25) { // checks for letters
       book.letterFrq[asciiIndex]++;
       return false;
    } else {
        return false;
    }
}

int main() {
    bool running = true;
    while(running) {
        fstream bookFile; //book txt file stream
        string path;
        cout << "Input file path: " << endl;
        getline(cin, path);
        
        bookFile.open(path, ios::in); // open the txt file 
        if (bookFile.fail()) { // checks if file exists
            cout << "file not found" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        cout << "processing " << path << endl;

        Queue q = Queue()
        getline(bookFile, book.title); // first line is always title
        getline(bookFile, book.author); // second line is always author full name

        // reads down linewise until content is flagged
        string contentFlag;
        getline(bookFile, contentFlag);
        while(contentFlag.find("Contents:") == string::npos) {
            getline(bookFile, contentFlag);
        }

        // loop to process each char in contents
        bool prevCRLF = false;
        while(!bookFile.eof()) {
            char letter;
            letter = toupper(bookFile.get());
            prevCRLF = processChar(letter, book, prevCRLF);
        }
        
        // convert letter frequency to percent
        int total = 0;
        for (int i = 0; i < 26; i++) {
            total += book.letterFrq[i];
        }
        for (int i = 0; i < 26; i++) {
            book.letterFrq[i] *= 100;
            book.letterFrq[i] /= total;
        }
        
        // catalog output
        ofstream card("CardCatalog.txt", ios::app | ios::out); // append if exists, else make new file

        card << "Title: " << book.title << endl;
        card << "Full Author: " << book.author << endl;
        card << "Word Count: " << book.wordCount << endl;
        card << "Line Count: " << book.lineCount << endl;

        cout << "Would you ike to see the letter frequency, 1 for yes 2 for no? " << endl;
        int input; //check if user wants letter frequency in catalog
        cin >> input;
        if (input == 1) {
            for (int i = 0; i < 26; i++) {
                card << (char) (i+65) << ": "<< book.letterFrq[i] << "%"  << endl;
            }
        }
        
        card << endl;

        cout << "repeat (1), or quit (2)" << endl; // check if run again
        cin >> input;
        if (input == 1) {
            continue;
        } else {
            break;
        }
    }
}
