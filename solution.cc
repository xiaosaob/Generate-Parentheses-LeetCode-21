// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// "((()))", "(()())", "(())()", "()(())", "()()()"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n,0,0,"",res);
        return res;
    }
    
    void helper(int n, int leftNum, int rightNum, string curSol, vector<string> &res) {
        if(leftNum == n) {
            curSol.append(n-rightNum, ')');
            res.push_back(curSol);
            return;
        } 
        helper(n, leftNum+1, rightNum, curSol+"(", res);
        if(rightNum < leftNum)
            helper(n, leftNum, rightNum+1, curSol+")", res);
    }
};
