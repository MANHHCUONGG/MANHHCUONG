//hoten: NGUYEN MANH CUONG
//LOP: 15A8
//MA DE: 12
#include<iostream>
#include<string.h>
#include<iomanip>
#include<conio.h>
#include<fstream>
using namespace std;
struct sanpham
{
	char masp[20];
	char tensp[20];
	int soluong;
	long long dongia, giamgia, tongtien;

};
void nhap( sanpham sp[], int &n)
{
	cout << " \n nhap so luong sp:";
	cin  >> n;
	
	for ( int i = 0; i < n; i++ )
	{
	cout << " \n nhap thong tin cho san pham thu " << i + 1 << ":\n" ;
	cin.ignore();
	cout << " \n nhap ma san pham :";cin.getline(sp[i].masp, 20);
	
	cout << " \n nhap ten san pham :";
	
	cin.getline(sp[i].tensp, 20);
	cout << " \n nhap so luong san pham :"; cin >> sp[i].soluong;
	cout << " \n nhap don gia san pham :"; cin >> sp[i].dongia;
	

    }
}
void tieude()
{
	cout << setw(10) << right << "||masp||";
	cout << setw(15) << right << "||tensp||";
	cout << setw(20) << right << "||soluong||";
	cout << setw(25) << right << "||dongia||";
	cout << setw(30) << right << "||giamgia||";
	cout << setw(35) << right << "||tongtien||";
	cout << endl;
}
   
void xuat( sanpham sp[], int n)
{
	cout << endl;
	for ( int i = 0; i < n; i++)
	{
		cout << setw(10) << right << sp[i].masp;
	    cout << setw(15) << right << sp[i].tensp;
	    cout << setw(20) << right << sp[i].soluong;
	    cout << setw(25) << right << sp[i].dongia;
	    cout << setw(30) << right << sp[i].giamgia;
	    cout << setw(35) << right << sp[i].tongtien;
	    cout << endl;
	}    
	    
}
void giamgia( sanpham sp[], int n)
{
	for ( int i = 0; i < n; i++)
	{
		if( sp[i].soluong >= 50 && sp[i].soluong < 100 )
		{
			sp[i].giamgia = 500000;
		}
		else if(sp[i].soluong >= 100 && sp[i].soluong < 150 )
		{
			sp[i].giamgia = 1000000;
		}
		else if(sp[i].soluong >= 150)
		{
			sp[i].giamgia = 2000000;
		}
		
		
	}
}
void tongtien (sanpham sp[], int n)
{
	for ( int i = 0; i < n; i++ )
	{
		sp[i].tongtien = sp[i].soluong * sp[i].dongia - sp[i].giamgia;
	}
}
void sapxep(sanpham sp[], int n)
{
	for ( int i = 0; i < n; i++)
	{
		for ( int j = i + 1; j < n; j++)
		{
			if ( sp[i].dongia < sp[j].dongia )
			{
				sanpham tg;
				tg = sp[i];
				sp[i] = sp[j];
				sp[j] = tg;
				
			}
		}
	}
}
int tongtienmax(sanpham sp[], int n)
{
	int max;
	max = sp[0].tongtien;
	for ( int i = 1; i < n; i++ )
	{ 
	   if ( sp[i].tongtien > max)
	   {
	   	
	   	  max = sp[i].tongtien;
	   	  
	   }
	}return max;
}
void tongtienMax(sanpham sp[], int n) {
	int max = sp[0].tongtien;
	for (int i = 0; i < n; i++) {
		if (tongtienmax (sp, n) == sp[i].tongtien) {
			cout << setw(10) << right << sp[i].masp;
			cout << setw(15) << right << sp[i].tensp;
			cout << setw(20) << right << sp[i].soluong;
			cout << setw(25) << right << sp[i].dongia;
			cout << setw(30) << right << sp[i].giamgia;
			cout << setw(35) << right << sp[i].tongtien;
			cout << endl;
		}

	}
}
void them ( sanpham sp[], int &n, sanpham x )
{
	cin.ignore();
    cout << " \n nhap ma san pham :";cin.getline(x.masp, 20);
	cout << " \n nhap ten san pham :";
	cin.getline(x.tensp, 20);
	cout << " \n nhap so luong san pham :"; cin >> x.soluong;
	cout << " \n nhap don gia san pham :"; cin >> x.dongia;
	
	    n++;
	    sp[n - 1] = x;
	    
	}
void xoasp(sanpham sp[], int &n){
	int x;
	do{
		cout << "\n Nhap so luong cua san pham can xoa: "; 
			    cin >> x;
		if(x < 0){
			cout << "\nNhap lai!"<< endl;
		}
	}while(x < 0);
	
	for(int i =0 ; i < n;i++){
		if(sp[i].soluong > x){
			for (int j = i; j < n; j++){
				sp[j] = sp[j+1];
			}n--;
		}
	}
}

