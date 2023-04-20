/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//  https://leetcode.com/problems/linked-list-cycle-ii/solutions/44781/concise-o-n-solution-by-using-c-with-detailed-alogrithm-description/?orderBy=most_votes

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head == NULL || head->next == NULL){
            return NULL;
        }

        // Entry is the point where the cycle starts.
        ListNode* slow = head, * fast = head, *entry = head;

        while(fast->next && fast->next->next){
            slow = slow -> next;
            fast = fast->next->next;

            // Cycle is detected
            if(slow == fast){
                while(slow != entry){
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};