#include <fstream>
#include <iostream>
#include <stdio.h>
using namespace std;

const string U2 = "U2.txt";
const string U2rez = "rez.txt";

class Results{
	public:
	    string name;
	    int scorestech;
	    int scoresart;
};

Results* Freading(const string fn);


int main(){
	Results* v = Freading(U2);
	ofstream output;
    output.open(U2rez, std::ios::out);
    for(int i=0;i<3;i++){
    	string details = v[i].name + "\n"
    					 + "Average Techniqu: " + to_string(v[i].scorestech) + "\n"
    					 + "Average Art: " + to_string(v[i].scoresart) + "\n\n";
    	output<<details;
	}
    output.close();
	return 0;
}

Results* Freading(const string fn){
    int alldancers, alljudge;
	float avgTech, avgArt;
	ifstream fin(fn.c_str());
    fin >> alldancers >> alljudge;
	Results* v = new Results[alldancers];
	//Set to next line
   	fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   	for(int i=0; i < alldancers; i++){
   		//Set the average to be 0
   		avgTech = 0;
   		avgArt = 0;
   		//Read the name
		string name;
	    getline(fin,name);
	    //Assign it to the element im array
	    v[i].name = name;
	    //Calculate average of Technique score
		for(int b=0; b<alljudge; b++){
			int score;
			fin>>score;
			avgTech += score;
		}
		//Calculate average of Art
		for(int b=0; b<alljudge; b++){
			int score;
			fin>>score;
			avgArt += score;
		}
		v[i].scorestech = avgTech/alljudge;
		v[i].scoresart = avgArt/alljudge;

	   	fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return v;
}

