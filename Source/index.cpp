#include <bits/stdc++.h>
#include "LibMain.h"
#include "LibSettingMain.h"
#include "LibValidation.h"
#include "LibSettingValidation.h"
#include "LibOthers.h"
#include "LibSettingOthers.h"
#include "Graphic.h"

using namespace std;



DSSV dssv;
void Menu();
void SubMenu1();
void SubMenu2();
void SubMenu3();
void SubMenu4();
void SubMenu5();
void SubMenu6();
void SubMenu7();
void SubMenu8();
void SubMenu9();

int main()
{
    Menu();
    return 0;
}

void Menu()
{
    while (true)
    {
        int tem;
        system("cls");
        cout << "\n	        \tCHUONG TRINH QUAN LI SINH VIEN - UTC2 - IT K63           ";
        cout << "\n\t	+----------------------------------------------------------------+";
        cout << "\n\t	| [1]. Them moi sinh vien           | [6]. Xoa sinh vien         |";
        cout << "\n\t	| [2]. Hien thi sinh vien hien co   | [7]. Thong ke sinh vien    |";
        cout << "\n\t	| [3]. Cap nhat thong tin sinh vien | [8]. Doc & Ghi file        |";
        cout << "\n\t	| [4]. Tim kiem sinh vien           | [9]. So sanh thoi gian     |";
        cout << "\n\t	| [5]. Sap xep sinh vien            | [0]. Thoat chuong trinh    |";
        cout << "\n\t	+----------------------------------------------------------------+";
        int chon;
        cout << "\n\n\t\tNhap lua chon: ";
        cin >> chon;
        switch (chon)
        {
        case 1:
            SubMenu1();
            system("pause");
            break;
        case 2:
            SubMenu2();
            system("pause");
            break;
        case 3:
            SubMenu3();
            system("pause");
            break;
        case 4:
            SubMenu4();
            system("pause");
            break;
        case 5:
            SubMenu5();
            system("pause");
            break;
        case 6:
            SubMenu6();
            system("pause");
            break;
        case 7:
            SubMenu7();
            system("pause");
            break;
        case 8:
            SubMenu8();
            system("pause");
            break;
        case 9:
            SubMenu9();
            system("pause");
            break;
        default:
            return;
        }
    }
}

void SubMenu1()
{
    int choiceSub;
    do
    {
        cout << "\t\t[0]. Quay lai";
        cout << "\n\t\t[1]. Them 1 sinh vien";
        cout << "\n\t\t[2]. Them nhieu sinh vien\n\n";
        cout << "\t\t(?): ";
        cin >> choiceSub;
    } while (choiceSub != 1 && choiceSub != 2 && choiceSub != 0);
    if (choiceSub == 0)
    {
        Menu();
    }
    else if (choiceSub == 1)
    {
        SV sv;
        cin.ignore();
        dssv.nhapThongTin(sv);
        if (dssv.kiemTraMSSVTonTai(sv.MSSV))
        {
            cout << endl;
            cout << "\t\t\t+------------------------------------------+\n";
            cout << "\t\t\t|     Ma so sinh vien da ton tai roi !     |\n";
            cout << "\t\t\t+------------------------------------------+\n";
            cout << endl;
        }
        else
        {
            dssv.themSV(sv);
            cout << endl;
            cout << "\t\t\t+-----------------------------------+\n";
            cout << "\t\t\t|    Da them sinh vien thanh cong!  |\n";
            cout << "\t\t\t+-----------------------------------+\n";
            cout << endl;
            dssv.inThongTinSV(sv);
        }
    }
    else
    {
        int n;
        cout << "\n\t\t(?) So luong sinh vien: ";
        cin >> n;
        cin.ignore();
        dssv.themDanhSachSV(n);
        cout << endl;
        cout << "\t\t\t+-----------------------------------+\n";
        cout << "\t\t\t|  Da them " << n << " sinh vien thanh cong!  |\n";
        cout << "\t\t\t+-----------------------------------+\n";
        cout << endl;
        if (n != 0)
            dssv.inDanhSachSV();
    }
    dssv.ghiFile();
    cout << "\t\t";
}

void SubMenu2()
{
    if (dssv.kiemTraSinhVienTonTai())
    {
        dssv.inDanhSachSV();
    }
    else
    {
        cout << endl;
        cout << "\t\t\t+-----------------------------------+\n";
        cout << "\t\t\t| Chua co sinh vien trong he thong! |\n";
        cout << "\t\t\t+-----------------------------------+\n";
        cout << endl;
    }
    cout << "\t\t";
}

void SubMenu3()
{
    int tem;
    if (dssv.kiemTraSinhVienTonTai())
    {
        do
        {
            cout << "\t\t[0]. Quay lai";
            cout << "\n\t\t[1]. Cap nhat bang ID";
            cout << "\n\t\t[2]. Cap nhat bang MSSV\n\n";
            cout << "\t\t(?): ";
            cin >> tem;
        } while (tem != 1 && tem != 2 && tem != 0);
        cin.ignore();
        if (tem == 0)
        {
            Menu();
        }
        else if (tem == 1)
        {
            dssv.capNhatSVBangID();
        }
        else
        {
            dssv.capNhatSVBangMSSV();
        }
    }
    else
    {
        cout << endl;
        cout << "\t\t\t+-----------------------------------+\n";
        cout << "\t\t\t| Chua co sinh vien trong he thong! |\n";
        cout << "\t\t\t+-----------------------------------+\n";
        cout << endl;
    }
    cout << "\t\t";
}

