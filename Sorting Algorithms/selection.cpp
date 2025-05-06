#include <iostream>
using namespace std;

template<typename T>
void selection_sort(T data[], int n) {
    for (int i = 0; i < n; ++i) {
        T min = data[i];
        int index = i;
        for (int j = i; j < n; ++j) {
            if (data[j] < min) {
                min = data[j];
                index = j;
            }
        }
        T temp = data[i];
        data[i] = data[index];
        data[index] = temp;

        cout << "After iteration " << i + 1 << ": ";
        for (int k = 0; k < n; ++k) {
            cout << data[k] << ", ";
        }
        cout << endl;
    }
    cout << "Final sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << data[i] << ", ";
    }
    cout << endl << endl;
}

int main() {
    string data[] = {"Nablus", "Gaza", "Al-Khalil", "Ramallah", "Ariha", "Jenin", "Tolkarem", "Al-Quds", "Yafa"};
   // string names[] = {"hanna", "jasmine", "Ayat", "reham", "shrouk", "sayed", "nada", "nader", "jasmin", "raneem"};
   // double foo[] = {2.2, 1.1, 3.3, 4.5, 2.3, 2.22, 1.34, 1.98, 1.03, 1.09};

    cout << "Sorting integers:" << endl;
    selection_sort(data, 9);

//    cout << "Sorting strings:" << endl;
//    selection_sort(names, 10);
//
//    cout << "Sorting doubles:" << endl;
//    selection_sort(foo, 10);
}