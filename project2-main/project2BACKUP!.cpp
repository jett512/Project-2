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
	
	if (ListIsEmpty(list) == true)//establish base case
        {
                return 0;//there is nothing in the list
        }

        int n = ListFirst(list) - 1;//space before start of list
        RecursiveList sum = ListRest(list);//move to next elem
        MakeList(n, sum);//new list from n with recursive list sum

        return Sum(sum) +( n + 1);//Build on and break down recursively
     		
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
	  
 	if (ListIsEmpty(list) == true)//establish base case
	{
		return 1;//there is nothing in the list
	}

	int n = ListFirst(list) - 1;//space before start of list
        RecursiveList fact = ListRest(list);//move to next elem
        MakeList(n, fact);//new list from n with recursive list fact

	return Product(fact) *( n + 1);//Build on and break down recursively

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

   if (ListIsEmpty(list) == true)//base case
        {
                return sum_so_far;//nothing in the list
        }

   	int n = ListFirst(list) - 1;// the space before start of list
        RecursiveList sum = ListRest(list);//defined as the rest of the list
        MakeList(n, sum);
	
	 
	return TailRecursiveSumHelper(sum, n + (sum_so_far + 1));//build on and break down recursively
                        
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
/*
 EFFECTS: returns a new list containing only the elements of the original list
          which are odd in value, in the order in which they appeared in list
 For example, FilterOdd(( 4 1 3 0 )) would return the list ( 1 3 )

 PSEUDOCODE:
 algorithm FilterOdd

	deifine odd
	if list empty
		return null
	else if (list1st != 1 and list1St mod2 equals 0)
		return FilterOdd(rest of list)

	odd = new list from list1st to null 
	list = rest of list   
	odd = new list from 1st odd to rest of odd
	print odd
	return FilterOdd(list)

 COMMENTS:
	
Begin by defining a recursive list odd, that will be used later in the function. 
This list is only declared here because it will be modified only if later conditions are satisfied.

If statement that runs provided function to check if list is empty, if so nothing is returned.
Here the base case if defined to end the recursion when the list is empty.

Else if Statement checks if the first elem in list is a not equal to 1 and first elem mod2 equals 0.
This statment is what decides if the first elem in list is odd or even, if the statement is true the element is even,
so the rest of the list is returned.

If niether condition is true, the 1st element is odd
Then a new list is made from the 1st element to null, which is set equal to the recursive list odd. 
List is set equal to the rest of the list to continue searching the list.
Odd is then set equal to a new list from 1st element of odd to the rest of odd.'
Finally, the recursive call is made with list being returned to the function to filter out all odd elements. 
	
*/

RecursiveList FilterOdd(RecursiveList list) {
  // Implement this function.
	RecursiveList odd;
	if (ListIsEmpty(list) == true)//base case
	{
		return MakeList();//nothing in the list
	} 
	else if( ListFirst(list) != 1 && ListFirst(list) %2 == 0)//check if even
	{
		return FilterOdd(ListRest(list));//return rest of list
	}
	//must be odd
	odd = MakeList(ListFirst(list), MakeList());//create new list	
	list = ListRest(list);
	odd = MakeList(ListFirst(odd), ListRest(odd));//update list
	PrintList(odd);	
	return FilterOdd(list);//break down recursively
}

