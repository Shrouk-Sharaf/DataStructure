#include <iostream>
using namespace std;

template<typename T>
void Bubble_sort(T arr[], int n){
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]){
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}




int main(){
    int data[] = {2, 8, 1, 9, 7, 3, 4};
    string names[] = {"hanna","jasmine","Ayat","reham","shrouk", "sayed","nada", "nader","jasmin","raneem"};
    double foo[] = { 2.2,1.1, 3.3, 4.5, 2.3, 2.22, 1.34, 4.50, 1.98, 1.03, 1.09};

    int data_size = sizeof(data) / sizeof(data[0]);
    int names_size = sizeof(names) / sizeof(names[0]);
    int foo_size = sizeof(foo) / sizeof(foo[0]);

    Bubble_sort(data, data_size);
    Bubble_sort(names, names_size);
    Bubble_sort(foo, foo_size);
}