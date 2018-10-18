#ifndef LIB_H
#define	LIB_H
#include<iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;
void NhapMang(int A[],int n){
	srand(time(NULL));
	for(int i=0; i<n;  i++) {
	A[i]= rand() % 100 + 1;
	}
}
//Xu?t m?ng
void XuatMang(int A[],int n){
 cout<<endl;
 for(int i=0; i<n;  i++)
  cout<<A[i]<<"\t";
} 
//Hoán v? 2 ph?n t?
void Swap(int &a,int &b){
 int temp = a;
 a = b;
 b =  temp;
}
//Hoán v? nút cha th? i ph?i l?n hõn nút con
void Heapify(int A[],int n, int i) {
 int Left =  2*(i+1)-1;
 int Right = 2*(i+1);
 int Largest;
 if(Left<n && A[Left]>A[i])
  Largest = Left;
 else
  Largest = i;
 if(Right<n && A[Right]>A[Largest]) 
  Largest = Right;
 if(i!=Largest) {
  Swap(A[i],A[Largest]);
  Heapify(A,n,Largest);
 }
}
//Xây d?ng Heap sao cho m?i nút cha luôn l?n hõn nút con trên cây
void BuildHeap(int A[], int n) {
 for(int i = n/2-1; i>=0; i--)
  Heapify(A,n,i);
}
void HeapSort(int A[], int n) {
 BuildHeap(A,n);
 for(int i = n-1; i>0; i--){
  Swap(A[0],A[i]);
  Heapify(A,i,0);
 }
}
#endif

