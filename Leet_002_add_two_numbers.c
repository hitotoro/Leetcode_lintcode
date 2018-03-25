/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* root = NULL, *pTmp = NULL;
    struct ListNode* pl1 = NULL, *pl2 = NULL;
    int isOver = 0;
    int lval = 0, rval = 0, tval = 0;
        
    if(l1 == NULL && l2 == NULL)
        return root;
    
    pTmp = (struct ListNode*)malloc(sizeof(struct ListNode));
    pTmp->next = NULL;
    root = pTmp;
    
    pl1 = l1;
    pl2 = l2;
    
    while(pl1 != NULL || pl2 != NULL){
        //printf("(0x%8x, 0x%8x, 0x%8x)\n", pTmp, pl1, pl2);
        lval = (pl1 != NULL) ? pl1->val : 0;
        rval = (pl2 != NULL) ? pl2->val : 0;

        pl1 = (pl1 == NULL) ? NULL : pl1->next;
        pl2 = (pl2 == NULL) ? NULL : pl2->next;
        
        tval = lval + rval + isOver;
        isOver = (tval > 9) ? 1:0;
        tval = isOver ? (tval-10):(tval);
        
        pTmp->val = tval;
        if(isOver || pl1 != NULL || pl2 != NULL){
            pTmp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            pTmp->next->val = isOver;
            pTmp->next->next = NULL;
            pTmp = pTmp->next;
        }
        else{
            pTmp->next = NULL;
        }
        
        
    
        
    }
    //printf("(0x%8x 0x%8x)\n", pTmp, root);
    
    return root;    
}