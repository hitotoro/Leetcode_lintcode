/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* pPreRMNode = NULL;
    struct ListNode* pSrchNode = NULL;
    int ihead = 0, isrch = 0;
    
    //printf("head->val=%d\n", head->val);
    
    pSrchNode = head;
    pPreRMNode = head;
    ihead = 0;
    while(pSrchNode!=NULL){
        if(isrch-ihead > n){
            ihead++;
            pPreRMNode = pPreRMNode->next;
        }
        
        isrch++;
        pSrchNode = pSrchNode->next;
    }
    //printf("(%d,%d)\n", ihead, isrch);
    
    if((isrch-1)-ihead == n-1){// head is the nth node from the end
        head = head->next;
    }
    else{
        pPreRMNode->next = pPreRMNode->next->next;
    }
    
    return head;
}