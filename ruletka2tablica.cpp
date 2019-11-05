

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int n=37; //liczba numerow na stole
const int max_zakladow=500; //maksymalna ilosc zakladow w pojedynczej rundzie
const int max_graczy=4; //maksymalna liczba graczy
const int max_rund=10; //maksymalna ilosc rund

void funkcja_zerujaca(char tab1[] ,char splitx1[][n] ,char splitx2[][n], char zaklady_specjalnex[], char cornerx[]){ //przywraca stó³ do stanu pierwotnego
	
	for(int i=0; i<n; i++){
		tab1[i]=' ';
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			splitx1[i][j]='-';
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			splitx2[i][j]='|';
		}						
	}
	for(int i=0; i<9; i++){
		zaklady_specjalnex[i]=' ';
	}
	for(int i=0; i<34; i++){
		cornerx[i]='+';
	}						
}

void przypis_kolor( int pola[]) //przypisanie kolorów do pól na planszy 2-zielony 1-czerwony 0-czarny
{
	pola[0]=2;
	pola[1]=1;
	pola[2]=0;
	pola[3]=1;
	pola[4]=0;
	pola[5]=1;
	pola[6]=0;
	pola[7]=1;
	pola[8]=0;
	pola[9]=1;
	pola[10]=0;
	pola[11]=0;
	pola[12]=1;
	pola[13]=0;
	pola[14]=1;
	pola[15]=0;
	pola[16]=1;
	pola[17]=0;
	pola[18]=1;
	pola[19]=1;
	pola[20]=0;
	pola[21]=1;
	pola[22]=0;
	pola[23]=1;
	pola[24]=0;
	pola[25]=1;
	pola[26]=0;
	pola[27]=1;
	pola[28]=0;
	pola[29]=0;
	pola[30]=1;
	pola[31]=0;
	pola[32]=1;
	pola[33]=0;
	pola[34]=1;
	pola[35]=0;
	pola[36]=1;
}

void wypisz_zaklady(){
	cout<<"Zaklad Straight Up (35:1) numer-1"<<endl; 
	cout<<"Zaklad Split Bet (17:1) numer-2"<<endl;
	cout<<"Zaklad Corner Bet (8:1) numer-3"<<endl;
	cout<<"Zaklad Dozen Bet (2:1) numer-4"<<endl;
	cout<<"Zaklad Even lub Odd (1:1) numer-5"<<endl;
	cout<<"Zaklad 1st 18 lub 2nd 18 (1:1) numer-6"<<endl;
	cout<<"Zaklad Red lub Black (1:1) numer-7"<<endl;
}

