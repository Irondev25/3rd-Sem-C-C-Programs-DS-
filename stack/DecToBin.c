#include<stdio.h>
#include<stdlib.h>


struct stack{
    int data;
    struct stack *link;
};


void push(struct stack **top_ref, int data){
    struct stack *new_node = (struct stack *)malloc(sizeof(struct stack));
    new_node->data = data;
    new_node->link = *top_ref;
    *top_ref = new_node;
}


int pop(struct stack **top_ref){
    struct stack *delNode = *top_ref;
    int temp = delNode->data;
    *top_ref = delNode->link;    
    free(delNode);
    return temp;
}


void displaystack(struct stack *top){
    struct stack *node = top;
    while(node!=NULL){
        printf("%d", node->data);
        node = node->link;
    }
    printf("\n");
}


void convertDecToBin(struct stack *top ,int decNum){
    printf("Bin of %d: ", decNum);
    while(decNum > 0){
        push(&top, decNum%2);
        decNum = decNum/2;
    }
    displaystack(top);
}


int main(){
    struct stack *top = NULL;
    int n;
    printf("Enter number for binary conversion: ");
    scanf("%d", &n);
    while(n != 0){
        convertDecToBin(top, n);
        printf("Enter number(0 to exit): ");
        scanf("%d", &n);
    }
    return 0;
}