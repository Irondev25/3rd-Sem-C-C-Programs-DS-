#include "BST.h"


BST_TREE* BST_Create(int (*compare)(void* argu1, void *argu2)){
    BST_TREE* tree;
    tree = (BST_TREE*)malloc(sizeof(BST_TREE));
    if(tree){
        tree->root = NULL;
        tree->count = 0;
        tree->compare = compare;
    }
    return tree;
}


bool BST_Insert(BST_TREE* tree, void* dataPtr){
    NODE* newPtr;

    newPtr = (NODE*)malloc(sizeof(NODE));
    if(!newPtr)
        return false;

    newPtr->right = NULL;
    newPtr->left = NULL;
    newPtr->dataPtr = dataPtr;

    if(tree->count == 0)
        tree->root = newPtr;
    else
        _insert(tree, tree->root, newPtr);

    (tree->count)++;
    return true;
}

bool BST_Delete(BST_TREE* tree, void* dltKey){
    bool success;
    NODE* newRoot;
    newRoot = _delete(tree, tree->root, dltKey, &success);
    if(success){
        tree->root = newRoot;
        (tree->count)--;
        if(tree->count = 0);
            tree->root = NULL;
    }
    return success;
}

void* BST_Retrive(BST_TREE* tree, void* keyPtr){
    if(tree->root)
        return _retrive(tree, keyPtr, tree->root);
    else
        return NULL;
}

void BST_Traverse(BST_TREE* tree, void (*process)(void *dataPtr)){
    _traverse(tree->root, process);
    return;
}

bool BST_Empty(BST_TREE* tree){
    return (tree->count == 0);
}

bool BST_Full(BST_TREE* tree){
    NODE* newPtr;
    newPtr = (NODE*)malloc(sizeof(*tree->root));
    if(newPtr){
        free(newPtr);
        return false;
    }
    else
        return true;
}

int BST_Count(BST_TREE* tree){
    return (tree->count);
}

BST_Destroy(BST_TREE* tree){
    if(tree)
        _destroy(tree->root);
    free(tree);
    return NULL;
}