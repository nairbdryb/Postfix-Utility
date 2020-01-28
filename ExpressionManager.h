#ifndef EXPRESSION_MANAGER

#include <iostream>
#include <string>
#include "ExpressionManagerInterface.h"

using namespace std;

class ExpressionManager {
public:
	bool isBalanced(string expression);
	int postfixEvaluate(string postfixExpression); // Not yours
	bool infixToPostfix(string infixExpression);
	string postfixToInfix(string postfixExpression); //also not yours
	string toString();
	string infixToPostFix(string infixExpression); //mine
	int GetHierarchy(string input); //also mine

private:

};

#define EXPRESSION_MANAGER
#endif // !EXPRESSION_MANAGER


