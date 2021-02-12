#include <iostream>
#include <deque>
#include <string>

int main() {
    int n; 
    int len;
    std::deque<std::string> expr;
    
    std::cin >> n >> len;

    expr.push_front(std::to_string(n));
    std::string prev_op;

    for (int i = 0; i < len; i++) {
        std::string op;
        int n;

        std::cin >> op >> n;
        if ( (prev_op == "-" || prev_op == "+") && (op == "*" || op == "/")) {
            expr.push_back(")");
            expr.push_front("(");
        }

        expr.push_back(" ");
        expr.push_back(op);
        expr.push_back(" ");
        expr.push_back(std::to_string(n));
        prev_op = op;
    }

    while (!expr.empty()) {
        std::cout << expr[0];
        expr.pop_front();
    }

    std::cout << std::endl;

    return 0;
}
