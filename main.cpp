#include <iostream>
#include <fstream>

using namespace std;

//prototypes
int displayMenu();
void squareWave(char*, int);
void sawWave(char*, int);
void triangleWave(char*, int);

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

    //what sample are we creating?
    switch(sampleType)
    {
        case 1:
            squareWave(frames, numFrames);
            break;
        case 2:
            sawWave(frames, numFrames);
            break;
        case 4:
            triangleWave(frames, numFrames);
            break;
    }

    //write the frames to a file.
    ofstream sample("newSample.sam");
    for(int a=0; a<numFrames; a++){
        sample<<frames[a];
    }
    sample.close();

    //don't forget to delete the frames.
    delete[] frames;
    return 0;
}

void squareWave(char* frames, int numFrames){
    int halfWay = numFrames/2;
    for(int a=0; a<halfWay; a++){
        frames[a] = 0;
    }
    for(int a=halfWay; a<numFrames; a++){
        frames[a] = 255;
    }
}

void sawWave(char* frames, int numFrames){
    for(int a=0; a<numFrames;a++){
        frames[a] = ((float)a/numFrames) * (128) + 128;
    }
}

void triangleWave(char* frames, int numFrames){
    int halfway = numFrames/2;
    //go up.
    for(int a=0; a<halfway; a++){
        frames[a] = ((float)a/halfway) * 255;
    }
    //go down.
    for(int a=halfway; a<numFrames; a++){
        frames[a] = ((float)(a-halfway)/halfway)* -255 + 255;
    }
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
