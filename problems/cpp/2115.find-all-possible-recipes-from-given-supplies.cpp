/*
 * @lc app=leetcode id=2115 lang=cpp
 *
 * [2115] Find All Possible Recipes from Given Supplies
 */

// @lc code=start
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> findAllRecipes(
        vector<string>& recipes,
        vector<vector<string>>& ingredients,
        vector<string>& supplies) {
        vector<string> create;
        unordered_map<string, vector<string>> ingredients_to_recipes;
        unordered_map<string, int> indegree;
        
        for (int i = 0; i < recipes.size(); i++) {
            indegree[recipes[i]] += ingredients[i].size();
            
            for (const string& ingredient : ingredients[i]) {
                ingredients_to_recipes[ingredient].push_back(recipes[i]);
            }
        }
        
        stack<string> supplies_stack;
        for (const string& supply : supplies)
            supplies_stack.push(supply);

        while (!supplies_stack.empty()) {
            string ingredient = supplies_stack.top();
            supplies_stack.pop();
            for (const string& recipe : ingredients_to_recipes[ingredient]) {
                indegree[recipe]--;
                if (indegree[recipe] == 0) {
                    supplies_stack.push(recipe);
                    create.push_back(recipe);
                }
            }
        }
        
        return create;
    }
};

// @lc code=end
