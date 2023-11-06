/*
THƯ VIỆN CÀI ĐẶT CÁC HÀN TRONG ortherFuntions.h
*/

#pragma once

#include <bits/stdc++.h>
#include "ortherFunctions.h"


void swapNodes(Node *node1, Node *node2)
{
    SV temp = node1->sv;
    node1->sv = node2->sv;
    node2->sv = temp;
}

Node *nodeCuoiCung(Node *dssv)
{
    while (dssv->next != NULL)
        dssv = dssv->next;
    return dssv;
}

Node *phanHoach(Node *l, Node *h, string tieuChi)
{
    if (tieuChi == "ID")
    {
        int pivot = h->sv.id;
        Node *i = l->prev;
        for (Node *j = l; j != h; j = j->next) {
            if (j->sv.id <= pivot) {
                i = (i == NULL) ? l : i->next;
                swapNodes(i, j);
            }
        }
        i = (i == NULL) ? l : i->next;
        swapNodes(i, h);
        return i;
    }
    else if (tieuChi == "TEN")
    {
        string pivot = tachChuoiInHoa(h->sv.hoVaTen);
        Node *i = l->prev;
        for (Node *j = l; j != h; j = j->next)
        {
            if (tachChuoiInHoa(j->sv.hoVaTen) <= pivot)
            {
                i = (i == NULL) ? l : i->next;
                swapNodes(i, j);
            }
        }
        i = (i == NULL) ? l : i->next;
        swapNodes(i, h);
        return i;
    }
    else if (tieuChi == "DTB")
    {
        float pivot = h->sv.diem.DTB;
        Node *i = l->prev;
        for (Node *j = l; j != h; j = j->next)
        {
            if (j->sv.diem.DTB <= pivot)
            {
                i = (i == NULL) ? l : i->next;
                swapNodes(i, j);
            }
        }
        i = (i == NULL) ? l : i->next;
        swapNodes(i, h);
        return i;
    }
}

void quickSort(Node *l, Node *h, string tieuChi)
{
    if (h != NULL && l != h && l != h->next)
    {
        Node *p = phanHoach(l, h, tieuChi);
        quickSort(l, p->prev, tieuChi);
        quickSort(p->next, h, tieuChi);
    }
}

void quickSort(Node *dssv, string tieuChi)
{
    Node *h = nodeCuoiCung(dssv);
    quickSort(dssv, h, tieuChi);
}


void Swap(Node* l, Node* r){
    swap(l->sv.id, r->sv.id);
    swap(l->sv.MSSV, r->sv.MSSV);
    swap(l->sv.hoVaTen, r->sv.hoVaTen);
    swap(l->sv.email, r->sv.email);
    swap(l->sv.ngaySinh.ngay, r->sv.ngaySinh.ngay);
    swap(l->sv.ngaySinh.thang, r->sv.ngaySinh.thang);
    swap(l->sv.ngaySinh.nam, r->sv.ngaySinh.nam);
    swap(l->sv.gioiTinh, r->sv.gioiTinh);
    swap(l->sv.nganhHoc, r->sv.nganhHoc); 
    swap(l->sv.diem.diemOOP, r->sv.diem.diemOOP);
    swap(l->sv.diem.diemDSA, r->sv.diem.diemDSA);
    swap(l->sv.diem.diemTRR, r->sv.diem.diemTRR);
    swap(l->sv.diem.DTB, r->sv.diem.DTB);
}

Node* phanHoachGiamTheoID(Node *l, Node *h)
{
    int pivot = h->sv.id;
    Node *i = l->prev;
    for (Node *j = l; j != h; j = j->next)
    {
        if (j->sv.id >= pivot)
        {
            i = (i == NULL) ? l : i->next;
            Swap(i, j);
        }
    }
    i = (i == NULL) ? l : i->next;
    Swap(i, h);
    return i;
}

void quickSortGiamTheoID(Node *l, Node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        Node *p = phanHoachGiamTheoID(l, h);
        quickSortGiamTheoID(l, p->prev);
        quickSortGiamTheoID(p->next, h);
    }
}

Node* phanHoachGiamTheoDTB(Node *l, Node *h)
{
    float pivot = h->sv.diem.DTB;
    Node *i = l->prev;
    for (Node *j = l; j != h; j = j->next)
    {
        if (j->sv.diem.DTB >= pivot)
        {
            i = (i == NULL) ? l : i->next;
            Swap(i, j);
        }
    }
    i = (i == NULL) ? l : i->next;
    Swap(i, h);
    return i;
}

void quickSortGiamTheoDTB(Node *l, Node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        Node *p = phanHoachGiamTheoDTB(l, h);
        quickSortGiamTheoDTB(l, p->prev);
        quickSortGiamTheoDTB(p->next, h);
    }
}

Node* phanHoachGiamTheoTen(Node *l, Node *h)
{ 
    string pivot = tachChuoiInHoa(h->sv.hoVaTen);;
    Node *i = l->prev;
    for (Node *j = l; j != h; j = j->next)
    {
        if (tachChuoiInHoa(j->sv.hoVaTen) >= pivot)
        {
            i = (i == NULL) ? l : i->next;
            Swap(i, j);
        }
    }
    i = (i == NULL) ? l : i->next;
    Swap(i, h);
    return i;
}

void quickSortGiamTheoTen(Node *l, Node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        Node *p = phanHoachGiamTheoTen(l, h);
        quickSortGiamTheoTen(l, p->prev);
        quickSortGiamTheoTen(p->next, h);
    }
}

Node *layNodeTheoId(Node *dssv, int id)
{
    Node *temp = dssv;
    while (temp != NULL)
    {
        if (temp->sv.id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}
Node *layNodeTheoMSSV(Node *dssv, string mssv)
{
    Node *temp = dssv;
    while (temp != NULL)
    {
        if (temp->sv.MSSV == mssv)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

string tachChuoiInHoa(const string& text){
    size_t lastSpacePos = text.find_last_of(' ');

    if (lastSpacePos == string::npos) {
        return text;
    }

    return text.substr(lastSpacePos + 1);
}

string tachChuoiThuong(const string& text) {
    // Tìm vị trí dấu cách cuối cùng trong chuỗi
    size_t lastSpacePos = text.find_last_of(' ');

    // Nếu không tìm thấy dấu cách, trả về toàn bộ chuỗi
    if (lastSpacePos == string::npos) {
        return text;
    }

    // Trích xuất từ cuối cùng
    string lastWord = text.substr(lastSpacePos + 1);

    // Biến chữ cái in hoa thành chữ thường
    for (char& c : lastWord) {
        c = tolower(c);
    }

    return lastWord;
}

std::string tachChuoiDauTien(const std::string& text) {
    // Tìm vị trí của dấu cách đầu tiên trong chuỗi
    size_t firstSpacePos = text.find(' ');

    // Nếu không tìm thấy dấu cách, trả về toàn bộ chuỗi
    if (firstSpacePos == std::string::npos) {
        return text;
    }

    // Trích xuất từ đầu đến vị trí đầu tiên bằng cách sử dụng substr
    return text.substr(0, firstSpacePos);
}
