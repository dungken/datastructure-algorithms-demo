/*
KHAI BÁO CÁC HÀM KHÁC NGOÀI CÁC HÀM CHUẨN HÓA
*/
#pragma once

#include <bits/stdc++.h>
#include "lib.h"
using namespace std;

// Kiểm tra sinh viên tồn tại
bool kiemTraTonTai(string);

// Quicksort
Node *nodeCuoiCung(Node *dssv);
Node *phanHoach(Node *l, Node *h);
void quickSort(Node *l, Node *h);
void quickSort(Node *dssv);

Node *layNodeTheoId(Node *dssv, int id);
Node *layNodeTheoMSSV(Node *dssv, string mssv);