#include"DictionaryProto.h"
int height(struct DictADT *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
}
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
}
struct DictADT* newNode(Data key)
{ 
    struct DictADT* node = (struct DictADT*)malloc(sizeof(struct DictADT)); 
    node->key   = key; 
    node->left   = NULL; 
    node->right  = NULL; 
    node->height = 1;  
    return(node); 
}
struct DictADT *rightRotate(struct DictADT *y)
{ 
    struct DictADT *x = y->left; 
    struct DictADT *T2 = x->right; 
    x->right = y; 
    y->left = T2; 
    y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 
  
    return x; 
}
struct DictADT *leftRotate(struct DictADT *x) 
{ 
    struct DictADT *y = x->right; 
    struct DictADT *T2 = y->left; 
  
    y->left = x; 
    x->right = T2; 
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
  
    return y; 
}
int getBalance(struct DictADT *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
}
struct DictADT* insert(struct DictADT* node, Data key)
{ 
    if (node == NULL) 
        return(newNode(key)); 
  
    if (strcmp(key.word,node->key.word)<0) 
        node->left  = insert(node->left, key); 
    else if (strcmp(key.word,node->key.word)>0) 
        node->right = insert(node->right, key); 
    else 
        return node; 
  
    node->height = 1 + max(height(node->left), 
                           height(node->right)); 
  
    int balance = getBalance(node); 
  
    if (balance > 1 && strcmp(key.word,node->left->key.word)<0)
        return rightRotate(node); 
  
    if (balance < -1 && strcmp(key.word,node->right->key.word)>0) 
        return leftRotate(node); 
  
    if (balance > 1 && strcmp(key.word,node->left->key.word)>0)
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    if (balance < -1 && strcmp(key.word,node->right->key.word)<0)
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
  
    return node; 
}
void search(struct DictADT* root, char key[100])
{ 
    
    if (root != NULL) 
    { 
        if(strcmp(root->key.word,key)==0)
         printf("%s\nDefinition:%s\n", root->key.word,root->key.def); 
         

        search(root->left,key); 
        search(root->right,key); 
    } 
    
}
void display(struct DictADT *root, int space) 
{ 
    int COUNT=10;
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    display(root->right, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%s\n", root->key.word); 
  
    // Process left child 
    display(root->left, space); 
}
void preOrder(struct DictADT *root) 
{ 
    if(root != NULL) 
    { 
        printf("%s\n", root->key.word); 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
}