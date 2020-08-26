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
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(A==NULL||A->next==NULL){
        return A;
    }
    int len=length(A);
    B=B%len;
    if(B==0){
        return A;
    }
    ListNode* temp=A;
    int k=0;
    while(k<len-B-1){
        temp=temp->next;
        k++;
    }
    ListNode* newHead=temp->next;
    temp->next=NULL;
    ListNode* temp1=newHead;
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    temp1->next=A;
    return newHead;
}
