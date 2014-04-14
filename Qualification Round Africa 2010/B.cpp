#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <fstream>
#include <stack>

using namespace std;
ifstream ifs("B-large-practice.in");

void Sol(int &cases)
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
	int N;
	ifs >> N;
	ifs.ignore();	//\n
	for(int c=0;c<N;c++){
		Sol(c);
	}
}

