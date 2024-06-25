//PROJEK AKHIR SEM 1
//INTERNET BANKING

#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

void hitungtopup();
void hitungtagihan();	

string nama[10];
char ktp[10][20], alamat[10][50];	
int rek[10], pin[10], depo[10], trx[10];
int x=0;
int awal, i;
char ulang;
int norek;
bool ada=false;
string garis1(25,'-');
string garis2(80,'=');
string garis3(30,'=');
int main(){
	first:
	do{
	Sleep(1500);system("CLS");
	cout<<garis1<<left<<setfill('-')<<setw(50)<<"-S E L A M A T	   D A T A N G"<<endl;
	cout<<"\n\t\t\t1. BUKA REKENING BARU \n\t\t\t2. LOGIN \n\t\t\t3. CETAK DAFTAR REKENING\n\t\t\t4. KELUAR"<<endl<<endl;
	cout<<garis1<<left<<setfill('-')<<setw(50)<<"-"<<endl;
	cout<<"\n\n\t\t\tSILAHKAN PILIH MENU \t: ";cin>>awal;
	
	if (awal==1){
		ulangrek:
		cout<<"\n\n\tInput No Rekening (MAX 10 digit ANGKA)\t: ";cin>>norek;
		for(i=0;i<x;i++){
			if(norek==rek[i]){
				ada=true;
				break;
			}else{
				ada=false;
			}
		}
		if(ada){
			cout<<"\tNo Rekening sudah tersedia, Mohon ulangi dengan nomor yang berbeda\n";
			Sleep(1000);
			goto ulangrek;
		}else{
			cin.ignore();
			cout<<"\tMasukkan Nama Lengkap Anda \t\t: ";getline(cin,(nama[i]));
			cout<<"\tMasukkan NIK / No KTP Anda \t\t: ";cin.getline(ktp[i],20);
			cout<<"\tAlamat Lengkap \t\t\t\t: ";cin.getline(alamat[i],50);
			cout<<"\tMasukkan Pin (4 digit ANGKA)\t\t: ";cin>>pin[i];
			cout<<"\n\n\tSELAMAT REKENING ANDA TELAH BERHASIL DITAMBAHKAN";
			cout<<"\n\tSilahkan Masukkan Deposit Awal untuk Membuka Rekening : RP ";cin>>depo[i];
			cout<<"\n\n\tTERIMAKASIH! SALDO ANDA TELAH BERHASIL DITAMBAHKAN\n";
			trx[i]=0;
			cout<<garis1<<left<<setfill('-')<<setw(50)<<"-"<<endl;
		}
		x+=1;
		rek[i]=norek;
		Sleep(1000);
		cout<<"\n\n\nKembali ke Menu Awal (Y/N)? ";cin>>ulang;
		
		
	}else if (awal==2){
		inputulang:
		cout<<"\n\n\tMasukkan No Rekening Anda \t: ";cin>>norek;
		for(i=0;i<x;i++){
			if(norek==rek[i]){
				ada=true;
				break;
			}else{
				ada=false;
			}
		}
		if(ada){
			int pinanda;
			ulangpin:
			cout<<"\tMasukkan Pin anda \t\t: ";cin>>pinanda;
			
			if(pinanda==pin[i]){Sleep(2000);system("CLS");
				int opsi;
				char keopsi;
				do{Sleep(1000);system("CLS");
				cout<<"S E L A M A T    D A T A N G   K E M B A L I,\n";
				cout<<nama[i]<<endl<<endl;
				cout<<garis2<<endl;
				cout<<"\n\t\t\t1. Info Akun\n\t\t\t2. Transfer Uang\n\t\t\t3. Top Up E-Wallet\n\t\t\t4. Isi Ulang dan Tagihan\n\t\t\t5. Keluar (ke menu utama)\n\n";
				cout<<garis2<<endl;
				cout<<"\n\n\t\t\tPilih Opsi Menu \t: ";cin>>opsi;
				switch (opsi){
					case 1:Sleep(1000);system("CLS");
					cout<<garis3<<left<<setfill('=')<<setw(50)<<"=INFO AKUN"<<endl<<endl;
					cout<<"\t\tNAMA ANDA \t\t: "<<nama[i]<<endl;
					cout<<"\t\tNO KTP ANDA \t\t: "<<ktp[i]<<endl;
					cout<<"\t\tALAMAT ANDA \t\t: "<<alamat[i]<<endl;
					cout<<"\t\tSALDO ANDA SEKARANG \t: "<<depo[i]<<endl;
					cout<<"\t\tJUMLAH TRANSAKSI ANDA \t: "<<trx[i]<<endl;
					break;
					
					case 2:
					menutf:Sleep(1000);system("CLS");
					int tf, antarek, jmlhtf;
					cout<<garis3<<left<<setfill('=')<<setw(50)<<"=TRANSFER UANG"<<endl<<endl;
					cout<<"\t\t\t1. Transfer Antar Rekening\n\t\t\t2. Transfer Antar Bank\n\n";
					cout<<garis3<<left<<setfill('=')<<setw(50)<<"="<<endl;
					cout<<"\n\n\t\t\tPilih Menu Transfer \t\t: ";cin>>tf;
					cout<<endl;Sleep(1000);
					if(tf==1){
						cout<<garis3<<left<<setfill('=')<<setw(50)<<"=TRANSFER SESAMA BANK"<<endl<<endl;
						cout<<"\t\tMasukkan No Rek Tujuan \t\t: ";cin>>antarek;
						cout<<"\t\tMasukkan Nominal Transfer \t: ";cin>>jmlhtf;Sleep(1000);
						if(jmlhtf<=depo[i]){
							depo[i]=depo[i]-jmlhtf;
							cout<<"\n\t\tTRANSFER BERHASIL\n\n\t\tSisa Saldo Anda : "<<depo[i]<<endl;
							trx[i]++;
						}else{
							cout<<"\n\t\tTRANSFER GAGAL (Saldo Anda Tidak Mencukupi)\n\n\t\tSaldo Anda : "<<depo[i]<<endl;
						}
					}else if(tf==2){
						cout<<garis3<<left<<setfill('=')<<setw(50)<<"=TRANSFER ANTAR BANK"<<endl<<endl;
						cout<<"\t\tMasukkan No Rek Tujuan \t\t: ";cin>>antarek;
						cout<<"\t\tMasukkan Nominal Transfer \t: ";cin>>jmlhtf;
						cout<<"\t\t*OTHER BANK, FEE=Rp 5.000\n";Sleep(1000);
						if(jmlhtf<=depo[i]-5000){
							depo[i]=depo[i]-jmlhtf-5000;
							cout<<"\n\t\tTRANSFER BERHASIL\n\n\t\tSisa Saldo Anda : "<<depo[i]<<endl;
							trx[i]++;
						}else{
							cout<<"\n\t\tTRANSFER GAGAL (Saldo Anda Tidak Mencukupi)\n\n\t\tSaldo Anda : "<<depo[i]<<endl;
						}
					}else{
						cout<<"\n\t\t\tMenu Tidak Tersedia (Pilih 1 / 2)";Sleep(1000);
						goto menutf;
					} 
					break;
					
					case 3:
					menutopup:Sleep(1000);system("CLS");
					int topup;
					char nohp[13];
					cout<<garis3<<left<<setfill('=')<<setw(50)<<"=TOP UP E-WALLET"<<endl<<endl;
					cout<<"\t\t\t1. Dana\n\t\t\t2. GoPay\n\t\t\t3. Ovo\n\t\t\t4. LinkAja\n\t\t\t5. ShopeePay\n\n";
					cout<<garis3<<left<<setfill('=')<<setw(50)<<"="<<endl;
					cout<<"\n\n\t\t\tPilih Jenis Layanan Top Up : ";cin>>topup;
					cout<<endl;Sleep(1000);
					switch(topup){
						case 1:
						cout<<garis3<<left<<setfill('=')<<setw(50)<<"=Top Up Saldo DANA"<<endl<<endl;
						cout<<"\t\tMasukkan No DANA \t\t: ";cin>>nohp;
						hitungtopup();
						break;
						case 2:
						cout<<garis3<<left<<setfill('=')<<setw(50)<<"=Top Up Saldo GOPAY"<<endl<<endl;
						cout<<"\t\tMasukkan No GOPAY \t\t: ";cin>>nohp;
						hitungtopup();
						break;
						case 3:
						cout<<garis3<<left<<setfill('=')<<setw(50)<<"=Top Up Saldo OVO"<<endl<<endl;
						cout<<"\t\tMasukkan No OVO \t\t: ";cin>>nohp;
						hitungtopup();
						break;
						case 4:
						cout<<garis3<<left<<setfill('=')<<setw(50)<<"=Top Up Saldo LinkAja"<<endl<<endl;
						cout<<"\t\tMasukkan No LINKAJA \t\t: ";cin>>nohp;
						hitungtopup();
						break;
						case 5:
						cout<<garis3<<left<<setfill('=')<<setw(50)<<"=Top Up Saldo ShopeePay"<<endl<<endl;
						cout<<"\t\tMasukkan No SHOPEEPAY \t\t: ";cin>>nohp;
						hitungtopup();
						break;
						default: 
						cout<<"\n\t\t\tMenu Tidak Tersedia (Pilih antara 1-5)";Sleep(1000);
						goto menutopup;
						break;
					}
					break;
					
					case 4:
					menulayanan:Sleep(1000);system("CLS");
					int layanan, denom, harga;
					char nomer[20];
					cout<<garis3<<left<<setfill('=')<<setw(50)<<"=ISI ULANG DAN TAGIHAN"<<endl<<endl;
					cout<<"\t\t\t1. Pulsa\n\t\t\t2. Paket Data\n\t\t\t3. Tagihan Listrik\n\t\t\t4. BPJS\n\n";
					cout<<garis3<<left<<setfill('=')<<setw(50)<<"="<<endl;
					cout<<"\n\n\t\t\tPilih Jenis Layanan : ";cin>>layanan;
					cout<<endl;Sleep(1000);
					switch(layanan){
						case 1:
						cout<<garis3<<left<<setfill('=')<<setw(50)<<"=Isi Ulang Pulsa"<<endl<<endl;
						cout<<"\t\tMasukkan No HP anda \t: ";cin>>nomer;
						menupulsa:
						cout<<"\t\tNOMINAL TERSEDIA :\n\t\t1. 5000\n\t\t2. 10000\n\t\t3. 20000\n\t\t4. 50000\n\t\t5. 100000\n";
						cout<<"\n\t\tPilih Nominal Pulsa \t: ";cin>>denom;Sleep(1000);
						switch(denom){
							case 1:harga=6000;
							cout<<"\t\tHarga = 6.000\n";
							break;
							case 2:harga=11000;
							cout<<"\t\tHarga = 11.000\n";
							break;
							case 3:harga=21000;
							cout<<"\t\tHarga = 21.000\n";
							break;
							case 4:harga=51000;
							cout<<"\t\tHarga = 51.000\n";
							break;
							case 5:harga=101000;
							cout<<"\t\tHarga = 101.000\n";
							break;
							default:
							cout<<"\n\t\t\tMenu Tidak Tersedia (Pilih antara 1-5)";Sleep(1000);
							cout<<endl;
							goto menupulsa;
							break;
						}
						if(harga<=depo[i]){
							depo[i]=depo[i]-harga;
							cout<<"\n\t\tIsi Ulang BERHASIL\n\n\t\tSisa Saldo Anda : "<<depo[i]<<endl;
							trx[i]++;
						}else{
							cout<<"\n\t\tIsi Ulang GAGAL (Saldo Anda Tidak Mencukupi)\n\n\t\tSaldo Anda : "<<depo[i]<<endl;
						}
						break;
						case 2:
						cout<<garis3<<left<<setfill('=')<<setw(50)<<"=Isi Ulang Paket Data"<<endl<<endl;
						cout<<"\t\tMasukkan No HP anda \t: ";cin>>nomer;
						menupaket:
						cout<<"\t\tPAKET TERSEDIA :\n\t\t1. 1GB\n\t\t2. 2GB\n\t\t3. 5GB\n\t\t4. 10GB\n";
						cout<<"\n\t\tPilih Nominal Paket \t: ";cin>>denom;Sleep(1000);
						switch(denom){
							case 1:harga=10000;
							cout<<"\t\t1 GB/Harga = 10.000\n";
							break;
							case 2:harga=20000;
							cout<<"\t\t2 GB/Harga = 20.000\n";
							break;
							case 3:harga=45000;
							cout<<"\t\t3 GB/Harga = 45.000\n";
							break;
							case 4:harga=80000;
							cout<<"\t\t10 GB/Harga = 80.000\n";
							break;
							default:
							cout<<"\n\t\t\tMenu Tidak Tersedia (Pilih antara 1-4)";Sleep(1000);
							cout<<endl;
							goto menupaket;
							break;
						}
						if(harga<=depo[i]){
							depo[i]=depo[i]-harga;
							cout<<"\n\t\tIsi Ulang BERHASIL\n\n\t\tSisa Saldo Anda : "<<depo[i]<<endl;
							trx[i]++;
						}else{
							cout<<"\n\t\tIsi Ulang GAGAL (Saldo Anda Tidak Mencukupi)\n\n\t\tSaldo Anda : "<<depo[i]<<endl;
						}
						break;
						case 3:
						cout<<garis3<<left<<setfill('=')<<setw(50)<<"=Tagihan Listrik"<<endl<<endl;
						cout<<"\t\tMasukkan No. Meter/ID anda \t: ";cin>>nomer;
						hitungtagihan();
						break;
						case 4:
						cout<<garis3<<left<<setfill('=')<<setw(50)<<"=Tagihan BPJS"<<endl<<endl;
						cout<<"\t\tMasukkan No. VA Keluarga anda \t: ";cin>>nomer;
						hitungtagihan();
						break;
						default:
						cout<<"\n\t\t\tMenu Tidak Tersedia (Pilih antara 1-4)";Sleep(1000);
						goto menulayanan;
						break;
					}
					break;
					
					case 5:
					goto first;
					break;
					
					default:Sleep(1000);
					string bintang(30,'*');
					cout<<endl;
					cout<<bintang<<left<<setfill('*')<<setw(50)<<"*SYSTEM ERROR"<<endl<<endl;
					break;	
				}
				cout<<endl;
				cout<<garis3<<left<<setfill('=')<<setw(50)<<"="<<endl;
				cout<<"\n\nKembali ke Menu Opsi (Y/N)? ";cin>>keopsi;
				}while(keopsi=='y'||keopsi=='Y');
			
			}else{
				cout<<"\tPin Anda Tidak Sesuai\n\n";
				Sleep(1000);
				goto ulangpin;
			}
			
		}else{
			cout<<"\tMaaf No Rekening Anda belum terdaftar"<<endl;
			Sleep(1000);
			goto inputulang;
		}
		Sleep(1000);
		cout<<"\n\nKembali ke Menu Awal (Y/N)? ";cin>>ulang;
	}else if(awal==3){Sleep(1000);system("CLS");
		string garispanjang(113,'=');
		cout<<garis3<<"================CETAK DAFTAR REKENING================"<<garis3<<endl<<endl<<endl;Sleep(2000);
		cout<<garispanjang<<endl<<endl;
		cout<<"| "<<right<<setfill(' ')<<setw(10)<<"NO. REK"<<" |"<<right<<setfill(' ')<<setw(30)<<"NAMA"<<" |"<<right<<setfill(' ')<<setw(15)<<"NO. KTP"<<" |"<<right<<setfill(' ')<<setw(30)<<"ALAMAT LENGKAP"<<" |"<<right<<setfill(' ')<<setw(10)<<"SALDO"<<" | "<<setfill(' ')<<setw(3)<<"TRX"<<" |"<<endl;
		for(i=0;i<x;i++){
		cout<<"| "<<right<<setfill(' ')<<setw(10)<<rek[i]<<" |"<<right<<setfill(' ')<<setw(30)<<nama[i]<<" |"<<right<<setfill(' ')<<setw(15)<<ktp[i]<<" |"<<right<<setfill(' ')<<setw(30)<<alamat[i]<<" |"<<right<<setfill(' ')<<setw(10)<<depo[i]<<" | "<<setfill(' ')<<setw(3)<<trx[i]<<" |"<<endl;
		}
		cout<<endl;
		cout<<garispanjang<<endl;
		cout<<"\n\nKembali ke Menu Awal (Y/N)? ";cin>>ulang;
	}else{
		exit(0);
	}
	
	}while(ulang=='y'||ulang=='Y');

}

void hitungtopup()
{
	int jmlhtopup;
	cout<<"\t\tMasukkan Nominal Top Up \t: ";cin>>jmlhtopup;Sleep(1000);
	if(jmlhtopup<=depo[i]){
		depo[i]=depo[i]-jmlhtopup;
		cout<<"\n\t\tTOPUP BERHASIL\n\n\t\tSisa Saldo Anda : "<<depo[i]<<endl;
		trx[i]++;
	}else{
		cout<<"\n\t\tTOPUP GAGAL (Saldo Anda Tidak Mencukupi)\n\n\t\tSaldo Anda : "<<depo[i]<<endl;
	}
}

void hitungtagihan()
{
	int harga;
	cout<<"\t\tMasukkan Jumlah Tagihan anda \t: ";cin>>harga;Sleep(1000);
	if(harga<=depo[i]){
		depo[i]=depo[i]-harga;
		cout<<"\n\t\tPembayaran BERHASIL\n\n\t\tSisa Saldo Anda : "<<depo[i]<<endl;
		trx[i]++;
	}else{
		cout<<"\n\t\tPembayaran GAGAL (Saldo Anda Tidak Mencukupi)\n\n\t\tSaldo Anda : "<<depo[i]<<endl;
	}	
}

