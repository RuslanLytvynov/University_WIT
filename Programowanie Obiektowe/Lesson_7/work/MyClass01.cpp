///*****************************************************
MyClass01::MyClass01(){
    cout<<"\n\t\tKonstruktor MyClass01\n";
    this->x2 = 2;
    this->x1 = 1;
    this->x0 = 0;
    }
///*****************************************************
MyClass01::MyClass01(int x2, int x1, int x0){
    cout<<"\n\t\Try Konstruktory MyClass01\n";
    this->x2 = 2;
    this->x1 = 1;
    this->x0 = 0;
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
