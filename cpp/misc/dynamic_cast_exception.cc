/*
 * @file dynamic_cast_exception.cc
 * @brief when the bad_cast exception will be throwed?
 *
 * @version 1.0
 * @date Mon Nov 19 23:35:40 2012
 *
 * @copyright Copyright (C) 2012 UESTC
 * @author shiwei<shiwei2012@gmail.com>
 */

#include <iostream>
#include <typeinfo>
#include <string>

class Fruit
{
public:
    // have to define one virtual function to make it polymorphic
    virtual const std::string &Name() {
        return _name;
    }

protected:
    std::string _name;
};

class Apple : public Fruit
{

};

class Peach : public Fruit
{

};

static void
CastPointer(Fruit *fruit)
{
    try {

        Peach *peach = dynamic_cast<Peach *>(fruit);

        if (NULL == peach) {
            std::cout << "null pointer returned when casting pointer" 
                << std::endl;
        }

    } catch (std::bad_cast &ex) {
        std::cout << "bad_cast exception throwed when casting pointer"
                  << std::endl;
    }
}

static void
CastRef(Fruit &fruit)
{
    try {

        Peach &peach = dynamic_cast<Peach &>(fruit);

    } catch (std::bad_cast &ex) {
        std::cout << "bad_cast exception throwed when casting reference"
                  << std::endl;
    }
}

int
main(int argc, char *argv[])
{
    Fruit *fruit = new Apple();

    CastPointer(fruit);

    delete fruit;
    fruit = NULL;

    Apple apple;
    Fruit &rfruit = apple;

    CastRef(rfruit);

    return 0;
}


