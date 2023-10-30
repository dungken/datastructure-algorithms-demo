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
    // Điểm trung bình
    sv.diem.DTB = (sv.diem.diemDSA + sv.diem.diemOOP + sv.diem.diemTRR) / 3;
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
    cout << "ID\t MSSV\t      hoVaTen\t \temail\t \t\tngay/thang/nam sinh\t gioiTinh\t nganhHoc\t OOP     DSA     TRR    DTB\n";
    Node *current = dssv;
    while (current != NULL)
    {
        cout << current->sv.id << " \t" << current->sv.MSSV << " \t" << current->sv.hoVaTen << " \t" << current->sv.email << " \t";
        cout << current->sv.ngaySinh.ngay << "/" << current->sv.ngaySinh.thang << "/" << current->sv.ngaySinh.nam << " \t" << current->sv.gioiTinh << " \t";
        cout << current->sv.nganhHoc << " \t" << current->sv.diem.diemOOP << "     " << current->sv.diem.diemDSA << "     " << current->sv.diem.diemTRR << "     " << current->sv.diem.DTB << endl;
        current = current->next;
    }
}
void DSSV::inThongTinSV(SV s)
{
    cout << s.id << " \t" << s.MSSV << " \t" << s.hoVaTen << " \t" << s.email << " \t";
    cout << s.ngaySinh.ngay << "/" << s.ngaySinh.thang << "/" << s.ngaySinh.nam << " \t" << s.gioiTinh << " \t";
    cout << s.nganhHoc << " \t" << s.diem.diemOOP << "     " << s.diem.diemDSA << "     " << s.diem.diemTRR << "     " << s.diem.DTB << endl;
}
void DSSV::docFile()
{
    ifstream docDuLieu("data.txt");
    string line;
    while (getline(docDuLieu, line))
    {
        stringstream ss(line);
        string id, mssv, ten, email, ngay, thang, nam, gioiTinh, nganh, dsa, oop, trr, dtb;
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
        getline(ss, dtb, ';');
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
        sv.diem.DTB = stof(dtb);
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
        << fixed << setprecision(2) << tem->sv.diem.DTB << ";" << "\n";
        tem = tem->next;
    }
    xuatDuLieu.close();
}

void DSSV::capNhatSvTheoTen(Node *nodeFound)
{
    cin.ignore();
    string hoVaTen;
    do
    {
        cout << "(?) Nhap Ho & Ten: ";
        getline(cin, hoVaTen);
    } while (!isName(hoVaTen));
    chuanHoaChuoi(hoVaTen);
    // Thuc hien cap nhat ho va ten
    Node *temp = dssv;
    while (temp != NULL)
    {
        if (temp->sv.id == nodeFound->sv.id)
        {
            temp->sv.hoVaTen = hoVaTen;
            break;
        }
        temp = temp->next;
    }
    cout << "Cap nhat ten thanh cong!";
}

void DSSV::capNhatSvTheoEmail(Node *nodeFound)
{
    cin.ignore();
    string email;
    do
    {
        cout << "(?) Nhap email: ";
        getline(cin, email);
    } while (!isEmail(email));
    // Thuc hien cap nhat email
    Node *temp = dssv;
    while (temp != NULL)
    {
        if (temp->sv.id == nodeFound->sv.id)
        {
            temp->sv.email = email;
            break;
        }
        temp = temp->next;
    }
    cout << "Cap nhat email thanh cong!";
}
void DSSV::capNhatSvTheoNgaySinh(Node *nodeFound)
{
    int ngay, thang, nam;
    do
    {
        cout << "(?) Nhap ngay sinh: ";
        cin >> ngay >> thang >> nam;
    } while (!isBirth(ngay, thang, nam));
    // Thuc hien cap nhat ngay sinh
    Node *temp = dssv;
    while (temp != NULL)
    {
        if (temp->sv.id == nodeFound->sv.id)
        {
            temp->sv.ngaySinh.ngay = ngay;
            temp->sv.ngaySinh.thang = thang;
            temp->sv.ngaySinh.nam = nam;
            break;
        }
        temp = temp->next;
    }
    cout << "Cap nhat ngay sinh thanh cong!";
}
void DSSV::capNhatSvTheoGioiTinh(Node *nodeFound)
{
    cin.ignore();
    string gioiTinh;
    do
    {
        cout << "(?) Nhap gioi tinh: ";
        getline(cin, gioiTinh);
    } while (!isGender(gioiTinh));
    chuanHoaChuoi(gioiTinh);
    // Thuc hien cap nhat gioi tinh
    Node *temp = dssv;
    while (temp != NULL)
    {
        if (temp->sv.id == nodeFound->sv.id)
        {
            temp->sv.gioiTinh = gioiTinh;
            break;
        }
        temp = temp->next;
    }
    cout << "Cap nhat gioi tinh thanh cong!";
}
void DSSV::capNhatSvTheoNganh(Node *nodeFound)
{
    cin.ignore();
    string nganhHoc;
    do
    {
        cout << "(?) Nhap nganh hoc: ";
        getline(cin, nganhHoc);
    } while (!isMajors(nganhHoc));
    chuanHoaChuoi(nganhHoc);
    // Thuc hien cap nhat nganh
    Node *temp = dssv;
    while (temp != NULL)
    {
        if (temp->sv.id == nodeFound->sv.id)
        {
            temp->sv.nganhHoc = nganhHoc;
            break;
        }
        temp = temp->next;
    }
    cout << "Cap nhat nganh hoc thanh cong!";
}
void DSSV::capNhatSvTheoDiem(Node *nodeFound)
{
    float diemDSA, diemOOP, diemTRR;
    do
    {
        cout << "(?) Nhap diem 3 mon (DSA + OOP + TRR): ";
        cin >> diemDSA >> diemOOP >> diemTRR;
    } while (!isMark(diemDSA, diemOOP, diemTRR));
    // Thuc hien cap nhat diem
    Node *temp = dssv;
    while (temp != NULL)
    {
        if (temp->sv.id == nodeFound->sv.id)
        {
            temp->sv.diem.diemDSA = diemDSA;
            temp->sv.diem.diemOOP = diemOOP;
            temp->sv.diem.diemTRR = diemTRR;
            break;
        }
        temp = temp->next;
    }
    cout << "Cap nhat diem thanh cong!";
}

