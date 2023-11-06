#pragma once
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

/* HÀM IN TIÊU ĐỀ KHI XUẤT DANH SÁCH */
void printTableHeader()
{
    cout << "\t+------+--------------------+-----------------------------+---------------------------+---------------------+------------+----------------------------+-------+--------+--------+-------+" << endl;
    cout << "\t|  ID  |       MSSV         |          Ho & Ten           |          Email            |      Ngay sinh      |  Gioi Tinh |         Nganh hoc          |  OOP  |   DSA  |   TRR  |  GPA  |" << endl;
    cout << "\t+------+--------------------+-----------------------------+---------------------------+---------------------+------------+----------------------------+-------+--------+--------+-------+" << endl;
}

/* HÀM IN TỪNG DÒNG DỮ LIỆU */
void printTableRow(SV s)
{
    string ngaySinh = formatDOB(s.ngaySinh.ngay, s.ngaySinh.thang, s.ngaySinh.nam);
    cout << "\t| " << setw(4) << s.id << " | " << setw(18) << s.MSSV << " | " << setw(27) << s.hoVaTen << " | " << setw(25) << s.email << " | " << setw(19) << ngaySinh << " | " << setw(10) << s.gioiTinh << " | " << setw(26) << s.nganhHoc << " | " << setw(5) << fixed << setprecision(2) << s.diem.diemOOP << " | " << setw(6) << fixed << setprecision(2) << s.diem.diemDSA << " | " << setw(6) << fixed << setprecision(2) << s.diem.diemTRR << " | " << setw(5) << fixed << setprecision(2) << s.diem.DTB << " |" << endl;
    cout << "\t+------+--------------------+-----------------------------+---------------------------+---------------------+------------+----------------------------+-------+--------+--------+-------+" << endl;
}
