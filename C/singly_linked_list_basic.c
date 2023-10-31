/*program in C to implement linked list to insert and delete an element from the list.*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};

typedef struct node* NODE;

NODE getnode() {
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL) {
        printf("Out of memory\n");
        exit(0);
    }
    return x;
}

void freenode(NODE x) {
    free(x);
}

NODE insert_front(int item, NODE first) {
    NODE temp;
    temp = getnode();
    temp->info = item;
    temp->link = first;
    return temp;
}

NODE delete_front(NODE first) {
    NODE temp;
    if (first == NULL) {
        printf("List is empty\n");
        return first;
    }
    temp = first;
    printf("The deleted item is %d\n", first->info);
    first = first->link;
    freenode(temp);
    return first;
}

NODE insert_rear(int item, NODE first) {
    NODE temp, cur;
    temp = getnode();
    temp->info = item;
    temp->link = NULL;
    if (first == NULL)
        return temp;
    cur = first;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}

NODE delete_rear(NODE first) {
    NODE cur = first, prev = NULL;
    if (cur == NULL) {
        printf("List is empty\n");
        return first;
    }
    while (cur->link != NULL) {
        prev = cur;
        cur = cur->link;
    }
    printf("The deleted item is %d\n", cur->info);
    freenode(cur);
    if (prev == NULL)
        return NULL;
    prev->link = NULL;
    return first;
}

void display(NODE first) {
    NODE temp = first;
    if (temp == NULL) {
        printf("NO NODES IN THE LIST!!\n");
        return;
    } else {
        while (temp != NULL) {
            printf("%d ", temp->info);
            temp = temp->link;
        }
    }
}

int main() {
    NODE first = NULL;
    int choice, item;

    for (;;) {
        printf("\n1. INSERT FRONT\n2. INSERT REAR\n3. DELETE FRONT\n4. DELETE REAR\n5. DISPLAY\n6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item: ");
                scanf("%d", &item);
                first = insert_front(item, first);
                break;
            case 2:
                printf("Enter the item: ");
                scanf("%d", &item);
                first = insert_rear(item, first);
                break;
            case 3:
                first = delete_front(first);
                break;
            case 4:
                first = delete_rear(first);
                break;
            case 5:
                display(first);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
