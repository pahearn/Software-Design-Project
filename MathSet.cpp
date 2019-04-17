#include "MathSet.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
		
int main(){
	MathSet<int> mySet;
	MathSet<int> odd;
	MathSet<int> even;
	MathSet<int> intersect;
	MathSet<int> unionSet;
	MathSet<double> evenDouble;
	MathSet<double> oddDouble;
	MathSet<double> unionDouble;
    MathSet<string> alphaSet;
    MathSet<string> vowelSet;
    MathSet<string> unionString;
    MathSet<string> intersectString;
	
	cout<<"Creation of sets for testing: \n"<<endl;
	for (int i = 0; i<10; i++){
		mySet.add(i);
	}
	cout<<"\n";
	for (int i = 1; i<10; i=i+2){
		odd.add(i);
	}
	cout<<"\n";
	for (int i = 0; i<10; i=i+2){
		even.add(i);
	}
	cout<<"\n";
	for (double i = 1; i<10; i=i+2){
		oddDouble.add(i);
	}
	cout<<"\n";
	for (double i = 0; i<10; i=i+2){
		evenDouble.add(i);
	}
	cout<<"\n";
	alphaSet.add("A");
	alphaSet.add("B");
	alphaSet.add("C");
	alphaSet.add("D");
	alphaSet.add("E");
	alphaSet.add("F");
	alphaSet.add("G");
	alphaSet.add("H");
	alphaSet.add("I");
	cout<<"\n";
	vowelSet.add("A");
	vowelSet.add("E");
	vowelSet.add("I");
	vowelSet.add("O");
	vowelSet.add("U");
	
	cout<<"\n";
	cout<<"Testing of Intersection:"<<endl;
	
	mySet.print();
	odd.print();
    cout<<"\nAdding intersection elements:"<<endl;
	intersect = mySet.intersectionOfTwoSets(odd);
	intersect.print();
	
	cout<<"\nTesting of Union:"<<endl;
	
	mySet.print();
	odd.print();
    cout<<"\nAdding union elements:"<<endl;
	unionSet = even.unionOfTwoSets(odd);
	unionSet.print();
	
	cout<<"\nTesting union with Doubles: "<<endl;

	evenDouble.print();
	oddDouble.print();
    cout<<"\nAdding union elements:"<<endl;
	unionDouble = evenDouble.unionOfTwoSets(oddDouble);
	unionDouble.print();

    cout<<"\nTesting union and intersection with string: "<<endl;
    cout<<"\nTesting intersection with string: "<<endl;
    
    alphaSet.print();
	vowelSet.print();
    cout<<"\nAdding intersecting elements:"<<endl;
	intersectString = alphaSet.intersectionOfTwoSets(vowelSet);
	intersectString.print();
	
	cout<<"\nTesting union with string: "<<endl;

	alphaSet.print();
	vowelSet.print();
    cout<<"\nAdding union elements:"<<endl;
	unionString = alphaSet.unionOfTwoSets(vowelSet);
	unionString.print();
    
}
	
