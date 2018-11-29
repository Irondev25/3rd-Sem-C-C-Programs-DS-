#include "BST.h"

NODE* _insert(BST_TREE* tree, NODE* root, NODE* newPtr){
    if(!root)
        return newPtr;

    if(tree->compare(newPtr->dataPtr, root->dataPtr)<0){
        root->left = _insert(tree, root->left, newPtr);
        return root;
    }
    else{
        root->right = _insert(tree, root->right, newPtr);
        return root;
    }
    return root;
}

NODE* _delete(BST_TREE* tree, NODE* root, void* dataPtr, bool *success){
    NODE* dltPtr;
    NODE* exchPtr;
    NODE* newRoot;
    void* holdPtr;

    if(!root){
        *success = false;
        return NULL;
    }
    if(tree->compare(dataPtr, root->dataPtr)<0) 
        root->left = _delete(tree, root->left, dataPtr, success);
    else if(tree->compare(dataPtr, root->dataPtr)>0)
        root->right = _delete(tree, root->right, dataPtr, success);
    else{
        dltPtr = root;
        if(!root->left){
            free(root->dataPtr);
            newRoot = root->right;
            free(dltPtr);
            *success = true;
            return newRoot;
        }
        else if(!root->right){
            newRoot = root->left;
            free(dltPtr);
            *success = true;
            return newRoot;
        }
        else{
            exchPtr = root->left;
            while(exchPtr->right)
                exchPtr = exchPtr->right;
            holdPtr = root->dataPtr;
            root->dataPtr = exchPtr->dataPtr;
            exchPtr->dataPtr = holdPtr;
            root->left = _delete(tree, root->left, exchPtr->dataPtr, success);
        }
        return root;
    }
}

void* _retrive(BST_TREE* tree, void* dataPtr, NODE* root){
    if(root){
        if(tree->compare(dataPtr, root->dataPtr)<0){
            return _retrive(tree, dataPtr, root->left);
        }
        else if(tree->compare(dataPtr, root->dataPtr)>0)
            return _retrive(tree, dataPtr, root->right);
        else
            return root->dataPtr;
    }
    return NULL;
}

void _traverse(NODE* root, void (*process)(void* dataPtr)){
    if(root){
        _traverse(root->left, process);
        process(root->dataPtr);
        _traverse(root->right, process);
    }
    return;
}

void _destroy(NODE* root){
    if(root){
        _destroy(root->left);
        free(root->dataPtr);
        _destroy(root->right);
        free(root);
    }
    return;
}