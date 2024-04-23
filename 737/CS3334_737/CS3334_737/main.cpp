#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string strArr[100];
    string x="";
    vector<string> str;
    vector<string> outputStr;
    vector<int> count;
    while (cin>>x) {
        str.push_back(x);
    }
    int size=0;
    for (int i=0; i<str.size(); i++) {
        string tempStr=str[i];
        if (i!=0) {
            bool isArrExist=false;
            for (int j=0; j<size; j++) {
                if (tempStr==outputStr[j]) {
                    isArrExist=true;
                    count[j]++;
                    continue;
                }
            }
            if (!isArrExist) {
                int position=0;
                while (tempStr>outputStr[position]) {
                    if (position==size) {
                        outputStr.insert(outputStr.begin()+position, tempStr);
                        count.insert(count.begin()+position, 1);
                    } else {
                        position++;
                    }
                }
                outputStr.insert(outputStr.begin()+position, tempStr);
                count.insert(count.begin()+position, 1);
                size++;
            }
        } else {
            outputStr.push_back(tempStr);
            count.push_back(1);
            size++;
        }
    }
    
    for (int i=0; i<size; i++) {
        cout << outputStr[i] << " " << count[i] << "\n";
    }
    
    return 0;
}
