#pragma once
#include "Organizations.h"
class Students: public Organizations
{
public:
    struct STUDENT
    {
        std::string Fname;
        std::string Lname;
        std::string Birthday;
        std::string Age;
        std::string Gender;
        std::string Address;
        std::string ContNum;
        std::string EMail;
        std::string ID;
        std::string Course;
        int MemberID = 0;

        NODEOrg* HeadOrg = nullptr, * TailOrg = nullptr;
    };
    struct NODEStudent
    {
        NODEStudent* NextStudent = nullptr, * PreviousStudent = nullptr;
        STUDENT Students;
    };

    void Add_Student(NODEStudent*&, NODEStudent*&, NODEStudent*&);
    void Create_Students(STUDENT&, int);

    int SearchingLoop(NODEStudent*, std::string, int);
    NODEStudent* SearchFor_Node_Student(NODEStudent*, int);

    int Short_Read(NODEStudent*);
    void Read_Student(NODEStudent*);
    
    void UPDATE_Student(NODEStudent*&);

    void MemberID_Decrease(NODEStudent*&);
    void DeleteAll(NODEStudent*&, NODEStudent*&, int&);
    void Delete_Student_Node(NODEStudent*&, NODEStudent*&, NODEStudent*&, int&);
};

