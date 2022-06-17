/*
 * recursive_list.h
 * 
 * A simple interface for a recursively defined list data structure.
 * 
 * INSTRUCTOR NOTE: THIS FILE IS INCLUDED AS PART OF YOUR STARTER CODE. DO NOT
 * MODIFY THIS FILE.
 */

#ifndef __RECURSIVE_LIST_H__
#define __RECURSIVE_LIST_H__

/*
 * A well-formed list is either:
 *   the empty list
 *   or an integer followed by a well-formed list.
 *
 * Lists are applicative (functional) data structures; in other words, they are
 * immutable.
 */

/*
 * We define lists using the following type declaration. Don't worry
 * if you don't understand what this syntax means. For the purposes of this
 * project, just assume that "RecursiveList" is the name of a type that you can
 * use just like "int" or "double".
 */

typedef void *RecursiveList;

// EFFECTS: returns true if list is empty, false otherwise
extern bool ListIsEmpty(RecursiveList list);

// EFFECTS: returns an empty list
RecursiveList MakeList();

// EFFECTS: given the list, make a new list consisting of the new element
//          followed by the elements of the original list
RecursiveList MakeList(int elem, RecursiveList list);

// REQUIRES: list is not empty
// EFFECTS: returns the first element of list
extern int ListFirst(RecursiveList list);

// REQUIRES: list is not empty
// EFFECTS: returns the list containing all but the first element of list
extern RecursiveList ListRest(RecursiveList list);

// MODIFIES: std::cout
// EFFECTS: prints list to std::cout
extern void PrintList(RecursiveList list);


#endif /* __RECURSIVE_H__ */