/*
 EFFECTS: returns a new list containing only the elements of the original list
          which are even in value, in the order in which they appeared in list
 For example, FilterEven(( 4 1 3 0 )) would return the list ( 4 0 )

 PSEUDOCODE:
 algorithm FilterEven
  
	deifine even
	if list empty
		return null
	else if (list1st != 0 and list1St mod2 equals 1)
		return FilterEven(rest of list)

	even = new list from list1st to null 
	list = rest of list   
	even = new list from 1st even to rest of even
	print even
	return FilterEven(list)

 COMMENTS:

Begin by defining a recursive list even, that will be used later in the function. 
This list is only declared here because it will be modified only if later conditions are satisfied.

If statement that runs provided function to check if list is empty, if so nothing is returned.
Here the base case if defined to end the recursion when the list is empty.

Else if Statement checks if the first elem in list is a not equal to 0 and first elem mod2 equals 1.
This statment is what decides if the first elem in list is odd or even, if the statement is true the element is odd,
so the rest of the list is returned to the function.

If niether condition is true, the 1st element is even.
Then a new list is made from the 1st element to null, which is set equal to the recursive list even. 
List is set equal to the rest of the list to continue searching the list.
Even is then set equal to a new list from 1st element of even to the rest of even.
Finally, the recursive call is made with list being returned to the function to filter out all even elements.  

*/

RecursiveList FilterEven(RecursiveList list) {
  // Implement this function.
	
	RecursiveList even;
	if (ListIsEmpty(list) == true)//base case
	{
		return MakeList();//list is empty
	} 
	else if( ListFirst(list) != 0 && ListFirst(list) %2 == 1)//check if odd
	{
		return FilterEven(ListRest(list));//return rest of list
	}
	
	even = MakeList(ListFirst(list), MakeList());//create new list	
	list = ListRest(list);
	even = MakeList(ListFirst(even), ListRest(even));//update list
	PrintList(even);	
	return FilterEven(list);//break down recursively

}


/** QUESTION 4: REVERSE **/
/*
 EFFECTS: returns the reverse of list
 For example, the reverse of ( 3 2 1 ) is ( 1 2 3 )

 PSEUDOCODE:
 algorithm Reverse
   
	Helper(list, reversed list)
		if list empty
			return reversed list
		if list rest empty
			return makelist(list1st(list), reversed list)
		reversed list = makelist(list1st(list), reversed list)
		return Helper(ListRest(list), reversed list
	
	Reverse(list)
		RecursiveList rev = empty list
        return ReverseHelper(list, reversed list)

 COMMENTS:
	
A helper function is created to add another recursive list parameter to the reverse function.
This allows for the new reversed version of the list to be stored in a list.

Check if list empty, if so return the reversed list as the base case. 
If list is empty there is nothing to reverse.

Check if the rest of the list is empty. This means that the current list first is the final elem in the list.
Condition is true and a list is made with Listfirst to start followed by reversed list.
This displays a list with the final elem at the front followed by the reversed list.

If niether if statements are true, then a list is made with Listfirst to start followed by reversed list.
This is set equal to the reversed list. 
The recursive call is made to break down the original list and return the reversed list to the function. 

Then the reverse function is called
This function defines the list reverse list and sets it to empty.
I will fill the reverse list in the helper function with the list in reversed order.
The helper function is called with parameters list and reversed list, and will return the final product. 

*/

RecursiveList ReverseHelper(RecursiveList list, RecursiveList rev){ //added for additional param rev

	if(ListIsEmpty(list) == true)//Check if list empty
        {
                return rev;//base case
        }

        if(ListIsEmpty(ListRest(list)) == true)//current list first is the final elem in the list.
        {
 
                //cout << ListFirst(list);
                return MakeList(ListFirst(list), rev);//final elem of list at front followed by reversed list.
	}
 
        
        rev = MakeList(ListFirst(list), rev);//final elem of list at front followed by reversed list.
	
	//PrintList(list);	
        return ReverseHelper(ListRest(list), rev);//Recursive call to break down list
}

RecursiveList Reverse(RecursiveList list) {
  // Implement this function.
	//PrintList(list);

	RecursiveList rev = MakeList();//defines the list reverse list and sets it to empty.
        return ReverseHelper(list, rev);//helper called with extra param, generates final solution
      
}


