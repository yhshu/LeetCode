/* 
 本题是两个数据结构的组合：list 和 hash
 LRU Cache 的需求：
 1. get() 取数据的时间复杂度需要满足 O(1)，使用 hash
 2. get() 和 put() 导致数据位置的移动，时间复杂度需要满足 O(1)，使用 list 的增删操作
*/

class LRUCache {
private:
    int capacity_;               // cache 容量
    list<pair<int, int>> cache_; // 存储数据的双向链表，(索引，内容)
    unordered_map<int, list<pair<int, int>>::iterator> map_;  // cache 索引到链表结点的映射
    
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        const auto it = map_.find(key);
        if(it == map_.cend())     // 没有找到
            return -1;
        
        // 将最近访问的数据移动
        // 从 cache_ 中将 it->second 对应的元素剪切到 cache_.begin() 之前
        cache_.splice(cache_.begin(), cache_, it->second); 
        return it->second->second;
    }
    
    void put(int key, int value) {
        const auto it = map_.find(key);
        
        if(it != map_.cend()) {   // key 已经存在
            it->second->second = value;
            cache_.splice(cache_.begin(), cache_, it->second);
            return;
        }
        
        // key 尚不存在
        // 如果容量已满，在链表中删除最早使用的元素
        if(capacity_ == cache_.size()) {
            const auto& node = cache_.back();  // 获取链表末尾元素
            map_.erase(node.first);            // 在 hash 中删除该元素的键
            cache_.pop_back();
        }
        // 将当前元素插入到链表中，并将键放入 hash
        cache_.emplace_front(key, value);
        map_[key] = cache_.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
