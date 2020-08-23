/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* getMidNode(ListNode* head){
    ListNode* fast=head;
    ListNode* slow=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

ListNode* reverse(ListNode* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    ListNode* smallAns=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    head=smallAns;
    return head;
}
int Solution::lPalin(ListNode* A) {
    if(A==NULL||A->next==NULL){
        return 1;
    }
    ListNode* midNode=getMidNode(A);
    ListNode* head1=reverse(midNode->next);
    midNode->next=NULL;
    while(A!=NULL&&head1!=NULL){
        if(A->val!=head1->val){
            return 0;
        }
        A=A->next;
        head1=head1->next;
    }
    return 1;
}
