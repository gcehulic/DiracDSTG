#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
int const INF = 99999;

void ispisi(int udaljenosti[][19], int brojVrhova){
	cout << "Najkraca udaljenost izmedju dva vrha: " << endl<<endl;
	for(int i = 0; i < brojVrhova; ++i){
		for(int j = 0; j < brojVrhova; ++j){
			if(udaljenosti[i][j] == INF){
				cout << "INF  ";
			} else {
				cout << udaljenosti[i][j];
				if(udaljenosti[i][j] < 10) cout << "  ";
				else if(udaljenosti[i][j]<100) cout << " ";
			} 
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool gradPostoji(string gradovi[], string grad){
	for(int i = 0; i < 19; i++){
		if(!grad.compare(gradovi[i])){
			return true;
		}
	}
	return false;
}

void FloydWarshall(int graf[][19], int brojVrhova){
	bool ispravno = false;
	string gradovi[19] = {"Zagreb", "Varazdin", "Koprivnica", "Sisak", "Daruvar", "Slavonski Brod", "Osijek", "Vukovar", "Karlovac", "Crikvenica", "Rijeka", "Porec", "Pula", "Starigrad", "Zadar", "Knin", "Split", "Makarska", "Dubrovnik"};
	int gradoviCount = 19;
	string polaziste = "";
	string odrediste = "";
	int put = 0;
	int polazak = 0, dolazak = 0;
	int udaljenosti[19][19];
	
	for (int i = 0; i < brojVrhova; ++i){
		for(int j = 0; j < brojVrhova; ++j){
			udaljenosti[i][j] = graf[i][j];
		}
	}
	
	for(int k = 0; k < brojVrhova; ++k){
		for (int i = 0; i < brojVrhova; ++i){
			for (int j = 0; j < brojVrhova; ++j){
				if(udaljenosti[i][k] + udaljenosti[k][j] < udaljenosti[i][j]){
					udaljenosti[i][j] = udaljenosti[i][k] + udaljenosti[k][j];
				}
			}
		}
	}
	
	ispisi(udaljenosti,brojVrhova);
	do{
		cout << "Unesite polaziste: ";
		getline(cin, polaziste);
		ispravno = gradPostoji(gradovi, polaziste);
		if(!ispravno) cout << "Neispravan unos grada!\nGrad mora imati prvo slovo veliko i hrvatski znakovi nisu podrzani.\nNemojte stavljati razmak nakon naziva." << endl;
	} while (!ispravno);
	
	ispravno = false;
	do{
		cout << "Unesite odrediste: ";
		getline(cin, odrediste);
		ispravno = gradPostoji(gradovi, odrediste);
		if(!ispravno) cout << "Neispravan unos grada!\nGrad mora imati prvo slovo veliko i hrvatski znakovi nisu podrzani.\nNemojte stavljati razmak nakon naziva." << endl;
	} while(!ispravno);
	
	for (int i  = 0; i < gradoviCount; i++){
		if(!polaziste.compare(gradovi[i])){
			polazak = i;
		}
		if(!odrediste.compare(gradovi[i])){
			dolazak = i;
		}
	}
	cout << "Najkraca udaljenost od polazista to odredista: " << udaljenosti[polazak][dolazak] << " kilometara" << endl;
	
	
}

int main (){

	bool ponovi;
	
	int graf[19][19] = {
                {0,70,INF,48,INF,INF,INF,INF,49,INF,INF,INF,INF,173,INF,INF,INF,INF,INF },
                {70,0,41,102,INF,INF,INF,INF,115,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF },
                {INF,41,0,INF,72,INF,163,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF },
                {48,102,INF,0,69,133,INF,INF,INF,INF,INF,INF,INF,INF,INF,160,INF,INF,INF },
                {INF,INF,72,69,0,77,113,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF },
                {INF,INF,INF,133,77,0,69,88,INF,INF,INF,INF,INF,INF,INF,191,INF,233,280 },
                {INF,INF,163,INF,113,69,0,33,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF },
                {INF,INF,INF,INF,INF,88,33,0,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,315 },
                {49,115,INF,INF,INF,INF,INF,INF,0,82,91,INF,INF,133,INF,INF,INF,INF,INF },
                {INF,INF,INF,INF,INF,INF,INF,INF,82,0,26,INF,INF,121,INF,INF,INF,INF,INF },
                {INF,INF,INF,INF,INF,INF,INF,INF,91,26,0,79,82,INF,INF,INF,INF,INF,INF },
                {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,79,0,45,INF,INF,INF,INF,INF,INF },
                {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,82,45,0,INF,INF,INF,INF,INF,INF },
                {173,INF,INF,INF,INF,INF,INF,INF,133,121,INF,INF,INF,0,26,67,INF,INF,INF},
                {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,26,0,78,119,INF,INF },
                {INF,INF,INF,160,INF,191,INF,INF,INF,INF,INF,INF,INF,67,78,0,73,INF,INF },
                {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,119,73,0,58,INF },
                {INF,INF,INF,INF,INF,233,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,58,0,113 },
                {INF,INF,INF,INF,INF,280,INF,315,INF,INF,INF,INF,INF,INF,INF,INF,INF,113,0 },
            };

	do{
		FloydWarshall(graf, 19);
		string odg;
		bool neispravanOdg;
		do{
			neispravanOdg = false;
			cout << endl << "==================="<<endl <<"Zelite li izracunati udaljenost izmedju druga dva grada? Odgovor (da/ne): ";
			getline(cin, odg);
			if(!odg.compare("da") || !odg.compare("Da") || !odg.compare("dA") || !odg.compare("DA")){
				ponovi = true;
			} else if(!odg.compare("ne") || !odg.compare("Ne") || !odg.compare("nE") || !odg.compare("NE")){
				ponovi = false;
			} else {
				neispravanOdg = true;
				cout << endl << "Neispravan odgovor!" << endl;
			}
		} while(neispravanOdg);
		
	} while(ponovi);
	

	cin.get();
	return 0;
}
