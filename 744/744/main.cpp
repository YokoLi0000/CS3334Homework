#include <iostream>
#include <stack>
using namespace std;

int main() {
    int t;
    stack<int> A, B, S, temp;
    while (cin >> t) {
        for (int i=0; i<t; i++) {
            int n;
            cin >> n;
            for (int j=0; j<n; j++) {
                int num;
                cin >> num;
                A.push(num);
            }
            int m;
            cin >> m;
            for (int j=0; j<m; j++) {
                int* arr = new int[n];
                for (int k=0; k<n; k++) {
                    cin >> arr[k];
                }
                temp = A;
                bool valid;
                for (int k=0; k<n; k++) {
                    do {
                        valid = false;
                        if (!S.empty() && S.top()==arr[k]) {
                            B.push(S.top());
                            S.pop();
                            valid = true;
                        } else if (!temp.empty()) {
                            bool found = false;
                            if (temp.top()==arr[k]) {
                                found = true;
                            }
                            while (temp.top()!=arr[k]) {
                                S.push(temp.top());
                                temp.pop();
                                if (temp.empty()) {
                                    break;
                                }
                                if (temp.top()==arr[k]) {
                                    found = true;
                                }
                            }
                            if (found) {
                                B.push(temp.top());
                                temp.pop();
                                valid = true;
                            }
                        } else if (S.top()!=arr[k] && temp.empty()) {
                            valid = false;
                            break;
                        }
                        if (B.empty()) {
                            break;
                        }
                    } while (B.top()!=arr[k]);
                    if (!valid) {
                        cout << "Impossible\n";
                        break;
                    }
                }
                if (valid) {
                    cout << "Aye\n";
                }
                delete [] arr;
                arr = NULL;
                while (!temp.empty()) {
                    temp.pop();
                }
                while (!B.empty()) {
                    B.pop();
                }
                while (!S.empty()) {
                    S.pop();
                }
            }
            while (!A.empty()) {
                A.pop();
            }
        }
    }
    return 0;
}
