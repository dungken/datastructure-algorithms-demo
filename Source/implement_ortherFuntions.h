/*
THƯ VIỆN CÀI ĐẶT CÁC HÀN TRONG ortherFuntions.h
*/

#pragma once

#include <bits/stdc++.h>
#include "ortherFunctions.h"

bool kiemTraTonTai(string mssv)
{
}

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
        for (Node *j = l; j != h; j = j->next)
        {
            if (j->sv.id <= pivot)
            {
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
        string pivot = h->sv.hoVaTen;
        Node *i = l->prev;
        for (Node *j = l; j != h; j = j->next)
        {
            if (j->sv.hoVaTen <= pivot)
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