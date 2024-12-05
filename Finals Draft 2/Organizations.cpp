#include "Organizations.h"
Organizations:: NODEOrg* Organizations:: Count_Org_Menu(NODEOrg*& Selected, std::string instructions)
{
    NODEOrg* SELECTED = nullptr, * TempCount = Selected, * Viewing = Selected;
    const bool Menu_Loop = true;
    int choice = 0;
    int NumOf_Org = COUNT_ORG(TempCount);
    do
    {
        Short_Read_Organization(Viewing);
        std::cout
            << "==============================================================================================\n"
            << "There Are Currently " << NumOf_Org << " Organizations, Which One Do You Wish To " << instructions << "? \n"
            << "==============================================================================================\n: ";
        std::cin >> choice;
        if (CheckingInput_Validity(choice, NumOf_Org))
        {
            break;
        }
        else
        {
            INVALID_INPUT_MESSAGE();
        }
    } while (Menu_Loop == true);
    SELECTED = SearchFor_Node_Organizations(Selected, choice);
    return SELECTED;
}

void Organizations:: Add_ORG(NODEOrg*& head, NODEOrg*& tail, NODEOrg*& temp)
{
    if (head == nullptr)
    {
        head = temp;
        tail = temp;
        tail->PreviousOrg = head;
    }
    else
    {
        tail->NextOrg = temp;
        temp->PreviousOrg = tail;
        tail = temp;
    }
}
void Organizations:: Create_Organizations(Organization& node, int ORGNUM)
{
    std::cout << "==================================== ORGANIZATION DATA ===================================\n";
    INPUTING(node.Organization, "Organization: ");
    INPUTING(node.Role, "Role: ");
    node.ROLENUM = ORGNUM;
}
int Organizations:: COUNT_ORG(NODEOrg*& Selected)
{
    NODEOrg* Select = Selected;
    int i = 0;
    if (Select->NextOrg == nullptr)
    {
        i = 1;
    }
    else
    {
        do
        {
            Select = Select->NextOrg;
            ++i;
        } while (Select);
    }
    return i;
}
Organizations:: NODEOrg* Organizations:: SearchFor_Node_Organizations(NODEOrg* Searching, int memID)
{
    NODEOrg* SELECTED = nullptr;
    if (Searching == nullptr)
    {
        INVALID_INPUT_MESSAGE();
    }
    else
    {
        do
        {
            if (Searching->membership.ROLENUM == memID)
            {
                SELECTED = Searching;
                break;
            }
            else
            {
                Searching = Searching->NextOrg;
            }

        } while (Searching);
    }
    return SELECTED;
}

void Organizations::Short_Read_Organization(NODEOrg* temporg)
{
    if (temporg)
    {
        NODEOrg* org = temporg;
        do
        {
            std::cout
                << "================================== ORGANIZATION DATA " << org->membership.ROLENUM << " ==================================\n"
                << "Organization: " << org->membership.Organization << "\n"
                << "Role: " << org->membership.Role << "\n";
            org = org->NextOrg;
        } while (org);
    }
    else
    {
        std::cout << "=================================== ORGANIZATION DATA ===================================\n\n";
        EMPTYLIST_READ_MESSAGE();
    }
}
void Organizations:: Read_Organization(NODEOrg* temporg)
{
    if (temporg)
    {
        NODEOrg* org = temporg;
        do
        {
            std::cout
                << "================================== ORGANIZATION DATA " << org->membership.ROLENUM << " ==================================\n"
                << "Organization: " << org->membership.Organization << "\n"
                << "Role: " << org->membership.Role << "\n";
            Read_Activities(org->membership.HeadAct);
            org = org->NextOrg;
        } while (org);
    }
    else
    {
        std::cout << "=================================== ORGANIZATION DATA ===================================\n\n";
        EMPTYLIST_READ_MESSAGE();
    }
}

void Organizations:: UPDATE_Organization(NODEOrg*& Selected)
{
    if (Selected)
    {
        const bool Menu_Loop = true;
        int choice = 0;
        int SwChoice = 0;
        NODEOrg* SELECTED = nullptr;
        NODEAct* Select = nullptr;
        system("pause");
        system("cls");

        SELECTED = Count_Org_Menu(Selected, "Update");
        Select = SELECTED->membership.HeadAct;
        do
        {
            std::cout
                << "==========================================================================================\n"
                << "                               What Do You Wish To Update?\n"
                << "                                 [1] - Organization\n"
                << "                                 [2] - Role\n"
                << "                                 [3] - Project Activities\n: ";
            std::cin >> SwChoice;
            std::cin.ignore();
            if (CheckingInput_Validity(SwChoice, 3))
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
            INPUTING(SELECTED->membership.Organization, "Organization: ");
            break;
        case 2:
            INPUTING(SELECTED->membership.Role, "Role: ");
            break;
        case 3:
            UPDATE_Activities(Select);
            break;
        }
    }
    else
    {
        EMPTYLIST_MESSAGE();
    }
}

void Organizations:: MemberID_ORG_Decrease(NODEOrg*& Start)
{
    do
    {
        Start->membership.ROLENUM -= 1;
        Start = Start->NextOrg;
    } while (Start);

}
void Organizations:: DeleteAll_ORG(NODEOrg*& Head, NODEOrg*& Tail)
{
    Head = nullptr;
    Tail = nullptr;
}
void Organizations:: Delete_Organization_Node(NODEOrg*& Selected, NODEOrg*& head, NODEOrg*& tail, int& memID)
{
    if (Selected == head)
    {
        head = head->NextOrg;
        head->PreviousOrg = nullptr;
        MemberID_ORG_Decrease(Selected);
    }
    else if (Selected == tail)
    {
        tail = tail->PreviousOrg;
        tail->NextOrg = nullptr;
        MemberID_ORG_Decrease(Selected);
    }
    else if (Selected != head && Selected != tail)
    {
        Selected->PreviousOrg->NextOrg = Selected->NextOrg;
        Selected->NextOrg->PreviousOrg = Selected->PreviousOrg;
        MemberID_ORG_Decrease(Selected->NextOrg);
    }
    Selected = nullptr;
    DELETE_MESSAGE();
}

