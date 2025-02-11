#ifndef SCHOOL_ROOM_H
#define SCHOOL_ROOM_H

#include "person.h"

struct SchoolRoom{
    int roomNumber;           
    struct Person occupants[50];     
};

#endif
