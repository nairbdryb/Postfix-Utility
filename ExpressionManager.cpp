#include "ExpressionManager.h"
#include <stack>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
//int GetHierarchy(string toCheck);

using namespace std;

vector<string> ExpressionManager::parseTokens(string expression) {
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
    vector<string> tokens = parseTokens(postfixExpression);
    string tempString;
    string tempNum;
    string tempOperator;
    stack<string> postfix;


for (int j = 0; j < postfixExpression.size(); j++) {// Decimal check, turns out . is a char :)
	if (postfixExpression[j] == '.') {
		return "invalid";
	}
}
if (isBalanced(postfixExpression) == false) {
    return "Invalid";
}
for (int i = 0; i < tokens.size(); i++) { // continues until the entire string is done
    if (isdigit(tokens.at(i)[0]) && isdigit(tokens.at(i)[1] != true)) { /////// BRIAN THIS IS THE FUNCTION TO TEST FOR DECIMALS
        return "invalid";
    }
    if (isalpha(tokens.at(i)[0])) {//i added this, might want to double check it
        return "invalid";
    }

    if (tokens.at(i) == "+" || tokens.at(i) == "-"
        || tokens.at(i) == "*" || tokens.at(i) == "/" || tokens.at(i) == "%") {
        if (postfix.size() < 2) {
            return "Invalid Expression";
        }
        else {
            tempOperator = tokens.at(i);
            tempNum = postfix.top();
            postfix.pop();
            tempString = "(" + postfix.top() + tempOperator + tempNum + ")";
            postfix.pop();
            postfix.push(tempString);
        }
    }
    else if (isdigit(tokens.at(i)[0])) {
        postfix.push(tokens.at(i));
    }
}
if (postfix.size() > 1) {
    return "Invalid";
}
return postfix.top();
}

string ExpressionManager::postfixEvaluate(string postfixExpression) {
    stack<int> myStack;
    vector<string> token;
    stringstream zz;
    int z = 0;
    int y = 0;
    int x = 0;

    if (isBalanced(postfixExpression) == false) {
        return "Invalid, ya nerd";
    }
    token = parseTokens(postfixExpression);
    if (token.size() < 3 || isdigit(token.at(0)[0] != true)){
        return "invalid, Not enough.";
    }

    for (int i = 0; i != token.size(); i++) {
        if (isdigit(token.at(i)[0]) == true) {
            stringstream transfer(token[i]);
            transfer >> x;
            myStack.push(x);
        }
        else {
            if (myStack.size() != 0) {
                y = myStack.top();
                myStack.pop();
                z = myStack.top();
                myStack.pop();
            }

            
            if (myStack.size() < 2) {
                return "invalid. Too few.";
            } // this one checks to see if it is less than 2 numbers before the operators
            

            if (token.at(i) == "+") {
                myStack.push(z + y);
                //myStack.pop();
            }
            else if (token.at(i) == "-") {
                myStack.push(z - y);
                //myStack.pop();
            }
            else if (token.at(i) == "*") {
                myStack.push(z * y);
                //myStack.pop();
            }
            else if (token.at(i) == "/") {
                if (y != 0) {
                    myStack.push(z / y);
                    //myStack.pop();
                }
            }
            else if (token.at(i) == "%") {
                if (y != 0) {
                    myStack.push(z % y);
                    //myStack.pop();
                }
            }
            //cout << z << endl;
        }
    }
    zz << myStack.top();
    string str;
    zz >> str;
    return str;
}

