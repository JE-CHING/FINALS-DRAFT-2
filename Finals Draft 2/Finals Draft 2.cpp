// Finals Draft 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Students.h"

int main()
{
    Students member;
    Students:: NODEStudent* HeadStudent = nullptr, * TailStudent = nullptr, * TempStudent = nullptr, * Selected_Student = nullptr;
    Students:: NODEOrg* TempOrg = nullptr, * Selected_Org = nullptr;
    Students:: NODEAct* TempAct = nullptr, * Selected_Act = nullptr;

    const int loopID = 1;
    const bool Menu_Loop = true;
    bool EXIT = false;

    int MemberID_Studentcount = 1;
    int MemberID_ORGcount = 1;
    int MemberID_ACTcount = 1;

    int UPchoice = 0;
    int select = 0;
    int Valid = 0;
    bool YENO = false;
    int CH = 0, Ch = 0, Select_Create = 0;

    do
    {
        CH = member.Main_Menu();
        std::cin.ignore();
        system("Pause");
        system("Cls");
        switch (CH)
        {
        case 1:
        {
            Select_Create = member.Create_Menu();
            switch (Select_Create)
            {
            case 1:
            {
                std::cin.ignore();
                MemberID_ORGcount = 1;
                TempStudent = new Students:: NODEStudent;
                member.Create_Students(TempStudent->Students, MemberID_Studentcount);
                member.Add_Student(HeadStudent, TailStudent, TempStudent);
                MemberID_Studentcount++;
                break;
            }
            case 2:
            {
                if (HeadStudent)
                {
                    std::cin.ignore();
                    select = member.SearchingLoop(HeadStudent, "Add A Organization", MemberID_Studentcount);
                    if (select != 0)
                    {
                        Selected_Student = member.SearchFor_Node_Student(HeadStudent, select);
                        system("pause");
                        system("cls");

                        if (Selected_Student->Students.HeadOrg)
                        {
                            std::cin.ignore();
                            MemberID_ORGcount = member.COUNT_ORG(Selected_Student->Students.HeadOrg);
                            TempOrg = new Students:: NODEOrg;
                            member.Create_Organizations(TempOrg->membership, MemberID_ORGcount + 1);
                            member.Add_ORG(Selected_Student->Students.HeadOrg, Selected_Student->Students.TailOrg, TempOrg);
                        }
                        else
                        {
                            std::cin.ignore();
                            TempOrg = new Students:: NODEOrg;
                            member.Create_Organizations(TempOrg->membership, MemberID_ORGcount);
                            member.Add_ORG(Selected_Student->Students.HeadOrg, Selected_Student->Students.TailOrg, TempOrg);
                        }
                    }
                    else
                    {
                        member.INVALID_INPUT_MESSAGE();
                    }
                }
                else
                {
                    member.NO_STUDENT_MESSAGE();
                }
                break;
            }
            case 3:
            {
                if (HeadStudent)
                {
                    std::cin.ignore();
                    select = member.SearchingLoop(HeadStudent, "Add A Organization", MemberID_Studentcount);
                    if (select != 0)
                    {
                        Selected_Student = member.SearchFor_Node_Student(HeadStudent, select);
                        system("pause");
                        system("cls");

                        if (Selected_Student->Students.HeadOrg)
                        {
                            std::cin.ignore();
                            Selected_Org = member.Count_Org_Menu(Selected_Student->Students.HeadOrg, "Add To");
                            if (Selected_Org->membership.HeadAct)
                            {
                                std::cin.ignore();
                                MemberID_ACTcount = member.COUNT_ACT(Selected_Org->membership.HeadAct);
                                TempAct = new Students:: NODEAct;
                                member.Create_Activities(TempAct->Acts, MemberID_ACTcount + 1);
                                member.Add_ACT(Selected_Org->membership.HeadAct, Selected_Org->membership.TailAct, TempAct);
                            }
                            else
                            {
                                std::cin.ignore();
                                TempAct = new Students:: NODEAct;
                                member.Create_Activities(TempAct->Acts, MemberID_ACTcount);
                                member.Add_ACT(Selected_Org->membership.HeadAct, Selected_Org->membership.TailAct, TempAct);
                            }
                        }
                        else
                        {
                            member.NO_ORG_MESSAGE();
                        }
                    }
                    else
                    {
                        member.INVALID_INPUT_MESSAGE();
                    }
                }
                else
                {
                    member.NO_STUDENT_MESSAGE();
                }
                break;
            }
            system("pause");
            system("cls");
            break;
            }
            break;
        }
        case 2:
        {
            select = member.SearchingLoop(HeadStudent, "View", MemberID_Studentcount);
            if (select != 0)
            {
                Selected_Student = member.SearchFor_Node_Student(HeadStudent, select);
                system("pause");
                system("cls");
                member.Read_Student(Selected_Student);
                system("Pause");
                system("Cls");
            }
            break;
        }
        case 3:
        {
            select = member.SearchingLoop(HeadStudent, "Update", MemberID_Studentcount);
            if (select != 0)
            {
                Selected_Student = member.SearchFor_Node_Student(HeadStudent, select);
                system("pause");
                system("cls");
                member.UPDATE_Student(Selected_Student);
            }
            break;
        }
        case 4:
        {

            Ch = member.Delete_Menu();
            switch (Ch)
            {
                case 1:
                {
                    if (HeadStudent)
                    {
                        member.DeleteAll(HeadStudent, TailStudent, MemberID_Studentcount);
                        member.DELETE_MESSAGE();
                    }
                    else
                    {
                        member.EMPTYLIST_MESSAGE();
                    }
                    break;
                }
                case 2:
                {
                    if (HeadStudent)
                    {
                        if (MemberID_Studentcount <= 2)
                        {
                            member.DeleteAll(HeadStudent, TailStudent, MemberID_Studentcount);
                            member.DELETE_MESSAGE();
                        }
                        else
                        {
                            select = member.SearchingLoop(HeadStudent, "Delete", MemberID_Studentcount);
                            if (select != 0)
                            {
                                Selected_Student = member.SearchFor_Node_Student(HeadStudent, select);
                                member.Delete_Student_Node(Selected_Student, HeadStudent, TailStudent, MemberID_Studentcount);
                            }
                            else
                            {
                                member.INVALID_INPUT_MESSAGE();
                            }
                        }
                    }
                    else
                    {
                        member.EMPTYLIST_MESSAGE();
                    }
                    break;
                }
                case 3:
                {
                    if (HeadStudent)
                    {
                        std::cin.ignore();
                        select = member.SearchingLoop(HeadStudent, "Delete", MemberID_Studentcount);
                        if (select != 0)
                        {
                            Selected_Student = member.SearchFor_Node_Student(HeadStudent, select);
                            system("pause");
                            system("cls");
                            if (Selected_Student->Students.HeadOrg)
                            {
                                member.DeleteAll_ORG(Selected_Student->Students.HeadOrg, Selected_Student->Students.TailOrg);
                            }
                            else
                            {
                                member.EMPTYLIST_MESSAGE();
                            }
                        }
                        else
                        {
                            member.INVALID_INPUT_MESSAGE();
                        }
                    }
                    else
                    {
                        member.EMPTYLIST_MESSAGE();
                    }
                    break;
                }
                case 4:
                {
                    if (HeadStudent)
                    {
                        std::cin.ignore();
                        select = member.SearchingLoop(HeadStudent, "Delete", MemberID_Studentcount);
                        if (select != 0)
                        {
                            Selected_Student = member.SearchFor_Node_Student(HeadStudent, select);
                            system("pause");
                            system("cls");
                            if (Selected_Student->Students.HeadOrg)
                            {
                                std::cin.ignore();
                                Selected_Org = member.Count_Org_Menu(Selected_Student->Students.HeadOrg, "Delete");
                                if (Selected_Org)
                                {
                                    member.Delete_Organization_Node(Selected_Org, Selected_Student->Students.HeadOrg, Selected_Student->Students.TailOrg, Selected_Org->membership.ROLENUM);
                                }
                                else
                                {
                                    member.INVALID_INPUT_MESSAGE();
                                }
                            }
                            else
                            {
                                member.EMPTYLIST_MESSAGE();
                            }
                        }
                        else
                        {
                            member.INVALID_INPUT_MESSAGE();
                        }
                        
                    }
                    else
                    {
                        member.EMPTYLIST_MESSAGE();
                    }
                    break;
                }
                case 5:
                {
                    if (HeadStudent)
                    {
                        std::cin.ignore();
                        select = member.SearchingLoop(HeadStudent, "Delete", MemberID_Studentcount);
                        if (select != 0)
                        {
                            Selected_Student = member.SearchFor_Node_Student(HeadStudent, select);
                            system("pause");
                            system("cls");
                            if (Selected_Student->Students.HeadOrg)
                            {
                                std::cin.ignore();
                                Selected_Org = member.Count_Org_Menu(Selected_Student->Students.HeadOrg, "Delete");
                                if (Selected_Org->membership.HeadAct)
                                {
                                    member.DeleteAll_ACT(Selected_Org->membership.HeadAct, Selected_Org->membership.TailAct);
                                }
                                else
                                {
                                    member.INVALID_INPUT_MESSAGE();
                                }

                            }
                            else
                            {
                                member.INVALID_INPUT_MESSAGE();
                            }
                        }
                        else
                        {
                            member.INVALID_INPUT_MESSAGE();
                        }
                    }
                    else
                    {
                        member.EMPTYLIST_MESSAGE();
                    }
                    break;
                }
                case 6:
                {
                    if (HeadStudent)
                    {
                        std::cin.ignore();
                        select = member.SearchingLoop(HeadStudent, "Delete", MemberID_Studentcount);
                        if (select != 0)
                        {
                            Selected_Student = member.SearchFor_Node_Student(HeadStudent, select);
                            system("pause");
                            system("cls");
                            if (Selected_Student->Students.HeadOrg)
                            {
                                std::cin.ignore();
                                Selected_Org = member.Count_Org_Menu(Selected_Student->Students.HeadOrg, "Delete");
                                if (Selected_Org->membership.HeadAct)
                                {
                                    std::cin.ignore();
                                    Selected_Act = member.Count_ACT_Menu(Selected_Org->membership.HeadAct, "Delete");
                                    if(Selected_Act)
                                    {
                                        member.Delete_Activities_Node(Selected_Act, Selected_Org->membership.HeadAct, Selected_Org->membership.TailAct, Selected_Act->Acts.ACTNUM);
                                    }
                                    else
                                    {
                                        member.INVALID_INPUT_MESSAGE();
                                    }
                                }
                                else
                                {
                                    member.INVALID_INPUT_MESSAGE();
                                }

                            }
                            else
                            {
                                member.INVALID_INPUT_MESSAGE();
                            }
                        }
                        else
                        {
                            member.INVALID_INPUT_MESSAGE();
                        }
                    }
                    else
                    {
                        member.EMPTYLIST_MESSAGE();
                    }
                    break;
                }
                

                }

            break;
        }
        case 5:
        {
            EXIT = true;
            member.EXIT_MESSAGE();
            break;
        }
        default:
        {
            member.INVALID_INPUT_MESSAGE();
            break;
        }
        }
    } while (EXIT == false);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
