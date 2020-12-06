///*************************************************
MyClass::MyClass(){
    cout<<"\n\t\tKonstruktor bezargumentowy MyClass\n\n";
    x2 = 1;
    x1 = 7;
    x0 = 3;
    }
///*************************************************
MyClass::MyClass(int x2, int x1, int x0){
    cout<<"\n\t\tKonstruktor Trzyargumentowy MyClass\n\n";
    this->x2 = x2;
    this->x1 = x1;
    this->x0 = x0;
    }
///*************************************************
MyClass::MyClass(const MyClass& myClass){
    this->x2 = myClass.x2;
    this->x1 = myClass.x1;
    this->x0 = myClass.x0;
}
///*************************************************
int MyClass::CRC(){SetCrC(); return cRc;}
///*************************************************
int MyClass::CrC(){
    return 4*(x2%2) + 2* (x1%2) +  x0%2;
    }
///*************************************************
/**
x2%2   x1%2   x0%2
  1      1      1   =   7
  1      1      0   =   6
  1      0      1   =   5
  1      0      0   =   4
  0      1      1   =   3
  0      1      0   =   2
  0      0      1   =   1
  0      0      0   =   0
*/
///*************************************************
void MyClass::SetCrC(){
    cRc = CrC();
    }
///*************************************************
string MyClass::ToString(){
    return "("   + MyUtility::ToString(x2) +
            ", " + MyUtility::ToString(x1) +
            ", " + MyUtility::ToString(x0) +
            ") -> " + MyUtility::ToString(CRC());
    }
