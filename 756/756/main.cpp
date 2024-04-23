#include <iostream>
using namespace std;

void insert(int*arr, int index, int k) {
    int cur_index = index, parent_index;
    arr[cur_index] = k;
    if (cur_index>1) {
        parent_index = cur_index/2;
        while (arr[cur_index]>arr[parent_index] && parent_index!=0) {
            int temp = arr[cur_index];
            arr[cur_index] = arr[parent_index];
            arr[parent_index] = temp;
            cur_index /= 2;
            parent_index /= 2;
        }
    }
}

void pop(int*arr, int index) {
    int start = 1;
    arr[start] = arr[index];
    arr[index] = 0;
    while (start*2<=index-1 && (arr[start*2]>arr[start] || arr[start*2+1]>arr[start])) {
        if (arr[start*2]>arr[start] && arr[start*2+1]>arr[start]) {
            if (arr[start*2]>arr[start*2+1]) {
                int temp = arr[start*2];
                arr[start*2] = arr[start];
                arr[start] = temp;
                start *= 2;
            } else {
                int temp = arr[start*2+1];
                arr[start*2+1] = arr[start];
                arr[start] = temp;
                start = start * 2 + 1;
            }
        } else if (arr[start*2]>arr[start]) {
            int temp = arr[start*2];
            arr[start*2] = arr[start];
            arr[start] = temp;
            start *= 2;
        } else if (arr[start*2+1]>arr[start]) {
            int temp = arr[start*2+1];
            arr[start*2+1] = arr[start];
            arr[start] = temp;
            start = start * 2 + 1;
        }
    }
}

void print(int*arr, int index) {
    int sum = 0;
    for (int i=1; i<=index; i++) {
        sum += arr[i];
    }
    cout << sum << "\n";
}

int main() {
    int N;
    while (cin >> N) {
        int index = 0;
        int *arr = new int[N+1];
        for (int i=0; i<N; i++) {
            char operation;
            cin >> operation;
            if (operation=='a') {
                index++;
                int k;
                cin >> k;
                insert(arr, index, k);
            } else if (operation=='p') {
                pop(arr, index);
                index--;
            } else if (operation=='r') {
                print(arr, index);
            }
        }
        delete[] arr;
    }
    return 0;
}
