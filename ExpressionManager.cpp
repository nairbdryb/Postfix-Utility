#include "ExpressionManager.h"
#include <string>

using namespace std;

int ExpressionManager::postfixEvaluation(string postfixExpression) {
	// add numbers to stack until I get an operator. 
	// then pop off the top 2 elements then put the operator in the middle, 
	//top is right bottom left
}

string ExpressionManager::postfixToInfix(string postfixExpression) {
	stack<char> postfix;
	while(postfixEspression)


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