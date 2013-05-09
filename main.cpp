#include <iostream>
#include <fstream>

using namespace std;

int displayMenu();

int main()
{
    //set up variables
    int numFrames;
    //prompt for numFrames
    cout<<"Please enter the number of frames in this sample: "<<endl;
    cin>>numFrames;

    //setup the frames.
    char* frames = new char[numFrames];
    //get the sample type.
    int sampleType = displayMenu();
    //don't forget to delete the frames.
    delete[] frames;
    return 0;
}

int displayMenu()
{
    int choice = 0;
    do
    {
        //display the menu.
        cout<<"Choose a wave type:"<<endl;
        cout<<"1) Square"<<endl;
        cout<<"2) Sawtooth (/|)"<<endl;
        cout<<"3) Sin"<<endl;
        cout<<"4) Triangle"<<endl;
        cin>>choice;
    }while(choice<=0 || choice>4);
    return choice;
}
