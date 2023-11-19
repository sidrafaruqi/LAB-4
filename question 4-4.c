#include <stdio.h>
#include <stdlib.h>

struct sll {
    int data;
    struct sll* next;
};

void removeNodes(struct sll** head) {
    struct sll* current = *head;
    struct sll* prev = NULL;
    int i = 0;

    while (current != NULL) {
        if (i % 2 != 0) {
            // If you want to remove the current node at odd index
            if (prev == NULL) {
                *head = current->next;
                free(current);
                current = *head;
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
        i++;
    }
}

int main() {
    struct sll* head = NULL;
    struct sll* nodeA = (struct sll*)malloc(sizeof(struct sll));
    struct sll* nodeB = (struct sll*)malloc(sizeof(struct sll));
    struct sll* nodeC = (struct sll*)malloc(sizeof(struct sll));
    struct sll* nodeD = (struct sll*)malloc(sizeof(struct sll));
    struct sll* nodeE = (struct sll*)malloc(sizeof(struct sll));



    nodeA->data = 3;
    nodeB->data = 6;
    nodeC->data = 8;
    nodeD->data = 4;
    nodeE->data = 4;

    head = nodeA;
    nodeA->next = nodeB;
    nodeB->next = nodeC;
    nodeC->next = nodeD;
    nodeD->next = nodeE;
    nodeE->next = NULL;

    // Call the removeNodes function
    removeNodes(&head);

    // Print the modified list
    struct sll* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}


