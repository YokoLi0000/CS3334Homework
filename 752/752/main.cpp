#include <iostream>
#include <queue>
using namespace std;

class task {
private:
    int Ri, Wi, order;
    
public:
    task(int Ri, int Wi, int order) {
        this->Ri = Ri;
        this->Wi = Wi;
        this->order = order;
    }
    int getRi();
    int getWi();
    int getOrder();
};

int task::getRi() {
    return Ri;
}

int task::getWi() {
    return Wi;
}

int task::getOrder() {
    return order;
}

int main() {
    int n;
    while (cin >> n) {
        queue<task> highPriority;
        queue<task> lowPriority;
        int timeArray[n];
        int finishingTime = 0;
        for (int i=0; i<n; i++) {
            int Ri, Wi, Pi;
            cin >> Ri >> Wi >> Pi;
            if (Pi==0) {
                highPriority.push(task(Ri, Wi, i));
            } else {
                lowPriority.push(task(Ri, Wi, i));
            }
        }
        //bool nextProcessLow = false;
        for (int i=0; i<n; i++) {
            bool processHigh = true;
            if (!lowPriority.empty()) {
                if (highPriority.empty()) {
                    processHigh = false;
                } else if (lowPriority.front().getRi()<=finishingTime && highPriority.front().getRi()>lowPriority.front().getRi() && highPriority.front().getRi()>finishingTime) {
                    processHigh = false;
                } else if (finishingTime==0 && highPriority.front().getRi()>lowPriority.front().getRi()) {
                    processHigh = false;
                } else if (lowPriority.front().getRi()>finishingTime && highPriority.front().getRi()>lowPriority.front().getRi()) {
                    processHigh = false;
                }
            }
            if (processHigh) {
                if (finishingTime==0 || finishingTime<highPriority.front().getRi()) {
                    finishingTime = highPriority.front().getRi();
                }
                finishingTime += highPriority.front().getWi();
                timeArray[highPriority.front().getOrder()] = finishingTime;
                highPriority.pop();
            } else {
                if (finishingTime==0 || finishingTime < lowPriority.front().getRi()) {
                    finishingTime = lowPriority.front().getRi();
                }
                finishingTime += lowPriority.front().getWi();
                timeArray[lowPriority.front().getOrder()] = finishingTime;
                lowPriority.pop();
            }
        }
        for (int i=0; i<n-1; i++) {
            cout << timeArray[i] << " ";
        }
        cout << timeArray[n-1] << "\n";
    }
    return 0;
}
