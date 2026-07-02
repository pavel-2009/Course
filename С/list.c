#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};


struct Node* push_front(struct Node *head, int data) {
    struct Node *new_head = (struct Node*) malloc(sizeof(struct Node));

    new_head->data = data;
    new_head->next = head;

    return new_head;
}


int main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;

    struct Node *second = (struct Node*) malloc(sizeof(struct Node));
    second->data = 20;
    second->next = NULL;

    head->next = second;

    struct Node *new_head = push_front(head, 30);

    struct Node *current = new_head;
    while (current != NULL) {
        printf("[Data: %d] -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    current = new_head;

    while (current != NULL) {
        struct Node *next_node = current->next; 
        free(current);          
        current = next_node;                    
    }
    new_head = NULL;

    return 0;
}