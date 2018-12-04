#include <cassert>
#include "linkedList.h"
#include "linkedListFuncs.h"


// removed a few blank spaces in the code because I
// understand better when there aren't many unused spaces

void addIntToEndOfList(LinkedList *list, int value) {
  assert(list!=NULL); // if list is NULL, we can do nothing.

  Node* p = new Node;
  // (1) Allocate a new node.  p will point to it.
  p->data = value; //makes p->data point to int value
  p->next = NULL; //makes sure p->next is null;

  if (list->head == NULL) {
    //  Make both head and tail of this list point to p if list->head == null
    list->head = p;
    list->tail = p;    
  } else {
    // Add p at the end of the list.   
    list->tail->next = p; //list->tail->next was NULL, but now it points to p
    list->tail = p; //updates tail
  }
}

void addIntToStartOfList(LinkedList *list, int value) {
  assert(list!=NULL); // if list is NULL, we can do nothing.

  Node* p = new Node;//allocates a new node
  p->data = value;
  p->next = NULL;
  //  You will need two cases just as in addIntToEndOfList,
  //  one for when list->head is NULL and another for when it is not.
  if (list->head==NULL){
	  // Makes both head and tail of list point to p if list ->head is null
	  list->head = p;
	  list->tail = p;
  } else {
	// Add p start of list
	p->next = list->head; // makes p->next point to current head rather than NULL
	list->head = p; // updates head to be p
  }
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return a pointer to node with the largest value.
// You may assume list has at least one element  
// If more than one element has largest value, 
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head

Node * pointerToMax(LinkedList *list) {
  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.
  assert(list!=NULL);
  assert(list->head != NULL);

  Node * p = list->head; //allocate new node
  Node * max = new Node; //allocate new node that points to maximum value
  max = list->head; //data location of max.  start with list->head in case it is the largest value

  while(p){ // while p is not null
	if((p->data)>(max->data)) // if value at data location p is greater than value at data location max
		max = p;
	 p=p->next;// p points to next item in list
  }
  return max; //returns data location of max
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return a pointer to node with the smallest value.  
// You may assume list has at least one element
// If more than one element has smallest value, 
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head


Node * pointerToMin(LinkedList *list) {
  // Code may assume that these assertions are true;
  // so does not need to do error checking for these conditions.
  assert(list!=NULL);
  assert(list->head != NULL);
  
  Node * p = list->head; //allocate new node
  Node * min = new Node; //allocate new node that points to minimum value
  min = list->head; //data location of minimum value.  start with list->head in case it has the smallest value

  while(p){ // while p is not null
	if((p->data)<(min->data)) // if value at data location p is less than value at data location min
		min = p;
	 p=p->next;//p points to next item in list
  }
  return min; //returns data location of min
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the largest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int largestValue(LinkedList *list) {
  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.
  assert(list!=NULL);
  assert(list->head != NULL);
  
  Node * p = list->head; //allocate new node
  Node * max = new Node; //allocate new node that points to maximum value
  max = list->head; //data location of maximum value.  start with list->head in case it has the largest value

  while(p){ // while p is not null
	if((p->data)>(max->data)) // if value at data location p is greater than value at data location max
		max = p;
	 p=p->next;//p points to next item in list
  }
  return max->data; //returns value of data location of max
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the smallest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int smallestValue(LinkedList *list) {
  // Code may assume that these assertions are true;
  // so does not need to do error checking for these conditions.
  assert(list!=NULL);
  assert(list->head != NULL);
  
  Node * p = list->head; //allocate new node
  Node * min = new Node; //allocate new node that points to minimum value
  min = list->head; //data location of minimum value.  start with list->head in case it has the smallest value

  while(p){ // while p is not null
	if((p->data)<(min->data)) // if value at data location p is less than value at data location min
		min = p;
	 p=p->next;//p points to next item in list
  }
  return min->data; //returns value of data location of min
 }

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the sum of all values in the list.
// You may assume that list is not NULL
// However, the list may be empty (i.e. list->head may be NULL)
//  in which case your code should return 0.

int sum(LinkedList * list) {
  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.
  assert(list!=NULL);

  int sum=0;//initialize a int that will return the sum of the list
  Node * tmp = list->head;//allocate new node
  while(tmp){// while tmp is not equal to null
	sum += tmp->data; //add number at data location of tmp
	tmp = tmp->next;  //tmp points to next node in the list
  }
  //   sum of all values in list (0 if there are none).
  return sum;
}

