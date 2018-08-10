//
//  main.cpp
//  ironAnanchai
//
//  Created by Ananchai Mankhong on 9/12/2560 BE.
//  Copyright © 2560 Ananchai Mankhong. All rights reserved.
//

#ifdef WIN32
#include <windows.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>

#define Width 1270
#define Height 720
#define  PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647
float ironUpDown = 0.0, ironLeftRight = 0.0;

//Game Speed
int speed = 500;
int speedTower = 1;
int ironStart = 0;
int enemy1VelocityX = 1200, enemy1PositionY = 0;
int enemy2VelocityX = 2000, enemy2PositionY = 0;
int enemy3VelocityX = 2800, enemy3PositionY = 0;
int enemySpeed = 5;
int score = 0;
float firers = 0.0;
float firersEnemy = 0.0;
float angleBomb = 0.0;
float angleVowel = 0.0;
int ironHealth = 5;
float redColorEyesIron = 0.1, greenColorEyeIron = 1.0, blueColorEyeIron = 1.0; //color my eyes
bool flagsBlast = false;
int countBlast = 0;
int setScore = 1;


using namespace  std;


//|******************************* Text Show ************************************|

void display_string(int x, int y, char *string, int font)
{
    glColor3f(0.1, 1.0, 0.1);
    glRasterPos2f(x, y);
    for (int i = 0; i < (int) strlen(string); i++) {
        if(font==1)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
        if(font==2)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
        if(font==3)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,string[i]);
        if(font==4)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,string[i]);
    }
    
}


void display_stringToDetail(int x, int y, char *string, int font)
{
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(x, y);
    for (int i = 0; i < (int) strlen(string); i++) {
        if(font==1)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
        if(font==2)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
        if(font==3)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,string[i]);
        if(font==4)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,string[i]);
    }
    
}

//|******************************* END Text Show *********************************|


void MyCircle2f(GLfloat centerx, GLfloat centery, GLfloat radius)
{
    GLint i;
    GLdouble theta;
    GLint circle_points = 100;
    glBegin(GL_POLYGON);
    for (i=0; i < circle_points; i++)
    {
        theta= 2*PI*i/circle_points; // angle in radians
        glVertex2f(centerx+ radius*cos(theta),centery + radius*sin(theta));
    }
    glEnd();
}

void MyEclipese(float x_center, float y_center, float w, float h, int n = 100) {
    float theta, angle_increment;
    float x, y;
    if (n < 100)
        n = 100;
    angle_increment = PI * 2 / n;
    glPushMatrix();
    glTranslatef(x_center, y_center, 0);
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (theta = 0.0; theta < PI * 2; theta += angle_increment) {
        x = w / 2 * cos(theta);
        y = h / 2 * sin(theta);
        glVertex2f(x, y);
        glColor3f(0.5, 0.5, 0.5);
    }
    glEnd();
    glPopMatrix();
}





void ironface(){
    
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(691, 335);
    glVertex2f(717, 338);
    glVertex2f(739, 354);
    glVertex2f(756, 373);
    glVertex2f(762, 396);
    glVertex2f(767, 419);
    glVertex2f(770, 442);
    glVertex2f(773, 462);
    glVertex2f(775, 484);
    glVertex2f(774, 502);
    glVertex2f(772, 520);
    glVertex2f(767, 536);
    glVertex2f(755, 555);
    glVertex2f(736, 572);
    glVertex2f(714, 584);
    glVertex2f(687, 593);
    glVertex2f(652, 594);
    glVertex2f(618, 589);
    glVertex2f(593, 577);
    glVertex2f(569, 559);
    glVertex2f(550, 533);
    glVertex2f(541, 504);
    glVertex2f(540, 477);
    glVertex2f(546, 453);
    glVertex2f(559, 414);
    glVertex2f(573, 393);
    glVertex2f(593, 375);
    glVertex2f(624, 358);
    glVertex2f(658, 347);
    glEnd();
    
    glLineWidth(2);
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(691, 335);
    glVertex2f(717, 338);
    glVertex2f(739, 354);
    glVertex2f(756, 373);
    glVertex2f(762, 396);
    glVertex2f(767, 419);
    glVertex2f(770, 442);
    glVertex2f(773, 462);
    glVertex2f(775, 484);
    glVertex2f(774, 502);
    glVertex2f(772, 520);
    glVertex2f(767, 536);
    glVertex2f(755, 555);
    glVertex2f(736, 572);
    glVertex2f(714, 584);
    glVertex2f(687, 593);
    glVertex2f(652, 594);
    glVertex2f(618, 589);
    glVertex2f(593, 577);
    glVertex2f(569, 559);
    glVertex2f(550, 533);
    glVertex2f(541, 504);
    glVertex2f(540, 477);
    glVertex2f(546, 453);
    glVertex2f(559, 414);
    glVertex2f(573, 393);
    glVertex2f(593, 375);
    glVertex2f(624, 358);
    glVertex2f(658, 347);
    glEnd();
    
    //faceIn yello
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(756, 373);
    glVertex2f(762, 396);
    glVertex2f(767, 419);
    glVertex2f(770, 442);
    glVertex2f(773, 462);
    glVertex2f(775, 484);
    glVertex2f(774, 502);
    glVertex2f(772, 520);
    glVertex2f(767, 536);
    glVertex2f(755, 555);
    glVertex2f(735, 539);
    glVertex2f(685, 534);
    glVertex2f(642, 555);
    glVertex2f(617, 543);
    glVertex2f(597, 518);
    glVertex2f(617, 479);
    glVertex2f(601, 442);
    glVertex2f(621, 423);
    glVertex2f(641, 409);
    glVertex2f(651, 396);
    glVertex2f(652, 365);
    glVertex2f(676, 360);
    glVertex2f(709, 363);
    glVertex2f(739, 370);
    glEnd();
    //line
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(756, 373);
    glVertex2f(762, 396);
    glVertex2f(767, 419);
    glVertex2f(770, 442);
    glVertex2f(773, 462);
    glVertex2f(775, 484);
    glVertex2f(774, 502);
    glVertex2f(772, 520);
    glVertex2f(767, 536);
    glVertex2f(755, 555);
    glVertex2f(735, 539);
    glVertex2f(685, 534);
    glVertex2f(642, 555);
    glVertex2f(617, 543);
    glVertex2f(597, 518);
    glVertex2f(617, 479);
    glVertex2f(601, 442);
    glVertex2f(621, 423);
    glVertex2f(641, 409);
    glVertex2f(651, 396);
    glVertex2f(652, 365);
    glVertex2f(676, 360);
    glVertex2f(709, 363);
    glVertex2f(739, 370);
    glEnd();
    
    
    //ears
    glColor3f(0, 0, 0);
    MyCircle2f(568.36, 436.33, 30);
    glColor3f(1, 0, 0);
    MyCircle2f(568.36, 436.33, 28.5);
    
    
    //eyes
    glColor3f(redColorEyesIron, greenColorEyeIron, blueColorEyeIron);
    glBegin(GL_QUADS);
    glVertex2f(695, 469);
    glVertex2f(696, 492);
    glVertex2f(631, 489);
    glVertex2f(638, 463);
    glEnd();
    
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(695, 469);
    glVertex2f(696, 492);
    glVertex2f(631, 489);
    glVertex2f(638, 463);
    glEnd();
    
    glColor3f(redColorEyesIron, greenColorEyeIron, blueColorEyeIron);
    glBegin(GL_QUADS);
    glVertex2f(775, 484);
    glVertex2f(774, 502);
    glVertex2f(724, 494);
    glVertex2f(730, 474);
    glEnd();
    
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(775, 484);
    glVertex2f(774, 502);
    glVertex2f(724, 494);
    glVertex2f(730, 474);
    glEnd();

    glLineWidth(2);
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(653, 382);
    glVertex2f(680, 379);
    glVertex2f(697, 396);
    glVertex2f(741, 398);
    glVertex2f(756, 386);
    glEnd();
    
    

    
    
}


void ironManBody(){
    

    
    //BodyIronMan
    glColor3f(0.9, 0.1, 0.4);
    glBegin(GL_POLYGON);
    glVertex2f(548.24, 221.31);
    glVertex2f(616.14, 235.14);
    glVertex2f(661.41, 237.65);
    glVertex2f(687.81, 247.71);
    glVertex2f(707.93, 262.80);
    glVertex2f(721.76, 281.66);
    glVertex2f(723.02, 311.84);
    glVertex2f(717.99, 338.25);
    glVertex2f(680.27, 379.74);
    glVertex2f(593.50, 375.97);
    glVertex2f(578.42, 357.11);
    glVertex2f(516.80, 303.04);
    glVertex2f(514.29, 254.00);
    glEnd();
    
    glLineWidth(2);
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(548.24, 221.31);
    glVertex2f(616.14, 235.14);
    glVertex2f(661.41, 237.65);
    glVertex2f(687.81, 247.71);
    glVertex2f(707.93, 262.80);
    glVertex2f(721.76, 281.66);
    glVertex2f(723.02, 311.84);
    glVertex2f(717.99, 338.25);
    glVertex2f(680.27, 379.74);
    glVertex2f(593.50, 375.97);
    glVertex2f(578.42, 357.11);
    glVertex2f(516.80, 303.04);
    glVertex2f(514.29, 254.00);
    glEnd();
    


    
    //upBody
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(717.99, 338.25);
    glVertex2f(691.58, 335.73);
    glVertex2f(652.60, 365.91);
    glVertex2f(573.94, 393.37);
    glVertex2f(585.96, 336.99);
    glVertex2f(577.16, 301.78);
    glVertex2f(588.48, 266.57);
    glVertex2f(616, 235);
    glVertex2f(661.41, 237.65);
    glVertex2f(687.81, 247.71);
    glVertex2f(707.93, 262.80);
    glVertex2f(721.76, 281.66);
    glVertex2f(723.02, 311.84);
    glEnd();
    
    glLineWidth(2);
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(717.99, 338.25);
    glVertex2f(691.58, 335.73);
    glVertex2f(652.60, 365.91);
    glVertex2f(573, 393.37);
    glVertex2f(585.96, 336.99);
    glVertex2f(577.16, 301.78);
    glVertex2f(588.48, 266.57);
    glVertex2f(616, 235);
    glVertex2f(661.41, 237.65);
    glVertex2f(687.81, 247.71);
    glVertex2f(707.93, 262.80);
    glVertex2f(721.76, 281.66);
    glVertex2f(723.02, 311.84);
    glEnd();
    

    
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(514, 281);
    glVertex2f(577, 301);
    glEnd();
    
    
    //sixpack
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(514, 281);
    glVertex2f(577, 301);
    glVertex2f(588, 266);
    glVertex2f(616, 235);
    glVertex2f(584, 233);
    glVertex2f(567, 225);
    glVertex2f(548, 221);
    glVertex2f(514, 254);
    glEnd();
    
    
    
    //line six pack
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(514, 254);
    glVertex2f(533, 256);
    glVertex2f(554, 261);
    glVertex2f(588, 266);
    glEnd();
    
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(530, 286);
    glVertex2f(533, 256);
    glVertex2f(567, 225);
    glEnd();
    
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(549, 293);
    glVertex2f(554, 261);
    glVertex2f(584, 233);
    glEnd();
    
    
    
    //PowerCenter
    glColor3f(0.1, 0.9, 1);
    MyCircle2f(643, 291, 30);
    glColor3f(1, 1, 1);
    MyCircle2f(643, 291, 25);
    glColor3f(0.6, 1, 1);
    MyCircle2f(643, 291, 20);
    
    

    
    
    
    
}


