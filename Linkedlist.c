#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void display(node *head) {
    printf("The elements are: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

node *insertAtStart(node *head, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

node *insertAtEnd(node *head, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = newNode;
    return head;
}

node *insertAtPosition(node *head, int data, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return head;
    }

    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;

    if (position == 0) {
        newNode->next = head;
        return newNode;
    }

    node *p = head;
    for (int i = 0; i < position - 1 && p != NULL; i++) {
        p = p->next;
    }

    if (p == NULL) {
        printf("Invalid position\n");
        return head;
    }

    newNode->next = p->next;
    p->next = newNode;
    return head;
}

node *deleteAtStart(node *head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

node *deleteAtEnd(node *head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    node *p = head;
    while (p->next->next != NULL) {
        p = p->next;
    }

    free(p->next);
    p->next = NULL;
    return head;
}

node *deleteAtPosition(node *head, int position) {
    if (head == NULL || position < 0) {
        printf("Invalid operation\n");
        return head;
    }

    if (position == 0) {
        node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    node *p = head;
    for (int i = 0; i < position - 1 && p != NULL; i++) {
        p = p->next;
    }

    if (p == NULL || p->next == NULL) {
        printf("Invalid position\n");
        return head;
    }

    node *temp = p->next;
    p->next = p->next->next;
    free(temp);
    return head;
}

int main() {
    node *head = NULL;

    head = insertAtStart(head, 32);
    display(head);

    head = insertAtEnd(head, 56);
    display(head);

    head = insertAtPosition(head, 99, 1);
    display(head);

    head = deleteAtStart(head);
    display(head);

    head = deleteAtEnd(head);
    display(head);

    head = deleteAtPosition(head, 0);
    display(head);

    return 0;
}
