#pragma once

#include <vector>
#include "Employee.hpp"

//singleton - stan globalny ale zamkniety w klase

////
//class Singleton{
//    Singleton(){}
//public:
//    static Singleton& getInstance(){
//        static Singleton s;
//        return s;
//    }
//};

// WE NEED IT ONLY TO CLEAR DATABASE IN TESTS
// DO NOT USE DIRECTLY IN PRODUCTION CODE!
extern std::vector<Employee*> employees; //UNIQUE POINTERY? znaczenie dokumentujace

// Whether CEO/HR are interested in hired/fired employees
// Set to true to start notifying them
extern bool inform_ceo; //OBSERVER!!!obserwator
extern bool inform_hr;

bool addEmployee(const PersonData& person, int type, double salary); //metoda fabryczna?

// Remember to delete e after calling that!
void removeEmployee(Employee* e);

Employee* findEmployee(const std::string& pesel);
