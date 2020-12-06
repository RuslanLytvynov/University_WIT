///*****************************************
void Application::Run(){
    Main07();
    }
///*****************************************
void Application::Main01(){
    cout<<"\n\n\t\tApplication::Main01\n\n";
    }
///*****************************************
void Application::Main02(){
    MyClass m0;
    m0.Ini(1,2,3);
    m0.Print("\n");
    cout<<"m0: ";
    m0.Adr();
    cout<<"&m0:       "<<&m0<<endl;
    }
///*****************************************
void Application::Main03(){
    MyClass m0;
    }
///*****************************************
void Application::Main04(){
    MyClass m0(1, 2, 3), m1, m2(4,2,7), m3;
    m0.Print("\n");
    m1.Print("\n");
    m2.Print("\n");
    m3.Print("\n");
    }
///*****************************************
void Application::Main05(){
    MyClass m0(1, 2, 3);
    m0.Print("\n");
    ///m0.x2 =9999;
    m0.Ini(9999,2,3);
    m0.Print("\n");
    }
///*****************************************
void Application::Main06(){
    MyClass m0(1111, 2222, 3333);
    m0.Print("\n");
    m0.Ini(9999,m0.GetX1(),m0.GetX0());
    m0.Print("\n");
    }
///*****************************************
void Application::Main07(){
    MyClass m0(1, 2, 3);
    m0.Print();
    //m0.x1 = 9;
    *(((int*)&m0)+1) = 9;

    m0.Print();

    }
///*****************************************

