class LRUCache {
public:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> m;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        cache.splice(cache.begin(), cache, m[key]);
        return m[key]->second;
    }
    
    void put(int key, int value) {

    // If key already exists in cache
    if (m.find(key) != m.end()) {

        // Update the value associated with the key
        m[key]->second = value;

        // Since this key was just used/updated,
        // move it to the front (Most Recently Used)
        cache.splice(cache.begin(), cache, m[key]);

        return;
    }

    // Key does not exist.
    // Check if cache is already full.
    if (cache.size() == cap) {

        // The node at the back is the
        // Least Recently Used (LRU) node.
        auto d_key = cache.back().first;

        // Remove the key from hashmap
        m.erase(d_key);

        // Remove the node from the list
        cache.pop_back();
    }

    // Insert the new key-value pair at the front
    // because a newly inserted key is considered
    // Most Recently Used (MRU)
    cache.push_front({key, value});

    // Store iterator to the newly inserted node
    // for O(1) future access
    m[key] = cache.begin();
    
    }
};