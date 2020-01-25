#pragma once
#include <iostream>
#include <string>
#include "ExpressionManagerInterface.h"

using namespace std;

class ExpressionManager {
public:
	bool IsBalanced(string expression);
	int postfixEvaluate(string postfixExpression); // Not yours
	bool infixToPostfix(string infixExpression);
	string postfixToInfix(string postfixExpression); //also not yours
	string toString();
	string infixToPostFix(string infixExpression); //mine
	int GetHierarchy(string input); //also mine

private:

};