void rysuj(char straightx[], char splitx1[][n] ,char splitx2[][n], char zaklady_specjalnex[], char cornerx[]){ //rysowanie pola do gry z uwzglêdnieniem postawionych zak³adów
cout<<" "<<endl;
cout<<"  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl;
cout<<"  |"<<setw(6)<<"|"<<setw(3)<<"3"<<setw(3)<<splitx2[3][6]<<setw(3)<<"6"<<setw(3)<<splitx2[6][9]<<setw(3)<<"9"<<setw(3)<<splitx2[9][12]<<setw(3)<<"12"<<setw(3)<<splitx2[12][15]<<setw(3)<<"15"<<setw(3)<<splitx2[15][18]<<setw(3)<<"18"<<setw(3)<<splitx2[18][21]<<setw(3)<<"21"<<setw(3)<<splitx2[21][24]<<setw(3)<<"24"<<setw(3)<<splitx2[24][27]<<setw(3)<<"27"<<setw(3)<<splitx2[27][30]<<setw(3)<<"30"<<setw(3)<<splitx2[30][33]<<setw(3)<<"33"<<setw(3)<<splitx2[33][36]<<setw(3)<<"36"<<setw(3)<<"|"<<endl;
cout<<"  |"<<setw(6)<<"|"<<setw(3)<<straightx[2]<<setw(3)<<"|"<<setw(3)<<straightx[5]<<setw(3)<<"|"<<setw(3)<<straightx[8]<<setw(3)<<"|"<<setw(3)<<straightx[11]<<setw(3)<<"|"<<setw(3)<<straightx[14]<<setw(3)<<"|"<<setw(3)<<straightx[17]<<setw(3)<<"|"<<setw(3)<<straightx[20]<<setw(3)<<"|"<<setw(3)<<straightx[23]<<setw(3)<<"|"<<setw(3)<<straightx[26]<<setw(3)<<"|"<<setw(3)<<straightx[29]<<setw(3)<<"|"<<setw(3)<<straightx[32]<<setw(3)<<"|"<<setw(3)<<straightx[35]<<setw(3)<<"|"<<endl;
cout<<"  |"<<"     "<<"|--"<<splitx1[2][3]<<"--"<<cornerx[3]<<"--"<<splitx1[5][6]<<"--"<<cornerx[6]<<"--"<<splitx1[8][9]<<"--"<<cornerx[9]<<"--"<<splitx1[11][12]<<"--"<<cornerx[12]<<"--"<<splitx1[14][15]<<"--"<<cornerx[15]<<"--"<<splitx1[17][18]<<"--"<<cornerx[18]<<"--"<<splitx1[20][21]<<"--"<<cornerx[21]<<"--"<<splitx1[23][24]<<"--"<<cornerx[24]<<"--"<<splitx1[26][27]<<"--"<<cornerx[27]<<"--"<<splitx1[29][30]<<"--"<<cornerx[30]<<"--"<<splitx1[32][33]<<"--"<<cornerx[33]<<"--"<<splitx1[35][36]<<"--+"<<endl;
cout<<"  |"<<setw(3)<<"0"<<setw(3)<<"|"<<setw(3)<<"2"<<setw(3)<<splitx2[2][5]<<setw(3)<<"5"<<setw(3)<<splitx2[5][8]<<setw(3)<<"8"<<setw(3)<<splitx2[8][11]<<setw(3)<<"11"<<setw(3)<<splitx2[11][14]<<setw(3)<<"14"<<setw(3)<<splitx2[14][17]<<setw(3)<<"17"<<setw(3)<<splitx2[17][20]<<setw(3)<<"20"<<setw(3)<<splitx2[20][23]<<setw(3)<<"23"<<setw(3)<<splitx2[23][26]<<setw(3)<<"26"<<setw(3)<<splitx2[26][29]<<setw(3)<<"29"<<setw(3)<<splitx2[29][32]<<setw(3)<<"32"<<setw(3)<<splitx2[32][35]<<setw(3)<<"35"<<setw(3)<<"|"<<endl;
cout<<"  |"<<setw(3)<<straightx[36]<<setw(3)<<"|"<<setw(3)<<straightx[1]<<setw(3)<<"|"<<setw(3)<<straightx[4]<<setw(3)<<"|"<<setw(3)<<straightx[7]<<setw(3)<<"|"<<setw(3)<<straightx[10]<<setw(3)<<"|"<<setw(3)<<straightx[13]<<setw(3)<<"|"<<setw(3)<<straightx[16]<<setw(3)<<"|"<<setw(3)<<straightx[19]<<setw(3)<<"|"<<setw(3)<<straightx[22]<<setw(3)<<"|"<<setw(3)<<straightx[25]<<setw(3)<<"|"<<setw(3)<<straightx[28]<<setw(3)<<"|"<<setw(3)<<straightx[31]<<setw(3)<<"|"<<setw(3)<<straightx[34]<<setw(3)<<"|"<<endl;
cout<<"  |"<<"     "<<"|--"<<splitx1[1][2]<<"--"<<cornerx[2]<<"--"<<splitx1[4][5]<<"--"<<cornerx[5]<<"--"<<splitx1[7][8]<<"--"<<cornerx[8]<<"--"<<splitx1[10][11]<<"--"<<cornerx[11]<<"--"<<splitx1[13][14]<<"--"<<cornerx[14]<<"--"<<splitx1[16][17]<<"--"<<cornerx[17]<<"--"<<splitx1[19][20]<<"--"<<cornerx[20]<<"--"<<splitx1[22][23]<<"--"<<cornerx[23]<<"--"<<splitx1[25][26]<<"--"<<cornerx[26]<<"--"<<splitx1[28][29]<<"--"<<cornerx[29]<<"--"<<splitx1[31][32]<<"--"<<cornerx[32]<<"--"<<splitx1[34][35]<<"--+"<<endl;
cout<<"  |"<<setw(6)<<"|"<<setw(3)<<"1"<<setw(3)<<splitx2[1][4]<<setw(3)<<"4"<<setw(3)<<splitx2[4][7]<<setw(3)<<"7"<<setw(3)<<splitx2[7][10]<<setw(3)<<"10"<<setw(3)<<splitx2[10][13]<<setw(3)<<"13"<<setw(3)<<splitx2[13][16]<<setw(3)<<"16"<<setw(3)<<splitx2[16][19]<<setw(3)<<"19"<<setw(3)<<splitx2[19][22]<<setw(3)<<"22"<<setw(3)<<splitx2[22][25]<<setw(3)<<"25"<<setw(3)<<splitx2[25][28]<<setw(3)<<"28"<<setw(3)<<splitx2[28][31]<<setw(3)<<"31"<<setw(3)<<splitx2[31][34]<<setw(3)<<"34"<<setw(3)<<"|"<<endl;
cout<<"  |"<<setw(6)<<"|"<<setw(3)<<straightx[0]<<setw(3)<<"|"<<setw(3)<<straightx[3]<<setw(3)<<"|"<<setw(3)<<straightx[6]<<setw(3)<<"|"<<setw(3)<<straightx[9]<<setw(3)<<"|"<<setw(3)<<straightx[12]<<setw(3)<<"|"<<setw(3)<<straightx[15]<<setw(3)<<"|"<<setw(3)<<straightx[18]<<setw(3)<<"|"<<setw(3)<<straightx[21]<<setw(3)<<"|"<<setw(3)<<straightx[24]<<setw(3)<<"|"<<setw(3)<<straightx[27]<<setw(3)<<"|"<<setw(3)<<straightx[30]<<setw(3)<<"|"<<setw(3)<<straightx[33]<<setw(3)<<"|"<<endl;
cout<<"  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl;
cout<<"        |"<<setw(24)<<"|"<<setw(24)<<"|"<<setw(24)<<"|"<<endl;
cout<<"        |"<<setw(14)<<"1st 12"<<setw(10)<<"|"<<setw(14)<<"2nd 12"<<setw(10)<<"|"<<setw(14)<<"3rd 12"<<setw(10)<<"|"<<endl;
cout<<"        |"<<setw(12)<<zaklady_specjalnex[0]<<setw(12)<<"|"<<setw(12)<<zaklady_specjalnex[1]<<setw(12)<<"|"<<setw(12)<<zaklady_specjalnex[2]<<setw(12)<<"|"<<endl;
cout<<"        +-----------+-----------+-----------+-----------+-----------+-----------+"<<endl;
cout<<"        |"<<setw(12)<<"|"<<setw(12)<<"|"<<setw(12)<<"|"<<setw(12)<<"|"<<setw(12)<<"|"<<setw(12)<<"|"<<endl;
cout<<"        |"<<setw(8)<<"1-18"<<setw(4)<<"|"<<setw(7)<<"odd"<<setw(5)<<"|"<<setw(7)<<"red"<<setw(5)<<"|"<<setw(7)<<"blk"<<setw(5)<<"|"<<setw(8)<<"even"<<setw(4)<<"|"<<setw(8)<<"19-36"<<setw(4)<<"|"<<endl;
cout<<"        |"<<setw(6)<<zaklady_specjalnex[3]<<setw(6)<<"|"<<setw(6)<<zaklady_specjalnex[4]<<setw(6)<<"|"<<setw(6)<<zaklady_specjalnex[5]<<setw(6)<<"|"<<setw(6)<<zaklady_specjalnex[6]<<setw(6)<<"|"<<setw(6)<<zaklady_specjalnex[7]<<setw(6)<<"|"<<setw(6)<<zaklady_specjalnex[8]<<setw(6)<<"|"<<endl;
cout<<"        +-----------+-----------+-----------+-----------+-----------+-----------+"<<endl;	
}

