#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        stack<char> codes;
        int position = 0;
        bool unmatch = false;
        for (int i=0; i<s.length(); i++) {
            if (codes.empty()) {
                position = i + 1;
            }
            if (s[i]=='(' || s[i]=='[' || s[i]=='{') {
                codes.push(s[i]);
            } else if (s[i]==')' || s[i]==']' || s[i]=='}') {
                if (codes.empty()) {
                    position = i + 1;
                    unmatch = true;
                    break;
                } else {
                    char c = codes.top();
                    if (c=='(' && char(c+1)==s[i]) {
                        codes.pop();
                    } else if ((c == '[' || c == '{') && char(c+2)==s[i]) {
                        codes.pop();
                    } else {
                        position = i + 1;
                        unmatch = true;
                        break;
                    }
                }
            }
        }
        if (unmatch || !codes.empty()) {
            cout << position << "\n";
        } else {
            cout << "Success\n";
        }
    }
    return 0;
}
