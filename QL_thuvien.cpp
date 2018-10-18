#include "iostream"
#include "conio.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "windows.h"
 
using namespace std;
 
struct Book{
    int masach;
    char tensach[30];
    char tacgia[30];
    char nxb[30];
    int namxb;
    int trangthai;
};
 
struct Booknode{
    Book info;
    Booknode *pnext;
};
 
struct list{
    Booknode *phead;
    Booknode *ptail;
};
 
void createList(list &l)
{
    l.phead=NULL;
    l.ptail=NULL;
}
Booknode *getnode(Book &s)
{
    Booknode *p;
    p = new Booknode;
    if ( p==NULL);
    p->info=s;
    p->pnext = NULL;
    return p;
}
 
void AddHead(list &l, Booknode *p)
{
        if (l.phead==NULL)
        {
            l.phead = p;
            l.ptail = l.phead;
        }
        else
        {
            p->pnext = l.phead;
            l.phead = p;    
        }
}
 
int RemoveHead(list &l)
    {   Booknode *p;
        if(l.phead!=NULL)
        {   p=l.phead;
            l.phead=l.phead->pnext;
            delete p;
            if(l.phead==NULL)
                l.ptail=NULL;
            return 1;
        }
        return 0;
    }
 
int RemoveAfterQ(list &l,Booknode *q)
{  
    if(q!=NULL&& q->pnext!=NULL)
{
   
    Booknode *p=q->pnext;
    q->pnext=p->pnext;
    if(p==l.ptail)
    l.ptail=q;
   
    delete p;
    return 1;
   
}
    else
    return 0;
}
 
int RemoveX(list &l, char key[30])
{  
    Booknode *p,*q=NULL;
    p=l.phead;
    if(p==NULL)
    return 0;
    while((p!=NULL)&&(strcmp(p->info.tensach,key)!=0)) // n?u p!=NULL và khi chýa ph?i là khóa key th? ti?p t?c t?m ;lýu ? r?ng v?ng l?p này ðýa con tr? q t?i nút k? ti?p nút có khóa key
    {
       
        q=p;
        p=p->pnext;
       
    }
    if(strcmp(l.phead->info.tensach,key)==0) // v? d? d?ng hàm xóa 1 nút ð?ng sau nút q th? ph?i xét n?i dung c?a nút ð?u tr?oc,n?u trùng v?i khóa key th? ti?n hành xóa nút ð?u
    {
        RemoveHead(l);
        return 1;
    }
   
    if(q!=NULL) // c?n n?u khác ð?ng th?i phía trên t?m ðc ví trí nút q th? ti?n hnahf xóa nút k? ti?p nút q ,c?ng chính là nút có khóa key
    {
    RemoveAfterQ(l,q);
    }
    else
    return 1;
   
}
 
void search_tacgia(list l, char tacgia_key[30])
{
    Booknode *p;
    p=l.phead;
    while(p!=NULL)
    {
        if(strcmp(p->info.tacgia,tacgia_key)==0)
        {
            cout<<"\n Ma Sach: "<<p->info.masach;
            cout<<"\n Ten Sach: "<<p->info.tensach;
            cout<<"\n Tac Gia: "<<p->info.tacgia;
            cout<<"\n NXB: "<<p->info.nxb;
            cout<<"\n Nam XB: "<<p->info.namxb;
            cout<<"\n Trang Thai: "<<p->info.trangthai;
        }
        p=p->pnext;
    }
}
 
void search_trangthai(list l, int x)
{
    Booknode *p = l.phead;
    while(p!=NULL)
    {
        if(p->info.trangthai==x)
        {
            cout<<"\n Ma Sach: "<<p->info.masach;
            cout<<"\n Ten Sach: "<<p->info.tensach;
            cout<<"\n Tac Gia: "<<p->info.tacgia;
            cout<<"\n NXB: "<<p->info.nxb;
            cout<<"\n Nam XB: "<<p->info.namxb;
            cout<<"\n Trang Thai: "<<p->info.trangthai;
        }
        p=p->pnext;
    }
}
 
