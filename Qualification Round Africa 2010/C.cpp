#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <fstream>
#include <stack>

using namespace std;
ifstream ifs("C-large-practice.in");
map<char,string> encode;

string IntToString(int i)
{
	string ret = "";
	while(i > 9){
		ret += i % 10 + 48;
		i = i / 10;
	}
	ret += i + 48;
	return ret;
}

void insert()
{
	int code = 1;
	for (int i = -1; i < 26;)
	{
		code++;
		string buf = "";
		int N = (i==14||i==21)?4:3;		//pqrs,wxyz
		for (int c = 0; c < N; ++c)
		{
			i++;
			buf += IntToString(code);
			char key = i + 97;
			encode.insert(map<char,string>::value_type(key,buf));
		}
	}
	char key = ' ';
	encode.insert(map<char,string>::value_type(key,IntToString(0)));
}

void Sol(int &cases)
{
	stack<string> st;
	string str,ret="";
	getline(ifs,str);

	for(int i=0;i<str.size();i++){
		string buf = encode[str.at(i)];
		if(ret != "" && ret.at(ret.size()-1) == buf.at(0)){
			ret += " ";
		}
		ret += buf;
	}

	ofstream ofs( "C.out", std::ios::out | std::ios::app );
	ofs << "Case #" << cases+1 << ": "+ret;

	ofs << endl;
}

int main()
{	
	insert();

	int N;
	ifs >> N;
	ifs.ignore();	//\n
	for(int c=0;c<N;c++){
		Sol(c);
	}
}

