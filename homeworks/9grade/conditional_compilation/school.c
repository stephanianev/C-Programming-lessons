#include <stdio.h>
#include "school_class.h"
#include "school_room.h"

struct School{
    struct SchoolClass classes[20]; 
    struct SchoolRoom rooms[10];    
};

void main() {
    struct School mySchool;

    mySchool.classes[0].classNumber = 9;
    mySchool.classes[0].classLetter = 'A';

    mySchool.rooms[0].roomNumber = 9113;

    struct Person examplePerson = {"Ivan", "Petrov", "Ivanov", 2005};
    mySchool.classes[0].students[0] = examplePerson;

    struct Person exampleTeacher = {"Gosho", "Goshov", "Babin", 1990};
    mySchool.classes[0].classTeacher[0] = exampleTeacher;

    printf("Class: %d%c\n", mySchool.classes[0].classNumber, mySchool.classes[0].classLetter);
    printf("Room Number: %d\n", mySchool.rooms[0].roomNumber);
    printf("Student data: %s %s %s %d\n",
           mySchool.classes[0].students[0].firstName,
           mySchool.classes[0].students[0].middleName,
           mySchool.classes[0].students[0].lastName,
           mySchool.classes[0].students[0].birthYear);
    
    printf("Classteacher data: %s %s %s %d\n",
           mySchool.classes[0].teacher[0].firstName,
           mySchool.classes[0].teacher[0].middleName,
           mySchool.classes[0].teacher[0].lastName,
           mySchool.classes[0].teacher[0].birthYear);
}