struct zaklad{ //struktura z informacjami o zakladzie
	int nr_zak; //typ zakladu
	int tabp[4]; //liczby obstawione w zakladzie
	int kasa; //zetony postawione na dany zaklad
};

void czy_poprawne_zetony(zaklad zakl[][max_zakladow], int i, int j, int punkty[]){ //sprawdzenie czy gracz ma odpowiednia ilosc zetonow ktore chce postawic
	cout<<"Zostalo ci "<<punkty[i]<<" zetonow"<<endl;
	cout<<"Ile chcesz postawic?"<<endl;
	bool poprawne_zetony=false; 
		
		while(poprawne_zetony==false){
			cin>>zakl[i][j].kasa;
				if(zakl[i][j].kasa<0 || zakl[i][j].kasa>punkty[i]){
					cout<<"Nie masz tylu zetonow"<<endl;
					cout<<"Podaj jeszcze raz:"<<endl;
					poprawne_zetony=false;
				}
				else poprawne_zetony=true;
		}
	punkty[i]=punkty[i]-zakl[i][j].kasa;	
}

void obstaw_zaklad1( zaklad zakl[][max_zakladow], int j, int i, int punkty[] ,char straightx[]){ //obstawianie zakladu typu Straight Up
	cout<<"Zaklad Straight Up"<<endl;
	cout<<"Podaj liczbe:"<<endl;
	bool poprawne_dane=false; 
	int x;
		
		while(poprawne_dane==false){ //sprawdzenie czy liczba podana przez gracza jest z zakresu od 1 do 36
			cin>>x;
			if(x<1 || x>n){
				cout<<"Niepoprawna liczba"<<endl;
				cout<<"Podaj jeszcze raz:"<<endl;
				poprawne_dane=false;
			}
			else poprawne_dane=true;
		}
	zakl[i][j].nr_zak=1; //wpisanie informacji o obstawionym zak³adzie do tablicy struktur ¿eby pozniej mo¿na by³o srawdziæ czy gracz wygra³
	zakl[i][j].tabp[0]=x;//
			
	czy_poprawne_zetony(zakl, i, j, punkty);	
	
	straightx[x-1]='X'; //zaznaczenie X zakladu obstawionego przez gracza na stole
}
	
void wynik_zaklad_typ1(zaklad zakl[][max_zakladow], int i, int j, int liczba, int punkty[] ){ //sprawdzanie czy liczba obstawiona przez gracza w zakladzie Straight Up zosta³a wylosowana
	
	if(zakl[i][j].tabp[0]==liczba){
		punkty[i]=punkty[i]+37*zakl[i][j].kasa;
	}	
}	
	

