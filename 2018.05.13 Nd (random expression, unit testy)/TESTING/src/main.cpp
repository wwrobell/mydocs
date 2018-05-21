#include <iostream>
#include "rational.h"
#include <memory>

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
    Expression* left;
    Expression* right;
public:
    BinaryOperator(Expression* left, Expression* right): left{left}, right{right} { }

    //~BinaryOperator(){
    //    delete left;
    //    delete right;
    //}
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


int main()
{
    Literal l1{4}, l2{1.2}, l3{4.3};
    Add s (&l1, &l2);
    Mult m(&s, &l3);

    Expression* l4 = new Literal{4};
    Expression* l5 = new Literal{7};
    Expression* ss = new Add{l4,l5};

    std::cout<<ss->eval();
    ////
    {
        std::unique_ptr<Expression> p { new Literal{5}};
        //Expression* raw_ptr = p.release();

    }

    //std::string s = f(); // move ctor wystarczy
    //std::string s2 = s; // copy ctor needed

    // std::unique_ptr<Expression> p = f();
    // std::unique_ptr<Expression> p = std::move(p);
    // //p == nullptr

    return 0;
}

