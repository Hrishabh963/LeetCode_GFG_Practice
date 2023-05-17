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
    ListNode* reverse(ListNode* head){
        if(!head)return head;
        ListNode* newHead = NULL , *curr = head, *next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = newHead;
            newHead = curr;
            curr = next;
        }
        return newHead;
    }
    int pairSum(ListNode* head) {
        if(!head)return 0;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;
        ListNode* temp = head;
        int maxi = 0;
        while(slow!=NULL){
            maxi = max(maxi,slow->val + temp->val);
            slow = slow->next;
            temp = temp->next;
        }
        return maxi;
    }
};