void obstaw_zaklad2( zaklad zakl[][max_zakladow], int j, int i, int punkty[] ,char splitx1[][n] ,char splitx2[][n]){ //obstawianie zakladu typu Split Bet
	cout<<"Zaklad Split Bet"<<endl;
	bool poprawne_liczby=false;
	int l1;
	int l2;
		
		while(poprawne_liczby==false){
			cout<<"Podaj pierwsza liczbe:"<<endl;
			bool poprawne_dane1=false; 
			while(poprawne_dane1==false){ //sprawdzenie czy liczba podana przez gracza jest z zakresu od 1 do 36
				cin>>l1;
				if(l1<1 || l1>37){
					cout<<"Niepoprawna liczba"<<endl;
					cout<<"Podaj jeszcze raz:"<<endl;
					poprawne_dane1=false;
				}
				else poprawne_dane1=true;
			}
			cout<<"Podaj druga liczbe:"<<endl;
			bool poprawne_dane2=false; 	
			while(poprawne_dane2==false){ //sprawdzenie czy liczba podana przez gracza jest z zakresu od 1 do 36
				cin>>l2;
				if(l2<1 || l2>37){
					cout<<"Niepoprawna liczba"<<endl;
					cout<<"Podaj jeszcze raz:"<<endl;
					poprawne_dane2=false;
				}
				else poprawne_dane2=true;
			}
			if(!(l1+3==l2 || l1-3==l2 ||(l1+1==l2 && l1%3!=0) || (l1-1==l2 && l1%3!=1))){ //sprawdzenie czy z podanych liczb mozna utworzyc Split Bet
				cout<<"Nie mozna z tych liczb obstawic Split Beta"<<endl;
				cout<<"Podaj liczby jeszcze raz"<<endl;
				bool poprawne_liczby=false;
			}									
			else poprawne_liczby=true;
		}
	zakl[i][j].nr_zak=2;    //
	zakl[i][j].tabp[0]=l1;  // wpisanie informacji o obstawionym zak³adzie do tablicy struktur ¿eby pozniej mo¿na by³o srawdziæ czy gracz wygra³
	zakl[i][j].tabp[1]=l2;  //
				
	czy_poprawne_zetony(zakl, i, j, punkty);
				
	splitx1[l1][l2]='X'; //zaznaczenie X zakladu obstawionego przez gracza na stole
	splitx1[l2][l1]='X'; //zaznaczenie X zakladu obstawionego przez gracza na stole
	splitx2[l1][l2]='X'; //zaznaczenie X zakladu obstawionego przez gracza na stole
	splitx2[l2][l1]='X'; //zaznaczenie X zakladu obstawionego przez gracza na stole
}
	
void wynik_zaklad_typ2(zaklad zakl[][max_zakladow], int i, int j, int liczba, int punkty[] ){ //sprawdzanie czy liczba obstawiona przez gracza w zakladzie Split Bet zosta³a wylosowana
	if(zakl[i][j].tabp[0]==liczba || zakl[i][j].tabp[1]==liczba){
					punkty[i]=punkty[i]+17*zakl[i][j].kasa;
	}
}		
	
void obstaw_zaklad3(zaklad zakl[][max_zakladow], int j, int i, int punkty[], char cornerx[] ){ //obstawianie zakladu typu Corner Bet
	cout<<"Zaklad Corner Bet"<<endl;
	cout<<"Podaj liczbe ktora znajduje sie w lewym gornym rogu twojego zakladu:"<<endl;
	bool poprawne_dane=true;
	int x;
	while(poprawne_dane==true){ //sprawdzanie czy podana liczba mo¿e znajdowaæ zie w lewym górnym rogu Corner Bet
		cin>>x;
		int czy_poprawna=0;
		for(int i=1; i<35; i=i+3){ //je¿eli x={1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34} to nie moze znajdowaæ sie w lewym górnym rogu Corner Bet
			if(x==i){
				cout<<"Ta liczba nie moze sie znalesc w lewym gornym rogu Corner Beta"<<endl;
				cout<<"Podaj jeszcze raz"<<endl;
				czy_poprawna=czy_poprawna+1;
			}
		}
		if(x==35 || x==36){ //je¿eli x={35, 36} to nie moze znajdowaæ sie w lewym górnym rogu Corner Bet
			cout<<"Ta liczba nie moze sie znalesc w lewym gornym rogu Corner Beta"<<endl;
			cout<<"Podaj jeszcze raz"<<endl;
			czy_poprawna=czy_poprawna+1;	
		}
		if(czy_poprawna==0)poprawne_dane=false;
		else poprawne_dane=true;
		}
	cout<<"Liczby obstawione przez ciebie: "<<x<<" "<<x+3<<" "<<x-1<<" "<<x+2<<endl;
	
	zakl[i][j].nr_zak=3;    //
	zakl[i][j].tabp[0]=x;   //
	zakl[i][j].tabp[1]=x+3; // wpisanie informacji o obstawionym zak³adzie do tablicy struktur ¿eby pozniej mo¿na by³o srawdziæ czy gracz wygra³
	zakl[i][j].tabp[2]=x-1; //
	zakl[i][j].tabp[3]=x+2; //
	
	czy_poprawne_zetony(zakl, i, j, punkty);
	
	cornerx[x]='X'; //zaznaczenie X zakladu obstawionego przez gracza na stole
}

