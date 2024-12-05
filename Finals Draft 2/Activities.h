#pragma once
#include "Helper_Functions.h"
class Activities: public Helper_Functions
{
public:
    struct ACTIVITIES
    {
        std::string Projects;
        std::string Activities;

        int ACTNUM = 0;
    };
    struct NODEAct
    {
        NODEAct* NextAct = nullptr, * PreviousACT = nullptr;
        ACTIVITIES Acts;
    };

    NODEAct* Count_ACT_Menu(NODEAct*&, std::string);

    void Add_ACT(NODEAct*&, NODEAct*&, NODEAct*&);
    void Create_Activities(ACTIVITIES&, int);
    int COUNT_ACT(NODEAct*&);
    NODEAct* SearchFor_Node_Activities(NODEAct*, int);

    void Read_Activities(NODEAct*);

    void UPDATE_Activities(NODEAct*&);

    void MemberID_ACT_Decrease(NODEAct*&);
    void DeleteAll_ACT(NODEAct*&, NODEAct*&);
    void Delete_Activities_Node(NODEAct*&, NODEAct*&, NODEAct*&, int&);
};

