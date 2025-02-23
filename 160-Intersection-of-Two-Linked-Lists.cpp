/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        ListNode* curr = h1;
        ListNode* temp = h2;
        int s1  = 0 , s2 = 0 ;
        while(curr != nullptr){
            s1++;
            curr = curr->next;
        }
        while(temp != nullptr){
            s2++;
            temp = temp->next;
        }
        curr = h1;
        temp = h2;
        int count = 0;
        if(s1 > s2){
            while(count != s1-s2){
                curr = curr->next;
                count++;
            }
        }else{
            while(count != s2-s1){
                temp = temp->next;
                count++;
            }
        }
        while(curr && temp){
                if(curr == temp){
                    return temp;
                }
                curr = curr->next;
                temp = temp->next;
            }
        return nullptr;
    }
};
