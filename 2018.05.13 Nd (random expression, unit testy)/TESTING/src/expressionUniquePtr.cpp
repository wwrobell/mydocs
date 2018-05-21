#include <iostream>
#include "rational.h"
#include <memory>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Expression {
public:
    virtual ~Expression() = 0;
    virtual double eval() const = 0;
};

inline Expression::~Expression() = default;
inline double Expression::eval() const{
    return 0;
}


class Literal : public Expression{
    double val;
public:
    explicit Literal(double val): val{val} { }
    double eval() const override{ // nadpisuje funkcje bazowa
        return val;
    }
};

class BinaryOperator : public Expression{
protected:
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
public:
    BinaryOperator(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
        : left{std::move(left)}, right{std::move(right)} { }
};

class UnaryOperator : public Expression{
    Expression* subExpression;
};

class Add : public BinaryOperator{
public:
    using BinaryOperator::BinaryOperator;

    double eval()const override{
        return left->eval() + right->eval();
    }
};

class Mult : public BinaryOperator{
public:
    using BinaryOperator::BinaryOperator;

    double eval()const override{
        return left->eval() * right->eval();
    }
};

std::unique_ptr<Expression> random_expression(){
    int v1 = rand() % 3;
    if (v1 == 0){
        return std::unique_ptr{new Literal(rand() % 10)};
    }
    else if (v1 == 1){
        std::unique_ptr<Expression> e1 = random_expression();
        std::unique_ptr<Expression> e2 = random_expression();
        return std::unique_ptr{new Add(e1, e2)};
    }
    else if (v2 == 2){
        std::unique_ptr<Expression> e1 = random_expression();
        std::unique_ptr<Expression> e2 = random_expression();
        return std::unique_ptr{new Mult(e1, e2)};
    }
    else
        return nullptr;
}

int main()
{
    srand (time(NULL));
    std::unique_ptr<Expression> l1 {new Literal{2}};
    std::unique_ptr<Expression> l2 {new Literal{5}};
    Add a{std::move(l1), std::move(l2)};
    //Mult b{std::move(l1), std::move(l2)}; //brak mozliwosci przekazania argumentow// przepiecie unique_ptr  przy uzyciu move we wczesniejszej lini


    return 0;
}

