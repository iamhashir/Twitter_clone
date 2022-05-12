
#include "ofApp.h"
void ofApp::update()
{
}
//--------------------------------------------------------------
void ofApp::setup()
{

	// small font is used to load the font of user tweets
	smallFont.load("segoeuii.ttf", 12);

	// large font is used to load the font of timestamp of our tweets
	largeFont.load("segoeuii.ttf", 18);

	// logo font is used to load the font of our main logo of our app it is the biggest font of our page
	LogoFont.load("Lobster-Regular.ttf", 3000, true, true, true, .5, 2);

	// Background twitter image is being loaded here
	backgroundImg.load("background1.jpg");

	// The height and width of left side buttons are set here

	Leftbtn1.set(ofGetViewportWidth() / 14, ofGetViewportHeight() / 2.5);
	Leftbtn2.set(ofGetViewportWidth() / 14, ofGetViewportHeight() / 1.5);
	// viewport height unit is used so that it remain responsive

	// The height and width of bottom side buttons are set here

	Bottombtn2.set(ofGetViewportWidth() / 2.85, ofGetViewportHeight() / 1.1);
	Bottombtn1.set(ofGetViewportWidth() / 2, ofGetViewportHeight() / 1.1);
	Bottombtn3.set(ofGetViewportWidth() / 1.55, ofGetViewportHeight() / 1.1);
	// viewport height  and width unit is used so that it remain responsive with our screen

	// The height and width of right side buttons are set here

	Rightbtn1.set(ofGetViewportWidth() / 1.1, ofGetViewportHeight() / 2.5);
	Rightbtn2.set(ofGetViewportWidth() / 1.1, ofGetViewportHeight() / 1.5);

	// The height and width of top side buttons are set here
	Topbtn1.set(ofGetViewportWidth() / 1.6, ofGetViewportHeight() / 9);
	Topbtn2.set(ofGetViewportWidth() / 2.8, ofGetViewportHeight() / 9);
	Topbtn3.set(ofGetViewportWidth() / 2, ofGetViewportHeight() / 9);
	// viewport height  and width unit is used so that it remain responsive with our screen

	// radius is set here for convenience of our clickable buttons it set the area which should be clickable for the buttons
	radius = 30;

	// load data function is called so that our data loads from the tweets files and proceed further
	loadData();

	// width and height is set for our buttons it is kept same for each and every buttons because the all are made equal to each other
	width = ofGetViewportWidth() / 6.5;
	height = ofGetViewportHeight() / 8;
}

// function adds line breaks into string passed to it and returns formatted string
string ofApp::wrapString(string text, int width)
{
	string typeWrapped = "";

	string StringTempHolder = "";
	
	vector<string> words = ofSplitString(text, ""); 
	
	// text is being splitted
	
	for (int i = 0; i < words.size(); i++)
	{						   
	// loop is iterated through out the vector
	
		string wrd = words[i]; // gathers current word 

		// in case if we are not on the first word space is added
		if (i > 0)
		{
			StringTempHolder += " ";
		}
		StringTempHolder += wrd; // adds current word to string holder

		int stringwidth = smallFont.stringWidth(StringTempHolder); // set the line width of our string

		if (stringwidth >= width)
		{						 // decides weather to add a space or a new line 
			typeWrapped += "\n"; 
			StringTempHolder = wrd;	 
			// last word is also added 
		}
		else if (i > 0)
		{
			typeWrapped += " "; // space is added if not on first word
		}
		typeWrapped += wrd;
	}
	return typeWrapped;
};

//---------------------------------------------------------------------
void ofApp::loadData()
{
	userData.open(ofToDataPath("sampleTweets.csv")); // Launches the csv files to gather data of tweets
	if (userData.is_open())
	{ // checks the status of a file

		while (!userData.eof())
		{
			getline(userData, tweetTimestamp, ',');
			getline(userData, charSkip, 'b');
			getline(userData, tweetContainer);
			// retrieves all the data into tweetcontainer string
			tweetContainer1.push_back(tweetTimestamp);
			tweetContainer2.push_back(tweetContainer); // pushes the tweets into container
		}
		tweetContainer1.erase(tweetContainer1.begin()); // Deletes the heading of our first tweet

		userData.close(); // the file is closed after being used
	}
	else
	{
		cout << "The file was unable to found." << endl; // exception is handled over here
	}
};

