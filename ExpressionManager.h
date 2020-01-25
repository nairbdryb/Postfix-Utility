#pragma once
#include <iostream>
#include <string>
#include "ExpressionManagerInterface.h"

using namespace std;

class ExpressionManager {
public:
	bool IsBalanced();
	int postfixEvaluate(); // Emily's
	bool infixToPostfix();
	string postfixToInfix(); // Emily's
	string toString();
	string infixToPostFix(string infixExpression); //mine
	int GetHierarchy(string input); //also mine

private:

};
