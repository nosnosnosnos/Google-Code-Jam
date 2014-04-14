#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <fstream>
#include <stack>

using namespace std;

void Sol(int &cases,ifstream &ifs)
{
	stack<string> st;
	string str,ret="";
	getline(ifs,str);

	for(int i=0;i<str.size();i++){
		if(str.at(i) == ' '){
			st.push(ret);
			ret = "";
		}else{
			ret += str.at(i);
		}
	}
	st.push(ret);

	ofstream ofs( "B.out", std::ios::out | std::ios::app );
	ofs << "Case #" << cases+1 << ":";


	while(!st.empty()){
		ofs << " " << st.top();
		st.pop();
	}

	ofs << endl;
}

int main()
{
	ifstream ifs("B-large-practice.in");
	
	int N;
	ifs >> N;
	ifs.ignore();	//\n
	for(int c=0;c<N;c++){
		Sol(c,ifs);
	}
}