void ironArm(){

    //finger
    glColor3f(0, 0, 0);
     MyCircle2f(379, 365, 16);
     glColor3f(1, 0, 0);
      MyCircle2f(379, 365, 15);
    
    glColor3f(0, 0, 0);
    MyCircle2f(395, 346, 18);
     glColor3f(1, 0, 0);
      MyCircle2f(395, 346, 17);
    
    glColor3f(0, 0, 0);
    MyCircle2f(414, 331, 20);
     glColor3f(1, 0, 0);
        MyCircle2f(414, 331, 19);
    glColor3f(0, 0, 0);
    MyCircle2f(436, 328, 21);
     glColor3f(1, 0, 0);
      MyCircle2f(436, 328, 20);
   
  

  
    
    
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(544.47, 377.23);
    glVertex2f(508.00, 391.06);
    glVertex2f(450.16, 409.92);
    glVertex2f(426.27, 413.69);
    glVertex2f(412.44, 412.44);
    glVertex2f(396.09, 404.89);
    glVertex2f(383.51, 394.83);
    glVertex2f(370.94, 379.74);
    glVertex2f(384.77, 354.59);
    glVertex2f(406.15, 340.76);
    glVertex2f(436.33, 328.19);
    glVertex2f(471.53, 335.73);
    glVertex2f(501.71, 344.53);
    glVertex2f(548.24, 336.99);
    glVertex2f(544.47, 377.23);
    glEnd();
    
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(544.47, 377.23);
    glVertex2f(508.00, 391.06);
    glVertex2f(450.16, 409.92);
    glVertex2f(426.27, 413.69);
    glVertex2f(412.44, 412.44);
    glVertex2f(396.09, 404.89);
    glVertex2f(383.51, 394.83);
    glVertex2f(370.94, 379.74);
    glVertex2f(384.77, 354.59);
    glVertex2f(406.15, 340.76);
    glVertex2f(436.33, 328.19);
    glVertex2f(471.53, 335.73);
    glVertex2f(501.71, 344.53);
    glVertex2f(548.24, 336.99);
    glVertex2f(544.47, 377.23);
    glEnd();
    
    
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(453.93, 365.91);
    glVertex2f(471.53, 335.73);
    glVertex2f(501.71, 344.53);
    glVertex2f(548.24, 336.99);
    glVertex2f(541.95, 352.08);
    glVertex2f(544.47, 377.23);
    glVertex2f(508.00, 391.06);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(475, 401);
    glVertex2f(453.93, 365.91);
    glVertex2f(471.53, 335.73);
    glVertex2f(501.71, 344.53);
    glVertex2f(548.24, 336.99);
    glVertex2f(541.95, 352.08);
    glVertex2f(544.47, 377.23);
    glVertex2f(508.00, 391.06);
    glEnd();
    
    
    //yellow
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(463.99, 353.34);
    glVertex2f(497.94, 363.40);
    glVertex2f(541.95, 352.08);
    glVertex2f(548.24, 336.99);
    glVertex2f(501.71, 344.53);
    glVertex2f(471.53, 335.73);
    glEnd();
    
    
  



    //shoulder
    glColor3f(0.9, 0.1, 0.4);
    glBegin(GL_POLYGON);
    glVertex2f(561.29, 405.70);
    glVertex2f(587.22, 399.86);
    glVertex2f(611.11, 387.29);
    glVertex2f(624.94, 362.14);
    glVertex2f(618.65, 339.50);
    glVertex2f(577.16, 301.78);
    glVertex2f(560.81, 318.13);
    glVertex2f(548.24, 336.99);
    glVertex2f(541.95, 352.08);
    glVertex2f(544.47, 377.23);
    glEnd();
    
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(561.29, 405.70);
    glVertex2f(587.22, 399.86);
    glVertex2f(611.11, 387.29);
    glVertex2f(624.94, 362.14);
    glVertex2f(618.65, 339.50);
    glVertex2f(577.16, 301.78);
    glVertex2f(560.81, 318.13);
    glVertex2f(548.24, 336.99);
    glVertex2f(541.95, 352.08);
    glVertex2f(544.47, 377.23);
    glEnd();
    
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(587.22, 399.86);
    glVertex2f(573.39, 393.57);
    glVertex2f(563.33, 378.49);
    glVertex2f(563.33, 355.85);
    glVertex2f(569.61, 340.76);
    glVertex2f(578.42, 324.42);
    glVertex2f(590.28, 310.34);
    glVertex2f(606.08, 320.64);
    glVertex2f(618.65, 339.50);
    glVertex2f(624.94, 362.14);
    glVertex2f(611.11, 387.29);
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(587.22, 399.86);
    glVertex2f(573.39, 393.57);
    glVertex2f(563.33, 378.49);
    glVertex2f(563.33, 355.85);
    glVertex2f(569.61, 340.76);
    glVertex2f(578.42, 324.42);
    glVertex2f(590.28, 310.34);
    glVertex2f(606.08, 320.64);
    glVertex2f(618.65, 339.50);
    glVertex2f(624.94, 362.14);
    glVertex2f(611.11, 387.29);
    glEnd();




    
    
}

void ironManLegs(){
    
    //upLeg
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(426.27, 304.30);
    glVertex2f(378.49, 309.33);
    glVertex2f(325.67, 324.42);
    glVertex2f(309.33, 321.90);
    glVertex2f(295.50, 309.33);
    glVertex2f(287.95, 291.72);
    glVertex2f(286.69, 267.83);
    glVertex2f(291.72, 243.94);
    glVertex2f(303.04, 226.34);
    glVertex2f(315.61, 218.79);
    glVertex2f(330.70, 221.31);
    glVertex2f(335.73, 237.65);
    glVertex2f(368.43, 235.14);
    glVertex2f(398.60, 237.65);
    glVertex2f(425, 237);
    glEnd();
    
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(426.27, 304.30);
    glVertex2f(378.49, 309.33);
    glVertex2f(325.67, 324.42);
    glVertex2f(309.33, 321.90);
    glVertex2f(295.50, 309.33);
    glVertex2f(287.95, 291.72);
    glVertex2f(286.69, 267.83);
    glVertex2f(291.72, 243.94);
    glVertex2f(303.04, 226.34);
    glVertex2f(315.61, 218.79);
    glVertex2f(330.70, 221.31);
    glVertex2f(335.73, 237.65);
    glVertex2f(368.43, 235.14);
    glVertex2f(398.60, 237.65);
    glVertex2f(425, 237);
    glEnd();
    
    
    
    

    
    
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(489.14, 304.30);
    glVertex2f(426.27, 304.30);
    glVertex2f(412.44, 282.92);
    glVertex2f(413.69, 264.06);
    glVertex2f(427.52, 252.74);
    glVertex2f(425.01, 237.65);
    glVertex2f(479.08, 245.20);
    glVertex2f(476.56, 262.80);
    glVertex2f(489.14, 304.30);
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(489.14, 304.30);
    glVertex2f(426.27, 304.30);
    glVertex2f(412.44, 282.92);
    glVertex2f(413.69, 264.06);
    glVertex2f(427.52, 252.74);
    glVertex2f(425.01, 237.65);
    glVertex2f(479.08, 245.20);
    glVertex2f(476.56, 262.80);
    glVertex2f(489.14, 304.30);
    glEnd();
    
    glColor3f(1, 1, 0);
    glBegin(GL_QUADS);
    glVertex2f(427.52, 252.74);
    glVertex2f(425.01, 237.65);
    glVertex2f(479.08, 245.20);
    glVertex2f(476.56, 262.80);
    glEnd();
    
    
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(479.08, 245.20);
    glVertex2f(425.01, 237.65);
    glVertex2f(448.90, 220.05);
    glVertex2f(450.16, 203.70);
    glVertex2f(518.06, 211.25);
    glVertex2f(489.14, 233.88);
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(479.08, 245.20);
    glVertex2f(425.01, 237.65);
    glVertex2f(448.90, 220.05);
    glVertex2f(450.16, 203.70);
    glVertex2f(518.06, 211.25);
    glVertex2f(489.14, 233.88);
    glEnd();
    
    
    glColor3f(1, 1, 0);
    glBegin(GL_QUADS);
    glVertex2f(448.90, 220.05);
    glVertex2f(450.16, 203.70);
    glVertex2f(518.06, 211.25);
    glVertex2f(502.14, 224.88);
    glEnd();
    

    
    
    
    //legDown
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(335.73, 237.65);
    glVertex2f(342.02, 212.50);
    glVertex2f(355.85, 196.16);
    glVertex2f(374.71, 184.84);
    glVertex2f(387.29, 202.45);
    glVertex2f(450.16, 203.70);
    glVertex2f(448.90, 220.05);
    glVertex2f(425.01, 237.65);
    glVertex2f(398.60, 237.65);
    glVertex2f(368.43, 235.14);
    glEnd();
    
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(335.73, 237.65);
    glVertex2f(342.02, 212.50);
    glVertex2f(355.85, 196.16);
    glVertex2f(374.71, 184.84);
    glVertex2f(387.29, 202.45);
    glVertex2f(450.16, 203.70);
    glVertex2f(448.90, 220.05);
    glVertex2f(425.01, 237.65);
    glVertex2f(398.60, 237.65);
    glVertex2f(368.43, 235.14);
    glEnd();

    
    
    //Belt
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(504.23, 314.36);
    glVertex2f(489.14, 304.30);
    glVertex2f(476.56, 262.80);
    glVertex2f(479.08, 245.20);
    glVertex2f(489.14, 233.88);
    glVertex2f(518.06, 211.25);
    glVertex2f(548.24, 221.31);
    glVertex2f(514.29, 254.00);
    glVertex2f(514.29, 281.66);
    glVertex2f(516.80, 303.04);
    glEnd();
    
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(504.23, 314.36);
    glVertex2f(489.14, 304.30);
    glVertex2f(476.56, 262.80);
    glVertex2f(479.08, 245.20);
    glVertex2f(489.14, 233.88);
    glVertex2f(518.06, 211.25);
    glVertex2f(548.24, 221.31);
    glVertex2f(514.29, 254.00);
    glVertex2f(514.29, 281.66);
    glVertex2f(516.80, 303.04);
    glEnd();
    
    
    
    
}

