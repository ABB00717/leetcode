#include <set>
using namespace std;

class SmallestInfiniteSet {
   public:
    SmallestInfiniteSet() {
        infinite_set.insert(1);
    }

    int popSmallest() {
        int top = *infinite_set.begin();
        infinite_set.erase(infinite_set.begin());

        if (infinite_set.size() == 0) {
            infinite_set.insert(top + 1);
        }

        return top;
    }

    void addBack(int target) {
        if (infinite_set.find(target) != infinite_set.end() || *infinite_set.rbegin() <= target) {
            return;
        }

        infinite_set.insert(target);
    }

   private:
    set<int> infinite_set;
};

int main() {
    SmallestInfiniteSet* obj = new SmallestInfiniteSet();
    obj->popSmallest();
    obj->addBack(1);
    obj->popSmallest();
    obj->popSmallest();
    obj->popSmallest();
    obj->addBack(2);
    obj->addBack(3);
    obj->popSmallest();
    obj->popSmallest();
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
