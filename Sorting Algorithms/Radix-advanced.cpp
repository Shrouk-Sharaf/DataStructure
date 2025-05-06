#include <iostream>
#include <vector>
#include <climits>
using namespace std;

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

void radix_sort(vector<int>& arr) {
    int num_bits = sizeof(int) * CHAR_BIT;

    for (int bit_pos = 0; bit_pos < num_bits; bit_pos += 2) radix_sort_step(arr, bit_pos);
}

void radix_sort_int(vector<int>& arr) {
    for (int& num : arr) num ^= (1 << 31);
    radix_sort(arr);
    for (int& num : arr) num ^= (1 << 31);
    for (int num : arr) cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> data = {232, -8115, 3461, -329, 427, -143, 4, 0};
    radix_sort_int(data);
}