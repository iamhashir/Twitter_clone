
#pragma once

#include "ofMain.h"
#include <vector>

class ofApp : public ofBaseApp {

public:
    //sets the normal used too functions
    void setup();
    void draw();
    void loadData();
    std::string ofApp::wrapString(std::string text, int width); //wrapString function is declared here

    void update();
    void mousePressed(int x, int y, int button);

    vector<string> userTweets, tweetContainer1, tweetContainer2, tweetsTimestamp;
    string tweetTimestamp, charSkip, tweetContainer;
    int height , width , radius,tweetsCounter;

    ifstream userData;

    ofRectangle btn1, btn2 ;

    //Different sort of Button names are set here
    ofPoint Topbtn1,Topbtn2,Topbtn3,Leftbtn1,Leftbtn2,Rightbtn1,Rightbtn2,Bottombtn1,Bottombtn2,Bottombtn3;
    //font names are set over here
    ofTrueTypeFont smallFont, largeFont, LogoFont;

    ofImage backgroundImg ;

};
