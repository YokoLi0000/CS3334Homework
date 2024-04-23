#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        queue<int> customerQueue;
        int serveTime = 0;
        for (int i=0; i<N; i++) {
            int A, O, L;
            cin >> A >> O >> L;
            if (N==1) {
                serveTime = A;
                break;
            }
            if (i==0) {
                customerQueue.push(A + O);
            } else {
                while (customerQueue.front()<=A && !customerQueue.empty()) {
                    customerQueue.pop();
                }
                if (i<N-1) {
                    if (customerQueue.size()<=L) {
                        if (A>customerQueue.back()) {
                            serveTime = A + O;
                        } else {
                            serveTime = customerQueue.back() + O;
                        }
                        customerQueue.push(serveTime);
                    }
                } else {
                    if (customerQueue.size()<=L) {
                        if (A>customerQueue.back()) {
                            serveTime = A;
                        } else {
                            serveTime = customerQueue.back();
                        }
                    } else {
                        serveTime = -1;
                    }
                }
                
            }
        }
        cout << serveTime << "\n";
    }
    return 0;
}
