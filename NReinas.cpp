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
		int pos = 1;
		while(!reinasAux.empty()) {
			
			for (int i =0; i <= reinasAcomodadas; i++) {
				
				if (siguiente[1] == reinasAux.top()[1]-pos) {
					siguiente[1] = siguiente[1]+1;
				}
				if (siguiente[1] == reinasAux.top()[1] ) {
					
					siguiente[1] = siguiente[1]+1;
				} 
				
				if (siguiente[1] == reinasAux.top()[1]+pos) {
					siguiente[1] = siguiente[1]+1;
				}
				
				pos++;
			}
			
			reinasAux.pop();
		}
		
		
	}
	
int acomodarReinas() {
		
		buscarPosicion();
		if (!pilaReinas.empty() and pilaReinas.top()[1] > totalReinas) {
		
			cout<<pilaReinas.top()[0]<<"| Y: "<<pilaReinas.top()[1]<<"\n";
			pilaReinas.pop();
			reinasAcomodadas--;
			cout<<pilaReinas.top()[0]<<"| Y: "<<pilaReinas.top()[1]<<"\n";
			siguiente = {pilaReinas.top()[0],pilaReinas.top()[1]+1};
			
			pilaReinas.pop();
			
			cout<<pilaReinas.top()[0]<<"| Y: "<<pilaReinas.top()[1]<<"\n";
			
		}
		if (reinasAcomodadas == totalReinas+1) {
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
	
	while (!pilaReinas.empty()) {
		cout<<pilaReinas.top()[0]<<"| Y: "<<pilaReinas.top()[1]<<"\n";
		pilaReinas.pop();
	}

}

