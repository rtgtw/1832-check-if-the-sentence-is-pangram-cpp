/*
1832. Check if the sentence is a pangram

A pangram is when all 26 letters in the alphabet are used at least once

Given a string sentence containing only lowercase English letters, return true if the sentence is a pangram, or false otherwise.



Example 1:

Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.



For this problem, all of the inputs are already lowercase and they are all alphabets

to solve this, we can use a set

A set is perfect here since a set contains all unique elements
with that in mind, when we iterate through sentence and place them within the set
all we have to do to solve this problem is check if set is = 26, 
this represents the 26 letters in the alphabet

Since we are not receiving Upper case or Other elements besides lowercase numbers
this is all we have to do, however what if we did?

the ctype.h library has 2 functions to help us out here
	isalpha - boolean value that determines if the element is an alpahbet or not (A or a)
	tolower - this turns any uppercase letter to lowercase, which brings us back to our base case

we can use an if statement to work with only alphabets and tolower to convert them all to lowercase


//This really showcases the power of a set and how it can be used as a data structure to
//determine if n elements are within a list programatically 

*/


#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
public:
	bool checkIfPangram(std::string sentence);

};

bool Solution::checkIfPangram(std::string sentence) {

	//Since our input has already been given to us as lowercase, the first step
	//is to create an empty set which we will include each element from sentence

	std::unordered_set<int> seen_set;

	//Create a for loop that iterates through sentence and places each element into set
	for (int i = 0; i < sentence.size(); i++) {


		//We are going to iterate through sentence and insert each value
		//Since the set only holds unique values we do not have to worry about inserting
		//A value already within the set
		seen_set.insert(sentence[i]);
	}

	//Since our input is only lowercase letters, we can now check to see if 
	//The set contains 26 letters, this will indicate that all 26 letters of the alphabet
	//Are present within the set so this is true, if not then it is false

	if (seen_set.size() == 26) {
		return true;
	}
	else {
		return false;
	}
	

}


int main() {



	std::string sentence = "thequickbrownfoxjumpsoverthelazydog";

	std::string string1 = "abcdefghijklmnopqrstuvwxyzzzz";

	Solution solution;

	std::cout << std::boolalpha << solution.checkIfPangram(sentence);

	return 0;
}