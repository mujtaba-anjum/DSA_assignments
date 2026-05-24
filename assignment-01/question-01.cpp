//#include <iostream>
//#include <string>
//#include <vector>
//#include <stack>
//#include <cstdlib>
//using namespace std;
//
//struct Token
//{
//    string value;
//    bool isOperator;
//    bool isOpenBracket;
//    bool isCloseBracket;
//    bool isOperand;
//
//    Token(string v, bool op, bool ob, bool cb, bool operand) : value(v), isOperator(op), isOpenBracket(ob),
//        isCloseBracket(cb), isOperand(operand)
//    { }
//};
//
//
//bool isDigitChar(char c) { return c >= '0' && c <= '9'; }
//bool isAlphaChar(char c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_'; }
//bool isAlphaNumChar(char c) { return isAlphaChar(c) || isDigitChar(c); }
//bool isOpenBracketChar(char c) { return c == '(' || c == '[' || c == '{'; }
//bool isCloseBracketChar(char c) { return c == ')' || c == ']' || c == '}'; }
//bool isOperatorChar(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }
//
//bool bracketsMatch(char open, char close)
//{
//    if (open == '(' && close == ')') return true;
//    if (open == '[' && close == ']') return true;
//    if (open == '{' && close == '}') return true;
//    return false;
//}
//
//int precedence(string op)
//{
//    if (op == "*" || op == "/") return 2;
//    if (op == "+" || op == "-") return 1;
//    return 0;
//}
//
//vector<Token> tokenize(const string& expr)
//{
//    vector<Token> tokens;
//    int i = 0;
//    int n = (int)expr.size();
//
//    while (i < n)
//    {
//        if (expr[i] == ' ' || expr[i] == '\t')
//        {
//            i++;
//            continue;
//        }
//
//        if (isDigitChar(expr[i]))
//        {
//            string num = "";
//            while (i < n && isDigitChar(expr[i]))
//            {
//                num += expr[i];
//                i++;
//            }
//            tokens.push_back(Token(num, false, false, false, true));
//            continue;
//        }
//
//        if (isAlphaChar(expr[i]))
//        {
//            string var = "";
//            while (i < n && isAlphaNumChar(expr[i]))
//            {
//                var += expr[i];
//                i++;
//            }
//            tokens.push_back(Token(var, false, false, false, true));
//            continue;
//        }
//
//        if (isOperatorChar(expr[i]))
//        {
//            tokens.push_back(Token(string(1, expr[i]), true, false, false, false));
//            i++;
//            continue;
//        }
//
//        if (isOpenBracketChar(expr[i]))
//        {
//            tokens.push_back(Token(string(1, expr[i]), false, true, false, false));
//            i++;
//            continue;
//        }
//
//        if (isCloseBracketChar(expr[i]))
//        {
//            tokens.push_back(Token(string(1, expr[i]), false, false, true, false));
//            i++;
//            continue;
//        }
//
//        cerr << "Syntax Error: Unknown character '" << expr[i] << "'" << endl;
//        exit(1);
//    }
//    return tokens;
//}
//
//void validateSyntax(const vector<Token>& tokens)
//{
//    if (tokens.empty())
//    {
//        cerr << "Syntax Error: Empty expression" << endl;
//        exit(1);
//    }
//
//    stack<char> bracketStack;
//    int n = (int)tokens.size();
//
//    for (int i = 0; i < n; i++)
//    {
//        Token t = tokens[i];
//
//        if (t.isOpenBracket)
//        {
//            bracketStack.push(t.value[0]);
//        }
//        if (t.isCloseBracket)
//        {
//            if (bracketStack.empty())
//            {
//                cerr << "Syntax Error: Unmatched closing bracket '" << t.value << "'" << endl;
//                exit(1);
//            }
//            char top = bracketStack.top();
//            bracketStack.pop();
//
//            if (!bracketsMatch(top, t.value[0]))
//            {
//                cerr << "Syntax Error: Mismatched brackets '" << top << "' and '" << t.value[0] << "'" << endl;
//                exit(1);
//            }
//        }
//
//        if (i > 0 && t.isCloseBracket && tokens[i - 1].isOpenBracket)
//        {
//            cerr << "Syntax Error: Empty brackets" << endl;
//            exit(1);
//        }
//
//        if (i > 0 && t.isOperand && tokens[i - 1].isOperand)
//        {
//            cerr << "Syntax Error: Two operands without operator" << endl;
//            exit(1);
//        }
//        if (i > 0 && t.isOperator && tokens[i - 1].isOperator)
//        {
//            cerr << "Syntax Error: Two operators side by side" << endl;
//            exit(1);
//        }
//        if (t.isOperator && i == 0)
//        {
//            cerr << "Syntax Error: Expression cannot start with operator" << endl;
//            exit(1);
//        }
//        if (t.isOperator && i == n - 1)
//        {
//            cerr << "Syntax Error: Expression cannot end with operator" << endl;
//            exit(1);
//        }
//        if (t.isOperator && i > 0 && tokens[i - 1].isOpenBracket)
//        {
//            cerr << "Syntax Error: Operator after opening bracket" << endl;
//            exit(1);
//        }
//        if (t.isOperator && i < n - 1 && tokens[i + 1].isCloseBracket)
//        {
//            cerr << "Syntax Error: Operator before closing bracket" << endl; exit(1);
//        }
//    }
//
//    if (!bracketStack.empty())
//    {
//        cerr << "Syntax Error: Unclosed bracket '" << bracketStack.top() << "'" << endl;
//        exit(1);
//    }
//}
//
//vector<string> infixToPostfix(const vector<Token>& tokens)
//{
//    vector<string> output;
//    stack<Token> opStack;
//
//    for (int i = 0; i < (int)tokens.size(); i++)
//    {
//        Token t = tokens[i];
//
//        if (t.isOperand)
//        {
//            output.push_back(t.value);
//        }
//        else if (t.isOpenBracket)
//        {
//            opStack.push(t);
//        }
//        else if (t.isCloseBracket)
//        {
//            bool found = false;
//            while (!opStack.empty())
//            {
//                Token top = opStack.top();
//                opStack.pop();
//                if (top.isOpenBracket)
//                {
//                    found = true;
//                    break;
//                }
//                output.push_back(top.value);
//            }
//            if (!found)
//            {
//                cerr << "Syntax Error: Mismatched brackets" << endl;
//                exit(1);
//            }
//        }
//        else if (t.isOperator)
//        {
//            while (!opStack.empty() &&
//                opStack.top().isOperator &&
//                precedence(opStack.top().value) >= precedence(t.value))
//            {
//                output.push_back(opStack.top().value);
//                opStack.pop();
//            }
//            opStack.push(t);
//        }
//    }
//
//    while (!opStack.empty())
//    {
//        if (opStack.top().isOpenBracket)
//        {
//            cerr << "Syntax Error: Unclosed bracket" << endl;
//            exit(1);
//        }
//        output.push_back(opStack.top().value);
//        opStack.pop();
//    }
//
//    return output;
//}
//
//vector<string> collectVariables(const vector<Token>& tokens)
//{
//    vector<string> vars;
//    for (int i = 0; i < (int)tokens.size(); i++)
//    {
//        if (!tokens[i].isOperand)
//            continue;
//        bool isNum = true;
//        for (int j = 0; j < (int)tokens[i].value.size(); j++)
//        {
//            if (!isDigitChar(tokens[i].value[j]))
//            {
//                isNum = false;
//                break;
//            }
//        }
//        if (isNum)
//            continue;
//        bool found = false;
//        for (int j = 0; j < (int)vars.size(); j++)
//        {
//            if (vars[j] == tokens[i].value)
//            {
//                found = true;
//                break;
//            }
//        }
//        if (!found) vars.push_back(tokens[i].value);
//    }
//    return vars;
//}
//
//double evaluatePostfix(const vector<string>& postfix,
//    const vector<string>& varNames,
//    const vector<double>& varValues)
//{
//    stack<double> evalStack;
//
//    for (int i = 0; i < (int)postfix.size(); i++)
//    {
//        string token = postfix[i];
//
//        bool isNum = true;
//        for (int j = 0; j < (int)token.size(); j++)
//        {
//            if (!isDigitChar(token[j]))
//            {
//                isNum = false;
//                break;
//            }
//        }
//
//        if (isNum)
//        {
//            evalStack.push((double)atoi(token.c_str()));
//        }
//        else if (token == "+" || token == "-" || token == "*" || token == "/")
//        {
//            if ((int)evalStack.size() < 2)
//            {
//                cerr << "Runtime Error: Not enough operands for '" << token << "'" << endl;
//                exit(2);
//            }
//            double b = evalStack.top(); evalStack.pop();
//            double a = evalStack.top(); evalStack.pop();
//            if (token == "+") evalStack.push(a + b);
//            else if (token == "-") evalStack.push(a - b);
//            else if (token == "*") evalStack.push(a * b);
//            else {
//                if (b == 0)
//                {
//                    cerr << "Logical Error: Division by zero" << endl;
//                    exit(3);
//                }
//                evalStack.push(a / b);
//            }
//        }
//        else {
//            bool found = false;
//            for (int j = 0; j < (int)varNames.size(); j++)
//            {
//                if (varNames[j] == token)
//                {
//                    evalStack.push(varValues[j]);
//                    found = true;
//                    break;
//                }
//            }
//            if (!found)
//            {
//                cerr << "Runtime Error: Variable '" << token << "' has no value" << endl;
//                exit(2);
//            }
//        }
//    }
//
//    if ((int)evalStack.size() != 1)
//    {
//        cerr << "Runtime Error: Invalid expression" << endl;
//        exit(2);
//    }
//    return evalStack.top();
//}
//
//int main()
//{
//    string expression;
//    getline(cin, expression);
//    vector<Token> tokens = tokenize(expression);
//
//    validateSyntax(tokens);
//    vector<string> varNames = collectVariables(tokens);
//
//    vector<double> varValues;
//    for (int i = 0; i < (int)varNames.size(); i++)
//    {
//        double val;
//        cerr << "Enter value for " << varNames[i] << ": ";
//        if (!(cin >> val))
//        {
//            cerr << "Runtime Error: Invalid input for variable '" << varNames[i] << "'" << endl;
//            exit(2);
//        }
//        varValues.push_back(val);
//    }
//
//    vector<string> postfix = infixToPostfix(tokens);
//    for (int i = 0; i < (int)postfix.size(); i++)
//    {
//        if (i > 0) cout << " ";
//        cout << postfix[i];
//    }
//    cout << "\n";
//
//    double result = evaluatePostfix(postfix, varNames, varValues);
//
//    if (result == (long long)result)
//        cout << (long long)result << "\n";
//    else
//        cout << result << "\n";
//
//    return 0;
//}