#include<iostream>
using namespace std;

struct sinhvien{
	int ma;
	string ten;
	string lop;
	float tk;
};
void nhap(sinhvien sv[], int n){
	for(int i=0; i<n; i++){
		cout<<"Ma: ";
		cin>>sv[i].ma;
		cin.ignore();
		cout<<"Ten: ";
		getline(cin, sv[i].ten);
		cout<<"Lop: ";
		getline(cin, sv[i].lop);
		cout<<"Diem tk: ";
		cin>>sv[i].tk;
	}
}
void xuat(sinhvien &sv){
	cout<<sv.ma<<" - "<<sv.ten<<" - "<<sv.lop<<" - "<<sv.tk<<endl;
}
void hienthi(sinhvien sv[], int n ){
	for(int i=0; i<n; i++){
		xuat(sv[i]);
	}
}
void sort(sinhvien sv[], int n){
	for(int i=1; i<n; i++){
		sinhvien x = sv[i];
		int j=i-1;
		while(j>=0 && sv[j].tk>x.tk){
			sv[j+1]=sv[j];
			j--;
		}
		sv[j+1]=x;
	}
}

int tim(sinhvien sv[], int n, float x){
	int l, r=n-1, m;
	int found = -1;
	while(l<=r){
		m=(l+r)/2;
		if(sv[m].tk==x){
			found=m;
			break;
		} 
		else if(sv[m].tk<x) l=m+1;
		else r=m-1;
	}
	if(found == -1) cout<<"null.";
	int i= found;
	while(i>=0 && sv[i].tk==x) i--;
	int j= found+1;
	while(j<n&&sv[j].tk==x) j++;
	for(int k=i+1; k<j; k++){
		xuat(sv[k]);
	}
	return 0;
}
int main(){
	int n;
	cin>>n;
	sinhvien sv[n];
	nhap(sv, n);
	hienthi(sv, n);
	cout<<"----------------------"<<endl;
	sort(sv, n);
	hienthi(sv, n);
	cout<<"----------------------"<<endl;
	float x;
	cin>>x;
	tim(sv, n, x);
}
