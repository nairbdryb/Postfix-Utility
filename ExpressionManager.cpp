//
// Created by Ethan Low on 1/27/20.
//

#include "ExpressionManager.h"
#include <stack>
#include <iostream>

bool ExpressionManager::isBalanced(string expression) {
	stack<char> myStack;
	//cin >> (myChar, expression);
	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
			myStack.push(expression[i]);
		}
		else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
			if (myStack.empty()) {
				return false;
			}
			if (expression[i] == ')' && myStack.top() == '(') {
				myStack.pop();
			}
			else if (expression[i] == '}' && myStack.top() == '{') {
				myStack.pop();
			}
			else if (expression[i] == ']' && myStack.top() == '[') {
				myStack.pop();
			}
			else return false;
		} //else return false;

	}
	if (myStack.empty()) {
		return true;
	}
	else return false;
}

string ExpressionManager::postfixToInfix(string postfixExpression) { //also not yours

	stack<char> postfix; // can a stack of chars also hold strings?

	for (int i = 0; postfixExpression.length(); ) { // continues until the entire string is done
		if (postfixExpression.at(i) == " ") { // if the char is a space it is ignored
			i++;
		} //FIXME: how do I deal with double digits?
		else if (isdigit(postfixExpression.at(i))) { // Sees is the char is a number
			if (postfixExpression.at(i + 1) == " ") {
				postfix.push(postfixExpression.at(i)); // If there is a space after the number then it takes it and adds it to the stack
			}
			else if (isdigit(postfixExpression.at(i + 1))) {
				postfix.push(postfixExpression.at(i) && postfixExpression.at(i + 1));// I don't know if this is legal Maybe add to a different string variable first?
			}
			//TODO: if the next one is a space add to string		IF NOT then take both numbers and add them in one string

		}
		else if (postfixExpression.at(i) == "+" || postfixExpression.at(i) == "-"
			|| postfixExpression.at(i) == "*" || postfixExpression.at(i) == "/") { // if the char is an operand it is added to the top of the stack

			// TODO: find a way to make the things all add to a string. then add the string back into the stack.
			postfix.push(postfixExpression.at(i))
		}
		return std::string();
	}

	string ExpressionManager::postfixEvaluate(string postfixExpression) {
		// add numbers to stack until I get an operator. 
		// then pop off the top 2 elements then put the operator in the middle, 
		//top is right bottom left
		return std::string();
	}

	string ExpressionManager::infixToPostfix(string infixExpression) {



		return std::string();
	}
