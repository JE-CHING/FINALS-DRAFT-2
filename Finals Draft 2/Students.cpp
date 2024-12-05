#include "Students.h"

void Students:: Add_Student(NODEStudent*& head, NODEStudent*& tail, NODEStudent*& temp)
{
    if (head == nullptr)
    {
        head = temp;
        tail = temp;
        tail->PreviousStudent = head;
    }
    else
    {
        tail->NextStudent = temp;
        temp->PreviousStudent = tail;
        tail = temp;
    }
}
void Students:: Create_Students(STUDENT& Person, int memID)
{
    Person.MemberID = memID;
    std::cout
        << "==========================================================================================\n"
        << "==================================== PERSONAL INFO =======================================\n";
    INPUTING(Person.Fname, "First Name: ");
    INPUTING(Person.Lname, "Last Name: ");
    INPUTING(Person.Birthday, "Birthday: ");
    INPUTING(Person.Age, "Age: ");
    INPUTING(Person.Gender, "Gender: ");
    INPUTING(Person.Address, "Address: ");
    INPUTING(Person.ContNum, "Contanct Number: ");
    INPUTING(Person.EMail, "Email: ");
    INPUTING(Person.ID, "Student ID Number: ");
    INPUTING(Person.Course, "Enrolled Course: ");
}

int Students:: SearchingLoop(NODEStudent* Head, std::string instructions, int Count)
{
    if (Head)
    {
        const bool Menu_Loop = true;
        int select = 0;
        int Valid = 0;
        do
        {
            Valid = Short_Read(Head);
            if (Valid == 0)
            {
                break;
            }
            else
            {
                std::cout
                    << "==========================================================================================\n"
                    << " -------------------------------------- SEARCHING --------------------------------------- \n"
                    << "==========================================================================================\n"
                    << "There Are Currently " << Count - 1 << " Members\n"
                    << "Which Member Do You Wish To " << instructions << "?\n: ";
                std::cin >> select;
                if (CheckingInput_Validity(select, Count))
                {
                    break;
                }
                else
                {
                    INVALID_INPUT_MESSAGE();
                }
            }
        } while (Menu_Loop == true);
        return select;
    }
    else
    {
        EMPTYLIST_MESSAGE();
    }
}
Students:: NODEStudent* Students:: SearchFor_Node_Student(NODEStudent* Searching, int memID)
{
    NODEStudent* SELECTED = nullptr;
    if (Searching == nullptr)
    {
        INVALID_INPUT_MESSAGE();
    }
    else
    {
        do
        {
            if (Searching->Students.MemberID == memID)
            {
                SELECTED = Searching;
                break;
            }
            else
            {
                Searching = Searching->NextStudent;
            }

        } while (Searching);
    }
    return SELECTED;
}

int Students:: Short_Read(NODEStudent* node)
{
    int Valid = 0;
    if (!node)
    {
        EMPTYLIST_MESSAGE();
        Valid = 0;
    }
    else
    {
        do
        {
            std::cout
                << "==========================================================================================\n"
                << "Member Number: " << node->Students.MemberID << "\n"
                << "==================================== PERSONAL INFO =======================================\n"
                << "Name: " << node->Students.Lname << ", " << node->Students.Fname << "\n"
                << "Student ID: " << node->Students.ID << "\n"
                << "Course: " << node->Students.Course << "\n\n";
            node = node->NextStudent;
        } while (node);
        Valid = 1;
    }
    return Valid;
}
void Students:: Read_Student(NODEStudent* node)
{
    if (node)
    {
        NODEStudent* temp = node;
        std::cout
            << "==========================================================================================\n"
            << "Member Number: " << temp->Students.MemberID << "\n"
            << "==================================== PERSONAL INFO =======================================\n"
            << "Name: " << temp->Students.Fname << " " << temp->Students.Lname << "\n"
            << "Birthday: " << temp->Students.Birthday << "\n"
            << "Age: " << temp->Students.Age << "\n"
            << "Gender: " << temp->Students.Gender << "\n"
            << "Address: " << temp->Students.Address << "\n"
            << "Contanct Number: " << temp->Students.ContNum << "\n"
            << "Email: " << temp->Students.EMail << "\n"
            << "Student ID number: " << temp->Students.ID << "\n"
            << "Course: " << temp->Students.Course << "\n";
        Read_Organization(node->Students.HeadOrg);
        std::cout << "\n\n";
    }
    else
    {
        EMPTYLIST_MESSAGE();
    }
}

void Students:: UPDATE_Student(NODEStudent*& Selected)
{
    int choice = Update_Menu();
    NODEOrg* SELECTED = Selected->Students.HeadOrg;
    std::cin.ignore();
    std::cout << "==========================================================================================\n";
    switch (choice)
    {
    case 1:
        INPUTING(Selected->Students.Fname, "First Name: ");
        break;
    case 2:
        INPUTING(Selected->Students.Lname, "Last Name: ");
        break;
    case 3:
        INPUTING(Selected->Students.Birthday, "Birthday: ");
        break;
    case 4:
        INPUTING(Selected->Students.Age, "Age: ");
        break;
    case 5:
        INPUTING(Selected->Students.Gender, "Gender: ");
        break;
    case 6:
        INPUTING(Selected->Students.Address, "Address: ");
        break;
    case 7:
        INPUTING(Selected->Students.ContNum, "Contanct Number: ");
        break;
    case 8:
        INPUTING(Selected->Students.EMail, "Email: ");
        break;
    case 9:
        INPUTING(Selected->Students.ID, "Student ID Number: ");
        break;
    case 10:
        INPUTING(Selected->Students.Course, "Enrolled Course: ");
        break;
    case 11:
        UPDATE_Organization(SELECTED);
        break;

    }
}

void Students:: MemberID_Decrease(NODEStudent*& Start)
{
    do
    {
        Start->Students.MemberID -= 1;
        Start = Start->NextStudent;
    } while (Start);

}
void Students:: DeleteAll(NODEStudent*& Head, NODEStudent*& Tail, int& MemberID)
{
    Head = nullptr;
    Tail = nullptr;
    MemberID = 1;
}
void Students:: Delete_Student_Node(NODEStudent*& Selected, NODEStudent*& head, NODEStudent*& tail, int& memID)
{
    if (Selected == head)
    {
        head = head->NextStudent;
        head->PreviousStudent = nullptr;
        MemberID_Decrease(Selected);
    }
    else if (Selected == tail)
    {
        tail = tail->PreviousStudent;
        tail->NextStudent = nullptr;
        MemberID_Decrease(Selected);
    }
    else if (Selected != head && Selected != tail)
    {
        Selected->PreviousStudent->NextStudent = Selected->NextStudent;
        Selected->NextStudent->PreviousStudent = Selected->PreviousStudent;
        MemberID_Decrease(Selected->NextStudent);
    }
    memID--;
    Selected = nullptr;
    DELETE_MESSAGE();
}












