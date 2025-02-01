//=================================================
// Isabella Rivera and Joel Singh
// January 2025
// projecttwo.cpp
// This program attempts to determine if soprano gets
// caught by either of his two owners as he tries to
// jump onto the counter. The program reads input data
// about the time of his hop, and the time each of the
// owners spend in and out of kitchen. 
//=================================================

#include <iostream>
using namespace std;
bool determineHopSuccess(int p1_in, int p1_out, int p2_in, int p2_out, int t_hop);

//Initializing cycles
int main() {
    int p1_in;
    int p1_out;
    int p2_in;
    int p2_out;
    int t_hop;

    cin >> p1_in;
    cin >> p1_out;
    cin >> p2_in;
    cin >> p2_out;
    cin >> t_hop;
    determineHopSuccess( p1_in, p1_out,  p2_in, p2_out, t_hop);

    if (determineHopSuccess(p1_in, p1_out,  p2_in, p2_out, t_hop)){
        cout <<"CAUGHT"<< endl;
    }
    else{
        cout << "SUCCESS"<< endl;
    }
}

// create cycles for each person
bool determineHopSuccess(int p1_in, int p1_out, int p2_in, int p2_out, int t_hop){
    t_hop %= 1440;
    int cycleOne= p1_in + p1_out;
    int cycleTwo = p2_in + p2_out;

    int sopranoLoc1 = t_hop % cycleOne;
    int sopranoLoc2 = t_hop % cycleTwo;
    bool failure1 = false;
    bool failure2 = false;

    //Check if someone is in the kitchen
    if (sopranoLoc1 < p1_in){
        failure1 = true;
    }
    

    if (sopranoLoc2 < p2_in){
        failure2 = true;
    }

    return failure1 || failure2;
}
