string MyUtility::ToString(int Number){
    string Result;

    ostringstream convert;
    convert << Number;
    Result = convert.str();

    return Result;
    }
