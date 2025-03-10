#include <iostream>
#include <vector>
#include <chrono>
#include <climits>
using namespace std;
using namespace std::chrono;

template<typename T>
void printArray(T arr[], int n);

template<typename T>
void Selection_sort(T arr[], int n);

template<typename T>
void Bubble_sort(T arr[], int n);

template<typename T>
void inputArray(T arr[], int n);

void Radix_sort(vector<int>& arr);

int main() {
    char repeat = 'y';
    while (repeat == 'y' || repeat == 'Y') {
        int size;
        cout << "Enter the number of items to sort: ";
        cin >> size;

        if (size <= 0) {
            cout << "Invalid size! Please enter a positive integer." << endl;
            continue;
        }

        int dataTypeChoice;
        cout << "Select data type:" << endl;
        cout << "1. Integers" << endl;
        cout << "2. Strings" << endl;
        cout << "3. Doubles" << endl;
        cout << "Enter your choice (1-3):\n";
        cin >> dataTypeChoice;

        void* arr = nullptr;
        switch (dataTypeChoice) {
            case 1:
                arr = new int[size];
                inputArray(static_cast<int*>(arr), size);
                break;
            case 2:
                arr = new string[size];
                inputArray(static_cast<string*>(arr), size);
                break;
            case 3:
                arr = new double[size];
                inputArray(static_cast<double*>(arr), size);
                break;
            default:
                cout << "Invalid data type choice!" << endl;
                continue;
        }

        int choice;
        cout << "Select a sorting algorithm:" << endl;
        cout << "1. Insertion Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Bubble Sort" << endl;
        cout << "4. Shell Sort" << endl;
        cout << "5. Merge Sort" << endl;
        cout << "6. Quick Sort" << endl;
        cout << "7. Count Sort (Only for integers)" << endl;
        cout << "8. Radix Sort (Only for integers)" << endl;
        cout << "9. Bucket Sort" << endl;
        cout << "Enter your choice (1-9):\n";
        cin >> choice;

        cout << "Sorting using ";
        auto start = high_resolution_clock::now();

        switch (choice) {
            case 1:
                cout << "Insertion Sort..." << endl;
//                if (dataTypeChoice == 1) Insertion_sort(static_cast<int*>(arr), size);
//                else if (dataTypeChoice == 2) Insertion_sort(static_cast<string*>(arr), size);
//                else if (dataTypeChoice == 3) Insertion_sort(static_cast<double*>(arr), size);
                break;

            case 2:
                cout << "Selection Sort..." << endl;
                if (dataTypeChoice == 1) Selection_sort(static_cast<int*>(arr), size);
                else if (dataTypeChoice == 2) Selection_sort(static_cast<string*>(arr), size);
                else if (dataTypeChoice == 3) Selection_sort(static_cast<double*>(arr), size);
                break;

            case 3: // Bubble Sort
                cout << "Bubble Sort..." << endl;
                if (dataTypeChoice == 1) Bubble_sort(static_cast<int*>(arr), size);
                else if (dataTypeChoice == 2) Bubble_sort(static_cast<string*>(arr), size);
                else if (dataTypeChoice == 3) Bubble_sort(static_cast<double*>(arr), size);
                break;
            case 4:
                cout << "Shell Sort..." << endl;
//                if (dataTypeChoice == 1) Shell_sort(static_cast<int*>(arr), size);
//                else if (dataTypeChoice == 2) Shell_sort(static_cast<string*>(arr), size);
//                else if (dataTypeChoice == 3) Shell_sort(static_cast<double*>(arr), size);
                break;
            case 5:
                cout << "Merge Sort..." << endl;
//                if (dataTypeChoice == 1) Merge_sort(static_cast<int*>(arr), 0, size - 1);
//                else if (dataTypeChoice == 2) Merge_sort(static_cast<string*>(arr), 0, size - 1);
//                else if (dataTypeChoice == 3) Merge_sort(static_cast<double*>(arr), 0, size - 1);
                break;
            case 6:
                cout << "Quick Sort..." << endl;
//                if (dataTypeChoice == 1) Quick_sort(static_cast<int*>(arr), 0, size - 1);
//                else if (dataTypeChoice == 2) Quick_sort(static_cast<string*>(arr), 0, size - 1);
//                else if (dataTypeChoice == 3) Quick_sort(static_cast<double*>(arr), 0, size - 1);
                break;
            case 7:
                cout << "Count Sort..." << endl;
//                if (dataTypeChoice == 1) Count_sort(static_cast<int*>(arr), size);
//                else cout << "Count Sort is only supported for integers." << endl;
                break;
            case 8:
                if (dataTypeChoice == 1) {
                    cout << "Radix Sort..." << endl;
                    vector<int> vec(static_cast<int*>(arr), static_cast<int*>(arr) + size);
                    Radix_sort(vec);
                    for (int i = 0; i < size; ++i) {
                        static_cast<int*>(arr)[i] = vec[i];
                    }
                }
                else cout << "Radix Sort is only supported for integers." << endl;
                break;
            case 9:
                cout << "Bucket Sort..." << endl;
//                if (dataTypeChoice == 1) Bucket_sort(static_cast<int*>(arr), size);
//                else if (dataTypeChoice == 2) Bucket_sort(static_cast<string*>(arr), 0, size - 1);
//                else if (dataTypeChoice == 3) Bucket_sort(static_cast<double*>(arr), 0, size - 1);
                break;
            default:
                cout << "please choose a valid option." << endl;
                break;

        }

        auto stop = high_resolution_clock::now();

        cout << "Sorted Data: ";
        if (dataTypeChoice == 1) printArray(static_cast<int*>(arr), size);
        else if (dataTypeChoice == 2) printArray(static_cast<string*>(arr), size);
        else if (dataTypeChoice == 3) printArray(static_cast<double*>(arr), size);

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Sorting Time: " << duration.count() / 1e6 << " seconds" << endl;

        if (dataTypeChoice == 1) delete[] static_cast<int*>(arr);
        else if (dataTypeChoice == 2) delete[] static_cast<string*>(arr);
        else if (dataTypeChoice == 3) delete[] static_cast<double*>(arr);

        cout << "Do you want to sort another dataset? (y/n): ";
        cin >> repeat;
    }

    cout << "Thank you for using the sorting system! Goodbye!" << endl;
}

