/*  Ten: Tran Huu Dang 
	MSSV: thpc04349
	ASSIGNMENT Nhap Mon Lap Trinh
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int tiepTuc;
void doiMau(const char *color) {
	char cmd[512];
	sprintf(cmd,"echo|set /p=\"\e[%sm\"",color);
	system(cmd);
}
bool ktSN(float x) {
	if (x==(int)x) return true;
	else return false;
}
bool ktSNT(int x) {
	int i;
	if (x<2) return false;
	for (i=2; i<=sqrt(x); i++) {
		if (x%i==0) return false;
	} return true;
}
bool ktSCP(int x) {
	//truong hop khong tinh so 0 va 1 
	if (x<4) return false;
	if (sqrt(x)==(int)sqrt(x)) return true;
	else return false;
}
void bai1() {
	float n;
	//do {
		//INPUT: Nhap N 
		printf("Nhap vao so N: "); scanf("%f",&n);
		if (n>=0) {
			if ( ktSN(n) ) {		
			printf("%d La so nguyen!\n",(int)n);
				if (ktSNT(n)) {
					printf("%d La so nguyen to! \n",(int)n);
				} else printf("%d Khong la so nguyen to! \n",(int)n);
				if (ktSCP(n)) {
					printf("%d La so chinh phuong! \n",(int)n);
				} else printf("%d Khong la so chinh phuong! \n",(int)n);	
			} else 
			printf("%.2f la so thuc!",n);
		}else {
//			doiMau("0;31");
			printf("Day la so am nen khong phai SNT va SCP!\n");
//			doiMau("0;0");
			if( ktSN(n) ) printf("%d la so nguyen!\n",(int)n);
			else printf("%.2f la so thuc!\n",n); 
		}	
	/*OUT: kiem tra xem do la so nguyen hay so thuc
		Neu la SN thi co phai SNT khong, SCP khong	*/
	//} while (n<0);
}
int UCLN(int a, int b) {
	if (a==0 || b==0) return a+b;
	if (a<0) a=a*-1;
	if (b<0) b=b*-1;
	
		while (a!=b) {
			if (a>b) a=a-b;
			else 	 b=b-a;
		} return a;
}
int BCNN(int a, int b) {
	int c=a*b;
	return c/UCLN(a,b);
}
int bai2() {
	int x,y;
	do {
		printf("Nhap vao so x: "); scanf("%d",&x);
		printf("Nhap vao so y: "); scanf("%d",&y);
		if (x>=0 && y>=0) {
			if (x==0 && y==0) 
				printf("Khong ton tai BCNN va UCLN!");
			else if (x==0 || y==0) {
				printf("UCLN la cua %d va %d la: %d\n",x,y,x+y);
				printf("Khong ton tai BCNN cua %d va %d! ",x,y);
			}
			else  {
				printf("BCNN cua %d va %d la: %d\n",x,y,BCNN(x,y)); 
				printf("UCLN cua %d va %d la: %d",x,y,UCLN(x,y));
			}
		} else {
			doiMau("31;31");
			printf("Vui long nhap lai x va y!\n");
			doiMau("0;0");
		}
	}	while (x<0 || y<0);
}
void bai3() {
	int gioBatDau, gioKetThuc,soGio;
	int tienKM; // tien khuyen mai 
	int tienThanhToan;
	do {
		printf("QUAN BAT DAU TU 12h-23h!\n");
		printf("Nhap vao so gio bat dau: "); scanf("%d",&gioBatDau);
		printf("Nhap vao so gio ket thuc: "); scanf("%d",&gioKetThuc);
		if (gioBatDau<12 || gioKetThuc>23 || gioBatDau > gioKetThuc) {
			doiMau("31;31"); 
			printf("Quan da dong cua!\nVui long chon gio khac!\n\n");
			doiMau("0;0");
		}
		else {
			soGio = gioKetThuc-gioBatDau;
			tienThanhToan = soGio * 150000;
			// neu qua 3h dau thi khuyen mai 30%/h 
				if (soGio>3) {
					printf("So tien goc can tra tuong ung voi %dh hat Karaoke la: %dVND\n",soGio,tienThanhToan);
					doiMau("34;34");printf("\t[So gio da vuot qua 3h dau tien]\n"); doiMau("0;0");
					tienKM = 150000 * ((soGio-3) * 0.7);
					tienThanhToan =3*150000+(soGio-3)*150000*70/100;
						//3 gio dau la 150k, cac gio sau giam 30%
					//tienThanhToan =(soGio)*150000*70/100;
					//tienThanhToan = (soGio * 150000) - tienKM;
					printf("So tien duoc khuyen mai tuong ung voi %d gio sau la: %dVND\n",soGio-3,tienKM);	                						
				}
			//neu trong 3h dau thi khong khuyen mai	
				else 
					tienThanhToan = soGio * 150000;
			// nam trong khoang 14h-17h thi khuyen mai giam 10%			
				if (gioBatDau >=14 && gioBatDau<=17) {
					printf("So tien goc can tra tuong ung voi %dh hat Karaoke la: %dVND\n",soGio,tienThanhToan);
					tienThanhToan =  (tienThanhToan * 0.9);
					printf("Vi nam trong khoang 14h-17h nen duoc giam 10 phan tram tien thanh toan tuong ung %.0fVND!\n",tienThanhToan * 0.1);
				}
			doiMau("33;33");	
		printf("So tien can thanh toan la: %dVND\n",tienThanhToan);	
			doiMau("0;0");
		}	
	} while (gioBatDau<12 || gioKetThuc>23);
}

