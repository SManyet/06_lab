#include "Queue_test.cpp"
#include "Stack_test.cpp"

#include <iostream>
#include <fstream>



using namespace std;




int main() {
//     Queue<int> q(30);
//     int first = 5;
//     q.enqueue(first);
//     int *returned = q.dequeue();
//     std::cout << *returned << std::endl;

    fstream file;
    string path = "linked_lists.txt";
    bool input = false;
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
    // int charCount = 0;
    // while (!file.eof()) {
    //     file.get();
    //     charCount++;
    // }
    // file.close();
    file.open(path, ios::in);

    cout << "here" << endl;
    // Queue<char> q(charCount);
    int maxWordLength = 100;
    Stack<char> stack(maxWordLength);
    while (!file.eof()) {
        string punct = " .,;:!?";
        char temp = file.get();
        // char *letter = new char;
        char *letter = &temp;
        if (punct.find(letter) == string::npos) {
            cout << "2" << endl;
            cout << letter << endl;
            stack.push(letter);
        } else {
            for (int i = 0; i < stack.length(); i++) {
                cout << "1" << endl;
                cout << stack.pop() << endl;
                // q.enqueue(*stack.pop());
            }
            Stack<char> stack(maxWordLength);
            // q.enqueue(letter);
        }
    }
    // for(int i = 0; i < q.getNumItems(); i++) {
        // cout << q.dequeue();
    // }

    
    

    return 0;
}
