/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* ret = NULL;
    struct ListNode* tmp = NULL;
    //int i =0;
    if(l1 == NULL)
        return l2;
    else if(l2 == NULL)
        return l1;
    
    ret = (l1->val <= l2->val) ? l1 : l2;
    if(l1->val <= l2->val)
        l1 = l1->next;
    else
        l2 = l2->next;
    
    tmp = ret;
    
    while(l1!=NULL || l2!=NULL){
        
        if((l1!=NULL && l2!=NULL && l1->val <= l2->val) || (l2 == NULL)){
            tmp->next = l1;
            l1 = l1->next;
            //printf("%d, l1=%x,l2=%x, ret=%x\n",i,l1,l2,ret);
        }
        else if((l1!=NULL && l2!=NULL && l1->val > l2->val) || (l1 == NULL)){
            tmp->next = l2; 
            l2 = l2->next;
            //printf("%d, l1=%x,l2=%x, ret=%x\n",i,l1,l2,ret);
        }
        //i++;
        tmp = tmp->next;
    }
    
    tmp->next = NULL;
                
    return ret;
    
}