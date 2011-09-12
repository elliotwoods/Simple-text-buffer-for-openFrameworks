#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0,0,0);
	
	//this sets up the key pressed event
	//we could also do this ourselves manually
	textBox.init();
	
	ofAddListener(textBox.evtEnter, this, &testApp::addText);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	//I've left the draw call as manual
	// but this could also be event driven
	// like textInput::keyPressed
	ofPushMatrix();
	ofScale(5,5);
	textBox.draw();
	ofPopMatrix();
	
	drawEntries();
}

//--------------------------------------------------------------
/*
void testApp::keyPressed(int key){
	//if we don't setup the event using
	//textInput::init(), then we can
	//send key events ourselves here
	//manually. like so:
	
	textBox.keyPressed(key);
}*/

//--------------------------------------------------------------
void testApp::addText(string &s) {
	textEntries.push_back(s);
	textBox.clear();
}
//--------------------------------------------------------------
void testApp::drawEntries() {
	for (int i=0; i<textEntries.size(); ++i) {
		ofDrawBitmapString(textEntries[i], 50, 100+10*i);
	}
}