void bai4 () {		
	int soKW;
	do {
		printf ("Nhap vao so dien(kWh) su dung: "); scanf("%d",&soKW);
	if (soKW<=0) printf("Ban nhap sai, vui long nhap lai!\n");
	else if (soKW<=50) printf("So tien phai tra la: %d VND ",soKW*1678);
	else if (soKW<=100) printf("So tien phai tra la: %d VND ",50*1678 + (soKW-50)*1734);
	else if (soKW<=200) printf("So tien phai tra la: %d VND",50*1678 + 50*1734 + (soKW-100)*2014);
	else if (soKW<=300) printf("So tien phai tra la: %d VND",50*1678 + 50*1734 + 100*2014 + (soKW-200)*2536);
	else if (soKW<=400) printf("So tien phai tra la: %d VND",50*1678 + 50*1734 + 100*2014 + 100*2536 + (soKW-300)*2834);
	else printf("So tien phai tra la: %d VND",50*1678 + 50*1734 + 100*2014 + 100*2536 + 100*2834 + (soKW-400)*2927);
	} while (soKW<1);
}
void bai5 () {
	int i,soTo,soTien,soTienBanDau;
	int menhGia[9] = {500,200,100,50,20,10,5,2,1};
	do {
			printf("Nhap vao menh gia muon doi: "); scanf("%d",&soTien);
			//soTien=(int)soTien;
			soTienBanDau=soTien;
			if (soTien>0) {
				printf("Voi "); doiMau("31;31"); printf("%dK ",soTienBanDau); 
							doiMau("0;0");   printf("ban co the doi thanh:\n");
			}
				
		if (soTienBanDau>=1) {
			while (soTien>0) {
				for (i=0; i<9; i++) {
					//Neu nhap 500k -> 2x200 & 1x100
					//Neu khong co thi: 500k --> 500k
					if (soTienBanDau == menhGia[i] && soTienBanDau !=1 ) 
						i++;
					soTo=soTien/menhGia[i];
					if (soTo!=0 ) { doiMau("34;34");printf("%d ",soTo); doiMau("0;0");printf("to ");
						doiMau("32;32"); printf("%dK\n",menhGia[i]); doiMau("0;0");
					}
					soTien=soTien-soTo*menhGia[i];
				} 
			}
		} else printf("Khong co menh gia nay, vui long nhap lai!\n");
	}while (soTienBanDau<1);	
}
void bai6(){
	int tienVay,tienLai,tienGoc,tienTra,tienConLai;
	float laiSuatThang; 
	int thang;
	//INPUT: Nhap vao so tien muon vay
	do {
		printf("Nhap so tien vay: ");scanf("%d",&tienVay);
		//Lai suat co dinh la 5%/thang 
		printf("Nhap vao so thang vay: "); scanf("%d",&thang);
		printf("Nhap vao lai suat (PhanTram/thang): "); scanf("%f",&laiSuatThang); 
		laiSuatThang = laiSuatThang / 100; 
		if(tienVay<=0 || laiSuatThang<=0) {
			doiMau("31;31");
			printf("\n           [ERROR]\n");
			doiMau("0;0");
			printf("Vui long nhap so tien hop le!\n");
		}
		else{	
		tienGoc=tienVay/thang;
		tienConLai=tienVay;
		printf("\n");
			printf("+-------------------------------------------------------------------------------+\n");
			printf("| Ky han  | Lai phai tra  | Goc phai tra  | So tien phai tra  | So tien con lai |\n");
			for(int i=1;i<=thang;i++){
				tienLai=tienConLai*laiSuatThang; 
		     	tienTra=tienLai+tienGoc;
		     	tienConLai=tienConLai-tienGoc;
		     	printf("-------------------------------------------------------------------------------\n");
		     	printf("|");	doiMau("31;31"); printf(" %6d  ",i); doiMau("0;0");
		     	printf("|");	doiMau("32;32"); printf(" %12d  ",tienLai); doiMau("0;0");
		     	printf("| ");	doiMau("33;33"); printf("%12d  ",tienGoc); doiMau("0;0");
				printf("| ");	doiMau("34;34"); printf("%12d      ",tienTra); doiMau("0;0");
				printf("| ");	doiMau("35;35"); printf("%12d    ",tienConLai); doiMau("0;0"); printf("| ");
				printf("\n");
			}
				printf("+-------------------------------------------------------------------------------+\n");		
		}
	} while (tienVay<=0 || laiSuatThang<=0);
}
void bai7(){
int thoiHan;
float phanTramVay;
double soTien,laiHangThang,laiSuat,soTienTraTruoc,traHangThang,traLai,tongPhaiTra,phanTramTraTruoc;
	do {
		printf("Nhap vao so tien muon vay: "); scanf("%lf",&soTien);
		printf("Nhap vao phan tram vay toi da: ");scanf("%f",&phanTramVay);
		printf("Ban muon tra trong bao lau(nam): "); scanf("%d",&thoiHan);
		printf("Ban muon vay voi lai suat bao nhieu (phanTram): "); scanf("%lf",&laiSuat);
		if (soTien<=0||phanTramVay<=0||thoiHan<=0||laiSuat<=0) {
				printf("Vui long nhap lai!\n\n");
		} else {
			laiSuat=laiSuat/100;
			phanTramTraTruoc=100-phanTramVay;
			float x;
	//soTien=500000000;		so tien co dinh cua de bai
			x=phanTramTraTruoc/10;
	//laiHangThang=0.072/12;	lai suat co dinh cua de bai la 7,2%
			laiHangThang=laiSuat/12;
	//thoiHan=24*12;		thoi han co dinh cua de la 24 nam
			thoiHan=thoiHan*12;
			soTienTraTruoc=soTien*x/10;
			soTien=soTien-soTienTraTruoc;
			traHangThang=soTien/thoiHan;
			printf("So tien tra truoc: %.2fvnd\n",soTienTraTruoc);
			printf("So tien tra hang thang \n");
			printf("Ky han(thang) \tLai phai tra(VND) \tGoc phai tra(VND) \tSo tien phai tra(VND) \tSo tien con lai(VND)|\n");
			for(int i=1;i<=thoiHan;i++){
				traLai=soTien*laiHangThang;
				tongPhaiTra=traLai+traHangThang;
				soTien=soTien-traHangThang;
				printf("___________________________________________________________________________________________________________\n");
				printf("     %d      \t  %.2f\t\t   %.2f\t\t    %.2f\t\t     %d\n",i,traLai,traHangThang,tongPhaiTra,(int)soTien);
			}
			break;
		}		
	} while (soTien<=0||phanTramVay<=0||thoiHan<=0||laiSuat<=0);
}

