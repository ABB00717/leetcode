/*
 * @lc app=leetcode id=3306 lang=cpp
 *
 * [3306] Count of Substrings Containing Every Vowel and K Consonants II
 */

// @lc code=start
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
class Solution {
public:
  long long countOfSubstrings(std::string word, int k) {
    long long result = 0;
    int l = 0, r = 0;
    std::pmr::unordered_map<char, int> vowelCount;
    int consonantCount = 0;

    std::pmr::vector<int> nextConsonant(word.size());
    int nextConsonantIndex = word.size();
    for (int i = word.size()-1; i >= 0; i--) {
      nextConsonant[i] = nextConsonantIndex;
      if (!isVowel(word[i]))
        nextConsonantIndex = i;
    }

    while (r < word.size()) {
      char newLetter = word[r];

      if (isVowel(newLetter))
        vowelCount[newLetter]++;
      else
        consonantCount++;

      while (consonantCount > k) {
        char lLetter = word[l];
        if (isVowel(lLetter)) {
          vowelCount[lLetter]--;
          if (vowelCount[lLetter] == 0)
            vowelCount.erase(lLetter);
        } else {
          consonantCount--;
        }

        l++;
      }

      while (consonantCount == k && vowelCount.size() == 5 && l < word.size()) {
        result += nextConsonant[r] - r;
        char lLetter = word[l];
        if (isVowel(lLetter)) {
          vowelCount[lLetter]--;
          if (vowelCount[lLetter] == 0)
            vowelCount.erase(lLetter);
        } else {
          consonantCount--;
        }

        l++;
      }
      r++;
    }

    return result;
  }

private:
  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
};
// @lc code=end
