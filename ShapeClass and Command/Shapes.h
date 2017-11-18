#ifndef SHAPES_H
#define SHAPES_H

#include <iostream>

class shape
{
public:
    virtual void draw() = 0;
    virtual void move(int x, int y) = 0;
    virtual ~shape(){}
};

class circle : public shape
{
private:
    int m_x, m_y, m_r;
public:
    circle (int x, int y, int r);
    void draw();
    void move(int x, int y);
    ~circle();
};

class rectangle : public shape
{
private:
    int m_x1, m_y1;
    int m_x2, m_y2;
public:
    rectangle (int x1, int y1, int x2, int y2);
    void draw();
    void move(int x, int y);
    ~rectangle();
};

class triangle : public shape
{
private:
    int m_x1, m_y1;
    int m_x2, m_y2;
    int m_x3, m_y3;
public:
    triangle (int x1, int y1, int x2, int y2, int x3, int y3);
    void draw();
    void move(int x, int y);
    ~triangle();
};

#endif /* ifndef SHAPES_H */
