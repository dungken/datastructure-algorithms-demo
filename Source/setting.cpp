/**
 * FILE CÀI ĐẶT
 */
#include <bits/stdc++.h>
#include "validation.h"
using namespace std;

int ID = 0;

struct Ngay
{
    int ngay, thang, nam;
};

struct Diem
{
    float diemOOP, diemDSA, diemTRR;
};

struct SV
{
    int id;          // ID sinh viên
    string MSSV;     // MSSV sinh viên
    string hoVaTen;  // Họ và Tên sinh viên
    string email;    // Email sinh viên
    Ngay ngaySinh;   // Ngày/tháng/năm sinh của sinh viên
    string gioiTinh; // Giới tính sinh viên
    string nganhHoc; // Nghành học sinh viên
    Diem diem;       // Điểm 3 môn: Lập trình hướng đối tượng, Cấu trúc dữ liệu & Giải thuật, Toán rời rạc
};

// Node lưu thông tin sinh viên
struct Node
{
    SV sv;
    Node *next;
    Node *prev;
};

// Danh sách sinh viên
class DSSV
{
private:
    Node *dssv;

public:
    DSSV()
    {
        dssv = NULL;
    }
    ~DSSV()
    {
        delete[] this->dssv;
    }

    /*THÊM THÔNG TIN SINH VIÊN*/
    Node *taoSV(SV);
    void themSV(SV);
    void themDanhSachSV(int);

    /*XUẤT THÔNG TIN SINH VIÊN*/
    void inThongTinSV(SV);
    void inDanhSachSV();

    /*CẬP NHẬT THÔNG TIN SINH VIÊN*/
    void capNhatSV(int id);
    void capNhatSV(string mssv);

    /*XÓA SINH VIÊN*/
    void xoaSV(int id[]);
    void xoaSV(string mssv);

    /*SẮP XẾP SINH VIÊN*/
    // (ID: 1) (MSSV: 2) (TEN: 3) (DTB: 4)
    void sxSVTangDanID();
    void sxSVTangDanMssv();
    void sxSVTangDanTen();
    void sxSVTangDanDTB();
    void sxSVTangDan(int);

    void sxSVGiamDanID();
    void sxSVGiamDanMssv();
    void sxSVGiamDanTen();
    void sxSVGiamDanDTB();
    void sxSVGiamDan(int);

    /*TÌM KIẾM SINH VIÊN*/
    void timKiemSV(int id);
    void timKiemSV(string ten);

    /*THỐNG KÊ SINH VIÊN*/
    // (DTB: 1) (NGANH: 2) (GIOI TINH: 3)
    void thongKeDTB();
    void thongKeNganh();
    void thongKeGioiTinh();
    void thongKe(int);

    /*XỬ LÝ ĐỌC GHI FILE*/
    void docFile();
    void ghiFile();
};

Node *DSSV::taoSV(SV svTem)
{
    Node *newStudent = new Node();
    newStudent->sv = svTem;
    newStudent->prev = NULL;
    newStudent->next = NULL;
    return newStudent;
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

// Hàm nhập thông tin sinh viên + chuẩn hóa
void nhapThongTin(SV &sv)
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
    chuanHoaMSSV(mssv);
    sv.MSSV = mssv;
    // Họ và Tên
    do
    {
        cout << "(?) Nhap Ho & Ten: ";
        getline(cin, hoVaTen);
    } while (!isName(hoVaTen));
    chuanHoaTen(hoVaTen);
    sv.hoVaTen = hoVaTen;
    // Email
    do
    {
        cout << "(?) Nhap email: ";
        getline(cin, email);
    } while (!isEmail(email));
    chuanHoaEmail(email);
    sv.email = email;
    // Ngày sinh
    do
    {
        cout << "(?) Nhap ngay sinh: ";
        cin >> ngay >> thang >> nam;
    } while (!isBirth(ngay, thang, nam));
    chuanHoaNgaySinh(ngay, thang, nam);
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
    chuanHoaGioiTinh(gioiTinh);
    sv.gioiTinh = gioiTinh;
    // Ngành học
    do
    {
        cout << "(?) Nhap nganh hoc: ";
        getline(cin, nganhHoc);
    } while (!isMajors(nganhHoc));
    chuanHoaNganh(nganhHoc);
    sv.nganhHoc = nganhHoc;
    // Điểm
    do
    {
        cout << "(?) Nhap diem 3 mon (DSA + OOP + TRR): ";
        cin >> diemDSA >> diemOOP >> diemTRR;
    } while (!isMark(diemDSA, diemOOP, diemTRR));
    chuanHoaDiem(diemDSA, diemOOP, diemTRR);
    sv.diem.diemDSA = diemDSA;
    sv.diem.diemOOP = diemOOP;
    sv.diem.diemTRR = diemTRR;
    cin.ignore();
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