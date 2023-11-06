#pragma once
#include <bits/stdc++.h>
#include "LibMain.h"
using namespace std;

void swapNodes(Node *node1, Node *node2);
Node *nodeCuoiCung(Node *dssv);
Node *phanHoach(Node *l, Node *h, string tieuChi);
void quickSort(Node *l, Node *h, string tieuChi);
void quickSort(Node *dssv, string tieuChi);

Node *phanHoachGiamTheoID(Node *l, Node *h);
void quickSortGiamTheoID(Node *l, Node *h);
Node *phanHoachGiamTheoDTB(Node *l, Node *h);
void quickSortGiamTheoDTB(Node *l, Node *h);
Node *phanHoachGiamTheoTen(Node *l, Node *h);
void quickSortGiamTheoTen(Node *l, Node *h);
void Swap(Node *l, Node *r);

Node *layNodeTheoId(Node *dssv, int id);
Node *layNodeTheoMSSV(Node *dssv, string mssv);
string tachChuoiInHoa(const string &s);
string tachChuoiThuong(const string &s);