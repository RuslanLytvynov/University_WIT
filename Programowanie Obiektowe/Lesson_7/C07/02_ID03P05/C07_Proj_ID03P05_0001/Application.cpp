///************************************************
void Application::Run(){
    Main05();
    }
///************************************************
void Application::Main01(){
    cout<<"\n\n\t\tApplication -> Main01\n\n\n";
    }
///************************************************
void Application::Main02(){
    MyClass myClass;
    myClass.Print("\n");
    myClass.Ini(1, 2, 3);
    myClass.Print("\n");
    }
///************************************************
void Application::Main03(){
    MyClass m0, m1, m2, m3, m4, m5;
    }
///************************************************
void Application::Main04(){
    MyClass m0, m1, m2, m3, m4, m5;
    cout<<"Adres m0:";
    m0.Adr();
    cout<<"Adres m1:";
    m1.Adr();
    cout<<"Adres m2:";
    m2.Adr();
    cout<<"Adres m3:";
    m3.Adr();
    cout<<"Adres m4:";
    m4.Adr();
    cout<<"Adres m5:";
    m5.Adr();

    }
///************************************************
void Application::Main05(){
    MyClass m0(11, 12, 13);
    m0.Print();
    ///m0.x2 = 9999;
    m0.Ini(9999,12, 13);
    m0.Print();
    }
///************************************************
