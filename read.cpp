#include <iostream> //简单的链表法（双向链表）
using namespace std;
#define MAX 7
struct Node
{
  int key;
  Node *front;
  Node *back;
};
int h(int key)
{
  return key % 7;
}
void insert(Node *t[], int key)
{
  Node *head = t[h(key)];
  Node *one = new Node;
  one->key = key;
  one->front = head;
  one->back = head->back;
  if (head->back != nullptr)
  {
    head->back->front = one;
  }
  head->back = one;
}
bool search(Node *t[], int key)
{
  int hash = h(key);
  Node *head = t[hash];
  while (head->back != nullptr)
  {
    if (head->back->key == key)
    {
      return true;
    }
    head = head->back;
  }
  return false;
}
void remove(Node *t[], int key)
{
  int hash = h(key);
  Node *head = t[hash];
  Node *answer;
  while (head->back != nullptr)
  {
    if (head->back->key == key)
    {
      answer = head->back;
      break;
    }
    head = head->back;
  }
  if (answer->back = nullptr)
  {
    answer->front->back = nullptr;
    delete answer;
  }
  else
  {
    answer->front->back = answer->back;
    answer->back->front = answer->front;
    delete answer;
  }
}
void print(Node *t[])
{
  for (int i = 0; i < MAX; i++)
  {
    Node *head = t[i]->back;
    while (head != nullptr)
    {
      cout << head->key << " ";
      head = head->back;
    }
    cout << '\n';
  }
}
int main()
{
  Node *t[MAX];
  for (int i = 0; i < MAX; i++)
  {
    t[i] = new Node;
    t[i]->key = i;
    t[i]->back = nullptr;
    t[i]->front = t[i];
  }
  insert(t, 12);
  insert(t, 1);
  insert(t, 3);
  insert(t, 8);
  print(t);
  return 0;
}
