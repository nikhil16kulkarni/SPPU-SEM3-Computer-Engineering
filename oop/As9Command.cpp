
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main(int argc,char* argv[]){
ifstream in(argv[1]);
   if(argc<4)
	{
		cout<<"\nInvalid arguments.";
		exit(1);
	}
	if(!in){
		cout<<"\nError in opening file.";
	 	exit(1);
	 }
	string replace_data=" ";
	string old=argv[2];
	string data;
	int found;
	while(in){
		getline(in,data);
	 	found=data.find(old);
		while(data.find(old)<500){
			data.replace(found,old.size(),argv[3]);
		  	found=data.find(old);
		}
		replace_data=replace_data+data+"\n";
	}
	in.close();
	ofstream out(argv[1]);
	out<<replace_data<<endl;
	out.close();
	ifstream b(argv[1]);
	while(b){
		getline(b,data);
		cout<<data;
	}
	b.close();
	return 0;
}
