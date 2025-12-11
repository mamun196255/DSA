#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertBefore(struct Node* head, int key, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        printf("List empty!\n");
        free(newNode);
        return head;
    }

    // Case: insert before head
    if (head->data == key) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Key not found!\n");
        free(newNode);
        return head;
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

    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;

    head = insertBefore(head, 10, 5);
    head = insertBefore(head, 5, 2);

    printList(head);

    return 0;
}
