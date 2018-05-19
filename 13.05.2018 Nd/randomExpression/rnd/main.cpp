#include <iostream>
#include <memory>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Visitor; //forward declaration
class Add;
class Mult;
class Literal;

class Expression {
public:
    virtual ~Expression() = 0;
    virtual double eval() const = 0;
    virtual void accept(Visitor& v) const = 0;
};

inline Expression::~Expression() = default;
inline double Expression::eval() const{
    return 0;
}

class Visitor{
public:
    virtual void visit(const Literal& e) = 0;
    virtual void visit(const Add& e) = 0;
    virtual void visit(const Mult& e) = 0;
    virtual ~Visitor() = default;
};

class Literal : public Expression{
    double val;
public:
    explicit Literal(double val): val{val} { }

    double eval() const override{ // nadpisuje funkcje bazowa
        return val;
    }

    void accept(Visitor& v) const{
        v.visit(*this);
    }

    double getValue() const{
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
    Expression& getLeft() const {return *left;}
    Expression& getRight() const {return *right;}
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

    void accept(Visitor& v) const{
        v.visit(*this); //referencja do samego siebie?
    }
};

class Mult : public BinaryOperator{
public:
    using BinaryOperator::BinaryOperator;

    double eval()const override{
        return left->eval() * right->eval();
    }

    void accept(Visitor& v) const{
        v.visit(*this);
    }
};


class Printer : public Visitor{
public:
    void visit(const Literal& e) override{
        std::cout<<e.eval();
    }

    void visit(const Add& e) override{
        e.getLeft().accept(*this);
        std::cout<<" + ";
        e.getRight().accept(*this);
    }

    void visit(const Mult& e) override{
    }
};

//class Printer : public Visitor{
//    std::ostream os;
//public:
//    Printer(std::ostream& os): os{os} {} //bug
//    void visit(const Literal& e) override{
//        os<<e.eval();
//    }
//
//    void visit(const Add& e) override{
//        e.getLeft().accept(*this);
//        os<<" + ";
//        e.getRight().accept(*this);
//    }
//
//    void visit(const Mult& e) override{
//    }
//};

//Ewaluacja przy uzyciu visitora [Metoda I]
class Evaluator : public Visitor{
    double value;
public:
    void visit(const Literal& e) override{
        value = e.getValue();
    }

    void visit(const Add& e) override{
        e.getLeft().accept(*this);
        double leftValue = value;
        e.getRight().accept(*this);
        double rightValue = value;

        value = leftValue + rightValue;
    }

    double getValue() const{
        return value;
    }
};

//Ewaluacja przy uzyciu dynamic casta [Metoda I]
double eval_expr(const Expression& e){
    if (const Literal* lit = dynamic_cast<const Literal*>(&e))
        return lit->getValue();
    else if (const Add* add = dynamic_cast<const Add*>(&e))
        return eval_expr(add->getLeft()) + eval_expr(add->getRight());
    //Mult
}

std::unique_ptr<Expression> random_expression(){
    int v1 = rand() % 3;
    if (v1 == 0){
        return std::unique_ptr<Expression>{new Literal(rand() % 10)};
    }
    else if (v1 == 1){
        std::unique_ptr<Expression> e1 = random_expression();
        std::unique_ptr<Expression> e2 = random_expression();
        return std::unique_ptr<Expression>{new Add(std::move(e1), std::move(e2))};
    }
    else if (v1 == 2){
        std::unique_ptr<Expression> e1 = random_expression();
        std::unique_ptr<Expression> e2 = random_expression();
        return std::unique_ptr<Expression>{new Mult(std::move(e1), std::move(e2))};
    }
   // else
   //     return nullptr;
}

//sprobowac zrobic prosty interpreter : input: "32 + 7 * 2" output: wynik , skorzystac ze stacka

//std::ostream& operator << (std::ostream& os, const Expression& e){
//    Printer printer{os};
//    e.accept(printer);
//    return os;
//}

int main()
{
    srand (time(NULL));
    std::unique_ptr<Expression> l1 {new Literal{2}};
    std::unique_ptr<Expression> l2 {new Literal{5}};
    Add a{std::move(l1), std::move(l2)};
    //Mult b{std::move(l1), std::move(l2)}; //brak mozliwosci przekazania argumentow// przepiecie unique_ptr  przy uzyciu move we wczesniejszej lini

    std::cout<<"random: "<<std::endl;
    std::cout<<random_expression()->eval();






    return 0;
}

