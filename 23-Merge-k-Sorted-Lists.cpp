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
    ListNode* mergeKLists(vector<ListNode*>& list) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        vector<int> v;
        for(auto head : list){
            ListNode* curr = head;
            while(curr != nullptr){
                v.push_back(curr->val);
                curr = curr->next;
            }
        }
        sort(v.begin(), v.end());
        for(int i : v){
            temp->next = new ListNode(i);
            temp = temp->next;
        }
        return dummy->next;
    }
};
