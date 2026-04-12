#include <iostream>

const int TABLE_SIZE = 10;

class HashTable {
private:
    int table[TABLE_SIZE];
    bool isOccupied[TABLE_SIZE];

    // map keys to indices
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            isOccupied[i] = false;
        }
    }
    
    // if occupied, step forward until finidng an empty slot or the key itself
    void insert(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (isOccupied[index]) {
            if (table[index] == key) {
                return; 
            }
            index = (index + 1) % TABLE_SIZE; 
            
            if (index == startIndex) {
                std::cout << "Error: Hash table is full.\n";
                return;
            }
        }

        table[index] = key;
        isOccupied[index] = true;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (isOccupied[index]) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % TABLE_SIZE;
            
            if (index == startIndex) {
                break;
            }
        }
        return false;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (isOccupied[i]) {
                std::cout << "Index " << i << ": " << table[i] << "\n";
            } else {
                std::cout << "Index " << i << ": [Empty]\n";
            }
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(15);
    ht.insert(25); 
    ht.insert(35); 
    ht.insert(8);
    ht.insert(18);

    std::cout << "Hash Table Contents:\n";
    ht.display();

    std::cout << "\nSearch for 25: " << (ht.search(25) ? "Found" : "Not Found") << "\n";
    std::cout << "Search for 99: " << (ht.search(99) ? "Found" : "Not Found") << "\n";

    return 0;
}