#include "SortingSystem.h"
#include <type_traits>

template <typename T>
SortingSystem<T>::SortingSystem(int n) {
    size = n;
    data = new T[size];

    cout << "Enter " << n << " elements of the array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ":\n";
        cin >> data[i];
    }
}

template <typename T>
SortingSystem<T>::~SortingSystem() {
    cout << "Dataset is deleted successfully" << endl;
    delete[] data;
}

template <typename T>
void SortingSystem<T>::selectionSort() {
    cout << "Initial Data: ";
    displayData();
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(data[i], data[minIndex]);
        }

        cout << "After iteration " << i + 1 << ": ";
        displayData();
    }
}

template <typename T>
void SortingSystem<T>::bubbleSort() {
    cout << "Initial Data: ";
    displayData();
    for (int i = 0; i < size - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                swapped = true;
            }
        }

        cout << "After pass " << i + 1 << ": ";
        displayData();

        if (!swapped) break;
    }
}

template<>
void SortingSystem<int>::radixSort() {
    cout << "Initial Data: ";
    displayData();
    int maxVal = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > maxVal) {
            maxVal = data[i];
        }
    }

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        int* output = new int[size];
        int count[10] = {0};

        for (int i = 0; i < size; i++)
            count[(data[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = size - 1; i >= 0; i--) {
            output[count[(data[i] / exp) % 10] - 1] = data[i];
            count[(data[i] / exp) % 10]--;
        }

        for (int i = 0; i < size; i++)
            data[i] = output[i];

        cout << "After sorting by place value " << exp << ": ";
        displayData();

        delete[] output;
    }
}

template <typename T>
void SortingSystem<T>::displayData() {
    cout << "[";
    for (int i = 0; i < size; ++i) {
        cout << data[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]" << endl;
}

template <typename T>
void SortingSystem<T>::showMenu() {
    while (true) {
        cout << "\nSelect a sorting algorithm:" << endl;
        cout << "1. Selection Sort" << endl;
        cout << "2. Bubble Sort" << endl;

        if (is_same<T, int>::value) {
            cout << "3. Radix Sort" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice:\n";
        }
        else {
            cout << "3. Exit" << endl;
            cout << "Enter your choice:\n";
        }

        int choice;
        cin >> choice;

        int exitChoice = is_same<T, int>::value ? 4 : 3;
        if (choice == exitChoice) {
            cout << "Thank you for using the sorting system! Goodbye!" << endl;
            break;
        }

        switch (choice) {
            case 1:
                cout << "Selection Sort..." << endl;
                selectionSort();
                break;
            case 2:
                cout << "Bubble Sort..." << endl;
                bubbleSort();
                break;
            case 3:
                if (is_same<T, int>::value) {
                    cout << "Radix Sort..." << endl;
                    radixSort();
                }
                else {
                    cout << "Invalid choice! Please try again." << endl;
                }
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                continue;
        }
        cout << "Final Sorted Data: ";
        displayData();
        break;
    }
}

int main() {
    int datatype;
    cout << "Select the data type for the sorting system:" << endl;
    cout << "1. int" << endl;
    cout << "2. double" << endl;
    cout << "3. string" << endl;
    cout << "Enter your choice:\n";
    cin >> datatype;

    int size;
    cout << "Enter the size of the array:\n";
    cin >> size;

    switch (datatype) {
        case 1: {
            SortingSystem<int> system(size);
            system.showMenu();
            break;
        }
        case 2: {
            SortingSystem<double> system(size);
            system.showMenu();
            break;
        }
        case 3: {
            SortingSystem<string> system(size);
            system.showMenu();
            break;
        }
        default:
            cout << "Invalid choice! Exiting the program." << endl;
            break;
    }
}