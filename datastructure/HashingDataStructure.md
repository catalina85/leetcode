# Hashing

## Introduction

Suppose we want to design a system for storing employee records keyed using phone numbers. And we want following queries to be performed efficiently:

1. Insert a phone number and corresponding information.
2. Search a phone number and fetch the information.
3. Delete a phone number and related information.

We can think of using the following data structures to maintain information about different phone numbers.

1. Array of phone numbers and records.
2. Linked List of phone numbers and records.
3. Balanced binary search tree with phone numbers as keys.
4. Direct Access Table.

Due to above limitations Direct Access Table cannot always be used. **Hashing** is the solution that can be used in almost all such situations and performs extremely well compared to above data structures like Array, Linked List, Balanced BST in practice. With hashing we get O(1) search time on average (under reasonable assumptions) and O(n) in worst case.

Hashing is an improvement over Direct Access Table. The idea is to use hash function that converts a given phone number or any other key to a smaller number and uses the small number as index in a table called hash table.



**Hash Function:** A function that converts a given big phone number to a small practical integer value. The mapped integer value is used as an index in hash table. In simple terms, a hash function maps a big number or string to a small integer that can be used as index in hash table.

A good hash function should have following properties
1) Efficiently computable.
2) Should uniformly distribute the keys (Each table position equally likely for each key)

For example for phone numbers a bad hash function is to take first three digits. A better function is consider last three digits. Please note that this may not be the best hash function. There may be better ways.

**Hash Table:** An array that stores pointers to records corresponding to a given phone number. An entry in hash table is NIL if no existing phone number has hash function value equal to the index for the entry.

## **Collision Handling**

**What is Collision?**
Since a hash function gets us a small number for a key which is a big integer or string, there is possibility that two keys result in same value. The situation where a newly inserted key maps to an already occupied slot in hash table is called collision and must be handled using some collision handling technique.

**What are the chances of collisions with large table?**
Collisions are very likely even if we have big table to store keys. An important observation is Birthday Paradox. With only 23 persons, the probability that two people have same birthday is 50%.

**How to handle Collisions?**
There are mainly two methods to handle collision:

- **Chaining:**The idea is to make each cell of hash table point to a linked list of records that have same hash function value. Chaining is simple, but requires additional memory outside the table.
- **Open Addressing:** In open addressing, all elements are stored in the hash table itself. Each table entry contains either a record or NIL. When searching for an element, we one by one examine table slots until the desired element is found or it is clear that the element is not in the table.



### **Separate Chaining**

The idea is to make each cell of hash table point to a linked list of records that have same hash function value.

Let us consider a simple hash function as “**key mod 7**” and sequence of keys as 50, 700, 76, 85, 92, 73, 101.

![](../imgs/06_hashing/hashChaining1.png)



**Advantages:**
1) Simple to implement.
2) Hash table never fills up, we can always add more elements to chain.
3) Less sensitive to the hash function or load factors.
4) It is mostly used when it is unknown how many and how frequently keys may be inserted or deleted.

**Disadvantages:**
1) Cache performance of chaining is not good as keys are stored using linked list. Open addressing provides better cache performance as everything is stored in same table.
2) Wastage of Space (Some Parts of hash table are never used)
3) If the chain becomes long, then search time can become O(n) in worst case.
4) Uses extra space for links.

**Performance of Chaining:**
Performance of hashing can be evaluated under the assumption that each key is equally likely to be hashed to any slot of table (simple uniform hashing).

```
 m = Number of slots in hash table
 n = Number of keys to be inserted in hash table
 
 Load factor α = n/m 
  
 Expected time to search = O(1 + α)
 
 Expected time to insert/delete = O(1 + α)

 Time complexity of search insert and delete is 
 O(1) if  α is O(1)
```

 

### **Open Addressing** 

Like separate chaining, open addressing is a method for handling collisions. In Open Addressing, all elements are stored in the hash table itself. So at any point, size of the table must be greater than or equal to the total number of keys (Note that we can increase table size by copying old data if needed).

Insert(k): Keep probing until an empty slot is found. Once an empty slot is found, insert k.

Search(k): Keep probing until slot’s key doesn’t become equal to k or an empty slot is reached.

Delete(k): **Delete operation is interesting**. If we simply delete a key, then search may fail. So slots of deleted keys are marked specially as “deleted”.
Insert can insert an item in a deleted slot, but the search doesn’t stop at a deleted slot.



Open Addressing is done following ways:

