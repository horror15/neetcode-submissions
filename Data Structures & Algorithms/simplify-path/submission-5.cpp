class Solution {
public:
    string simplifyPath(string path) {
        int i=0;
        stack<string>st;
        while(i<path.size()){
            if(path[i]=='/'){
                i++;
                continue;
            } else if (path[i]=='.') {
                int j=i;
                while(j<path.size() && path[j] != '/'){
                    j++;
                }
                string token = path.substr(i, j-i);
                if(token == "."){
                    
                }else if(token == ".."){
                    if(!st.empty()){
                        st.pop();
                    }
                } else {
                    st.push(token);
                }
                i=j;
            } else {
                int j=i;
                while(j<path.size() && path[j] != '/'){
                    j++;
                }
                st.push(path.substr(i, j-i));
                i=j;
            }
        }
        string s = "";
        while(!st.empty()){
            s = "/" + st.top()  + s;
            st.pop();
        }
        if(s==""){
            return "/";
        }
        return s;
    }
};