#ifndef SHAPES_H
#define SHAPES_H

#include <iostream>

class shape
{
public:
    virtual void create() = 0;
    virtual ~shape(){}
};

class circle : public shape
{
public:
    circle ();
    void create();
    ~circle();
};

class rectangle : public shape
{
public:
    rectangle ();
    void create();
    ~rectangle();
};

class triangle : public shape
{
public:
    triangle ();
    void create();
    ~triangle();
};









#endif /* ifndef SHAPES_H */