string ExpressionManager::infixToPostfix(string infixExpression) {
    vector<string> strings;
    stringstream ss;
    stack<string> theStack;
    string postfix = "";
    //int tempA = -9999999;
    //int tempB = -9999999;

    if (isBalanced(infixExpression) == false) {
        return "invalid";
    }

	for (int j = 0; j < infixExpression.size(); j++) {// Decimal check, turns out . is a char :)
		if (infixExpression[j] == '.') {
			return "invalid";
		}
	}
    /*if (infixToPostfixCheck(infixExpression) == false) {
        return "invalid";
    }*/
    ///////////////////////////////////////////////////////////////////////////////
    int opOne;
    int opTwo;
    vector<string> expression = parseTokens(infixExpression);
    if (expression.size() < 3){
        return "Invalid. Too Little.";
    }
    if (expression.size() > 1)/////////added this check too :)
    for (int i = 0; i < expression.size(); i++) {
        int spacing = 1;
        if (GetHierarchy(expression[i]) == 1 || GetHierarchy(expression[i]) == 2) {
            while (GetHierarchy(expression[i + spacing]) == 0 || GetHierarchy(expression[i + spacing]) == 3
                || expression[i + spacing] == "") {
                spacing++;
            }
            if (GetHierarchy(expression[i + spacing]) == 1 || GetHierarchy(expression[i + spacing]) == 2)
                return "invalid";
        }
    }
    ///////////////////////////////////////////////////////////////////////////////

    strings = parseTokens(infixExpression);
//    for (int i = 0; i < strings.size(); i++) { /////// BRIAN I ALSO ADDED A FOR LOOP I HOPE YOU LIKE IT :)
//        if (isdigit(strings.at(i)[0]) && isdigit(strings.at(i)[1] != true)) { /////// BRIAN THIS IS THE FUNCTION TO TEST FOR DECIMALS
//            return "invalid1";
//        }
//        if (isdigit(strings.at(i)[0] != true && GetHierarchy(strings.at(i)) == -1)){
//            return "invalid3";
//        }
//
//    }

    while (strings.size() > 0) {
        if (strings.size() > 0)
            ss << strings.at(0);
        if (isdigit(strings.at(0)[0])) {
            postfix = postfix + strings.at(0) + " ";
            strings.erase(strings.begin());
        }

        else if (theStack.size() > 0 && isdigit(strings.at(0)[0] == true)) {
            while (theStack.size() > 0 && GetHierarchy(strings.at(0)) <= GetHierarchy(theStack.top())) {
                postfix = postfix + theStack.top() + " ";
                theStack.pop();
            }
        }
        else if (isdigit(strings.at(0)[0]) != true) {
                if (GetHierarchy(strings.at(0)) == -1){
                    return "Invalid. Not numbers.";
                }
            if (GetHierarchy(strings.at(0)) == 1) {
                if (theStack.size() > 0) {
                    while (theStack.size() > 0 && GetHierarchy(theStack.top()) >= GetHierarchy(strings.at(0))) {
                        postfix = postfix + theStack.top() + " ";
                        theStack.pop();
                    }
                    theStack.push(strings.at(0));
                    strings.erase(strings.begin());
                }
                else {
                    theStack.push(strings.at(0));
                    strings.erase(strings.begin());
                }
                /*
                if (theStack.size() == 0 || GetHierarchy(theStack.top()) == 0) {
                    theStack.push(strings.at(0));
                    strings.erase(strings.begin());
                }
                else {
                    postfix = postfix + strings.at(0) + " ";
                    strings.erase(strings.begin());
                }*/
            }
            else if (GetHierarchy(strings.at(0)) == 2) {
                if (theStack.size() == 0 || GetHierarchy(theStack.top()) == 0 || GetHierarchy(theStack.top()) == 1) {
                    theStack.push(strings.at(0));
                    strings.erase(strings.begin());
                }
                else {
                    postfix = postfix + strings.at(0) + " ";
                    strings.erase(strings.begin());
                }
            }
            else if (GetHierarchy(strings.at(0)) == 3) {
                if (strings.at(0) == ")") {
                    while (theStack.size() > 0 && theStack.top() != "(") {
                        postfix = postfix + theStack.top() + " ";
                        theStack.pop();
                    }
                    if (theStack.size() > 0)
                        theStack.pop();
                    strings.erase(strings.begin());
                }
                else if (strings.at(0) == "]") {
                    while (theStack.top() != "[") {
                        postfix = postfix + theStack.top() + " ";
                        theStack.pop();
                    }
                    theStack.pop();
                }
                else { //(strings.at(0) == "}")
                    while (theStack.top() != "{") {
                        postfix = postfix + theStack.top() + " ";
                        theStack.pop();
                    }
                    theStack.pop();
                }
            }
            else {
                if (/*theStack.size() > 0*/ true) {//changed to true due to infinite loop
                    theStack.push(strings.at(0));
                    strings.erase(strings.begin());
                }
            }
        }
        else {
            cout << "infixtopostfix error" << endl;
        }
    }
    if (strings.size() == 0) {
        while (theStack.size() > 0) {
            postfix = postfix + theStack.top() + " ";
            theStack.pop();
        }
    }
    return postfix;
}

int ExpressionManager::GetHierarchy(string toCheck) {
    if (toCheck == ")" || toCheck == "]" || toCheck == "}") {
        return 3;
    }
    else if (toCheck == "*" || toCheck == "/" || toCheck == "%") {
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
    return -99;
}
/*
bool ExpressionManager::infixToPostfixCheck(string infixExpression) {
    int opOne;
    int opTwo;
    vector<string> expression = parseTokens(infixExpression);


    for (int i = 0; i < expression.size(); i++) {
        int spacing = 1;
        if (GetHierarchy(expression[i]) == 1 || GetHierarchy(expression[i]) == 2){
            while (GetHierarchy(expression[i + spacing]) == 0 || GetHierarchy(expression[i + spacing]) == 3
             || expression[i + spacing] == ""){
                spacing++;
            }
            if (GetHierarchy(expression[i+spacing]) == 1 || GetHierarchy(expression[i+spacing]) == 2)
                return false;

        }
    }
    return true;
}
*/
//HELLO ETHAN!!!!
