#include<string>
using namespace std;

string convert_to_digital_time(int minutes){
    //complete this function
    string hours = to_string(minutes / 60);
    string remaining_minutes = to_string(minutes % 60);
    
    if(remaining_minutes.size() == 1) {
        remaining_minutes = '0' + remaining_minutes;
    }
    
    return hours+":"+remaining_minutes;
}