//---------------------------------------------------------------------------------------------
void ofApp::draw()
{
	// sets the color of our background image to light blue

	ofSetColor(26, 140, 216);
	// image is instantiated and drawed on the background
	backgroundImg.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	// sets the color of our logo font
	ofSetColor(0, 230, 255);

	// logo is instantiated on the screen and set to top left corner
	LogoFont.drawString("Tweet It", 50, 130);

	// sets the color of our main tweets
	ofSetColor(255, 255, 255);

	// tweets counter is set over here to control the amount of tweets instantiated
	tweetsCounter = 0;

	int i = 350, j = 220,

		k = 350, l = 240;

	// a for loop is set over here to draw tweets time stamp and user's tweets over the screen
	for (int a = 0; a < userTweets.size(); a++)
	{
		// time stamp is drawn over the screen to specific cordinaes
		largeFont.drawString(tweetsTimestamp[a], i, j);
		j += 82;
		// the y value of our timestamp is incremented by 82 so that it always proceed to further line

		string newText = wrapString(userTweets[a], 250);
		// time user's tweets is drawn over the screen to specific cordinaes

		smallFont.drawString(newText, k, l);
		l += 80;
		// the y value of our main tweets is incremented by 80 so that it always proceed to other lines

		// the loop is set to break when it reached to 6 so that it only produces 6 tweets
		if (tweetsCounter > 6)
		{
			break;
		}
		tweetsCounter++;
	}

	// color is set to aqua of our ellipse
	ofSetColor(26, 140, 216);

	// ellispes are drawn for different buttons on our app

	// left side buttons are drawn over screen
	ofDrawEllipse(Leftbtn1, width, height);
	ofDrawEllipse(Leftbtn2, width, height);

	// right side buttons are drawn over screen
	ofDrawEllipse(Rightbtn1, width, height);
	ofDrawEllipse(Rightbtn2, width, height);

	// Top side buttons are drawn over screen
	ofDrawEllipse(Topbtn1, width, height);
	ofDrawEllipse(Topbtn2, width, height);
	ofDrawEllipse(Topbtn3, width, height);
	// bottom side buttons are drawn over screen
	ofDrawEllipse(Bottombtn1, width, height);
	ofDrawEllipse(Bottombtn2, width, height);
	ofDrawEllipse(Bottombtn3, width, height);

	// color of our string is changed
	ofSetColor(92, 40, 147);
	// now the name of our buttons are set to diffent coordinates where our buttons are located
	largeFont.drawString("Politics", 68, 400);
	largeFont.drawString("Wait", 74, 665);
	largeFont.drawString("girls", 514, 900);
	largeFont.drawString("justify", 734, 900);
	largeFont.drawString("uber", 960, 900);
	largeFont.drawString("loan", 1354, 400);
	largeFont.drawString("study", 1354, 665);
	largeFont.drawString("computer", 500, 118);
	largeFont.drawString("physics", 720, 118);
	largeFont.drawString("love", 940, 118);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	// left button is set over here to react to the event when the mouse is pressed over left button cordinate
	if (Leftbtn1.distance(ofPoint(x, y)) < radius)
	{
		// tweets are cleared by default first
		userTweets.clear();

		// a loop is used to iterate inside the vector to match the specific word and give the result over screen
		for (int i = 0; i < tweetContainer2.size(); i++)
		{
			string str1 = tweetContainer2[i];
			if (str1.find("politics") != string::npos)
			{
				// when specific tweets is found it pushes back inside a vector to later print over screen in other function
				userTweets.push_back(tweetContainer2[i]);
				tweetsTimestamp.push_back(tweetContainer1[i]);
			}
		}
	}
	// left button is set over here to react to the event when the mouse is pressed over left button cordinate
	else if (Leftbtn2.distance(ofPoint(x, y)) < radius)
	{
		userTweets.clear();

		// a loop is used to iterate inside the vector to match the specific word and give the result over screen
		for (int i = 0; i < tweetContainer2.size(); i++)
		{
			string str1 = tweetContainer2[i];
			if (str1.find("wait") != string::npos)
			{
				// when specific tweets is found it pushes back inside a vector to later print over screen in other function

				userTweets.push_back(tweetContainer2[i]);
				tweetsTimestamp.push_back(tweetContainer1[i]);
				// count++;
			}
		}
	}
	// bottom button is set over here to react to the event when the mouse is pressed over bottom button cordinate
	else if (Bottombtn3.distance(ofPoint(x, y)) < 100)
	{
		userTweets.clear();
		// a loop is used to iterate inside the vector to match the specific word and give the result over screen

		for (int i = 0; i < tweetContainer2.size(); i++)
		{
			string str1 = tweetContainer2[i];
			if (str1.find("uber") != string::npos)
			{
				// when specific tweets is found it pushes back inside a vector to later print over screen in other function

				userTweets.push_back(tweetContainer2[i]);
				tweetsTimestamp.push_back(tweetContainer1[i]);
				// count++;
			}
		}
	}

	// bottom button is set over here to react to the event when the mouse is pressed over bottom button cordinate
	else if (Bottombtn2.distance(ofPoint(x, y)) < 100)
	{
		userTweets.clear();
		// a loop is used to iterate inside the vector to match the specific word and give the result over screen
		for (int i = 0; i < tweetContainer2.size(); i++)
		{
			string str1 = tweetContainer2[i];
			if (str1.find("girls") != string::npos)
			{
				// when specific tweets is found it pushes back inside a vector to later print over screen in other function
				userTweets.push_back(tweetContainer2[i]);
				tweetsTimestamp.push_back(tweetContainer1[i]);
				// count++;
			}
		}
	}
	// bottom button is set over here to react to the event when the mouse is pressed over bottom button cordinate
	else if (Bottombtn1.distance(ofPoint(x, y)) < 100)
	{
		userTweets.clear();
		// a loop is used to iterate inside the vector to match the specific word and give the result over screen
		for (int i = 0; i < tweetContainer2.size(); i++)
		{
			string str1 = tweetContainer2[i];
			if (str1.find("justify") != string::npos)
			{
				// when specific tweets is found it pushes back inside a vector to later print over screen in other function
				userTweets.push_back(tweetContainer2[i]);
				tweetsTimestamp.push_back(tweetContainer1[i]);
				// count++;
			}
		}
	}
	// right button is set over here to react to the event when the mouse is pressed over bottom right cordinate
	else if (Rightbtn1.distance(ofPoint(x, y)) < 100)
	{
		userTweets.clear();
		// a loop is used to iterate inside the vector to match the specific word and give the result over screen
		for (int i = 0; i < tweetContainer2.size(); i++)
		{
			string str1 = tweetContainer2[i];
			if (str1.find("loan") != string::npos)
			{
				// when specific tweets is found it pushes back inside a vector to later print over screen in other function
				userTweets.push_back(tweetContainer2[i]);
				tweetsTimestamp.push_back(tweetContainer1[i]);
				// count++;
			}
		}
	}
	// right button is set over here to react to the event when the mouse is pressed over bottom right cordinate
	else if (Rightbtn2.distance(ofPoint(x, y)) < 100)
	{
		userTweets.clear();
		// a loop is used to iterate inside the vector to match the specific word and give the result over screen
		for (int i = 0; i < tweetContainer2.size(); i++)
		{
			string str1 = tweetContainer2[i];
			if (str1.find("study") != string::npos)
			{
				// when specific tweets is found it pushes back inside a vector to later print over screen in other function
				userTweets.push_back(tweetContainer2[i]);
				tweetsTimestamp.push_back(tweetContainer1[i]);
				// count++;
			}
		}
	}
	// top button is set over here to react to the event when the mouse is pressed over bottom top cordinate
	else if (Topbtn1.distance(ofPoint(x, y)) < 100)
	{
		userTweets.clear();
		// a loop is used to iterate inside the vector to match the specific word and give the result over screen
		for (int i = 0; i < tweetContainer2.size(); i++)
		{
			string str1 = tweetContainer2[i];
			if (str1.find("shine") != string::npos)
			{
				// when specific tweets is found it pushes back inside a vector to later print over screen in other function
				userTweets.push_back(tweetContainer2[i]);
				tweetsTimestamp.push_back(tweetContainer1[i]);
				// count++;
			}
		}
	}
	// top button is set over here to react to the event when the mouse is pressed over bottom top cordinate
	else if (Topbtn2.distance(ofPoint(x, y)) < 100)
	{
		userTweets.clear();
		// a loop is used to iterate inside the vector to match the specific word and give the result over screen
		for (int i = 0; i < tweetContainer2.size(); i++)
		{
			string str1 = tweetContainer2[i];
			if (str1.find("computer") != string::npos)
			{
				// when specific tweets is found it pushes back inside a vector to later print over screen in other function
				userTweets.push_back(tweetContainer2[i]);
				tweetsTimestamp.push_back(tweetContainer1[i]);
				// count++;
			}
		}
	}
	// top button is set over here to react to the event when the mouse is pressed over bottom top cordinate
	else if (Topbtn3.distance(ofPoint(x, y)) < 100)
	{
		userTweets.clear();
		// when specific tweets is found it pushes back inside a vector to later print over screen in other function
		for (int i = 0; i < tweetContainer2.size(); i++)
		{
			string str1 = tweetContainer2[i];
			if (str1.find("physics") != string::npos)
			{
				// a loop is used to iterate inside the vector to match the specific word and give the result over screen
				userTweets.push_back(tweetContainer2[i]);
				tweetsTimestamp.push_back(tweetContainer1[i]);
				// count++;
			}
		}
	}
}
