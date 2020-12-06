///*****************************************************
MyClass01::MyClass01(){
    cout<<"\n\t\tKonstruktor Bezargumentowy MyClass01\n";
    this->x2 = 2;
    this->x1 = 1;
    this->x0 = 0;
    }
///*****************************************************
MyClass01::MyClass01(int x2, int x1, int x0){
    cout<<"\n\t\tKonstruktor Trzyargumentowy MyClass01 \n";
    this->x2 = x2;
    this->x1 = x1;
    this->x0 = x0;
    }
///*****************************************************
void MyClass01::Ini(int x2, int x1, int x0){
    (*this).x2 = x2;
    this->x1 = x1;
    this->x0 = x0;
    }
///*****************************************************
void MyClass01::Print(const char * myStr){
    cout<<"("<<x2<<", "<<x1<<", "<<x0<<")"<<myStr;
    }
///*****************************************************
int MyClass01::CrC(){
    return 4*(x2%2) + 2*(x1%2) + x0%2;
    }
/**
x2  x1  x0
 1   1   1  = 7
 1   1   0  = 6
 1   0   1  = 5
 1   0   0  = 4
 0   1   1  = 3
 0   1   0  = 2
 0   0   1  = 1
 0   0   0  = 0
*/

///*****************************************************
