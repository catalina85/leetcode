class MyHashMap:
    """
    Open Addressing for handling Collisions
    index = (5 * index + 1) % self->capacity;
    """

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.capacity = 1 << 3
        self.load_factor = 0.75
        self.size = 0
        # self.nodes = [Node(-1, -1)] * self.capacity
        self.nodes = [Node(-1, -1) for _ in range(self.capacity)]

    def put(self, key, value):
        """
        value will always be non-negative.
        """
        index1 = self.myhash(key)
        while (self.nodes[index1].key != -1):
            if (self.nodes[index1].key == key):
                self.nodes[index1].value = value
                return
            if (self.nodes[index1].key == -2):
                break
            index1 = (5 * index1 + 1) % self.capacity

        self.nodes[index1].key = key
        self.nodes[index1].value = value
        self.size += 1

        if self.size / self.capacity >= self.load_factor:
            self.rehash()

    def get(self, key):
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        index1 = self.myhash(key)
        while (self.nodes[index1].key != -1):
            if (self.nodes[index1].key == key):
                return self.nodes[index1].value
                # return self.nodes[index1].key
            index1 = (5 * index1 + 1) % self.capacity
        return -1

    def remove(self, key):
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """
        index1 = self.myhash(key)
        while (self.nodes[index1].key != -1):
            if (self.nodes[index1].key == key):
                self.nodes[index1] = Node(-2, -2)
                self.size -= 1
                return
            index1 = (5 * index1 + 1) % self.capacity

    def myhash(self, key):
        return key % self.capacity

    def rehash(self):
        self.capacity <<= 1
        new_nodes = [Node(-1, -1) for _ in range(self.capacity)]

        for i in range(self.capacity >> 1):
            if self.nodes[i].key != -1:
                index1 = self.myhash(self.nodes[i].key)

                while (new_nodes[index1].key != -1):
                    index1 = (5 * index1 + 1) % self.capacity

                new_nodes[index1].key = self.nodes[i].key
                new_nodes[index1].value = self.nodes[i].value
        self.nodes = new_nodes

    def displayMap(self):
        for i in range(self.capacity):
            print(str(i) + ": key: " + str(self.nodes[i].key) + " value: " + str(self.nodes[i].value))


class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None


if __name__ == "__main__":
    # Your MyHashMap object will be instantiated and called as such:
    obj = MyHashMap()

    key = [30, 8, 79, 78, 81, 73, 99, 64, 77, 64, 57, 55, 27, 68, 70, 45, 54, 1, 84, 39, 19, 59, 38, 16, 51, 7,
           10, 46, 33, 89, 18, 89, 68, 25, 12, 48, 61, 93, 41, 57, 34, 29, 63, 65, 98, 73, 88, 24, 74, 38]

    value = [60, 15, 36, 35, 62, 82, 17, 61, 35, 1, 19, 97, 85, 58, 85, 44, 26, 18, 47, 55, 74, 81, 96, 66, 81, 5,
             56, 88, 57, 33, 96, 64, 80, 74, 94, 17, 10, 68, 95, 89, 36, 59, 92, 85, 54, 20, 73, 0, 63, 95]

    remove = [9, 53, 5, 81, 84, 33, 24, 62, 55, 23, 10, 63, 98, 15, 36, 69, 30, 35, 26, 53, 81, 42, 98, 45, 43,
              78, 19, 42, 74, 77]

    get = [87, 71, 85, 60, 72, 78, 1, 29, 83, 95, 57, 70, 70, 71, 43, 76, 47, 75, 77, 93, 79, 42, 16, 71, 48,
           3, 61, 71, 76, 49]

    for i in range(len(key)):
        obj.put(key[i], value[i])

    for each in remove:
        obj.remove(each)

    for each in get:
        print(obj.get(each))

    print("size: ", obj.size)

    '''
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
'''
