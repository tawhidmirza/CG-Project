#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include<math.h>
#define PI 3.1416

using namespace std;

float _move = 0.0f; float Shipspeed00=.4;//!move_cargoShip_01()
float _move2 = 0.0f; float Shipspeed01=.4;   //!move_cargoShip_02()
float _moveBP = 0.0f;    float Planespeed=.4;//!moveBannerPlane()
float moveBat = 0.0f;   //!moveBannerPlane()
float _rotateLight = 0.0f; float lightSpeed=.4;//!rotateWT_light()  !rotateLH_light()
float move_truck00 =0.0f;float Truckspeed00= .4f; //!update_truck00()
float move_truck01 =0.0f; float Truckspeed01 = .4;//!update_truck00()

GLfloat position2 =0.0f; GLfloat speed2 =0.01f;
GLfloat position =0.0f; GLfloat speed =0.01f;


void display(int val);
void displayHotel_Night(int val);



void road() //!akm_road
{

    //ROAD
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2d(-50.0,-30.0);
        glVertex2d(50.0,-30.0);
        glVertex2d(50.0,-50.0);
        glVertex2d(-50.0,-50.0);
    glEnd();
    //Up-Line
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(-50.0,-32.0);
        glVertex2d(50.0,-32.0);
    glEnd();

    //Middle-Line-1
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(-50.0,-40.0);
        glVertex2d(-40.0,-40.0);
    glEnd();

    //Middle-Line-2
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(-38.0,-40.0);
        glVertex2d(-32.0,-40.0);
    glEnd();

    //Middle-Line-3
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(-30.0,-40.0);
        glVertex2d(-20.0,-40.0);
    glEnd();

    //Middle-Line-4
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(-18.0,-40.0);
        glVertex2d(-12.0,-40.0);
    glEnd();

    //Middle-Line-5
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(-10.0,-40.0);
        glVertex2d(-0.0,-40.0);
    glEnd();

    //Middle-Line-6
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(2.0,-40.0);
        glVertex2d(8.0,-40.0);
    glEnd();

    //Middle-Line-7
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(10.0,-40.0);
        glVertex2d(20.0,-40.0);
    glEnd();

    //Middle-Line-8
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(22.0,-40.0);
        glVertex2d(28.0,-40.0);
    glEnd();

    //Middle-Line-9
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(30.0,-40.0);
        glVertex2d(40.0,-40.0);
    glEnd();

    //Middle-Line-10
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(42.0,-40.0);
        glVertex2d(50.0,-40.0);
    glEnd();

    //Down-Line
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(-50.0,-48.0);
        glVertex2d(50.0,-48.0);
    glEnd();
    //Road End
}

void sand()
{
    glBegin(GL_POLYGON);

    glVertex2f(-50.0f, -30.0f);
    glVertex2f(50.0f, -30.0f);
    glVertex2f(50.0f, -10.0f);
    glVertex2f(-50.0f, -10.0f);
    glEnd();
}


void ocean()
{
    glBegin(GL_POLYGON);
    glVertex2f(-50.0f, -10.0f);
    glVertex2f(50.0f, -10.0f);
    glVertex2f(50.0f, 20.0f);
    glVertex2f(-50.0f, 20.0f);
    glEnd();

}

void tide()
{
    glPushMatrix();
    glTranslatef(_move, 0, 1);
    glBegin(GL_POLYGON);
    glColor3ub(250, 250, 250);
    glVertex2f(-30.0f, 0.0f);
    glVertex2f(10.0f, 0.0f);
    glVertex2f(10.0f, -.5f);
    glVertex2f(-30.0f, -.5f);
    glEnd();

    glPopMatrix();
}

void tideNight()
{
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(-30.0f, 0.0f);
    glVertex2f(10.0f, 0.0f);
    glVertex2f(10.0f, -0.5f);
    glVertex2f(-30.0f, -0.5f);
    glEnd();

    glPopMatrix();
}



void sky()
{
    glBegin(GL_POLYGON);
    glVertex2f(-50.0f, 20.0f);
    glVertex2f(50.0f, 20.0f);
    glVertex2f(50.0f, 50.0f);
    glVertex2f(-50.0f, 50.0f);
    glEnd();
}

void sun()
{
    glPushMatrix();
    glTranslatef(_move, 0, 0);
    glColor3ub(255,208,0);
    glScalef(0.5, 0.5, 0);
    glTranslatef(20, 45, 0);

            glBegin(GL_POLYGON);
            for(int i=0;i<200;i++)
            {
                float pi=3.1416;
                float A=(i*2*pi)/200;
                float r=10;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y+20);
            }
            glEnd();

    glPopMatrix();

}


void land02()
{
    glBegin(GL_POLYGON);
    glVertex2f(-50.0f, -20.0f);
    glVertex2f(50.0f, -20.0f);
    glVertex2f(50.0f, 0);
    glVertex2f(-50.0f, 0);
    glEnd();
}

void ocean02()
{
    glBegin(GL_QUADS);
    glVertex2d(-50.0,-20.0);
    glVertex2d(50.0,-20.0);
    glVertex2d(50.0,-50.0);
    glVertex2d(-50.0,-50.0);
    glEnd();
}

void sky02()
{
    glBegin(GL_POLYGON);
    glVertex2f(-50.0f, 10.0f);
    glVertex2f(50.0f, 10.0f);
    glVertex2f(50.0f, 50.0f);
    glVertex2f(-50.0f, 50.0f);
    glEnd();
}

void cloud()
{

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=3;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+40,y+40);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=4;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+43,y+40);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=3;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+44,y+44);
        }
        glEnd();

}
void cloud2()
{
        int a=-43, b=40;
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=4;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+a,y+b);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=4;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+a,y+(b+4));
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=4;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+(a+4),y+b);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=4;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+(a-4),y+b);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=4;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+a,y+(b-4));
        }
        glEnd();

}

void cloud3()
{
        int a=0, b=40;
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=4;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+a,y+b);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=4;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+a,y+(b+4));
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=4;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+(a+4),y+b);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=4;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+(a-4),y+b);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
        glColor3ub(250, 250, 250);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=4;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+a,y+(b-4));
        }
        glEnd();

}

void star()
{
    glBegin(GL_POLYGON);
    glColor3ub(255, 255,255);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(0.0f, 1.0f);
    glEnd();


}

void circle(float radiusX, float radiusY)
{
    int i;
    float angle=0.0;
    glBegin(GL_POLYGON);
        for(i=0; i<100; i++){
            angle=2*PI*i/100;
            glVertex2f(radiusX*cos(angle),radiusY*sin(angle));
        }
        glEnd();
}



void build_windows()
{
        //!!!############________windows__________##########################
    //!##############column-00
    glPushMatrix();
    glTranslatef(-.5, .5, 0);
    glBegin(GL_POLYGON); //!window
    glColor3ub (0,177,177);
    glVertex2f(0, 0);
    glVertex2f(1, 0);
    glVertex2f(1, .5);
    glVertex2f(0, .5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.5, 1.5, 0);
    glBegin(GL_POLYGON); //!window
    glColor3ub (0,177,177);
    glVertex2f(0, 0);
    glVertex2f(1, 0);
    glVertex2f(1, .5);
    glVertex2f(0, .5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.5, 2.5, 0);
    glBegin(GL_POLYGON); //!window
    glColor3ub (0,177,177);
    glVertex2f(0, 0);
    glVertex2f(1, 0);
    glVertex2f(1, .5);
    glVertex2f(0, .5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.5, 3.5, 0);
    glBegin(GL_POLYGON); //!window
    glColor3ub (0,177,177);
    glVertex2f(0, 0);
    glVertex2f(1, 0);
    glVertex2f(1, .5);
    glVertex2f(0, .5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.5, 4.5, 0);
    glBegin(GL_POLYGON); //!window
    glColor3ub (0,177,177);
    glVertex2f(0, 0);
    glVertex2f(1, 0);
    glVertex2f(1, .5);
    glVertex2f(0, .5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.5, 5.5, 0);
    glBegin(GL_POLYGON); //!window
    glColor3ub (0,177,177);
    glVertex2f(0, 0);
    glVertex2f(1, 0);
    glVertex2f(1, .5);
    glVertex2f(0, .5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.5, 6.5, 0);
    glBegin(GL_POLYGON); //!window
    glColor3ub (0,177,177);
    glVertex2f(0, 0);
    glVertex2f(1, 0);
    glVertex2f(1, .5);
    glVertex2f(0, .5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.5, 7.5, 0);
    glBegin(GL_POLYGON); //!window
    glColor3ub (0,177,177);
    glVertex2f(0, 0);
    glVertex2f(1, 0);
    glVertex2f(1, .5);
    glVertex2f(0, .5);
    glEnd();
    glPopMatrix();

}

void building()
{
    glPushMatrix();
    glTranslatef(0,-10,0);
    glScalef(2,3.5, 0);

    glBegin(GL_POLYGON);    //!body-01
    glColor3ub (77,77,255);
    glVertex2f(0, 0);
    glVertex2f(6, 0);
    glVertex2f(6, 8.5);
    glVertex2f(0, 8.5);
    glEnd();

    glBegin(GL_POLYGON); //!body-01-upper-layer
    glColor3ub (200,200,200);
    glVertex2f(-1, 8.5);
    glVertex2f(7, 8.5);
    glVertex2f(7, 9);
    glVertex2f(-1, 9);
    glEnd();

    glBegin(GL_POLYGON);    //!body-01-upper-layer-02
    glColor3ub (250,250,250);
    glVertex2f(-0, 9);
    glVertex2f(6, 9);
    glVertex2f(6, 9.5);
    glVertex2f(0, 9.5);
    glEnd();

    glBegin(GL_POLYGON);    //!body-01-upper-layer-03
    glColor3ub (0,0,0);
    glVertex2f(.5, 9);
    glVertex2f(5.5, 9);
    glVertex2f(4, 10);
    glVertex2f(2, 10);
    glEnd();



    glPushMatrix();
    glTranslatef(-7, 0, 0);
    glBegin(GL_POLYGON);    //!body-left
    glColor3ub (77,77,255);
    glVertex2f(0, 0);
    glVertex2f(6, 0);
    glVertex2f(6, 7);
    glVertex2f(0, 7);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-14, 0, 0);
    glBegin(GL_POLYGON);        //!body-01-bar00-left
    glColor3ub (255,255,255);
    glVertex2f(6, 0);
    glVertex2f(7, 0);
    glVertex2f(7, 7);
    glVertex2f(6, 7);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-7, -2, 0);
    glBegin(GL_POLYGON);    //!body-02-upper-layer
    glColor3ub (200,200,200);
    glVertex2f(-1, 8.5);
    glVertex2f(7, 8.5);
    glVertex2f(7, 9);
    glVertex2f(-1, 9);
    glEnd();
    glPopMatrix();





    glBegin(GL_POLYGON);        //!body-01-bar01
    glColor3ub (255,255,255);
    glVertex2f(0, 0);
    glVertex2f(-1, 0);
    glVertex2f(-1, 8.5);
    glVertex2f(0, 8.5);
    glEnd();


    glPushMatrix();
    glTranslatef(7, 0, 0);
    glBegin(GL_POLYGON);    //!body-right
    glColor3ub (77,77,255);
    glVertex2f(0, 0);
    glVertex2f(6, 0);
    glVertex2f(6, 7);
    glVertex2f(0, 7);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7, 0, 0);
    glBegin(GL_POLYGON);        //!body-01-bar00-right
    glColor3ub (255,255,255);
    glVertex2f(6, 0);
    glVertex2f(7, 0);
    glVertex2f(7, 7);
    glVertex2f(6, 7);
    glEnd();
    glPopMatrix();








    glBegin(GL_POLYGON);    //!body-01-bar00
    glColor3ub (255,255,255);
    glVertex2f(6, 0);
    glVertex2f(7, 0);
    glVertex2f(7, 8.5);
    glVertex2f(6, 8.5);
    glEnd();




    //!#############################windows
    build_windows();


    //!####################column-01
    glPushMatrix();
    glTranslatef(1.3, 0, 0);
    build_windows();
    glPopMatrix();

    //!####################column-02
    glPushMatrix();
    glTranslatef(6, 0, 0);
    build_windows();
    glPopMatrix();

    //!####################column-02
    glPushMatrix();
    glTranslatef(4.5, 0, 0);
    build_windows();
    glPopMatrix();


    //!####################column-03
    glPushMatrix();
    glTranslatef(9, 0, 0);
    build_windows();
    glPopMatrix();

    //!####################column-03
    glPushMatrix();
    glTranslatef(11, 0, 0);
    build_windows();
    glPopMatrix();

    //!####################column-04
    glPushMatrix();
    glTranslatef(-3, 0, 0);
    build_windows();
    glPopMatrix();

    //!####################column-05
    glPushMatrix();
    glTranslatef(-5, 0, 0);
    build_windows();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7.5, -2, 0);
    glBegin(GL_POLYGON); //!body-02-upper-layer-02
    glColor3ub (250,250,250);
    glVertex2f(-0, 9);
    glVertex2f(6, 9);
    glVertex2f(6, 9.5);
    glVertex2f(0, 9.5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-7.5, -2, 0);
    glBegin(GL_POLYGON); //!body-02-upper-layer-02
    glColor3ub (250,250,250);
    glVertex2f(-0, 9);
    glVertex2f(6, 9);
    glVertex2f(6, 9.5);
    glVertex2f(0, 9.5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-7.5, -1.5, 0);
    glBegin(GL_POLYGON); //!body-02-upper-layer-03
    glColor3ub (0,0,0);
    glVertex2f(.5, 9);
    glVertex2f(5.5, 9);
    glVertex2f(4, 10);
    glVertex2f(2, 10);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7, -2, 0);
    glBegin(GL_POLYGON); //!body-03-upper-layer
    glColor3ub (200,200,200);
    glVertex2f(-1, 8.5);
    glVertex2f(7, 8.5);
    glVertex2f(7, 9);
    glVertex2f(-1, 9);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(7.5, -2, 0);
    glBegin(GL_POLYGON); //!body-03-upper-layer-02
    glColor3ub (250,250,250);
    glVertex2f(-0, 9);
    glVertex2f(6, 9);
    glVertex2f(6, 9.5);
    glVertex2f(0, 9.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7.5, -1.5, 0);
    glBegin(GL_POLYGON); //!body-03-upper-layer-03
    glColor3ub (0,0,0);
    glVertex2f(.5, 9);
    glVertex2f(5.5, 9);
    glVertex2f(4, 10);
    glVertex2f(2, 10);
    glEnd();
    glPopMatrix();

    glPopMatrix();

}



