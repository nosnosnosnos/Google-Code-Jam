#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <fstream>

using namespace std;

void Sol(int &cases,ifstream &ifs)
{
	int C,I;
	ifs >> C;
	ifs >> I;
	int P[I];
	for(int i=0;i<I;i++){
		ifs >> P[i];
		// cout << "cases:" << c << " "<< P[i] << endl;
	}

	for(int f=0;f<I-1;f++){
		if(P[f] >= C)continue;
		for(int b=f+1;b<I;b++){
			if(P[b] >= C)continue;
			if((P[f]+P[b]) == C){
				ofstream ofs( "A.out", std::ios::out | std::ios::app );
				ofs << "Case #" << cases+1 << ": " << f+1 << " " << b+1 << endl;
				// cout << f+1 << " " << b+1 << endl; 
				return;
			}
		}
	}
}

int main()
{
	ifstream ifs("A-small-practice.in");
	
	int N;
	ifs >> N;
	for(int c=0;c<N;c++){
		Sol(c,ifs);
	}
}