struct sinhVien  {
	char hoTen[50];
	float diem;	
};
char chuanHoa(char s[50] ) {
	int n,i,j;
 strlwr(s);
   
   n=strlen(s);
	//xoa_1KT khi co 2KT lien ke
	for (i=0; i<n; i++) {
		if (s[i]==' ' && s[i+1]==' ') {
			for (j=i; j<n; j++) {
				s[j]=s[j+1];
			}  
			i--;
			n--;
		}		
	}
	//xoa phu am thua
	for (i=0; i<n; i++) {
		if (s[i]=='u'&&s[i+1]=='u'&&s[i+2]!='u')
			i++;
		if (s[i]==s[i+1]) {
			for (j=i; j<n; j++) {
				s[j]=s[j+1];
			}  
			i--;
			n--;
		}		
	}
	//xoa KT dau tien trong chuoi
		if (s[0]==' ') {
			for (i=0; i<n; i++) {
				s[i]=s[i+1];
			} n--;
		} 
	//xoa KT cuoi cung trong chuoi		
	if (s[n-1]==' ') s[n-1]='\0';
	
	//chuan hoa hoa ten (viet hoa ky tu dau)
	s[0]=s[0]-32;
	for (int i=0; i<strlen(s); i++)
		if (s[i]==' ') {
			s[i+1]=s[i+1]-32;
	    }
	return s[50]; 
}
void bai8() {
	int i,j;
	int n;
	//do {
		printf("Nhap vao so luong sinh vien: "); scanf("%d",&n);
		//printf("%c",n);
	//} while ((char)n );
	struct sinhVien danhSach[n];
	for (i=0; i<n; i++) {
		fflush(stdin);
		printf("\n\nDu lieu sinh vien thu %d: ",i+1);
		printf("\n\t\tNhap ten sinh vien thu %d: ",i+1); 
			gets(danhSach[i].hoTen);
		nhapDiem: printf("\t\tNhap diem sinh vien thu %d: ",i+1); 
			scanf("%f",&danhSach[i].diem);
			if (danhSach[i].diem<0 || danhSach[i].diem>10) {
				printf("\nNhap diem trong khoang tu 0 den 10!\n");
				goto nhapDiem;
			}
				
	}
	//chuan hoa ho ten
	for (i=0; i<n; i++) {
		chuanHoa(danhSach[i].hoTen);
	}
	//sap xep sinh vien
	char tenTam[50] ;
	float diemTam;
	for (i=0; i<n-1; i++) {
		for (j=i+1; j<n; j++) {
			if ( danhSach[i].diem < danhSach[j].diem ) {
				//hoan Vi diem
				diemTam = danhSach[i].diem;
				danhSach[i].diem = danhSach[j].diem;
				danhSach[j].diem = diemTam;
				//hoan vi ten
				strcpy(tenTam,danhSach[i].hoTen);
				strcpy(danhSach[i].hoTen,danhSach[j].hoTen);
				strcpy(danhSach[j].hoTen,tenTam) ;
			}
		}
	}
	
	//
	printf("Danh sach sinh vien: \n");
//	printf("STT \t\t Ho va Ten \t\t DiemTB\t\t Hoc luc\t\t\t\n");
//	for (i=0; i<n; i++) {
//		
//		printf("%d  %s              %.1f",i+1,danhSach[i].hoTen,danhSach[i].diem); 
//		
//		//printf("Diem: %.1f\n",danhSach[i].diem); 
		printf("\n\t\t\t          Danh sach sinh vien: \n");
		printf("\t\t        Ho va ten          Diem		       Hoc luc \n");
		printf("\t\t ________________________________________________________________\n");
		for (i=0; i<n; i++) {
			printf("\t\t %d| %s ",i+1,danhSach[i].hoTen);
			printf("%13.1f",danhSach[i].diem);
		if (danhSach[i].diem>10) {
			printf("\t\tFALSE!\n");	
		}
		else if (danhSach[i].diem>=9) printf("\t\tHoc luc xuat sac!\n");
		else if (danhSach[i].diem>=8) printf("\t\tHoc luc gioi!\n");
		else if (danhSach[i].diem>=6.5) printf("\t\tHoc luc kha!\n");
		else if (danhSach[i].diem>=5) printf("\t\tHoc luc trung binh!\n");
		else if (danhSach[i].diem>=3.5) printf("\t\tHoc luc yeu!\n");
		else if (danhSach[i].diem>=0) printf("\t\tHoc luc kem!\n");
		else {
			printf("\t\tFALSE!\n");	
		}
	}
		
}
void bai9 () {
		int so1,so2,diemSo,soNgauNhien;
	do {
		printf("Nhap vao so dau tien: "); scanf("%d",&so1);
		printf("Nhap vao so thu hai: "); scanf("%d",&so2);
		if ( (so1>0 && so1<16) && (so2<16 && so2>0) ) {
			srand(time(0));
			//sinh so ngau nhien thay doi
			printf("So quay duoc la: ");
			for (int i=0; i<2; i++) {
				soNgauNhien = rand() % 15 + 1;
				//sinh so ngau nhien trong khoang tu [1;15]
				doiMau("34;34");
				//in ra SNN
				printf("%d",soNgauNhien);
				doiMau("0;0");
				if (i==0) printf("  va  ");
				
				if ( so1 == soNgauNhien || so2 == soNgauNhien )
					diemSo++;
					// neu SNN = a or b thi tang len 1 diem
			}
			if (diemSo==0) 
				printf("\nChuc ban may man lan sau!");
			
			else if (diemSo == 1 ) 
				printf("\nChuc mung ban da trung giai nhi!");
			else 
				printf ("\nChuc mung ban da trung giai nhat!");
			
		} else printf("Vui long chon so tu 1-15!\n------------------------\n");
	} while (so1<1 || so1>15 || so2<1 || so2>15);
}
struct phanso {
	int tuSo;
	int mauSo;
};
void bai10() {
	struct phanso ps1, ps2, tong, hieu,tich,thuong;
	int toiGian;
	do {
		ps1.tuSo=1;	ps1.mauSo=1;	ps2.tuSo=1;	ps2.mauSo=1;
		//INPUT: Nhap vao 2 phan so
	printf("NHAP VAO PHAN SO THU NHAT: \n");
	printf("\t Tu so 1: "); scanf("%d",&ps1.tuSo);
	printf("\t Mau so 1: "); scanf("%d",&ps1.mauSo);
	printf("Phan so thu nhat la: ");
		doiMau("34;34");	printf("%d/%d\n",ps1.tuSo,ps1.mauSo); doiMau("0;0");
	printf("NHAP VAO PHAN SO THU HAI: \n");
	printf("\t Tu so 2: "); scanf("%d",&ps2.tuSo);
	printf("\t Mau so 2: "); scanf("%d",&ps2.mauSo);
	printf("Phan so thu hai la: ");
	doiMau("34;34");	printf("%d/%d\n",ps2.tuSo,ps2.mauSo); doiMau("0;0");
	//OUT: In ra tong hieu tich thuong hai phan so
	if (ps1.mauSo!=0 && ps2.mauSo!=0) {
	// xu ly tong
	tong.tuSo=ps1.tuSo*ps2.mauSo+ps1.mauSo*ps2.tuSo;
	tong.mauSo=ps1.mauSo*ps2.mauSo;
	
	if (tong.mauSo<0) {
		tong.tuSo = tong.tuSo * -1;
		tong.mauSo = tong.mauSo * -1;
	}
		// toi gian phan so
		toiGian = UCLN(tong.tuSo,tong.mauSo);
		tong.tuSo= tong.tuSo/toiGian;
		tong.mauSo= tong.mauSo/toiGian;
	if (tong.tuSo == 0) 
		printf("\t  Tong cua hai phan so la: 0\n");
	else if (tong.mauSo==1)
		printf("\t  Tong cua hai phan so la: %d\n",tong.tuSo);
	else if (tong.tuSo == tong.mauSo)  
		printf("\t  Tong cua hai phan so la: 1\n");
	else if (tong.tuSo == (tong.mauSo * -1)) 
		printf("\t  Tong cua hai phan so la: -1\n");
	else 
		printf("\t  Tong cua hai phan so la: %d/%d\n",tong.tuSo, tong.mauSo);

	// xu ly hieu
	hieu.tuSo=ps1.tuSo*ps2.mauSo-ps1.mauSo*ps2.tuSo;
	hieu.mauSo=ps1.mauSo*ps2.mauSo;
	if (hieu.mauSo<0) {
		hieu.tuSo = hieu.tuSo * -1;
		hieu.mauSo = hieu.mauSo * -1;
	}
		// toi gian phan so
		toiGian = UCLN(hieu.tuSo,hieu.mauSo);
		hieu.tuSo= hieu.tuSo/toiGian;
		hieu.mauSo= hieu.mauSo/toiGian;
	if (hieu.tuSo == 0) 
		printf("\t  Hieu cua hai phan so la: 0\n");
	else if (hieu.mauSo==1)
		printf("\t  Hieu cua hai phan so la: %d\n",hieu.tuSo);
	else if (hieu.tuSo == hieu.mauSo)  
		printf("\t  Hieu cua hai phan so la: 1\n");
	else if (hieu.tuSo == (hieu.mauSo * -1))
		printf("\t  Hieu cua hai phan so la: -1\n");
	else 
		printf("\t  Hieu cua hai phan so la: %d/%d\n",hieu.tuSo, hieu.mauSo);
	
	//xu ly tich
	tich.tuSo=ps1.tuSo*ps2.tuSo;
	tich.mauSo=ps2.mauSo*ps1.mauSo;
	
	if (tich.mauSo<0) {
		tich.tuSo = tich.tuSo * -1;
		tich.mauSo = tich.mauSo * -1;
	}
		// toi gian phan so
		toiGian = UCLN(tich.tuSo,tich.mauSo);
	tich.tuSo= tich.tuSo/toiGian;
	tich.mauSo= tich.mauSo/toiGian;
	if (tich.tuSo == 0) 
		printf("\t  Tich cua hai phan so la: 0\n");
	else if (tich.mauSo==1)
		printf("\t  Tich cua hai phan so la: %d\n",tich.tuSo);
	else if (tich.tuSo == tich.mauSo)  
		printf("\t  Tich cua hai phan so la: 1\n");
	else if (tich.tuSo == (tich.mauSo * -1))
		printf("\t  Tich cua hai phan so la: -1\n");
	else 
		printf("\t  Tich cua hai phan so la: %d/%d\n",tich.tuSo,tich.mauSo); 
	
	// xu ly thuong
	thuong.tuSo=ps1.tuSo*ps2.mauSo;
	thuong.mauSo=ps1.mauSo*ps2.tuSo;

	if (thuong.mauSo<0) {
		thuong.tuSo = thuong.tuSo * -1;
		thuong.mauSo = thuong.mauSo * -1;
	}
		// toi gian phan so
		toiGian = UCLN(thuong.tuSo,thuong.mauSo);
	thuong.tuSo=thuong.tuSo/toiGian;
	thuong.mauSo=thuong.mauSo/toiGian;
	if (thuong.tuSo == 0) 
		printf("\t  Thuong cua hai phan so la: 0\n");
	else if (thuong.mauSo==1)
		printf("\t  Thuong cua hai phan so la: %d\n",thuong.tuSo);
	else if (thuong.tuSo == thuong.mauSo)  
		printf("\t  Thuong cua hai phan so la: 1\n");
	else if (thuong.tuSo == (thuong.mauSo * -1))
		printf("\t  Thuong cua hai phan so la: -1\n");
	else 
		printf("\t  Thuong cua hai phan so la: %d/%d",thuong.tuSo,thuong.mauSo);
	}  else {
			system("cls");
			doiMau("0;31");
			printf("\n\t  [ERROR]\n");
			printf("\nKhong ton tai mau so nao bang 0!\n");
			doiMau("0;0");
			printf("\tVui long nhap lai!\n\n");
		}
	}while(ps1.mauSo==0 || ps2.mauSo==0);		
		
}
void bai11() {    
  char s[200];   
  fflush(stdin);
  printf("Nhap chuoi : ");	gets(s);
	int d,n,i,j;
	char max,min;  
	n=strlen(s);
	// a b 278 c'\0'
	for (i=0; i<n; i++) {
		if (s[i]<'0' || s[i]>'9') {
			for (j=i; j<n; j++) {
				s[j]=s[j+1];
			}  
			i--;
			n--;
		}		
	}	min=s[0]; max=s[0];
	for (int k=0; k<n; k++) {
		if (s[k]>max) max=s[k];
		if (s[k]<min) min=s[k];
	}
	printf("Chuoi gom cac so: '%s'\n",s);
	printf("\n\tMAX: %c \n\tMIN: %c",max,min);
}

