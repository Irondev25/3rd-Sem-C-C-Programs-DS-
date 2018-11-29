// exceptions with arguments

#include <iostream>
#include<string>

using namespace std;

class Distance
{
    int feet;
    float inches;

  public:
    class InchesEx
    {
      public:
        string origin;
        float iValue;
        InchesEx(string origin, float inches){
            this->origin = origin;
            this->iValue = inches;
        }
    };
    Distance() : feet(0), inches(0.0) {}
    Distance(int ft, float in)
    {
        if (in >= 12.0)
            throw InchesEx("2-arg constructor", in);
        feet = ft;
        inches = in;
    }
    void getdist(){
        cout<<"\nEnter feet: ";
        cin>>feet;
        cout<<"Enter inches: ";
        cin>>inches;
        if(inches>=12.0)
            throw InchesEx("getdist() function", inches);
    }
    void showdist()
    {
        cout << feet << "\'-" << inches << '\"';
    }
};

int main()
{
    try{
        Distance dist1(17, 3.5); //2-arg constructor
        Distance dist2;          //no-arg constructor
        dist2.getdist();         //get value
        //display distances
        cout << "\ndist1 = ";
        dist1.showdist();
        cout << "\ndist2 = ";
        dist2.showdist();
    }
    catch (Distance::InchesEx ix) //exception handler
    {
        cout << "\nInitialization error in " << ix.origin
             << ".\n Inches value of " << ix.iValue
             << " is too large.";
    }
    cout << endl;
    return 0;
}