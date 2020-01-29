//
// Created by Team Byrd on 1/27/20. :P
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
    return std::string();
}

string ExpressionManager::postfixEvaluate(string postfixExpression) {
    stack<int> myStack;
    vector<string> token;
    token = parseTokens(postfixExpression);
    for (int i = 0; i != token.size(); i++){
        if (isdigit(postfixExpression[i]) == true){
            stringstream transfer(token[i]);
            int x;
            transfer >> x;
            myStack.push(x);
            cout << x << " ";
        } else {
            int y = myStack.top();
            int z = 0;
            myStack.pop();
            z = myStack.top() + y;
            myStack.pop();
            cout << z << endl;
        }
    }

    return std::string();
}

string ExpressionManager::infixToPostfix(string infixExpression) {
    vector<string> strings;
    stack stack;

   strings = parseTokens(infixExpression);
   for (int i = 0; i < strings.size(); i++) {
       stack.push(strings.at(i));
   }



	return "";
}

int ExpressionManager::GetHierarchy(string toCheck) {
    if (toCheck == ")" || toCheck == "]" || toCheck == "}") {
        return 3;
    }
    else if (toCheck == "*" || toCheck = "/" || toCheck == "%") {
        return 2;
    }
    else if (toCheck == "+" || toCheck == "-") {
        return 1;
    }
    else if (toCheck == "(" || toCheck == "[" || toCheck == "{") {
        return 0;;
    }
    else {
        return -1;
    }
}

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

