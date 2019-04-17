#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template <class T>
class MathSet{
	vector<T> set;
	
	
public:

	void add(T elementToAdd){
		if(find(set.begin(), set.end(), elementToAdd) != set.end()){ //if (element is in set)...
			cerr<<elementToAdd << " is already in the set."<<endl;
			return;
		} else { //element is not in set
			set.push_back(elementToAdd);
			cout<<elementToAdd << " was added to the set." <<endl;
		}
		return;
	}
/*
NAME
	MathSet::add - adds a new element to the set
SYNOPSIS
	void MathSet::add(T elementToAdd)
	
	elementToAdd - the element of type T that will be added to the end of the set
DESCRIPTION
	The function receives an element that is to be added to the set.  If the element is already present in
	the set, it will not be added as sets do not contain duplicates.  If the element was not present in
	the set, it will be added to the end of the set and a confirmation message is printed.
RETURNS
	N/A	
*/
	
	
	void removeByValue(T elementToRemove){
		if (sizeOfSet() == 0){
			cerr<<"Set is empty: no element was removed."<<endl;
			return;
		}
		
		if(find(set.begin(), set.end(), elementToRemove) != set.end()){ //if (element is in set)...
			set.erase(remove(set.begin(), set.end(), elementToRemove), set.end());
			cout<<elementToRemove<< " was removed from the set"<<endl;
		}else { //element is not in set
			cerr<<"Element: " << elementToRemove <<" does not exist in the set."<<endl;
		}
	}
/*
NAME
	MathSet::removeByValue - removes a value from the set
SYNOPSIS
	void MathSet::removeByValue(T elementToRemove)
	
	elementToRemove - the element of type T that will be removed from the set
DESCRIPTION
	The function receives an element that is to be removed from the set.  If the set is empty, the 
	function will return. If the element is not presentin the set, the function will return.If the 
	element is in the set, it will be removed and a confirmation message is printed. 
RETURNS
	N/A	
*/
	
	void removeByPosition(int position){
		if (sizeOfSet() == 0){
			cerr<<"Set is empty: no element was removed"<<endl;
			return;
		}
		
		if (position >= sizeOfSet()|| position<0){
			cerr<<"Specified position does not exist in the set"<<endl;
			return;
		}
		
		set.erase(set.begin()+position);
		cout<<"Element " << position << " was removed from the set"<<endl;
	}
/*
NAME
	MathSet::removeByPosition - removes the element at a specific position
SYNOPSIS
	void MathSet::removeByPosition(int position)
	
	position - the integer position of the element that is to be removed
DESCRIPTION
	The function receives an integer value and removes the element at the specified position. If the set 
	is empty, the function will exit and the user is notified. If the specific position is a negative number or larger than the
	size of the set, an error occurs and nothing is removed. If no error has occurred, the element at the
	specific position is removed and a confirmation message is printed.
RETURNS
	N/A	
*/
	
	int sizeOfSet(){
		return set.size(); //returns the number of elements in the ADT
	}
/*
NAME
	MathSet::sizeOfSet - returns the size of the set
SYNOPSIS
	int MathSet::sizeOfSet()
DESCRIPTION
	The function returns the integer size of the set.
RETURNS
	The size of the set as an integer.	
*/
	
	void elementExists(T elementToCheck){
		if(find(set.begin(), set.end(), elementToCheck) != set.end()){ //if (element is in set)...
			cout<< elementToCheck<< " is in the set." <<endl;
		}else { //element is not in set
			cout<< elementToCheck<< " is not in the set." <<endl;
		}
	}
	
/*
NAME
	MathSet::elementExists - states if an item exists in the set
SYNOPSIS
	void MathSet::elementExists(T elementToCheck))
	
	elementToCheck - the element of type T that 
DESCRIPTION
	Receives an element of type T and checks if it is located in the set. If it is found, it prints to
	the user that it is found.  If it is not found, it prints to the user that it is not found.
RETURNS
	N/A	
*/
	
	void print(){
		for(int i=0; i<sizeOfSet(); i++){
			cout<<set[i]<<" ";
		}
		cout<<endl;
	}
	
/*
NAME
	MathSet::print - displays the contents of the set
SYNOPSIS
	void MathSet::print()
DESCRIPTION
	Prints out the contents of the set, separated by spaces.
RETURNS
	N/A	
*/
	
	void emptySet(){
		set.clear();	
	}
/*
NAME
	MathSet::emptySet - clears all elements from the set
SYNOPSIS
	void MathSet::emptySet()
DESCRIPTION
	Clears all elements from the set, leaving the set empty.
RETURNS
	N/A	
*/
	
    T getValue(int position){
        if (sizeOfSet() == 0){
			cerr<<"Set is empty"<<endl;
			exit;
		}
		
		if (position >= sizeOfSet()|| position<0){
			cerr<<"Specified position does not exist in the set"<<endl;
			exit;
		}
		
		return set[position];
    }
/*
NAME
	MathSet::getValue- returns the value of the element located at the position
SYNOPSIS
	T MathSet::getValue(int position)
	
	position - the integer position of the element that will have it's value returned
DESCRIPTION
	The function receives an integer value and returns the value of the element at that position.
	If the set is empty, the function will exit and the user is notified. If the specific position is a negative number 
	or larger than the size of the set, the user is notified and nothing is returned. If no error occurs,
	the function returns the value at that location.
RETURNS
	The value at the specified location in the set.	
*/
    
	MathSet<T> unionOfTwoSets(MathSet<T> setA){
		MathSet<T> unionSet;
		for(int i=0; i<sizeOfSet(); i++){
			unionSet.add(set[i]);
		}
		
		for(int i=0; i<setA.sizeOfSet(); i++){
			unionSet.add(setA.getValue(i));
		}
		
		return unionSet;
	}
/*
NAME
	MathSet::unionOfTwoSets- receives one set and returns the mathematical union of the inputted set and the object
SYNOPSIS
	MathSet<T> MathSet::unionOfTwoSets(MathSet<T> setA)
	
	setA - The inputted set that will form a union
	unionSet - The set containing the union of the object's set and setA
DESCRIPTION
	The function receives one set and returns a set that contains every element from each of the two sets.
	The function first iterates through the object's set and adds all of its elements to unionSet, it then iterates
	through setA and adds all of setA's elements to unionSet.  If there are duplicate elements, they will be
	handled in the MathSet::add function.  The object and setB's contents will not be directly changed by this function.
RETURNS
	A set containing the union of the object and setB's elements 	
*/
	
	MathSet<T> intersectionOfTwoSets(MathSet<T> setA){
		MathSet<T> intersectSet;
		for(int i=0; i<sizeOfSet(); i++){
			for(int j=0; j<setA.sizeOfSet();j++){
				if(set[i] == setA.getValue(j)){
					intersectSet.add(set[i]);
				}
			}
		}
		return intersectSet;
	}
};

/*
NAME
	MathSet::intersectionOfTwoSets- receives one set and returns the mathematical intersection of the inputted set and the object
SYNOPSIS
	MathSet<T> MathSet::intersectionOfTwoSets(MathSet<T> setA)
	
	setA - The inputted set that will form an intersection
	intersectSet - The set containing the intersection of setA and setB
DESCRIPTION
	The function receives one set and returns a set containing the shared elements between the object's set and setA.
	The function uses nested for loops to compare each element of the object's set and setA, if there is a shared element,
	it will be added to the intersection set.  After each element has been compared, the intersection set is returned.
RETURNS
	A set containing the intersection of the object and setB's elements 	
*/