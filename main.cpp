#include <iostream>
#include "GameCommand.h"
#include "GameObject.h"
#include "Building.h"
#include "Student.h"
#include "DoctorsOffice.h"
#include "ClassRoom.h"
#include "View.h"
using namespace std;

int main()
{
    cout << "Welcome to COVID Game!" << endl;

    Model* main_model = new Model();
    View* main_view = new View();

    main_model -> Display(*main_view);
    main_model -> ShowStatus();

    while (true)
    {
        int student_id;
        int office_id;
        int class_id;
        int vaccine_amount;
        int assignment_amount;
        int x;
        int y;
        char game_command;
        cout << "Enter game command: ";
        cin >> game_command;

        switch (game_command)
        {
            case 'm':
            {
            cout << "Enter student id, x, y" << endl;
            cin >> student_id >> x >> y;
            Point2D loc(x,y);
            DoMoveCommand(*main_model, student_id, loc);
            main_model -> Display(*main_view);
            break;
            }

            {
            case 'd':
            cout << "Enter student id, office id" << endl;
            cin >> student_id >> office_id;
            DoMoveToDoctorCommand(*main_model, student_id, office_id);
            main_model -> Display(*main_view);
            break;
            }
            {
            case 'c':
            cout << "Enter student id, class id" << endl;
            cin >> student_id >> class_id;
            DoMoveToClassCommand(*main_model, student_id, class_id);
            main_model -> Display(*main_view);
            break;
            }

            {
            case 's':
            cout << "Enter student id" << endl;
            cin >> student_id;
            DoStopCommand(*main_model, student_id);
            main_model -> Display(*main_view);
            break;
            }

            {
            case 'v':
            cout << "Enter student id, vaccine amount" << endl;
            cin >> student_id >> vaccine_amount;
            DoRecoverInOfficeCommand(*main_model, student_id, vaccine_amount);
            main_model -> Display(*main_view);
            break;
            }

            {
            case 'a':
            cout << "Enter student id, assignment amount" << endl;
            cin >> student_id >> assignment_amount;
            DoLearningCommand(*main_model, student_id, assignment_amount);
            main_model -> Display(*main_view);
            break;
            }

            {
            case 'g':
            DoGoCommand(*main_model, *main_view);
            main_model -> ShowStatus();
            break;
            }


            {
            case 'r':
            DoRunCommand(*main_model, *main_view);
            main_model -> ShowStatus();
            break;
            }

            {
            case 'q':
            exit(0);
            }
        }
    }
    return 0;
}