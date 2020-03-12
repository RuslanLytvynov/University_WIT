#include <iostream>
#include <cmath>

constexpr double pi = 4. * std::atan(1.);

int main() {
	std::cout << "Enter 1 for circle or 2 for triangle: ";
	int figure;
	std::cin >> figure;	
	if (figure == 1) {	
		std::cout << "Enter radius:" << std::endl;
		double r;
		std::cin >> r;
		if (r > 0.) {
			double area = pi * std::pow(r,2);
			std::cout << "Circle area is " << area << std::endl;}
		else {
			std::cout << "Invalid radius!" << std::endl;}}
	else if (figure == 2) {
		std::cout << "Enter three sides: ";
		double a, b, c;
		std::cin >> a >> b >> c;
		if (a > 0. && b > 0. && c > 0. && a + b > c && b + c > a && c + a > b){		
			double s = (a+b+c)/2.;
			double triangle = std::sqrt(s*(s-a)*(s-b)*(s-c));
			std::cout << "Triangle area is " << triangle << std::endl;}
		else  {
			std::cout << "Invalid sides!" << std::endl;}
			}
			
	else { 
		std::cout << "Invalid figure!" << std::endl;}
	}	

	
