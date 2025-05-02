/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
#include <cstdlib>
#include <vector>
class Solution {
public:
  std::vector<int> asteroidCollision(std::vector<int> &asteroids) {
    std::vector<int> result;
    result.reserve(asteroids.size());

    for (int i = 0; i < asteroids.size(); i++) {
      if (asteroids[i] > 0 || result.empty() || result.back() < 0) {
        result.push_back(asteroids[i]);
      } else if (result.back() <= -asteroids[i]) {
        if (result.back() < -asteroids[i]) {
          i--;
        }
        result.pop_back();
      }
    }

    return result;
  }
};
// @lc code=end