void fireIron(){
    //fireUp
    glColor3f(0.1, 0.9, 1);
    glBegin(GL_TRIANGLES);
    glVertex2f(315, 310);
    glVertex2f(316, 270);
    glVertex2f(213, 296);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLES);
    glVertex2f(315, 310);
    glVertex2f(241, 294);
    glVertex2f(316, 270);
    glEnd();
    
    
    //fireDown
    glColor3f(0.1, 0.9, 1);
    glBegin(GL_TRIANGLES);
    glVertex2f(323, 264);
    glVertex2f(237, 241);
    glVertex2f(323, 227);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLES);
    glVertex2f(323, 264);
    glVertex2f(272, 242);
    glVertex2f(323, 227);
    glEnd();
    
    
    //fire center
    glColor3f(0.1, 0.9, 1);
    glBegin(GL_TRIANGLES);
    glVertex2f(308, 292);
    glVertex2f(187, 264);
    glVertex2f(311, 237);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLES);
    glVertex2f(308, 292);
    glVertex2f(245, 267);
    glVertex2f(311, 237);
    glEnd();
    
    //fireDownLegDown
    glColor3f(0.1, 0.9, 1);
    glBegin(GL_TRIANGLES);
    glVertex2f(368, 235);
    glVertex2f(284, 207);
    glVertex2f(373, 197);
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLES);
    glVertex2f(355, 230);
    glVertex2f(321, 211);
    glVertex2f(373, 197);
    glEnd();

    
}



void ironMan(){
    
    glPushMatrix();
    if(firers == 20){
        glScalef(0.001, 0.001, 0);
        fireIron();
        firers=0;
        
    }
    fireIron();
    glPopMatrix();
    
    ironManBody();
    ironface();
    ironArm();
    ironManLegs();
    firers++;
   
}


void ironFirst(){
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2d(150, 350);
    glVertex2d(150, 450);
    glVertex2d(51, 450);
    glVertex2d(51, 350);
    glEnd();
    

}


void enemyFirst(){
    
    
    
    //bodyEnemy
    glColor3f(0, 0, 0);
    MyEclipese(800, 398, 300, 150);
    glColor3f(0.5, 0.5, 0.5);
    MyEclipese(800, 398, 300, 140);
    
    //eyesEnemy
    glColor3f(0, 0, 0);
    MyCircle2f(706, 419, 21);
    glColor3f(1, 1, 1);
    MyCircle2f(706, 419, 20);
    glColor3f(1, 0.3, 1);
    MyCircle2f(706, 419, 12);
    glColor3f(1, 0, 0);
    MyCircle2f(706, 419, 10);
    
    
    //mouth
    glLineWidth(3);
    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(655.12, 377.23);
    glVertex2f(702.90, 340.76);
    glVertex2f(690.81, 386.74);
    glVertex2f(721.54, 365.44);
    glVertex2f(714.05, 392.94);
    glVertex2f(733.21, 380.90);
    glVertex2f(735.03, 398.54);
    glVertex2f(741.24, 391.54);
    glEnd();
    
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(655.12, 377.23);
    glVertex2f(702.90, 340.76);
    glVertex2f(690.81, 386.74);
    glVertex2f(721.54, 365.44);
    glVertex2f(714.05, 392.94);
    glVertex2f(733.21, 380.90);
    glVertex2f(735.03, 398.54);
    glVertex2f(741.24, 391.54);
    glEnd();
    
    
    
    //wingUp
    
    glColor3f(0, 0.4, 0.9);
    glBegin(GL_QUADS);
    glVertex2f(951, 500);
    glVertex2f(852, 500);
    glVertex2f(800, 470);
    glVertex2f(900, 451);
    glEnd();
    glLineWidth(4);
    glColor3f(0, 0.1, 0.5);
    glBegin(GL_LINE_STRIP);
    glVertex2f(900, 451);
    glVertex2f(951, 500);
    glVertex2f(852, 500);
    glVertex2f(800, 470);
    glEnd();
    
    //wingDown
    glColor3f(0, 0.4, 0.9);
    glBegin(GL_QUADS);
    glVertex2f(850, 300);
    glVertex2f(800, 330);
    glVertex2f(900, 350);
    glVertex2f(950, 300);
    glEnd();
    glLineWidth(4);
    glColor3f(0, 0.1, 0.5);
    glBegin(GL_LINE_STRIP);
    glVertex2f(900, 350);
    glVertex2f(950, 300);
    glVertex2f(850, 300);
    glVertex2f(800, 330);
    glEnd();


}

