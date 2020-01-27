#include "ExpressionManager.h"
#include <string>

using namespace std;

int ExpressionManager::postfixEvaluation(string postfixExpression) { // Not yours
	// add numbers to stack until I get an operator. 
	// then pop off the top 2 elements then put the operator in the middle, 
	//top is right bottom left
}

string ExpressionManager::postfixToInfix(string postfixExpression) { //also not yours
	stack<char> postfix;
	for (int i = 0; postfixExpression.length(); ) { // continues until the entire string is done
		if (postfixExpression.at(i) == " ") { // if the char is a space it is ignored
			i++;
		} //FIXME: how do I deal with double digits?
		else if (isdigit(postfixExpression.at(i)) ) { // Sees is the char is a number
			//TODO: if the next one is a space add to string		IF NOT then take both numbers and add them in one string

		}
		else if (postfixExpression.at(i) == "+" || postfixExpression.at(i) == "-" 
			|| postfixExpression.at(i) == "*" || postfixExpression.at(i) == "/") { // if the char is an operand it is added to the top of the stack
			
			postfix.push(postfixExpression.at(i))
		}
	}


	//add numbers to the top of the stack until you get to an operator
	// check to see if it's less than 2 if so INVALID
	// top number is right number 
	// bottom number is left number
	// operator in the middle
	// add parentheses
	// add to top of the stack
	//continue

}

string ExpressionManager::InfixToPostFix(string infixExpression) {

	stack<char> infix;
	/*
	pop()//tells you element and removes it
	top()//tells you top element
	push()//adds element to the top
	empty()//checks to see if it is empty
	*/

}
int ExpressionManager::GetHierarchy(string input) {
	if (input == ")" || input == "]" || input == "}") {
		return 3;
	}
	else if (input == "*" || input == "/" || input == "%") {
		return 2;
	}
	else if (input == "+" || input == "-") {
		return 1;
	}
	else if (input == "(" || input == "[" || input == "{") {
		return 0;
	}
	else {
		return -1;
	}
}