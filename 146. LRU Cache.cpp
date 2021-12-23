/*
A list and a hash table.
 1. time complexity of get() needs to be O(1), use Hash
 2. get() and put() move the data position, and the time complexity is O(1), use list to add and remove elements
*/

class LRUCache {
private:
    int cap;
    list<pair<int, int>> cache;  // (key, value) list
    unordered_map<int, list<pair<int, int>>::iterator> index;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = index.find(key); // it is the iterator of the map
        if (it == index.end()) return -1;  // key not exists

        cache.splice(cache.begin(), cache, it->second); // transfer from it->second of cache into the position cache.begin()
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = index.find(key);
        if (it != index.end()) { // key already exists
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
        } else { // key not exists
            if (cap == cache.size()) {
                auto& last = cache.back();
                index.erase(last.first);  // 1. remove the old key in the index
                cache.pop_back();         // 2. remove the old element in the cache
            }
            cache.emplace_front(key, value);
            index[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
