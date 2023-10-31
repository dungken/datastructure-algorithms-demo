/**
 * FILE CHÍNH XỬ LÝ CHƯƠNG TRÌNH
 */

#include <bits/stdc++.h>
#include "setting.h"
#include "lib.h"
#include "validation.h"
#include "implement_Validation.h"
#include "ortherFunctions.h"
#include "implement_ortherFuntions.h"
using namespace std;

void Menu(DSSV dssv);

int main() {
    DSSV dssv;
    Menu(dssv);
    return 0;
}

void Menu(DSSV dssv) {
    while(true) {
        int tem;
        system("cls");
        cout << "\n	        CHUONG TRINH QUAN LI SINH VIEN - UTC2 - IT K63           ";
        cout << "\n	+----------------------------------------------------------------+";
        cout << "\n	| [1]. Them moi sinh vien           | [6]. Xoa sinh vien         |";
        cout << "\n	| [2]. Hien thi sinh vien hien co   | [7]. Thong ke sinh vien    |";
        cout << "\n	| [3]. Cap nhat thong tin sinh vien | [8]. Doc & Ghi file        |";
        cout << "\n	| [4]. Tim kiem sinh vien           | [0]. Thoat chuong trinh    |";
        cout << "\n	| [5]. Sap xep sinh vien            |                            |";
        cout << "\n	+----------------------------------------------------------------+";
        int chon;
        cout << "\n\n\tNhap lua chon: ";
        cin >> chon;
        switch (chon) {
            case 1:
                do {
                    cout << "\t[0]. Quay lai";
                    cout << "\n\t[1]. Them 1 sinh vien";
                    cout << "\n\t[2]. Them nhieu sinh vien\n\n";
                    cout << "\t(?): ";
                    cin >> tem;
                }while(tem != 1 && tem != 2 && tem != 0);
                if(tem == 0) {
                    Menu(dssv);
                } else if(tem == 1) {
                    SV sv;
                    cin.ignore();
                    dssv.nhapThongTin(sv);
                    dssv.themSV(sv);
                    dssv.inThongTinSV(sv);
                }else {
                    int n;
                    cout << "\n\t(?) So luong sinh vien: ";
                    cin >> n;
                    cin.ignore();
                    dssv.themDanhSachSV(n);
                }
                dssv.ghiFile();
                cout << "\t";
                system("pause");
                break;
            case 2:
                dssv.inDanhSachSV();
                cout << "\t";
                system("pause");
                break;
            case 3:
                do {
                    cout << "\t[0]. Quay lai";
                    cout << "\n\t[1]. Cap nhat bang ID";
                    cout << "\n\t[2]. Cap nhat bang MSSV\n\n";
                    cout << "\t(?): ";
                    cin >> tem;
                }while(tem != 1 && tem != 2 && tem != 0);
                cin.ignore();
                if(tem == 0) {
                    Menu(dssv);
                } else if(tem == 1) {
                    dssv.capNhatSVBangID();
                }else {
                    dssv.capNhatSVBangMSSV();
                }
                dssv.ghiFile();
                cout << "\t";
                system("pause");
                break;
            case 4:
                do {
                    cout << "\t[0]. Quay lai";
                    cout << "\n\t[1]. Tim kiem bang ID";
                    cout << "\n\t[2]. Tim kiem bang Ten\n\n";
                    cout << "\t(?): ";
                    cin >> tem;
                }while(tem != 1 && tem != 2 && tem != 0);
                if(tem == 0) {
                    Menu(dssv);
                } else if(tem == 1) {
                    cout << "\t(?) Nhap ID: ";
                    int id;
                    cin >> id;
                    dssv.timKiemSV(id);
                }else {
                    string hoVaTen;
                    cout << "\t(?) Nhap Ten: ";
                    cin.ignore();
                    getline(cin, hoVaTen);
                    dssv.timKiemSV(hoVaTen);
                }
                cout << "\t";
                system("pause");
                break;
            case 5:
                do {
                    cout << "\t[0]. Quay lai";
                    cout << "\n\t[1]. Tang dan";
                    cout << "\n\t[2]. Giam dan\n\n";
                    cout << "\t(?): ";
                    cin >> tem;
                }while(tem != 1 && tem != 2 && tem != 0);
                if(tem == 0) {
                    Menu(dssv);
                } else if(tem == 1) {
                    dssv.sxSVTangDan();
                }else {
                    dssv.sxSVGiamDan();
                }
                cout << "\t";
                system("pause");
                break;
            case 6:
                do {
                    cout << "\t[0]. Quay lai";
                    cout << "\n\t[1]. Xoa theo ID";
                    cout << "\n\t[2]. Xoa theo MSSV\n\n";
                    cout << "\t(?): ";
                    cin >> tem;
                }while(tem != 1 && tem != 2 && tem != 0);
                if(tem == 0) {
                    Menu(dssv);
                } else if(tem == 1) {
                    int n, id[dssv.soLuong()];
                    cout << "\tNhap so luong SV can xoa: ";
                    cin >> n;
                    cout << "\tNhap danh sach ID can xoa: ";
                    for(int i= 0; i < n; i++) {
                        cin >> id[i];
                    }
                    dssv.xoaSV(id, n);
                }else {
                    string mssv;
                    do
                    {
                        cout << "\t(?) Nhap MSSV: ";
                        cin.ignore();
                        getline(cin, mssv);
                    } while (!isMSSV(mssv));
                    dssv.xoaSV(mssv);
                }
                dssv.ghiFile();
                cout << "\t";
                system("pause");
                break;
            case 7:
                dssv.thongKe();
                cout << "\t";
                system("pause");
                break;
            case 8:
                do {
                    cout << "\t[0]. Quay lai";
                    cout << "\n\t[1]. Ghi file";
                    cout << "\n\t[2]. Doc file\n\n";
                    cout << "\t(?): ";
                    cin >> tem;
                }while(tem != 1 && tem != 2 && tem != 0);
                if(tem == 0) {
                    Menu(dssv);
                } else if(tem == 1) {
                    dssv.ghiFile();
                }else {
                    dssv.docFile();
                }
                cout << "\t";
                system("pause");
                break;
            default:
                return;
        }
    }
}