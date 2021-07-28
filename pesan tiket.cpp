#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
using namespace std;


//kamus global program
class InfoKursi
{
	public:
		int nokursi;
		int statuskursi;
		string customer;
};

int urut;
int b, k;
vector< vector<InfoKursi> > Kursi(3, vector<InfoKursi> (6));
vector<InfoKursi>::iterator baris;
vector<InfoKursi>::iterator kolom;


//Fungsi lain program
void Gerbong()
{
	urut=1;
	for(b=1; b<3; b++)
	{
		for(k=1; k<6; k++)
		{
			Kursi[b][k].nokursi=urut++;
			Kursi[b][k].statuskursi=0;
			Kursi[b][k].customer="kosong";
		}
	}
}

void CetakGerbong()
{
	urut=0;
	for(b=1; b<3; b++)
	{
		for(k=1; k<6; k++)
		{
			cout<<Kursi[b][k].nokursi<<"-";
			cout<<Kursi[b][k].statuskursi<<" ";
			cout<<Kursi[b][k].customer<<"\t";
		}
		cout<<endl;
	}
}

bool pengecekan(vector< vector<InfoKursi> > kursi, int cek)
{
	bool found;
	found=false;
	for(b=1; b<3; b++)
	{
		for(k=1; k<6; k++)
		{
			if(kursi[b][k].nokursi==cek)
			{
				if(kursi[b][k].statuskursi==1)
				{
					found=true;
				}
			}
		}
	}
	return found;
}

void pemesanan()
{
	int noKursi;
	cout<<endl;
	cout<<"Pilih nomor kursi: ";
	cin>>noKursi;
	
	if(pengecekan(Kursi, noKursi))
	{
		cout<<"Kursi telah dipesan"<<endl;
		cout<<"Silakan pilih nomor lain";
	}
	else
	{
		for(b=1; b<3; b++)
		{
			for(k=1; k<6; k++)
			{
				if(Kursi[b][k].nokursi==noKursi)
				{
					cout<<"Masukkan nama Anda: ";
					cin>>Kursi[b][k].customer;
					cout<<"\t";
					Kursi[b][k].statuskursi=1;
				}
			}
		}
	}
}



int main()
{
	system("COLOR B0");
	cout<<"\n\t\tPEMESANAN TIKET KERETA PURBALINGGA-BOGOR"<<endl;
	cout<<"\t\t________________________________________"<<endl;
	cout<<endl;
	
	Gerbong();
	CetakGerbong();
	
	for(b=0; b<6; b++)
	{
		pemesanan();
		cout<<endl;
		CetakGerbong();
	}
	
	return 0;
}

//Nadira Nazwa Azzahra
//dengan bantuan: Andreas Sahir Aryanto