void batman()   //!###########################akmBatman()
{
/*
glBegin(GL_POLYGON);
                glColor3ub(226, 223, 210);
glVertex2f(-9.0f, -9.0f);
glVertex2f(4.0f, -9.0f);
glVertex2f(4.0f, 7.0f);
glVertex2f(-9.0f, 7.0f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(0, 0, 0); // Red
glVertex2f(-9.0f, 7.0f);
glVertex2f(4.0f, 7.0f);
glVertex2f(4.0f, 8.0f);
glVertex2f(-9.0f, 8.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0, 0, 0); // Red
glVertex2f(-9.0f, -10.0f);
glVertex2f(4.0f, -10.0f);
glVertex2f(4.0f, -9.0f);
glVertex2f(-9.0f, -9.0f);
glEnd();

glBegin(GL_POLYGON);
                glColor3ub(226, 223, 210);
glVertex2f(4.0f, -8.0f);
glVertex2f(6.0f, -8.0f);
glVertex2f(6.0f, 6.0f);
glVertex2f(4.0f, 6.0f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(0, 0, 0); // Red
glVertex2f(4.0f, 6.0f);
glVertex2f(6.0f, 6.0f);
glVertex2f(6.0f, 7.0f);
glVertex2f(4.0f, 7.0f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(0, 0, 0); // Red
glVertex2f(4.0f, -9.0f);
glVertex2f(6.0f, -9.0f);
glVertex2f(6.0f, -8.0f);
glVertex2f(4.0f, -8.0f);
glEnd();

glBegin(GL_POLYGON);
                glColor3ub(226, 223, 210);
glVertex2f(6.0f, -7.0f);
glVertex2f(8.0f, -7.0f);
glVertex2f(8.0f, 5.0f);
glVertex2f(6.0f, 5.0f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(0, 0, 0); // Red
glVertex2f(6.0f, 5.0f);
glVertex2f(8.0f, 5.0f);
glVertex2f(8.0f, 6.0f);
glVertex2f(6.0f, 6.0f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(0, 0, 0); // Red
glVertex2f(6.0f, -8.0f);
glVertex2f(8.0f, -8.0f);
glVertex2f(8.0f, -7.0f);
glVertex2f(6.0f, -7.0f);
glEnd();

glBegin(GL_POLYGON);
                glColor3ub(226, 223, 210);
glVertex2f(8.0f, -6.0f);
glVertex2f(10.0f, -6.0f);
glVertex2f(10.0f, 4.0f);
glVertex2f(8.0f, 4.0f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(0, 0, 0); // Red
glVertex2f(8.0f, 4.0f);
glVertex2f(10.0f, 4.0f);
glVertex2f(10.0f, 5.0f);
glVertex2f(8.0f, 5.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0, 0, 0); // Red
glVertex2f(8.0f, -7.0f);
glVertex2f(10.0f, -7.0f);
glVertex2f(10.0f, -6.0f);
glVertex2f(8.0f, -6.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0, 0, 0); // Red
glVertex2f(10.0f, -6.0f);
glVertex2f(11.0f, -6.0f);
glVertex2f(11.0f, 4.0f);
glVertex2f(10.0f, 4.0f);
glEnd();
/////////----------------------------Right border

glBegin(GL_POLYGON);
                glColor3ub(226, 223, 210);
glVertex2f(-9.0f, -8.0f);
glVertex2f(-11.0f, -8.0f);
glVertex2f(-11.0f, 6.0f);
glVertex2f(-9.0f, 6.0f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(0, 0, 0); // Red
glVertex2f(-9.0f, -9.0f);
glVertex2f(-11.0f, -9.0f);
glVertex2f(-11.0f, -8.0f);
glVertex2f(-9.0f, -8.0f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(0, 0, 0); // Red
glVertex2f(-9.0f, 6.0f);
glVertex2f(-11.0f, 6.0f);
glVertex2f(-11.0f, 7.0f);
glVertex2f(-9.0f, 7.0f);
glEnd();


glBegin(GL_POLYGON);
                glColor3ub(226, 223, 210);
glVertex2f(-11.0f, -7.0f);
glVertex2f(-13.0f, -7.0f);
glVertex2f(-13.0f, 5.0f);
glVertex2f(-11.0f, 5.0f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(0, 0, 0); // Red
glVertex2f(-11.0f, -8.0f);
glVertex2f(-13.0f, -8.0f);
glVertex2f(-13.0f, -7.0f);
glVertex2f(-11.0f, -7.0f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(0, 0, 0); // Red
glVertex2f(-11.0f, 5.0f);
glVertex2f(-13.0f, 5.0f);
glVertex2f(-13.0f, 6.0f);
glVertex2f(-11.0f, 6.0f);
glEnd();


glBegin(GL_POLYGON);
                glColor3ub(226, 223, 210);
glVertex2f(-13.0f, -6.0f);
glVertex2f(-14.5f, -6.0f);
glVertex2f(-14.5f, 4.0f);
glVertex2f(-13.0f, 4.0f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(0, 0, 0); // Red
glVertex2f(-13.0f, -7.0f);
glVertex2f(-14.5f, -7.0f);
glVertex2f(-14.5f, -6.0f);
glVertex2f(-13.0f, -6.0f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(0, 0, 0); // Red
glVertex2f(-13.0f, 4.0f);
glVertex2f(-14.5f, 4.0f);
glVertex2f(-14.5f, 5.0f);
glVertex2f(-13.0f, 5.0f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(0, 0, 0); // Red
glVertex2f(-14.5f, -6.0f);
glVertex2f(-15.5f, -6.0f);
glVertex2f(-15.5f, 4.0f);
glVertex2f(-14.5f, 4.0f);
glEnd();
*/
////---------------------------------------BORDER ENDS



glBegin(GL_POLYGON);
glColor3ub(0, 0, 0);
glVertex2f(-5.0f, -6.0f);
glVertex2f(-4.0f, -6.0f);
glVertex2f(-4.0f, 5.0f);
glVertex2f(-5.0f, 5.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0, 0, 0);
glVertex2f(-4.0f, -7.0f);
glVertex2f(-1.0f, -7.0f);
glVertex2f(-1.0f, 4.0f);
glVertex2f(-4.0f, 4.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0, 0, 0);
glVertex2f(-1.0f, -6.0f);
glVertex2f(0.0f, -6.0f);
glVertex2f(0.0f, 5.0f);
glVertex2f(-1.0f, 5.0f);
glEnd();

glBegin(GL_POLYGON); // Each set of 4 vertices form a quad
glColor3ub(0, 0, 0); // Red
glVertex2f(-3.0f, -8.0f);
glVertex2f(-2.0f, -8.0f);
glVertex2f(-2.0f, -6.0f);
glVertex2f(-3.0f, -6.0f);
glEnd();

glBegin(GL_POLYGON); // Each set of 4 vertices form a quad
glColor3ub(0, 0, 0); // Red
glVertex2f(0.0f, -3.0f);
glVertex2f(3.0f, -3.0f);
glVertex2f(3.0f, 1.0f);
glVertex2f(0.0f, 1.0f);
glEnd();

glBegin(GL_POLYGON); // Each set of 4 vertices form a quad
glColor3ub(0, 0, 0); // Red
glVertex2f(-8.0f, -3.0f);
glVertex2f(-5.0f, -3.0f);
glVertex2f(-5.0f, 1.0f);
glVertex2f(-8.0f, 1.0f);
glEnd();

glBegin(GL_POLYGON); // Each set of 4 vertices form a quad
glColor3ub(0, 0, 0); // Red
glVertex2f(3.0f, -5.0f);
glVertex2f(4.0f, -5.0f);
glVertex2f(4.0f, 0.0f);
glVertex2f(3.0f, 0.0f);
glEnd();

glBegin(GL_POLYGON); // Each set of 4 vertices form a quad
glColor3ub(0, 0, 0); // Red
glVertex2f(4.0f, -4.0f);
glVertex2f(5.0f, -4.0f);
glVertex2f(5.0f, 1.5f);
glVertex2f(4.0f, 1.5f);
glEnd();

glBegin(GL_POLYGON); // Each set of 4 vertices form a quad
glColor3ub(0, 0, 0); // Red
glVertex2f(5.0f, -7.0f);
glVertex2f(6.0f, -7.0f);
glVertex2f(6.0f, 4.0f);
glVertex2f(5.0f, 4.0f);
glEnd();
glBegin(GL_POLYGON); // Each set of 4 vertices form a quad
glColor3ub(0, 0, 0); // Red
glVertex2f(3.5f, 3.0f);
glVertex2f(5.0f, 3.0f);
glVertex2f(5.0f, 4.0f);
glVertex2f(3.5f, 4.0f);
glEnd();

glBegin(GL_POLYGON); // Each set of 4 vertices form a quad
glColor3ub(0, 0, 0); // Red
glVertex2f(6.0f, -6.0f);
glVertex2f(7.0f, -6.0f);
glVertex2f(7.0f, 3.0f);
glVertex2f(6.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON); // Each set of 4 vertices form a quad
glColor3ub(0, 0, 0); // Red
glVertex2f(7.0f, -5.0f);
glVertex2f(8.0f, -5.0f);
glVertex2f(8.0f, 2.0f);
glVertex2f(7.0f, 2.0f);
glEnd();

glBegin(GL_POLYGON); // Each set of 4 vertices form a quad
glColor3ub(0, 0, 0); // Red
glVertex2f(-8.0f, -5.0f);
glVertex2f(-9.0f, -5.0f);
glVertex2f(-9.0f, 0.0f);
glVertex2f(-8.0f, 0.0f);
glEnd();

glBegin(GL_POLYGON); // Each set of 4 vertices form a quad
glColor3ub(0, 0, 0); // Red
glVertex2f(-10.0f, -4.0f);
glVertex2f(-9.0f, -4.0f);
glVertex2f(-9.0f, 1.5f);
glVertex2f(-10.0f, 1.5f);
glEnd();

glBegin(GL_POLYGON); // Each set of 4 vertices form a quad
glColor3ub(0, 0, 0); // Red
glVertex2f(-11.0f, -7.0f);
glVertex2f(-10.0f, -7.0f);
glVertex2f(-10.0f, 4.0f);
glVertex2f(-11.0f, 4.0f);
glEnd();
glBegin(GL_POLYGON); // Each set of 4 vertices form a quad
glColor3ub(0, 0, 0); // Red
glVertex2f(-10.0f, 4.0f);
glVertex2f(-8.5f, 4.0f);
glVertex2f(-8.5f, 3.0f);
glVertex2f(-10.0f, 3.0f);
glEnd();


glBegin(GL_POLYGON); // Each set of 4 vertices form a quad
glColor3ub(0, 0, 0); // Red
glVertex2f(-12.0f, -6.0f);
glVertex2f(-11.0f, -6.0f);
glVertex2f(-11.0f, 3.0f);
glVertex2f(-12.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0, 0, 0); // Red
glVertex2f(-13.0f, -5.0f);
glVertex2f(-12.0f, -5.0f);
glVertex2f(-12.0f, 2.0f);
glVertex2f(-13.0f, 2.0f);
glEnd();

}



