//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
    Node* reverseHeads(Node* head){
        Node* dummy = NULL;
        Node* curr  = head;
        while(curr!=NULL){
            Node* next = curr->next;
            curr->next = dummy;
            dummy = curr;
            curr= next;
        }
        return dummy;
    }
    
    Node *reverse(Node *head, int k)
    {
        // code here
        Node* reversed = reverseHeads(head);
        int count = 0;
        Node* temp = reversed;
        while(temp->next!=NULL){
            temp = temp->next;
            count++;
        }
        temp->next = reversed;
        count = count - k;
        Node* temp2 = reversed;
        while(count--){
            temp2 = temp2->next;
        }
        Node* ans = temp2->next;
        temp2->next = NULL;
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends