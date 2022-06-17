/*
 * project2.cpp
 * 
 * The implementation file where you will implement your code for Project 2.
 *
 * INSTRUCTOR NOTE: Do not change any of the existing function signatures in
 * this file. You may add helper functions for 
 * any function other than Sum in Question 1. 
 */

#include "recursive_list.h"
#include "project2.h"
#include "iostream"
using namespace std;

/** QUESTION 1: SUM AND PRODUCT **/

// EFFECTS: returns the sum of each element in list, or zero if the list is
//          empty
// Your implementation of Sum should NOT be tail recursive and should NOT
// use a helper function. 
//
/* PSEUDOCODE:

	if list empty
		return 0
	n = space before start of list
	list sum = rest of the list
	Create list starting from n, with rest of the list
	
	return fun(sum) + (n + 1)
	
 COMMENTS:

Begin with if statement to establish the base case, being an empty list.
If this is the case then 0 is returned because there is nothing in the list

Then n is defined at the space before start of list to recursively move through the list.
Artithmatic process is taking the sum of the rest of the list, added to the next elem in the list.
The list sum is defined as the rest of the list to recursively move through the list.
List is created with starting elem n, and sum as the list

The return is the recursive call to Sum(sum), the function Sum with argument recursivelist sum plus n + 1
This recursive call allows the fucntion to move through the rest of the list, starting at n, to find the sum of the list.
Each time the fucntion runs, the value of n changes, causing the program to unwind a stack to the base case of being empty.
	
*/
int Sum(RecursiveList list) {
  // Implement this function.
	
	if (ListIsEmpty(list) == true)
        {
                return 0;
        }

        int n = ListFirst(list) - 1;
        RecursiveList sum = ListRest(list);
        MakeList(n, sum);

        return Sum(sum) +( n + 1);
     		
}
/*
EFFECTS: returns the product of each element in list, or one if the list is
          empty

 PSEUDOCODE:
 algorithm Product
  
	if list empty
		return 1
	n = space before start of list
	list fact = rest of the list
	Create list starting from n, with rest of the list
	
	return fun(fact) * (n + 1)

 COMMENTS:
Begin with if statement to establish the base case, being an empty list.
If this is the case then 1 is returned because there is nothing in the list

Then n is defined at the space before start of list to recursively move through the list.
The list fact is defined as the rest of the list to recursively move through the list.
List is created with starting elem n, and fact as the list

The return is the recursive call to Product(fact), the function Product with argument recursivelist fact multiplied by n + 1
Artithmatic process is taking the product of the rest of the list, multiplied by the next elem in the list.
This recursive call allows the function to move through the rest of the list, starting at n, to find the fact of the list.
Each time the fucntion runs, the value of n changes, causing the program to unwind a stack to the base case of being empty.
*/
int Product(RecursiveList list) {
  // Implement this function.
	  
 	if (ListIsEmpty(list) == true)
	{
		return 1;
	}

	int n = ListFirst(list) - 1;
        RecursiveList fact = ListRest(list);
        MakeList(n, fact);

	
	//return  Product()*( 1 + ListFirst(list));
	return Product(fact) *( n + 1);

}


/** QUESTION 2: TAIL RECURSIVE SUM **/
/*
 EFFECTS: adds the next element in the list to the sum so far
 Your implementation of TailRecursiveSumHelper MUST be tail recursive.

 PSEUDOCODE:

	if list empty
		return sum_so_far
	n = space before start of list
	list sum = rest of the list
	Create list starting from n, with rest of the list
	
	return fun(sum, n + (sum_so_far));


 COMMENTS:

Begin with if statement to establish the base case, being an empty list.
If this is the case then 0 is returned because there is nothing in the list

Then n is defined at the space before start of list to recursively move through the list.
Artithmatic process is taking the sum of the rest of the list, added to the next elem in the list.
The list sum is defined as the rest of the list to recursively move through the list.
List is created with starting elem n, and sum as the list

Then return the recursive call to the function with recursive list sum followed by n plus sum_so_far.
This recursive call allows the function to move through the rest of the list, starting at n, to find the sum of the list.
Each time the fucntion runs, the value of n changes, causing the program to unwind a stack to the base case of being empty.

Now that this function loads the sum of a given list, it can be called elsewhere to be used.
This allows use of additional parameters in the computation of the sum. 


*/

int TailRecursiveSumHelper(RecursiveList list, int sum_so_far) {
  // Implement this function.

   if (ListIsEmpty(list) == true)
        {
                return sum_so_far;
        }

   	int n = ListFirst(list) - 1;
        RecursiveList sum = ListRest(list);
        MakeList(n, sum);
	
	 
	return TailRecursiveSumHelper(sum, n + (sum_so_far + 1));
                        
}

// EFFECTS: returns the sum of each element in list, or zero if the list is
//          empty
// THIS FUNCTION IS PROVIDED AS PART OF THE STARTER CODE.
// DO NOT MODIFY THIS FUNCTION.
// 
// PSEUDOCODE:
// algorithm TailRecursiveSum
//   return TailRecursiveSumHelper(list, 0)
int TailRecursiveSum(RecursiveList list) {
  return TailRecursiveSumHelper(list, 0);
}


/** QUESTION 3: FILTER ODD AND FILTER EVEN **/

// EFFECTS: returns a new list containing only the elements of the original list
//          which are odd in value, in the order in which they appeared in list
// For example, FilterOdd(( 4 1 3 0 )) would return the list ( 1 3 )
//
// PSEUDOCODE:
// algorithm FilterOdd
//   Your pseudocode goes here. You do not need to define inputs, outputs, or
//   side effects, since the requires, modifies, and effects statements are
//   already provided above.
//
// COMMENTS:
// Add comments here that might help us to understand your thought process,
// especially if you're unable to finish the pseudocode or code. This can help
// us award points in the code logic category.




RecursiveList FilterOdd(RecursiveList list) {
  // Implement this function.
	RecursiveList odd;
	int n = 0;	
	//PrintList(list);
	if (ListIsEmpty(list) == true)
	{
		return MakeList();
	} 
	else if( ListFirst(list) != 1 && ListFirst(list) %2 == 0)
	{
		return FilterOdd(ListRest(list));
	}
	
	
	//ListFirst(list) == ListFirst(odd);
	odd = MakeList(ListFirst(list), MakeList());	
	//ListFirst(odd) == ListFirst(list);
	list = ListRest(list);
	odd = MakeList(ListFirst(odd), ListRest(odd));
	PrintList(odd);	
	return FilterOdd(list);
}

// EFFECTS: returns a new list containing only the elements of the original list
//          which are even in value, in the order in which they appeared in list
// For example, FilterEven(( 4 1 3 0 )) would return the list ( 4 0 )
//
// PSEUDOCODE:
// algorithm FilterEven
//   Your pseudocode goes here. You do not need to define inputs, outputs, or
//   side effects, since the requires, modifies, and effects statements are
//   already provided above.
//
// COMMENTS:
// Add comments here that might help us to understand your thought process,
// especially if you're unable to finish the pseudocode or code. This can help
// us award points in the code logic category.
RecursiveList FilterEven(RecursiveList list) {
  // Implement this function.
  return list;
}


/** QUESTION 4: REVERSE **/

// EFFECTS: returns the reverse of list
// For example, the reverse of ( 3 2 1 ) is ( 1 2 3 )
//
// PSEUDOCODE:
// algorithm Reverse
//   Your pseudocode goes here. You do not need to define inputs, outputs, or
//   side effects, since the requires, modifies, and effects statements are
//   already provided above.
//
// COMMENTS:
// Add comments here that might help us to understand your thought process,
// especially if you're unable to finish the pseudocode or code. This can help
// us award points in the code logic category.
RecursiveList Reverse(RecursiveList list) {
  // Implement this function.
  return list;
}


/** QUESTION 5: APPEND **/

// EFFECTS: returns the list (first_list second_list)
// For example, if first_list is ( 1 2 3 ) and second_list is ( 4 5 6 ), then
// returns ( 1 2 3 4 5 6 )
//
// PSEUDOCODE:
// algorithm Append
//   Your pseudocode goes here. You do not need to define inputs, outputs, or
//   side effects, since the requires, modifies, and effects statements are
//   already provided above.
//
// COMMENTS:
// Add comments here that might help us to understand your thought process,
// especially if you're unable to finish the pseudocode or code. This can help
// us award points in the code logic category.
RecursiveList Append(RecursiveList first_list, RecursiveList second_list) {
  // Implement this function.
  return first_list;
}


/** QUESTION 6: CHOP **/

// REQUIRES: list has at least n elements
// EFFECTS: returns the list equal to list without its last n elements
//
// PSEUDOCODE:
// algorithm Chop
//   Your pseudocode goes here. You do not need to define inputs, outputs, or
//   side effects, since the requires, modifies, and effects statements are
//   already provided above.
//
// COMMENTS:
// Add comments here that might help us to understand your thought process,
// especially if you're unable to finish the pseudocode or code. This can help
// us award points in the code logic category.
RecursiveList Chop(RecursiveList list, unsigned int n) {
  // Implement this function.
  return list;
}


/** QUESTION 7: ROTATE **/

// EFFECTS: returns a list equal to the original list with the
//          first element moved to the end of the list n times.
// For example, Rotate(( 1 2 3 4 5 ), 2) yields ( 3 4 5 1 2 )
//
// PSEUDOCODE:
// algorithm Rotate
//   Your pseudocode goes here. You do not need to define inputs, outputs, or
//   side effects, since the requires, modifies, and effects statements are
//   already provided above.
//
// COMMENTS:
// Add comments here that might help us to understand your thought process,
// especially if you're unable to finish the pseudocode or code. This can help
// us award points in the code logic category.
RecursiveList Rotate(RecursiveList list, unsigned int n) {
  // Implement this function.
  return list;
}


/** QUESTION 8: INSERT LIST **/

// REQUIRES: n <= the number of elements in first_list
// EFFECTS: returns a list comprising the first n elements of first_list,
//          followed by all elements of second_list, followed by any remaining
//          elements of "first_list"
// For example, InsertList (( 1 2 3 ), ( 4 5 6 ), 2) returns ( 1 2 4 5 6 3 )
//
// PSEUDOCODE:
// algorithm InsertList
//   Your pseudocode goes here. You do not need to define inputs, outputs, or
//   side effects, since the requires, modifies, and effects statements are
//   already provided above.
//
// COMMENTS:
// Add comments here that might help us to understand your thought process,
// especially if you're unable to finish the pseudocode or code. This can help
// us award points in the code logic category.
RecursiveList InsertList(RecursiveList first_list, RecursiveList second_list,
                         unsigned int n) {
  // Implement this function.
  return first_list;
}
