#include <stdio.h>
#include <stdlib.h>

// Double Circular linked List
typedef struct node{
    int value;
    struct node *next;
    struct node *prev;
}Node;

void insert(const int val, const int copies, Node *pos, int *count){
    Node *temp = pos;
    Node *posNext = pos->next;
    (*count) += copies;

    for(int i = 0; i < copies; i++){
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->value = val;
        newNode->prev = temp;

        temp->next = newNode;
        temp = newNode;
    }

    temp->next = posNext;
    posNext->prev = temp;
}

void erase(const int val, Node *pos, int *count){
    Node *nextTemp = pos->next;
    (*count) -= val;

    for(int i = 0; i < val; i++){
        Node *temp = nextTemp;
        nextTemp = nextTemp->next;
        free(temp);
    }

    pos->next = nextTemp;
    nextTemp->prev = pos;
}

void move(const int val, Node **pos, const int count){
    // Mod the move steps
    if(count <= 0) return;

    int modedVal = val % count;
    if(modedVal >= 0){
        for(int i = 0; i < modedVal; i++){
            (*pos) = (*pos)->next;
        }
    }else{
        for(int i = 0; i > modedVal; i--){
            (*pos) = (*pos)->prev;
        }
    }

}

void show(Node *pos, int *count){
    Node *temp = pos;

    printf("%d", pos->value);
    // while(temp->next != pos){
    for(int i = 0; i < (*count) - 1; i++){
        printf(" %d", temp->next->value);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int x = 0, n = 0, count = 1;
    Node *init = (Node *)malloc(sizeof(Node));
    Node *pos = init;

    scanf("%d\n%d\n", &x, &n);
    init->value = x;
    init->next = init;
    init->prev = init;

    for(int i = 0; i < n; i++){
        char op[10] = {0};
        int val = 0, copies = 0;

        scanf("%s", op);
        // printf("%c\n", op[0]);

        switch (op[0]){
            case 'i': // Insert
                scanf("%d %d\n", &val, &copies);
                insert(val, copies, pos, &count);
                break;
            case 'e': // Erase
                scanf("%d\n", &val);
                erase(val, pos, &count);
                break;
            case 'm': // Move
                scanf("%d\n", &val);
                move(val, &pos, count);
                break;
            case 's': // Show
                show(pos, &count);
                break;
        }
    }

    return 0;
}