template<typename T>
void printArray(T arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

template<typename T>
void Selection_sort(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }

        // Print the array after each iteration
        cout << "Iteration " << i + 1 << ": ";
        printArray(arr, n);
    }
}

template<typename T>
void Bubble_sort(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Print the array after each pass
        cout << "After pass " << i + 1 << ": ";
        printArray(arr, n);

        if (!swapped) break;
    }
}

template<typename T>
void inputArray(T arr[], int n) {
    cout << "Enter data to sort:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Enter data " << i + 1 << ": ";
        cin >> arr[i];
    }
}

int get_bit(int value, int k) {
    return (value >> k) & 1;
}

void radix_sort_step(vector<int>& arr, int bit_pos) {
    const int num_bins = 4;
    vector<int> count(num_bins, 0);

    for (int num : arr) {
        int bin = (get_bit(num, bit_pos + 1) << 1) | get_bit(num, bit_pos);
        count[bin]++;
    }

    for (int i = 1; i < num_bins; i++) count[i] += count[i - 1];

    vector<int> sorted(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        int bin = (get_bit(arr[i], bit_pos + 1) << 1) | get_bit(arr[i], bit_pos);
        sorted[--count[bin]] = arr[i];
    }
    arr = sorted;
}

void Radix_sort(vector<int>& arr) {
    int num_bits = sizeof(int) * CHAR_BIT;

    for (int bit_pos = 0; bit_pos < num_bits; bit_pos += 2) radix_sort_step(arr, bit_pos);
}