class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> sortedArr = arr;
        std::sort(sortedArr.begin(), sortedArr.end(), std::greater<int>());

        vector<int> result;
        for (int i = 0; i < arr.size(); i++) {
            if (i != arr.size()-1 && arr[i] != sortedArr[i]) {
                result.push_back(arr[i]);
            } else if (i != arr.size()-1 && arr[i] == sortedArr[i]) {
                arr.erase(arr.begin());
                result.push_back(arr[i]);
            } else {
                result.push_back(-1);
            }
        }

        return result;
    }
};