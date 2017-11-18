#ifndef COMMANDS_H
#define COMMANDS_H

#include "Shapes.h"
#include <iostream>

class command
{
private:
public:
    virtual void execute() = 0;
    virtual ~command(){}
};

class create : public command
{
private:
    char m_shape_type;
    int  m_index;
    shape **m_shapes_list;
public:
    create (char c, int index, shape **sp);
    void execute();
};

class move : public command
{
private:
    int m_index;
    int m_x, m_y;
    shape **m_shapes_list;
public:
    move (int index, int x, int y, shape **sp);
    void execute();
};

class draw : public command
{
private:
    int m_index;
    shape **m_shapes_list;
public:
    draw(int index, shape **sp);
    void execute();
};

class remove : public command
{
private:
    int m_index;
    shape **m_shapes_list;
public:
    remove (int index, shape **sp);
    void execute();
};

#endif