void circle()
{

            glBegin(GL_POLYGON);
            for(int i=0;i<200;i++)
            {
                glColor3ub(226, 223, 210);
                float pi=3.1416;
                float A=(i*2*pi)/200;
                float r=10;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y+20);
            }
            glEnd();
}



void batmanLogo() //!################################akm_bat()
{


            glPushMatrix();
            glScaled(.6, .8, 0);
            glTranslatef(8, 26, 0);
            //!#############################################flashLight
            glPushMatrix();
            glTranslatef(-28,-2,0);
            glScaled(3, 2.5, 0);
            //!#############################light01
            glBegin(GL_POLYGON);
            glColor3ub(255, 255, 255); // Red
            glVertex2f(1, 0);
            glVertex2f(10, 6);
            glVertex2f(6, 10);
            glVertex2f(0, 1);
            glEnd();

            glPopMatrix();

            glPushMatrix();
            glTranslatef(28,-2,0);
            glScaled(3, 2.5, 0);
            glRotatef(90, 0.0f, 0.0f, 1.0f);
            //!#############################light02
            glBegin(GL_POLYGON);
            glColor3ub(255, 255, 255); // Red
            glVertex2f(1, 0);
            glVertex2f(10, 6);
            glVertex2f(6, 10);
            glVertex2f(0, 1);
            glEnd();
            glPopMatrix();

            //!#############################################flashLight_end

            glPushMatrix();
            circle();

            glPopMatrix();

            glPushMatrix();

            glScaled(.8, 1, 0);
            glTranslatef(1,21,0);
            glRotatef(moveBat, 0.0f, 1.0f, 0.0f);
            batman();
            glPopMatrix();

            glPopMatrix();


}



void updateBat(int value) {



    moveBat+=1;

    if(moveBat > 360)
    {
        moveBat-=360;
    }

    glutPostRedisplay(); //Notify GLUT that the display has changed



    glutTimerFunc(20, updateBat, 0); //Notify GLUT to call update again in 25 milliseconds
}



void Umbrella()
{

        glPushMatrix();
    glScalef(48, 48, 0);
    glBegin(GL_QUADS);
    glColor3ub(156, 156, 161);

    glVertex2f(-0.01, -0.6f);
    glVertex2f(0.01, -0.6f);
    glVertex2f(0.01, -0.9f);
    glVertex2f(-0.01, -0.9f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(245, 203, 66);
    glVertex2f(-0.05,-0.65);
    glVertex2f(0.05,-0.65);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(245, 105, 66);
    glVertex2f(0.13,-0.64);
    glVertex2f(0.05,-0.65);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(24, 161, 26);
    glVertex2f(-0.13,-0.64);
    glVertex2f(-0.05,-0.65);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(82, 235, 212);
    glVertex2f(-0.18,-0.63);
    glVertex2f(-0.13,-0.64);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(232, 9, 9);
    glVertex2f(0.18,-0.63);
    glVertex2f(0.13,-0.64);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(179, 2, 219);
    glVertex2f(0.21,-0.62);
    glVertex2f(0.18,-0.63);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(18, 51, 219);
    glVertex2f(-0.21,-0.62);
    glVertex2f(-0.18,-0.63);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(142, 136, 148);
    glVertex2f(-0.23,-0.61);
    glVertex2f(-0.21,-0.62);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(117, 118, 128);
    glVertex2f(0.23,-0.61);
    glVertex2f(0.21,-0.62);
    glVertex2f(0.0,-0.45);
    glEnd();

    glPopMatrix();


}

void Seat()
{

    glPushMatrix();
    glTranslatef(0, 20, 0);
    glScalef(70, 70, 0);

    glBegin(GL_QUADS);
    glColor3ub(150, 124, 45);
    glVertex2f(0.13, -0.83f);
    glVertex2f(0.15, -0.83f);
    glVertex2f(0.15, -0.86f);
    glVertex2f(0.13, -0.866f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(171, 151, 89);
    glVertex2f(0.09, -0.83f);
    glVertex2f(0.16, -0.83f);
    glVertex2f(0.08, -0.88f);
    glVertex2f(0.02, -0.88f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(150, 124, 45);
    glVertex2f(0.02, -0.8f);
    glVertex2f(0.08, -0.8f);
    glVertex2f(0.08, -0.9f);
    glVertex2f(0.02, -0.9f);
    glEnd();
    glPopMatrix();


}

void crab(){

glBegin(GL_POLYGON); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.4f,0.1f);
glVertex2f(0.44f,0.1f);
glVertex2f(0.46f,0.15f);
glVertex2f(0.44f,0.18f);
glVertex2f(0.4f,0.18f);
glVertex2f(0.38f,0.15f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.44f,0.18f);
glVertex2f(0.47f,0.2f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.47f,0.2f);
glVertex2f(0.49f,0.16f);
glEnd();
glBegin(GL_LINES); //CRAB
 glColor3ub(220,88,33);
glVertex2f(0.46f,0.15f);
glVertex2f(0.48f,0.17f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.48f,0.17f);
glVertex2f(0.5f,0.13f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.45f,0.13f);
glVertex2f(0.47f,0.15f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.47f,0.15f);
glVertex2f(0.49f,0.11f);
glEnd();
glBegin(GL_LINES); //CRAB
 glColor3ub(220,88,33);
glVertex2f(0.44f,0.1f);
glVertex2f(0.46f,0.12f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.46f,0.12f);
glVertex2f(0.48f,0.08f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.4f,0.18f);
glVertex2f(0.38f,0.2f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.38f,0.2f);
glVertex2f(0.36f,0.16f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.38f,0.15f);
glVertex2f(0.36f,0.17f);
 glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.36f,0.17f);
glVertex2f(0.34f,0.13f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.4f,0.1f);
glVertex2f(0.38f,0.12f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.38f,0.12f);
glVertex2f(0.36f,0.08f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.39f,0.13f);
glVertex2f(0.37f,0.14f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
 glVertex2f(0.37f,0.14f);
glVertex2f(0.35f,0.1f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.445f,0.17f);
glVertex2f(0.475f,0.19f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.475f,0.19f);
glVertex2f(0.485f,0.16f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.39f,0.17f);
glVertex2f(0.37f,0.19f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.37f,0.19f);
glVertex2f(0.35f,0.16f);
glEnd();
glPointSize(3.00);
glBegin(GL_POINTS);
glColor3ub(31,31,27);
glVertex2f(0.41f,0.16f);
glVertex2f(0.43f,0.16f);
glEnd();
glBegin(GL_POLYGON); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.2f,0.1f);
glVertex2f(0.25f,0.1f);
glVertex2f(0.27f,0.15f);
glVertex2f(0.25f,0.2f);
glVertex2f(0.2f,0.2f);
glVertex2f(0.18f,0.15f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.25f,0.19f);
glVertex2f(0.27f,0.20f);
glEnd();
glBegin(GL_LINES); //CRAB
 glColor3ub(220,88,33);
glVertex2f(0.27f,0.20f);
glVertex2f(0.29f,0.15f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.25f,0.20f);
glVertex2f(0.27f,0.21f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.27f,0.21f);
glVertex2f(0.29f,0.18f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.26f,0.14f);
glVertex2f(0.28f,0.16f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.28f,0.16f);
glVertex2f(0.30f,0.12f);
glEnd();
 glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.26f,0.17f);
glVertex2f(0.28f,0.18f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.28f,0.18f);
glVertex2f(0.30f,0.16f);
glEnd();
glBegin(GL_LINES); //CRAB
glColor3ub(220,88,33);
glVertex2f(0.25f,0.10f);
glVertex2f(0.27f,0.12f);
glEnd();
glBegin(GL_LINES);
glColor3ub(220,88,33);
glVertex2f(0.27f,0.12f);//CRAB
glVertex2f(0.29f,0.10f);
glEnd();
glBegin(GL_LINES);
glColor3ub(220,88,33);
glVertex2f(0.17f,0.16f);//CRAB
glVertex2f(0.19f,0.14f);
glEnd();
glBegin(GL_LINES);
glColor3ub(220,88,33);//CRAB
glVertex2f(0.17f,0.16f);
glVertex2f(0.15f,0.12f);
glEnd();
glBegin(GL_LINES);
glColor3ub(220,88,33);//CRAB
glVertex2f(0.17f,0.19f);
glVertex2f(0.21f,0.11f);
glEnd();
glBegin(GL_LINES);
glColor3ub(220,88,33);//CRAB
glVertex2f(0.17f,0.19f);
glVertex2f(0.14f,0.13f);
glEnd();
glBegin(GL_LINES);
glColor3ub(220,88,33);//CRAB
glVertex2f(0.20f,0.19f);
glVertex2f(0.17f,0.22f);
glEnd();
glBegin(GL_LINES);
glColor3ub(220,88,33);//CRAB
glVertex2f(0.17f,0.22f);
 glVertex2f(0.15f,0.17f);
glEnd();
glBegin(GL_LINES);
glColor3ub(220,88,33);//CRAB
glVertex2f(0.17f,0.13f);
glVertex2f(0.20f,0.11f);
glEnd();
glBegin(GL_LINES);
glColor3ub(220,88,33);//CRAB
glVertex2f(0.17f,0.13f);
glVertex2f(0.15f,0.12f);
glEnd();
glBegin(GL_LINES);
glColor3ub(220,88,33);//CRAB
glVertex2f(0.20f,0.10f);
glVertex2f(0.17f,0.12f);
glEnd();
glBegin(GL_LINES);
glColor3ub(220,88,33);//CRAB
glVertex2f(0.17f,0.12f);
glVertex2f(0.15f,0.10f);
glEnd();
glPointSize(3.00);
glBegin(GL_POINTS);
glColor3ub(31,31,27);
glVertex2f(0.24f,0.16f);
glVertex2f(0.21f,0.16f);
glEnd();
}



