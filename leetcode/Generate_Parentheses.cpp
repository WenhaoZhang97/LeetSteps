class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        addpar(result,"",n,0);
        return result;
    }
    
    void addpar(vector<string> &result,string initial,int m,int n) {
        //m--left parenthesis n--right parenthesis
        if(m==0&&n==0)
            result.push_back(initial);
        if(m>0)
            addpar(result,initial+"(",m-1,n+1);
        if(n>0)
            addpar(result,initial+")",m,n-1);
    }
};

//思路来自于leetcode的discussion