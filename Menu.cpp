#include "SortingSystem.h"

template <typename T>
SortingSystem<T>::SortingSystem(int n) {
    size = n;
    data = new T[size];
}

template <typename T>
SortingSystem<T>::~SortingSystem() {
    cout << "Dataset is deleted successfully" << endl;
    delete[] data;
}

template <typename T>
void SortingSystem<T>::setData() {
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> data[i];
    }
}

template <typename T>
void SortingSystem<T>::selectionSort() {
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
    }
}

template <typename T>
void SortingSystem<T>::bubbleSort() {
    for (int i = 0; i < size - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

template <typename T>
void SortingSystem<T>::radixSort() {
    T maxVal = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > maxVal) {
            maxVal = data[i];
        }
    }

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        T* output = new T[size];
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
        cout << "3. Radix Sort" << endl;
        cout << "4. Enter new dataset" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5):\n";
        int choice;
        cin >> choice;

        if (choice == 5) {
            cout << "Thank you for using the sorting system! Goodbye!" << endl;
            break;
        } else if (choice == 4) {
            setData();
            continue;
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
                cout << "Radix Sort..." << endl;
                radixSort();
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                continue;
        }

        cout << "Sorted Data: ";
        displayData();

        int option;
        while (true) {
            cout << "\n1) Sort again using a different algorithm\n2) Enter a new dataset\n3) Exit\n";
            cout << "Enter your choice (1-3):\n";
            cin >> option;

            if (option == 1) {
                break;
            }
            else if (option == 2) {
                setData();
                break;
            }
            else if (option == 3) {
                cout << "Thank you for using the sorting system! Goodbye!" << endl;
                return;
            }
            else cout << "Invalid option! Please enter a number between 1 and 3." << endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array:\n";
    cin >> n;

    SortingSystem<int> sorter(n);
    sorter.setData();
    sorter.showMenu();
}