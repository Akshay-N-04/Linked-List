/*program in C to implement adoublylinked list where each node consists of integers. The program should support thefollowing operations:
v. Create a doubly linked list by adding each node at the front.
vi. Insert a new node to the left of the node whose key value is read as aninput.
vii. Delete the node of a given data if it is found, otherwise display appropriatemessage
viii. Display the contents of the list.*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* llink;
    struct node* rlink;
};

struct node* first = NULL;
struct node* cur;
struct node* prev;
struct node* next;

void insertfront() {
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->llink = temp->rlink = NULL;
    printf("Enter the node to be inserted: ");
    scanf("%d", &temp->info);

    if (first == NULL) {
        first = temp;
        return;
    }

    temp->rlink = first;
    first->llink = temp;
    first = temp;
}

void insertleft() {
    int key;
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->llink = temp->rlink = NULL;

    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter the key before which the node is to be inserted: ");
    scanf("%d", &key);
    printf("Enter the node to be inserted: ");
    scanf("%d", &temp->info);

    prev = NULL;
    cur = first;

    while (cur != NULL) {
        if (cur->info == key && cur == first) {
            temp->rlink = cur;
            cur->llink = temp;
            first = temp;
            return;
        }

        if (cur->info == key) {
            temp->rlink = cur;
            cur->llink = temp;
            temp->llink = prev;
            prev->rlink = temp;
            return;
        }

        prev = cur;
        cur = cur->rlink;
    }

    printf("Key not found\n");
}

void Delete1() {
    int key;
    printf("Enter the node to be deleted: ");
    scanf("%d", &key);

    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    if (first->rlink == NULL) {
        if (key == first->info) {
            printf("%d node is deleted\n", key);
            free(first);
            first = NULL;
            return;
        } else {
            printf("Key not found\n");
            return;
        }
    }

    cur = first;

    while (cur != NULL) {
        if (cur->info == key) {
            if (cur == first) {
                first = first->rlink;
                printf("%d node is deleted\n", key);
                free(cur);
                return;
            }

            if (cur->rlink == NULL) {
                prev = cur->llink;
                prev->rlink = NULL;
                printf("%d node is deleted\n", key);
                free(cur);
                return;
            }

            prev = cur->llink;
            next = cur->rlink;
            prev->rlink = next;
            next->llink = prev;
            printf("%d node is deleted\n", key);
            free(cur);
            return;
        }

        cur = cur->rlink;
    }

    printf("Key not found\n");
}

void display() {
    cur = NULL;

    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List is:\n");
    cur = first;

    while (cur != NULL) {
        printf("%d\n", cur->info);
        cur = cur->rlink;
    }
}

int main() {
    int ch;

    printf("1. Insert at front\n2. Insert before a node\n3. Delete a node\n4. Display\n");

    for (;;) {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insertfront();
                break;
            case 2:
                insertleft();
                break;
            case 3:
                Delete1();
                break;
            case 4:
                display();
                break;
            default:
                exit(0);
        }
    }

    return 0;
}
