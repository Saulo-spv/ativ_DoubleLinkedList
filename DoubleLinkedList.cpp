#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

typedef struct Node {
    int iValue;
    Node* ptrNext;
    Node* ptrPrev;
} Node;


Node* newNode(int);
void addElementEnd(Node**, int);
void showList(Node*);
void insertBefore(Node*, int);
void deleteNodebyValue(Node**, int);
Node* searchNodebyValue(Node**, int);


int main() {
    Node* head = nullptr;

    // Adicionando elementos à lista
    addElementEnd(&head, 10);
    addElementEnd(&head, 20);
    addElementEnd(&head, 30);

    // Mostrando a lista
    cout << "Lista Original:" << endl;
    showList(head);

    return 0;
}


Node* newNode(int iPayload) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iValue = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;
    
    return temp;
}

void addElementEnd(Node** head, int iValue) {
    Node* node = newNode(iValue);
    if ((*head) == NULL) {   
        (*head) = node;
    } else {
        Node* current = (*head);
        // Percurso até o fim da lista
        while (current->ptrNext != NULL) current = current->ptrNext;
        // Insercao do no
        node->ptrPrev = current;
        current->ptrNext = node;
    }
}

void showList(Node* head) {
    if (head == NULL) {
        cout << "Lista Vazia!" << endl;
    } else if (head->ptrPrev != NULL) {
        cout << "Não é possivel printar a partir do meio da lista!" << endl;
    } else {
        Node* current = head;
        cout << "Elementos: \n";
        // Percurso até o fim da lista
        while (current != NULL) {
            cout << current->iValue << " " << endl;
            current = current->ptrNext;
        } 
    }
}
