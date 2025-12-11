#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAfter(struct Node* head, int key, int value) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }

    printf("Key not found!\n");
    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    
    head = (struct Node*) malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;

    head = insertAfter(head, 10, 20);
    head = insertAfter(head, 20, 30);

    printList(head);

    return 0;
}
