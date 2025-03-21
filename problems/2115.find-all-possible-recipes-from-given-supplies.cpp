/*
 * @lc app=leetcode id=2115 lang=cpp
 *
 * [2115] Find All Possible Recipes from Given Supplies
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
   public:
    std::vector<std::string> findAllRecipes(
        std::vector<std::string>& recipes,
        std::vector<std::vector<std::string>>& ingredients,
        std::vector<std::string>& supplies) {
        std::vector<std::string> create;
        std::vector<std::string> prev_create;

        std::unordered_set<std::string> supplies_set(supplies.begin(), supplies.end());
        do {
            prev_create = create;
            for (int i = 0; i < recipes.size();) {
                bool have_all_ingredients = true;
                for (const auto& ingredient : ingredients[i]) {
                    if (supplies_set.find(ingredient) == supplies_set.end()) {
                        have_all_ingredients = false;
                        break;
                    }
                }

                if (have_all_ingredients) {
                    supplies_set.insert(recipes[i]);
                    create.push_back(recipes[i]);
                    ingredients.erase(ingredients.begin() + i);
                    recipes.erase(recipes.begin() + i);
                } else {
                    i++;
                }
            }
        } while (create.size() != prev_create.size());

        return create;
    }
};

// @lc code=end
