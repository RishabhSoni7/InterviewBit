/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* fHead=NULL;
    ListNode* fTail=NULL;
    while(A!=NULL&&B!=NULL){
        if(A->val<=B->val){
            if(fHead==NULL&&fTail==NULL){
                fHead=A;
                fTail=A;
            }else{
                fTail->next=A;
                fTail=fTail->next;
            }
            A=A->next;
        }else{
             if(fHead==NULL&&fTail==NULL){
                fHead=B;
                fTail=B;
            }else{
                fTail->next=B;
                fTail=fTail->next;
            }
            B=B->next;
        }
    }
    while(A!=NULL){
        fTail->next=A;
        fTail=fTail->next;
        A=A->next;       
    }
    while(B!=NULL){
        fTail->next=B;
        fTail=fTail->next;
        B=B->next;       
    }
    return fHead;
}