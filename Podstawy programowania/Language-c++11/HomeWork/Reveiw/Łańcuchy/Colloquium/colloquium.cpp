#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


int main (int argc,char *argv[]){
	std::ifstream input(argv[1]);
	std::string lin;
	std::getline (input,lin);
	int sub = 0, stud = 0;
	double check;
	for(std::istringstream strea(lin); strea>>check;sub++);
	std::vector<double> srednia(sub);
	for(std::string current; std::getline(input,lin);){
		std::istringstream stream(lin);
		double ocena_suma=0;
		if(stream>>current){
			stud++;
			std::cout<<current<<" ";
			for(int k=0;stream>>current;k++){
					double ocena;
					std::istringstream(current)>>ocena;
					ocena_suma+=ocena;
					srednia[k]=srednia[k]+ocena;}
		std::cout<<ocena_suma<<std::endl;}}
	int i=1;
	for (double cur :srednia){
		double a = cur/stud;
		std::cout<<i<<" "<<a<<std::endl;
	i++;}
	}
