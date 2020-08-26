/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if(A==NULL||A->next==NULL){
        return A;
    }
    ListNode* temp=A->next->next;
    A->next->next=A;
    A=A->next;
    A->next->next=swapPairs(temp);
    return A;
}
