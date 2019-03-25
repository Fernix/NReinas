#include <array>
#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;


	stack<array<int,2>> pilaReinas;
	int reinasAcomodadas = 0;
	int totalReinas;
	array<int,2> ultimo;
	array<int,2> siguiente = {0,0};
	
	

	buscarPosicion() {
		
		stack<array<int,2>> reinasAux = pilaReinas;
		//int pos = 1;
		while(!reinasAux.empty()) {
			
			for (int pos =1; pos < reinasAcomodadas;pos++) {
				cout<<siguiente[0]<<"|"<<siguiente[1]<<"-";
				if (siguiente[1] == reinasAux.top()[1]-pos) {
					siguiente[1] = siguiente[1]+1;
					cout<<siguiente[0]<<"|"<<siguiente[1]<<"-";
					cout<<"chi";
				}
				
				if (siguiente[1] == reinasAux.top()[1] ) {
					
					siguiente[1] = siguiente[1]+1;
					cout<<siguiente[0]<<"|"<<siguiente[1]<<"-";
					cout<<"che";
				} 
				
				if (siguiente[1] == reinasAux.top()[1]+pos) {
					siguiente[1] = siguiente[1]+1;
					cout<<siguiente[0]<<"|"<<siguiente[1]<<"\n";
					cout<<"ñol";
				}
				cout<<siguiente[0]<<"|"<<siguiente[1]<<"\n";
				pos++;
			}
			reinasAux.pop();
		}
		
		
	}
	
	
	
	
	cambiarPos() {
		if (!pilaReinas.empty() and pilaReinas.top()[1] >= totalReinas) {
			if (pilaReinas.size() == 1 ) {
				cout<<pilaReinas.top()[0]<<"|"<<pilaReinas.top()[1]<<"\n";
				//pilaReinas.top()[1] = pilaReinas.top()[1]+1;
				siguiente = pilaReinas.top();
				siguiente[1] = 1;
				pilaReinas.pop();
				cout<<pilaReinas.top()[0]<<"|"<<pilaReinas.top()[1]<<"\n";
				reinasAcomodadas = 0;
			
				
			} else {
				
				pilaReinas.pop();
				siguiente = pilaReinas.top();
				pilaReinas.pop();
				siguiente[1] = siguiente[1] + 1;
				reinasAcomodadas = reinasAcomodadas -2;
			}
			
			
		}
		
		
	}
	
int acomodarReinas() {
	
	
	cambiarPos();
	buscarPosicion();
		
		if (reinasAcomodadas == totalReinas) {
			cout<<"\n FIN \n";
			return 0;
		}	
		reinasAcomodadas++;	
			pilaReinas.push(siguiente);
			
			siguiente[0]++;
			siguiente[1] = 0;
			
		
		acomodarReinas();
		
		
		
		
	}
	
	
	
	

	

int main(int argc, char *argv[]) {
	cout<<"Introduzca el total de Reinas que acomodar: ";
	cin>>totalReinas;

	acomodarReinas();
	
	cout<<"Tamaño: "<<pilaReinas.size()<<"\n";
	while (!pilaReinas.empty()) {
		cout<<pilaReinas.top()[0]<<"| Y: "<<pilaReinas.top()[1]<<"\n";
		pilaReinas.pop();
	}

}

