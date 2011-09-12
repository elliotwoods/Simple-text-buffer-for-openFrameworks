#pragma once

#include "ofMain.h"
#include "textInput.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		//void keyPressed  (int key);
	
		textInput textBox;
	
		/////
		//for the purpose of this example
		vector<string> textEntries;
		void addText(string& s);
		void drawEntries();
		//
		/////
};
