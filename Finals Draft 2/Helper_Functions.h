#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <Windows.h>
class Helper_Functions
{
public: 
    int Main_Menu();
    int Create_Menu();
    int Update_Menu();
    int Delete_Menu();

    bool CheckingInput_Validity(int, int);
    void INPUTING(std::string&, std::string);

    void DELETE_MESSAGE();
    void NO_ORG_MESSAGE();
    void NO_STUDENT_MESSAGE();
    void EMPTYLIST_READ_MESSAGE();
    void EMPTYLIST_MESSAGE();
    void INVALID_INPUT_MESSAGE();
    void UPDATE_MESSAGE();
    void EXIT_MESSAGE();
};

