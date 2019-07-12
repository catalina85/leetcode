#include <iostream>

using namespace std;

class Node {
public:
    int key;
    int value;
    Node *next;

    Node(int key, int value, Node *next) {
        this->key = key;
        this->value = value;
        this->next = next;
    }
};

class MyHashMap {
    /**
     * Separate Chaining for handling Collisions
     */
public:
    int capacity;
    float load_factor;
    int size;
    Node **nodes;

    /** Initialize your data structure here. */
    MyHashMap() {
        this->capacity = 1 << 3;
        this->load_factor = 0.75;
        this->size = 0;
        this->nodes = new Node *[this->capacity];

        for (int i = 0; i < this->capacity; i++)
            nodes[i] = NULL;
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = this->myhash(key);
        Node *head = this->nodes[index];

        while (head != NULL) {
            if (head->key == key) {
                head->value = value;
                return;
            }
            head = head->next;
        }
        this->nodes[index] = new Node(key, value, this->nodes[index]);
        this->size += 1;

        if (float(this->size) / this->capacity >= this->load_factor)
            rehash();
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = this->myhash(key);
        Node *head = this->nodes[index];

        while (head != NULL) {
            if (head->key == key) {
                return head->value;
            }
            head = head->next;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = this->myhash(key);
        Node *dummyHead = new Node(-1, -1, this->nodes[index]);

        for (Node *head = dummyHead; head->next != NULL; head = head->next) {
            if (head->next->key == key) {
                head->next = head->next->next;
                this->size -= 1;
                break;
            }
        }
        nodes[index] = dummyHead->next;
    }

    int myhash(int key) {
        return key % this->capacity;
    }

    void rehash() {
        this->capacity <<= 1;
        Node **tmp = this->nodes;
        this->nodes = new Node *[this->capacity];
        this->size = 0;
        for (int i = 0; i < this->capacity; i++)
            nodes[i] = NULL;

        for (int i = 0; i < this->capacity >> 1; i++) {
            Node *head = tmp[i];
            while (head != NULL) {
                this->put(head->key, head->value);
                head = head->next;
            }
        }
    }

    void displayMap() {
        for (int i = 0; i < this->capacity; i++) {
            Node *head = this->nodes[i];
            cout << i << endl;
            while (head != NULL) {
                cout << "  key: " << head->key << " value: " << head->value << endl;
                head = head->next;
            }
        }
    }
};

int main() {
    auto *obj = new MyHashMap();
    int key[] = {30, 8, 79, 78, 81, 73, 99, 64, 77, 64, 57, 55, 27, 68, 70, 45, 54, 1, 84, 39, 19, 59, 38, 16, 51, 7,
                 10, 46, 33, 89, 18, 89, 68, 25, 12, 48, 61, 93, 41, 57, 34, 29, 63, 65, 98, 73, 88, 24, 74, 38};

    int value[] = {60, 15, 36, 35, 62, 82, 17, 61, 35, 1, 19, 97, 85, 58, 85, 44, 26, 18, 47, 55, 74, 81, 96, 66, 81, 5,
                   56, 88, 57, 33, 96, 64, 80, 74, 94, 17, 10, 68, 95, 89, 36, 59, 92, 85, 54, 20, 73, 0, 63, 95};

    int remove[] = {9, 53, 5, 81, 84, 33, 24, 62, 55, 23, 10, 63, 98, 15, 36, 69, 30, 35, 26, 53, 81, 42, 98, 45, 43,
                    78, 19, 42, 74, 77};

    int get[] = {87, 71, 85, 60, 72, 78, 1, 29, 83, 95, 57, 70, 70, 71, 43, 76, 47, 75, 77, 93, 79, 42, 16, 71, 48,
                 3, 61, 71, 76, 49};

    for (int i = 0; i < sizeof(key) / sizeof(key[0]); i++)
        obj->put(key[i], value[i]);

    for (int r: remove)
        obj->remove(r);

    for (int g: get)
        cout << obj->get(g) << endl;

    cout << "size: " << obj->size << endl;
    return 0;
/*
output:
cpp      	  py
-1            -1
-1            -1
-1            -1
-1            -1
-1            -1
-1            -1
18            18
59            59
-1            -1
-1            -1
89            89
85            85
85            85
-1            -1
-1            -1
-1            -1
-1            -1
-1            -1
-1            -1
68            68
36            36
-1            -1
66            66
-1            -1
17            17
-1            -1
10            10
-1            -1
-1            -1
-1            -1
size: 30      size:  30
 */

}