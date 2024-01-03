#include <stdio.h>
#include <stdlib.h>
typedef struct tree {
    int item; /* data item */
    struct tree *parent; /* pointer to parent */
    struct tree *left; /* pointer to left child */
    struct tree *right; /* pointer to right child */
} tree;

typedef struct tree *t;

void traverse_right(t l, int h){
    t random_t = malloc(sizeof(tree));
    if (h > 0){
        l->right = random_t;
        l->item = 0;
        printf("h");
        h--; 
        traverse_right(l->right, h);
    }
    l->right = NULL;
}
void traverse_tree(t l, int h){
    t random_t = malloc(sizeof(tree));
    if (h > 0) {
        l->left = random_t;
        l->item = 0;
        printf("%d", l->item);
        traverse_right(l, h);
        h--;
        traverse_tree(l->left, h);
    }
    l->left = NULL; 
}


void main(){
    t t_tail = malloc(sizeof(tree));
    traverse_tree(t_tail, 3);
}