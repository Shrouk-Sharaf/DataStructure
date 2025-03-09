#include <iostream>
using namespace std;


template<typename t>
void selection_sort(t data[], int n){
    for (int i = 0; i < n; ++i) {
        t min = data[i];
        int index = i;
        for (int j = i; j < n; ++j) {
            if (data[j] < min) {
                min = data[j];
                index = j;
            }
        }
        t temp = data[i];
        data[i] = data[index];
        data[index] = temp;
    }

    for (int i = 0; i < n; ++i) {
        cout << data[i] << " ";

    }
    cout << endl;
}

int main(){
    int data[] = {2, 8, 1, 9, 7, 3, 4};
    string names[] = {"hanna","jasmine","Ayat","reham","shrouk", "sayed","nada", "nader","jasmin","raneem"};
    double foo[] = { 2.2,1.1, 3.3, 4.5, 2.3, 2.22, 1.34, 1.98, 1.03, 1.09};

    selection_sort(data, 7);
    selection_sort(names, 10);
    selection_sort(foo, 10);
}
