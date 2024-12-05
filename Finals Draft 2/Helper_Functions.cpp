#include "Helper_Functions.h"

int Helper_Functions:: Main_Menu()
{
    const bool Menu_Loop = true;
    int Mchoice;
    do
    {
        std::cout
            << "==========================================================================================\n"
            << " ----------------------------------------- Menu ----------------------------------------- \n"
            << "==========================================================================================\n"
            << "                                       [1] - Create\n"
            << "                                       [2] - Read\n"
            << "                                       [3] - Update\n"
            << "                                       [4] - Delete\n"
            << "                                       [5] - Exit\n"
            << "==========================================================================================\n: ";
        std::cin >> Mchoice;
        if (CheckingInput_Validity(Mchoice, 5))
        {
            break;
        }
        else
        {
            INVALID_INPUT_MESSAGE();
        }
    } while (Menu_Loop == true);
    return Mchoice;
}
int Helper_Functions:: Create_Menu()
{
    const bool Menu_Loop = true;
    int Choice;
    do
    {
        std::cout
            << "==========================================================================================\n"
            << " ------------------------------------ CREATING MENU ------------------------------------- \n"
            << "==========================================================================================\n"
            << "                                    [1] - Student\n"
            << "                                    [2] - Organization\n"
            << "                                  [3] - Project Activities\n"
            << "==========================================================================================\n"
            << "         NOTE: [Organizations] And [Project Activities] Are Under [Student].\n"
            << "  Please Create [Student] File Before Adding [Organizations] And [Project Activities].\n"
            << "==========================================================================================\n: ";
        std::cin >> Choice;
        if (CheckingInput_Validity(Choice, 3))
        {
            break;
        }
        else
        {
            INVALID_INPUT_MESSAGE();
        }
    } while (Menu_Loop == true);
    return Choice;
}
int Helper_Functions:: Update_Menu()
{
    int Choice;
    const bool Menu_Loop = true;
    do
    {
        std::cout
            << "==========================================================================================\n"
            << " ---------------------------------------- UPDATE ---------------------------------------- \n"
            << "==========================================================================================\n"
            << "                                 What Do You Wish To Update\n"
            << "                                   [1] - First Name\n"
            << "                                   [2] - Last Name\n"
            << "                                   [3] - Birthday\n"
            << "                                   [4] - Age\n"
            << "                                   [5] - Gender\n"
            << "                                   [6] - Address\n"
            << "                                   [7] - Contanct Number\n"
            << "                                   [8] - Email\n"
            << "                                   [9] - Student ID Number\n"
            << "                                  [10] - Enrolled Course\n"
            << "                                  [11] - Organizations And Projects\n"
            << "==========================================================================================\n: ";
        std::cin >> Choice;
        if (CheckingInput_Validity(Choice, 11))
        {
            break;
        }
        else
        {
            INVALID_INPUT_MESSAGE();
        }
    } while (Menu_Loop == true);
    return Choice;
}
int Helper_Functions:: Delete_Menu()
{
    const bool Menu_Loop = true;
    int Choice;
    do
    {
        std::cout
            << "==========================================================================================\n"
            << " ------------------------------------ DELETING MENU ------------------------------------- \n"
            << "==========================================================================================\n"
            << "                                [1] - All Student Files\n"
            << "                                [2] - Specific Student File\n"
            << "                                [3] - All Organizations\n"
            << "                                [4] - Specific Organizations\n"
            << "                                [5] - All Activities\n"
            << "                                [6] - Specific Activities\n"
            << "==========================================================================================\n: ";
        std::cin >> Choice;
        if (CheckingInput_Validity(Choice, 6))
        {
            break;
        }
        else
        {
            INVALID_INPUT_MESSAGE();
        }
    } while (Menu_Loop == true);
    return Choice;
}
bool Helper_Functions:: CheckingInput_Validity(int Input, int Input_Limit)
{
    if (Input >= 1 && Input <= Input_Limit)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Helper_Functions:: INPUTING(std::string& person, std::string instructions)
{
    using namespace std;
    std::cout << instructions;
    std::getline(std::cin, person);
}

void Helper_Functions:: DELETE_MESSAGE()
{
    system("Cls");
    std::cout
        << "==========================================================================================\n"
        << " ---------------------------- SUCCESFULLY DELETED /(> _ <)/ ---------------------------- \n"
        << "==========================================================================================\n";
    system("Pause");
    system("Cls");
}
void Helper_Functions:: NO_ORG_MESSAGE()
{
    system("Cls");
    std::cout
        << "==========================================================================================\n"
        << " ----------------------------- PLEASE CREATE A ORGANIZATION ----------------------------- \n"
        << "==========================================================================================\n";
    system("Pause");
    system("Cls");
}
void Helper_Functions:: NO_STUDENT_MESSAGE()
{
    system("Cls");
    std::cout
        << "==========================================================================================\n"
        << " ----------------------------- PLEASE CREATE A STUDENT FILE ----------------------------- \n"
        << "==========================================================================================\n";
    system("Pause");
    system("Cls");
}
void Helper_Functions:: EMPTYLIST_READ_MESSAGE()
{
    std::cout
        << "==========================================================================================\n"
        << " -------------------------------- EMPTY LIST o(T_T)o ---------------------------------- \n"
        << "==========================================================================================\n";
}
void Helper_Functions:: EMPTYLIST_MESSAGE()
{
    system("Cls");
    std::cout
        << "==========================================================================================\n"
        << " -------------------------------- EMPTY LIST o(T_T)o ---------------------------------- \n"
        << "==========================================================================================\n";
    system("Pause");
    system("Cls");
}
void Helper_Functions:: INVALID_INPUT_MESSAGE()
{
    system("Cls");
    std::cout
        << "==========================================================================================\n"
        << " ------------------------ Invalid Input (> _ <) Please Try Again ------------------------ \n"
        << "==========================================================================================\n\n";
    system("Pause");
    system("Cls");
}
void Helper_Functions:: UPDATE_MESSAGE()
{
    system("Cls");
    std::cout
        << "==========================================================================================\n"
        << " ----------------------------- SUCCEESFULLY UPDATED /(> _ <)/ ----------------------------- \n"
        << "==========================================================================================\n\n";
    std::system("Pause");
    system("Cls");
}
void Helper_Functions:: EXIT_MESSAGE()
{
    system("Cls");
    std::cout
        << "==========================================================================================\n"
        << " ---------------- Thank You For Using This Program Have A Good Day ('o') ---------------- \n"
        << "==========================================================================================\n";
    system("Pause");
    system("Cls");
}