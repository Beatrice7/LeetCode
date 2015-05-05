/********************************************************************************** 
* 
* Design and implement a data structure for Least Recently Used (LRU) cache. 
* It should support the following operations: get and set.
* 
*    get(key) - Get the value (will always be positive) of the key if the key exists 
*               in the cache, otherwise return -1.
*
*    set(key, value) - Set or insert the value if the key is not already present. 
*                      When the cache reached its capacity, it should invalidate 
*                      the least recently used item before inserting a new item.
*               
**********************************************************************************/

class LRUCache
{
    public:
        struct Node{
            int key;
            int value;
            Node(int k, int v):key(k), value(v){}
        };

        LRUCache(int capacity):capacity_(capacity){}

        int get(int key){
            auto it = cacheMap_.find(key);
            if(it != cacheMap_.end()){
                //remove it from dataList, add to dataList.begin()
                dataList_.splice(dataList_.begin(), dataList_, it->second);
                //after the codes above, the it->second is invalid.
                it->second = dataList_.begin();
                return it->second->value;
            }
            return -1;
        }

        void set(int key, int value){
            auto it = cacheMap_.find(key);
            if(it != cacheMap_.end()){
                dataList_.splice(dataList_.begin(), dataList_, it->second);
                it->second = dataList_.begin();
                it->second->value = value;
            }else{//insert
                if(dataList_.size() >= capacity_){
                    //tail store the last Node, not the iterator of Node like dataList_.end() 
                    auto tail = dataList_.back();
                    cacheMap_.erase(tail.key);//fatal important!!!
                    dataList_.pop_back();
                    tail.key = key, tail.value = value;
                    dataList_.push_front(tail);
                    cacheMap_[key] = dataList_.begin();
                }else{
                    dataList_.push_front(Node(key, value));
                    cacheMap_[key] = dataList_.begin();
                }
                
            }
        }

    private:
        list<Node> dataList_;
        unordered_map<int, list<Node>::iterator> cacheMap_;
        int capacity_;
};





#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache
{
    public:
        struct Node{
            int key;
            int value;
            Node(int k, int v):key(k), value(v){}
        };

        LRUCache(int capacity):capacity_(capacity){}

        int get(int key){
            auto it = cacheMap_.find(key);
            if(it != cacheMap_.end()){
                //remove it from dataList, add to dataList.begin()
                dataList_.splice(dataList_.begin(), dataList_, it->second);
                //after the codes above, the it->second is invalid.
                it->second = dataList_.begin();
                return it->second->value;
            }
            return -1;
        }

        void set(int key, int value){
            auto it = cacheMap_.find(key);
            if(it != cacheMap_.end()){
                dataList_.splice(dataList_.begin(), dataList_, it->second);
                it->second = dataList_.begin();
                it->second->value = value;
            }else{//insert
                if(dataList_.size() >= capacity_){
                    //tail store the last Node, not the iterator of Node like dataList_.end() 
                    auto tail = dataList_.back();
                    cacheMap_.erase(tail.key);//fatal important!!!
                    dataList_.pop_back();
                    tail.key = key, tail.value = value;
                    dataList_.push_front(tail);
                    cacheMap_[key] = dataList_.begin();
                }else{
                    dataList_.push_front(Node(key, value));
                    cacheMap_[key] = dataList_.begin();
                }
                
            }
        }

        void print(){
            for(list<Node>::iterator it = dataList_.begin(); it != dataList_.end(); ++it){
                cout << it->value << endl;    
            }
        }

    private:
        list<Node> dataList_;
        unordered_map<int, list<Node>::iterator> cacheMap_;
        int capacity_;
};



int main(int argc, const char *argv[])
{
    int capacity = 5;
    if(argc > 1){
        capacity = atoi(argv[1]);
    }
    
    LRUCache cache(capacity);
    
    int v;
    for(int i = 0; i < 10; ++i){
        v = i;
        cache.set(v, v);
    }
    cache.print();



    return 0;
}
