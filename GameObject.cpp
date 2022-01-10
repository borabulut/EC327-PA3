#include <iostream>
#include <cmath>
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
using namespace std;

GameObject :: GameObject(char in_code)
{
    display_code = in_code;
    id_num = 1;
    state = 0;
    cout << "GameObject constructed" << endl;
}

GameObject :: GameObject(Point2D in_loc, int in_id, char in_code)
{
    display_code = in_code;
    id_num = in_id;
    location = in_loc;
    state = 0;
    cout << "GameObject constructed" << endl;
}

GameObject :: ~GameObject()
{
    cout << "GameObject destructed." << endl;
}

Point2D GameObject :: GetLocation()
{
    return location;
}

int GameObject :: GetId()
{
    return id_num;
}

int GameObject :: GetState()
{
    return state;
}

void GameObject :: ShowStatus()
{
    cout << display_code << id_num << " at " << location << endl;
}

void GameObject :: DrawSelf(char * ptr)
{
    *ptr = display_code;
    *(ptr+1) = (char)('0' + id_num);
    // The function puts the display_code at the character pointed to by ptr, and then the ASCII character for the id_num in the next character.
}