void wynik_zaklad_typ3(zaklad zakl[][max_zakladow], int i, int j, int liczba, int punkty[] ){ //sprawdzanie czy liczba obstawiona przez gracza w zakladzie Corner Bet zosta³a wylosowana
	if(zakl[i][j].tabp[0]==liczba){
		punkty[i]=punkty[i]+8*zakl[i][j].kasa;
	}
	else if(zakl[i][j].tabp[1]==liczba){
		punkty[i]=punkty[i]+8*zakl[i][j].kasa;
	}
	else if(zakl[i][j].tabp[2]==liczba){
		punkty[i]=punkty[i]+8*zakl[i][j].kasa;
	}
	else if(zakl[i][j].tabp[3]==liczba){
		punkty[i]=punkty[i]+8*zakl[i][j].kasa;
	}
}	

void obstaw_zaklad4( zaklad zakl[][max_zakladow], int j, int i, int punkty[], char zaklady_specjalnex[]){ //obstawianie zakladu typu Dozen Bet
	cout<<"Zaklad Dozen Bet"<<endl;
	cout<<"Podaj przedzial:"<<endl;
	cout<<"(1;12) - 1  (13;24) - 2  (25;36) - 3"<<endl;
	bool poprawne_dane=true;
	int x;
		while(poprawne_dane==true){
			cin>>x;
			if(x==1 || x==2 || x==3){
				poprawne_dane=false;
			}
			else{
				cout<<"Niepoprawna liczba"<<endl;
				cout<<"Podaj jeszcze raz:"<<endl;
				poprawne_dane=true;
				} 
		}
	zakl[i][j].nr_zak=4; //wpisanie informacji o obstawionym zak³adzie do tablicy struktur ¿eby pozniej mo¿na by³o srawdziæ czy gracz wygra³
	zakl[i][j].tabp[0]=x; //
				
	czy_poprawne_zetony(zakl, i, j, punkty);		
	
	if(x==1) zaklady_specjalnex[0]='X'; //
	else if (x==2) zaklady_specjalnex[1]='X'; // zaznaczenie X zakladu obstawionego przez gracza na stole
	else if (x==3) zaklady_specjalnex[2]='X'; //
}

void wynik_zaklad_typ4(zaklad zakl[][max_zakladow], int i, int j, int liczba, int punkty[] ){ //sprawdzanie czy liczba obstawiona przez gracza w zakladzie Dozen Bet zosta³a wylosowana
	if(zakl[i][j].tabp[0]==1){
		if(liczba>=1 && liczba<=12)punkty[i]=punkty[i]+2*zakl[i][j].kasa;
		}
	else if(zakl[i][j].tabp[0]==2){
		if(liczba>=13 && liczba<=24)punkty[i]=punkty[i]+2*zakl[i][j].kasa;
		}
	else if(zakl[i][j].tabp[0]==3){
		if(liczba>=25 && liczba<=36)punkty[i]=punkty[i]+2*zakl[i][j].kasa;
		}
}	

void obstaw_zaklad5( zaklad zakl[][max_zakladow], int j, int i, int punkty[], char zaklady_specjalnex[]){ //obstawianie zakladu typu Even or Odd
	cout<<"Zaklad Even or Odd"<<endl;
	cout<<"Parzyste czy Nieparzyste:"<<endl;
	cout<<"Parzyste - 1  Nieparzyste - 2"<<endl;
	bool poprawne_dane=true;
	int x;
		while(poprawne_dane==true){
			cin>>x;
			if(x==1 || x==2){
				poprawne_dane=false;
				}
			else{
				cout<<"Niepoprawna liczba"<<endl;
				cout<<"Podaj jeszcze raz:"<<endl;
				poprawne_dane=true;
				} 
		}
	zakl[i][j].nr_zak=5; //wpisanie informacji o obstawionym zak³adzie do tablicy struktur ¿eby pozniej mo¿na by³o srawdziæ czy gracz wygra³
	zakl[i][j].tabp[0]=x; //
				
	czy_poprawne_zetony(zakl, i, j, punkty);	
	
	if(x==1) zaklady_specjalnex[7]='X'; //zaznaczenie X zakladu obstawionego przez gracza na stole
	else if(x==2) zaklady_specjalnex[4]='X'; //
}

void wynik_zaklad_typ5(zaklad zakl[][max_zakladow], int i, int j, int liczba, int punkty[] ){ //sprawdzanie czy liczba obstawiona przez gracza w zakladzie Even or Odd zosta³a wylosowana
	if(zakl[i][j].tabp[0]==1){
		if(liczba%2==0)punkty[i]=punkty[i]+zakl[i][j].kasa;
			}
	else if(zakl[i][j].tabp[0]==2){
		if(liczba%2!=0)punkty[i]=punkty[i]+zakl[i][j].kasa;
			}
}	

