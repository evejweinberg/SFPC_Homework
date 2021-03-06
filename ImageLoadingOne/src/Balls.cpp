//
//  Balls.cpp
//  ImageLoadingOne
//
//  Created by Eve Weinberg on 4/28/15.
//
//

#include "Balls.h"


//-----------------------------------------------------------------------
void Balls::setup(){

aStart.set(ofGetWidth()/2,ofGetHeight()+500);
bEnd.set(ofGetWidth()/2, -1200);
pct = 0;
    
    cloud.loadImage("cloud.png");
   
}



//-----------------------------------------------------------------------
void Balls::update(){

  
    pct += 0.001;   // ie: pct = pct + 0.005
    
    if (pct > 1){
        pct = 0;
    }
}





//-----------------------------------------------------------------------
void Balls::draw(){
    
    
    for (int k = 0; k < 10; k ++) {
    for (int j = 0; j < 700; j ++) {
        ofSetColor(0);
        if (j % 2 == 0){
        cloud.draw((70*ofGetElapsedTimef())+(j*500)-1000,600*k,214,91);
        } else {
           cloud.draw((70*ofGetElapsedTimef())+(j*500)-1000,600*k+300,214,91);
        }
    }
    }
    


    
    
    float x,y;
    ofPoint(0,0);
    ofPoint(ofGetWidth(),ofGetHeight());
    
    
    float pctShaped =  powf(pct, .5);     //pct * pct;      ///powf(pct, 2);
    ofPoint mixPt = (1.0-pctShaped) * aStart + pctShaped * bEnd;
    ofSetColor(0);
    ofCircle(mixPt, 450);
    
    ofSetColor(50);
    ofCircle(mixPt, 350);
    
    ofSetColor(100);
    ofCircle(mixPt, 200);
    
    ofSetColor(220);
    ofCircle(mixPt, 100);
    

    
    
}
