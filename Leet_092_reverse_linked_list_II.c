/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    int ist = 0;
    struct ListNode* pPreNode = NULL, *pCurNode = NULL, *pNxtNode = NULL;
    struct ListNode* pPreStNode = NULL, *pStNode = NULL;
    
    if(head == NULL || m >= n)
        return head;
    
    if(head->next == NULL)
        return head;
    
    pPreNode = NULL;
    pCurNode = head;
    pNxtNode = head->next;

    while(ist < n && pCurNode != NULL){
        
        pNxtNode = pCurNode->next;
        
        if(ist == m-2){
            pPreStNode = pCurNode;
        }
        if(ist == m-1){
            pStNode = pCurNode;            
        }
        if(ist > m-1){
            pCurNode->next = pPreNode;
        }
        if(ist == n-1){
            if(pPreStNode != NULL)
                pPreStNode->next = pCurNode;
            else
                head = pCurNode;
            pStNode->next = pNxtNode;
            break;
        }       
        pPreNode = pCurNode;
        pCurNode = pNxtNode;
        
        ist++;
    }
    
    return head;
}