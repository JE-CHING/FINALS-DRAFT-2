#include "Activities.h"
Activities::NODEAct* Activities:: Count_ACT_Menu(NODEAct*& Selected, std::string instructions)
{
    NODEAct* SELECTED = nullptr, * TempCount = Selected, * Viewing = Selected;
    const bool Menu_Loop = true;
    int choice = 0;
    int NumOf_Act = COUNT_ACT(TempCount);
    do
    {
        Read_Activities(Viewing);
        std::cout
            << "==============================================================================================\n"
            << "There Are Currently " << NumOf_Act << " Activities, Which One Do You Wish To " << instructions << "? \n"
            << "==============================================================================================\n: ";
        std::cin >> choice;
        if (CheckingInput_Validity(choice, NumOf_Act))
        {
            break;
        }
        else
        {
            INVALID_INPUT_MESSAGE();
        }
    } while (Menu_Loop == true);
    SELECTED = SearchFor_Node_Activities(Selected, choice);
    return SELECTED;
}


void Activities:: Add_ACT(NODEAct*& head, NODEAct*& tail, NODEAct*& temp)
{
    if (head == nullptr)
    {
        head = temp;
        tail = temp;
        tail->PreviousACT = head;
    }
    else
    {
        tail->NextAct = temp;
        temp->PreviousACT = tail;
        tail = temp;
    }
}
void Activities:: Create_Activities(ACTIVITIES& node, int ACTNUM)
{
    std::cout << "====================================== PROJECT DATA ======================================\n";
    INPUTING(node.Projects, "Project: ");
    INPUTING(node.Activities, "Activity: ");
    node.ACTNUM = ACTNUM;
}
int Activities:: COUNT_ACT(NODEAct*& Selected)
{
    NODEAct* Select = Selected;
    int i = 0;
    if (Select->NextAct == nullptr)
    {
        i = 1;
    }
    else
    {
        do
        {
            Select = Select->NextAct;
            ++i;
        } while (Select);
    }
    return i;
}

Activities::NODEAct* Activities:: SearchFor_Node_Activities(NODEAct* Searching, int memID)
{
    NODEAct* SELECTED = nullptr;
    if (Searching == nullptr)
    {
        INVALID_INPUT_MESSAGE();
    }
    else
    {
        do
        {
            if (Searching->Acts.ACTNUM == memID)
            {
                SELECTED = Searching;
                break;
            }
            else
            {
                Searching = Searching->NextAct;
            }

        } while (Searching);
    }
    return SELECTED;
}

void Activities::Read_Activities(NODEAct* act)
{
    if (act)
    {
        do
        {
            std::cout
                << "===================================== PROJECT DATA " << act->Acts.ACTNUM << " =====================================\n"
                << "Project: " << act->Acts.Projects << "\n"
                << "Activity: " << act->Acts.Activities << "\n"
                << "==========================================================================================\n";
            act = act->NextAct;
        } while (act);
    }
    else
    {
        std::cout << "====================================== PROJECT DATA ======================================\n\n";
        EMPTYLIST_READ_MESSAGE();
    }
}

void Activities:: UPDATE_Activities(NODEAct*& Selected)
{
    if (Selected)
    {
        const bool Menu_Loop = true;
        int choice = 0;
        int SwChoice = 0;
        NODEAct* SELECTED = nullptr;

        system("pause");
        system("cls");

        SELECTED = Count_ACT_Menu(Selected, "Update");
        do
        {
            std::cout
                << "==========================================================================================\n"
                << "                            What Do You Wish To Update?\n"
                << "                                 [1] - Project\n"
                << "                                 [2] - Activity\n: ";
            std::cin >> SwChoice;
            std::cin.ignore();
            if (CheckingInput_Validity(SwChoice, 2))
            {
                break;
            }
            else
            {
                INVALID_INPUT_MESSAGE();
            }
        } while (Menu_Loop == true);
        std::cout << "==========================================================================================\n";
        switch (SwChoice)
        {
        case 1:
            INPUTING(SELECTED->Acts.Projects, "Project: ");
            break;
        case 2:
            INPUTING(SELECTED->Acts.Activities, "Activity: ");
            break;
        }
    }
    else
    {
        EMPTYLIST_MESSAGE();
    }

}


void Activities:: MemberID_ACT_Decrease(NODEAct*& Start)
{
    do
    {
        Start->Acts.ACTNUM -= 1;
        Start = Start->NextAct;
    } while (Start);
}
void Activities:: DeleteAll_ACT(NODEAct*& Head, NODEAct*& Tail)
{
    Head = nullptr;
    Tail = nullptr;
}
void Activities:: Delete_Activities_Node(NODEAct*& Selected, NODEAct*& head, NODEAct*& tail, int& memID)
{
    if (Selected == head)
    {
        head = head->NextAct;
        head->PreviousACT = nullptr;
        MemberID_ACT_Decrease(Selected);
    }
    else if (Selected == tail)
    {
        tail = tail->PreviousACT;
        tail->NextAct = nullptr;
        MemberID_ACT_Decrease(Selected);
    }
    else if (Selected != head && Selected != tail)
    {
        Selected->PreviousACT->NextAct = Selected->NextAct;
        Selected->NextAct->PreviousACT = Selected->PreviousACT;
        MemberID_ACT_Decrease(Selected->NextAct);
    }
    Selected = nullptr;
    DELETE_MESSAGE();
}