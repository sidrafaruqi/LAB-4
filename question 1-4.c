#include <stdio.h>
#include <stdlib.h>

struct address {
    char name[100];
    char email[100];
    int number;
};

int i = 0;

void addcontact(struct address **m) {
    struct address *k = (struct address *)realloc(*m, (i + 1) * sizeof(struct address));
    *m = k;

    printf("\nEnter Contact Information:\n");
    printf("Name: ");
    scanf("%s", m[i]->name);
    printf("Email: ");
    scanf("%s", m[i]->email);
    printf("Phone Number: ");
    scanf("%d", &m[i]->number);

    printf("CONTACT HAS BEEN ADDED!\n");
    i++;
}

void displaycontacts(struct address *m) {
    for (int j = 0; j < i; j++) {
        printf("\nADDRESS %d\n", j + 1);
        printf("NAME: %s\n", (m + j)->name);
        printf("Email: %s\n", (m + j)->email);
        printf("NUMBER: %d\n", (m + j)->number);
    }
}

void deletecontact(struct address *m, int a) {
    if (a >= 1 && a <= i) {
        for (int j = a - 1; j < i - 1; j++) {
            m[j] = m[j + 1];
        }
        i--;
        printf("Contact deleted successfully.\n");
    } else {
        printf("Invalid contact number.\n");
    }
}

int main() {
    int a, b;
    struct address *y = NULL;

    do {
        printf("\n1: ADD\n2: VIEW\n3: DELETE\n4: EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &a);

        switch (a) {
            case 1:
                addcontact(&y);
                break;

            case 2:
                displaycontacts(y);
                break;

            case 3:
                printf("ENTER THE NUMBER OF CONTACT YOU WANT TO DELETE: ");
                scanf("%d", &b);
                deletecontact(y, b);
                break;

            default:
                if (a != 4) {
                    printf("Invalid choice. Please try again.\n");
                }
        }
    } while (a != 4);

    free(y);

    return 0;
}
