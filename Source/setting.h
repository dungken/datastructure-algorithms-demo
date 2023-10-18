/*
 * THƯ VIỆN CÀI ĐẶT
 */
#pragma once
#include <bits/stdc++.h>
#include "lib.h"
#include "validation.h"

using namespace std;

Node *DSSV::taoSV(SV svTem)
{
    Node *newStudent = new Node();
    newStudent->sv = svTem;
    newStudent->prev = NULL;
    newStudent->next = NULL;
    return newStudent;
}

// Hàm nhập thông tin sinh viên + chuẩn hóa
void DSSV::nhapThongTin(SV &sv)
{
    string mssv, hoVaTen, email, nganhHoc, gioiTinh;
    int ngay, thang, nam;
    float diemDSA, diemOOP, diemTRR;
    // ID
    sv.id = ++ID;
    // MSSV
    do
    {
        cout << "(?) Nhap MSSV: ";
        getline(cin, mssv);
    } while (!isMSSV(mssv));

    sv.MSSV = mssv;
    // Họ và Tên
    do
    {
        cout << "(?) Nhap Ho & Ten: ";
        getline(cin, hoVaTen);
    } while (!isName(hoVaTen));
    chuanHoaChuoi(hoVaTen);
    sv.hoVaTen = hoVaTen;
    // Email
    do
    {
        cout << "(?) Nhap email: ";
        getline(cin, email);
    } while (!isEmail(email));
    sv.email = email;
    // Ngày sinh
    do
    {
        cout << "(?) Nhap ngay sinh: ";
        cin >> ngay >> thang >> nam;
    } while (!isBirth(ngay, thang, nam));
    sv.ngaySinh.ngay = ngay;
    sv.ngaySinh.thang = thang;
    sv.ngaySinh.nam = nam;
    cin.ignore();
    // Giới tính
    do
    {
        cout << "(?) Nhap gioi tinh: ";
        getline(cin, gioiTinh);
    } while (!isGender(gioiTinh));
    chuanHoaChuoi(gioiTinh);
    sv.gioiTinh = gioiTinh;
    // Ngành học
    do
    {
        cout << "(?) Nhap nganh hoc: ";
        getline(cin, nganhHoc);
    } while (!isMajors(nganhHoc));
    chuanHoaChuoi(nganhHoc);
    sv.nganhHoc = nganhHoc;
    // Điểm
    do
    {
        cout << "(?) Nhap diem 3 mon (DSA + OOP + TRR): ";
        cin >> diemDSA >> diemOOP >> diemTRR;
    } while (!isMark(diemDSA, diemOOP, diemTRR));
    sv.diem.diemDSA = diemDSA;
    sv.diem.diemOOP = diemOOP;
    sv.diem.diemTRR = diemTRR;
    cin.ignore();
}

void DSSV::themSV(SV sv)
{
    Node *newStudent = taoSV(sv);
    if (dssv == NULL)
        dssv = newStudent;
    else
    {
        newStudent->next = dssv;
        dssv = newStudent;
    }
}

void DSSV::themDanhSachSV(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << "Them sinh vien " << i << "\n";
        SV sv;
        this->nhapThongTin(sv);
        this->themSV(sv);
    }
}

void DSSV::inDanhSachSV()
{
    cout << "ID\t MSSV\t      hoVaTen\t \temail\t \t\tngay/thang/nam sinh\t gioiTinh\t nganhHoc\t OOP     DSA     TRR\n"; 
    Node* current = dssv;
    while (current != NULL)
    {
        cout << current->sv.id << " \t" << current->sv.MSSV << " \t" << current->sv.hoVaTen << " \t" << current->sv.email << " \t";
        cout << current->sv.ngaySinh.ngay << "/" << current->sv.ngaySinh.thang << "/" << current->sv.ngaySinh.nam << " \t" << current->sv.gioiTinh << " \t";
        cout << current->sv.nganhHoc << " \t" << current->sv.diem.diemOOP << "     " << current->sv.diem.diemDSA << "     " << current->sv.diem.diemTRR << endl;
        current = current ->next;
    }   
}

void DSSV::inThongTinSV(SV s)
{
    cout << s.id << " \t" << s.MSSV << " \t" << s.hoVaTen << " \t" << s.email << " \t";
        cout << s.ngaySinh.ngay << "/" << s.ngaySinh.thang << "/" << s.ngaySinh.nam << " \t" << s.gioiTinh << " \t";
        cout << s.nganhHoc << " \t" << s.diem.diemOOP << "     " << s.diem.diemDSA << "     " << s.diem.diemTRR << endl;
}

/*
6351071011
Ha Van Dung
brave2112love@gmail.com
21 12 2004
Nam
CNTT
10 8 9

6351071011
Nguyen Nguyen Huy
nguyenhuy@gmail.com
21 12 2004
Nam
CNTT
10 8 9
*/