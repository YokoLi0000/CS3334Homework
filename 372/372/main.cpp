#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        int n;
        cin >> n;
        int walls[n];
        for (int j=0; j<n; j++) {
            cin >> walls[j];
        }
        int lowJump = 0, highJump = 0;
        for (int j=0; j<n-1; j++) {
            if (walls[j+1]<walls[j]) {
                lowJump++;
            } else if (walls[j+1]==walls[j]){
                continue;
            } else {
                highJump++;
            }
        }
        cout << "Case " << i+1 << ": " << highJump << " " << lowJump << "\n";
    }
    return 0;
}
