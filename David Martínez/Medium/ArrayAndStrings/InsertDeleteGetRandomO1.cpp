#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
    unordered_map<int, int> ht;
    vector<int> set;

public:
    RandomizedSet() {
        ht = unordered_map<int, int>();
        set = vector<int>();
    }
    
    bool insert(int val) {

        //check if value exists inside set. runtime: O(1)
        if(this->ht.find(val) != this->ht.end()){
            return false;
        }

        //if value does not exists
        //insert and return true. runtime: O(n)
        this->set.push_back(val);
        this->ht[val] = this->set.size()-1;
        return true;
    }
    
    bool remove(int val) {
        //check if value exists inside set. runtime: O(1)
        if(this->ht.find(val) != this->ht.end()){
            
            int idx = ht[val]; //get index of value to remove
            int last = set.back(); //get index of last element in set

            ht[last] = idx; //set new value of last element

            //swap value with last index
            swap(set[idx], set[set.size()-1]);

            set.pop_back(); //remove on array
            this->ht.erase(val); //remove on hash table


            return true;
        }

        return false;
    }
    
    int getRandom() {
        return set[rand() % set.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


/*
time: 38 minutes aprox

complexity
    runtime: O(1)
    space: O(n) 

notes:
    I have noticed that when I need to do object oriented programming
    and create multiple methods, I tend to rush and document less.

    I should stop and make a little documentation of what I am doing
    it could start with seeing the methods and going to a lower level of
    thinking about which data structures I will use and how I will use them.

    Overall, good performance still

*/