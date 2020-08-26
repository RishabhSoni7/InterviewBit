/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
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

//Recursion
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(A==NULL||A->next==NULL){
        return A;
    }
    
    ListNode* temp=A;
    int k=0;
    
    while(temp!=NULL&&k<B-1){
        temp=temp->next;
        k++;
    }
    ListNode* newHead=NULL;
    if(temp!=NULL){
    newHead=temp->next;
    temp->next=NULL;
    }
    ListNode* smallAns=reverse(A);
    A->next=reverseList(newHead,B);
    return smallAns;
}
