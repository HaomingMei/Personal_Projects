class TimeMap {
public:
    std::unordered_map<string, std::map<int, string>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {

        mp[key][timestamp] = value;

        
    }
    
    string get(string key, int timestamp) {
        // key exist
        if(mp.find(key) != mp.end())
        {
            const auto &itr = (mp.find(key))->second;
            auto valueIt = itr.upper_bound(timestamp);
            if(valueIt != itr.begin())
            {
                return (--valueIt)->second;
            }
            else if(valueIt == itr.begin())
            {
                return "";
            }
        }
        // key do not exist
            return "";
        

        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */