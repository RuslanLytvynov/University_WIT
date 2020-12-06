///************************************************
MyClass::MyClass(){
    cout<<"\n\t\tKonstruktor bezargumentowy MyClass\n\n";
    x2 = 2;
    x1 = 1;
    x0 = 0;
    }
///************************************************
MyClass::MyClass(int x2, int x1, int x0){
    cout<<"\n\t\tKonstruktor trzyargumentowy MyClass\n\n";
    this->x2 = x2;
    this->x1 = x1;
    this->x0 = x0;
    }
///************************************************
void MyClass::Ini(int x2, int x1, int x0){
    (*this).x2 = x2;
    this->x1 = x1;
    this->x0 = x0;
    }
///************************************************
void MyClass::Print(const char* myStr){
    cout<<"("<<x2<<", "<<x1<<", "<<x0<<")"<<myStr;
    }
///************************************************
void MyClass::Adr(){
    cout<<this<<endl;
    }
///************************************************

