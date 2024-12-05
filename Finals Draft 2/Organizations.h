#pragma once
#include "Activities.h"

class Organizations: public Activities
{
public: 
    struct Organization
    {
        std::string Organization;
        std::string Role;
        int ROLENUM = 0;

        NODEAct* HeadAct = nullptr, * TailAct = nullptr;
    };
    struct NODEOrg
    {
        NODEOrg* NextOrg = nullptr, * PreviousOrg = nullptr;
        Organization membership;
    };

    NODEOrg* Count_Org_Menu(NODEOrg*&, std::string);

    void Add_ORG(NODEOrg*&, NODEOrg*&, NODEOrg*&);
    void Create_Organizations(Organization&, int);
    int COUNT_ORG(NODEOrg*&);
    NODEOrg* SearchFor_Node_Organizations(NODEOrg*, int);

    void Short_Read_Organization(NODEOrg*);
    void Read_Organization(NODEOrg*);

    void UPDATE_Organization(NODEOrg*&);

    void MemberID_ORG_Decrease(NODEOrg*&);
    void DeleteAll_ORG(NODEOrg*&, NODEOrg*&);
    void Delete_Organization_Node(NODEOrg*&, NODEOrg*&, NODEOrg*&, int&);
};