void Nhap(Book s) // t?i sao khai báo hàm nh?p mà ko s? d?ng trong main;n?u ko dùng th? t?t nhát b? ði
{
    cout<<"\n nhap ma sach: ";cin>>s.masach; fflush(stdin);
    cout<<"\n nhap ten sach: "; gets(s.tensach);
    cout<<"\n nhap ten tac gia: "; gets(s.tacgia);
    cout<<"\n nhap ten nxb: "; gets(s.nxb);
    cout<<"\n nhap nam xb: "; cin>>s.namxb;
    cout<<"\n nhap trang thai( 0- chua muon or 1- da muon): "; cin>>s.trangthai;
}
void xuat(list l)
{
    int i=1;
    Booknode *R = l.phead;
    cout<<"\n";
    if(R==NULL)
        cout<<"\n\t Danh sach trong !";
    else
    {
        while(R!=NULL)
        {
            cout<<"\n ------------------------------------------";
            cout<<"\n | Sach thu: "<<i++<<"                             |";
            cout<<"\n ------------------------------------------";
            cout<<"\n Ma Sach: "<<R->info.masach;
            cout<<"\n Ten Sach: "<<R->info.tensach;
            cout<<"\n Tac Gia: "<<R->info.tacgia;
            cout<<"\n Nha Xuat Ban: "<<R->info.nxb;
            cout<<"\n Nam Xuat Ban: "<<R->info.namxb;
            cout<<"\n Trang Thai (0-Chua muon : 1-Da muon): "<<R->info.trangthai;
            R=R->pnext;
            cout<<"\n ------------------------------------------";
        }
    }
}
int main()
{
    Book s;
    list l;
    Booknode *p;
    int x, chon;
    char key[30];
    createList(l);
    do{
        system("cls");
        cout<<"\n\t ---------------------------------";
        cout<<"\n\t | CHUONG TRINH QUAN LY THU VIEN |";
        cout<<"\n\t ---------------------------------";
        cout<<"\n\t 1. Them 1 quyen sach vao dau danh sach ";
        cout<<"\n\t 2. Duyet danh sach ";
        cout<<"\n\t 3. Xoa 1 Phan Tu dau Danh Sach ";
        cout<<"\n\t 4. Xoa 1 Quyen Sach Theo Ten Tac Sach ";
        cout<<"\n\t 5. Seach 1 Quyen sach theo ten tac gia ";
        cout<<"\n\t 0. Thoat ";
        cout<<"\n\t # Chon (1->6 or 0 de thoat): ";
        cin>>chon;
        switch(chon)
        {
        case 1: {
            cout<<"\n\t Nhap Ma Sach: ";cin>>s.masach; fflush(stdin);
            cout<<"\n\t Nhap Ten Sach: "; gets(s.tensach);
            cout<<"\n\t Nhap Ten Tac Gia: "; gets(s.tacgia);
            cout<<"\n\t Nhap Ten NXB: "; gets(s.nxb);
            cout<<"\n\t Nhap Nam Xuat Ban: "; cin>>s.namxb;
            cout<<"\n\t Trang Thai (0-Chua muon : 1-Da Muon): "; cin>>s.trangthai;
            p=getnode(s);
            AddHead(l,p);
            break;
                }
        case 2:
            {
                xuat(l);
                break;
            }
        case 3:
            {
                RemoveHead(l);
                Sleep(500);
                cout<<"\n\t Xoa Thanh Cong !!!";
                break;
            }
        case 4:
            {
                cout<<"\n\t Nhap ten quyen sach can xoa : ";
                gets(key);
                RemoveX(l,key);
                Sleep(1000);
                cout<<"\n\t Xoa Thanh Cong !";
                break;
            }
        case 5:
            {
                cout<<"\n\t Nhap Ten Tac Gia : "; fflush(stdin);
                gets(key);
                search_tacgia(l,key);
                break;
            }
        }
        getch();
    }while(chon!=0);
}
