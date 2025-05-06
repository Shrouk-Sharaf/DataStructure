#include <iostream>
#include <stack>
#include <fstream>
using namespace std;

class BrowserHistory {
private:
    stack<string> backStack;
    stack<string> forwardStack;
    string currentUrl;

public:
    void visit(const string& url) {
        while (!forwardStack.empty()) forwardStack.pop();
        if (!currentUrl.empty()) backStack.push(currentUrl);
        currentUrl = url;
    }

    string goBack() {
        forwardStack.push(currentUrl);
        currentUrl = backStack.top();
        backStack.pop();
        return currentUrl;
    }

    string goForward() {
        backStack.push(currentUrl);
        currentUrl = forwardStack.top();
        forwardStack.pop();
        return currentUrl;
    }

    void printState() {
        cout << "Current URL: " << (currentUrl.empty() ? "None" : currentUrl) << endl;

        cout << "Back Stack: ";
        stack<string> temp = backStack, rev;
        while (!temp.empty()) {
            rev.push(temp.top());
            temp.pop();
        }
        while (!rev.empty()) {
            cout << rev.top() << " ";
            rev.pop();
        }
        cout << endl;

        cout << "Forward Stack: ";
        temp = forwardStack;
        while (!temp.empty()) {
            rev.push(temp.top());
            temp.pop();
        }
        while (!rev.empty()) {
            cout << rev.top() << " ";
            rev.pop();
        }
        cout << endl;

        cout << "-----------------------------" << endl;
    }
};

int main() {
    BrowserHistory bh;
    ifstream inputFile("./Browser History System/test.txt");
    string command;

    while (inputFile >> command) {
        if (command == "1") {
            string url;
            inputFile >> ws;
            getline(inputFile, url);
            cout << "Visit --> " << url << endl << endl;
            bh.visit(url);
        }
        else if (command == "2"){
            cout << "Back --> ";
            cout << bh.goBack() << endl << endl;
        }
        else if (command == "3"){
            cout << "Forward --> ";
            cout << bh.goForward() << endl << endl;
        }
        bh.printState();
    }
    inputFile.close();
}