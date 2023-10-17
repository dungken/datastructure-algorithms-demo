/*
 * THƯ VIỆN KHAI BÁO CÁC MẪU HÀM 
 */

#pragma once

#include <bits/stdc++.h>

bool isMSSV(string);
bool isName(string);
bool isEmail(string);
bool isBirth(int , int , int );
bool isGender(string);
bool isMajors(string);
bool isMark(int, int, int);

void chuanHoaMSSV(string&);
void chuanHoaTen(string&);
void chuanHoaEmail(string&);
void chuanHoaNgaySinh(int, int, int);
void chuanHoaGioiTinh(string&);
void chuanHoaNganh(string&);
void chuanHoaDiem(float, float, float);
