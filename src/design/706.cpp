#include <utility>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class MyHashMap {
public:
    MyHashMap() : table(N) {
    }

    void put(int key, int value) {
        auto &bucket = table[key % N];
        auto iter = find_if(bucket.begin(), bucket.end(), [=](pair<int, int> p) {
                return p.first == key;
                });
        if (iter == bucket.end()) bucket.emplace_back(key, value);
        else iter->second = value;
    }

    int get(int key) {
        auto &bucket = table[key % N];
        auto iter = find_if(bucket.begin(), bucket.end(), [=](pair<int, int> p) {
                return p.first == key;
                });
        if (iter == bucket.end()) return -1;
        else return iter->second;
    }

    void remove(int key) {
        auto &bucket = table[key % N];
        auto iter = find_if(bucket.begin(), bucket.end(), [=](pair<int, int> p) {
                return p.first == key;
                });
        if (iter != bucket.end()) bucket.erase(iter);
    }
private:
    constexpr static int N = 1e5;
    vector<list<pair<int, int>>> table;
};

int main() {
    MyHashMap m;
    m.put(1, 1);
    m.put(2, 2);
    cout << m.get(1) << endl;
    cout << m.get(3) << endl;
}
