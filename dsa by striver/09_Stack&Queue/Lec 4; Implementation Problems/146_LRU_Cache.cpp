// Design a data structure that follows the constraints of a Least Recently Used(LRU) cache.

// Implement the LRUCache class :

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.int get(int key) Return the value of the key if the key exists,
// otherwise return -1. void put(int key, int value) Update the value of the key if the key exists.Otherwise, add the key - value pair to the cache.If the number of keys exceeds the capacity from this operation, evict the least recently used key.The functions get and put must each run in O(1) average time complexity.

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4

#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
  class Node
  {
  public:
    int key;
    int val;
    Node *prev;
    Node *next;

    Node(int key, int val)
    {
      this->key = key;
      this->val = val;
      this->prev = nullptr;
      this->next = nullptr;
    }
  };

  Node *head = new Node(-1, -1);
  Node *tail = new Node(-1, -1);

  int cap;

  unordered_map<int, Node *> m;

  LRUCache(int capacity)
  {
    cap = capacity;
    head->next = tail;
    tail->prev = head;
  }

  void deleteNode(Node *delNode)
  {
    Node *nextNode = delNode->next;
    Node *prevNode = delNode->prev;
    delNode->next = nullptr;
    delNode->prev = nullptr;
    nextNode->prev = prevNode;
    prevNode->next = nextNode;
  }

  void addNode(Node *newNode)
  {
    Node *temp = head->next;
    head->next = newNode;
    newNode->prev = head;
    newNode->next = temp;
    temp->prev = newNode;
  }

  int get(int key)
  {
    auto it = m.find(key);

    // key does not exist
    if (it == m.end())
    {
      return -1;
    }

    Node *resNode = it->second;

    int val = resNode->val;

    deleteNode(resNode);
    addNode(resNode);

    return val;
  }

  void put(int key, int value)
  {
    auto it = m.find(key);

    // key is found, have to update the value
    if (it != m.end())
    {
      Node *resNode = it->second;
      resNode->val = value;

      deleteNode(resNode);
      addNode(resNode);
    }

    else
    {
      if (m.size() == cap)
      {
        m.erase(tail->prev->key);
        deleteNode(tail->prev);

        Node *newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
      }

      else
      {
        Node *newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
      }
    }
  }
};