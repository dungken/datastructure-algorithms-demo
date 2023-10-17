/*
THƯ VIỆN CÀI ĐẶT CÁC HÀM TRONG validation.h
*/

#pragma once

#include <bits/stdc++.h>
#include "validation.h"
using namespace std;

bool isMSSV(string mssv)
{
    if (mssv.length() != 10)
        return false;
    for (char x : mssv)
    {
        if (!isdigit(x))
            return false;
    }
    return true;
}

bool isName(string name)
{
    if (name.length() < 5)
        return false;
    for (char x : name)
    {
        tolower(x);
        if (!isalpha(x) || x != ' ')
            return false;
    }
    return true;
}

bool isKTDB(char c)
{
    return !isalpha(c) && !isdigit(c);
}

bool isEmail(string email)
{
    string strSearch = "@gmail.com";
    size_t foundPos = email.find(strSearch);
    if (foundPos == string::npos)
        return false;
    if (isKTDB(email[0]))
        return false;
    int cntCC = 0, cntSo = 0;
    for (char x : email)
    {
        if (x == ' ')
            return false;
        if (isalpha(x))
            ++cntCC;
        else if (isdigit(x))
            ++cntSo;
    }
    if (cntCC && cntSo)
        return true;
    return false;
}

bool isBirth(int ngay, int thang, int nam)
{
    if (ngay < 1)
        return false;
    if (thang < 1 || thang > 12)
        return false;
    if (nam < 1)
        return false;
    if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
    {
        if (ngay > 31)
            return false;
    }
    else if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
    {
        if (ngay > 30)
            return false;
    }
    else
    {
        if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
        {
            if (ngay > 29)
                return false;
        }
        else
        {
            if (ngay > 28)
                return false;
        }
    }
    return true;
}

bool isGender(string gender)
{
    if (gender.length() != 2 || gender.length() != 3)
        return false;
    for (char x : gender)
    {
        if (!isalpha(x))
            return false;
    }
}
bool isMajors(string nganh)
{
    for (char x : nganh)
    {
        if (!isalpha(x))
            return false;
    }
}

bool isMark(float dsa, float oop, float trr)
{
    return (dsa >= 0 && dsa <= 10) && (oop >= 0 && oop <= 10) && (trr >= 0 && trr <= 10);
}

void chuanHoaChuoi(string &str)
{
    // Xóa ký tự khoảng trắng trong chuỗi
    int i = 0;
    while (i < str.length())
    {
        if (isspace(str[i]))
        {
            int j = i + 1;
            while (j < str.length() && isspace(str[j]))
            {
                j++;
            }
            str.erase(i, j - i - 1);
        }
        i++;
    }
    // Xóa khoảng trắng cuối chuỗi nếu có
    if (!str.empty() && isspace(str[str.length() - 1]))
    {
        str.pop_back();
    }
    // Đổi các ký tự đầu của các từ thành ký tự in hoa
    bool isFirstChar = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (isFirstChar && isalpha(str[i]))
        {
            str[i] = toupper(str[i]);
            isFirstChar = false;
        }
        else if (isspace(str[i]))
        {
            isFirstChar = true;
        }
    }
}
