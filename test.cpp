#include "Queue_test.cpp"
#include "Stack_test.cpp"

#include <iostream>
#include <fstream>

using namespace std;

int main() {

    fstream file;
    string path = "linked_lists.txt";
    bool input = true;
    while (input) {
        cout << "input file path: " << endl;
        getline(cin, path);
        file.open(path, ios::in);
        if (file.fail()) {
            cout << "file not found" << endl;
            file.clear();
            file.ignore();
            continue;
        } else {
            cout << "processing " << path << endl;
            input = false;
        }
    }
    int charCount = 0;
    while (!file.eof()) {
        file.get();
        charCount++;
    }
    file.close();
    file.open(path, ios::in);
    Queue<char> q(charCount);
    int maxWordLength = 100;
    Stack<char> stack(maxWordLength);

    while (!file.eof()) {
        string punct = " .,;:!?";

        char fileChar = file.get();
        char *letter = new char(fileChar);



        if (punct.find(*letter) == string::npos) {
            stack.push(letter);
        } else {
            for (int i = 0; i < stack.length(); i++) {
                q.enqueue(stack.pop());
            }
            Stack<char> stack(maxWordLength);
            q.enqueue(letter);
        }
    }
    for(int i = 0; i < q.getNumItems(); i++) {
        cout << q.dequeue();
    }
    return 0;
}

//things changed:
// - new operator
// - length()
// - indexOfHead
