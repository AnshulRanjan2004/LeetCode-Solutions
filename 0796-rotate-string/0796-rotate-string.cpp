class Solution {
public:
    bool rotateString(string s, string goal) {
        queue <int> q,q1;
        int n=s.size(); 
        for(int i=0;s[i]!='\0';i++){
         q.push(s[i]);
		 q1.push(goal[i]);
       }
        if(s==goal){
            return true;
        }
        int i=0;
        while(i<n){
            q.push(q.front());
            q.pop();
            if(q==q1)
                return true;
            i++;
        }
      return false; 
    }
};
