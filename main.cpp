#include <iostream>
using namespace std;
// array for months
string months [12] = {"January","February","March","April","May","June","July",
                      "August","September","October","November","December"};
class dateConvert {
    int month , day;
public :
    dateConvert(int month , int day){
    this->month=month;
    this->day=day;
}
    bool _31_Monthes(int month ){      // function to determine if the month has 31 day or not :)
    bool check=false ;
    int _31_monthes[7]={1,3,5,7,8,10,12};
    for  ( auto i : _31_monthes ){
        if ( month == i ) {
            check= true;
            return check;
        }
    }
        return check;
}
void Convert(){

//some conditions for checking errors

    if (month<1 || month > 12 ){
        throw MonthError();
    }

    else if(day<1) {
        throw DayError();
    }

    else if (month==2 and day>29 ){
        throw DayError();
    }

    else if (!_31_Monthes(month) and day>30 ){
        throw DayError();
    }
    else{
        cout << day << " " <<months[month-1] << "\n" ;
    }

}

// exception class for month error

class MonthError{
public :
    void  error (){
    cout << "INValid Month! \n";
}
};

//    exception class for day error
class DayError{
public:
    void error (){
        cout <<"INValid Day! \n";
    }
};

};

int main (){
    int day , month ;

    cout <<"enter your day and your month : \n" ;
    cin >> day >> month ;

    dateConvert date(month,day);

// throw block should be inside the try block

    try{
        date.Convert();
    }
    catch (dateConvert::DayError D) {
        D.error();
    }
    catch (dateConvert::MonthError M) {
        M.error();
    }

}