#include <iostream>
using namespace std; 
 
class List {
  private:
      struct node {
          int val;
          node* next;
          node(int v, node* n = 0):val(v), next(n){}
      };
      node* head;
      int _size;
  public:
      List();
      List(const List& other);
      List(const string & num);
      void clear();
      void push_front(int val);  
      List operator+(const List& other); 
      List& operator=(const List& other); 
      int size() const;
      ~List();
      friend ostream& operator<<(ostream & os, const List &  out);
};
 
List::List() {
  head = 0;
  _size = 0;
}
 
List::List(const List& other) {
  int* num = new int[other._size];
  node* current = other.head;
  int i = other._size - 1;
  while (current != 0) {
    num[i] = current->val;
    i--;
    current = current->next;
  }
  head = 0;
  _size = 0;
  for (int i = 0; i < other._size; i++) 
    push_front(num[i]);
  delete []num;  
}
 
List::List(const string& num) {
  head = NULL;
  _size = 0;
  for (int i = 0; i < num.size(); i++) 
    push_front(num[i] - 48);
}
 
void List::clear() {
  while (head != 0) {
    node* temp = head;
    head = head->next;
    delete temp;
  }
  _size = 0;
}
 
void List::push_front(int val) {
  node* temp = new node(val, head);
  head = temp;
  _size++;
}
 
List List::operator+(const List& other) {
  int max = _size > other._size ? _size : other._size;
  char* addNum = new char[max + 1];
  int carry = 0;
  List result;
  if (_size > other._size) {
    node* c1 = head, *c2 = other.head;
    int i = 0;
    while (c2 != 0) {
      addNum[i++] = (c1->val + c2->val + carry) % 10 + 48;
      carry = (c1->val + c2->val + carry) / 10;
      c1 = c1->next;
      c2 = c2->next;
    }
    while (c1 != 0) {
      addNum[i++] = (c1->val + carry) % 10 + 48;
      carry = (c1->val + carry) / 10;
      c1 = c1->next;
    }
    addNum[i] = carry + 48;
  } else {
    node* c1 = other.head, *c2 = head;
    int i = 0;
    while (c2 != 0) {
      addNum[i++] = (c1->val + c2->val + carry) % 10 + 48;
      carry = (c1->val + c2->val + carry) / 10;
      c1 = c1->next;
      c2 = c2->next;
    }
    while (c1 != 0) {
      addNum[i++] = (c1->val + carry) % 10 + 48;
      carry = (c1->val + carry) / 10;
      c1 = c1->next;
    }
    addNum[i] = carry + 48;
  }
  if (addNum[max] == '1') {
    for (int i = max; i >= 0; i--) 
      result.push_front(addNum[i] - 48);
  } else {
    for (int i = max - 1; i >= 0; i--) 
      result.push_front(addNum[i] - 48);
  }
  delete []addNum;
  return result;
}
 
List& List::operator=(const List& other) {
  node* temp = head;
  int* num = new int[other._size];
  node* current = other.head;
  int i = other._size - 1;
  while (current != 0) {
    num[i] = current->val;
    i--;
    current = current->next;
  }
  head = NULL;
  _size = 0;
  for (int i = 0; i < other._size; i++) 
    push_front(num[i]);
  while (temp != 0) {
    node* t = temp;
    temp = temp->next;
    delete t;
  }
  delete []num;
  return *this;  
}
 
int List::size() const  { return _size; }
 
List::~List() {
  clear();
}
 
ostream& operator<<(ostream& os, const List& out) {
  char* num = new char[out._size + 1];
  List::node* current = out.head;
  int i = out._size - 1;
  num[out._size] = '\0';
  while (current != 0) {
    num[i] = current->val + 48;
    i--;
    current = current->next;
  }
  os << num;
  delete []num;
  return os;
}
 
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    List l1(s1), l2(s2);
    List l3 = l1 + l2;
    cout << l3;
 
    return 0;
}
