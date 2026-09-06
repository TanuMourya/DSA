class Solution {
public:
    string removeDuplicates(string s) {
      stack<char>st;
      int i=0;
      int n=s.length();
      while(i<n){
        if(st.empty() || st.top()!=s[i]){
            st.push(s[i]);
        }
        else{
            st.pop();
        }
        i++;
      }  
      string ans="";
      while(!st.empty()){
        ans+=st.top();
        st.pop();
      }
      if(ans!="")reverse(ans.begin(),ans.end());
      return ans;
    }
};