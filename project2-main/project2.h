/*
 * project2.h
 * 
 * An interface for the functions that you will implement in Project 2.
 *
 * INSTRUCTOR NOTE: THIS FILE IS INCLUDED AS PART OF YOUR STARTER CODE. DO NOT
 * MODIFY THIS FILE.
 */

#ifndef __PROJECT2_H__
#define __PROJECT2_H__

#include "recursive_list.h"

// EFFECTS: returns the sum of each element in list, or zero if the list is
//          empty
int Sum(RecursiveList list);

// EFFECTS: returns the product of each element in list, or one if the list is
//          empty
int Product(RecursiveList list);

// EFFECTS: returns the sum of each element in list, or zero if the list is
//          empty
int TailRecursiveSum(RecursiveList list);

// EFFECTS: returns a new list containing only the elements of the original list
//          which are odd in value, in the order in which they appeared in list
// For example, FilterOdd(( 4 1 3 0 )) would return the list ( 1 3 )
RecursiveList FilterOdd(RecursiveList list);

// EFFECTS: returns a new list containing only the elements of the original list
//          which are even in value, in the order in which they appeared in list
// For example, FilterEven(( 4 1 3 0 )) would return the list ( 4 0 )
RecursiveList FilterEven(RecursiveList list);

// EFFECTS: returns the reverse of list
// For example, the reverse of ( 3 2 1 ) is ( 1 2 3 )
RecursiveList Reverse(RecursiveList list);

// EFFECTS: returns the list (first_list second_list)
// For example, if first_list is ( 1 2 3 ) and second_list is ( 4 5 6 ), then
// returns ( 1 2 3 4 5 6 )
RecursiveList Append(RecursiveList first_list, RecursiveList second_list);

// REQUIRES: list has at least n elements
// EFFECTS: returns the list equal to list without its last n elements
RecursiveList Chop(RecursiveList list, unsigned int n);

// EFFECTS: returns a list equal to the original list with the
//          first element moved to the end of the list n times.
// For example, Rotate(( 1, 2, 3, 4, 5), 2) yields ( 3, 4, 5, 1, 2 )
RecursiveList Rotate(RecursiveList list, unsigned int n);

// REQUIRES: n <= the number of elements in first_list
// EFFECTS: returns a list comprising the first n elements of first_list,
//          followed by all elements of second_list, followed by any remaining
//          elements of "first_list"
// For example, Insert (( 1 2 3 ), ( 4 5 6 ), 2) returns ( 1 2 4 5 6 3 )
RecursiveList InsertList(RecursiveList first_list, RecursiveList second_list,
                         unsigned int n);

#endif /* __PROJECT2_H__ */
