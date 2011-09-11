#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0,0,0);
	
	text="";
	position=0;
	cursorx=0;
	cursory=0;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofPushMatrix();
	drawText();
	ofPopMatrix();
}

void testApp::drawText() {
	ofScale(5,5);
	ofDrawBitmapString(text, 10,10);
	
	ofPushStyle();
	float timeFrac = 255.0f * sin(3.0f * ofGetElapsedTimef());
	ofSetColor(timeFrac,timeFrac,timeFrac);
	ofSetLineWidth(3.0f);
	ofLine(cursorx*8 + 10, 13.7*cursory, cursorx*8 + 10, 10+13.7*cursory);
	ofPopStyle();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	typeKey(key);
}

void testApp::typeKey(int key) {
	//add charachter
	if (key >=32 && key <=126) {
		text.insert(text.begin()+position, key);
		position++;
	}
	
	if (key==OF_KEY_RETURN) {
		text.insert(text.begin()+position, '\n');
		position++;
	}
	
	if (key==OF_KEY_BACKSPACE) {
		if (position>0) {
			text.erase(text.begin()+position-1);
			--position;
		}
	}
	
	if (key==OF_KEY_DEL) {
		if (text.size() > position) {
			text.erase(text.begin()+position);
		}
	}
	
	if (key==OF_KEY_LEFT)
		if (position>0)
			--position;
	
	if (key==OF_KEY_RIGHT)
		if (position<text.size()+1)
			++position;	
	
	//for multiline:
	cursorx = cursory = 0;
	for (int i=0; i<position; ++i) {
		if (*(text.begin()+i) == '\n') {
			++cursory;
			cursorx = 0;
		} else {
			cursorx++;
		}
	}
}
//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}