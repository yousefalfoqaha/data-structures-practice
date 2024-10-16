#include <stdio.h>

struct node {
    int data;
    node* next;
};

main() {
    struct node n2 = {2};
    struct node n1 = {1, &n2};

    node nodes[] = { n1, n2 };

    int length = sizeof(nodes) / sizeof(nodes[0]);
    int i;
    for (i = 0; i < length; i++) {
        printf("%d ", nodes[i].data);
    }

        printf("%d", *n1.next);

    return 0;
}