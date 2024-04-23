#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        int n;
        cin >> n;
        vector<int> cards;
        for (int j=0; j<n; j++) {
            int num;
            cin >> num;
            cards.push_back(num);
        }
        int m;
        cin >> m;
        for (int j=0; j<m; j++) {
            char operation;
            cin >> operation;
            switch (operation) {
                case 'm': {
                    int largestNum = 0;
                    for (int k=0; k<cards.size(); k++) {
                        if (cards[k]>largestNum) {
                            largestNum = cards[k];
                        }
                    }
                    cout << largestNum << "\n";
                    break;
                }
                    
                case 'r': {
                    cards.pop_back();
                    break;
                }
                    
                case 'a': {
                    int add;
                    cin >> add;
                    cards.push_back(add);
                    break;
                }
                    
                default:
                    break;
            }
        }
    }
    return 0;
}
