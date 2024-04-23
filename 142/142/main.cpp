#include <iostream>
using namespace std;

class DisjointSet{
private:
    int set[30000], count[30000], rank[30000], max;

public:
    DisjointSet(int n) {
        max = 1;
        for (int i=0; i<n; i++) {
            set[i] = i;
            count[i] = 1;
            rank[i] = 0;
        }
    }
    
    int Find(int i) {
        if (i!=set[i]) {
            set[i] = Find(set[i]);
        }
        return set[i];
    }
    
    bool Same(int i, int j) {
        return Find(i)==Find(j);
        
    }
    
    void Union(int i, int j) {
        if (!Same(i, j)) {
            if (rank[i]>rank[j]) {
                set[j] = i;
                count[i] += count[j];
                if (max<count[i]) {
                    max = count[i];
                }
            } else {
                set[i] = j;
                count[j] += count[i];
                if (max<count[j]) {
                    max = count[j];
                }
                if (rank[i]==rank[j]) {
                    rank[j]++;
                }
            }
        }
    }
    
    int getMax() {
        return max;
    }
};


int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        int ppl1, ppl2;
        int n, m;
        cin >> n >> m;
        DisjointSet set(n);
        for (int j=0; j<m; j++) {
            cin >> ppl1 >> ppl2;
            ppl1--;
            ppl2--;
            set.Union(set.Find(ppl1), set.Find(ppl2));
        }
        cout << set.getMax() << "\n";
    }
    return 0;
}
