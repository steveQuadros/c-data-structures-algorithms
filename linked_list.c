#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *node_create(int data, struct Node *next);
struct Node *node_insert_at(struct Node *head, struct Node *node, int position);
struct Node *node_delete_at(struct Node *head, int position);
struct Node *node_reverse_list(struct Node *head);
struct Node *node_merge_sorted(struct Node *headA, struct Node *headB);

void print_list(struct Node *head);
void test_insert_at();
void test_delete_at();
void test_reverse_list();
void test_merge_sorted();

int main(int argc, char *argv[])
{
    // test_insert_at();
    // test_delete_at();
    // test_reverse_list();
    test_merge_sorted();
    return 0;
}

void test_reverse_list() {
    printf("------ Test Reverse At\n");
    struct Node *h = node_create(392, NULL);
    struct Node *a = node_create(83745, NULL);
    struct Node *b = node_create(9187231, NULL);
    struct Node *c = node_create(129, NULL);

    h->next = a;
    a->next = b;
    b->next = c;
    c->next = NULL;

    // print initial list
    print_list(h);

    h = node_reverse_list(h);
    print_list(h);
}

void test_insert_at() {
    printf("------ Test Insert At\n");
    struct Node *h = node_create(392, NULL);
    struct Node *a = node_create(83745, NULL);
    struct Node *b = node_create(9187231, NULL);

    h->next = a;
    a->next = b;
    b->next = NULL;

    // print initial list
    print_list(h);

    // add item at pos 2
    struct Node *c = node_create(3, NULL);
    h = node_insert_at(h, c, 0);
    print_list(h);

    // add item at pos 2
    struct Node *d = node_create(765, NULL);
    h = node_insert_at(h, d, 3);
    print_list(h);

    free(h);
    free(a);
    free(b);
    printf("------\n");
}

void test_delete_at() {
    printf("------ Test Delete At \n");
    struct Node *h = node_create(392, NULL);
    struct Node *a = node_create(83745, NULL);
    struct Node *b = node_create(9187231, NULL);
    struct Node *c = node_create(129, NULL);

    h->next = a;
    a->next = b;
    b->next = c;
    c->next = NULL;

    print_list(h);

    h = node_delete_at(h, 1);
    print_list(h);

    h = node_delete_at(h, 2);
    print_list(h);

    h = node_delete_at(h, 0);
    print_list(h);

    printf("------\n");
}

void test_merge_sorted() {
    printf("------ Test Merge Sorted \n");

    printf("LL A: \n");
    struct Node *hA = node_create(1, NULL);
    struct Node *aA = node_create(3, NULL);
    struct Node *bA = node_create(6, NULL);
    struct Node *cA = node_create(9, NULL);
    hA->next = aA;
    aA->next = bA;
    bA->next = cA;
    cA->next = NULL;

    print_list(hA);

    printf("LL B: \n");
    struct Node *hB = node_create(2, NULL);
    struct Node *aB = node_create(4, NULL);
    struct Node *bB = node_create(5, NULL);
    struct Node *cB = node_create(7, NULL);

    hB->next = aB;
    aB->next = bB;
    bB->next = cB;
    cB->next = NULL;
    print_list(hB);

    printf("LL Merged and sorted: \n");
    hA = node_merge_sorted(hA, hB);
    print_list(hA);

    printf("------\n");
}

void print_list(struct Node *head) {
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    } ;
    printf("\n");
}

struct Node *node_create(int data, struct Node *next) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = data;
    n->next = next;
    return n;
}

struct Node *node_insert_at(struct Node *head, struct Node *node, int position) {
    int count = 0;
    struct Node *cur = head;

    if (position == 0) {
        node->next = head;
        head = node;
    }

    while(cur != NULL) {
        if (count == position - 1) {
            struct Node *tmp = cur->next;
            cur->next = node;
            node->next = tmp;
            break;
        }
        cur = cur->next;
        count++;
    }
    return head;
}

struct Node *node_delete_at(struct Node *head, int position) {
    int count = 0;
    struct Node *prev = NULL;
    struct Node *cur = head;

    if (position == 0) {
        cur = head->next;
        free(head);
        return cur;
    }

    while(cur != NULL) {
        if (count == position) {
            prev->next = cur->next;
            break;
        }
        prev = cur;
        cur = cur->next;
        count++;
    }

    free(cur);
    return head;
}

struct Node *node_reverse_list(struct Node *head) {
    struct Node *prev = NULL;
    struct Node *cur = head;
    struct Node *next = NULL;

    if (head->next == NULL) {
        return head;
    }

    while(cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

// NOT IMPLEMENTED
struct Node *node_merge_sorted(struct Node *headA, struct Node *headB) {
    if (headA == NULL)
        return headB;

    if (headB == NULL)
        return headA;

    return headA;
}