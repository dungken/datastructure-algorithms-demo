/*
 * THƯ VIỆN CÀI ĐẶT
 */
#pragma once
#include <bits/stdc++.h>
#include "lib.h"
#include "validation.h"
#include "ortherFunctions.h"
#include "Graphic.h"

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
        cout << "\t\t(?) Nhap MSSV: ";
        getline(cin, mssv);
    } while (!isMSSV(mssv));

    sv.MSSV = mssv;
    // Họ và Tên
    do
    {
        cout << "\t\t(?) Nhap Ho & Ten: ";
        getline(cin, hoVaTen);
    } while (!isName(hoVaTen));
    chuanHoaChuoi(hoVaTen);
    sv.hoVaTen = hoVaTen;
    // Email
    do
    {
        cout << "\t\t(?) Nhap email: ";
        getline(cin, email);
    } while (!isEmail(email));
    sv.email = email;
    // Ngày sinh
    do
    {
        cout << "\t\t(?) Nhap ngay sinh: ";
        cin >> ngay >> thang >> nam;
    } while (!isBirth(ngay, thang, nam));
    sv.ngaySinh.ngay = ngay;
    sv.ngaySinh.thang = thang;
    sv.ngaySinh.nam = nam;
    cin.ignore();
    // Giới tính
    do
    {
        cout << "\t\t(?) Nhap gioi tinh: ";
        getline(cin, gioiTinh);
    } while (!isGender(gioiTinh));
    chuanHoaChuoi(gioiTinh);
    sv.gioiTinh = gioiTinh;
    // Ngành học
    do
    {
        cout << "\t\t(?) Nhap nganh hoc: ";
        getline(cin, nganhHoc);
    } while (!isMajors(nganhHoc));
    chuanHoaChuoi(nganhHoc);
    sv.nganhHoc = nganhHoc;
    // Điểm
    do
    {
        cout << "\t\t(?) Nhap diem 3 mon (DSA + OOP + TRR): ";
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
    {
        dssv = newStudent;
        tail = newStudent;
    }
    else
    { 
        newStudent->prev = tail;
        tail->next = newStudent;
        tail = newStudent;
    }
}

void DSSV::themDanhSachSV(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << "\t\t*Them sinh vien " << i << endl;
        SV sv;
        this->nhapThongTin(sv);
        this->themSV(sv);
        cout << endl;
    }
}