void obstaw_zaklad6( zaklad zakl[][max_zakladow], int j, int i, int punkty[], char zaklady_specjalnex[]){ //obstawianie zakladu typu 1st 18 or 2nd 18
	cout<<"Zaklad 1st 18 or 2nd 18"<<endl;
	cout<<"Podaj przedzial:"<<endl;
	int x;
	cout<<"1st 18 - 1  2nd 18 - 2"<<endl;
	bool poprawne_dane=true;
		while(poprawne_dane==true){
			cin>>x;
			if(x==1 || x==2){
				poprawne_dane=false;
			}
			else{
				cout<<"Niepoprawna liczba"<<endl;
				cout<<"Podaj jeszcze raz:"<<endl;
				poprawne_dane=true;
				} 
		};
	zakl[i][j].nr_zak=6; //wpisanie informacji o obstawionym zak³adzie do tablicy struktur ¿eby pozniej mo¿na by³o srawdziæ czy gracz wygra³
	zakl[i][j].tabp[0]=x;//
				
	czy_poprawne_zetony(zakl, i, j, punkty);	
	
	if(x==1) zaklady_specjalnex[3]='X'; //zaznaczenie X zakladu obstawionego przez gracza na stole
	else if(x==2) zaklady_specjalnex[8]='X'; //
}

void wynik_zaklad_typ6(zaklad zakl[][max_zakladow], int i, int j, int liczba, int punkty[] ){ //sprawdzanie czy liczba obstawiona przez gracza w zakladzie 1st 18 or 2nd 18 zosta³a wylosowana
	if(zakl[i][j].tabp[0]==1){
		if(liczba>=1 && liczba<=18)punkty[i]=punkty[i]+zakl[i][j].kasa;
			}
	else if(zakl[i][j].tabp[0]==2){
		if(liczba>=19 && liczba<=36)punkty[i]=punkty[i]+zakl[i][j].kasa;
		}
 }	

void obstaw_zaklad7( zaklad zakl[][max_zakladow], int j, int i, int punkty[], int tab[], char zaklady_specjalnex[]){ //obstawianie zakladu typu Red or Black
	cout<<"Zaklad Red or Black"<<endl;
	cout<<"Podaj kolor:"<<endl;
	cout<<"Red-1  Black-0"<<endl;
	bool poprawne_dane=true;
	int x;
		while(poprawne_dane==true){
			cin>>x;
			if(x==1 || x==0){
				poprawne_dane=false;
				}
			else{
				cout<<"Niepoprawna liczba"<<endl;
				cout<<"Podaj jeszcze raz:"<<endl;
				poprawne_dane=true;
				} 
		}
	zakl[i][j].nr_zak=7; //wpisanie informacji o obstawionym zak³adzie do tablicy struktur ¿eby pozniej mo¿na by³o srawdziæ czy gracz wygra³
	zakl[i][j].tabp[0]=x; //
				
	czy_poprawne_zetony(zakl, i, j, punkty);	

	if(x==1) zaklady_specjalnex[5]='X'; //zaznaczenie X zakladu obstawionego przez gracza na stole
	else if(x==0) zaklady_specjalnex[6]='X'; //
}

void wynik_zaklad_typ7(zaklad zakl[][max_zakladow], int i, int j, int liczba, int punkty[], int tab[] ){//sprawdzanie czy liczba obstawiona przez gracza w zakladzie Red or Black zosta³a wylosowana
	if(zakl[i][j].tabp[0]==tab[liczba]){
	punkty[i]=punkty[i]+zakl[i][j].kasa;
	}
}	

