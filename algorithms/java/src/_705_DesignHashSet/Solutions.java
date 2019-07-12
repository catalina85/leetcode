package _705_DesignHashSet;

class MyHashSet {
    /**
     * Separate Chaining for handling Collisions
     */
    int capacity;
    final float LOAD_FACTOR = 0.75f;
    int size;
    Node[] nodes;

    /**
     * Initialize your data structure here.
     */
    public MyHashSet() {
        this.capacity = 1 << 3;
        this.size = 0;
        this.nodes = new Node[this.capacity];
    }

    public void add(int key) {
        int index = this.myhash(key);
        Node head = nodes[index];
        while (head != null) {
            if (head.key == key)
                return;
            head = head.next;
        }
        nodes[index] = new Node(key, nodes[index]);
        this.size += 1;

        if (1.0 * this.size / this.capacity >= LOAD_FACTOR)
            rehash();
    }

    public void remove(int key) {
        int index = this.myhash(key);
        Node dummyHead = new Node(-1, nodes[index]);

        for (Node head = dummyHead; head.next != null; head = head.next) {
            if (head.next.key == key) {
                head.next = head.next.next;
                this.size -= 1;
                break;
            }
        }
        nodes[index] = dummyHead.next;
    }

    /**
     * Returns true if this set contains the specified element
     */
    public boolean contains(int key) {
        int index = this.myhash(key);
        Node head = nodes[index];
        while (head != null) {
            if (head.key == key)
                return true;
            head = head.next;
        }
        return false;
    }

    public int myhash(int key) {
        return key % this.capacity;
    }

    public void rehash() {
        this.capacity <<= 1;
        Node[] tmp = nodes;
        nodes = new Node[this.capacity];
        this.size = 0;
        for (Node head : tmp) {
            for (Node n = head; n != null; n = n.next) {
                this.add(n.key);
            }
        }
    }

    public void displaySet() {
        for (int i = 0; i < this.capacity; i++) {
            Node head = nodes[i];
            System.out.print(i);
            while (head != null) {
                System.out.print(" --> " + head.key);
                head = head.next;
            }
            System.out.println();
        }
    }

    class Node {
        int key;
        Node next;

        Node(int key, Node next) {
            this.key = key;
            this.next = next;
        }
    }
}

public class Solutions {
    public static void main(String[] args) {
        MyHashSet myHashSet = new MyHashSet();

        int[] add = {30, 8, 79, 78, 81, 73, 99, 64, 77, 64, 57, 55, 27, 68, 70, 45, 54, 1, 84, 39, 19, 59, 38, 16, 51, 7,
                10, 46, 33, 89, 18, 89, 68, 25, 12, 48, 61, 93, 41, 57, 34, 29, 63, 65, 98, 73, 88, 24, 74, 38};

        int[] rv = {9, 53, 5, 81, 84, 33, 24, 62, 55, 23, 10, 63, 98, 15, 36, 69, 30, 35, 26, 53, 81, 42, 98, 45, 43, 78,
                19, 42, 74, 77};

        int[] contain = {87, 71, 85, 60, 72, 78, 1, 29, 83, 95, 57, 70, 70, 71, 43, 76, 47, 75, 77, 93, 79, 42, 16, 71, 48,
                3, 61, 71, 76, 49};

        for (int a : add)
            myHashSet.add(a);

        for (int r : rv)
            myHashSet.remove(r);

        for (int c : contain)
            System.out.println(myHashSet.contains(c));

        System.out.println("size: " + myHashSet.size);

//        output:
//        0    False    false
//        0    False    false
//        0    False    false
//        0    False    false
//        0    False    false
//        0    False    false
//        1    True     true
//        1    True     true
//        0    False    false
//        0    False    false
//        1    True     true
//        1    True     true
//        1    True     true
//        0    False    false
//        0    False    false
//        0    False    false
//        0    False    false
//        0    False    false
//        0    False    false
//        1    True     true
//        1    True     true
//        0    False    false
//        1    True     true
//        0    False    false
//        1    True     true
//        0    False    false
//        1    True     true
//        0    False    false
//        0    False    false
//        0    False    false
//        size: 30
    }
}