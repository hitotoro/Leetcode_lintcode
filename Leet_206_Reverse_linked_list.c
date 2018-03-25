/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#if 1 // iterative
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* pPreNode = NULL;
    struct ListNode* pCurNode = NULL;
    struct ListNode* pNxtNode = NULL;
    
    if(head == NULL)
        return head;
    
    if(head->next == NULL)
        return head;
    
    pCurNode = head;
    pNxtNode = head->next;
    
    while(pCurNode!=NULL){
        pCurNode->next = pPreNode;
        
        pPreNode = pCurNode;
        pCurNode = pNxtNode;
        pNxtNode = (pNxtNode!=NULL) ? pNxtNode->next : NULL; 
    }
    
    head = pPreNode;
    
    return head;
}
#else // recursive
// think by yourself next time:)

#endif