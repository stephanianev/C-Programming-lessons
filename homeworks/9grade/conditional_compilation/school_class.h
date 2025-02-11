#ifndef SCHOOL_CLASS_H
#define SCHOOL_CLASS_H

#include "person.h"

struct SchoolClass{
    struct Person students[26]; 
    char classLetter;    
    int classNumber;     
    struct Person classTeacher; 
};

#endif
