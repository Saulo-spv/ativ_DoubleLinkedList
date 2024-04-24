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
void deleteNode(Node**, Node*);
void deleteNodebyValue(Node**, int);
Node* searchNodebyValue(Node*, int);


int main() {
    Node* head = nullptr;

    // Adicionando elementos à lista
    addElementEnd(&head, 10);
    addElementEnd(&head, 20);
    addElementEnd(&head, 30);

    // Mostrando a lista
    cout << "Lista Original:" << endl;
    showList(head);

    // Procurando um nó com valor 20
    Node* node20 = searchNodebyValue(head, 20);
    if (node20 != nullptr) {
        cout << "\nNó com valor 20 encontrado." << endl;
    }

    // Inserindo um nó antes do nó com valor 20
    if (node20 != nullptr) {
        cout << "\nInserindo 15 antes do nó com valor 20:" << endl;
        insertBefore(node20, 15);
        showList(head);
    }

    // Deletando o nó com valor 20
    cout << "\nDeletando o nó com valor 20:" << endl;
    deleteNodebyValue(&head, 20);
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

Node* searchNodebyValue(Node* head, int iValue)
{
    if (head == nullptr) {
        cout << "Lista Vazia!." << endl;
        return head;
    } else {
        // Criamos um nó currente a avançamos até encontrar o nó buscado
        Node* current = head;
        while (current != nullptr && current->iValue != iValue) current = current->ptrNext;
        
        // Verificamos se o nó desejado foi encontrado
        if (current == nullptr) {
            cout << "Valor não encontrado." << endl;
            return current;
        } else {
            return current;
        }
    }
}

void insertBefore(Node* position, int iValue){
    if(position == nullptr){
        cout << "Impossivel inserir nessa posição!" << endl;
        return;
    }

    Node* node = newNode(iValue);

    // Insere o nó na posição desejada
    if (position->ptrPrev == nullptr) {
        position->ptrPrev = node;
        node->ptrNext = position;
    } else{
        Node* temp = position->ptrPrev;
        temp->ptrNext = node;
        node->ptrPrev = temp;
        node->ptrNext = position;
        position->ptrPrev = node;
    }
}

void deleteNode(Node** head, Node* node) {
    if ((*head) == NULL || node == NULL){
        cout << "Lista ou ponteiro vazio." << endl;
        return;
    }

    // Atualiza os ponteiros e exclui o no desejado
    if ((*head) == node) (*head) = node->ptrNext;
    if (node->ptrNext != NULL) node->ptrNext->ptrPrev = node->ptrPrev;
    if (node->ptrPrev != NULL) node->ptrPrev->ptrNext = node->ptrNext;
    free(node);
}

void deleteNodebyValue(Node** head, int iValue) {
    Node* node = searchNodebyValue(*head, iValue);
    deleteNode(head, node);
}