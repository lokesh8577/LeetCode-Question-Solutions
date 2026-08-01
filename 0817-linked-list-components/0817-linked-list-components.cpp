class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it : nums){
            mp[it]++;
        }

        ListNode* temp = head;
        int count = 0;
        bool already = false;
        while(temp != NULL){
            if(mp.find(temp->val) != mp.end()){
                if(already == false){
                    count++;
                    already = true;
                }

                temp = temp->next;
            }
            else{
                temp = temp->next;
                already = false;
            }
        }
        return count;
    }
};