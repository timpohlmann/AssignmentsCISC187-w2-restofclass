# Hash Table coding assignment
### Code portion first and then im going to write some analysis
```C++
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


// HashTable Class
class HashTable {
private:
    vector<list<pair<string, int>>> table;  // the actual table: vector of buckets, each bucket is a linked list
    int currentSize;                         // how many elements are currently stored
    int capacity;                            // how many buckets exist
    int collisionCount;                      // how many collisions have happened

    // Converts a string key into a bucket index
    int hashFunction(const string& key) const {
        const int prime = 31;
        long long hash = 0;
        for (char c : key) {
            hash = hash * prime + c;//building a number piece by piece from each
        }
        // prevents negative numbers from overflow
        return ((hash % capacity) + capacity) % capacity;//hash%capacity is what bucket it will go to
    }

    // Called when table gets too full, doubles capacity and reinserts everything
    void rehash() {
        int oldCapacity = capacity;
        capacity = capacity * 2;//double the capacity
        collisionCount = 0;

        vector<list<pair<string, int>>> oldTable = table; // save old data
        table.clear();
        table.resize(capacity);  // make a new bigger table
        currentSize = 0;

        // Reinsert every element from the old table into the new one
        for (auto& bucket : oldTable)//ranged base for loop
            for (auto& pair : bucket)
                insert(pair.first, pair.second);//calls insert function pair.first = key, pair.second=value

        cout << "[Rehash triggered] Capacity expanded: " << oldCapacity
             << " -> " << capacity << "\n";//output to update capacity
    }

public:
    // Constructor -- sets up an empty table with 11 buckets by default
    HashTable(int size = 11)
        : capacity(size), currentSize(0), collisionCount(0) {//initializes member variables
        table.resize(capacity);//creates 11 buckets(each with own linked list)
    }

    // Insert a key-value pair (or update value if key already exists)
    void insert(const string& key, int value) {
        if (loadFactor() > 0.75) rehash();  // resize if getting too full

        int index = hashFunction(key);       // figure out which bucket this key belongs in


        for (auto& pair : table[index]) {//ranged base for loop
            if (pair.first == key) {//if theres already a value at that key replace it
                pair.second = value;
                return;
            }
        }


        if (!table[index].empty()) {//is a collision if its added to non-empty bucket
            collisionCount++;
        }

        table[index].push_back({key, value}); // add to the bucket, end of the linked list
        currentSize++;//adds to the amount of pairs total
    }

    // Remove a key, returns true if it was found and removed, false if not found
    bool remove(const string& key) {
        int index = hashFunction(key);//calling hashfunction to find index where it would be
        auto& bucket = table[index];//which bucket

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {//loops through list using iterator, goes until end of list
            if (it->first == key) {//looks at the key of each pair in the list, compares it to the one we passed into the function
                bucket.erase(it);//removes it(build in function)
                currentSize--;//updates #of pairs
                return true;
            }
        }
        return false;//if key not found
    }

    // Search for a key -- returns the value if found, or -1 if not found
    int search(const string& key) const {//given a key
        int index = hashFunction(key);//calls hashfunction with key parameter
        for (const auto& pair : table[index]) {//range based for loop, loops through every pair in the table(bucket)
            if (pair.first == key) {//if the key is found return the value which corresponds to it
                return pair.second;
            }
        }
        return -1; // -1 means not found
    }

    // Load factor is how full the table is (elements / capacity)
    double loadFactor() const {
        return (double)currentSize / capacity;
    }

    int size() const { return currentSize; }

    bool isEmpty() const { return currentSize == 0; }//returns true if empty

    // Print every bucket and what's in it
    void printTable() const {
        for (int i = 0; i < capacity; i++) {
            cout << "Bucket[" << i << "]: ";//so for each bucket(the amount of buckets is equal to the capacity)
            for (const auto& pair : table[i]) {//for each bucket print the key and value for each pair
                cout << "(" << pair.first << ", " << pair.second << ") ";
            }
            cout << "\n";
        }
    }

   //these functions will make analysis clearer
    int getCollisionCount() const { return collisionCount; }
    int getCapacity() const { return capacity; }

    int maxBucketSize() const {
        int maxSize = 0;
        for (const auto& bucket : table)
            maxSize = max(maxSize, (int)bucket.size());//using max function that updates if new bucket is larger than previous bucket iterated over
        return maxSize;
    }

    double avgBucketLength() const {
        int nonEmpty = 0, total = 0;
        for (const auto& bucket : table) {//loops over every bucket
            if (!bucket.empty()) {//if the bucket is not empty
                nonEmpty++;
                total += bucket.size();//add to the total size
            }
        }//using ternary operator, if all buckets are empty, its 0, otherwise the total amount size/buckets containing anyhing
        return nonEmpty == 0 ? 0.0 : (double)total / nonEmpty;
    }
};


// Helper: print stats about a hash table
void printStats(const string& label, HashTable& ht) {//parameters
    cout << "\n===== " << label << " =====\n";
    cout << "Capacity:         " << ht.getCapacity() << "\n";//using helper functions from the class
    cout << "Elements:         " << ht.size() << "\n";
    cout << "Load Factor:      " << ht.loadFactor() << "\n";
    cout << "Total Collisions: " << ht.getCollisionCount() << "\n";
    cout << "Max Bucket Size:  " << ht.maxBucketSize() << "\n";
    cout << "Avg Bucket Len:   " << ht.avgBucketLength() << "\n";
}



// Test 1: Random/varied words
void testRandomWords() {
    HashTable ht;

    vector<string> words = {
        "apple","banana","cherry","date","elderberry","fig","grape","honeydew",
        "kiwi","lemon","mango","nectarine","orange","papaya","quince","raspberry",
        "strawberry","tangerine","ugli","vanilla","watermelon","xigua","yam","zucchini",
        "apricot","blueberry","cantaloupe","dragonfruit","durian","guava","jackfruit",
        "kumquat","lychee","mulberry","persimmon","pomegranate","rambutan","starfruit",
        "tamarind","coconut","avocado","pineapple","plum","peach","pear","lime",
        "clementine","mandarin","grapefruit","boysenberry","blackberry","cranberry",
        "gooseberry","currant","passionfruit","breadfruit","soursop","sapodilla",
        "feijoa","ackee","carambola","cherimoya","longan","mangosteen","noni",
        "pawpaw","plantain","salak","santol","wampee","langsat","marang","pulasan",
        "bignay","siniguelas","camias","guyabano","macopa","balimbing","chico",
        "caimito","bayabas","kalamansi","duhat","sampaloc","paho","kalamunding",
        "cotton","silk","linen","wool","polyester","nylon","denim","velvet",
        "satin","chiffon","tweed","flannel","corduroy","muslin","organza",
        "poplin","rayon","spandex","cashmere","angora"
    };//'random' words

    for (const auto& w : words) {//range based for loop, loops through each string w in the vector
        ht.insert(w, (int)w.size());//parameters going into insert function, w is the string that your at.
    }

    printStats("Test 1: Random/Varied Words", ht);//calling print stats with parameters


    string existing = "watermelon";
    int result = ht.search(existing);//calling search function with parameter
    cout << "\nSearch '" << existing << "': "
         << (result != -1 ? "Found, value=" + to_string(result) : "Not found") << "\n";//if result is found
    //search function returns the value, and found value and string result

    // Search for a non-existing key
    string missing = "dragonsbreath";
    result = ht.search(missing);
    cout << "Search '" << missing << "': "
         << (result != -1 ? "Found, value=" + to_string(result) : "Not found") << "\n";//if value is found, it prints the index was found @
    //otherwise prints not found

    // Remove an existing key and verify
    cout << "\nRemove 'apple': " << (ht.remove("apple") ? "Success" : "Not found") << "\n";//if remove function works its success, else not found
    cout << "Search 'apple' after remove: "
         << (ht.search("apple") != -1 ? "Still found (ERROR)" : "Not found (OK)") << "\n";//if value is found prints still found, should be not found


    cout << "Remove 'dragonsbreath': "
         << (ht.remove("dragonsbreath") ? "Success (ERROR)" : "Not found (OK)") << "\n";//removing something that doesnt exist,
}//should return false, meaning its not found



// Test 2: Sequential keys (student1, student2, ...)
void testSequentialKeys() {
    HashTable ht;
    for (int i = 1; i <= 100; i++)//for loop
        ht.insert("student" + to_string(i), i);//inserting students and corresponding values
    printStats("Test 2: Sequential Keys (student1..student100)", ht);
}


// Test 3: Same-prefix keys (data_0001, data_0002, ...)
void testSamePrefixKeys() {
    HashTable ht;
    for (int i = 1; i <= 100; i++) {
        string key = "data_";//filling table with keys of same prefix, purpose of testing how good the hash function is
        if      (i < 10)  key += "000" + to_string(i);//1-9
        else if (i < 100) key += "00"  + to_string(i);//10-99
        else              key += "0"   + to_string(i);//100
        ht.insert(key, i);
    }
    printStats("Test 3: Same-Prefix Keys (data_0001..data_0100)", ht);
}


int main() {
    cout << "   Hash Table Lab - C++ Implementation  \n";

    testRandomWords();//calling tests
    testSequentialKeys();
    testSamePrefixKeys();

    cout << "\n[Done]\n";
    return 0;
}
```
