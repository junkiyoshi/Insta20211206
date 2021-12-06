#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
	ofSetColor(255);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	int len = 20;
	for (int deg = 0; deg < 360; deg += 1) {

		int radius = ofMap(ofNoise(cos(deg * DEG_TO_RAD) * 0.8, sin(deg * DEG_TO_RAD) * 0.8, ofGetFrameNum() * 0.008), 0, 1, 200, 360);
		radius = radius / 40 * 40;

		ofPushMatrix();
		ofTranslate(glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));

		if (deg % 5 == 0) {

			ofDrawLine(glm::vec2(len * 1.5 * cos(deg * DEG_TO_RAD), len * 1.5 * sin(deg * DEG_TO_RAD)), glm::vec2(len * 1.5 * cos((deg + 180) * DEG_TO_RAD), len * 1.5 * sin((deg + 180) * DEG_TO_RAD)));
		}
		else {

			ofDrawLine(glm::vec2(len * 0.5 * cos(deg * DEG_TO_RAD), len * 0.5 * sin(deg * DEG_TO_RAD)), glm::vec2(len * 0.5 * cos((deg + 180) * DEG_TO_RAD), len * 0.5 * sin((deg + 180) * DEG_TO_RAD)));
		}

		ofPopMatrix();
	}

}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}