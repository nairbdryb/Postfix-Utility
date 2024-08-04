# Expression Manager
This is a proof of concept command line tool with several utilities. This program reads files from an array defined at the top of main.cpp. Each line is a command followed by arguments. Commands must be separated by newlines. Below is a list of possible commands, and a short description of its features.

* `isBalanced`: Checks for balanced parenthesis. Can check for `()`, `[]`, and `[]` in any order. Returns a file with the original command with true or false appended.
* `postfixToInfix`: Converts postfix expressions to infix expressions.
* `infixToPostfix`: converts infix expressions to postfix expressions.
* `postfixEvaluate`: Returns the calculated value of a postfix expression after the original command. Command and value are separated by newlines.
