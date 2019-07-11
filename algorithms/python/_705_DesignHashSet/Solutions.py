class MyHashSet:
    """
    Open Addressing
    using Double Hashing to implement
    index1 = (index1 + i1 * index2) % self.capacity
    """

    def __init__(self, ):
        """
        Initialize your data structure here.
        """
        self.capacity = 1 << 3
        self.load_factor = 0.75
        self.table = [None] * self.capacity
        self.size = 0
        self.prime = 7

    def add(self, key):
        index1 = self.myhash1(key)
        index2 = self.myhash2(key)
        while self.table[index1] is not None:
            if self.table[index1] == key:
                return
            if self.table[index1] == "==TOMBSTONE==":
                break
            i = 1
            index1 = (index1 + i * index2) % self.capacity
            i += 1
        self.table[index1] = key
        self.size += 1

        if self.size / self.capacity >= self.load_factor:
            self.rehash()

    def remove(self, key):
        index1 = self.myhash1(key)
        while self.table[index1] is not None:
            if self.table[index1] == key:
                self.table[index1] = "==TOMBSTONE=="
                self.size -= 1
                return
            index2 = self.myhash2(key)
            i = 1
            index1 = (index1 + i * index2) % self.capacity
            i += 1

    def contains(self, key):
        """
        Returns true if this set contains the specified element
        """
        index1 = self.myhash1(key)
        while self.table[index1] is not None:
            if self.table[index1] == key:
                return True
            index2 = self.myhash2(key)
            i = 1
            index1 = (index1 + i * index2) % self.capacity
            i += 1
        return False

    def myhash1(self, key):
        return key % self.capacity

    def myhash2(self, key):
        return self.prime - key % self.prime

    def rehash(self):
        self.capacity <<= 1
        new_table = [None] * self.capacity
        for i in range(self.capacity >> 1):
            if self.table[i] is not None and self.table[i] != "==TOMBSTONE==":
                index1 = self.myhash1(self.table[i])
                index2 = self.myhash2(self.table[i])
                while new_table[index1] is not None:
                    i1 = 1
                    index1 = (index1 + i1 * index2) % self.capacity
                    i1 += 1
                new_table[index1] = self.table[i]
        self.table = new_table

    def displayHash(self):
        for i in range(self.capacity):
            print(str(i) + " --> " + str(self.table[i]))


if __name__ == "__main__":
    myHashSet = MyHashSet()

    add = [30, 8, 79, 78, 81, 73, 99, 64, 77, 64, 57, 55, 27, 68, 70, 45, 54, 1, 84, 39, 19, 59, 38, 16, 51, 7, 10, 46,
           33, 89, 18, 89, 68, 25, 12, 48, 61, 93, 41, 57, 34, 29, 63, 65, 98, 73, 88, 24, 74, 38]

    rv = [9, 53, 5, 81, 84, 33, 24, 62, 55, 23, 10, 63, 98, 15, 36, 69, 30, 35, 26, 53, 81, 42, 98, 45, 43, 78, 19, 42,
          74, 77]

    contain = [87, 71, 85, 60, 72, 78, 1, 29, 83, 95, 57, 70, 70, 71, 43, 76, 47, 75, 77, 93, 79, 42, 16, 71, 48, 3, 61,
               71, 76, 49]

    for i in range(len(add)):
        myHashSet.add(add[i])

    for i in range(len(rv)):
        myHashSet.remove(rv[i])

    for i in range(len(contain)):
        print(myHashSet.contains(contain[i]))

    # output:
    # 0    False    false
    # 0    False    false
    # 0    False    false
    # 0    False    false
    # 0    False    false
    # 0    False    false
    # 1    True     true
    # 1    True     true
    # 0    False    false
    # 0    False    false
    # 1    True     true
    # 1    True     true
    # 1    True     true
    # 0    False    false
    # 0    False    false
    # 0    False    false
    # 0    False    false
    # 0    False    false
    # 0    False    false
    # 1    True     true
    # 1    True     true
    # 0    False    false
    # 1    True     true
    # 0    False    false
    # 1    True     true
    # 0    False    false
    # 1    True     true
    # 0    False    false
    # 0    False    false
    # 0    False    false