/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head)return head;
        ListNode* temp = head;
        ListNode* first;
        int count = 0;
        while(temp!=NULL){
            count++;
            if(count == k){
                first = temp;
            }
            temp = temp->next;
        }
        temp = head;
        count = count - k;
        while(temp!=NULL && count--){
            temp = temp->next;
        }
        int x = first->val;
        first->val = temp->val;
        temp->val = x;
        return head;
    }
};