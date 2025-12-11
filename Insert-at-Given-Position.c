#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtPos(struct Node* head, int pos, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;

    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position!\n");
            free(newNode);
            return head;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

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

    head = insertAtPos(head, 1, 10);
    head = insertAtPos(head, 2, 20);
    head = insertAtPos(head, 3, 30);
    head = insertAtPos(head, 2, 15);

    printList(head);

    return 0;
}
