#include <stdio.h>
#include <stdlib.h>

struct sll {
    int data;
    struct sll* next;
};

struct sll* merge(struct sll** head1, struct sll** head2) {
    struct sll* t1 = *head1;
    struct sll* t2 = *head2;
    struct sll dummy; // Dummy node to simplify the code
    struct sll* t3 = &dummy;

    while (t1 != NULL && t2 != NULL) {
        if (t1->data < t2->data) {
            t3->next = t1;
            t1 = t1->next;
        } else {
            t3->next = t2;
            t2 = t2->next;
        }
        t3 = t3->next;
    }

    // Attach the remaining nodes of t1 and t2
    while (t1 != NULL) {
        t3->next = t1;
        t1 = t1->next;
        t3 = t3->next;
    }

    while (t2 != NULL) {
        t3->next = t2;
        t2 = t2->next;
        t3 = t3->next;
    }

    *head1 = dummy.next; // Update head1 to point to the merged list
    *head2 = NULL; // Update head2 to NULL as its elements are now part of the merged list
    return dummy.next; // Return the merged list
}

int main() {
    struct sll* head1 = NULL;
    struct sll* nodeA = (struct sll*)malloc(sizeof(struct sll));
    struct sll* nodeB = (struct sll*)malloc(sizeof(struct sll));
    struct sll* nodeC = (struct sll*)malloc(sizeof(struct sll));

    nodeA->data = 3;
    nodeB->data = 6;
    nodeC->data = 8;

    head1 = nodeA;
    nodeA->next = nodeB;
    nodeB->next = nodeC;
    nodeC->next = NULL;

    struct sll* head2 = NULL;
    struct sll* node1 = (struct sll*)malloc(sizeof(struct sll));
    struct sll* node2 = (struct sll*)malloc(sizeof(struct sll));
    struct sll* node3 = (struct sll*)malloc(sizeof(struct sll));

    node1->data = 2;
    node2->data = 4;
    node3->data = 9;

    head2 = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    struct sll* mergedList = merge(&head1, &head2);

    struct sll* temp = mergedList;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