void fireEnemyStart(){
    
    //fire
    glColor3f(1, 0.3, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(890.26, 437.58);
    glVertex2f(894.03, 364.65);
    glVertex2f(950.61, 348.31);
    glVertex2f(987.08, 345.79);
    glVertex2f(1010.97, 353.34);
    glVertex2f(985.82, 375.97);
    glVertex2f(1052.47, 383.51);
    glVertex2f(1010.97, 412.44);
    glVertex2f(1056.24, 436.33);
    glVertex2f(1033.60, 446.39);
    glVertex2f(1004.68, 455.19);
    glVertex2f(980.79, 455.19);
    glVertex2f(998.40, 463.99);
    glVertex2f(1002.17, 475.31);
    glVertex2f(965.70, 474.05);
    glVertex2f(935.52, 462.73);
    glEnd();
    glLineWidth(10);
    glColor3f(1, 0, 0.1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(890.26, 437.58);
    glVertex2f(894.03, 364.65);
    glVertex2f(950.61, 348.31);
    glVertex2f(987.08, 345.79);
    glVertex2f(1010.97, 353.34);
    glVertex2f(985.82, 375.97);
    glVertex2f(1052.47, 383.51);
    glVertex2f(1010.97, 412.44);
    glVertex2f(1056.24, 436.33);
    glVertex2f(1033.60, 446.39);
    glVertex2f(1004.68, 455.19);
    glVertex2f(980.79, 455.19);
    glVertex2f(998.40, 463.99);
    glVertex2f(1002.17, 475.31);
    glVertex2f(965.70, 474.05);
    glVertex2f(935.52, 462.73);
    glEnd();
    
    
    //fireIn
    glColor3f(1, 1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(890.97, 423.72);
    glVertex2f(893.06, 383.40);
    glVertex2f(931.75, 364.65);
    glVertex2f(968.22, 360.88);
    glVertex2f(950.61, 386.03);
    glVertex2f(985.82, 392.32);
    glVertex2f(958.16, 406.15);
    glVertex2f(989.59, 418.72);
    glVertex2f(940.55, 432.55);
    glVertex2f(968.22, 453.93);
    glVertex2f(930.50, 446.39);
    glVertex2f(911.63, 435.07);
    glEnd();
    
    
    
}

void vowel(){
    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 1, 0);
    glVertex2f(1.26, -1.26);
    glColor3f(1, 1, 0);
    glVertex2f(30.18, 54.07);
    glColor3f(1, 0, 0);
    glVertex2f(-12.57, 59.10);
    glColor3f(1, 1, 0);
    glVertex2f(-50.30, 40.24);
    glColor3f(1, 0, 0);
    glVertex2f(-61.61, -1.26);
    glColor3f(1, 1, 0);
    glVertex2f(-42.75, -38.98);
    glColor3f(1, 0, 0);
    glVertex2f(-2.51, -57.84);
    glColor3f(1, 1, 0);
    glVertex2f(37.72, -49.04);
    glColor3f(1, 0, 0);
    glVertex2f(61.61, -15.09);
    glColor3f(1, 1, 0);
    glVertex2f(60.36, 25.15);
    glColor3f(1, 0, 0);
    glVertex2f(30.18, 54.07);
    
    glEnd();
}

void enemyNumber1(){
    glPushMatrix();
    glTranslatef(832, 328, 0);
    glScalef(0.5, 0.5, 0);
    glRotatef(angleVowel, 0, 0, 1);
    vowel();
    angleVowel++;
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(851, 305, 0);
    glScalef(0.5, 0.5, 0);
    glRotatef(angleVowel, 0, 0, 1);
    vowel();
    angleVowel++;
    glPopMatrix();
    
    glPushMatrix();
    if(firersEnemy==10){
        glScalef(0.01, 0.01, 0);
        fireEnemyStart();
        firersEnemy=0;
    }
    fireEnemyStart();
    glPopMatrix();
    enemyFirst();
    firersEnemy++;

}



void enemySecond(){
    
    glLineWidth(3);
    glColor3f(0.5, 0.5, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(137.06, 13.83);
    glVertex2f(111.91, 49.04);
    glVertex2f(-52.81, 47.78);
    glVertex2f(-80.48, 42.75);
    glVertex2f(-99.34, 22.63);
    glVertex2f(-103.11, 7.54);
    glVertex2f(-99.34, -10.06);
    glVertex2f(-91.79, -25.15);
    glVertex2f(-79.22, -38.98);
    glVertex2f(-61.61, -47.78);
    glVertex2f(-25.15, -54.07);
    glVertex2f(22.63, -56.58);
    glVertex2f(79.22, -54.07);
    glVertex2f(106.88, -45.27);
    glVertex2f(139.57, -18.86);


    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(137.06, 13.83);
    glVertex2f(111.91, 49.04);
    glVertex2f(-52.81, 47.78);
    glVertex2f(-80.48, 42.75);
    glVertex2f(-99.34, 22.63);
    glVertex2f(-103.11, 7.54);
    glVertex2f(-99.34, -10.06);
    glVertex2f(-91.79, -25.15);
    glVertex2f(-79.22, -38.98);
    glVertex2f(-61.61, -47.78);
    glVertex2f(-25.15, -54.07);
    glVertex2f(22.63, -56.58);
    glVertex2f(79.22, -54.07);
    glVertex2f(106.88, -45.27);
    glVertex2f(139.57, -18.86);
    glEnd();
    
    
    //logo nueClear
    glColor3f(0, 0, 0);
    MyCircle2f(0, 0, 36);
    glColor3f(1, 1, 0);
    MyCircle2f(0, 0, 35);
    
    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0, 0);
    glVertex2f(-12, 25);
    glVertex2f(-28, -1);
    glEnd();
    
    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0, 0);
    glVertex2f(21, 25);
    glVertex2f(35, 1);
    glEnd();
    
    
    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0, 0);
    glVertex2f(20, -26);
    glVertex2f(-11, -23);
    glEnd();
    
    glColor3f(1, 1, 0);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(0, 0);
    glEnd();
    
    
    //tail
    
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex2f(137, 13);
    glVertex2f(152, 15);
    glVertex2f(153, -18);
    glVertex2f(139, -18);
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(137, 13);
    glVertex2f(152, 15);
    glVertex2f(153, -18);
    glVertex2f(139, -18);
    glEnd();
    
    glColor3f(0.5, 0.5, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(174, 61);
    glVertex2f(242, 61);
    glVertex2f(247, 22);
    glVertex2f(236, 7);
    glVertex2f(235, -6);
    glVertex2f(245, -22);
    glVertex2f(242, -65);
    glVertex2f(184, -67);
    glVertex2f(153, -18);
    glVertex2f(152, 15);
    glEnd();
    glColor3f(0, 0, 0.);
    glBegin(GL_LINE_LOOP);
    glVertex2f(174, 61);
    glVertex2f(242, 61);
    glVertex2f(247, 22);
    glVertex2f(236, 7);
    glVertex2f(235, -6);
    glVertex2f(245, -22);
    glVertex2f(242, -65);
    glVertex2f(184, -67);
    glVertex2f(153, -18);
    glVertex2f(152, 15);
    glEnd();

    glLineWidth(3);
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(152, 15);
    glVertex2f(227, 18);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(152, -6);
    glVertex2f(235, -6 );
    glEnd();
    
    
}


void enemyNumber2(){
    enemySecond();
    if(angleBomb==360){
        angleBomb=0;
    }
    angleBomb+=enemySpeed;
   
}


void enemyNumber3(){
    glPushMatrix();
    if(firersEnemy==10){
        glScalef(0.01, 0.01, 0);
        fireEnemyStart();
        firersEnemy=0;
    }
    fireEnemyStart();
    glPopMatrix();

    enemyFirst();
    firersEnemy++;
    
}


void point(){
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(30.0);
    glBegin(GL_POINTS);
    glVertex2f(0, 0);
    glEnd();
}


void ironFirstSence(){

    //display_string(548, 647, "IRON MAN", 1);
    display_string(500, 20, "\" Press Space to Start \"", 2);
    display_string(700, 400, "Made by A'Ananchai Mankhong 58160223", 2);
    display_string(1050, 20, "<-- Click detail with Playing!", 3);
}

float r1 = 1.0, g1 = 1.0, b1 = 1.0;
float r2 = 1.0, g2 = 1.0, b2 = 1.0;
float r3 = 1.0, g3 = 1.0, b3 = 1.0;
float r4 = 1.0, g4 = 1.0, b4 = 1.0;
float r5 = 1.0, g5 = 1.0, b5 = 1.0;


void health1(){
    
    
    glColor3f(r1, g1, b1);
    glBegin(GL_POLYGON);
    glVertex2f(500.46, 318.13);
    glVertex2f(479.08, 338.25);
    glVertex2f(450.16, 349.56);
    glVertex2f(427.52, 344.53);
    glVertex2f(411.18, 331.96);
    glVertex2f(398.60, 313.10);
    glVertex2f(391.06, 292.98);
    glVertex2f(391.06, 270.35);
    glVertex2f(398.60, 250.23);
    glVertex2f(413.69, 227.59);
    glVertex2f(431.30, 207.48);
    glVertex2f(448.90, 188.61);
    glVertex2f(469.02, 172.27);
    glVertex2f(499.20, 152.15);
    glVertex2f(525.60, 169.75);
    glVertex2f(543.21, 186.10);
    glVertex2f(565.84, 204.96);
    glVertex2f(580.93, 225.08);
    glVertex2f(598.53, 247.71);
    glVertex2f(604.82, 269.09);
    glVertex2f(606.08, 295.50);
    glVertex2f(596.02, 315.61);
    glVertex2f(582.19, 335.73);
    glVertex2f(564.58, 344.53);
    glVertex2f(546.98, 349.56);
    glVertex2f(520.57, 339.50);
    glEnd();
    
    
}

void health2(){
    
    
    glColor3f(r2, g2, b2);
    glBegin(GL_POLYGON);
    glVertex2f(500.46, 318.13);
    glVertex2f(479.08, 338.25);
    glVertex2f(450.16, 349.56);
    glVertex2f(427.52, 344.53);
    glVertex2f(411.18, 331.96);
    glVertex2f(398.60, 313.10);
    glVertex2f(391.06, 292.98);
    glVertex2f(391.06, 270.35);
    glVertex2f(398.60, 250.23);
    glVertex2f(413.69, 227.59);
    glVertex2f(431.30, 207.48);
    glVertex2f(448.90, 188.61);
    glVertex2f(469.02, 172.27);
    glVertex2f(499.20, 152.15);
    glVertex2f(525.60, 169.75);
    glVertex2f(543.21, 186.10);
    glVertex2f(565.84, 204.96);
    glVertex2f(580.93, 225.08);
    glVertex2f(598.53, 247.71);
    glVertex2f(604.82, 269.09);
    glVertex2f(606.08, 295.50);
    glVertex2f(596.02, 315.61);
    glVertex2f(582.19, 335.73);
    glVertex2f(564.58, 344.53);
    glVertex2f(546.98, 349.56);
    glVertex2f(520.57, 339.50);
    glEnd();
    
    
}

void health3(){
    
    
    glColor3f(r3, g3, b3);
    glBegin(GL_POLYGON);
    glVertex2f(500.46, 318.13);
    glVertex2f(479.08, 338.25);
    glVertex2f(450.16, 349.56);
    glVertex2f(427.52, 344.53);
    glVertex2f(411.18, 331.96);
    glVertex2f(398.60, 313.10);
    glVertex2f(391.06, 292.98);
    glVertex2f(391.06, 270.35);
    glVertex2f(398.60, 250.23);
    glVertex2f(413.69, 227.59);
    glVertex2f(431.30, 207.48);
    glVertex2f(448.90, 188.61);
    glVertex2f(469.02, 172.27);
    glVertex2f(499.20, 152.15);
    glVertex2f(525.60, 169.75);
    glVertex2f(543.21, 186.10);
    glVertex2f(565.84, 204.96);
    glVertex2f(580.93, 225.08);
    glVertex2f(598.53, 247.71);
    glVertex2f(604.82, 269.09);
    glVertex2f(606.08, 295.50);
    glVertex2f(596.02, 315.61);
    glVertex2f(582.19, 335.73);
    glVertex2f(564.58, 344.53);
    glVertex2f(546.98, 349.56);
    glVertex2f(520.57, 339.50);
    glEnd();
    
    
}

void health4(){
    
    
    glColor3f(r4, g4, b4);
    glBegin(GL_POLYGON);
    glVertex2f(500.46, 318.13);
    glVertex2f(479.08, 338.25);
    glVertex2f(450.16, 349.56);
    glVertex2f(427.52, 344.53);
    glVertex2f(411.18, 331.96);
    glVertex2f(398.60, 313.10);
    glVertex2f(391.06, 292.98);
    glVertex2f(391.06, 270.35);
    glVertex2f(398.60, 250.23);
    glVertex2f(413.69, 227.59);
    glVertex2f(431.30, 207.48);
    glVertex2f(448.90, 188.61);
    glVertex2f(469.02, 172.27);
    glVertex2f(499.20, 152.15);
    glVertex2f(525.60, 169.75);
    glVertex2f(543.21, 186.10);
    glVertex2f(565.84, 204.96);
    glVertex2f(580.93, 225.08);
    glVertex2f(598.53, 247.71);
    glVertex2f(604.82, 269.09);
    glVertex2f(606.08, 295.50);
    glVertex2f(596.02, 315.61);
    glVertex2f(582.19, 335.73);
    glVertex2f(564.58, 344.53);
    glVertex2f(546.98, 349.56);
    glVertex2f(520.57, 339.50);
    glEnd();
    
    
}

void health5(){
    
    
    glColor3f(r5, g5, b5);
    glBegin(GL_POLYGON);
    glVertex2f(500.46, 318.13);
    glVertex2f(479.08, 338.25);
    glVertex2f(450.16, 349.56);
    glVertex2f(427.52, 344.53);
    glVertex2f(411.18, 331.96);
    glVertex2f(398.60, 313.10);
    glVertex2f(391.06, 292.98);
    glVertex2f(391.06, 270.35);
    glVertex2f(398.60, 250.23);
    glVertex2f(413.69, 227.59);
    glVertex2f(431.30, 207.48);
    glVertex2f(448.90, 188.61);
    glVertex2f(469.02, 172.27);
    glVertex2f(499.20, 152.15);
    glVertex2f(525.60, 169.75);
    glVertex2f(543.21, 186.10);
    glVertex2f(565.84, 204.96);
    glVertex2f(580.93, 225.08);
    glVertex2f(598.53, 247.71);
    glVertex2f(604.82, 269.09);
    glVertex2f(606.08, 295.50);
    glVertex2f(596.02, 315.61);
    glVertex2f(582.19, 335.73);
    glVertex2f(564.58, 344.53);
    glVertex2f(546.98, 349.56);
    glVertex2f(520.57, 339.50);
    glEnd();
    
    
}

void healthIronMan5(){
    //Heart5
    glPushMatrix();
    glTranslatef(130, 650, 0);
    glScalef(0.15, 0.15, 0);
    health5();
    glPopMatrix();
    
}

void healthIronMan4(){
    //Heart4
    glPushMatrix();
    glTranslatef(90, 650, 0);
    glScalef(0.15, 0.15, 0);
    health4();
    glPopMatrix();
}

void healthIronMan3(){
    //Heart3
    glPushMatrix();
    glTranslatef(50, 650, 0);
    glScalef(0.15, 0.15, 0);
    health3();
    glPopMatrix();
}

void healthIronMan2(){
    //Heart2
    glPushMatrix();
    glTranslatef(10, 650, 0);
    glScalef(0.15, 0.15, 0);
    health2();
    glPopMatrix();
}

void healthIronMan1(){
    //Heart1
    glPushMatrix();
    glTranslatef(-30, 650, 0);
    glScalef(0.15, 0.15, 0);
    health1();
    glPopMatrix();
}


void healthIronManALL(){
    healthIronMan5();
    healthIronMan4();
    healthIronMan3();
    healthIronMan2();
    healthIronMan1();
}


void blast(){
  
    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(1.26, 0.00);
    glVertex2f(-93.05, -114.43);
    glVertex2f(-38.98, -98.08);
    glVertex2f(-15.09, -124.49);
    glVertex2f(30.18, -96.82);
    glVertex2f(86.76, -109.40);
    glVertex2f(100.59, -69.16);
    glVertex2f(154.66, -56.58);
    glVertex2f(130.77, -17.60);
    glVertex2f(164.72, 10.06);
    glVertex2f(130.77, 30.18);
    glVertex2f(153.41, 64.13);
    glVertex2f(105.62, 71.67);
    glVertex2f(100.59, 113.17);
    glVertex2f(46.52, 99.34);
    glVertex2f(30.18, 130.77);
    glVertex2f(-2.51, 98.08);
    glVertex2f(-44.01, 120.71);
    glVertex2f(-61.61, 79.22);
    glVertex2f(-104.37, 76.70);
    glVertex2f(-105.62, 51.55);
    glVertex2f(-142.09, 37.72);
    glVertex2f(-121.97, 10.06);
    glVertex2f(-145.86, -13.83);
    glVertex2f(-124.49, -32.69);
    glVertex2f(-148.38, -76.70);
    glVertex2f(-101.85, -80.48);
    glVertex2f(-93, -114);
    glEnd();
    
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(1.26, 0.00);
    glVertex2f(-93.05, -114.43);
    glVertex2f(-38.98, -98.08);
    glVertex2f(-15.09, -124.49);
    glVertex2f(30.18, -96.82);
    glVertex2f(86.76, -109.40);
    glVertex2f(100.59, -69.16);
    glVertex2f(154.66, -56.58);
    glVertex2f(130.77, -17.60);
    glVertex2f(164.72, 10.06);
    glVertex2f(130.77, 30.18);
    glVertex2f(153.41, 64.13);
    glVertex2f(105.62, 71.67);
    glVertex2f(100.59, 113.17);
    glVertex2f(46.52, 99.34);
    glVertex2f(30.18, 130.77);
    glVertex2f(-2.51, 98.08);
    glVertex2f(-44.01, 120.71);
    glVertex2f(-61.61, 79.22);
    glVertex2f(-104.37, 76.70);
    glVertex2f(-105.62, 51.55);
    glVertex2f(-142.09, 37.72);
    glVertex2f(-121.97, 10.06);
    glVertex2f(-145.86, -13.83);
    glVertex2f(-124.49, -32.69);
    glVertex2f(-148.38, -76.70);
    glVertex2f(-101.85, -80.48);
    glVertex2f(-93, -114);
    glEnd();
    
    
    
    glScalef(0.9, 0.9, 0);
    glColor3f(1, 0.6, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(1.26, 0.00);
    glVertex2f(-93.05, -114.43);
    glVertex2f(-38.98, -98.08);
    glVertex2f(-15.09, -124.49);
    glVertex2f(30.18, -96.82);
    glVertex2f(86.76, -109.40);
    glVertex2f(100.59, -69.16);
    glVertex2f(154.66, -56.58);
    glVertex2f(130.77, -17.60);
    glVertex2f(164.72, 10.06);
    glVertex2f(130.77, 30.18);
    glVertex2f(153.41, 64.13);
    glVertex2f(105.62, 71.67);
    glVertex2f(100.59, 113.17);
    glVertex2f(46.52, 99.34);
    glVertex2f(30.18, 130.77);
    glVertex2f(-2.51, 98.08);
    glVertex2f(-44.01, 120.71);
    glVertex2f(-61.61, 79.22);
    glVertex2f(-104.37, 76.70);
    glVertex2f(-105.62, 51.55);
    glVertex2f(-142.09, 37.72);
    glVertex2f(-121.97, 10.06);
    glVertex2f(-145.86, -13.83);
    glVertex2f(-124.49, -32.69);
    glVertex2f(-148.38, -76.70);
    glVertex2f(-101.85, -80.48);
    glVertex2f(-93, -114);
    glEnd();
    
    
    
    glScalef(0.8, 0.8, 0);
    glColor3f(1, 1, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(1.26, 0.00);
    glVertex2f(-93.05, -114.43);
    glVertex2f(-38.98, -98.08);
    glVertex2f(-15.09, -124.49);
    glVertex2f(30.18, -96.82);
    glVertex2f(86.76, -109.40);
    glVertex2f(100.59, -69.16);
    glVertex2f(154.66, -56.58);
    glVertex2f(130.77, -17.60);
    glVertex2f(164.72, 10.06);
    glVertex2f(130.77, 30.18);
    glVertex2f(153.41, 64.13);
    glVertex2f(105.62, 71.67);
    glVertex2f(100.59, 113.17);
    glVertex2f(46.52, 99.34);
    glVertex2f(30.18, 130.77);
    glVertex2f(-2.51, 98.08);
    glVertex2f(-44.01, 120.71);
    glVertex2f(-61.61, 79.22);
    glVertex2f(-104.37, 76.70);
    glVertex2f(-105.62, 51.55);
    glVertex2f(-142.09, 37.72);
    glVertex2f(-121.97, 10.06);
    glVertex2f(-145.86, -13.83);
    glVertex2f(-124.49, -32.69);
    glVertex2f(-148.38, -76.70);
    glVertex2f(-101.85, -80.48);
    glVertex2f(-93, -114);
    glEnd();
    
    
    
    glScalef(0.6, 0.6, 0);
    glColor3f(1, 1, 0.9);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(1.26, 0.00);
    glVertex2f(-93.05, -114.43);
    glVertex2f(-38.98, -98.08);
    glVertex2f(-15.09, -124.49);
    glVertex2f(30.18, -96.82);
    glVertex2f(86.76, -109.40);
    glVertex2f(100.59, -69.16);
    glVertex2f(154.66, -56.58);
    glVertex2f(130.77, -17.60);
    glVertex2f(164.72, 10.06);
    glVertex2f(130.77, 30.18);
    glVertex2f(153.41, 64.13);
    glVertex2f(105.62, 71.67);
    glVertex2f(100.59, 113.17);
    glVertex2f(46.52, 99.34);
    glVertex2f(30.18, 130.77);
    glVertex2f(-2.51, 98.08);
    glVertex2f(-44.01, 120.71);
    glVertex2f(-61.61, 79.22);
    glVertex2f(-104.37, 76.70);
    glVertex2f(-105.62, 51.55);
    glVertex2f(-142.09, 37.72);
    glVertex2f(-121.97, 10.06);
    glVertex2f(-145.86, -13.83);
    glVertex2f(-124.49, -32.69);
    glVertex2f(-148.38, -76.70);
    glVertex2f(-101.85, -80.48);
    glVertex2f(-93, -114);
    glEnd();
    
    

    glPointSize(10);
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2f(26, -158);
    glVertex2f(56, -125);
    glVertex2f(135, -133);
    glVertex2f(138, -96);
    glVertex2f(173, -90);
    glVertex2f(182, -33);
    glVertex2f(70, 134);
    glVertex2f(71, 178);
    glVertex2f(176, 158);
    glVertex2f(176, 79);
    glEnd();
    


    
}

void collisionBast(){
   
    glTranslatef(ironLeftRight+350, ironUpDown+220, 0);
    blast();
}



void ironSecondSence(){
    
    
    //IronMan
    glPushMatrix();
    glTranslatef(ironLeftRight, ironUpDown, 0);
    glScalef(0.50, 0.50, 0);
    ironMan();
    glPopMatrix();

    

    //Score Board
//    glColor3f(0.000, 0.000, 0.000);
//    glBegin(GL_POLYGON);
//    glVertex2f(1200, 650);
//    glVertex2f(1200, 700);
//    glVertex2f(1050, 700);
//    glVertex2f(1050, 650);
//    glEnd();

    //Print Score
    char buffer [100];
    sprintf (buffer, "SCORE:  %d", score);
    glColor3f(0.000, 1.000, 0.000);
    display_string(1075, 685, buffer, 1);


    //enemy1
    glPushMatrix();
    glTranslatef(enemy1VelocityX, enemy1PositionY, 0);
    glScalef(0.7, 0.7, 0);
    enemyNumber1();
    enemy1VelocityX -= enemySpeed;
    firersEnemy++;
    //check flying loop
    if(enemy1VelocityX < -900){
        enemy1VelocityX = 1500;
        enemy1PositionY = ironUpDown-80;
        score = score + setScore;
    }
    //check collision
    if(ironHealth == 0){
        ironStart = 2;

    }else{
        if( (ironUpDown-enemy1PositionY >= -20 && ironUpDown-enemy1PositionY <= 180) &&
           ironLeftRight - enemy1VelocityX == 90){
            flagsBlast = true;
            ironHealth--;
        }
    }
    glPopMatrix();
    

    //enemy2
    glPushMatrix();
    glTranslatef(enemy2VelocityX, enemy2PositionY, 0);
    glTranslatef(600, 270, 0);
    glRotatef(angleBomb, 0, 0, 1);
    glScalef(0.5, 0.5, 0);
    enemyNumber2();
    enemy2VelocityX -= enemySpeed;
    //check flying loop
    if(enemy2VelocityX < -900){
        enemy2VelocityX = 1500;
        enemy2PositionY = ironUpDown-80;
        score = score + setScore;
    }
    //check collision
    if(ironHealth == 0 ){
        ironStart = 2;

    }else{
        if((ironUpDown-enemy2PositionY >= -20 && ironUpDown-enemy2PositionY <= 180) &&
           ironLeftRight - enemy2VelocityX == 200){
            flagsBlast = true;
            ironHealth--;
        }
    }
    glPopMatrix();





    //enemy3
    glPushMatrix();
    glTranslatef(enemy3VelocityX, enemy3PositionY, 0);
    glScalef(0.7, 0.7, 0);
    enemyNumber3();
    enemy3VelocityX -= enemySpeed;
    firersEnemy++;
    //check flying loop
    if(enemy3VelocityX < -900){
        enemy3VelocityX = 1500;
        enemy3PositionY = ironUpDown-80;
        score = score + setScore;
    }
    //check collision
    if(ironHealth == 0){
        ironStart = 2;

    }else{
        if( (ironUpDown-enemy3PositionY >= -20 && ironUpDown-enemy3PositionY <= 180) &&
           ironLeftRight - enemy3VelocityX == 90){
            flagsBlast = true;
            ironHealth--;
            
        }
    }
    glPopMatrix();
    
    //cout << "HEALTH = " << ironHealth << endl;
    
            if(ironHealth == 5){
            
                r5 = 1.0; g5 = 0.0; b5 = 0.0;
                healthIronMan5();
                r4 = 1.0; g4 = 0.0; b4 = 0.0;
                healthIronMan4();
                r3 = 1.0; g3 = 0.0; b3 = 0.0;
                healthIronMan3();
                r2 = 1.0; g2 = 0.0; b2 = 0.0;
                healthIronMan2();
                r1 = 1.0; g1 = 0.0; b1 = 0.0;
              

            }
    
            if(ironHealth == 4){

                r5 = 1.0; g5 = 1.0; b5 = 1.0;
                healthIronMan5();
                r4 = 1.0; g4 = 0.0; b4 = 0.0;
                healthIronMan4();
                r3 = 1.0; g3 = 0.0; b3 = 0.0;
                healthIronMan3();
                r2 = 1.0; g2 = 0.0; b2 = 0.0;
                healthIronMan2();
                r1 = 1.0; g1 = 0.0; b1 = 0.0;
       
            }
  
            if(ironHealth == 3){
                r5 = 1.0; g5 = 1.0; b5 = 1.0;
                healthIronMan5();
                r4 = 1.0; g4 = 1.0; b4 = 1.0;
                healthIronMan4();
                r3 = 1.0; g3 = 0.0; b3 = 0.0;
                healthIronMan3();
                r2 = 1.0; g2 = 0.0; b2 = 0.0;
                healthIronMan2();
                r1 = 1.0; g1 = 0.0; b1 = 0.0;
            
            }

            if(ironHealth == 2){
                r5 = 1.0; g5 = 1.0; b5 = 1.0;
                healthIronMan5();
                r4 = 1.0; g4 = 1.0; b4 = 1.0;
                healthIronMan4();
                r3 = 1.0; g3 = 1.0; b3 = 1.0;
                healthIronMan3();
                r2 = 1.0; g2 = 0.0; b2 = 0.0;
                healthIronMan2();
                r1 = 1.0; g1 = 0.0; b1 = 0.0;
            
            }

            if(ironHealth == 1){
                r5 = 1.0; g5 = 1.0; b5 = 1.0;
                healthIronMan5();
                r4 = 1.0; g4 = 1.0; b4 = 1.0;
                healthIronMan4();
                r3 = 1.0; g3 = 1.0; b3 = 1.0;
                healthIronMan3();
                r2 = 1.0; g2 = 1.0; b2 = 1.0;
                healthIronMan2();
                r1 = 1.0; g1 = 0.0; b1 = 0.0;
                
            }
    
            if(ironHealth == 0){
                r5 = 1.0; g5 = 1.0; b5 = 1.0;
                healthIronMan5();
                r4 = 1.0; g4 = 1.0; b4 = 1.0;
                healthIronMan4();
                r3 = 1.0; g3 = 1.0; b3 = 1.0;
                healthIronMan3();
                r2 = 1.0; g2 = 1.0; b2 = 1.0;
                healthIronMan2();
                r1 = 1.0; g1 = 1.0; b1 = 1.0;
              
            }
  
    

}


void tower1(){
    
    
    //1
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.00, 250);
    glVertex2f(0.00, 343.28);
    glVertex2f(33.95, 362.14);
    glVertex2f(67.90, 339.50);
    glVertex2f(69.16, 250);
    glEnd();
    
    //window
    glColor3f(1, 1, 0.7);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(15, 330);
    glVertex2f(15, 300);
    glVertex2f(30, 330);
    glVertex2f(30, 300);
    glVertex2f(45, 330);
    glVertex2f(45, 300);
    glEnd();
}

void tower2(){
    //2
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.00, 250);
    glVertex2f(-3.77, 379.74);
    glVertex2f(11.32, 386.03);
    glVertex2f(37.72, 421.24);
    glVertex2f(62.87, 388.54);
    glVertex2f(77.96, 381.00);
    glVertex2f(89.28, 362.14);
    glVertex2f(91.79, 250);
    glEnd();
    
    //window
    glColor3f(1, 1, 0.7);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(15, 370);
    glVertex2f(15, 340);
    glVertex2f(15, 310);
    glVertex2f(15, 280);
    
    glVertex2f(30, 370);
    glVertex2f(30, 340);
    glVertex2f(30, 310);
    glVertex2f(30, 280);
    
    glVertex2f(45, 370);
    glVertex2f(45, 340);
    glVertex2f(45, 310);
    glVertex2f(45, 280);
    
    glVertex2f(60, 370);
    glVertex2f(60, 340);
    glVertex2f(60, 310);
    glVertex2f(60, 280);
    glEnd();


}

void tower3(){
    //3
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.00, 250);
    glVertex2f(-3.77, 370.94);
    glVertex2f(6.29, 383.51);
    glVertex2f(6.29, 411.18);
    glVertex2f(13.83, 443.87);
    glVertex2f(22.63, 504.23);
    glVertex2f(38.98, 443.87);
    glVertex2f(44.01, 408.66);
    glVertex2f(44.01, 381.00);
    glVertex2f(56.58, 368.43);
    glVertex2f(54.07, 250);
    glEnd();
    
    //window
    glColor3f(1, 1, 0.7);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(20, 400);
    
    glVertex2f(10, 370);
    glVertex2f(10, 340);
    glVertex2f(10, 310);
    glVertex2f(10, 280);
    
    glVertex2f(25, 370);
    glVertex2f(25, 340);
    glVertex2f(25, 310);
    glVertex2f(25, 280);
    
    glVertex2f(40, 370);
    glVertex2f(40, 340);
    glVertex2f(40, 310);
    glVertex2f(40, 280);
    glEnd();


    


}

