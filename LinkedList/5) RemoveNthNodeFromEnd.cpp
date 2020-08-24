/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 int length(ListNode* A){
     int len=0;
     while(A!=NULL){
         A=A->next;
         len++;
     }
     return len;
 }
 
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    if(B==0){
        return A;
    }
    
    int len=length(A);
    if(B>=len){
        ListNode* nodeToBeDeleted=A;
        A=A->next;
        delete nodeToBeDeleted;
        return A;
    }
    int k=len-B;
    ListNode* temp=A;
    int i=0;
    while(i<k-1){
        temp=temp->next;
        i++;
    }
    ListNode* nodeToBeDeleted=temp->next;
        temp->next=temp->next->next;
        delete nodeToBeDeleted;
}