/** QUESTION 5: APPEND **/
/*
 EFFECTS: returns the list (first_list second_list)
 For example, if first_list is ( 1 2 3 ) and second_list is ( 4 5 6 ), then
 returns ( 1 2 3 4 5 6 )

 PSEUDOCODE:
 algorithm Append
  
	if first list empty
		first list equal second list
		return first list
	else if second list rest empty
		second list equal first list
		return second list
	else if first list rest empty
		first list = new list( first elem first list, second list)
		return first list
	n equals first elem in first list
	return function(listrest(first list), newlist(n, secondlist)

 COMMENTS:
 
Check if first list empty, if so return then set first list as second.
return the first list as the base case.
Check if the rest of the second list is empty. This means that the current list first is the final elem in the list.
then set second list equal to the first.
Check if the rest of the first list is empty. This means that the current list first is the final elem in the list.
then set first list as second.

If outside of if statements both lists are not empty and have more than 1 elem in them each.
define n as the first elem in the first list. helps keep track of the first elem in first list.
Recursively call the append function with parameters rest of first list, new list starting with n, followed by second, list.
This recursive call allows the second list to have elem from the first list added to it each time,
While also perserving the order of the second list. 

*/
RecursiveList Append(RecursiveList first_list, RecursiveList second_list) {
  // Implement this function.
	
	 if( ListIsEmpty(first_list) == true)//Check if list empty
	{	
		first_list = second_list;//set first list as second
		return first_list;//base case	
	}
	else if( ListIsEmpty(second_list) == true)//current list first is the final elem in the second_list.
	{
		second_list = first_list;//set first list as second	
		return second_list;//other base case
	}
	else if(ListIsEmpty(ListRest(first_list)) == true)//current list first is the final elem in the first_list.
	{
		first_list = MakeList(ListFirst(first_list), second_list);//first elem first_list, followed by second list
		return first_list;
	} 
	
		int n = ListFirst(first_list);//variable to keep track of first elem in first_list	
		return Append(ListRest(first_list),MakeList(n, second_list));//recurisve call to break down list
}




/** QUESTION 6: CHOP **/
/*

 REQUIRES: list has at least n elements
 EFFECTS: returns the list equal to list without its last n elements

 PSEUDOCODE:
 algorithm Chop
   
	Helperfunction(list, listchop, number of elem to chop)
		if list empty or number of elem to chop = 0
			return listchop
		if list rest empty
			return makelist(list1st(list), reversed listchop)
		listchop = revered list
		listchop = NewList(1st elem of reversed list, rest = reversed listchop
		return helper(listrest(list), listchop, elem to chop -1)
	
	Chopfunction(list, n)
		if list empty or number of elem to chop = 0
			return list
		define listchop as empty list
		return helperfunction(reversed list, listchop, elem to chop +1)

 COMMENTS:
The main chop function checks if list is empty or if number of elem to chop equals 0, if so return the list as the base case. 
If list is empty there is nothing to chop or n = 0, there is nothing to chop. return the unmodified list.

Define list chop as an empty list that will be filled by the helper function.
Make recursive call to helper function with parameters reversed list, chopped list, and n + 1.
Must return the reversed list to the helper function to delete elements from the back of the list, and not the front.
Also must return n + 1 to correct for the extra time that the function must run to produce the correct answer. 

A helper function is created to add another recursive list parameter to the chop function.
This allows for the new chopped version of the list to be stored in a list.
n, or the number of elements to be chopped is also brought to helper function, but as n + 1(explained above).

Check if list empty or if number of elem to chop equals 0, if so return the chopped list as the base case. 
If list is empty there is nothing to chop. 
If at any point n equals 0 the function must end regardless if inside the helper or main chop function.
	
Check if the rest of the list is empty. This means that the current list first is the final elem in the list.
Condition is true and a list is made with Listfirst to start followed by chopped list.
This displays a list with the final elem at the front followed by the chopped list.

Beyond the two if statements means that we arent done chopping elements.
Here is a walkthrough of the logic for n = 1.
Set the chopped list to the original list reversed twice, so it equals the orignal list(1 2 3 4 5)
Then set chop equal to a new list with the first elem being the first elem in the reversed list. (1)
This is then followed by the rest of the chopped list previusly defined. (2 3 4 5).
After that, chop = ( 1 2 3 4 5)
Make the recursive call to the helper function that returns listrest=(4 3 2 1), chop= (2 3 4 5), and n as 1
Since n!=0 and ListRest != empty repeat the process again.
n - 1 is used to break down the number of elements that must be chopped each time.
Set the chopped list to the original list reversed twice, so the list (1 2 3 4) bc we returned the rest of the list.
This is then followed by the rest of the chopped list previusly defined. (2 3 4).
After that, chop = ( 1 2 3 4)
Now back to the return function, where we return listrest=( 3 2 1), chop= (1 2 3 4), and n as 0
Since n =0 the function returns chop to the main chop function.
Then the output for ( 1 2 3 4 5) n = 1 is (1 2 3 4).
 



*/

