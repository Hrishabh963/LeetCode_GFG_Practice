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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)return head;
        if(!head->next)return head;
        ListNode *oddHead = head,*even = head->next, *evenHead = head->next;
        while(even && even->next){
            oddHead->next = oddHead->next->next;
            oddHead = oddHead->next;
            even->next = even->next->next;
            even = even->next;
        }
        oddHead->next = evenHead;
        return head;
    }
};