int main(){
	int pola[n]; //tablica "kolorów" dla poszczególnych pól na stole
	int ile_graczy; //liczba graczy
	przypis_kolor(pola);
	
	cout<<"Witajcie w grze RULETKA"<<endl;
	cout<<endl;
	cout<<"Ile graczy bedzie dzisiaj gralo? (od 1 do 4)"<<endl;
	
	bool poprawna_liczba_graczy=false;
	while(poprawna_liczba_graczy==false){ //sprawdzenie czy liczba graczy jest poprawna
		cin>>ile_graczy;
		if(ile_graczy<=0 || ile_graczy>max_graczy){
			cout<<"Niepoprawna liczba graczy"<<endl;
			cout<<"Podaj jeszcze raz:"<<endl;
			poprawna_liczba_graczy=false;
		}
		else poprawna_liczba_graczy=true;
	}
	cout<<"Wiec dzisiaj gra u nas "<<ile_graczy<<" graczy!!"<<endl;
	cout<<"Witamy serdecznie!!"<<endl;
	cout<<endl;
	
	int punkty[ile_graczy]; //tablica punktów poszczególnych graczy
	
	cout<<"Poczatkowa ilosc zetonow:"<<endl;
	for(int i=0; i<ile_graczy; i++){ //przypisanie pocz¹tkowych zetonów dla graczy
		punkty[i]=100;
	}
	for(int i=0; i<ile_graczy; i++){
		cout<<"Gracz numer "<<i+1<<"="<<punkty[i]<<" zetonow"<<endl;
	}
	system("pause");
	system("cls");
	
	bool punkty_0=false; //zmienna informuj¹ca czy któryœ z graczy ma zerow¹ liczbe ¿etonów
	int ktora_runda=0; //licznik rund
	while(punkty_0==false){ //gra toczy sie dopóki jeden z graczy nie bedzie mia³ zero punktów po zakoñczeniu rundy
		char straightx[n]; //tablica znaków dla zakladu Straight Up
		char splitx1[n][n]; //tablica znaków dla zak³adu Split Bet
		char splitx2[n][n]; //tablica znaków dla zak³adu Split Bet
		char zaklady_specjalnex[9]; //tablica znaków dla zak³adu Dozen Bet, Even or Odd, 1st 18 or 2nd 18 i Red or Black
		char cornerx[34]; //tablica znaków dla zak³adu Corner Bet
		zaklad zakl[max_graczy][max_zakladow]; //tablica struktur dla jednego zakladu jednego gracza w jednej rundzie
		for(int i=0; i<ile_graczy; i++){ //obstawianie zak³adów przez kolejnych graczy
			
			funkcja_zerujaca(straightx, splitx1, splitx2, zaklady_specjalnex, cornerx);
			rysuj(straightx, splitx1, splitx2, zaklady_specjalnex, cornerx);
			
			cout<<"Zaklady obstawia gracz numer "<<i+1<<endl<<endl;
			bool ile_rund=true;
			int j=0; //ile zak³adów obstawi³ gracz w swojej turze
			system("pause");
			system("cls");
			
			while(ile_rund==true){ //gracz wykonuje tyle zak³adów ile chce
				int zaklad_numer; //numer zak³adu który chcemy wybraæ
				rysuj(straightx, splitx1, splitx2, zaklady_specjalnex, cornerx); 
				wypisz_zaklady();
				cout<<endl<<"Jaki zaklad chcesz obstawic: ";
				cin>>zaklad_numer;
				switch( zaklad_numer ){ //gracz wybiera numer zak³adu który chcia³by obstawiæ
					case 1:	obstaw_zaklad1(zakl, j, i, punkty, straightx);
							j=j+1;	
						break;
		    		case 2: obstaw_zaklad2(zakl, j, i, punkty, splitx1, splitx2);
							j=j+1;	
						break;	
		    		case 3:	obstaw_zaklad3(zakl, j, i, punkty, cornerx);
							j=j+1;		
		    			break;
		    		case 4: obstaw_zaklad4(zakl, j, i, punkty, zaklady_specjalnex);
							j=j+1;	
						break;
					case 5: obstaw_zaklad5(zakl, j, i, punkty, zaklady_specjalnex);
							j=j+1;	
						break;
					case 6: obstaw_zaklad6(zakl, j, i, punkty, zaklady_specjalnex);
							j=j+1;	
						break;
					case 7: obstaw_zaklad7(zakl, j, i, punkty, pola, zaklady_specjalnex);
							j=j+1;	
						break;
		    		default: cout<<"Niepoprawny numer zakladu"<<endl;
		    				 system("pause");
		   				break;
				}
				system("cls");
				rysuj(straightx, splitx1, splitx2, zaklady_specjalnex, cornerx); //rysowanie sto³u z obstawionymi zak³adami
				
				cout<<"Czy chcesz dokonac kolejnych zakladow?"<<endl;
				cout<<"TAK-1"<<" NIE-2"<<endl;
				int zmienna;
				cin>>zmienna;
				if(zmienna==1)ile_rund=true;
				else ile_rund=false;
					
				if(punkty[i]==0){ //jezeli gracz postawi³ wszystskie swoje ¿etony to nie mo¿e dokonaæ kolejnych zak³adów
				cout<<"Nie masz wiecej zetonow i nie mozesz postawic kolejnych zakladow :("<<endl;
				system("pause");
				system("cls");
				break;
				}
								
				system("cls");
			}
			rysuj(straightx, splitx1, splitx2, zaklady_specjalnex, cornerx); //rysowanie sto³u z obstawionymi zak³adami
			cout<<endl<<"Zaklady postawione przez Ciebie:"<<endl;
			if(j==0)cout<<"Nie postawiles zandych zakladow."<<endl;
			
			for(int i1=0; i1<j; i1++){ //wypisanie zak³adów postawionych przez gracza
				cout<<"Zaklad numer "<<i1+1<<" - ";
				switch(zakl[i][i1].nr_zak){
					case 1:	cout<<"Straight Up | Liczba - "<<zakl[i][i1].tabp[0]<<"| Zetony: "<<zakl[i][i1].kasa<<endl;						
						break;
			    	case 2:	cout<<"Split Bet | Liczby - "<<zakl[i][i1].tabp[0]<<" , "<<zakl[i][i1].tabp[1]<<"| Zetony: "<<zakl[i][i1].kasa<<endl;	
						break;
			    	case 3:	cout<<"Corner Bet | Liczby- "<<zakl[i][i1].tabp[0]<<" , "<<zakl[i][i1].tabp[1]<<" , "<<zakl[i][i1].tabp[2]<<" , "<<zakl[i][i1].tabp[3];
							cout<<"| Zetony: "<<zakl[i][i1].kasa<<endl;	
			    		break;
			    	case 4:	cout<<"Dozen Bet | Przedzial - ";
						if(zakl[i][i1].tabp[0]==1) cout<<"(1;12) |";
						else if(zakl[i][i1].tabp[0]==2) cout<<"(13;24) |";
						else cout<<"(25;36) |";	
						cout<<"Zetony: "<<zakl[i][i1].kasa<<endl;
						break;
					case 5:	cout<<"Even, Odd | Liczby - ";
						if(zakl[i][i1].tabp[0]==1) cout<<"Parzyste |";
						else cout<<"Nieparzyste |";
						cout<<"Zetony: "<<zakl[i][i1].kasa<<endl;	
						break;
					case 6:	cout<<"1st 18, 2nd 18 | Przedzial - ";
						if(zakl[i][i1].tabp[0]==1) cout<<"1st 18 |";
						else cout<<"2nd 18 |";
						cout<<"Zetony: "<<zakl[i][i1].kasa<<endl;	
						break;
					case 7:	cout<<"Red, Black| Kolor - ";
						if(zakl[i][i1].tabp[0]==1) cout<<"Red |";
						else cout<<"Black |"; 
						cout<<"Zetony: "<<zakl[i][i1].kasa<<endl;	
						break;
			    }
			}
			system("pause");
			system("cls");
		}
		srand( time( NULL ) );
		int liczba=(( rand() % 36) + 0); //losowanie liczby od 0 do 36	
		cout<<"Losuje liczbe...."<<endl;;
		system("pause");
		cout<<"Wylosowana liczba to: "<<liczba<<" ! Kolor: ";
		
		if(pola[liczba]==1)cout<<"Red"<<endl<<endl;        //
		else if(pola[liczba]==0)cout<<"Black"<<endl<<endl; // wypisanie koloru wylosowanej liczby
		else cout<<"Green"<<endl<<endl;                    //
		funkcja_zerujaca(straightx, splitx1, splitx2, zaklady_specjalnex, cornerx); //usuniêcie obstawionych zak³adów ze sto³u
		straightx[liczba-1]='X'; //zaznaczenie X na stole wylosowanej liczby
		if(liczba==0){           //
			straightx[36]='X';   //
		}                        //
		rysuj(straightx, splitx1, splitx2, zaklady_specjalnex, cornerx); //rysowanie sto³u z zaznaczeniem wylosowanej liczby

		for(int i=0; i<ile_graczy; i++){ //dodanie wygranej liczby ¿etonów do konta poszczególnych graczy
			for(int j=0; j<max_zakladow; j++){
				switch(zakl[i][j].nr_zak){
					case 1: wynik_zaklad_typ1(zakl, i, j, liczba,  punkty );
						break;
					case 2: wynik_zaklad_typ2(zakl, i, j, liczba, punkty );
						break;
					case 3:	wynik_zaklad_typ3(zakl, i, j, liczba, punkty );
						break;
					case 4: wynik_zaklad_typ4(zakl, i, j, liczba, punkty );
						break;
					case 5: wynik_zaklad_typ5(zakl, i, j, liczba, punkty );
						break;
					case 6: wynik_zaklad_typ6(zakl, i, j, liczba, punkty );
						break;
					case 7: wynik_zaklad_typ7(zakl, i, j, liczba, punkty, pola );
						break;
				}
			}
		}
		cout<<"Aktualny stan punktacji:"<<endl;
		
		for(int i=0; i<ile_graczy; i++){ //wypisanie w tabeli aktualnej punktacji po zakoñczonej rundzie
			cout<<"+-----------+---------+"<<endl;
			cout<<"|"<<setw(2)<<"Gracz nr."<<i+1<<setw(2)<<"|"<<setw(5)<<punkty[i]<<setw(5)<<"|"<<endl;
			if(punkty[i]==0)punkty_0=true;							
		}
			cout<<"+-----------+---------+"<<endl;
		ktora_runda=ktora_runda+1; //zliczanie liczby przeprowadzonych rund
		if(ktora_runda==max_rund){ //jezeli zakoñczy³a sie 10 runda to zakoñcz dzia³anie pêtli
			system("pause");
			system("cls");
			break;
		}
		if(punkty_0==true){ //je¿eli którys z graczy ma 0 zetonów po zakoñczeniu rundy, zakoñcz dzia³anie pêtli
			system("pause");
			system("cls");
			break;
		}
		
		for(int i=0; i<ile_graczy; i++){ //zerowanie danych na temat zak³adów postawionych w zakoñczonej rundzie
			for(int j=0; j<500; j++){
				zakl[i][j].nr_zak=0;
				zakl[i][j].kasa=0;
				zakl[i][j].tabp[0]=0;
				zakl[i][j].tabp[1]=0;
				zakl[i][j].tabp[2]=0;
				zakl[i][j].tabp[3]=0;
			}
		}
		
		cout<<endl<<"Przejdzmy do nastepnej rundy!!"<<endl;
		system("pause");
		system("cls");
	}	
	cout<<endl<<"KONIEC GRY!!"<<endl;
	cout<<endl<<"Ostateczna punktacja:"<<endl;
	for(int i=0; i<ile_graczy; i++){ //wypisanie ostatecznej punktacji
		cout<<"Gracz nr."<<i+1<<setw(2)<<"|"<<setw(2)<<punkty[i]<<endl;
	}
	int zwyciezca=0;								
	for(int i=0; i<ile_graczy; i++){ //sprawdzenie który gracz zebra³ najwiêcej zetonów
		if(punkty[i]>punkty[zwyciezca]){
			zwyciezca=i;
		}
	}
	cout<<endl<<"Wygrywa gracz nr. "<<zwyciezca+1; //wypisanie zwyciêzcy
	return 0;
}
