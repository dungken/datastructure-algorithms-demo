/*
 * THƯ VIỆN CÀI ĐẶT
 */
#pragma once
#include <bits/stdc++.h>
#include "lib.h"
#include "validation.h"
#include "ortherFunctions.h"

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

void DSSV::docFile()
{
    ifstream docDuLieu("data.txt");
    string line;
    while (getline(docDuLieu, line))
    {
        stringstream ss(line);
        string id, mssv, ten, email, ngay, thang, nam, gioiTinh, nganh, dsa, oop, trr;
        getline(ss, id, ';');
        getline(ss, mssv, ';');
        getline(ss, ten, ';');
        getline(ss, email, ';');
        getline(ss, ngay, ';');
        getline(ss, thang, ';');
        getline(ss, nam, ';');
        getline(ss, gioiTinh, ';');
        getline(ss, nganh, ';');
        getline(ss, dsa, ';');
        getline(ss, oop, ';');
        getline(ss, trr, ';');
        SV sv;
        sv.id = stoi(id);
        sv.MSSV = mssv;
        sv.hoVaTen = ten;
        sv.email = email;
        sv.ngaySinh.ngay = stoi(ngay);
        sv.ngaySinh.thang = stoi(thang);
        sv.ngaySinh.nam = stoi(nam);
        sv.gioiTinh = gioiTinh;
        sv.nganhHoc = nganh;
        sv.diem.diemDSA = stof(dsa);
        sv.diem.diemOOP = stof(oop);
        sv.diem.diemTRR = stof(trr);
        themSV(sv);
    }
    docDuLieu.close();
}

void DSSV::ghiFile()
{
    ofstream xuatDuLieu;
    xuatDuLieu.open("data.txt");
    if (!xuatDuLieu)
    {
        cout << "File khong the mo!" << endl;
        exit(1);
    }
    Node *tem = dssv;
    while (tem != NULL)
    {
        xuatDuLieu << tem->sv.id << ";" << tem->sv.MSSV << ";"
                   << tem->sv.hoVaTen << ";" << tem->sv.email << ";"
                   << tem->sv.ngaySinh.ngay << ";" << tem->sv.ngaySinh.thang << ";" << tem->sv.ngaySinh.nam
                   << ";" << tem->sv.gioiTinh << ";" << tem->sv.nganhHoc
                   << ";" << tem->sv.diem.diemDSA << ";" << tem->sv.diem.diemOOP << ";" << tem->sv.diem.diemTRR << ";"
                   << "\n";
        tem = tem->next;
    }
    xuatDuLieu.close();
}
