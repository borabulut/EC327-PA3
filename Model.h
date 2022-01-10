#ifndef MODEL_H
#define MODEL_H
#include "GameObject.h"
#include "Building.h"
#include "ClassRoom.h"
#include "DoctorsOffice.h"
#include "Student.h"
#include "View.h"
using namespace std;

class Model
{
    private:
    int time;
    GameObject * object_ptrs[10];
    int num_objects;
    Student * student_ptrs[10];
    int num_students;
    DoctorsOffice * office_ptrs[10];
    int num_offices;
    ClassRoom * class_ptrs[10];
    int num_classes;

    public:
    Model();
    ~Model();
    Student * GetStudentPtr(int id);
    DoctorsOffice * GetDoctorsOfficePtr(int id);
    ClassRoom * GetClassRoomPtr(int id);
    bool Update();
    void Display(View& view);
    void ShowStatus();
};

#endif