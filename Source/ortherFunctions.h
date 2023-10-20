/*
KHAI BÁO CÁC HÀM KHÁC NGOÀI CÁC HÀM CHUẨN HÓA
*/
#pragma once

#include <bits/stdc++.h>
#include "lib.h"
using namespace std;

// Kiểm tra sinh viên tồn tại
bool kiemTraTonTai(string);

void swapNodes(Node* node1, Node* node2);

// Quicksort
Node *nodeCuoiCung(Node *dssv);
Node *phanHoach(Node *l, Node *h, string tieuChi);
void quickSort(Node *l, Node *h, string tieuChi);
void quickSort(Node *dssv, string tieuChi);

Node *phanHoachGiamTheoID(Node *l, Node *h);
void quickSortGiamTheoID(Node *l, Node *h);
Node *phanHoachGiamTheoMSSV(Node *l, Node *h);
void quickSortGiamTheoMSSV(Node *l, Node *h);
Node *phanHoachGiamTheoDTB(Node *l, Node *h);
void quickSortGiamTheoDTB(Node *l, Node *h);
Node *phanHoachGiamTheoTen(Node *l, Node *h);
void quickSortGiamTheoTen(Node *l, Node *h);
void Swap(Node* l, Node* r);

Node *layNodeTheoId(Node *dssv, int id);
Node *layNodeTheoMSSV(Node *dssv, string mssv);