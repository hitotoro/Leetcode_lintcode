/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#if 1 // recursive
bool isMirror(struct TreeNode* N1, struct TreeNode* N2){
    if(N1==NULL && N2==NULL)
        return true;
    else if(N1==NULL || N2==NULL)
        return false;
    else if(N1->val == N2->val) 
        return (isMirror(N1->left, N2->right) && isMirror(N1->right, N2->left));
    else
        return false;
        
}

bool isSymmetric(struct TreeNode* root) {
    
    if(root == NULL)
        return true;
    
    return isMirror(root->left, root->right);
    
}
#else // iteraltive

struct myQueue{
    struct TreeNode *node;
    struct myQueue* left;
    struct myQueue* right;
};

bool myQueue_push(struct TreeNode* pNodeIn, struct myQueue** pHeader, struct myQueue** pTailer){
    // left to header
    // right to tailer
    struct myQueue* pTmpNode = NULL;
    struct myQueue* pNodeIn_T = NULL;
    
    if((*pTailer != NULL) && ((*pTailer)->right != *pHeader))
        return false;
    if((*pTailer == NULL && *pHeader!= NULL) || (*pTailer != NULL && *pHeader == NULL))
        return false;

    /*
    if(pNodeIn != NULL)
        printf("val = %d\n", pNodeIn->val);
    else
        printf("val = null\n");
    */
        
    //creat one
    pNodeIn_T = (struct myQueue*)malloc(sizeof(struct myQueue));
    pNodeIn_T->node = pNodeIn;
    
    if(*pHeader == NULL && *pTailer == NULL){
        *pHeader = pNodeIn_T;
        (*pHeader)->right = pNodeIn_T;
        (*pHeader)->left = pNodeIn_T;
        *pTailer = *pHeader;
        return true;
    }
    
    pTmpNode = (*pTailer)->right;
    (*pTailer)->right = pNodeIn_T;
    pNodeIn_T->left = *pTailer;
    pNodeIn_T->right = pTmpNode;
    
    pTmpNode->left = pNodeIn_T;
    
    *pTailer = pNodeIn_T;

    //printf("push, pH = 0x%x, pT= 0x%x\n", *pHeader, *pTailer);
    
    return true;
}

bool myQueue_pop(struct myQueue** pHeader, struct myQueue** pTailer){
    struct myQueue* pDel = NULL;
    
    pDel = *pHeader;
    
    if(*pHeader == NULL || *pHeader == NULL)
        return false;
    
    if(*pHeader == *pTailer){
        *pHeader = NULL;
        *pTailer = NULL;
    }
    else{
        *pHeader = pDel->right;
        (*pHeader)->left = pDel->left;
        (*pTailer)->right = *pHeader;
    }
    if(pDel){
        free(pDel);
        pDel = NULL;
    }
    
    //printf("pop, pH = 0x%x, pT= 0x%x\n", *pHeader, *pTailer);
    
    return true;
}

bool isSymmetric(struct TreeNode* root) {
    bool isSym = true;
    struct myQueue* pHeader = NULL;
    struct myQueue* pTailer = NULL;
    struct myQueue* pCheckNode1 = NULL;
    struct myQueue* pCheckNode2 = NULL;
    
    int cnt = 0, cnt2 = 0, cntMax = 0xfffffff;
        
    myQueue_push(root, &pHeader, &pTailer);
    //printf("pH = 0x%x, pT= 0x%x\n", pHeader, pTailer);
    myQueue_push(root, &pHeader, &pTailer);
    //printf("pH = 0x%x, pT= 0x%x\n", pHeader, pTailer);
    
    while(pHeader != NULL && pTailer != NULL){
        pCheckNode1 = pHeader;
        pCheckNode2 = pHeader->right;
        //printf("p1 = 0x%x, p2= 0x%x\n", pCheckNode1, pCheckNode2);
        
        if(pCheckNode1->node == NULL && pCheckNode2->node != NULL)
            isSym = false;
        if(pCheckNode1->node != NULL && pCheckNode2->node == NULL)
            isSym = false;
        if(pCheckNode1->node != NULL && pCheckNode2->node != NULL){
            if(pCheckNode1->node->val != pCheckNode2->node->val)
                isSym = false;
        }
          
        //printf("p1->node = 0x%x, p2->node= 0x%x\n", pCheckNode1->node, pCheckNode2->node);
        
        if(pCheckNode1->node != NULL){
            myQueue_push(pCheckNode1->node->left, &pHeader, &pTailer);
        }
        if(pCheckNode2->node != NULL){
            myQueue_push(pCheckNode2->node->right, &pHeader, &pTailer);
        }
        if(pCheckNode1->node != NULL){
            myQueue_push(pCheckNode1->node->right, &pHeader, &pTailer);
        }
        if(pCheckNode2->node != NULL){
            myQueue_push(pCheckNode2->node->left, &pHeader, &pTailer);
        }
        
        myQueue_pop(&pHeader, &pTailer);
        myQueue_pop(&pHeader, &pTailer);
        
        if(!isSym){
            printf("isSym = 0\n");
            break;
        }
        
        cnt++;
        if(cnt > cntMax){
            printf("[1] while loop is too many times, please check.\n");
            break;
        }
    }
    //printf("pH = 0x%x, pT= 0x%x\n", pHeader, pTailer);  
    while(!(pHeader==NULL && pTailer==NULL)){
        //printf("queue is not empty, check!\n");
        
        myQueue_pop(&pHeader, &pTailer);
        
        cnt2++;
        if(cnt2 > 20){
            printf("[2] while loop is too many times, please check.\n");
            break;
        }
    }
    
    return isSym;
}
#endif