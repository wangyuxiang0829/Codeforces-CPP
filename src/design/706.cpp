#include <utility>
#include <list>
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;
using namespace placeholders;
class MyHashMap {
public:
    MyHashMap() : table(N) {
    }

    void put(int key, int value) {
        auto &bucket = table[key % N];
        auto iter = find_if(bucket.begin(), bucket.end(), bind(equal, _1, key));
        if (iter == bucket.end()) bucket.emplace_back(key, value);
        else iter->second = value;
    }

    int get(int key) {
        auto &bucket = table[key % N];
        auto iter = find_if(bucket.begin(), bucket.end(), bind(equal, _1, key));
        if (iter == bucket.end()) return -1;
        else return iter->second;
    }

    void remove(int key) {
        auto &bucket = table[key % N];
        auto iter = find_if(bucket.begin(), bucket.end(), bind(equal, _1, key));
        if (iter != bucket.end()) bucket.erase(iter);
    }
private:
    constexpr static int N = 1e5 + 7;
    vector<list<pair<int, int>>> table;

    static bool equal(pair<int, int> p, int key) {
        return key == p.first;
    }
};

int main() {
    MyHashMap m;
    m.put(1, 1);
    m.put(2, 2);
    cout << m.get(1) << endl;
    cout << m.get(3) << endl;
}
