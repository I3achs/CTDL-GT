#include<iostream>
using namespace std;

struct khachhang{
	int ma;
	string ten;
	string sdt;
	float tien;
};

void nhap(khachhang kh[], int n){
	for(int i=0; i<n; i++){
		cout<<"Ma: ";
		cin>>kh[i].ma;
		cin.ignore();
		cout<<"Ten: ";
		getline(cin, kh[i].ten);
		cout<<"SDT: ";
		getline(cin, kh[i].sdt);
		cout<<"Tong tien: ";
		cin>>kh[i].tien;
	}
}

void xuatkhachhang(khachhang kh[], int n){
	for(int i=0; i<n; i++)
	{
		cout<<kh[i].ma<<" - "<<kh[i].ten<<" - "<<kh[i].sdt<<" - "<<kh[i].tien<<endl;
	}
}

void sort(khachhang kh[], int n){
	for(int i=1; i<n; i++){
		khachhang x=kh[i];
		int j=i-1;
		while(j>=0&&kh[j].tien>x.tien){
			kh[j+1]=kh[j];
			j--;
		}
		kh[j+1]=x;
	}
}
int timkiem(khachhang kh[],int n,float x)
{
	int left = 0;
	int right = n-1;
	while (left <= right) 
	{
		int mid = (left + right) / 2;
		if(kh[mid].tien == x)
		{
			return mid;
		}
		if(kh[mid].tien < x)
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
	cin>>n;
	khachhang kh[n];
	nhap(kh, n);
	cout<<"--------------------------------"<<endl;
	xuatkhachhang(kh, n);
	cout<<"--------------------------------"<<endl;
	sort(kh, n);
	xuatkhachhang(kh, n);
	cout<<"--------------------------------"<<endl;
	int x;
	cin>>x;
	
}