void tower4(){
    //4
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(1.26, 250);
    glVertex2f(-1.26, 397.35);
    glVertex2f(10.06, 418.72);
    glVertex2f(59.10, 418.72);
    glVertex2f(76.70, 394.83);
    glVertex2f(72.93, 250);
    glEnd();
    
    //window
    glColor3f(1, 1, 0.7);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(15, 350);
    glVertex2f(15, 300);
    glVertex2f(30, 350);
    glVertex2f(30, 300);
    glVertex2f(45, 350);
    glVertex2f(45, 300);
    glEnd();


}

void tower5(){
    //5
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(1.26, 250);
    glVertex2f(0.00, 404.89);
    glVertex2f(44.01, 442.61);
    glVertex2f(72.93, 399.86);
    glVertex2f(67.90, 250);
    glEnd();
    //window
    glColor3f(1, 1, 0.7);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(15, 330);
    glVertex2f(15, 300);
    glVertex2f(15, 390);
    glVertex2f(30, 330);
    glVertex2f(30, 300);
    glVertex2f(30, 390);
    glVertex2f(45, 330);
    glVertex2f(45, 300);
    glVertex2f(45, 390);
    glEnd();


}

void tower6(){
    //6
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(1.26, 250);
    glVertex2f(-1.26, 377.23);
    glVertex2f(31.44, 430.04);
    glVertex2f(61.61, 373.46);
    glVertex2f(67.90, 250);
    glEnd();
    
    //window
    glColor3f(1, 1, 0.7);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(15, 330);
    glVertex2f(15, 300);
    glVertex2f(15, 360);
    glVertex2f(30, 330);
    glVertex2f(30, 300);
    glVertex2f(30, 360);
    glVertex2f(45, 330);
    glVertex2f(45, 300);
    glVertex2f(45, 360);
    
    glEnd();


}

