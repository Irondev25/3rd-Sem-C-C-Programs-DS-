#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//node for BST
typedef struct NODE{
    char name[50];
    struct NODE* left;
    struct NODE* right;
}node;


int compare(char name1[], char name2[]){
    return strcmp(name1, name2);
}

//create new node
node* createNode(char name[]){
    node* new = (node*)malloc(sizeof(node));
    strcpy(new->name, name);
    new->left = NULL;
    new->right = NULL;
    return new;
}

//insert node into BST
node* insert(node* root, char name[]){
    if(root==NULL)
        return createNode(name);
    if(compare(name, root->name)>0)
        root->right = insert(root->right, name);
    else    
        root->left = insert(root->left, name);
    return root;
}


//inorder traversal
void inorder(node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%s\n", root->name);
    inorder(root->right);
}


//read names from file and insert into BST
node* readFromFile(node* root){
    char c[50];
    FILE *fptr = fopen("d1.txt", "r");
    while (!feof(fptr))
    {
        fscanf(fptr, "%[^\n]\n", c);
        root = insert(root, c);
    }
    fclose(fptr);
    fptr = fopen("d2.txt", "r");
    while (!feof(fptr))
    {
        fscanf(fptr, "%[^\n]\n", c);
        root = insert(root, c);
    }
    fclose(fptr);
    fptr = fopen("d3.txt", "r");
    while (!feof(fptr))
    {
        fscanf(fptr, "%[^\n]\n", c);
        root = insert(root, c);
    }
    fclose(fptr);
    return root;
}


//write inorder traversal to file
void writeToFile(node* root){
    FILE *fg = NULL;
    if(root == NULL)
        return;
    writeToFile(root->left);
    fg = fopen("sorted_name.txt", "a");
    fprintf(fg, "%s\n", root->name);
    fclose(fg);
    writeToFile(root->right);
}


//main function
int main(){
    node* root = NULL;
    root = readFromFile(root);
    inorder(root);
    writeToFile(root);
    return 0;
}
