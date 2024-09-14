#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct LinkedList {
    struct Node *head;
};

void initialize_list(struct LinkedList *list) {
    list->head = NULL;
}

void destroy_list(struct LinkedList *list) {
    struct Node *current = list->head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
}

void insert_at_beginning(struct LinkedList *list, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}

void insert_at_end(struct LinkedList *list, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        struct Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

int length(struct LinkedList *list) {
    int count = 0;
    struct Node *current = list->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void insert_at_position(struct LinkedList *list, int data, int position) {
    if (position < 0 || position > length(list)) {
        printf("Invalid position\n");
        return;
    }
    if (position == 0) {
        insert_at_beginning(list, data);
    } else {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        struct Node *current = list->head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void delete_at_beginning(struct LinkedList *list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
}

void delete_at_end(struct LinkedList *list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
    } else {
        struct Node *current = list->head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
}

void delete_at_position(struct LinkedList *list, int position) {
    if (position < 0 || position >= length(list)) {
        printf("Invalid position\n");
        return;
    }
    if (position == 0) {
        delete_at_beginning(list);
    } else {
        struct Node *current = list->head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        struct Node *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

void print_list(struct LinkedList *list) {
    struct Node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to search for a node in the linked list
struct Node *search_node(struct LinkedList *list, int data) {
    struct Node *current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to reverse the linked list
void reverse_list(struct LinkedList *list) {
    struct Node *prev = NULL, *current = list->head, *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
}

// Function to sort the linked list using bubble sort
void bubble_sort(struct LinkedList *list) {
    if (list->head == NULL || list->head->next == NULL) {
        return;
    }

    int swapped;
    do {
        swapped = 0;
        struct Node *current = list->head;
        while (current->next != NULL) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}

int main() {
    struct LinkedList list;

    initialize_list(&list);

    insert_at_beginning(&list, 10);
    insert_at_beginning(&list, 20);
    insert_at_beginning(&list, 30);

    insert_at_end(&list, 40);
    insert_at_end(&list, 50);

    insert_at_position(&list, 60, 3);

    print_list(&list);

    delete_at_beginning(&list);
    delete_at_end(&list);
    delete_at_position(&list, 1);

    print_list(&list);

    // Search for a node
    struct Node *found_node = search_node(&list, 40);
    if (found_node != NULL) {
        printf("Node found with data: %d\n", found_node->data);
    } else {
        printf("Node not found.\n");
    }

    // Reverse the linked list
    reverse_list(&list);
    print_list(&list);

    // Sort the linked list
    bubble_sort(&list);
    print_list(&list);

    destroy_list(&list);

    return 0;
}