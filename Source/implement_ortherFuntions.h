/*
THƯ VIỆN CÀI ĐẶT CÁC HÀN TRONG ortherFuntions.h
*/

#pragma once

#include <bits/stdc++.h>
#include "ortherFunctions.h"

bool kiemTraTonTai(string mssv)
{
}


Node *nodeCuoiCung(Node *dssv)
{
    while (dssv->next != NULL)
        dssv = dssv->next;
    return dssv;
}

Node *phanHoach(Node *l, Node *h)
{
    int pivot = h->sv.id;
    Node *i = l->prev;
    for (Node *j = l; j != h; j = j->next)
    {
        if (j->sv.id <= pivot)
        {
            i = (i == NULL) ? l : i->next;
            swap((i->sv.id), (j->sv.id));
        }
    }
    i = (i == NULL) ? l : i->next;
    swap((i->sv.id), (h->sv.id));
    return i;
}
void quickSort(Node *l, Node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        Node *p = phanHoach(l, h);
        quickSort(l, p->prev);
        quickSort(p->next, h);
    }
}

void quickSort(Node *dssv)
{
    Node *h = nodeCuoiCung(dssv);
    quickSort(dssv, h);
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