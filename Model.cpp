#include <iostream>
#include "Model.h"
using namespace std;

Model :: Model()
{
    time = 0;
    Point2D Homer_loc(5,1);
    Student *S1 = new Student("Homer", 1, 'S', 2, Homer_loc);
    object_ptrs[0] = S1;
    student_ptrs[0] = S1;
    Point2D Marge_loc(10,1);
    Student *S2 = new Student("Marge", 2, 'S', 1, Marge_loc);
    object_ptrs[1] = S2;
    student_ptrs[1] = S2;
    Point2D D1_loc(1,20);
    DoctorsOffice *D1 = new DoctorsOffice(1, 1, 100, D1_loc);
    object_ptrs[2] = D1;
    office_ptrs[0] = D1;
    Point2D D2_loc(10,20);
    DoctorsOffice *D2 = new DoctorsOffice(2, 2, 200, D2_loc);
    object_ptrs[3] = D2;
    office_ptrs[1] = D2;
    Point2D C1_loc(0,0);
    ClassRoom *C1 = new ClassRoom(10, 1, 2, 3, 1, C1_loc);
    object_ptrs[4] = C1;
    class_ptrs[0] = C1;
    Point2D C2_loc(5,5);
    ClassRoom *C2 = new ClassRoom(20, 5, 7.5, 4, 2, C2_loc);
    object_ptrs[5] = C2;
    class_ptrs[1] = C2;
    num_objects = 6;
    num_students = 2;
    num_offices = 2;
    num_classes = 2;
    cout << "Model default constructed" << endl;
}

Model :: ~Model()
{
    for (int i = 0; i < num_objects; i++)
    {
        delete object_ptrs[i];
    }
    cout << "Model destructed." << endl;
}

Student* Model :: GetStudentPtr(int id)
{
    for (int i = 0; i<num_students; i++)
    {
        if ((student_ptrs[i] -> GetId()) == id)
        {
            return student_ptrs[i];
        }
    }
    return 0;
}

DoctorsOffice* Model :: GetDoctorsOfficePtr(int id)
{
    for (int i = 0; i<num_offices; i++)
    {
        if ((office_ptrs[i] -> GetId()) == id)
        {
            return office_ptrs[i];
        }
    }
    return 0;
}

ClassRoom* Model :: GetClassRoomPtr(int id)
{
    for (int i = 0; i<num_classes; i++)
    {
        if ((class_ptrs[i] -> GetId()) == id)
        {
            return class_ptrs[i];
        }
    }
    return 0;
}

bool Model :: Update()
{
    time += 1;
    bool result = false;
    for (int i = 0; i<num_objects; i++)
    {
        if ((object_ptrs[i] -> Update()) == true)
        {
            result = true;
        }
    }
    int total_classrooms = 0;
    for (int i = 0; i < num_classes; ++i)
    {
        if (class_ptrs[i]->passed() == true)
        {
            total_classrooms++;
            if (total_classrooms == num_classes)
            {
                cout << "GAME OVER: You win! All assignments done!" << endl;
                exit(0);
            }
        }
    }
    int total_infected = 0;
    for (int i = 0; i < num_students; i++)
    {
        if (student_ptrs[i]->IsInfected() == true)
        {
            total_infected++;
            if (total_infected == num_students)
            {
                cout << "GAME OVER: You lose! All of your Students are infected!" << endl;
                exit(0);
            }   
        }
    }
    return result;
}

        /*
        o If the player finishes all the ClassRooms the game should print “GAME OVER: You win! All assignments done!”. The game should then exit. Try using the exit function to achieve this.
o IfalltheStudentsareinfectedandcan’tmove,print“GAMEOVER:Youlose! All of your Students are infected!”. The game should then exit. Try using the exit function to achieve this.
        */


void Model :: Display(View& view)
{
    cout << "Time: " << time << endl;
    view.Clear();
    for (int i = 0; i < num_objects; i++)
    {
        view.Plot(object_ptrs[i]);
    }
    view.Draw();
}


void Model :: ShowStatus()
{
    cout << "Time: " << time << endl;
    
    for (int i = 0; i < num_objects; i++)
    {
        object_ptrs[i] -> ShowStatus();
    }
}