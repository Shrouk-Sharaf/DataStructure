#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    string url;
    Node* next;

    Node(const string& u) : url(u), next(nullptr) {}
};

class CustomStack {
private:
    Node* top;
    int size;

public:
    CustomStack() : top(nullptr), size(0) {}

    ~CustomStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const string& url) {
        Node* newNode = new Node(url);
        newNode->next = top;
        top = newNode;
        size++;
    }

    string pop() {
        if (isEmpty()) {
            return "";
        }
        Node* temp = top;
        string url = temp->url;
        top = top->next;
        delete temp;
        size--;
        return url;
    }

    string peek() const {
        if (isEmpty()) {
            return "";
        }
        return top->url;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    int getSize() const {
        return size;
    }

    // For printing the stack contents (in reverse order)
    void print() const {
        if (isEmpty()) {
            cout << "Empty";
            return;
        }

        // First, we'll reverse the stack to print it in the correct order
        Node* current = top;
        Node* prev = nullptr;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        // Now print the reversed stack
        current = prev;
        while (current != nullptr) {
            cout << current->url << " ";
            current = current->next;
        }

        // Restore the original stack order
        current = prev;
        prev = nullptr;
        next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
    }
};

class BrowserHistory {
private:
    CustomStack backStack;
    CustomStack forwardStack;
    string currentUrl;

public:
    void visit(const string& url) {
        // Clear forward stack when visiting a new URL
        while (!forwardStack.isEmpty()) {
            forwardStack.pop();
        }

        if (!currentUrl.empty()) {
            backStack.push(currentUrl);
        }
        currentUrl = url;
    }

    string goBack() {
        if (backStack.isEmpty()) {
            return currentUrl; // Can't go back
        }

        forwardStack.push(currentUrl);
        currentUrl = backStack.pop();
        return currentUrl;
    }

    string goForward() {
        if (forwardStack.isEmpty()) {
            return currentUrl; // Can't go forward
        }

        backStack.push(currentUrl);
        currentUrl = forwardStack.pop();
        return currentUrl;
    }

    void printState() {
        cout << "Current URL: " << (currentUrl.empty() ? "None" : currentUrl) << endl;

        cout << "Back Stack: ";
        backStack.print();
        cout << endl;

        cout << "Forward Stack: ";
        forwardStack.print();
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
        else if (command == "2") {
            cout << "Back --> ";
            cout << bh.goBack() << endl << endl;
        }
        else if (command == "3") {
            cout << "Forward --> ";
            cout << bh.goForward() << endl << endl;
        }
        bh.printState();
    }
    inputFile.close();
}