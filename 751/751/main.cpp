#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<int> cal;
    string s;
    while (getline(cin, s)) {
        for (char&c: s) {
            if (c>='0' && c<='9') {
                int n = c-'0';
                cal.push(n);
            } else if (c==' ') {
                continue;
            } else {
                int o1, o2, result = 0;
                o2 = cal.top();
                cal.pop();
                o1 = cal.top();
                cal.pop();
                switch (c) {
                    case '+':
                        result = o1 + o2;
                        break;
                
                    case '-':
                        result = o1 - o2;
                        break;
                        
                    case '*':
                        result = o1 * o2;
                        break;
                        
                    default:
                        break;
                }
                cal.push(result);
            }
        }
        cout << cal.top() << "\n";
        cal.pop();
    }
    return 0;
}
