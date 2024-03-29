#include "LinkedList.h"
#include "trace.h"
#include <stdio.h>

int main(void) {
    traceInit();
    struct LinkedList_Data d1 = {0, 6};
    struct LinkedList_Data d2 = {0, 5};
    struct LinkedList_Data d3 = {0, 4};
    struct LinkedList_Data d4 = {0, 3};
    struct LinkedList_Data d5 = {0, 3};
    struct LinkedList_Data d6 = {0, 3};
    struct LinkedList_Data d7 = {0, 2};
    struct LinkedList_Data d8 = {0, 1};
    struct LinkedList *lst = LinkedList_createList(&d1);
    LinkedList_insertOrdered(lst, &d2);
    LinkedList_insertOrdered(lst, &d3);
    LinkedList_insertOrdered(lst, &d4);
    LinkedList_insertOrdered(lst, &d5);
    LinkedList_insertOrdered(lst, &d6);
    LinkedList_insertOrdered(lst, &d7);
    LinkedList_insertOrdered(lst, &d8);

    struct LinkedList_Data d9 = {1, 0};
    struct LinkedList_Data d10 = {2, 2};

    LinkedList_insertIndex(lst, 0, &d9);
    LinkedList_insertIndex(lst, 1, &d10);

    printf("Len = %d\n", LinkedList_getLength(lst));
    LinkedList_printLst(lst);

    LinkedList_destroyList(lst);
    traceSummarize();
    traceFree();
    return 0;
}

void LinkedList_destroyData(struct LinkedList_Data *target) { _free(target); }

void LinkedList_printData(struct LinkedList_Data *data) {
    printf("{c = %d p = %d}", data->c, data->p);
}

int LinkedList_dataEquals(struct LinkedList_Data *a,
                          struct LinkedList_Data *b) {
    if ((a->c == b->c) && (a->p == b->p)) {
        return 1;
    }
    return 0;
}

int LinkedList_dataCmp(struct LinkedList_Data *a, struct LinkedList_Data *b) {
    if (a->p < b->p) {
        return -1;
    } else if (a->p > b->p) {
        return 1;
    } else {
        return 0;
    }
}