void tower7(){
    //7
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(2.51, 250);
    glVertex2f(-3.77, 413.69);
    glVertex2f(11.32, 431.30);
    glVertex2f(11.32, 446.39);
    glVertex2f(23.89, 457.70);
    glVertex2f(30.18, 485.37);
    glVertex2f(42.75, 450.16);
    glVertex2f(52.81, 443.87);
    glVertex2f(51.55, 419.98);
    glVertex2f(64.13, 402.38);
    glVertex2f(64.13, 250);
    glEnd();
    
    //window
    glColor3f(1, 1, 0.7);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(15, 330);
    glVertex2f(15, 300);
    glVertex2f(15, 360);
    glVertex2f(15, 390);
    glVertex2f(30, 330);
    glVertex2f(30, 300);
    glVertex2f(30, 360);
    glVertex2f(30, 390);
    glVertex2f(45, 330);
    glVertex2f(45, 300);
    glVertex2f(45, 360);
    glVertex2f(45, 390);
    
    glEnd();


}

void tower8(){
    //8
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(2.51, 250);
    glVertex2f(-3.77, 373.46);
    glVertex2f(8.80, 407.41);
    glVertex2f(59.10, 403.63);
    glVertex2f(76.70, 417.47);
    glVertex2f(91.79, 427.52);
    glVertex2f(108.14, 416.21);
    glVertex2f(113.17, 402.38);
    glVertex2f(125.74, 397.35);
    glVertex2f(130.77, 381.00);
    glVertex2f(129.51, 250);
    glEnd();
    
    
    //window
    glColor3f(1, 1, 0.7);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(15, 370);
    glVertex2f(15, 340);
    glVertex2f(15, 310);
    glVertex2f(15, 280);
    
    glVertex2f(30, 370);
    glVertex2f(30, 340);
    glVertex2f(30, 310);
    glVertex2f(30, 280);
    
    glVertex2f(45, 370);
    glVertex2f(45, 340);
    glVertex2f(45, 310);
    glVertex2f(45, 280);
    
    glVertex2f(60, 370);
    glVertex2f(60, 340);
    glVertex2f(60, 310);
    glVertex2f(60, 280);
    glEnd();


}

void tower9(){
    //9
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-1.26, 250);
    glVertex2f(-8.80, 435.07);
    glVertex2f(7.54, 446.39);
    glVertex2f(7.54, 460.22);
    glVertex2f(13.83, 469.02);
    glVertex2f(21.38, 572.13);
    glVertex2f(33.95, 466.50);
    glVertex2f(44.01, 455.19);
    glVertex2f(42.75, 442.61);
    glVertex2f(59.10, 428.78);
    glVertex2f(59.10, 250);
    glEnd();

    //window
    glColor3f(1, 1, 0.7);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(15, 330);
    glVertex2f(15, 300);
    glVertex2f(15, 360);
    glVertex2f(15, 390);
    glVertex2f(15, 420);
    glVertex2f(30, 330);
    glVertex2f(30, 300);
    glVertex2f(30, 360);
    glVertex2f(30, 390);
    glVertex2f(30, 420);
    glVertex2f(45, 330);
    glVertex2f(45, 300);
    glVertex2f(45, 360);
    glVertex2f(45, 390);
    glVertex2f(45, 420);
    
    glEnd();

}

void tower10(){
    //10
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(2.51, 250);
    glVertex2f(-2.51, 389.80);
    glVertex2f(23.89, 479.08);
    glVertex2f(60.36, 389.80);
    glVertex2f(62.87, 250);
    glEnd();
    
    //window
    glColor3f(1, 1, 0.7);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(15, 330);
    glVertex2f(15, 300);
    glVertex2f(15, 360);
    glVertex2f(15, 390);
    glVertex2f(30, 330);
    glVertex2f(30, 300);
    glVertex2f(30, 360);
    glVertex2f(30, 390);
    glVertex2f(45, 330);
    glVertex2f(45, 300);
    glVertex2f(45, 360);
    glVertex2f(45, 390);
    
    glEnd();


}

void tower11(){
    //11
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(1.26, 250);
    glVertex2f(2.51, 623.68);
    glVertex2f(15.09, 622.43);
    glVertex2f(32.69, 549.50);
    glVertex2f(90.53, 533.15);
    glVertex2f(82.99, 516.80);
    glVertex2f(90.53, 499.20);
    glVertex2f(98.08, 490.40);
    glVertex2f(119.46, 489.14);
    glVertex2f(85.50, 479.08);
    glVertex2f(67.90, 467.76);
    glVertex2f(60.90, 460.76);
    glVertex2f(52.81, 452.67);
    glVertex2f(59.10, 423.75);
    glVertex2f(111.91, 250);
    glEnd();
    
    
  
    glColor3f(1, 1, 0.7);
    MyCircle2f(33, 500, 25);
    glColor3f(0, 0, 0);
    MyCircle2f(33, 500, 20);
    glLineWidth(5);
    glColor3f(1, 1, 0.7);
    glBegin(GL_LINES);
    glVertex2f(25, 480);
    glVertex2f(45, 525);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(45, 525);
    glVertex2f(45, 485);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(33, 500);
    glVertex2f(45, 500);
    glEnd();
    
  

}