void DSSV::capNhatSVBangID()
{
    cout << "(?) Nhap ID: ";
    int id;
    cin >> id;
    Node *temp = layNodeTheoId(this->dssv, id);
    if (temp == NULL)
        cout << "Khong co ID can cap nhat!";
    else
    {
        int chon;
        cout << "1. Cap nhat ten.\n";
        cout << "2. Cap nhat email.\n";
        cout << "3. Cap nhat ngay sinh.\n";
        cout << "4. Cap nhat gioi tinh.\n";
        cout << "5. Cap nhat nganh.\n";
        cout << "6. Cap nhat diem.\n";
        cout << "(?) Nhap lua chon: ";
        cin >> chon;
        switch (chon)
        {
        case 1:
            this->capNhatSvTheoTen(temp);
            break;
        case 2:
            this->capNhatSvTheoEmail(temp);
            break;
        case 3:
            this->capNhatSvTheoNgaySinh(temp);
            break;
        case 4:
            this->capNhatSvTheoGioiTinh(temp);
            break;
        case 5:
            this->capNhatSvTheoNganh(temp);
            break;
        case 6:
            this->capNhatSvTheoDiem(temp);
            break;
        default:
            break;
        }
    }
}

void DSSV::capNhatSVBangMSSV()
{
    string mssv;
    do
    {
        cout << "(?) Nhap MSSV: ";
        getline(cin, mssv);
    } while (!isMSSV(mssv));
    Node *temp = layNodeTheoMSSV(this->dssv, mssv);
    if (temp == NULL)
        cout << "Khong co MSSV can cap nhat!";
    else
    {
        int chon;
        cout << "1. Cap nhat ten.\n";
        cout << "2. Cap nhat email.\n";
        cout << "3. Cap nhat ngay sinh.\n";
        cout << "4. Cap nhat gioi tinh.\n";
        cout << "5. Cap nhat nganh.\n";
        cout << "6. Cap nhat diem.\n";
        cout << "(?) Nhap lua chon: ";
        cin >> chon;
        switch (chon)
        {
        case 1:
            this->capNhatSvTheoTen(temp);
            break;
        case 2:
            this->capNhatSvTheoEmail(temp);
            break;
        case 3:
            this->capNhatSvTheoNgaySinh(temp);
            break;
        case 4:
            this->capNhatSvTheoGioiTinh(temp);
            break;
        case 5:
            this->capNhatSvTheoNganh(temp);
            break;
        case 6:
            this->capNhatSvTheoDiem(temp);
            break;
        default:
            break;
        }
    }
}

void DSSV::sxSVTangDanID()
{
    quickSort(this->dssv, "ID");
}
void DSSV::sxSVTangDanTen()
{
    quickSort(this->dssv, "TEN");
}
void DSSV::sxSVTangDanDTB()
{
    quickSort(this->dssv, "DTB");
}

void DSSV::sxSVTangDan()
{
    cout << "1. Tang dan theo ID.\n";
    cout << "2. Tang dan theo Ten.\n";
    cout << "3. Tang dan theo DTB.\n";
    int chon;
    cout << "(?) Nhap lua chon: ";
    cin >> chon;
    switch (chon)
    {
    case 1:
        this->sxSVTangDanID();
        break;
    case 2:
        this->sxSVTangDanTen();
        break;
    case 3:
        this->sxSVTangDanDTB();
        break;
    default:
        break;
    }
}