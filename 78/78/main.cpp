#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<string> output;
    cin >> n;
    for (int i=0; i<n; i++) {
        string word;
        cin >> word;
        string temp = word, result = "";
        int count = 0, c;
        while (count<temp.length()) {
            char compare = 'a';
            c = count;
            while (c<temp.length()) {
                if (temp[c]>compare) {
                    compare = temp[c];
                    count = c;
                }
                c++;
            }
            result += compare;
            count++;
        }
        output.push_back(result);
    }
    
    for (int i=0; i<output.size(); i++) {
        cout << output[i] << "\n";
    }
    
    return 0;
}
