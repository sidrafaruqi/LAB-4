#include <stdio.h>
#include <stdlib.h>

struct sll {
    int data;
    struct sll* next;
};

int* convert(struct sll *head1, int elements) {
    int *a = (int *)malloc(elements * sizeof(int));

    int i; // Declare i
    while (head1 != NULL) {
        for (i = 0; i < elements; i++) {
            a[i] = head1->data;
            head1 = head1->next;
        }
    }

    return a;
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

    int elements = 3;

    int *result = convert(head1, elements);

    // Print the array
    printf("Converted Array: ");
    for (int i = 0; i < elements; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Don't forget to free the allocated memory when done
    free(result);

    return 0;
}
