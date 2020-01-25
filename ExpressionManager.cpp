#include "ExpressionManager.h"
#include <string>

using namespace std;

int ExpressionManager::postfixEvaluation() {
	// add numbers to stack until I get an operator. 
	// then pop off the top 2 elements then put the operator in the middle, 
	//top is right bottom left
}

string ExpressionManager::postfixToInfix() {
	stack<char> postfix;
	//add numbers to the top of the stack until you get to an operator
	// check to see if it's less than 2 if so INVALID
	// top number is right number 
	// bottom number is left number
	// operator in the middle
	// add parentheses
	// add to top of the stack
	//continue

}
string ExpressionManager::InfixToPostFix() {
	stack<char> infix;
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
	else if (input == "(" || input == "[" || input == "{') {
		return 0;
	}
	else {
		return -1;
	}
}