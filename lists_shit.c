#include <stdio.h>
#include <stdlib.h>
#define N 10
// Remember that when creating a new node, you should
// declare it first o set it to NULL and then allocating
// it in the memory
typedef struct LinkedList{
    int data;
    struct LinkedList *next;
}LinkedList;

typedef struct LinkedList *node;

node CreateNode(){
    node temp = malloc(sizeof(LinkedList));
    temp -> next = NULL;
    return temp;
}
 
void InsertNodes(node head, int n_of_nodes){
    if (head -> next == NULL && n_of_nodes > 0){
        node tmp = CreateNode();
        tmp -> data = n_of_nodes;
        head -> next = tmp;
        n_of_nodes--;
        return InsertNodes(tmp, n_of_nodes);
    }
}

void PrintNodes(node tmp){
    while (tmp  != NULL){
        printf("%d ", tmp -> data);
        return PrintNodes(tmp -> next);
    }
    printf("\n"); 
}

node SearchList(node l, int item){
    if ((l == NULL) || (l->next == NULL)) {
        printf("Error: predecessor sought on null list.\n");
        return (NULL);
    }
    if (l->data == item){
        return l;
    } 
    else{
        return SearchList(l->next, item);
    }
}

node predecessor_list(node l, int x){
    if ((l == NULL) || (l->next == NULL)) {
        printf("Error: predecessor sought on null list.\n");
        return(NULL);
    }
    if ((l->next)->data == x) return(l);
    else return predecessor_list(l->next, x);
}

void delete_list(node l, int x){
    node p, pred; 
    p = SearchList(l, x);
    if (p != NULL) {
        pred = predecessor_list(l, x);
        if (pred == NULL) l = p->next;
        else pred->next = p->next;
        free(p); /* free memory used by node */
    }
}

int main(){
    node l = CreateNode();
    InsertNodes(l, N);
    PrintNodes(l->next);
    delete_list(l, 5);
    PrintNodes(l->next);
}

