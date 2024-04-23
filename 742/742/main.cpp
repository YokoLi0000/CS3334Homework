#include <iostream>
#include <cmath>
using namespace std;

char** set(int size) {
    char** pixel = new char*[size];
    for (int i=0; i<size; i++) {
        char* side = new char[size];
        pixel[i] = side;
        string l;
        cin >> l;
        for (int j=0; j<size; j++) {
            pixel[i][j]=l[j];
        }
    }
    return pixel;
}

int countNodes(char** edge, int x1, int y1, int x2, int y2) {
    bool same = true;
    int count = 1;
    char c = edge[x1][y1];
    for (int i=x1; i<=x2; i++) {
        for (int j=y1; j<=y2; j++) {
            if (edge[i][j]!=c) {
                same = false;
                break;
            }
        }
        if (!same) {
            break;
        }
    }
    if (same) {
        return 1;
    }
    return (count + countNodes(edge, x1, y1, (x1+x2)/2, (y1+y2)/2) + countNodes(edge, (x1+x2)/2+1, y1, x2, (y1+y2)/2) + countNodes(edge, (x1+x2)/2+1, (y1+y2)/2+1, x2, y2) + countNodes(edge, x1, (y1+y2)/2+1, (x1+x2)/2, y2));
}

int main() {
    int k;
    while (cin >> k) {
        int size = pow(2, k);
        char** pixel = new char*[size];
        pixel = set(size);
        cout << countNodes(pixel, 0, 0, size-1, size-1) << "\n";
    }
    return 0;
}