- **a)Linear Probing:** In linear probing, we linearly probe for next slot. For example, typical gap between two probes is 1 as taken in below example also.
  let **hash(x)** be the slot index computed using hash function and **S** be the table size

  ```
  If slot hash(x) % S is full, then we try (hash(x) + 1) % S
  If (hash(x) + 1) % S is also full, then we try (hash(x) + 2) % S
  If (hash(x) + 2) % S is also full, then we try (hash(x) + 3) % S 
  ..................................................
  ..................................................
  ```

  Let us consider a simple hash function as “key mod 7” and sequence of keys as 50, 700, 76, 85, 92, 73, 101.

  ![](../imgs/06_hashing/openAddressing1.png)

  **Clustering:** The main problem with linear probing is clustering, many consecutive elements form groups and it starts taking time to find a free slot or to search an element. 

- **b) Quadratic Probing** We look for i[^2]‘th slot in i’th iteration.

  ```
  let hash(x) be the slot index computed using hash function.  
  If slot hash(x) % S is full, then we try (hash(x) + 1*1) % S
  If (hash(x) + 1*1) % S is also full, then we try (hash(x) + 2*2) % S
  If (hash(x) + 2*2) % S is also full, then we try (hash(x) + 3*3) % S
  ..................................................
  ..................................................
  ```

- **c) Double Hashing** We use another hash function hash2(x) and look for i*hash2(x) slot in i’th rotation.

  ```
  let hash(x) be the slot index computed using hash function.  
  If slot hash(x) % S is full, then we try (hash(x) + 1*hash2(x)) % S
  If (hash(x) + 1*hash2(x)) % S is also full, then we try (hash(x) + 2*hash2(x)) % S
  If (hash(x) + 2*hash2(x)) % S is also full, then we try (hash(x) + 3*hash2(x)) % S
  ..................................................
  ..................................................
  ```

  See this for step by step diagrams.

  

  

**Comparison of above three:**

Linear probing has the best cache performance but suffers from clustering. One more advantage of Linear probing is easy to compute.

Quadratic probing lies between the two in terms of cache performance and clustering.

Double hashing has poor cache performance but no clustering. Double hashing requires more computation time as two hash functions need to be computed.



| S.No. | **Seperate Chaining**                                        | **Open Addressing**                                          |
| :---: | ------------------------------------------------------------ | ------------------------------------------------------------ |
|  1.   | Chaining is Simpler to implement.                            | Open Addressing requires more computation.                   |
|  2.   | In chaining, Hash table never fills up, we can always add more elements to chain. | In open addressing, table may become full.                   |
|  3.   | Chaining is Less sensitive to the hash function or load factors. | Open addressing requires extra care for to avoid clustering and load factor. |
|  4.   | Chaining is mostly used when it is unknown how many and how frequently keys may be inserted or deleted. | Open addressing is used when the frequency and number of keys is known. |
|  5.   | Cache performance of chaining is not good as keys are stored using linked list. | Open addressing provides better cache performance as everything is stored in the same table. |
|  6.   | Wastage of Space (Some Parts of hash table in chaining are never used). | In Open addressing, a slot can be used even if an input doesn’t map to it. |
|  7.   | Chaining uses extra space for links.                         | No links in Open addressing                                  |

**Performance of Open Addressing:**

Like Chaining, the performance of hashing can be evaluated under the assumption that each key is equally likely to be hashed to any slot of the table (simple uniform hashing)

  ```
   m = Number of slots in the hash table
   n = Number of keys to be inserted in the hash table
   
   Load factor α = n/m  ( < 1 )
  
   Expected time to search/insert/delete < 1/(1 - α) 
  
   So Search, Insert and Delete take (1/(1 - α)) time
  ```


### Double Hashing

**Double hashing** is a collision resolving technique in **Open Addressed** Hash tables. Double hashing uses the idea of applying a second hash function to key when a collision occurs.

> Double hashing can be done using :
> **(hash1(key) + i /* hash2(key)) % TABLE_SIZE**
> Here hash1() and hash2() are hash functions and TABLE_SIZE is size of hash table.
> (We repeat by increasing i when collision occurs)

First hash function is typically hash1(key) = key % TABLE_SIZE

A popular second hash function is : **hash2(key) = PRIME – (key % PRIME)** where PRIME is a prime smaller than the TABLE_SIZE.

A good second Hash function is:

- It must never evaluate to zero
- Must make sure that all cells can be probed

![](../imgs/06_hashing/double-hash-function.png)





