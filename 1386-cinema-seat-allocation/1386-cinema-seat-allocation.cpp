class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int ,set<int>>rs;
      
         for(auto p:reservedSeats){
             rs[p[0]].insert(p[1]);
           }
        
        int ans= 2*(n-rs.size());
        
        for(auto [r,s]:rs){
            bool a =false,b=false;

            if((!s.count(2))&&(!s.count(3))&&(!s.count(4))&&(!s.count(5))){
                ans++;
                a=true;
            }

            if((!s.count(4))&&(!s.count(5))&&(!s.count(6))&&(!s.count(7))){
                if(!a){
                    b=true;
                    ans++;
                }
            }
             if((!s.count(8))&&(!s.count(9))&&(!s.count(6))&&(!s.count(7))){
                if(!b){
                    ans++;
                }
            }    
        }

    return ans;
    }
};