void Luu_tep(sanpham sp[], int n){
	ofstream file ;
	file.open ("luu.txt");
	if (!file){
		cout <<"khong luu file thanh cong !" ;
		exit(1); 
	} 
	file<< setw(10) << right << "||masp|| ";
	file<< setw(15) << right << "||tensp||";
	file<< setw(20) << right << "||soluong||";
	file<< setw(25) << right << "||dongia||";
	file<< setw(30) << right << "||giamgia||";
	file<< setw(35) << right << "||tongtien||";
	file<< endl;
	for (int i = 0; i < n; i++){
		    file << setw(10) << right << sp[i].masp;
			file << setw(15) << right << sp[i].tensp;
			file << setw(20) << right << sp[i].soluong;
			file << setw(25) << right << sp[i].dongia;
			file << setw(30) << right << sp[i].giamgia;
			file << setw(35) << right << sp[i].tongtien;
			file << endl;	
	} 
	file.close(); 
} 
void Doc_Tep(sanpham sp[],int n,string h[]){
	ifstream file1;
	file1.open ("luu.txt");
	if (!file1){
		cout <<"doc tep khong thanh cong !";
	}       
			for(int i = 0; i < n + 1; i++){
			getline(file1,h[i]);
			cout<<h[i]<<endl;
			} 
			file1.close ();
			 		
	}
void menu() {
	cout << "\n\t\t\t\t=========== MENU SANPHAM ===========\n";
	cout <<"========================================================================================================="; 
	cout << "\n||1.NHAP DANH SACH SAN PHAM TU BAN PHIM                                                            ||";
	cout << "\n||-----------------------------------------------------------------------------------------------------||"; 
	cout << "\n||2.TINH GIAM GIA CAC SAN PHAM                                                                    ||";
	cout << "\n||-----------------------------------------------------------------------------------------------------||"; 
	cout << "\n||3.IN RA DANH SACH CAC SAN PHAM                                                             ||";
	cout << "\n||-----------------------------------------------------------------------------------------------------||"; 
	cout << "\n||4.SAP XEP SAN PHAM THEO THU TU GIAM DAN                                               ||";
	cout << "\n||-----------------------------------------------------------------------------------------------------||"; 
	cout << "\n||5.IN THONG TIN SAN PHAM CO TONG TIEN LON NHAT                                                      ||";
	cout << "\n||-----------------------------------------------------------------------------------------------------||"; 
	cout << "\n||6.THEM DANH SACH SAN PHAM                      ||";
	cout << "\n||-----------------------------------------------------------------------------------------------------||"; 
	cout << "\n||7.XOA DANH SACH SAN PHAM CO SO LUONG LON HON X        ||";
	cout << "\n||-----------------------------------------------------------------------------------------------------||"; 
	cout << "\n||8.LUU DANH SACH SAN PHAM RA TEP LUU.TXT                                                        ||";
	cout << "\n||-----------------------------------------------------------------------------------------------------||"; 
	cout << "\n||9.DOC DANH SACH SAN PHAM TU TEP LUU.TXT XUAT LEN THONG TIN MAN HINH                            ||";
	cout << "\n||-----------------------------------------------------------------------------------------------------||"; 
	cout << "\n||0.KET THUC                                                                                           ||";
	cout <<"\n========================================================================================================="; 
	cout << "\n\t\t\t\t================ END =================\n";
}		
int main() {
	sanpham sp[100];
	sanpham x; 
	int n;
	char k[10]; 
	
	string h[10];
	int luachon = 0;
	char masanpham [20];
	
	nhap(sp, n);
	menu(); 
	cout << "\nDa nhap thanh cong !";		
	do {
		cout << " \nnhap lua chon :";
		cin >> luachon;
		switch (luachon) {
		case 0: {
			cout << " \nKhong hop le . Thoat chuong trinh !";
			exit(1);
		}
		case 2: {
			if (n != 0) {
				tongtien(sp, n);
				cout << "\nDa tinh ! ";
				break;
			}
			else {
				cout << "\nThong tin rong !";
				break;
			}
		}
		case 3: {
			if (n != 0) {
				tieude();
				tongtien(sp, n);
				giamgia(sp, n);
				xuat(sp, n);
				cout << "\nDa tinh xong !" << endl;
				break;
			}
			else {
				cout << "\nThong tin rong !";
				break;
			}
		}
		case 4: {
			if (n != 0) {
		
				tongtien(sp, n);
				sapxep(sp, n);
				
				tieude();
				xuat(sp, n);
				break;
			}
			else {
				cout << "\nThong tin rong !";
				break;
			}
		}
		case 5: {
			if (n != 0) {
				tieude();
				tongtien(sp, n);
				tongtienMax(sp, n);
				break;
			}
			else {
				cout << "\nThong tin rong !";
				break;
			}
		}
		case 6:{
			if (n!=0){
				them(sp,n,x);
				giamgia(sp, n);
				tongtien(sp, n);
				tongtien(sp, n);
				sapxep(sp,n); 
				tieude(); 
				xuat(sp,n); 
					break;
				} else {
				cout << "\nThong tin rong !";
				break;
			}
		} 
		case 7:
	    	 cout << "\n\tThuc hien xoa san pham"<<endl;
	    	 xoasp(sp,n);
	    	 cout << "\n  =>Xoa thanh cong" << endl;
	    	 break;
		case 8:{
			if (n!=0){
			Luu_tep(sp,n);
			tongtien(sp, n);
			cout <<" da luu vao file thanh cong !"; 
					break;
				} else {
				cout << "\nThong tin rong !";
				break;
			}
		} 
		case 9:{
			if (n!=0){
			tongtien
			(sp, n);
			Doc_Tep(sp,n,h); 
			cout <<" da doc vao file thanh cong !"; 
					break;
				} else {
				cout << "\nThong tin rong !";
				break;
			}
		} 
		
	}
		
			} while (n != 0);
		
		return 0;
}

