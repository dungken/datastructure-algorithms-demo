/*
 * THƯ VIỆN CÀI ĐẶT
 */
#pragma once

#include <bits/stdc++.h>
#include "lib.h"
#include "validation.h"

using namespace std;


// Node *DSSV::taoSV(SV svTem)
// {
//     Node *newStudent = new Node();
//     newStudent->sv = svTem;
//     newStudent->prev = NULL;
//     newStudent->next = NULL;
//     return newStudent;
// }

// void DSSV::themSV(SV sv)
// {
//     Node *newStudent = taoSV(sv);
//     if (dssv == NULL)
//         dssv = newStudent;
//     else
//     {
//         newStudent->next = dssv;
//         dssv = newStudent;
//     }
// }

// // Hàm nhập thông tin sinh viên + chuẩn hóa
// void nhapThongTin(SV &sv)
// {
//     string mssv, hoVaTen, email, nganhHoc, gioiTinh;
//     int ngay, thang, nam;
//     float diemDSA, diemOOP, diemTRR;
//     // ID
//     sv.id = ++ID;
//     // MSSV
//     do
//     {
//         cout << "(?) Nhap MSSV: ";
//         getline(cin, mssv);
//     } while (!isMSSV(mssv));
//     chuanHoaMSSV(mssv);
//     sv.MSSV = mssv;
//     // Họ và Tên
//     do
//     {
//         cout << "(?) Nhap Ho & Ten: ";
//         getline(cin, hoVaTen);
//     } while (!isName(hoVaTen));
//     chuanHoaTen(hoVaTen);
//     sv.hoVaTen = hoVaTen;
//     // Email
//     do
//     {
//         cout << "(?) Nhap email: ";
//         getline(cin, email);
//     } while (!isEmail(email));
//     chuanHoaEmail(email);
//     sv.email = email;
//     // Ngày sinh
//     do
//     {
//         cout << "(?) Nhap ngay sinh: ";
//         cin >> ngay >> thang >> nam;
//     } while (!isBirth(ngay, thang, nam));
//     chuanHoaNgaySinh(ngay, thang, nam);
//     sv.ngaySinh.ngay = ngay;
//     sv.ngaySinh.thang = thang;
//     sv.ngaySinh.nam = nam;
//     cin.ignore();
//     // Giới tính
//     do
//     {
//         cout << "(?) Nhap gioi tinh: ";
//         getline(cin, gioiTinh);
//     } while (!isGender(gioiTinh));
//     chuanHoaGioiTinh(gioiTinh);
//     sv.gioiTinh = gioiTinh;
//     // Ngành học
//     do
//     {
//         cout << "(?) Nhap nganh hoc: ";
//         getline(cin, nganhHoc);
//     } while (!isMajors(nganhHoc));
//     chuanHoaNganh(nganhHoc);
//     sv.nganhHoc = nganhHoc;
//     // Điểm
//     do
//     {
//         cout << "(?) Nhap diem 3 mon (DSA + OOP + TRR): ";
//         cin >> diemDSA >> diemOOP >> diemTRR;
//     } while (!isMark(diemDSA, diemOOP, diemTRR));
//     chuanHoaDiem(diemDSA, diemOOP, diemTRR);
//     sv.diem.diemDSA = diemDSA;
//     sv.diem.diemOOP = diemOOP;
//     sv.diem.diemTRR = diemTRR;
//     cin.ignore();
// }

bool isBrith(int a, int b, int c){
    if(a <= 0 || a > 30) return false;
    if(b <= 0 || b > 12) return false;
    if(c <=0 ) return false;
    return true;
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