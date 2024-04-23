#include<iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int last_digit=0;
        n=n%60;
        if (n==0) {
            last_digit=0;
        } else if (n==1 || n==2) {
            last_digit=1;
        } else {
            int first_num=1, second_num=1;
            for (int i=2; i<n; i++) {
                last_digit=(first_num+second_num)%10;
                first_num=second_num;
                second_num=last_digit;
            }
        }
        cout << last_digit << "\n";
    }
    return 0;
}