//chuanHoaChuoi

void bai12() {    
  char s[200];  
  int i,ho,ten,d; 
  fflush(stdin);
  printf("Nhap vao ho ten muon chuan hoa : ");	gets(s);
  printf("Chuoi truoc khi chuan hoa la: '%s'\n",s);
  chuanHoa(s);
	printf("Ho ban co may tu: "); scanf("%d",&ho);
	//Xuat ho
	//schuanHoa( s );
	printf("Ho ban la: ");
	i=0; d=0;
	while (d!=ho) {
		printf("%c",s[i]);
		if (s[i]==' ') d++;
		i++;
	}	
	printf("\n");
	
	//Xuat ten
	d=0;
	for (i=strlen(s); i>0; i--) {
		if (s[i]!=' ') d++;
		if (s[i]==' ') break;
	}
	printf("Ten cua ban la: ");
	//ten=(strlen(s)-d)+1;
	//printf("\n %d, %d",d,ten);
	/*
	VD: Tran Le Huu Dang
							d = 4
							length = 16
							ten= (16 - 4) + 1 = 13
	*/
	for (ten=(strlen(s)-d)+1; ten<=strlen(s); ten++) {
		printf("%c",s[ten]);
	}
		
	printf("\nChuoi sau khi chuan hoa la: '%s'",s);	
  
}
int main () {
		int chon;		
MENU: do {	
		printf("\n\t\t	                     Menu Chuong Trinh\n");
		printf("\t\t\t+------------------------------------------------------------------+\n");
		printf("\t\t\t|    Nhap 1 : Chuc nang kiem tra so nguyen                         |\n");
		printf("\t\t\t|    Nhap 2 : Chuc nang tim UCLN va BCNN cua hai so                |\n");
		printf("\t\t\t|    Nhap 3 : Chuc nang tinh tien cho quan karaoke                 |\n");
		printf("\t\t\t|    Nhap 4 : Chuc nang tinh tien dien                             |\n");
		printf("\t\t\t|    Nhap 5 : Chuc nang doi tien                                   |\n");
		printf("\t\t\t|    Nhap 6 : Chuc nang tinh lai suat vay ngan hang, vay tra gop   |\n");
		printf("\t\t\t|    Nhap 7 : Chuc nang vay tien mua xe                            |\n");
		printf("\t\t\t|    Nhap 8 : Chuc nang sap xep thong tin sinh vien                |\n");
		printf("\t\t\t|    Nhap 9 : Xay dung game FPOLY-LOTT                             |\n");
		printf("\t\t\t|    Nhap 10: Chuc nang tinh toan phan so                          |\n");
		printf("\t\t\t|    Nhap 11: Chuc nang tim MIN, MAX trong 'Xau Ky Tu'             |\n");
		printf("\t\t\t|    Nhap 12: Chuc nang Chuan hoa ho ten                           |\n");
		printf("\t\t\t|    Nhap 0 : Thoat                                                |\n");
		printf("\t\t\t+------------------------------------------------------------------+\n");
		printf("Lua chon cua ban la: "); scanf("%d",&chon);
		switch (chon) {
			case 1: {
				printf("1: Day la Chuong trinh kiem tra so nguyen\n");
				do {
					bai1();
					doiMau("31;31");
					printf("\n\nBAN CO MUON TIEP TUC DUNG TINH NANG HAY KHONG? \n"); 
					doiMau("32;32");
					printf("1: Dung tiep tinh nang!\n0: Tro ve MENU chuong trinh!\n");
					printf("Lua chon cua ban la: ");
					scanf("%d",&tiepTuc);   
					doiMau("0;0");
					if (tiepTuc==0) {
						system("cls");
						goto MENU;
					}
				} while (tiepTuc!=0);
			} 

			case 2: {
				printf("2: Day la Chuong trinh tim UCLN va BCNN cua hai so\n"); 
				do {
					bai2();
					doiMau("31;31");
					printf("\n\nBAN CO MUON TIEP TUC DUNG TINH NANG HAY KHONG? \n"); 
					doiMau("32;32");
					printf("1: Dung tiep tinh nang!\n0: Tro ve MENU chuong trinh!\n");
					printf("Lua chon cua ban la: ");
					scanf("%d",&tiepTuc);   
					doiMau("0;0");
					if (tiepTuc==0) {
						system("cls");
						goto MENU;
					}
				} while (tiepTuc!=0);
			}
				
			case 3: {
				printf("3: Day la Chuong trinh tinh tien cho quan karaoke\n");
				do {
					bai3();
					doiMau("31;31");
					printf("\n\nBAN CO MUON TIEP TUC DUNG TINH NANG HAY KHONG? \n"); 
					doiMau("32;32");
					printf("1: Dung tiep tinh nang!\n0: Tro ve MENU chuong trinh!\n");
					printf("Lua chon cua ban la: ");
					scanf("%d",&tiepTuc);   
					doiMau("0;0");
					if (tiepTuc==0) {
						system("cls");
						goto MENU;
					}
				} while (tiepTuc!=0);
			}
				
			case 4: {
				printf("4: Day la Chuong trinh tinh tien dien\n");
				do {
					bai4();
					doiMau("31;31");
					printf("\n\nBAN CO MUON TIEP TUC DUNG TINH NANG HAY KHONG? \n"); 
					doiMau("32;32");
					printf("1: Dung tiep tinh nang!\n0: Tro ve MENU chuong trinh!\n");
					printf("Lua chon cua ban la: ");
					scanf("%d",&tiepTuc);   
					doiMau("0;0");
					if (tiepTuc==0) {
						system("cls");
						goto MENU;
					}
				} while (tiepTuc!=0);
			}
			
			case 5: {
				printf("5: Day la Chuong trinh doi tien\n"); 
				do {
					bai5();
					doiMau("31;31");
					printf("\n\nBAN CO MUON TIEP TUC DUNG TINH NANG HAY KHONG? \n"); 
					doiMau("32;32");
					printf("1: Dung tiep tinh nang!\n0: Tro ve MENU chuong trinh!\n");
					printf("Lua chon cua ban la: ");
					scanf("%d",&tiepTuc);   
					doiMau("0;0");
					if (tiepTuc==0) {
						system("cls");
						goto MENU;
					}
				} while (tiepTuc!=0);
			}
						
			case 6: {
				printf("6: Day la Chuong trinh tinh lai suat vay ngan hang, vay tra gop\n"); 
				do {
					bai6();
					doiMau("31;31");
					printf("\n\nBAN CO MUON TIEP TUC DUNG TINH NANG HAY KHONG? \n"); 
					doiMau("32;32");
					printf("1: Dung tiep tinh nang!\n0: Tro ve MENU chuong trinh!\n");
					printf("Lua chon cua ban la: ");
					scanf("%d",&tiepTuc);   
					doiMau("0;0");
					if (tiepTuc==0) {
						system("cls");
						goto MENU;
					}
				} while (tiepTuc!=0);
			}
			
			case 7: {
				printf("7: Day la Chuong trinh vay tien mua xe\n");
				do {
					bai7();
					doiMau("31;31");
					printf("\n\nBAN CO MUON TIEP TUC DUNG TINH NANG HAY KHONG? \n"); 
					doiMau("32;32");
					printf("1: Dung tiep tinh nang!\n0: Tro ve MENU chuong trinh!\n");
					printf("Lua chon cua ban la: ");
					scanf("%d",&tiepTuc);   
					doiMau("0;0");
					if (tiepTuc==0) {
						system("cls");
						goto MENU;
					}
				} while (tiepTuc!=0);
			}
				
			case 8: {
				printf("8: Day la Chuong trinh sap xep thong tin sinh vien\n");
				do {
					getchar();
					bai8();
					doiMau("31;31");
					printf("\n\nBAN CO MUON TIEP TUC DUNG TINH NANG HAY KHONG? \n"); 
					doiMau("32;32");
					printf("1: Dung tiep tinh nang!\n0: Tro ve MENU chuong trinh!\n");
					printf("Lua chon cua ban la: ");
					scanf("%d",&tiepTuc);   
					doiMau("0;0");
					if (tiepTuc==0) {
						system("cls");
						goto MENU;
					}
				} while (tiepTuc!=0);
			}
				
			case 9: {
				printf("9: Day la Chuong trinh Xgame FPOLY-LOTT\n");
				do {
					bai9();
					doiMau("31;31");
					printf("\n\nBAN CO MUON TIEP TUC DUNG TINH NANG HAY KHONG? \n"); 
					doiMau("32;32");
					printf("1: Dung tiep tinh nang!\n0: Tro ve MENU chuong trinh!\n");
					printf("Lua chon cua ban la: ");
					scanf("%d",&tiepTuc);   
					doiMau("0;0");
					if (tiepTuc==0) {
						system("cls");
						goto MENU;
					}
				} while (tiepTuc!=0);
			}	
			case 10: {
				printf("10: Day la Chuong trinh tinh toan phan so\n");
				printf("[LUU Y: Nhap vao hai phan so nguyen!]\n");
				do {
					bai10();
					doiMau("31;31");
					printf("\n\nBAN CO MUON TIEP TUC DUNG TINH NANG HAY KHONG? \n"); 
					doiMau("32;32");
					printf("1: Dung tiep tinh nang!\n0: Tro ve MENU chuong trinh!\n");
					printf("Lua chon cua ban la: ");
					scanf("%d",&tiepTuc);   
					doiMau("0;0");
					if (tiepTuc==0) {
						system("cls");
						goto MENU;
					}
				} while (tiepTuc!=0);
			}
			case 11: {
				printf("11: Day la Chuong trinh tim MIN, MAX trong chuoi\n");
				do {
					bai11();
					doiMau("31;31");
					printf("\n\nBAN CO MUON TIEP TUC DUNG TINH NANG HAY KHONG? \n"); 
					doiMau("32;32");
					printf("1: Dung tiep tinh nang!\n0: Tro ve MENU chuong trinh!\n");
					printf("Lua chon cua ban la: ");
					scanf("%d",&tiepTuc);   
					doiMau("0;0");
					if (tiepTuc==0) {
						system("cls");
						goto MENU;
					}
				} while (tiepTuc!=0);
			}
			case 12: {
				printf("12: Day la Chuong trinh chuan hoa ho ten\n");
				do {
					bai12();
					doiMau("31;31");
					printf("\n\nBAN CO MUON TIEP TUC DUNG TINH NANG HAY KHONG? \n"); 
					doiMau("32;32");
					printf("1: Dung tiep tinh nang!\n0: Tro ve MENU chuong trinh!\n");
					printf("Lua chon cua ban la: ");
					scanf("%d",&tiepTuc);   
					doiMau("0;0");
					if (tiepTuc==0) {
						system("cls");
						goto MENU;
					}
				} while (tiepTuc!=0);
			}							
			case 0: {
				doiMau("31;31");
				printf("Ban chon ket thuc! Xin cam on, Tam biet!");
				doiMau("0;0");
				return 0;  
			}		
			default : printf("Vui long nhap lai tu 0 den 10 \n"); 
		} 	
	} 
	while (chon<1 || chon>12); 
	return 0;
}