void tower12(){
    //12
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.00, 250);
    glVertex2f(5.03, 480.34);
    glVertex2f(45.27, 489.14);
    glVertex2f(81.73, 448.90);
    glVertex2f(85.50, 250);
    glEnd();
    
    //window
    glColor3f(1, 1, 0.7);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(15, 330);
    glVertex2f(15, 300);
    glVertex2f(15, 360);
    glVertex2f(15, 390);
    glVertex2f(15, 420);
    glVertex2f(30, 330);
    glVertex2f(30, 300);
    glVertex2f(30, 360);
    glVertex2f(30, 390);
    glVertex2f(30, 420);
    glVertex2f(45, 330);
    glVertex2f(45, 300);
    glVertex2f(45, 360);
    glVertex2f(45, 390);
    glVertex2f(45, 420);
    
    glEnd();



}

void tower13(){
    //13
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(1.26, 250);
    glVertex2f(-2.51, 399.86);
    glVertex2f(12.57, 408.66);
    glVertex2f(10.06, 438.84);
    glVertex2f(27.66, 450.16);
    glVertex2f(33.95, 550.75);
    glVertex2f(47.78, 443.87);
    glVertex2f(65.39, 437.58);
    glVertex2f(64.13, 399.86);
    glVertex2f(76.70, 381.00);
    glVertex2f(79.22, 250);
    glEnd();
    
    //window
    glColor3f(1, 1, 0.7);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(15, 330);
    glVertex2f(15, 300);
    glVertex2f(15, 360);
    glVertex2f(15, 390);
    glVertex2f(30, 330);
    glVertex2f(30, 300);
    glVertex2f(30, 360);
    glVertex2f(30, 390);
    glVertex2f(45, 330);
    glVertex2f(45, 300);
    glVertex2f(45, 360);
    glVertex2f(45, 390);
    
    glEnd();


}

float towerOntheMove1 = 0.0, towerOntheMove2 = 1280;

void towerMove(){
    

    glPushMatrix();
    glTranslatef(0, -200, 0);
    glTranslatef(towerOntheMove1, 0, 0);
    if(towerOntheMove1 <= -1260){
        towerOntheMove1 = 1280;
    }
    tower1(); //1
    //cout << "towerOntheMove1 = " << towerOntheMove1 << endl;
    glTranslatef(80, 0, 0);
    tower2();
    
    glTranslatef(110, 0, 0);
    tower3();
    
    glTranslatef(80, 0, 0);
    tower4();
    
    glTranslatef(100, 0, 0);
    tower5();
    
    glTranslatef(100, 0, 0);
    tower6();
    
    glTranslatef(80, 0, 0);
    tower7();
    
    glTranslatef(80, 0, 0);
    tower8();
    
    glTranslatef(160, 0, 0);
    tower9();
    
    glTranslatef(80, 0, 0);
    tower10();
    
    glTranslatef(80, 0, 0);
    tower11();
    
    glTranslatef(130, 0, 0);
    tower12();
    
    glTranslatef(100, 0, 0);
    tower13();
   

    glPopMatrix();
    


    
}


void towerMove2(){
    
    glPushMatrix();
    glTranslatef(0, -200, 0); //-100
    glTranslatef(towerOntheMove2, 0, 0);
    if(towerOntheMove2 <= -1260){
        towerOntheMove2 = 1280;
    }
    tower1();
    //cout << "towerOntheMove2 = " << towerOntheMove2 << endl;
    glTranslatef(80, 0, 0);
    tower2();
    
    glTranslatef(110, 0, 0);
    tower3();
    
    glTranslatef(80, 0, 0);
    tower4();
    
    glTranslatef(100, 0, 0);
    tower5();
    
    glTranslatef(100, 0, 0);
    tower6();
    
    glTranslatef(80, 0, 0);
    tower7();
    
    glTranslatef(80, 0, 0);
    tower8();
    
    glTranslatef(160, 0, 0);
    tower9();
    
    glTranslatef(80, 0, 0);
    tower10();
    
    glTranslatef(80, 0, 0);
    tower11();
    
    glTranslatef(130, 0, 0);
    tower12();
    
    glTranslatef(100, 0, 0);
    tower13();
    
    glPopMatrix();
    
 
    
    

    
    
    
}

void background(){
    
  
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.4, 0.8);
    glVertex2f(0, 720);
    
    glColor3f(0.6, 0.4, 0.7);
    glVertex2f(0, 50);
  
    glVertex2f(1270, 50);
    glColor3f(0.6, 0.4, 0.7);
    
    glColor3f(0.2, 0.4, 0.8);
    glVertex2f(1270, 720);
    
    glEnd();
    
    
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(1270, 0);
    glVertex2f(1270, 50);
    glVertex2f(0, 50);
    glEnd();
    

    
    
}