void netTower() //!akm_tower
{

            //!towerBar
            glPushMatrix();
            glScaled(.6, .6, 0);
            glTranslatef(58,-20,0);


            //!###########################towerStruct
            glPushMatrix();
            glScaled(4, 4, 0);
                    glBegin(GL_POLYGON);
            glColor3ub(0,0,0);
            glVertex2f(0, -4);
            glVertex2f(2, -4);
            glVertex2f(2, 6);
            glVertex2f(0, 6);
            glEnd();

            glBegin(GL_LINES);
            glColor3ub(0,0,0);
            glVertex2f(.5, .6);
            glVertex2f(1.5, 6);
            glVertex2f(1.5, 6);
            glVertex2f(1.5, 10);
            glVertex2f(1.5, 10);
            glVertex2f(.5, 10);
            glVertex2f(.5, 10);
            glVertex2f(.5, .6);
            glEnd();

            glBegin(GL_LINES);
            glColor3ub(0,0,0);
            glVertex2f(2, 6);
            glVertex2f(4, 9);
            glEnd();

            glBegin(GL_LINES);
            glColor3ub(0,0,0);
            glVertex2f(2, 6);
            glVertex2f(4, 7);
            glEnd();

            glBegin(GL_LINES);
            glColor3ub(0,0,0);
            glVertex2f(0, 6);
            glVertex2f(-2, 9);
            glEnd();

            glBegin(GL_LINES);
            glColor3ub(0,0,0);
            glVertex2f(0, 6);
            glVertex2f(-2, 7);
            glEnd();

            //!############################towerStruct End
            glPopMatrix();

            //!netBar1/2
            glPushMatrix();
            glTranslatef(-7,12,0);
            glScaled(2, 4, 0);
            glBegin(GL_POLYGON);
            glColor3ub(128, 0, 32);
            glVertex2f(0, 0);
            glVertex2f(1, 0);
            glVertex2f(1, 3);
            glVertex2f(0, 3);
            glEnd();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(13,12,0);
            glScaled(2, 4, 0);
            glBegin(GL_POLYGON);
            glColor3ub(128, 0, 32);
            glVertex2f(0, 0);
            glVertex2f(1, 0);
            glVertex2f(1, 3);
            glVertex2f(0, 3);
            glEnd();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(1.5,31,0);
            glScaled(2, 4, 0);
            glBegin(GL_POLYGON);
            glColor3ub(128, 0, 32);
            glVertex2f(0, 0);
            glVertex2f(1, 0);
            glVertex2f(1, 3);
            glVertex2f(0, 3);
            glEnd();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(4.5,31,0);
            glScaled(2, 4, 0);
            glBegin(GL_POLYGON);
            glColor3ub(128, 0, 32);
            glVertex2f(0, 0);
            glVertex2f(1, 0);
            glVertex2f(1, 3);
            glVertex2f(0, 3);
            glEnd();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-8,19,0);
            glScaled(4, 2, 0);
            glBegin(GL_POLYGON);
            glColor3ub(128, 0, 32);
            glVertex2f(0, 0);
            glVertex2f(6, 0);
            glVertex2f(6, .5);
            glVertex2f(0, .5);
            glEnd();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-8,28,0);
            glScaled(4, 2, 0);
            glBegin(GL_POLYGON);
            glColor3ub(128, 0, 32);
            glVertex2f(0, 0);
            glVertex2f(6, 0);
            glVertex2f(6, .5);
            glVertex2f(0, .5);
            glEnd();
            glPopMatrix();
            glPushMatrix();
            glTranslatef(-8,30,0);
            glScaled(4, 2, 0);
            glBegin(GL_POLYGON);
            glColor3ub(128, 0, 32);
            glVertex2f(0, 0);
            glVertex2f(6, 0);
            glVertex2f(6, .5);
            glVertex2f(0, .5);
            glEnd();
            glPopMatrix();


            //!net bar 1/2-2
            glPushMatrix();
            glTranslatef(-4,11,0);
            glScaled(2, 4, 0);
            glBegin(GL_POLYGON);
            glColor3ub(128, 0, 32);
            glVertex2f(0, 0);
            glVertex2f(1, 0);
            glVertex2f(1, 3);
            glVertex2f(0, 3);
            glEnd();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(10,11,0);
            glScaled(2, 4, 0);
            glBegin(GL_POLYGON);
            glColor3ub(128, 0, 32);
            glVertex2f(0, 0);
            glVertex2f(1, 0);
            glVertex2f(1, 3);
            glVertex2f(0, 3);
            glEnd();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-8,16,0);
            glScaled(4, 2, 0);
            glBegin(GL_POLYGON);
            glColor3ub(128, 0, 32);
            glVertex2f(0, 0);
            glVertex2f(6, 0);
            glVertex2f(6, .5);
            glVertex2f(0, .5);
            glEnd();
            glPopMatrix();

            //!########################net3
            glPushMatrix();
            glScaled(3, 4, 0);
            glTranslatef(-0.2,3.5,0);
            glBegin(GL_POLYGON);
            glColor3ub(250,250,250);
            glVertex2f(0, 0);
            glVertex2f(1, 0);
            glVertex2f(1, 2);
            glVertex2f(0, 2);
            glEnd();
            glPopMatrix();

            glPushMatrix();
            glScaled(3, 4, 0);
            glTranslatef(2,3.5,0);
            glVertex2f(0, 0);
            glVertex2f(1, 0);
            glVertex2f(1, 2);
            glVertex2f(0, 2);
            glPopMatrix();

            //!circle
            glPushMatrix();

            glScaled(.5, .5, 0);
            glTranslatef(-14, 42,0);
            glColor3ub(255, 255, 255);
            circle();
            glPopMatrix();

            glPushMatrix();
            glScaled(.5, .5, 0);
            glTranslatef(30, 42,0);
            glColor3ub(255, 255, 255);
            circle();
            glPopMatrix();

            //!circle2
             glPushMatrix();

            glScaled(.5, .5, 0);
            glTranslatef(-16, 42,0);
            glColor3ub(250, 250, 0);
            circle();
            glPopMatrix();

            glPushMatrix();
            glScaled(.5, .5, 0);
            glTranslatef(32, 42,0);
            glColor3ub(250, 250, 0);
            circle();
            glPopMatrix();


            glPopMatrix();





}

void boatMOdel(){


   glColor3ub( 23, 23, 22);
   glBegin(GL_POLYGON);
   glVertex2f(-10 ,10);
   glVertex2f(11,10);
   glVertex2f(16 ,5);
   glVertex2f(-10 ,5);
   glEnd();

   glColor3ub( 255, 0, 0);
   glBegin(GL_POLYGON);
   glVertex2f(-8 ,10);
   glVertex2f(10 ,10);
   glVertex2f(7 ,16);
   glVertex2f(-8,16);
   glEnd();

   glColor3ub(13, 0, 255);
   glBegin(GL_POLYGON);
   glVertex2f(-1.5 ,14.5);
   glVertex2f(0.5 ,14.5);
   glVertex2f(0.5 ,12.5);
   glVertex2f(-1.5 ,12.5);
   glEnd();

   glColor3ub( 13, 0, 255);
   glBegin(GL_POLYGON);
   glVertex2f(-5.5 ,14.5);
   glVertex2f(-3.5 ,14.5);
   glVertex2f(-3.5 ,12.5);
   glVertex2f(-5.5 ,12.5);
   glEnd();

   glColor3ub( 13, 0, 255);
   glBegin(GL_POLYGON);
   glVertex2f(2.5 ,14.5);
   glVertex2f(4.5 ,14.5);
   glVertex2f(4.5 ,12.5);
   glVertex2f(2.5 ,12.5);
   glEnd();

   glColor3ub( 0, 255, 72);
   glBegin(GL_POLYGON);
   glVertex2f(-2.5 ,16);
   glVertex2f(6.5 ,16);
   glVertex2f(5 ,20);
   glVertex2f(-2.5 ,20);
   glEnd();

   glColor3f( 255, 255, 0);
   glBegin(GL_POLYGON);
   glVertex2f(-1 ,19.5);
   glVertex2f(1,19.5);
   glVertex2f(1 ,17.5);
   glVertex2f(-1 ,17.5);
   glEnd();

   glColor3f( 255, 255, 0);
   glBegin(GL_POLYGON);
   glVertex2f(2 ,19.5);
   glVertex2f(4 ,19.5);
   glVertex2f(4 ,17.5);
   glVertex2f(2 ,17.5);
   glEnd();


}

void boat()
{

   glPushMatrix();
   glTranslatef(_move, 0, 1);
   boatMOdel();
   glPopMatrix();

}

void hill()
{
    glColor3ub(10, 95, 53);
    glBegin(GL_POLYGON);
    glVertex2f(-40, 20);
    glVertex2f(-50, 33);
    glVertex2f(-65, 20);
    glEnd();

    glColor3ub(7, 109, 45);
    glBegin(GL_POLYGON);
    glVertex2f(-35, 20);
    glVertex2f(-40, 33);
    glVertex2f(-60, 20);
    glEnd();
}

void kite()
{
   glColor3ub( 255, 31, 31);
   glBegin(GL_POLYGON);
   glVertex2f(40 ,35);
   glVertex2f(37 ,37.5);
   glVertex2f(40 ,40);
   glVertex2f(43 ,37.5);
   glEnd();
}

void kitelower()
{
   glColor3ub( 255, 248, 31);
   glBegin(GL_POLYGON);
   glVertex2f(38.5 ,33);
   glVertex2f(40 ,35);
   glVertex2f(41.5 ,33);
   glEnd();
}

void kitebox()
{
   glColor3ub( 30, 56, 250);
   glBegin(GL_POLYGON);
   glVertex2f(48 ,22.5);
   glVertex2f(45 ,22.5);
   glVertex2f(45 ,19.5);
   glVertex2f(48 ,19.5);
   glEnd();
}

void kiteline()
{
    glColor3ub( 255, 31, 31);
    glBegin(GL_LINES);
    glVertex2f(47,22.5);
    glVertex2f(40,35.5);

   glEnd();
}



