#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class List {
public:
    void traverse(int);
    void reset();
    void insert(int, int);
    void remove(int);
    void reverse(int, int);
    void query(int);
    List(){ head = NULL; ref = head;}
    
private:
    Node *head;
    Node *ref;
};

void List::traverse(int cnt) {
    for(int i=0; i<cnt-1; i++)
        ref = ref->next;
}

void List::reset() { ref=head; }

void List::insert(int ith, int data) {
    Node* n = new Node();
    n->data = data;
    if(ith == 0) {
        if(head==NULL)
            head = n;
        else
            ref->next = n;
        
        n->next = NULL;
        ref = n;
    }
    else {
        traverse(ith);
        n->next = ref->next;
        ref->next = n;
    }
}

void List::remove(int ith) {
    if(ith == 1)
        head = head->next;
    else {
        traverse(ith-1);
        ref->next = ref->next->next;
    }
}

void List::reverse(int ith, int jth) {
    Node *iprev, *i, *j, *jnext;
    traverse(ith - 1);
    iprev = ref;
    if (ith == 1) {
        i = head;
        traverse((jth - ith) + 1);
    }
    else {
        i = iprev->next;
        traverse(1 + (jth - ith) + 1);
    }
    j = ref;
    jnext = j->next;
    Node *pre, *cur, *nex;
    pre = i;
    cur = pre->next;
    nex = cur->next;
    while(cur != jnext) {
        cur->next = pre;
        pre = cur;
        cur = nex;
        if(nex!=NULL)
            nex = nex->next;
    }
    i->next = jnext;
    if (ith == 1)
        head = j;
    else
        iprev->next = j;
}

void List::query(int ith) {
    traverse(ith);
    cout << ref->data << endl;
}

int main() {
    int n;
    cin >> n;
    List L;
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        L.insert(0, num);
    }
    L.reset();
    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int operation, i_th;
        cin >> operation >> i_th;
        switch (operation) {
            case 1:
                int data;
                cin >> data;
                L.insert(i_th, data);
                break;
              
            case 2:
                L.remove(i_th);
                break;
                
            case 3:
                int j_th;
                cin >> j_th;
                L.reverse(i_th, j_th);
                break;
                
            case 4:
                L.query(i_th);
                break;
            
            default:
                break;
        }
        L.reset();
    }
    
    return 0;
}
