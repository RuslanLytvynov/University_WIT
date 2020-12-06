///****************************************************************
string MyUtility::ToString(int Number){
    string Result;

    ostringstream convert;
    convert << Number;
    Result = convert.str();

    return Result;
    }
///****************************************************************
string MyUtility::ToString(double Number){
    string Result;

    ostringstream convert;
    convert << Number;
    Result = convert.str();

    return Result;
    }
///****************************************************************
int MyUtility::MyRead(const char* myStr){
    int x;
    cout<<myStr;
    cin>>x;
    return x;
    }
///****************************************************************