RecursiveList ChopHelper(RecursiveList list, RecursiveList chop, unsigned int n){
	
	if(ListIsEmpty(list) == true || n == 0)//Check if list empty or nothing to chop
        {
                return chop;//base case
        }
        if(ListIsEmpty(ListRest(list)) == true)//current list first is the final elem in the list.
        {
                 return MakeList(ListFirst(list), Reverse(chop));//final elem of list at front followed by reversed chopped list.      
        }
	//not done chopping
	chop = Reverse(list);//( 1 2 3 4 5)
	chop = MakeList(ListFirst(Reverse(list)), ListRest(chop));// ( 1, 2 3 4 5)
	return ChopHelper(ListRest(list), chop, n-1);//( 4 3 2 1), ( 1 2 3 4 5), 1 

}

RecursiveList Chop(RecursiveList list, unsigned int n) {
  // Implement this function

	if(ListIsEmpty(list) == true || n == 0)//Check if list empty or nothing to chop
        {
                return list;//base case
        }
		
	RecursiveList chop = MakeList();//defines the list chop list and sets it to empty.	
	return ChopHelper(Reverse(list), chop, n + 1);//helper called with extra param, generates final solution
}





/** QUESTION 7: ROTATE **/
/*
EFFECTS: returns a list equal to the original list with the
first element moved to the end of the list n times.
 For example, Rotate(( 1 2 3 4 5 ), 2) yields ( 3 4 5 1 2 )

 PSEUDOCODE:
 algorithm Rotate

	Helperfunction(list, list rotate, number of rotations)
		if list empty or number of elem to rotate = 0
			return rotate
		if list rest empty
			return makelist(list1st(list), rotate)
		else if( number of rotations > n)
			rotate = new list( listfirst(reversed list), reverse(listrest(rotate)))
			return HelperFunction(list, reverse(rotate), n - 1
		rotate = new list( listfirst(reversed list), reverse(listrest(rotate)))
			return HelperFunction(list, reverse(rotate), n - 1
	
	Rotatefunction(list number of rotations)
		if list empty or number of elem to rotate = 0
			return list
	define list rotate as empty list
		return helperfunction(reversed list, list rotate, elem to rotate)

 COMMENTS:
 
The main rotate function checks if list is empty or if number of elem to rotate equals 0, if so return the list as the base case. 
If list is empty there is nothing to rotate or n = 0, there is nothing to rotate. return the unmodified list.
Define list rotate as an empty list that will be filled by the helper function.
Then set rotate equal to list ( 1 2 3 4 5), for use in the helper function.,
Make recursive call to helper function with parameters reversed list, rotated list list, and number od rotations to make.
Must return the reversed list to the helper function to delete elements from the back of the list, and not the front.

A helper function is created to add another recursive list parameter to the rotate function.
This allows for the new rotated version of the list to be stored in a list.
n, or the number of elements to be rotated is also brought to helper function to keep track of total rotations.
Check if list empty or if number of elem to rotate equals 0, if so return the rotated list as the base case. 
If list is empty there is nothing to rotate. 
If at any point n equals 0 the function must end regardless if inside the helper or main rotate function.
Check if the rest of the list is empty. This means that the current list first is the final elem in the list.
Condition is true and a list is made with Listfirst to start followed by rotated list.
This displays a list with the final elem at the front followed by the rotated list.

example for n = 1
list = ( 5 4 3 2 1), rotate = (1 2 3 4 5)
Then set rotate equal to a new list with the first elem being the first elem in the reversed list. (1)
This is then followed by the rest of the reversed rotate list previously defined. (5 4 3 2).
Then return the helper function with parameters list( 5 4 3 2 1), reversed rotate list( 5 4 3 2), n = 1
This outputs ( 1 5 4 3 2), when whgen reversed is ( 2 3 4 5 1), as desired.

*/

