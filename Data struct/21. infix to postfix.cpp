//只能處理英文字母的運算(A+B之類的)
#include <iostream>
#include <stack>
#include <string>

bool IsOperand(char c) {  //判斷是不是運算元
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int GetOperatorPrecedence(char op) {  //判斷優先度
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')   //括號令外處理了
        return 2;
    return 0;
}

bool HasHigherPrecedence(char op1, char op2) {  //比較優先度
    int precedence1 = GetOperatorPrecedence(op1);
    int precedence2 = GetOperatorPrecedence(op2);
    return precedence1 >= precedence2;    //若p1>=p2的話傳true
}

std::string InfixToPostfix(std::string exp) {
    std::stack<char> S;
    std::string result;   //建新的string

    for (int i = 0; i < exp.length(); i++) {  //掃描每個字元
        if (IsOperand(exp[i])) {   //是運算元就直接放入result string
            result += exp[i];
        } else if (exp[i] == '(') {   //括號開口放入stack
            S.push(exp[i]);
        } else if (exp[i] == ')') {   //括號結束要輸出到stack.top是括號開口時
            while (!S.empty() && S.top() != '(') {
                result += S.top();
                S.pop();   //輸出完記得移除
            }
            S.pop();   //移除括號開口
        } else {   //處理運算子
            while (!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(), exp[i])) {   //若stack不是空的且不是括號開口且優先度較低
                result += S.top();  //把stack.top輸出到result
                S.pop();
            }
            S.push(exp[i]);
        }
    }

    while (!S.empty()) {
        result += S.top();
        S.pop();
    }

    return result;
}

int main() {
    std::string expression;  //建一個string
    std::cout << "請輸入中序表示法表達式：";  //輸出問題
    std::cin >> expression;  //接收使用者的回答

    std::string postfixExpression = InfixToPostfix(expression);  //創一個postfixExpression的string內容是InfixToPostfix函式
    std::cout << "後序表示法表達式：" << postfixExpression << std::endl;  //把postfixExpression的答案輸出,std::endl是換行的意思

    return 0;
}
