#ifndef HEAPSORT
#define	HEAPSORT
#include<iostream>
#include "lib.h"
#define max 10000

int main(){
	int A[max], n;
 cout<<"Nhap so phan tu:"; cin>>n;
 NhapMang(A,n);
 cout<<"\nMang vua nhap la:";
 XuatMang(A,n);
 cout<<"\nSap xep theo Heap Sort:";
 HeapSort(A,n);
 XuatMang(A,n);
 return 0;
}
#endif
