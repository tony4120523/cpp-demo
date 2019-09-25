#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
// new init show insert search remove delete

struct Node {
    int n;
    Node* pNext;
};

Node* newNode() {
    Node* pNew = (Node*)malloc(sizeof(Node));
    return pNew;
}

void showList(Node* p) {
    while (p) {
        cout << "Member : " << p->n << endl;
        p = p->pNext;
    }
    return;
}

Node* initList(Node** ppHead) {
    for (int i = 4; i>=0; i--) {
        Node* pNew = newNode();
        pNew->pNext = *ppHead;
        *ppHead = pNew;
        pNew->n = i;
    }
    return *ppHead;
}

Node* insert(Node* pre, Node* next, Node* pNew, int n) {
    pNew->pNext = next;
    pre->pNext = pNew;
    pNew->n = n;
    return pNew;
}

Node* search(Node* p, int key) {
    while (p) {
        if (p->n == key)
            return p;
        p = p->pNext;
    }
    return NULL;
}

Node* remove(Node** ppHead, Node* p, int key) {
    Node* pPre = NULL;
    while (p) {
        if (p->n == key) {
            Node* pTem = p->pNext;
            free(p);
            if (pPre)  pPre->pNext = pTem;
            else  *ppHead = pTem;
        }
        pPre = p;
        p = p->pNext;
    }
    return NULL;
}

void delList(Node* pHead) {
    while (pHead) {
        Node* tmp = pHead->pNext;
        free(pHead);
        pHead = tmp;
    }
}

int main() {
    Node* pHead = NULL;
    cout << "=================" << endl;

    initList(&pHead);
    cout << "Initial List : " << endl;
    showList(pHead);
    cout << "=================" << endl;

    // add node between 1 and 2
    insert(pHead->pNext, pHead->pNext->pNext, newNode(), 99);
    cout << "Insert 99 between 1 and 2" << endl;
    showList(pHead);
    cout << "=================" << endl;

    Node* tmp = search(pHead, 99);
    cout << "Found : " << tmp->n << endl;
    cout << "=================" << endl;

    remove(&pHead, pHead, 0);
    cout << "Remove member : " << endl;
    showList(pHead);
    cout << "=================" << endl;

    delList(pHead);
    return 0;
}