void cargoShip() //!akm_ship
{

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!cargo ship structure
    glBegin(GL_POLYGON);
    glColor3ub (9, 9, 29);
    glVertex2f(-5,2);
    glVertex2f(25,2);
    glVertex2f(29,6);
    glVertex2f(-5,6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (255, 69, 0);
    glVertex2f(-4,0);
    glVertex2f(23,0);
    glVertex2f(25,2);
    glVertex2f(-5,2);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub (133, 133, 133);
    glVertex2f(2,4);
    glVertex2f(25,4);
    glVertex2f(27,6);
    glVertex2f(2,6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (0, 30, 0);
    glVertex2f(-5,6);
    glVertex2f(2,6);
    glVertex2f(2,11);
    glVertex2f(-5,11);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (20,0,39);
    glVertex2f(-4,11);
    glVertex2f(2,11);
    glVertex2f(2,13);
    glVertex2f(-4,13);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (20,0,39);
    glVertex2f(0,13);
    glVertex2f(2,13);
    glVertex2f(2,18);
    glVertex2f(0,18);
    glEnd();

    glPushMatrix();
    glTranslatef(-2.5, 0 ,0);
    glBegin(GL_POLYGON);
    glColor3ub (20,0,39);
    glVertex2f(0,13);
    glVertex2f(2,13);
    glVertex2f(2,18);
    glVertex2f(0,18);
    glEnd();
    glPopMatrix();

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!windowwwws
    glBegin(GL_POLYGON);
    glColor3ub (250, 250, 250);
    glVertex2f(-4,6);
    glVertex2f(-3,6);
    glVertex2f(-3,7);
    glVertex2f(-4,7);
    glEnd();

    glPushMatrix();
    glTranslatef(1.5, 0 ,0);
    glBegin(GL_POLYGON);
    glColor3ub (250, 250, 250);
    glVertex2f(-4,6);
    glVertex2f(-3,6);
    glVertex2f(-3,7);
    glVertex2f(-4,7);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3, 0 ,0);
    glBegin(GL_POLYGON);
    glColor3ub (250, 250, 250);
    glVertex2f(-4,6);
    glVertex2f(-3,6);
    glVertex2f(-3,7);
    glVertex2f(-4,7);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 0 ,0);
    glBegin(GL_POLYGON);
    glColor3ub (250, 250, 250);
    glVertex2f(-4,6);
    glVertex2f(-3,6);
    glVertex2f(-3,7);
    glVertex2f(-4,7);
    glEnd();
    glPopMatrix();

    //!!!!!!!!!!!!!!!!!! windows 2nd row
    glPushMatrix();
    glTranslatef(0, 2 ,0);
    glBegin(GL_POLYGON);
    glColor3ub (250, 250, 250);
    glVertex2f(-4,6);
    glVertex2f(-3,6);
    glVertex2f(-3,7);
    glVertex2f(-4,7);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 2 ,0);
    glBegin(GL_POLYGON);
    glColor3ub (250, 250, 250);
    glVertex2f(-4,6);
    glVertex2f(-3,6);
    glVertex2f(-3,7);
    glVertex2f(-4,7);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3, 2 ,0);
    glBegin(GL_POLYGON);
    glColor3ub (250, 250, 250);
    glVertex2f(-4,6);
    glVertex2f(-3,6);
    glVertex2f(-3,7);
    glVertex2f(-4,7);
    glEnd();
    glPopMatrix();

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!end of cargo ship structure

    /*! container structure. you can use this part as an obj for another method

    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
*/

    //!container column-01
    glPushMatrix();
    glColor3ub(0, 0, 52);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3, 2, 0);
    glColor3ub(77, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 2, 0);
    glColor3ub(77, 50, 0);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 4, 0);
    glColor3ub(205,102,0);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();

    //!column-02
    glPushMatrix();
    glTranslatef(5.5, 0, 0);
    glColor3ub(255,171,87);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(8, 2, 0);
    glColor3ub(255,87,87);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.5, 4, 0);
    glColor3ub(255,0,87);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();

    //!column-03
    glPushMatrix();
    glTranslatef(11, 0, 0);
    glColor3ub(128, 0, 255);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(16, 0, 0);
    glColor3ub(109, 218, 111);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(13, 2, 0);
    glColor3ub(10,0,20);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(14, 4, 0);
    glColor3ub(91, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(18, 2, 0);
    glColor3ub(255,255,26);
    glBegin(GL_POLYGON);
    glVertex2f(3,4);
    glVertex2f(8,4);
    glVertex2f(8,6);
    glVertex2f(3,6);
    glEnd();
    glPopMatrix();


    //!!!!!!crane
    glPushMatrix();
    glTranslatef(26.5, 6, 0);
    glScalef(1.5, 2, 0);

    //!!!!##################################### crane Body structure
    glBegin(GL_POLYGON);
    glColor3ub (51, 51, 51);
    glVertex2f(-1,0);
    glVertex2f(1,0);
    glVertex2f(1,.5);
    glVertex2f(-1,.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (51, 51, 51);
    glVertex2f(-.5,.5);
    glVertex2f(.5,.5);
    glVertex2f(.5,4);
    glVertex2f(-.5,4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (51, 51, 51);
    glVertex2f(-.2, 4);
    glVertex2f(.2, 4);
    glVertex2f(.2, 8);
    glVertex2f(-.2, 8);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub (63, 0, 0);
    glVertex2f(0, 6);
    glVertex2f(-4, 8);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub (63, 0, 0);
    glVertex2f(0, 2);
    glVertex2f(-4, 8);
    glEnd();

//!!!!!!!!!!end of crane body structure


    glPopMatrix();



}


void cargoShip_01() //!akm_ship01
{
    glPushMatrix();
    glTranslatef(_move, 0, 0);
    glTranslatef(0, 10, 0);
    cargoShip();
    glPopMatrix();
}

void cargoShip_02()//!akm_ship02
{
    glPushMatrix();
    glTranslatef(_move2, 0, 0);

    glPushMatrix();
    glTranslatef(-10, -5, 0);
    cargoShip();
    glPopMatrix();

    glPopMatrix();
}

void cargoShip_night()//!akm_ship02
{
    glPushMatrix();
    glScalef(1, .8, 0);
    glTranslatef(15, 20, 0);
    cargoShip();

    glPopMatrix();
}


void move_cargoShip_01 (int value) //!akm_ship01_anm
{

    _move += Shipspeed00;

    if(_move > 55)
    {
        _move = -55;
    }

	glutPostRedisplay();

	glutTimerFunc(20, move_cargoShip_01, 0);
}

void move_cargoShip_02 (int value) //!akm_ship02_anm
{

    _move2 += Shipspeed01;

    if(_move2 > 55)
    {
        _move2 = -55;
    }

	glutPostRedisplay();

	glutTimerFunc(20, move_cargoShip_02, 0);
}


void flagship()
{
glPushMatrix();
glTranslatef(position, 0, 0);
glBegin(GL_QUADS);
glColor3ub(173, 71, 7);
glVertex2f(0.3f, -0.9f);
glVertex2f(0.8f, -0.9f);
glVertex2f(1.0f, -0.6f);
glVertex2f(0.1f, -0.6f);
glEnd();
glBegin(GL_QUADS);//1st row
glColor3ub(37,19,15);
glVertex2f(0.21f, -0.6f);
glVertex2f(0.9f, -0.6f);
glVertex2f(0.9f, -0.5f);
glVertex2f(0.21f, -0.5f);
glEnd();
glBegin(GL_QUADS);
glColor3ub(45,45,45);//2nd row
glVertex2f(0.25f, -0.5f);
glVertex2f(0.83f, -0.5f);
glVertex2f(0.83f, -0.4f);
glVertex2f(0.25f, -0.4f);
glEnd();
glBegin(GL_QUADS);
glColor3ub(0.0,0.0,0.0);//1st piller
glVertex2f(0.31f, -0.22f);
glVertex2f(0.39f, -0.22f);
glVertex2f(0.39f, -0.40f);
glVertex2f(0.31f, -0.40f);
glEnd();
glBegin(GL_QUADS); //2nd piller
glColor3ub(0.0,0.0,0.0);
glVertex2f(0.45f, -0.22f);
glVertex2f(0.52f, -0.22f);
glVertex2f(0.52f, -0.40f);
glVertex2f(0.45f, -0.40f);
glEnd();
glBegin(GL_QUADS);//3rd piller
glColor3ub(0.0,0.0,0.0);
glVertex2f(0.56f, -0.22f);
glVertex2f(0.62f, -0.22f);
glVertex2f(0.62f, -0.40f);
glVertex2f(0.56f, -0.40f);
glEnd();
glBegin(GL_QUADS);//4th piller
glColor3ub(0.0,0.0,0.0);
glVertex2f(0.66f, -0.22f);
glVertex2f(0.73f, -0.22f);
glVertex2f(0.73f, -0.40f);
glVertex2f(0.66f, -0.40f);
glEnd();
glBegin(GL_QUADS);
glColor3ub(247,247,247);//1st piller_white part
glVertex2f(0.31f, -0.22f);
glVertex2f(0.39f, -0.22f);
glVertex2f(0.39f, -0.17f);
glVertex2f(0.31f, -0.17f);
glEnd();
glBegin(GL_QUADS); //2nd piller_white part
glColor3ub(247,247,247);
glVertex2f(0.45f, -0.22f);
glVertex2f(0.52f, -0.22f);
glVertex2f(0.52f, -0.17f);
glVertex2f(0.45f, -0.17f);
glEnd();
glBegin(GL_QUADS);//3rd piller_white part
glColor3ub(247,247,247);
glVertex2f(0.56f, -0.22f);
glVertex2f(0.62f, -0.22f);
glVertex2f(0.62f, -0.17f);
glVertex2f(0.56f, -0.17f);
glEnd();
glBegin(GL_QUADS);//4th piller_white part
glColor3ub(247,247,247);
glVertex2f(0.66f, -0.22f);
glVertex2f(0.73f, -0.22f);
glVertex2f(0.73f, -0.17f);
glVertex2f(0.66f, -0.17f);
glEnd();
glBegin(GL_QUADS);//piller brown
glColor3ub(654,52,52);
glVertex2f(0.17f, -0.6f);
glVertex2f(0.20f, -0.6f);
glVertex2f(0.20f, -0.0f);
glVertex2f(0.17f, -0.0f);
glEnd();
glBegin(GL_QUADS);//pileer-violet
glColor3ub(145,145,145);
glVertex2f(0.19f, -0.0f);
glVertex2f(0.21f,-0.0f);
glVertex2f(0.21f, -0.6f);
glVertex2f(0.19f, -0.6f);
glEnd();
glBegin(GL_TRIANGLES);//Flag
glColor3ub(247,5,3);
glVertex2f(-0.01f, -0.4);
glVertex2f(0.17f, -0.4f);
glVertex2f(0.17f, -0.01f);
glEnd();
glBegin(GL_QUADS);//1st ship window
glColor3ub(247,247,247);
glVertex2f(0.22f, -0.58f);
glVertex2f(0.28f, -0.58f);
glVertex2f(0.28f, -0.53f);
glVertex2f(0.22f, -0.53f);
glEnd();
glBegin(GL_QUADS);//2nd row WINDOW
glColor3ub(247,247,247);
glVertex2f(0.40f, -0.58f);
glVertex2f(0.34f, -0.58f);
glVertex2f(0.34f, -0.53f);
glVertex2f(0.40f, -0.53f);
glEnd();
glBegin(GL_QUADS);//3rd shipWINDOW
glColor3ub(247,247,247);
glVertex2f(0.51f, -0.58f);
glVertex2f(0.45f, -0.58f);
glVertex2f(0.45f, -0.53f);
glVertex2f(0.51f, -0.53f);
glEnd();
glBegin(GL_QUADS);//4th ship window
glColor3ub(247,247,247);
glVertex2f(0.55f, -0.58f);
glVertex2f(0.61f, -0.58f);
glVertex2f(0.61f, -0.53f);
glVertex2f(0.55f, -0.53f);
glEnd();
glBegin(GL_QUADS);//5th window
glColor3ub(247,247,247);
glVertex2f(0.65f, -0.58f);
glVertex2f(0.71f, -0.58f);
glVertex2f(0.71f, -0.53f);
glVertex2f(0.65f, -0.53f);
glEnd();
glBegin(GL_QUADS);//6th window
glColor3ub(247,247,247);
glVertex2f(0.85f, -0.58f);
glVertex2f(0.77f, -0.58f);
glVertex2f(0.77f, -0.53f);
glVertex2f(0.85f, -0.53f);
glEnd();
glPopMatrix();


}



void update(int value) {
if(position > 1.0)
position = -1.2f;
position += speed;
glutPostRedisplay();
glutTimerFunc(100, update, 0);
}


void banner() //!akm_banner
{
        glBegin(GL_POLYGON);
        glColor3ub(250, 250, 250);
        glVertex2i(-5, -4);
        glVertex2i(26, -4);
        glVertex2i(26, 14);
        glVertex2i(-5, 14);
        glEnd();

        glBegin(GL_LINES);
        glColor3ub(11, 11, 69);
        glVertex2i(26, -4);
        glVertex2i(31, 6);
        glVertex2i(31, 6);
        glVertex2i(26, 14);
        glVertex2i(26, 14);
        glVertex2i(26, -4);
        glEnd();

        glBegin(GL_LINES);
        glColor3ub(11, 11, 69);
        glVertex2i(-5, 0);
        glVertex2i(-3, 0);
        glVertex2i(-3, 0);
        glVertex2i(-2, 5);
        glVertex2i(-2, 5);
        glVertex2i(2, 5);
        glVertex2i(2, 5);
        glVertex2i(3, 0);
        glVertex2i(3, 0);
        glVertex2i(5, 0);
        glVertex2i(5, 0);
        glVertex2i(2, 10);
        glVertex2i(2, 10);
        glVertex2i(-2, 10);
        glVertex2i(-2, 10);
        glVertex2i(-5, 0);
        glEnd();

        glBegin(GL_LINES);
        glColor3ub(11, 11, 69);
        glVertex2i(6, 0);
        glVertex2i(8, 0);
        glVertex2i(8, 0);
        glVertex2i(8, 10);
        glVertex2i(8, 10);
        glVertex2i(6, 10);
        glVertex2i(6, 10);
        glVertex2i(6, 0);
        glEnd();

        glBegin(GL_LINES);
        glColor3ub(11, 11, 69);
        glVertex2i(10, 0);
        glVertex2i(16, 0);
        glVertex2i(16, 0);
        glVertex2i(16, 10);
        glVertex2i(16, 10);
        glVertex2i(14, 10);
        glVertex2i(14, 10);
        glVertex2i(14, 5);
        glVertex2i(14, 5);
        glVertex2i(12, 5);
        glVertex2i(12, 5);
        glVertex2i(12, 10);
        glVertex2i(12, 10);
        glVertex2i(10, 10);
        glVertex2i(10, 10);
        glVertex2i(10, 0);
        glEnd();

        glBegin(GL_LINES);
        glColor3ub(11, 11, 69);
        glVertex2i(18, 0);
        glVertex2i(24, 0);
        glVertex2i(24, 0);
        glVertex2i(24, 4);
        glVertex2i(24, 4);
        glVertex2i(18, 4);
        glVertex2i(18, 4);
        glVertex2i(18, 6);
        glVertex2i(18, 6);
        glVertex2i(24, 6);
        glVertex2i(24, 6);
        glVertex2i(24, 10);
        glVertex2i(24, 10);
        glVertex2i(18, 10);
        glVertex2i(18, 10);
        glVertex2i(18, 0);
        glEnd();

        glBegin(GL_LINES);
        glColor3ub(11, 11, 69);
        glVertex2i(31, 6);
        glVertex2i(50, 6);
        glEnd();

}

void airPlane() //!akm_airPlane
{

        glBegin(GL_POLYGON);
        glColor3ub(11, 11, 69);
        glVertex2f(0, 0);
        glVertex2f(10.0f, 0);
        glVertex2f(10.0f, 2.0f);
        glVertex2f(0, 2.0f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(17,30,108);
        glVertex2f(0, 0);
        glVertex2f(10.0f, 0);
        glVertex2f(10.0f, -1.0f);
        glVertex2f(0, -1.0f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(11, 11, 69);
        glVertex2f(0, -1.0f);
        glVertex2f(1.0f, 2.0f);
        glVertex2f(-4.0f, 5.0f);
        glVertex2f(-5.0f, 5.0f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(17,30,108);
        glVertex2f(5.0f, 2.0f);
        glVertex2f(7.0f, 2.0f);
        glVertex2f(3.0f, 5.0f);
        glVertex2f(2.0f, 5.0f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(11, 11, 69);
        glVertex2f(2.0f, 0.0f);
        glVertex2f(0.0f, -5.0f);
        glVertex2f(2.0f, -5.0f);
        glVertex2f(7.0f, 0.0f);
        glEnd();


        glBegin(GL_POLYGON);
        for(int i=0;i<100;i++)
        {
        glColor3ub(11, 11, 69);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=1.5;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+10,y+.43);
        }
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(17,30,108);
        glVertex2f(10.0f, 0.0f);
        glVertex2f(11.5f, 0.0f);
        glVertex2f(11.5f, -1.0f);
        glVertex2f(10.0f, -1.0f);
        glEnd();

}

void bannerPlane()//!akm_BP
{
        glPushMatrix();
        glTranslatef(_moveBP,0,0);

        glPushMatrix();
        glTranslatef(-65,32,0);

        glPushMatrix();
        airPlane();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-30,-5,0);
        glScalef(.7, .7, 0);
        banner();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();

}


void moveBannerPlane(int value) //!akm_BP_anm
{

    _moveBP += Planespeed;

    //detection mechanism
    if(_moveBP > 130)
    {
        _moveBP = -65;
    }

	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, moveBannerPlane, 0); //Notify GLUT to call update again in 25 milliseconds
}


void watchTower_Night() //!akm_WT_Night
{

        //!!#############################translate
        glPushMatrix();
        glTranslatef(-45, -15, 0);

        //!!####################scaling
        glPushMatrix();
        glScalef(2, 2, 0);

        //!############################body
        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 10.0f);
        glVertex2f(5.0f, 10.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 9.0f);
        glVertex2f(5.0f, 9.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 8.0f);
        glVertex2f(5.0f, 8.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 6.0f);
        glVertex2f(5.0f, 6.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 6.0f);
        glVertex2f(0.0f, 4.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(5.0f, 6.0f);
        glVertex2f(4.0f, 4.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 6.0f);
        glVertex2f(5.0f, 6.0f);
        glVertex2f(5.0f, 6.0f);
        glVertex2f(5.0f, 10.0f);
        glVertex2f(5.0f, 10.0f);
        glVertex2f(-1.0f, 10.0f);
        glVertex2f(-1.0f, 10.0f);
        glVertex2f(-1.0f, 6.0f);
        glEnd();

        //!#####################################Main_body_Struct
        glBegin(GL_QUADS);
        glColor3ub(20, 13, 0);
        glVertex2f(0, -4.0f);
        glVertex2f(4.0f, -4.0f);
        glVertex2f(4.0f, 10.0f);
        glVertex2f(0.0f, 10.0f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(83,0,0);
        glVertex2f(0, -1);
        glVertex2f(4.0f, -1.0f);
        glVertex2f(4.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glEnd();

        glPushMatrix();
        glTranslatef(0,2,0);
        glBegin(GL_QUADS);
        glColor3ub(83,0,0);
        glVertex2f(0, -1);
        glVertex2f(4.0f, -1.0f);
        glVertex2f(4.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,4,0);
        glBegin(GL_QUADS);
        glColor3ub(83,0,0);
        glVertex2f(0, -1);
        glVertex2f(4.0f, -1.0f);
        glVertex2f(4.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glEnd();
        glPopMatrix();

        //!##############################lightBox
        glBegin(GL_POLYGON);
        glColor3d(1,1,1);
        glVertex2f(1, 12.0f);
        glVertex2f(2, 12.0f);
        glVertex2f(2, 13.0f);
        glVertex2f(1, 13.0f);
        glEnd();

        //!###############################light
        glPushMatrix();
        glTranslated(1.5, 12.5, 0);
        glRotatef(_rotateLight, 0.0f, 1.0f, 1.0f);   //!################light rotate

        //!###############################light1
        glBegin(GL_POLYGON);
        glColor3d(1,0,0);
        glVertex2f(0, 0);
        glVertex2f(10.0f, -2.0f);
        glVertex2f(10.0f, 2.0f);
        glEnd();

        //!###############################light2
        glBegin(GL_POLYGON);
        glColor3d(1,0,0);
        glVertex2f(0, 0);
        glVertex2f(-10.0f, -2.0f);
        glVertex2f(-10.0f, 2.0f);
        glEnd();

        glPopMatrix();//!rotate




        //!#################################helmet
        glBegin(GL_POLYGON);
        glColor3ub(0, 108, 54);
        glVertex2f(-1, 13.0f);
        glVertex2f(5.0f, 13.0f);
        glVertex2f(2.0f, 16.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(0, 13.0f);
        glVertex2f(0, 10.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(4, 13.0f);
        glVertex2f(4, 10.0f);
        glEnd();






        glPopMatrix(); //!scale

        glPopMatrix(); //!translate



}


void watchTower() //!akm_WT
{

        //!!#############################translate
        glPushMatrix();
        glTranslatef(-45, -15, 0);

        //!!####################scaling
        glPushMatrix();
        glScalef(2, 2, 0);

        //!############################body
        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 10.0f);
        glVertex2f(5.0f, 10.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 9.0f);
        glVertex2f(5.0f, 9.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 8.0f);
        glVertex2f(5.0f, 8.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 6.0f);
        glVertex2f(5.0f, 6.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 6.0f);
        glVertex2f(0.0f, 4.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(5.0f, 6.0f);
        glVertex2f(4.0f, 4.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(-1.0f, 6.0f);
        glVertex2f(5.0f, 6.0f);
        glVertex2f(5.0f, 6.0f);
        glVertex2f(5.0f, 10.0f);
        glVertex2f(5.0f, 10.0f);
        glVertex2f(-1.0f, 10.0f);
        glVertex2f(-1.0f, 10.0f);
        glVertex2f(-1.0f, 6.0f);
        glEnd();

        //!#####################################Main_body_Struct
        glBegin(GL_QUADS);
        glColor3ub(210,255,77);
        glVertex2f(0, -4.0f);
        glVertex2f(4.0f, -4.0f);
        glVertex2f(4.0f, 10.0f);
        glVertex2f(0.0f, 10.0f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(83,0,0);
        glVertex2f(0, -1);
        glVertex2f(4.0f, -1.0f);
        glVertex2f(4.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glEnd();

        glPushMatrix();
        glTranslatef(0,2,0);
        glBegin(GL_QUADS);
        glColor3ub(83,0,0);
        glVertex2f(0, -1);
        glVertex2f(4.0f, -1.0f);
        glVertex2f(4.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,4,0);
        glBegin(GL_QUADS);
        glColor3ub(83,0,0);
        glVertex2f(0, -1);
        glVertex2f(4.0f, -1.0f);
        glVertex2f(4.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glEnd();
        glPopMatrix();

        //!##############################lightBox
        glBegin(GL_POLYGON);
        glColor3d(1,1,1);
        glVertex2f(1, 12.0f);
        glVertex2f(2, 12.0f);
        glVertex2f(2, 13.0f);
        glVertex2f(1, 13.0f);
        glEnd();





        //!#################################helmet
        glBegin(GL_POLYGON);
        glColor3ub(0, 108, 54);
        glVertex2f(-1, 13.0f);
        glVertex2f(5.0f, 13.0f);
        glVertex2f(2.0f, 16.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(0, 13.0f);
        glVertex2f(0, 10.0f);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2f(4, 13.0f);
        glVertex2f(4, 10.0f);
        glEnd();






        glPopMatrix(); //!scale

        glPopMatrix(); //!translate



}




void rotateWT_light(int value)  //!akm_WT_anm
 {



    _rotateLight -= lightSpeed;

    if(_rotateLight < -360.0)
    {
        _rotateLight+=360;
    }

    glutPostRedisplay();



    glutTimerFunc(20, rotateWT_light, 0);
}




void truck00() //!akm_truck00
{
    //Car Moving-1
    glPushMatrix();
    glTranslatef(move_truck00,0.0,0.0);

    glColor3f(1.0f,0.30f,0.30f);//Front side
    glBegin(GL_POLYGON);
        glVertex2d(-21.0,-29.0);
        glVertex2d(-18.0,-29.0);
        glVertex2d(-17.0,-32.0);
        glVertex2d(-17.0,-37.0);
        glVertex2d(-21.0,-37.0);
    glEnd();
    glColor3f(0.94f,0.94f,0.94f);//Mirror
    glBegin(GL_QUADS);
        glVertex2d(-20.6,-29.6);
        glVertex2d(-18.2,-29.6);
        glVertex2d(-17.4,-32.0);
        glVertex2d(-20.6,-32.0);
    glEnd();

    glColor3f(1.0f,0.30f,0.30f);//Back Side
    glBegin(GL_QUADS);
        glVertex2d(-33.0,-35.0);
        glVertex2d(-21.0,-35.0);
        glVertex2d(-21.0,-37.0);
        glVertex2d(-33.0,-37.0);
    glEnd();
    glColor3f(0.0f,0.90f,0.30f);//Container
    glBegin(GL_QUADS);
        glVertex2d(-33.0,-29.0);
        glVertex2d(-21.5,-29.0);
        glVertex2d(-21.5,-35.0);
        glVertex2d(-33.0,-35.0);
    glEnd();
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex2d(-31.5,-29.0);
        glVertex2d(-31.5,-35.0);
        glVertex2d(-30.5,-29.0);
        glVertex2d(-30.5,-35.0);
        glVertex2d(-29.5,-29.0);
        glVertex2d(-29.5,-35.0);
        glVertex2d(-28.5,-29.0);
        glVertex2d(-28.5,-35.0);
        glVertex2d(-27.5,-29.0);
        glVertex2d(-27.5,-35.0);
        glVertex2d(-26.5,-29.0);
        glVertex2d(-26.5,-35.0);
        glVertex2d(-25.5,-29.0);
        glVertex2d(-25.5,-35.0);
        glVertex2d(-24.5,-29.0);
        glVertex2d(-24.5,-35.0);
        glVertex2d(-23.5,-29.0);
        glVertex2d(-23.5,-35.0);
        glVertex2d(-22.5,-29.0);
        glVertex2d(-22.5,-35.0);
    glEnd();

    glPushMatrix();//Chaka-1
    glTranslatef(-19.0,-36.5,0.0);
    glColor3f(0.34f,0.34f,0.34f);
    circle(1.2, 2.3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-19.0,-36.5,0.0);
    glColor3f(1.05f,1.05f,1.05f);
    circle(0.8,1.5);
    glPopMatrix();
    glPushMatrix();//Chaka-2
    glTranslatef(-31.0,-36.5,0.0);
    glColor3f(0.34f,0.34f,0.34f);
    circle(1.2,2.3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-31.0,-36.5,0.0);
    glColor3f(1.05f,1.05f,1.05f);
    circle(0.8,1.5);
    glPopMatrix();

    glPopMatrix();

    //Car Moving-1 End


}


void truck01()  //!akm_truck01
{
        //Car Moving-2
    glPushMatrix();
    glTranslatef(move_truck01,0.0,0.0);
    glColor3f(1.0f,0.30f,0.0f);//Front side
    glBegin(GL_POLYGON);
    glVertex2d(18.0,-37.0);
    glVertex2d(21.0,-37.0);
    glVertex2d(21.0,-45.0);
    glVertex2d(17.0,-45.0);
    glVertex2d(17.0,-40.0);
    glEnd();

    glColor3f(0.94f,0.94f,0.94f);//Mirror
    glBegin(GL_QUADS);
    glVertex2d(18.2,-37.6);
    glVertex2d(20.6,-37.6);
    glVertex2d(20.6,-40.0);
    glVertex2d(17.4,-40.0);
    glEnd();

    glColor3f(1.0f,0.30f,0.0f);//Back Side
    glBegin(GL_QUADS);
    glVertex2d(21.0,-43.0);
    glVertex2d(32.0,-43.0);
    glVertex2d(32.0,-45.0);
    glVertex2d(21.0,-45.0);
    glEnd();

    glColor3f(0.30f,0.58f,1.0f);//Container
    glBegin(GL_QUADS);
    glVertex2d(21.5,-37.0);
    glVertex2d(32.0,-37.0);
    glVertex2d(32.0,-43.0);
    glVertex2d(21.5,-43.0);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex2d(22.0,-37.0);
        glVertex2d(22.0,-43.0);
        glVertex2d(23.0,-37.0);
        glVertex2d(23.0,-43.0);
        glVertex2d(24.0,-37.0);
        glVertex2d(24.0,-43.0);
        glVertex2d(25.0,-37.0);
        glVertex2d(25.0,-43.0);
        glVertex2d(26.0,-37.0);
        glVertex2d(26.0,-43.0);
        glVertex2d(27.0,-37.0);
        glVertex2d(27.0,-43.0);
        glVertex2d(28.0,-37.0);
        glVertex2d(28.0,-43.0);
        glVertex2d(29.0,-37.0);
        glVertex2d(29.0,-43.0);
        glVertex2d(30.0,-37.0);
        glVertex2d(30.0,-43.0);
        glVertex2d(31.0,-37.0);
        glVertex2d(31.0,-43.0);
    glEnd();

    glPushMatrix();//Chaka-1
    glTranslatef(19.0,-44.5,0.0);
    glColor3f(0.34f,0.34f,0.34f);
    circle(1.2,2.3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(19.0,-44.5,0.0);
    glColor3f(1.05f,1.05f,1.05f);
    circle(0.8,1.5);
    glPopMatrix();

    glPushMatrix();//Chaka-2
    glTranslatef(30.0,-44.5,0.0);
    glColor3f(0.34f,0.34f,0.34f);
    circle(1.2,2.3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30.0,-44.5,0.0);
    glColor3f(1.05f,1.05f,1.05f);
    circle(0.8,1.5);
    glPopMatrix();

    glPopMatrix();
    //Car Moving-2 End

}



void update_truck00(int value)  //!akm_truck00_anm
{

    if(move_truck00 > 75)
    {
        move_truck00 = -55;
    }

    move_truck00 += Truckspeed00;
    glutPostRedisplay();

	glutTimerFunc(20, update_truck00, 0);

}

void update_truck01(int value)  //!akm_truck01_anm
{

    if(move_truck01 < -75)
    {
        move_truck01 = 55;
    }

	        move_truck01 -= Truckspeed01;
    glutPostRedisplay();

	glutTimerFunc(20, update_truck01, 0);

}


void lightHouse_Night() //!akm_lightHouse_night
{
    glPushMatrix();  //!scaling
    glTranslated(-40, 21.5, 0);
    glScalef(1.5,1.5,0);

    glPushMatrix(); //!light_reftect
    glTranslatef(0, 13, 0);
    glColor3ub(240,250,210);
    circle(3.5, 3.5);
    glPopMatrix();

    glBegin(GL_POLYGON); //!################pillar
    glColor3ub(250, 249, 246);
    glVertex2f(-2, 0);
    glVertex2f(2, 0);
    glVertex2f(1.5, 10);
    glVertex2f(-1.5, 10);
    glEnd();

    glBegin(GL_POLYGON);    //!################pillar_shade_half
    glColor3ub(255, 255, 255);
    glVertex2f(-2, 0);
    glVertex2f(0, 0);
    glVertex2f(0, 10);
    glVertex2f(-1, 10);
    glEnd();

    glBegin(GL_POLYGON);    //!################upperB
    glColor3ub(150, 0, 0);
    glVertex2f(-1.5, 10);
    glVertex2f(1.5, 10);
    glVertex2f(1.5, 14);
    glVertex2f(-1.5, 14);
    glEnd();

    glBegin(GL_POLYGON); //!################Divider
    glColor3ub(0, 0, 0);
    glVertex2f(-2, 10);
    glVertex2f(2, 10);
    glVertex2f(2, 11);
    glVertex2f(-2, 11);
    glEnd();

    glBegin(GL_POLYGON); //!################helmet
    glColor3ub(0, 0, 0);
    glVertex2f(-2, 14);
    glVertex2f(2, 14);
    glVertex2f(0, 16);
    glEnd();

    glBegin(GL_POLYGON);    //!################lightBox
    glColor3ub(0, 0, 0);
    glVertex2f(-.5, 10);
    glVertex2f(.5, 10);
    glVertex2f(.5, 14);
    glVertex2f(-.5, 14);
    glEnd();

    glPushMatrix(); //!light
    glTranslatef(0, 12.5, 0);
    glColor3ub(245, 245, 164);
    circle(.5, .5);
    glPopMatrix();

    glPushMatrix();
    glRotatef(_rotateLight, 0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);    //!################light_shade
    glColor3ub(245, 245, 164);
    glVertex2f(15, 10);
    glVertex2f(1.5, 12);
    glVertex2f(1.5, 13);
    glVertex2f(15, 15);
    glEnd();
    glPopMatrix();

    glBegin(GL_POLYGON);    //!################stand
    glColor3ub(0, 0, 0);
    glVertex2f(-3, -1);
    glVertex2f(3, -1);
    glVertex2f(2, 0);
    glVertex2f(-2, 0);
    glEnd();


    glPopMatrix(); //!scaling






}

void lightHouse() //!akm_lightHouse
{
    glPushMatrix();  //!scaling
    glTranslated(-40, 21.5, 0);
    glScalef(1.5,1.5,0);


    glBegin(GL_POLYGON); //!################pillar
    glColor3ub(250, 249, 246);
    glVertex2f(-2, 0);
    glVertex2f(2, 0);
    glVertex2f(1.5, 10);
    glVertex2f(-1.5, 10);
    glEnd();

    glBegin(GL_POLYGON);    //!################pillar_shade_half
    glColor3ub(255, 255, 255);
    glVertex2f(-2, 0);
    glVertex2f(0, 0);
    glVertex2f(0, 10);
    glVertex2f(-1, 10);
    glEnd();

    glBegin(GL_POLYGON);    //!################upperB
    glColor3ub(150, 0, 0);
    glVertex2f(-1.5, 10);
    glVertex2f(1.5, 10);
    glVertex2f(1.5, 14);
    glVertex2f(-1.5, 14);
    glEnd();

    glBegin(GL_POLYGON); //!################Divider
    glColor3ub(0, 0, 0);
    glVertex2f(-2, 10);
    glVertex2f(2, 10);
    glVertex2f(2, 11);
    glVertex2f(-2, 11);
    glEnd();

    glBegin(GL_POLYGON); //!################helmet
    glColor3ub(0, 0, 0);
    glVertex2f(-2, 14);
    glVertex2f(2, 14);
    glVertex2f(0, 16);
    glEnd();

    glBegin(GL_POLYGON);    //!################lightBox
    glColor3ub(0, 0, 0);
    glVertex2f(-.5, 10);
    glVertex2f(.5, 10);
    glVertex2f(.5, 14);
    glVertex2f(-.5, 14);
    glEnd();

    glPushMatrix(); //!light
    glTranslatef(0, 12.5, 0);
    glColor3ub(245, 245, 164);
    circle(.5, .5);
    glPopMatrix();


    glBegin(GL_POLYGON);    //!################stand
    glColor3ub(0, 0, 0);
    glVertex2f(-3, -1);
    glVertex2f(3, -1);
    glVertex2f(2, 0);
    glVertex2f(-2, 0);
    glEnd();


    glPopMatrix(); //!scaling






}


void rotateLH_light(int value)  //!akm_LightHouse_anm
 {



    _rotateLight -= lightSpeed;

    if(_rotateLight < -360.0)
    {
        _rotateLight+=360;
    }

    glutPostRedisplay();



    glutTimerFunc(20, rotateLH_light, 0);
}


void tree()

{


glBegin(GL_QUADS);
glColor3ub(143,47,9);
glVertex2f(0.38f, 0.3f);
glVertex2f(0.38f, 0.4f);
glVertex2f(0.4f, 0.4f);
glVertex2f(0.4f, 0.3f);
glEnd();
glBegin(GL_QUADS);
glColor3ub(9,103,53);
 glVertex2f(0.44f, 0.4f);
glVertex2f(0.41f, 0.45f);
glVertex2f(0.38f, 0.45f);
glVertex2f(0.35f, 0.4f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(113,206,24);
glVertex2f(0.445f, 0.42f);
glVertex2f(0.395f, 0.52f);
glVertex2f(0.34f, 0.42f);
glEnd();
}

void bird()
{
glPushMatrix();
glTranslatef(position2,0.0f, 0.0f);
glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(0.27f,0.64f);// 1st
glVertex2f(0.30f,0.63f);
glVertex2f(0.30f,0.63f);
glVertex2f(0.29f,0.62f);
glVertex2f(0.29f,0.62f);
glVertex2f(0.29f,0.62f);
glVertex2f(0.28f,0.61f);
glVertex2f(0.28f,0.60f);
glVertex2f(0.27f,0.62f);
glVertex2f(0.26f,0.62f);
glVertex2f(0.26f,0.62f);
glVertex2f(0.26f,0.63f);
glVertex2f(0.27f,0.64f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(0.29f,0.44f);// 2nd
glVertex2f(0.32f,0.43f);
glVertex2f(0.33f,0.43f);
glVertex2f(0.32f,0.42f);
glVertex2f(0.313f,0.422f);
glVertex2f(0.315f,0.414f);
glVertex2f(0.31f,0.40f);
glVertex2f(0.308f,0.417f);
glVertex2f(0.295f,0.414f);
glVertex2f(0.29f,0.422f);
glVertex2f(0.28f,0.43f);
glVertex2f(0.28f,0.431f);
glVertex2f(0.29f,0.43f);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(0.37f,0.517f);// 3rd
glVertex2f(0.39f,0.505f);
glVertex2f(0.405f,0.497f);
glVertex2f(0.39f,0.4914f);
glVertex2f(0.39f,0.494f);
glVertex2f(0.39f,0.488f);
glVertex2f(0.385f,0.488f);
glVertex2f(0.38f,0.48f);
glVertex2f(0.37f,0.494f);
glVertex2f(0.36f,0.4914f);
glVertex2f(0.366f,0.5f);
glVertex2f(0.363f,0.511f);
glVertex2f(0.37f,0.511f);
glEnd();
glPopMatrix();
}

void update2(int value) {
if(position2 < -1.0)
position2 = 0.7f;
position2 -= speed2;
glutPostRedisplay();
glutTimerFunc(100, update2, 0);
}


void toggledisplay() {

glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);

glColor3ub(243, 213, 120);
land02();
glColor3ub(0,157,196);
ocean02();
glColor3ub(135,206,235);
sky02();



sun();

cloud();
cloud2();
cloud3();


//!###########################end of cloud----------------------

glPushMatrix();
glTranslatef(80, -10, 0);
lightHouse();
glPopMatrix();


//!###########################hill
glPushMatrix();
glTranslatef(0, -10, 0);
hill();
glPopMatrix();

glPushMatrix();
glTranslatef(5, -10, 0);
hill();
glPopMatrix();

glPushMatrix();
glTranslatef(15, -10, 0);
hill();
glPopMatrix();


glPushMatrix();
glTranslatef(90, -10, 0);
hill();
glPopMatrix();

glPushMatrix();
glTranslatef(85, -10, 0);
hill();
glPopMatrix();
//!###########################end of hill




//!###########################tide


    glPushMatrix();
    glTranslatef(7, -35, 0);
    tide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7, -46, 0);
    tide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-37, -30, 0);
    tide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-27, -38, 0);
    tide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(27, -34, 0);
    tide();
    glPopMatrix();



//!###########################end tide



glPushMatrix();
glScalef(1, .65, 0);
glTranslatef(0, 28, 0);
building();
//batmanLogo();
glPopMatrix();
//!##############################end of hotel

glPushMatrix();
glScalef(.65, 1, 0);
glTranslatef(-75, 22, 0);
netTower();
glPopMatrix();

glPushMatrix();
glScalef(1, .6, 0);
glTranslatef(0, 50, 0);
road();
truck00();
truck01();
glPopMatrix();
//!#######################################end of car_Road

glPushMatrix();
glTranslatef(0, 25, 0);
Umbrella();
Seat();
glPopMatrix();

glPushMatrix();
glTranslatef(-20, 30, 0);
Umbrella();
Seat();
glPopMatrix();

glPushMatrix();
glTranslatef(20, 25, 0);
Umbrella();
Seat();
glPopMatrix();

glPushMatrix();
glTranslatef(25, -20, 0);

glScalef(46, 46, 0);
crab();
glPopMatrix();
//!!!!!###################umbrelaaaaaaaa_SEAT_CRAB

glPushMatrix();
glScalef(45, 45, 0);
bird();
glPopMatrix();
//!##############################bird


glutTimerFunc(3600, displayHotel_Night, 0);
glutSwapBuffers();
glFlush();

}


void displayHotel(int val)
{
    glutDisplayFunc(toggledisplay);//inside the bracket this a function, which will be display
	//so make a function of this
}

void toggledisplay_Night() {

glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);


glColor3ub(167, 148, 122);
land02();
glColor3ub(42, 49, 149);
ocean02();
glColor3ub(42,42,53);
sky02();

    glPushMatrix();//!##########################moon
    glTranslatef(20, 35, 0);
    glScalef(0.5, 0.5, 0);
    circle();
    glPopMatrix();

//!##############################star
    glPushMatrix();
    glTranslatef(-10, 35, 0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3, 38, 0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10, 35, 0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15, 30, 0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-30, 35, 0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10, 28, 0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(20, 25, 0);
    star();
    glPopMatrix();
    //!##############################starEnds

glPushMatrix();
glTranslatef(80, -10, 0);
lightHouse_Night();
glPopMatrix();


//!###########################hill
glPushMatrix();
glTranslatef(0, -10, 0);
hill();
glPopMatrix();

glPushMatrix();
glTranslatef(5, -10, 0);
hill();
glPopMatrix();

glPushMatrix();
glTranslatef(15, -10, 0);
hill();
glPopMatrix();


glPushMatrix();
glTranslatef(90, -10, 0);
hill();
glPopMatrix();

glPushMatrix();
glTranslatef(85, -10, 0);
hill();
glPopMatrix();
//!###########################end of hill




//!###########################tide


    glPushMatrix();
    glTranslatef(7, -35, 0);
    tideNight();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7, -46, 0);
    tideNight();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-37, -30, 0);
    tideNight();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-27, -38, 0);
    tideNight();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(27, -34, 0);
    tideNight();
    glPopMatrix();



//!###########################end tide


glPushMatrix();
glScalef(1, .65, 0);
glTranslatef(0, 28, 0);
building();
batmanLogo();
glPopMatrix();
//!##############################end of hotel
glPushMatrix();
glScalef(.65, 1, 0);
glTranslatef(-75, 22, 0);
netTower();
glPopMatrix();

glPushMatrix();
glScalef(1, .6, 0);
glTranslatef(0, 50, 0);
road();
glPopMatrix();
//!#######################################end of car_Road


glPushMatrix();
glTranslatef(0, 25, 0);
Umbrella();
Seat();
glPopMatrix();

glPushMatrix();
glTranslatef(-20, 30, 0);
Umbrella();
Seat();
glPopMatrix();

glPushMatrix();
glTranslatef(20, 25, 0);
Umbrella();
Seat();
glPopMatrix();

//!!!!!###################umbrelaaaaaaaa_SEAT

glPushMatrix();
glTranslatef(0, -33, 0);
boat();
glPopMatrix();

glPushMatrix();
glTranslatef(-10, -20, 0);
glScalef(40, 30, 0);
flagship();
glPopMatrix();



glutSwapBuffers();
glFlush();

}


void displayHotel_Night(int val)
{
    glutDisplayFunc(toggledisplay_Night);//inside the bracket this a function, which will be display
	//so make a function of this
}





void night()//!############################################################################################
{

    glColor3ub(42,42,53);
    sky();

    glColor3ub(42, 49, 149);
    ocean();

    glColor3ub(167, 148, 122);
    sand();

    road();

    glPushMatrix();//!##########################moon
    glTranslatef(20, 35, 0);
    glScalef(0.5, 0.5, 0);
    circle();
    glPopMatrix();

//!##############################star
    glPushMatrix();
    glTranslatef(-10, 35, 0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3, 38, 0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10, 35, 0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15, 30, 0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-30, 35, 0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10, 28, 0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(20, 25, 0);
    star();
    glPopMatrix();
    //!##############################starEnds

//!###########################tide

    tideNight();

    glPushMatrix();
    glTranslatef(7, 5, 0);
    tideNight();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7, 8, 0);
    tideNight();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-37, 10, 0);
    tideNight();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-27, 18, 0);
    tideNight();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(27, 14, 0);
    tideNight();
    glPopMatrix();



//!###########################end tide
//!###########################umbrella, seat, tree, crabs

glPushMatrix();
glTranslatef(0, 20, 0);
Umbrella();
Seat();
glPopMatrix();

glPushMatrix();
glTranslatef(-20, 15, 0);
Umbrella();
Seat();
glPopMatrix();

glPushMatrix();
glTranslatef(20, 15, 0);
Umbrella();
Seat();
glPopMatrix();

glPushMatrix();
glTranslatef(10, -55, 0);
glScalef(100, 100, 0);
tree();
glPopMatrix();

//!###########################umbrella, seat, tree, crabs-----ends
glPushMatrix();
glTranslatef(-10, 28, 0);
glScalef(15, 10, 0);
flagship();
glPopMatrix();


cargoShip_night();  boat();
lightHouse_Night();hill(); watchTower_Night();


glPopMatrix();
glutSwapBuffers();


}



void displayNight(int val)
{
    glutDisplayFunc(night);//inside the bracket this a function, which will be display
	//so make a function of this
}



void display()
{

glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);

road();

glColor3ub(243, 213, 120);
sand();

glColor3ub(0,157,196);
ocean();


//!###########################tide

    tide();

    glPushMatrix();
    glTranslatef(7, 5, 0);
    tide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7, 8, 0);
    tide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-37, 10, 0);
    tide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-27, 18, 0);
    tide();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(27, 14, 0);
    tide();
    glPopMatrix();



//!###########################end tide

glColor3ub(135,206,235);
sky();

sun();


cloud();
cloud2();
cloud3();


bannerPlane();

lightHouse();
//!#########################raj
 hill();

glPushMatrix();
glTranslatef(-20, 29, 0);
glScalef(15, 10, 0);
flagship();
glPopMatrix();

cargoShip_01();
cargoShip_02();

watchTower();


//!###########################umbrella, seat, tree, crabs

glPushMatrix();
glTranslatef(0, 20, 0);
Umbrella();
Seat();
glPopMatrix();

glPushMatrix();
glTranslatef(-20, 15, 0);
Umbrella();
Seat();
glPopMatrix();

glPushMatrix();
glTranslatef(20, 15, 0);
Umbrella();
Seat();
glPopMatrix();

glPushMatrix();
glTranslatef(25, -20, 0);
glScalef(46, 46, 0);
crab();
glPopMatrix();

glPushMatrix();
glTranslatef(10, -55, 0);
glScalef(100, 100, 0);
tree();
glPopMatrix();

//!###########################umbrella, seat, tree, crabs-----ends





truck00();
truck01();
//glutTimerFunc(3600, displayHotel, 0);
glutSwapBuffers();
glFlush();

}

void display(int val) //call it from the keyBoard or mouse handle
{
    glutDisplayFunc(display);//inside the bracket this a function, which will be display
	//so make a function of this
}



void SpecialInput(int key, int x, int y)
{
switch(key)
{
case GLUT_KEY_UP:
            glutTimerFunc( 1, displayNight, 0);
            break;
case GLUT_KEY_DOWN:
            glutTimerFunc( 1, display, 0);
            break;
case GLUT_KEY_LEFT:
            glutTimerFunc( 1, displayHotel, 0);
            break;
case GLUT_KEY_RIGHT:
            glutTimerFunc( 1, displayHotel_Night, 0);
            break;
}
glutPostRedisplay();
}


void control(unsigned char key, int x, int y) {
switch (key) {

//!###########################################################Ship
case 'q':           Shipspeed00=0;   break;
case 'w':           Shipspeed01=0;   break;

case 'e':           Shipspeed00=0.4;   break;
case 'r':           Shipspeed01=0.4;   break;

case 't':           Shipspeed00+=0.4;   break;
case 'y':           Shipspeed01+=0.4;   break;

case 'u':           Shipspeed00-=0.4;   break;
case 'i':           Shipspeed01-=0.4;   break;
//!###########################################################truck
case '1':           Truckspeed00=0;   break;
case '2':           Truckspeed01=0;   break;

case '3':           Truckspeed00=0.4;   break;
case '4':           Truckspeed01=0.4;   break;

case '5':           Truckspeed00+=0.4;   break;
case '6':           Truckspeed01+=0.4;   break;

case '7':           Truckspeed00-=0.4;   break;
case '8':           Truckspeed01-=0.4;   break;
//!###########################################################plane
case 'Q':           Planespeed+=0.4;   break;
case 'W':           Planespeed-=0.4;   break;

//!###########################################################light
case 'Z':           lightSpeed=0;   break;
case 'X':           lightSpeed=0.4;   break;

case 'C':           lightSpeed+=0.4;   break;
case 'V':           lightSpeed-=0.4;   break;

}     glutPostRedisplay();

}




void init()
{
    glLoadIdentity();
    gluOrtho2D(-50,50,-50,50);
}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    	glutInitWindowSize(850, 650);
    	glutCreateWindow("Sea Beach View From Hotel");

    	init(); //ortho2d

	glutDisplayFunc(display);



	glutTimerFunc(20, move_cargoShip_01, 0);
	glutTimerFunc(20, move_cargoShip_02, 0);
	glutTimerFunc(20, moveBannerPlane, 0);
    glutTimerFunc(20, rotateWT_light, 0);
    glutTimerFunc(20, update_truck00, 0);
    glutTimerFunc(20, update_truck01, 0);
    glutTimerFunc(20, rotateLH_light, 0);
    glutTimerFunc(20, updateBat, 0);
    glutTimerFunc(100, update2, 0);
    glutTimerFunc(100, update, 0);



    glutKeyboardFunc(control);

    glutSpecialFunc(SpecialInput);




	glutMainLoop();
	return 0;
}