void ironLogo(){
    
    
    //I
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(215, 450);
    glVertex2f(255, 450);
    glVertex2f(255, 595);
    glVertex2f(215, 595);
    glEnd();
    
    glLineWidth(10);
    glColor3f(1, 1, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(255, 450);
    glVertex2f(255, 595);
    glVertex2f(215, 595);
    glEnd();
    
    
    //R
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(277.89, 600);
    glVertex2f(280.41, 445.13);
    glVertex2f(324.42, 443.87);
    glVertex2f(320, 504.23);
    glVertex2f(340 , 504.23);
    glVertex2f(343.50, 443.64);
    glVertex2f(384.77, 447.64);
    glVertex2f(382.26, 508.00);
    glVertex2f(365.91, 520.57);
    glVertex2f(381.00, 530.63);
    glVertex2f(384.77, 590.99);
    glVertex2f(348.31, 600);
    glEnd();
    
    glColor3f(1, 1, 0);
    glBegin(GL_LINES);
    glVertex2f(325, 579);
    glVertex2f(325, 534);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(324.42, 443.87);
    glVertex2f(320, 504.23);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    glVertex2f(277.89, 600);
    glVertex2f(348.31, 600);
    glVertex2f(384.77, 590.99);
    glVertex2f(381.00, 530.63);
    glVertex2f(365.91, 520.57);
    glVertex2f(382.26, 508.00);
    glVertex2f(384.77, 447.64);
    glEnd();
    
    
    //O
    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(428.78, 442.61);
    glVertex2f(399.86, 452.67);
    glVertex2f(397.35, 593.50);
    glVertex2f(426.27, 598.53);
    
    
    glVertex2f(426.27, 598.53);
    glVertex2f(474.05, 598.53);
    glVertex2f(462.25, 574.16);
    glVertex2f(426.27, 573.39);
    
    
    glVertex2f(423.75, 466.50);
    glVertex2f(462.73, 466.50);
    glVertex2f(461.48, 441.36);
    glVertex2f(428.78, 442.61);
    
    
    glVertex2f(461.05, 598.53);
    glVertex2f(495.43, 588.48);
    glVertex2f(491.65, 451.42);
    glVertex2f(461.48, 441.36);
    
    
    glEnd();
    
    
    glColor3f(1, 1, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(426.27, 573.39);
    glVertex2f(423.75, 466.50);
    glVertex2f(462.73, 466.50);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    glVertex2f(397.35, 593.50);
    glVertex2f(426.27, 598.53);
    glVertex2f(474.05, 598.53);
    glVertex2f(495.43, 588.48);
    glVertex2f(491.65, 451.42);
    glEnd();
    
    
    //N
    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(559.55, 441.36);
    glVertex2f(509.26, 446.39);
    glVertex2f(504.23, 599.79);
    glVertex2f(552.01, 601.05);
    
    glVertex2f(552.01, 601.05);
    glVertex2f(575.36, 541.95);
    glVertex2f(570.87, 441.36);
    glVertex2f(555.78, 480.34);
    
    glVertex2f(570.87, 441.36);
    glVertex2f(568.36, 601.05);
    glVertex2f(609.85, 601.05);
    glVertex2f(614.88, 443.87);
    glEnd();

    
    glColor3f(1, 1, 0);
    glBegin(GL_LINES);
    glVertex2f(555.78, 480.34);
    glVertex2f(559.55, 441.36);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    glVertex2f(504.23, 599.79);
    glVertex2f(552.01, 601.05);
    glVertex2f(575.36, 541.95);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    glVertex2f(568.36, 601.05);
    glVertex2f(609.85, 601.05);
    glVertex2f(614.88, 443.87);
    glEnd();

    

    
    //M
    glColor3f(1, 0 , 0);
    glBegin(GL_QUADS);
    
    glVertex2f(706.67, 446.39);
    glVertex2f(656.38, 448.90);
    glVertex2f(658.89, 603.56);
    glVertex2f(700.39, 602.31);
    
    glVertex2f(700.39, 602.31);
    glVertex2f(724.28, 559.55);
    glVertex2f(725.53, 491.65);
    glVertex2f(700.39, 539.44);
    
    
    glVertex2f(724.28, 559.55);
    glVertex2f(743.14, 598.53);
    glVertex2f(743.14, 533.15);
    glVertex2f(725.53, 491.65);
    
    
    glVertex2f(743.14, 598.53);
    glVertex2f(784.63, 601.05);
    glVertex2f(785.89, 445.13);
    glVertex2f(740.62, 446.39);
    glVertex2f(743.14, 533.15);
    
    glEnd();
    
    glColor3f(1, 1, 0);
    glBegin(GL_LINES);
    glVertex2f(700.39, 539.44);
    glVertex2f(706.67, 446.39);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(725.53, 491.65);
    glVertex2f(743.14, 533.15);
    glEnd();
    
    glColor3f(1, 1, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(658.89, 603.56);
    glVertex2f(700.39, 602.31);
    glVertex2f(724.28, 559.55);
    glEnd();
    
    glColor3f(1, 1, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(743.14, 598.53);
    glVertex2f(784.63, 601.05);
    glVertex2f(785.89, 445.13);
    glEnd();
    
    


    //A
    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(839.96, 450.16);
    glVertex2f(802.24, 450.16);
    glVertex2f(798.47, 590.99);
    glVertex2f(833.67, 601.05);
    
    glVertex2f(833.67, 601.05);
    glVertex2f(865.11, 601.05);
    glVertex2f(866.37, 578.42);
    glVertex2f(832.42, 577.16);
    
    glVertex2f(832.42, 533.15);
    glVertex2f(862.59, 533.15);
    glVertex2f(857.56, 504.23);
    glVertex2f(837.45, 504.23);
    
    glVertex2f(865.11, 601.05);
    glVertex2f(900.32, 589.73);
    glVertex2f(900.32, 448.90);
    glVertex2f(860.08, 447.64);
    
    glEnd();
    
    glColor3f(1, 1, 0);
    glBegin(GL_LINES);
    glVertex2f(839.96, 450.16);
    glVertex2f(837.45, 504.23);
    glEnd();

    
    glBegin(GL_LINE_STRIP);
    glVertex2f(871, 533);
    glVertex2f(832.42, 533.15);
    glVertex2f(832.42, 577.16);
    glEnd();
    
    
    glBegin(GL_LINE_STRIP);
    glVertex2f(833.67, 601.05);
    glVertex2f(865.11, 601.05);
    glVertex2f(900.32, 589.73);
    glVertex2f(900.32, 448.90);
    glEnd();


    
    
    
    
    //N
    glPushMatrix();
    
    glTranslatef(410, 0, 0);
    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(559.55, 441.36);
    glVertex2f(509.26, 446.39);
    glVertex2f(504.23, 599.79);
    glVertex2f(552.01, 601.05);
    
    glVertex2f(552.01, 601.05);
    glVertex2f(575.36, 541.95);
    glVertex2f(570.87, 441.36);
    glVertex2f(555.78, 480.34);
    
    glVertex2f(570.87, 441.36);
    glVertex2f(568.36, 601.05);
    glVertex2f(609.85, 601.05);
    glVertex2f(614.88, 443.87);
    glEnd();
    
    
    glColor3f(1, 1, 0);
    glBegin(GL_LINES);
    glVertex2f(555.78, 480.34);
    glVertex2f(559.55, 441.36);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    glVertex2f(504.23, 599.79);
    glVertex2f(552.01, 601.05);
    glVertex2f(575.36, 541.95);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    glVertex2f(568.36, 601.05);
    glVertex2f(609.85, 601.05);
    glVertex2f(614.88, 443.87);
    glEnd();

    glPopMatrix();

}


void checkScore(){
    
    if(score>=10 && score <= 29){ //Normal
        enemySpeed = 10;
        speedTower = 5;
        speed = 1000;
        
    }else if(score >= 30 && score <= 39){
        enemySpeed = 15;
        speedTower = 10;
        speed = 1500;
    }else if(score >= 40 && score <=49){
        enemySpeed = 20;
        speedTower = 15;
        speed = 1500;
    }else if(score >= 50){ //Hard
        enemySpeed = 30;
        speedTower = 20;
        speed = 1500;
    }
    
    

    
}

void checkBlast(){
    
    if(flagsBlast){
        if(countBlast > 5){
            collisionBast();
            if(countBlast == 20){
                flagsBlast = false;
                countBlast = 0;
            }
            
            
        }
        //cout << "countBlast = " << countBlast << endl;
        countBlast++;
    }
    
}


void manual(){
    
    glTranslatef(600, 5, 0);
    glScalef(0.4, 0.4, 0);
    glColor3f(1, 1, 1);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(1088, 50);
    glVertex2f(1088, 100);
    glVertex2f(1050, 30);
    glVertex2f(1050, 80);
    glVertex2f(1013, 46);
    glVertex2f(1013, 100);
    glEnd();
    
  
    
    
}

bool flagOpenManual = false;

void detialManual(){
    
    glPushMatrix();
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex2f(850, 50);
    glVertex2f(1250, 50);
    glVertex2f(1250, 350);
    glVertex2f(850, 350);
    glEnd();
    glPopMatrix();
    
  
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(857, 342);
    glVertex2f(882, 323);
    glEnd();
    
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(857, 323);
    glVertex2f(882, 342);
    glEnd();

    display_stringToDetail(1000, 330, "Detial", 1);
    display_stringToDetail(870, 280, "Keybroad Function", 2);
    display_stringToDetail(870, 250, "R|r = RED EYES, G|g = GREEN EYES, B|b = BLUE EYES", 3);
    display_stringToDetail(870, 200, "Mouse Function", 2);
    display_stringToDetail(870, 170, "MOUSE RIGHT BUTTON CLICK to Set Easy, Normal, Hard and Exit", 3);
    display_stringToDetail(870, 120, "Special Function", 2);
    display_stringToDetail(870, 90, "KEY UP = Move Up IronMan, KEY DOWN = Move Down IronMan ", 3);
    
    //display_stringToDetail(950, 80, "Thank you very much:) ", 2);
  
    
    
}

void gameOver(){
    
    
    glPushMatrix();
    glTranslatef(140, 35, 0);
    glColor3f(1, 1, 0);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(598.53, 250.23);
    glVertex2f(575.90, 299.27);
    glVertex2f(548.24, 248.97);
    glVertex2f(528.12, 301.78);
    glVertex2f(502.97, 251.49);
    glVertex2f(475.31, 300.52);
    glVertex2f(450.16, 250.23);
    glVertex2f(425.01, 299.27);
    glVertex2f(403.63, 252.74);
    glVertex2f(374.71, 296.75);
    glVertex2f(350.82, 252.74);
    glVertex2f(323.16, 299.27);
    glEnd();
    glPopMatrix();
    
    char buffer [100];
    sprintf (buffer, "YOUR SCORE:  %d", score);
    glColor3f(0.000, 1.000, 0.000);
    display_stringToDetail(500, 300, buffer, 1);
    


}



void resize(int w, int h){
    
     glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    
}


//|****************************** Display ******************************************|
void display(){
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0, Width, 0, Height);
 
    point();
    background();
    towerMove();
    towerMove2();
    if(flagOpenManual == true){
        detialManual();
    }
    //sence
    if(ironStart == 0){
        ironFirstSence();
        ironLogo();
        manual();
       
    }else if(ironStart == 1){
        ironSecondSence();
        healthIronManALL();
        checkScore();
        checkBlast();
        
    }else if(ironStart == 2){
        speedTower = 1;
        gameOver();
        ironFirstSence();
        ironLogo();
        manual();
    }

    towerOntheMove1-=speedTower;
    towerOntheMove2-=speedTower;
    //glFlush();
    glutSwapBuffers();
}


//|****************************** END Display **************************************|


//|******************************* Controller **************************************|


void specialKey(int key, int x, int y){
    
    switch (key) {
        case GLUT_KEY_UP:
            ironUpDown = ironUpDown + (speed/10);
            if(ironUpDown > 500){
                ironUpDown = 500;
            }
            //cout << "ironUp = " << ironUpDown << endl;
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            ironUpDown = ironUpDown - (speed/10);
            if(ironUpDown < -100){
                ironUpDown = -100;
            }
            //cout << "ironDown = " << ironUpDown << endl;
            glutPostRedisplay();
            break;
//        case GLUT_KEY_LEFT:
//            ironLeftRight = ironLeftRight - (speed/10);
//            cout << "LEFT = " << ironLeftRight << endl;
//            if(ironLeftRight < -150){
//                ironLeftRight = -150;
//            }
//            glutPostRedisplay();
//            break;
//        case GLUT_KEY_RIGHT:
//            ironLeftRight = ironLeftRight + (speed/10);
//            cout << "RIGHT = " << ironLeftRight << endl;
//            if(ironLeftRight > 950){
//                ironLeftRight = 950;
//            }
//        glutPostRedisplay();
            break;
       
        default:
            break;
    }
    
}

void keyboard(unsigned char key, int x, int y ){
    switch (key) {
        case 'r':
            if( greenColorEyeIron >= 1 && blueColorEyeIron >= 1){
                redColorEyesIron = 1.0;
                greenColorEyeIron = 0.0;
                blueColorEyeIron = 0.0;
            }else{
                redColorEyesIron  = 1.0;
                greenColorEyeIron += 0.05;
                blueColorEyeIron += 0.05;
            }
            glutPostRedisplay();
            break;
        case 'R':
            if( greenColorEyeIron >= 1 && blueColorEyeIron >= 1){
                redColorEyesIron = 1.0;
                greenColorEyeIron = 0.0;
                blueColorEyeIron = 0.0;
            }else{
                redColorEyesIron  = 1.0;
                greenColorEyeIron += 0.05;
                blueColorEyeIron += 0.05;
            }
            glutPostRedisplay();
            break;
        case 'g':
            if(redColorEyesIron >= 1 && blueColorEyeIron >=1){
                redColorEyesIron = 0.0;
                greenColorEyeIron = 1.0;
                blueColorEyeIron = 0.0;
            }else{
                redColorEyesIron += 0.05;
                greenColorEyeIron = 1.0;
                blueColorEyeIron += 0.05;
            }
            glutPostRedisplay();
            break;
        case 'G':
            if(redColorEyesIron >= 1 && blueColorEyeIron >=1){
                redColorEyesIron = 0.0;
                greenColorEyeIron = 1.0;
                blueColorEyeIron = 0.0;
            }else{
                redColorEyesIron += 0.05;
                greenColorEyeIron = 1.0;
                blueColorEyeIron += 0.05;
            }
            glutPostRedisplay();
            break;
        case 'b':
            if(redColorEyesIron >= 1 && greenColorEyeIron >= 1){
                redColorEyesIron = 0.0;
                greenColorEyeIron = 0.0;
                blueColorEyeIron = 1.0;
            }else{
                redColorEyesIron += 0.05;
                greenColorEyeIron += 0.05;
                blueColorEyeIron = 1.0;
            }
            glutPostRedisplay();
            break;
        case 'B':
            if(redColorEyesIron >= 1 && greenColorEyeIron >= 1){
                redColorEyesIron = 0.0;
                greenColorEyeIron = 0.0;
                blueColorEyeIron = 1.0;
            }else{
                redColorEyesIron += 0.05;
                greenColorEyeIron += 0.05;
                blueColorEyeIron = 1.0;
            }
            glutPostRedisplay();
            break;
        case ' ':
            score = 0;
            ironHealth = 5;
            speedTower = 1;
            enemySpeed = 5;
            ironStart = 1;
            speed = 500;
            glutAttachMenu(GLUT_RIGHT_BUTTON);
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

int _count = 0;

void mouse(int button, int state, int x, int y){

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        //cout << "mouse click at x = " << x << "  y = " << y << endl;
        if( (x >= 1004 && x <= 1035)  && (y >= 676 && y <= 705 )){
            flagOpenManual = true;
            _count++;
        }
        
        if(((x >= 857 && x <= 882) && (y >= 378 && y <= 396)) || _count == 2){
            flagOpenManual = false;
            _count = 0;
        }
       
    }
    
}



void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/speed, timer, 0);
}

void mainMenu(int value){
    
    switch (value) {
        case 1: //Easy
            enemySpeed = 5;
            speedTower = 1;
            speed = 500;
            score = 1;
            glutPostRedisplay();
            break;
        case 2: //Normal
            enemySpeed = 10;
            speedTower = 5;
            speed = 1000;
            score = 10;
            glutPostRedisplay();
            break;
        case 3: //Hard
            enemySpeed = 30;
            speedTower = 20;
            speed = 1500;
            score = 50;
            glutPostRedisplay();
           
            break;
        case 999:
            exit(0);
            break;
        default:
            break;
        
    }
}


int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(Width, Height);
    glutInitWindowPosition(100,120);
    glutCreateWindow("Iron Ananchai");
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyboard );
    glutSpecialFunc(specialKey);
    glutMouseFunc(mouse);
    glutCreateMenu(mainMenu);
    glutAddMenuEntry("Easy", 1);
    glutAddMenuEntry("Normal", 2);
    glutAddMenuEntry("Hard", 3);
    glutAddMenuEntry("Exit", 999);
    glutTimerFunc(1000,timer,0);
    glutMainLoop();
    return 0;
}
