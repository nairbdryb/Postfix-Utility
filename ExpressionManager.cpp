#include "ExpressionManager.h"
#include <string>

using namespace std;

int ExpressionManager::postfixEvaluation() {

}

string ExpressionManager::postfixToInfix() {

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