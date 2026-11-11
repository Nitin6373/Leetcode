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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0)
            return NULL;

        ListNode* Ans = NULL;
        ListNode* Head = NULL;

        struct cmp {
            bool operator()(ListNode*& a, ListNode*& b) {
                return a->val > b->val;
            }
        };
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (int i = 0; i < n; i++) {
            if (lists[i] != NULL)
                pq.push(lists[i]);
        }

        while (!pq.empty()) {
            auto el = pq.top();
            pq.pop();

            if(Head == NULL){
                Head = new ListNode(el->val);
                Ans = Head;
            }
            else{
                ListNode* T = new ListNode(el->val);
                T->next = NULL;
                Ans->next = T;
                Ans = Ans->next;
            }
            if(el->next != NULL)
                pq.push(el->next);
        }

        return Head;
    }
};