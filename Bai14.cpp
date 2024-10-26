#include<iostream>
#include<string>
using namespace std;
struct QLHH
{
	int mahh;
	string tenhh;
	int ngay,thang,nam;
	float gia;	
};
void nhap(QLHH&ql)
{
	cout <<"Nhap ma hang hoa: ";
	cin >>ql.mahh;
	cin.ignore();
	cout <<"Nhap ten hang hoa: ";
	getline(cin,ql.tenhh);
	cout <<"Nhap ngay: ";
	cin >>ql.ngay>>ql.thang>>ql.nam;
	cout <<"Nhap gia hang hoa: ";
	cin >>ql.gia;
}
void nhaphanghoa(QLHH ql[] ,int n)
{
	for(int i=0;i<n;i++)
	{
		cout <<"Nhap thong tin hang hoa thu:"<<i+1<<endl;
		nhap(ql[i]);
	}
}
void xuat(const QLHH &ql)
{
	cout <<"Ma hang hoa: "<<ql.mahh<<endl;
	cout <<"Ten hang hoa: "<<ql.tenhh<<endl;
	cout <<"Ngay: "<<ql.ngay<<"/"<<ql.thang<<"/"<<ql.nam<<endl;
	cout <<"Gia hang hoa: "<<ql.gia<<"trieu dong"<<endl;
}
void xuathanghoa(const QLHH ql[],int n)
{
	cout <<"Danh sach hang hoa: "<<endl;
	for(int i=0;i<n;i++)
	{
		xuat(ql[i]);
	}
}
void InsertionSort(QLHH ql[],int n)
{
	for(int i=1; i<n; i++){
		QLHH x=ql[i];
		int j=i-1;
		while(j>=0&&ql[j].gia>x.gia){
			ql[j+1]=ql[j];
			j--;
		}
		ql[j+1]=x;
	}
}
int timkiem(QLHH ql[],int n,float x)
{
	int left = 0;
	int right = n-1;
	while (left <= right) 
	{
		int mid = (left + right) / 2;
		if(ql[mid].gia == x)
		{
			return mid;
		}
		if(ql[mid].gia < x)
		{
			left = mid + 1;
		}
		else 
		{
			right = mid - 1;
		}
	}
	return -1;
}
int main(){
	int n;
	cout <<"Nhap so luong hang hoa: ";
	cin >>n;
	QLHH ds[100];
	nhaphanghoa(ds,n);
	xuathanghoa(ds,n);
	InsertionSort(ds,n);
	cout <<"Danh sach sau hh khi sap xep: "<<endl;
	xuathanghoa(ds,n);
	float x;
	cout <<"Nhap gia hang hoa: ";
	cin >>x;
	int tim=timkiem(ds,n,x);
	if(tim!=-1)
	{
		cout <<"Hang hoa co gia ban "<<x<<" la: "<<endl;
				xuat(ds[tim]);
	}
	else
	{
		cout <<"Khong tim thay hang hoa co gia ban "<<x<<endl;
	}
}