void SubMenu4()
{
    int tem;
    if (dssv.kiemTraSinhVienTonTai())
    {
        do
        {
            cout << "\t\t[0]. Quay lai";
            cout << "\n\t\t[1]. Tim kiem bang ID";
            cout << "\n\t\t[2]. Tim kiem bang Ten\n\n";
            cout << "\t\t(?): ";
            cin >> tem;
        } while (tem != 1 && tem != 2 && tem != 0);
        if (tem == 0)
        {
            Menu();
        }
        else if (tem == 1)
        {
            cout << "\t\t(?) Nhap ID: ";
            int id;
            cin >> id;
            dssv.timKiemSvTuyenTinh(id);
        }
        else
        {
            string hoVaTen;
            cout << "\t\t(?) Nhap Ten: ";
            cin.ignore();
            getline(cin, hoVaTen);
            dssv.timKiemSvTuyenTinh(hoVaTen);
        }
    }
    else
    {
        cout << endl;
        cout << "\t\t\t+-----------------------------------+\n";
        cout << "\t\t\t| Chua co sinh vien trong he thong! |\n";
        cout << "\t\t\t+-----------------------------------+\n";
        cout << endl;
    }
    cout << "\t\t";
}

void SubMenu5()
{
    int tem;
    if (dssv.kiemTraSinhVienTonTai())
    {
        do
        {
            cout << "\t\t[0]. Quay lai";
            cout << "\n\t\t[1]. Tang dan";
            cout << "\n\t\t[2]. Giam dan\n\n";
            cout << "\t\t(?): ";
            cin >> tem;
        } while (tem != 1 && tem != 2 && tem != 0);
        if (tem == 0)
        {
            Menu();
        }
        else if (tem == 1)
        {
            dssv.sxSVTangDan();
        }
        else
        {
            dssv.sxSVGiamDan();
        }
    }
    else
    {
        cout << endl;
        cout << "\t\t\t+-----------------------------------+\n";
        cout << "\t\t\t| Chua co sinh vien trong he thong! |\n";
        cout << "\t\t\t+-----------------------------------+\n";
        cout << endl;
    }
    cout << "\t\t";
}
void SubMenu6()
{
    int tem;
    if (dssv.kiemTraSinhVienTonTai())
    {
        do
        {
            cout << "\t\t[0]. Quay lai";
            cout << "\n\t\t[1]. Xoa theo ID";
            cout << "\n\t\t[2]. Xoa theo MSSV\n\n";
            cout << "\t\t(?): ";
            cin >> tem;
        } while (tem != 1 && tem != 2 && tem != 0);
        if (tem == 0)
        {
            Menu();
        }
        else if (tem == 1)
        {
            int n;
            cout << "\t\tNhap so luong SV can xoa: ";
            cin >> n;
            int listId[n + 1];
            dssv.inDanhSachSV();
            cout << "\t\tNhap danh sach ID can xoa: ";
            for (int i = 0; i < n; i++)
            {
                cin >> listId[i];
            }
            dssv.xoaSV(listId, n);
        }
        else
        {
            string mssv;
            dssv.inDanhSachSV();
            do
            {
                cout << "\t\t(?) Nhap MSSV: ";
                cin.ignore();
                getline(cin, mssv);
            } while (!isMSSV(mssv));
            dssv.xoaSV(mssv);
            dssv.inDanhSachSV();
        }
        dssv.ghiFile();
    }
    else
    {
        cout << endl;
        cout << "\t\t\t+-----------------------------------+\n";
        cout << "\t\t\t| Chua co sinh vien trong he thong! |\n";
        cout << "\t\t\t+-----------------------------------+\n";
        cout << endl;
    }
    cout << "\t\t";
}
void SubMenu7()
{
    if (dssv.kiemTraSinhVienTonTai())
    {
        dssv.thongKe();
    }
    else
    {
        cout << endl;
        cout << "\t\t\t+-----------------------------------+\n";
        cout << "\t\t\t| Chua co sinh vien trong he thong! |\n";
        cout << "\t\t\t+-----------------------------------+\n";
        cout << endl;
    }

    cout << "\t\t";
}
void SubMenu8()
{
    int tem;
    do
    {
        cout << "\t\t[0]. Quay lai";
        cout << "\n\t\t[1]. Ghi file";
        cout << "\n\t\t[2]. Doc file\n\n";
        cout << "\t\t(?): ";
        cin >> tem;
    } while (tem != 1 && tem != 2 && tem != 0);
    if (tem == 0)
    {
        Menu();
    }
    else if (tem == 1)
    {
        dssv.ghiFile(1);
    }
    else
    {
        dssv.docFile(1);
    }
    cout << "\t\t";
}

void SubMenu9()
{
    int tem;
    do
    {
        cout << "\t\t[0]. Quay lai";
        cout << "\n\t\t[1]. SelectionSort & QuickSort";
        cout << "\n\t\t[2]. MergeSort & QuickSort";
        cout << "\n\t\t[3]. Linear Search & Binary Search\n";
        cout << "\t\t(?): ";
        cin >> tem;
    } while (tem != 1 && tem != 2 && tem != 3 && tem != 0);
    if (tem == 0)
    {
        Menu();
    }
    else if (tem == 1)
    {
        dssv.soSanhThoiGianSapXep1();
    }
    else if (tem == 2)
    {
        dssv.soSanhThoiGianSapXep2();
    }
    else
    {
        dssv.soSanhThoiGianTimKiem();
    }
    cout << "\t\t";
}