void DSSV::inDanhSachSV()
{
    backGround();
    gotoxy(1,14); cout << "ID |";
    gotoxy(8,14); cout << "MSSV     |";
    gotoxy(20,14); cout << "Ho va ten      |";
    gotoxy(40,14); cout << "Gmail              |";
    gotoxy(60,14); cout << "Ngay/Thang/Nam |";
    gotoxy(77,14); cout << "Gioi tinh  |";
    gotoxy(91,14); cout << "Nganh hoc    |";
    gotoxy(107,14); cout << "OOP  |";
    gotoxy(114,14); cout << "DSA  |";
    gotoxy(121, 14); cout <<  "TRR  |";
    gotoxy(128, 14); cout << "DTB  \n"; 
    int dem = -3; 
    Node* current = dssv;
    while(current!=nullptr){
        List(current->sv, dem);
        dem = dem+2;
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
        cout << "\t\t(?) Nhap Ho & Ten: ";
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
    cout << "\t\t+------------------------------+\n";
    cout << "\t\t|Cap nhat ten thanh cong!\n";
    gotoxy(47,29); cout <<"|\n";
    gotoxy(0,30); cout << "\t\t+------------------------------+\n";
}

void DSSV::capNhatSvTheoEmail(Node *nodeFound)
{
    cin.ignore();
    string email;
    do
    {
        cout << "\t\t(?) Nhap email: ";
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
    cout << "\t\t+------------------------------+\n";
    cout << "\t\t|Cap nhat email thanh cong!\n";
    gotoxy(47,29); cout <<"|\n";
    gotoxy(0,30); cout << "\t\t+------------------------------+\n";
}
void DSSV::capNhatSvTheoNgaySinh(Node *nodeFound)
{
    int ngay, thang, nam;
    do
    {
        cout << "\t\t(?) Nhap ngay sinh: ";
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
    cout << "\t\t+------------------------------+\n";
    cout << "\t\t|Cap nhat ngay sinh thanh cong!\n";
    gotoxy(47,29); cout <<"|\n";
    gotoxy(0,30); cout << "\t\t+------------------------------+\n";
}
void DSSV::capNhatSvTheoGioiTinh(Node *nodeFound)
{
    cin.ignore();
    string gioiTinh;
    do
    {
        cout << "\t\t(?) Nhap gioi tinh: ";
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
    cout << "\t\t+------------------------------+\n";
    cout << "\t\t|Cap nhat gioi tinh thanh cong!\n";
    gotoxy(47,29); cout <<"|\n";
    gotoxy(0,30); cout << "\t\t+------------------------------+\n";

}
void DSSV::capNhatSvTheoNganh(Node *nodeFound)
{
    cin.ignore();
    string nganhHoc;
    do
    {
        cout << "\t\t(?) Nhap nganh hoc: ";
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
    cout << "\t\t+------------------------------+\n";
    cout << "\t\t|Cap nhat nganh hoc thanh cong!\n";
     gotoxy(47,29); cout <<"|\n";
    gotoxy(0,30); cout << "\t\t+------------------------------+\n";
}
void DSSV::capNhatSvTheoDiem(Node *nodeFound)
{
    float diemDSA, diemOOP, diemTRR;
    do
    {
        cout << "\t\t(?) Nhap diem 3 mon (DSA + OOP + TRR): ";
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
    cout << "\t\t+------------------------------+\n";
    cout << "\t\t|Cap nhat diem thanh cong!\n";
    gotoxy(47,29); cout <<"|\n";
    gotoxy(0,30); cout << "\t\t+------------------------------+\n";
}

void DSSV::capNhatSVBangID()
{
    cout << "\t\t(?) Nhap ID: ";
    int id;
    cin >> id;
    Node *temp = layNodeTheoId(this->dssv, id);
    if (temp == NULL)
        cout << "\t\t|Khong co ID can cap nhat!\n";
    else
    {
        int chon;
        cout << "\n\t\t[1]. Cap nhat ten\n";
        cout << "\t\t[2]. Cap nhat email\n";
        cout << "\t\t[3]. Cap nhat ngay sinh\n";
        cout << "\t\t[4]. Cap nhat gioi tinh\n";
        cout << "\t\t[5]. Cap nhat nganh\n";
        cout << "\t\t[6]. Cap nhat diem\n";
        cout << "\t\t(?): ";
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
        cout << "\t\t(?) Nhap MSSV: ";
        getline(cin, mssv);
    } while (!isMSSV(mssv));
    Node *temp = layNodeTheoMSSV(this->dssv, mssv);
    if (temp == NULL)
        cout << "\t\tKhong co ID can cap nhat!\n";
    else
    {
        int chon;
        cout << "\t\t[1]. Cap nhat ten\n";
        cout << "\t\t[2]. Cap nhat email\n";
        cout << "\t\t[3]. Cap nhat ngay sinh\n";
        cout << "\t\t[4]. Cap nhat gioi tinh\n";
        cout << "\t\t[5]. Cap nhat nganh\n";
        cout << "\t\t[6]. Cap nhat diem\n";
        cout << "\t\t(?): ";
        cin >> chon;
        cout << "\n";
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
    cout << "\n\t\t[1]. Tang dan theo ID\n";
    cout << "\t\t[2]. Tang dan theo Ten\n";
    cout << "\t\t[3]. Tang dan theo DTB\n";
    int chon;
    cout << "\t\t(?): ";
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

void DSSV::sxSVGiamDanID(){
    quickSortGiamTheoID(dssv, tail);
}
void DSSV::sxSVGiamDanDTB(){
    quickSortGiamTheoDTB(dssv, tail);
}
void DSSV::sxSVGiamDanTen(){
    quickSortGiamTheoTen(dssv, tail);
}


void DSSV::sxSVGiamDan()
{
    cout << "\n\t\t[1]. Giam dan theo ID\n";
    cout << "\t\t[2]. Giam dan theo Ten\n";
    cout << "\t\t[3]. Giam dan theo DTB\n";
    int chon;
    cout << "\t\t(?): ";
    cin >> chon;
    switch (chon)
    {
    case 1:
        this->sxSVGiamDanID();
        break;
    case 2:
        this->sxSVGiamDanTen();
        break;
    case 3:
        this->sxSVGiamDanDTB();
        break;
    default:
        break;
    }
}

int DSSV::soLuong(){
    Node* current = dssv;
    if(!dssv) return 0;
    int res = 0;
    while(current){
        res ++;
        current = current->next;
    }
    return res;
}

void DSSV::xoaNode(Node* sv){
    // Nếu tồn tại Node trước Node cần xóa
    if (sv->prev) {  
        sv->prev->next = sv->next;
    } else {
        dssv = sv->next;
    }

    // Nếu tồn tại Node sau Node cần xóa
    if (sv->next) { 
        sv->next->prev = sv->prev;
    }
    else {
        sv->prev = tail;
    }

    delete sv;
}
void DSSV::xoaSV(int id[], int n){
    Node* current = dssv;
    bool check = false;
    for(int i = 0; i < n; i++){
        while(current!=nullptr){
            if(current->sv.id == id[i]){
                check = true;
                xoaNode(current);
                break;
            }
            current = current->next;
        }
        
    }
    if (n > soLuong() || !check) {
        cout << "\t\t+------------------------------------------+\n";
        cout << "\t\t|Khong tim thay sinh vien co ID phu hop!\n";
        gotoxy(59,21); cout <<"|\n";
        gotoxy(0,22); cout << "\t\t+------------------------------------------+\n";
    }else{
        cout << "\t\t+----------------------+\n";
        cout << "\t\t|Da xoa thanh cong!"<< endl;
        gotoxy(39,21); cout <<"|\n";
        gotoxy(0,22); cout << "\t\t+----------------------+\n";
    }
}

void DSSV::xoaSV(string mssv){
    Node* current = dssv;
	bool check = false;

    while(current!=nullptr){
        if(current->sv.MSSV == mssv){
            check = true;
            xoaNode(current);
            break;; // Vì MSSV là duy nhất nên sau khi xóa 1 MSSV thì hàm sẽ dừng
        }
        current = current->next;
    }

    if (!current || !check) {
        cout << "\t\t+------------------------------------------+\n";
        cout << "\t\t|Khong tim thay sinh vien co MSSV phu hop!"<< endl;
        gotoxy(59,20); cout <<"|\n";
        gotoxy(0,21); cout << "\t\t+------------------------------------------+\n";
    }
    else{
        cout << "\t\t+----------------------+\n";
        cout << "\t\t|Da xoa thanh cong!"<< endl;
        gotoxy(39,20); cout <<"|\n";
        gotoxy(0,21); cout << "\t\t+----------------------+\n";
    }
}

void DSSV::timKiemSV(int id){
    Node* current = dssv;
    bool check = false;
    while(current!=nullptr){
        if(current->sv.id == id){
            check = true;
            break;
        }
        else current = current->next;
    }
    if(!current || !check){
        cout << "\t\t+------------------------------------------+\n";
        cout << "\t\t|Khong tim thay sinh vien co ID: " << id << endl;
        gotoxy(59,20); cout <<"|\n";
        gotoxy(0,21); cout << "\t\t+------------------------------------------+\n";
        return;
    }
    else{
        title();
        List(current->sv, 1);
    }
}

void DSSV::timKiemSV(string ten){
    Node* current = dssv;
    bool check = false;
    int dem = 0;
    while(current!=nullptr){
        if(tachChuoiInHoa(current->sv.hoVaTen) == tachChuoiInHoa(ten) || tachChuoiThuong(current->sv.hoVaTen) == tachChuoiThuong(ten)){
            check = true;
            dem++;
            if(dem) title();
            // inThongTinSV(current->sv);
            List(current->sv, dem);cout <<endl;
        }
        current = current->next;
    }
    if(!check){
        cout << "\t\t+------------------------------------------+\n";
        cout << "\t\t|Khong tim thay sinh vien co ten: " << ten << endl;
        gotoxy(59,20); cout <<"|\n";
        gotoxy(0,21); cout << "\t\t+------------------------------------------+\n";
        return;
    }
}

void DSSV::thongKeDTB(){
    cout << "\t\t[1]. Chinh xac muc diem\n";
    cout << "\t\t[2]. Cao hon muc diem\n";
    cout << "\t\t[3]. Thap hon muc diem\n";
    cout << "\t\t(?): ";
    int n; cin>>n;
    float diem;
    do
    {
        cout << "\t\t(?) Nhap DTB: ";
        cin >> diem;
    } while (!isMark(diem, 0, 0));

    Node* current = dssv; int dem = 0;

    if(n==1){
        while(current!=nullptr){
            if(current->sv.diem.DTB == diem) dem ++;
            current = current->next;
        }
        if(dem){
        cout << "\t\t+--------------------------------------+\n";
        cout << "\t\t|So luong sinh vien co DTB = " << diem << " : " << dem;
        gotoxy(55,25); cout <<"|\n";
        gotoxy(0,26); cout << "\t\t+--------------------------------------+\n";
        }
    }
    else if(n==2){
        while(current!=nullptr){
            if(current->sv.diem.DTB >= diem) dem ++;
            current = current->next;
        }
        if(dem){
        cout << "\t\t+----------------------------------------+\n";
        cout << "\t\t|So sinh vien co DTB cao hon " << diem << " la: " << dem << endl;
        gotoxy(57,25); cout <<"|\n";
        gotoxy(0,26); cout << "\t\t+----------------------------------------+\n";
        }
    }
    else{
        while(current!=nullptr){
            if(current->sv.diem.DTB < diem) dem ++;
            current = current->next;
        } 
        if(dem){
        cout << "\t\t+----------------------------------------+\n";
        cout << "\t\t|So sinh vien co DTB thap hon " << diem << " la: " << dem << endl;
        gotoxy(57,25); cout <<"|\n";
        gotoxy(0,26); cout << "\t\t+----------------------------------------+\n";
        }
    }
    if(!dem){
        cout << "\t\t+----------------------------------------+\n";
        cout << "\t\t|Khong tim thay sinh vien co DTB la: " << diem << endl;
        gotoxy(57,25); cout <<"|\n";
        gotoxy(0,26); cout << "\t\t+----------------------------------------+\n";
    }

}
void DSSV::thongKeNganh(){
    string s;
    do
    {
        cout << "\t\t(?) Nhap nganh hoc: ";
        cin.ignore();
        getline(cin, s);
    } while (!isMajors(s));
    chuanHoaChuoi(s);

    Node* current = dssv;int dem = 0;
    while(current!=nullptr){
        if(current->sv.nganhHoc == s) dem ++;
        current = current->next;
    }
    if(!dem){
        cout << "\t\t+----------------------------------------+\n";
        cout << "\t\t|Khong tim thay sinh vien nganh : " << s << endl;
        gotoxy(57,21); cout <<"|\n";
        gotoxy(0,22); cout << "\t\t+----------------------------------------+\n";
    }
        else {
            cout << "\t\t+----------------------------------------+\n";
            cout << "\t\t|So sinh vien hoc nganh " << s << " la: " << dem;
            gotoxy(57,21); cout <<"|\n";
            gotoxy(0,22); cout << "\t\t+----------------------------------------+\n";
        }
}

void DSSV::thongKeGioiTinh(){
    string s;
    do
    {
        cout << "\t\t(?) Nhap gioi tinh: ";
        cin.ignore();
        getline(cin, s);
    } while (!isGender(s));
    chuanHoaChuoi(s);

    Node* current = dssv;int dem = 0;
    while(current!=nullptr){
        if(current->sv.gioiTinh == s) dem ++;
        current = current->next;
    }

    cout << "\t\t+-------------+\n";
    cout << "\t\t| Co " << dem << " " << s;
    gotoxy(30,21); cout <<"|\n";
    gotoxy(0,22); cout << "\t\t+-------------+\n";
            

}

void DSSV::thongKe() {
    cout << "\n\t\t[1]. Thong ke DTB\n";
    cout << "\t\t[2]. Thong ke Nganh\n";
    cout << "\t\t[3]. Thong ke Gioi Tinh\n";
    cout << "\t\t[4]. Thong ke so luong SV\n";

    int chon;
    cout << "\t\t(?): ";
    cin >> chon;

    switch (chon)
    {
        case 1:
            this->thongKeDTB();
            break;
        case 2:
            this->thongKeNganh();
            break;
        case 3:
            this->thongKeGioiTinh();
            break;
        case 4:
            cout << "\t\t+------------------------+\n";
            cout << "\t\t|So luong sinh vien : " << this->soLuong();
            gotoxy(41,20); cout <<"|\n";
            gotoxy(0,21); cout << "\t\t+------------------------+\n";
            break;
        default:
            break;
    }
}