RecursiveList RotateHelper(RecursiveList list, RecursiveList rot, unsigned int n){
	//cout << n << "->";
	
	if(ListIsEmpty(list) == true || n == 0)//Check if list empty or nothing to rotate
        {
                return rot;//base case
        }

        if(ListIsEmpty(ListRest(list)) == true)//current list first is the final elem in the list.
        {
                
                 return MakeList(ListFirst(list), rot);//final elem of list at front followed by rotated list.      
		        
        }	

	//rot = Reverse(list);
        rot = MakeList(ListFirst(Reverse(list)), Reverse(ListRest(rot)));// set rot to (2 3 4 5) for n = 1 
	return RotateHelper(list, Reverse(rot), n - 1);//sends (5 4 3 2 1), ( 5 4 3 2), 0 ack to function
}

RecursiveList Rotate(RecursiveList list, unsigned int n) {
  // Implement this function.

	if(ListIsEmpty(list) == true || n == 0)//Check if list empty or nothing to rotate
        {
                return list;//base case
        }
	

	RecursiveList rot = MakeList();//defines the list rotate list and sets it to empty.
	rot = list;//rotate equals list because it will have the same number of total elem
  	return  RotateHelper(Reverse(list), rot, n);//helper called with extra param, generates final solution
}


/** QUESTION 8: INSERT LIST **/
/*
 REQUIRES: n <= the number of elements in first_list
 EFFECTS: returns a list comprising the first n elements of first_list,
          followed by all elements of second_list, followed by any remaining
          elements of "first_list"
 For example, InsertList (( 1 2 3 ), ( 4 5 6 ), 2) returns ( 1 2 4 5 6 3 )

 PSEUDOCODE:
 	if first list empty
		first list equal second list
		return first list
	else if second list rest empty
		second list equal first list
		return second list
	else if first list rest empty
		first list = new list( first elem first list, second list)
		return first list

 COMMENTS:

Check if first list empty, if so return then set first list as second.
return the first list as the base case.
Check if the rest of the second list is empty. This means that the current list first is the final elem in the list.
then set second list equal to the first.
Check if the rest of the first list is empty. This means that the current list first is the final elem in the list.
then set first list as second.

If outside of if statements both lists are not empty and have more than 1 elem in them each.
*/

RecursiveList InsertList(RecursiveList first_list, RecursiveList second_list,
                         unsigned int n) {
  // Implement this function.

	if( ListIsEmpty(first_list) == true)//Check if list empty
	{	
		first_list = second_list;//set first list as second
		return first_list;//base case	
	}
	else if( ListIsEmpty(second_list) == true)//current list first is the final elem in the second_list.
	{
		second_list = first_list;//set first list as second	
		return second_list;//other base case
	}
	else if(ListIsEmpty(ListRest(first_list)) == true)//current list first is the final elem in the first_list.
	{
		first_list = MakeList(ListFirst(first_list), second_list);//first elem first_list, followed by second list
		return first_list;
	} 

  return first_list;
}
