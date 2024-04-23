#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class List {
public:
    void traverse(int);
    void insert(int, int);
    void remove(int);
    void print(int);
    void resetRef();
    List() {head = NULL; ref = head;}
    void printAll();
private:
    Node* head;
    Node* ref;
};

void List::traverse(int cnt) {
    for(int i=1; i<cnt; i++)
        ref = ref->next;
}

void List::insert(int i, int data) {
    Node* n = new Node();
    n->data = data;
    if(i==0) {
        if(head==NULL)
            head = n;
        else
            ref->next = n;
        
        n->next = NULL;
        ref = n;
    }
    else {
        traverse(i);
        n->next = ref->next;
        ref->next = n;
        ref = n;
    }
}

void List::remove(int i) {
    traverse(i-1);
    ref->next = ref->next->next;
    ref = ref->next;
}

void List::print(int i) {
    traverse(i);
    cout << ref->data << endl;
}

void List::resetRef() {
    ref->next = head;
    ref = head;
}

void List::printAll() {
    Node* n = head;
    do {
        cout<<n->data<<" ";
        n = n->next;
    } while(n!=head);
}

int main() {
    int n;
    cin >> n;
    List Circle;
    for (int i=0; i<n; i++) {
        int tags;
        cin >> tags;
        Circle.insert(0, tags);
    }
    Circle.resetRef();
    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int operation, i_th;
        cin >> operation >> i_th;
        switch (operation) {
            case 1:
                int tags;
                cin >> tags;
                Circle.insert(i_th, tags);
                break;
            
            case 2:
                Circle.remove(i_th);
                break;
                
            case 3:
                Circle.print(i_th);
                
            default:
                break;
        }
    }
    
    return 0;
}
