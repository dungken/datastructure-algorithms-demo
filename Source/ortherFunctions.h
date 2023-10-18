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

Node *layNodeTheoId(Node *dssv, int id);
Node *layNodeTheoMSSV(Node *dssv, string mssv);