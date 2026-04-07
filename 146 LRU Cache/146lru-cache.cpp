#include <unordered_map>
#include <list>

class LRUCache {
private:
    int cap;
    // list stores {key, value} pairs
    std::list<std::pair<int, int>> cacheList; 
    // map stores key -> iterator to the node in cacheList
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;

    // Helper to move a node to the "Most Recently Used" position (front)
    void makeRecentlyUsed(int key) {
        cacheList.splice(cacheList.begin(), cacheList, map[key]);
    }

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        // Move the accessed key to the front
        makeRecentlyUsed(key);
        return map[key]->second;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            // Update existing value and move to front
            map[key]->second = value;
            makeRecentlyUsed(key);
            return;
        }

        if (cacheList.size() == cap) {
            // Evict Least Recently Used (the back of the list)
            int lastKey = cacheList.back().first;
            map.erase(lastKey);
            cacheList.pop_back();
        }

        // Add new key-value pair to the front
        cacheList.push_front({key, value});
        map[key] = cacheList.begin();
    }
};
