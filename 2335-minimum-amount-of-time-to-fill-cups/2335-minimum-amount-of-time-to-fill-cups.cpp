class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> q;
        for(auto it : amount){
           if(it>0) q.push(it);
        }
        int ans = 0;
        while(q.size()>0){
            int s1 = -1;
            if(q.size()>1){
                s1 = q.top();
                q.pop();
            }
            
            int s2 = -1;
            if(q.size()>0){
                s2 = q.top();
                q.pop();
            }
           // cout<<s1<<" "<<s2<<endl;
            s1--; s2--;
            //cout<<"after "<<s1<<" "<<s2<<endl;
            if(s1>0){
              //  cout<<"pushing "<<s1<<endl;
                q.push(s1);
                    }
            if(s2>0){
              //  cout<<"pushing "<<s2<<endl;
                q.push(s2);
                    }
            ans++;
        }
        if(!q.empty())ans++;
        return ans;
    }
};