#pragma once
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void backGround(){
    gotoxy(0, 2);
    cout << "+";
    for (int i = 1; i < 142; i++) cout << "-";
    cout << "+";

    for (int i = 3; i < 33; i++) {
        gotoxy(0, i);
        cout << "|";
        gotoxy(142, i);
        cout << "|";
    }

    gotoxy(0, 33);
    cout << "+";
    for (int i = 1; i < 142; i++) cout << "-";
    cout << "+";
}

void title(){
    gotoxy(1,19); cout << "ID";
    gotoxy(8,19); cout << "MSSV";
    gotoxy(20,19); cout << "Ho va ten";
    gotoxy(40,19); cout << "Gmail";
    gotoxy(60,19); cout << "Ngay/Thang/Nam";
    gotoxy(77,19); cout << "Gioi tinh";
    gotoxy(91,19); cout << "Nganh hoc";
    gotoxy(107,19); cout << "OOP";
    gotoxy(114,19); cout << "DSA";
    gotoxy(121, 19); cout <<  "TRR";
    gotoxy(128, 19); cout << "DTB\n"; 
}

void List(SV s, int i){
    gotoxy(1,19+i); cout << s.id;
    gotoxy(6,19+i); cout << s.MSSV;
    gotoxy(18,19+i); cout << s.hoVaTen;
    gotoxy(37,19+i); cout << s.email ;
    gotoxy(63,19+i); cout << s.ngaySinh.ngay << "/" << s.ngaySinh.thang << "/" << s.ngaySinh.nam;
    gotoxy(80,19+i); cout << s.gioiTinh;
    gotoxy(91,19+i); cout << s.nganhHoc;
    gotoxy(107,19+i); cout << s.diem.diemOOP;
    gotoxy(114,19+i); cout << s.diem.diemDSA;
    gotoxy(121, 19+i); cout  << s.diem.diemTRR;
    gotoxy(128, 19+i); cout << s.diem.DTB << endl; 
}

// void in(){
//     cout << id << " \t" << MSSV << " \t" << hoVaTen << " \t" << email << " \t";
//     cout << ngaySinh.ngay << "/" << ngaySinh.thang << "/" << ngaySinh.nam << " \t" << gioiTinh << " \t";
//     cout << nganhHoc << " \t" << diem.diemOOP << "     " << diem.diemDSA << "     " << diem.diemTRR << "     " << diem.DTB << endl;
// }
