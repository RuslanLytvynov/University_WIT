///*****************************************
void Application::Run(){
    Main02();
    }
///*****************************************
void Application::Main01(){
    MyClass m0(1, 2, 3);

    cout<<m0.ToString()<<endl;

    cout<<m0.ToString()<<endl;

    MyClass m1(m0);

    m0.x2 = 1;
    cout<<"m0 : "<<m0.ToString()<<endl;

    cout<<"m1 : "<<m0.ToString()<<endl;


    }
///*****************************************
void Application::Main02(){
    MyClasses mS0;
    }
///*****************************************
