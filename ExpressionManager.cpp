//
// Created by Ethan Low on 1/27/20.
//

#include "ExpressionManager.h"
#include <stack>
#include <iostream>
#include <vector>
#include <sstream>

vector<string> ExpressionManager::parseTokens(string expression)
{
    stringstream ss(expression);
    string token;
    vector<string> tokens;
    while(getline(ss, token, ' '))
    {
        tokens.push_back(token);
    }
    return tokens;
}

bool ExpressionManager::isBalanced(string expression) {
    stack<char> myStack;
    //cin >> (myChar, expression);
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            myStack.push(expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']'){
            if (myStack.empty()){
                return false;
            }
            if (expression[i] == ')' && myStack.top() == '('){
                myStack.pop();
            } else if (expression[i] == '}' && myStack.top() == '{') {
                myStack.pop();
            } else if (expression[i] == ']' && myStack.top() == '['){
                myStack.pop();
            } else return false;
        } //else return false;

    }
    if (myStack.empty()){
        return true;
    } else return false;
}

string ExpressionManager::postfixToInfix(string postfixExpression) {
	vector<std::strings> tokens = parseTokens(postfixExpression);
	std::string tempString;
	std::string tempNum;
	std::string tempOperator;

	stack<char> postfix; // can a stack of chars also hold strings?
	for (int i = 0; i < tokens.size(); i++) { // continues until the entire string is done
		
		if (tokens.at(i) == "+" || tokens.at(i) == "-"
			|| tokens.at(i) == "*" || tokens.at(i) == "/") { // if the char is an operand it is added to the top of the stack
			if (postfix.size() < 2) {
				cout << "Invalid Expression" << endl;
			}
			else {
				tempOperator = tokens.at(i);
				tempNum = postfix.top();
				postfix.pop();
				tempString = "(" + postfix.top() + tempOperator + tempNum + ")";
				postfix.pop();
				postfix.push(tempString);



		}


    return std::string();
}

string ExpressionManager::postfixEvaluate(string postfixExpression) {
    vector<string> token;
    token = parseTokens(postfixExpression);
    


    return std::string();
}

string ExpressionManager::infixToPostfix(string infixExpression) {
    /*stack<char> myStack;
    //cin >> (myChar, expression);
    for (int i = 0; i < infixExpression.length(); i++) {
        while (isdigit(infixExpression[i]) == true) {
            cout << infixExpression[i];
            i++;
        }
        cout << " ";
        if (isdigit(infixExpression[i] == false)) {
            myStack.push(infixExpression[i]);
        }
        //cout << myStack.top() << " ";
*/


    return std::string();
}