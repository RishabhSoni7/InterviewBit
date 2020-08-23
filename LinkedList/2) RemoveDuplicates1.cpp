/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    ListNode* prev=A;
    ListNode* curr=A->next;
    while(curr!=NULL){
        if(prev->val!=curr->val){
            prev=prev->next;
            curr=curr->next;
        }else{
            ListNode* temp1=curr;
            curr=curr->next;
            prev->next=curr;
            delete temp1;
        }
    }
    return A;
}
