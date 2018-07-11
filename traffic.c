#include<stdio.h>
#include<GL/glut.h>
#define SPEED 0.1
GLfloat mat_ambient[]= {0.7,0.7,0.7,1.0};
GLfloat mat_diffuse[]={0.8,0.8,0.8,1.0};
GLfloat mat_specular[]= {1.0,1.0,1.0,1.0};
GLfloat mat_shininess[]= {50.0};
GLfloat lightintensity[]= {0.8,0.8,0.8,1.0};
GLfloat lightposition[]= {2.0,-2.0,-6.0,0.0};
int stop=0;
int flag=0;
float i=0.0;
float j=0.0;
float k=0.0;
float l=0.0;
int day=0;
int case4=0,case5=0,case6=0,case7=0;
int light = 1;
int index=0;
int move=0;
int check=0;
void road();
void windmill();
void signal();
void display();
void idle();
void checksignal();
void crossing();
void keyboardFunc( unsigned char key, int x, int y );
void myReshape();
void choicemenu();
void manleg1(float k);
void manleg2(float k);
void manbody(float k);
void manhead(float k);
void light1();
void light2();
void light3();
void car1();
void car2();
void car22();
void wheel1();
void wheel2();
void wheel3();
void wheel4();
void wheel5();
void wheel6();
void wheel7();
void wheel8();
void ground();
void yellowrod1();
void yellowrod2();
void yellowwindow();
void redwindow1();
void redwindow2();
void redrod();
void sun();
void moon();
void daynightColor();
void checkcolorcar1();
void checkcolorcar2();
void checkcolorbus();
void frontscreen();
void myDisplay();
void drawstring(float x,float y,float z,char *s);
GLfloat red=0,blue=1,green=.3;


void myinit()
{
glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
glLightfv(GL_LIGHT0,GL_POSITION,lightposition);
glLightfv(GL_LIGHT0,GL_DIFFUSE,lightintensity);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-3.0,3.0,-3.0,3.0,-10.0,10.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

gluLookAt(2.0,1.0,1.0,0.0,0.2,0.2,0.0,1.0,0.0);
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

int main(int argc, char* argv[])
{
int ch_menu,submenu1,submenu2;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glEnable(GL_DEPTH_TEST);
glEnable(GL_COLOR_MATERIAL);
glutCreateWindow("Traffic signal");
glClearColor(0.0,1.0,1.0,1.0);
glViewport(0,0,1000,1000);
glutReshapeFunc(myReshape);
glutDisplayFunc(myDisplay);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_COLOR_MATERIAL);
glShadeModel(GL_SMOOTH);
glEnable(GL_NORMALIZE);
glutIdleFunc(idle);
glutKeyboardFunc(keyboardFunc);
myinit();
submenu1=glutCreateMenu(choicemenu);
glutAddMenuEntry("Red",4);
glutAddMenuEntry("Green",5);
submenu2=glutCreateMenu(choicemenu);
glutAddMenuEntry("Red And Blue",6);
glutAddMenuEntry("Green And Red",7);
ch_menu=glutCreateMenu(choicemenu);
	glutAddMenuEntry("Man Crossing",1);
	glutAddMenuEntry("Day",2);
	glutAddMenuEntry("Night",3);
	glutAddSubMenu("Bus color",submenu1);
	glutAddSubMenu("Car color",submenu2);
	glutAddMenuEntry("Quit",8);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutPostRedisplay();
    glutMainLoop();
}
void drawstring(float x,float y,float z,char *s)
{
	int i;
	glRasterPos3f(x,y,z);
    glColor3f(0.0,1.0,0.0);
	for(i=0;s[i]!='\0';i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
	}
}
void frontscreen(void)
{

glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
drawstring(-2.5,1.2,1.5,"CGV PROJECT ON \"TRAFFIC SIGNAL\" ");
drawstring(-2.5,1.0,1.5,"BY VANDANA R USN-1BI15CS179 AND");
drawstring(-2.5,0.8,1.5,"SWETHA S USN-1BI15CS190");
drawstring(-2.5,0.6,1.5,"D3 BATCH");
drawstring(-2.5,0.4,1.5,"DEPARTMENT OF CSE,BIT ");
drawstring(-2.5,0.0,1.5,"TIPS:");
drawstring(-2.5,-0.2,1.5,"PRESS \'r\' FOR RED SIGNAL");
drawstring(-2.5,-0.4,1.5,"PRESS \'g\' FOR GREEN SIGNAL");
drawstring(-2.5,-0.6,1.5,"RIGHT CLICK MOUSE FOR MENUS");
drawstring(-2.5,-0.8,1.5,"PRESS ENTER TO START");
glFlush();
}

void keyboardFunc( unsigned char key, int x, int y )
{
switch( key )
    {

case 13:
    flag=1;
    break;
case 'g':
case 'G':
light=1;
break;

case 'r':
case 'R':
light=0;
break;
    }

}
void choicemenu(int index)
{
	switch(index)
	{
	case 1:
	    if(index==1)
            move=1;
        else move=2;

	break;

	case 2:
        day =0;
        break;

    case 3:
        day = 1;
        break;

    case 4:
        case4=1;
        check=1;
        break;

    case 5:
        case5=1;
        check=2;
        break;

    case 6:
        case6=1;
        check=3;
        break;

    case 7:
        case7=1;
        check=4;
        break;

    case 8:
        exit(0);


	}
}
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    if(flag==0)
        frontscreen();
    if(flag==1)
        display();
    glFlush();
    glutSwapBuffers();
}

void display(void)
{
    glClearColor(0.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    daynightColor();
    glColor3f(0.5,0.5,0.5);
    road();
    glColor3f(1.0,1.0,1.0);
    crossing();
    glColor3f(0.0,0.0,1.0);
    signal();
    glColor3f(0.0,0.0,0.0);
    light1();
    glColor3f(1.0,0.5,0.0);
    light2();
    glColor3f(0.0,0.0,0.0);
    light3();
    glColor3f(0.0,0.0,0.0);
    wheel3();
    wheel4();
    wheel7();
   wheel8();
   glColor3f(1.0,1.0,0.0);
    car1();
    checkcolorbus();
    glColor3f(0.0,0.0,1.0);
    car2();
    checkcolorcar1();
    glColor3f(0.9,0.0,0.0);
    car22();
    glColor3f(0.0,0.0,0.0);
    checkcolorcar2();
    glColor3f(0.0,0.0,0.0);
    wheel1();
    wheel2();
    wheel5();
    wheel6();
   yellowrod1();
   yellowrod2();
   glColor3f(1.0,1.0,1.0);
   yellowwindow();
   glColor3f(0.0,1.0,0.0);
   ground();
   //glColor3f(1.0,0.5,0.0);
   //sun();
   //glColor3f(0.9,0.91,0.98);
 // moon();
 glColor3f(1.0,1.0,0.0);
   redwindow1();
   glColor3f(1.0,1.0,0.0);
   redwindow2();
    glColor3f(0.0,0.0,0.0);
   redrod();
   checksignal();
   glColor3f(0.7,0.0,0.0);
	 if(move==2&& stop==1)
	 {

	 }
	  else if(move==2)
     {
      glColor3f(0.7,0.0,0.0);
        float r=0.0;
         manleg1(r);
        manleg2(r);
        manbody(r);
        manhead(r);
     }
	 else if(move==1)
     {
        manleg1(k);
        manleg2(k);
        manbody(k);
        manhead(k);
     }
    glFlush();

}
void checkcolorbus()
{
if(case4&&check==1)
    {

    glColor3f(1.0,0.0,0.0);
    car1();

    }
else if(case5&&check==2)
    {

       glColor3f(0.0,1.0,0.0);
        car1();

    }
}
void checkcolorcar1()
{
    if(case6&&check==3)
    {
       glColor3f(1.0,0.0,0.0);
        car2();

    }
    else if(case7&&check==4)
    {
       glColor3f(0.0,1.0,0.0);
        car2();

    }
}
void checkcolorcar2()
{
    if(case6&&check==3)
    {
       glColor3f(0.0,0.0,1.0);
        car22();

    }
   else if(case7&&check==4)
    {
        glColor3f(1.0,0.0,0.0);
        car22();

    }
}
void daynightColor()
{
    if(day==0)
    {
    glClearColor(0.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0,0.5,0.0);
    sun();
    }
    if(day)
    {
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0.9,0.91,0.98);
    moon();
    }
}

void manleg1(float k)
{

glPushMatrix();
glTranslated(1.5+k,-0.515625,-2.2);
glScaled(1.0,1.6875,0.5);
glutSolidCube(0.1);
glPopMatrix();

}
void manleg2(float k)
{
glPushMatrix();
glTranslated(1.5+k,-0.515625,-2.3);
glScaled(1.0,1.6875,0.5);
glutSolidCube(0.1);
glPopMatrix();
}

void manbody(float k)
{
glPushMatrix();
glTranslated(1.5+k,-0.346875,-2.25);
glScaled(1.0,1.6875,2.0);
glutSolidCube(0.1);
glPopMatrix();
}
void manhead(float k)
{
glPushMatrix();
glTranslated(1.5+k,-0.20625,-2.25);
glScaled(0.5625,0.5625,0.5625);
glutSolidSphere( 0.1, 20, 20 );
glPopMatrix();
}
void crossing()
{
glPushMatrix();
glTranslated(0.0,-0.6,-2.1);
glScaled(30.0,0.1,3.0);
glutSolidCube(0.1);
glPopMatrix();

}
void ground()
{
glPushMatrix();

glTranslated(3.25,-0.6,0.0);
glScaled(35.0,0.1,200.0);
glutSolidCube(0.1);
glPopMatrix();
}

void road()
{
glPushMatrix();
glTranslated(0.0,-0.6,0.0);
glScaled(30.0,0.1,200.0);
glutSolidCube(0.1);
glPopMatrix();
}

void signal()
{
glPushMatrix();
glTranslated(-1.5,0.4,-2.0);
glScaled(1.0,20,1.0);
glutSolidCube(0.1);
glPopMatrix();


}
void light1()
{
glPushMatrix();
glTranslated(-1.5, 1.3,-2.0);
glutSolidSphere( 0.1, 20, 20 );
glPopMatrix();
}

void light2()
{
glPushMatrix();
glTranslated(-1.5,1.1,-2.0);
glutSolidSphere( 0.1, 20, 20 );
glPopMatrix();

}
void light3()
{
glPushMatrix();
glTranslated(-1.5,0.9,-2.0);
glutSolidSphere( 0.1, 20, 20 );
glPopMatrix();

}
void car1()
{
glPushMatrix();
glTranslated(-0.5,-0.15,0.2+i);
glScaled(6.0,7.0,15.0);
glutSolidCube(0.1);
glPopMatrix();

}
void car2()
{
glPushMatrix();
glTranslated(-0.5,-0.4,2.2+j);
glScaled(6.0,2.0,8.0);
glutSolidCube(0.1);
glPopMatrix();

}

void car22()
{
glPushMatrix();
glTranslated(-0.5,-0.225,2.2+j);
glScaled(6.0,1.5,5.0);
glutSolidCube(0.1);
glPopMatrix();

}

void wheel1()
{
glPushMatrix();
glTranslated(-0.16,-0.45,0.7+i);
glRotated(90.0,0.0,1.0,0.0);
glScaled(0.5,0.5,0.5);
glutSolidTorus(0.1,0.2,10,10);
glPopMatrix();

}

void wheel2()
{
glPushMatrix();
glTranslated(-0.16,-0.45,-0.2+i);
glRotated(90.0,0.0,1.0,0.0);
glScaled(0.5,0.5,0.5);
glutSolidTorus(0.1,0.2,10,10);
glPopMatrix();

}

void wheel3()
{
glPushMatrix();
glTranslated(-0.84,-0.45,0.7+i);
glRotated(90.0,0.0,1.0,0.0);
glScaled(0.5,0.5,0.5);
glutSolidTorus(0.1,0.2,10,10);
glPopMatrix();

}

void wheel4()
{
glPushMatrix();
glTranslated(-0.84,-0.45,-0.2+i);
glRotated(90.0,0.0,1.0,0.0);
glScaled(0.5,0.5,0.5);
glutSolidTorus(0.1,0.2,10,10);
glPopMatrix();

}
void wheel5()
{
glPushMatrix();
glTranslated(-0.16,-0.48,2.0+j);
glRotated(90.0,0.0,1.0,0.0);
glScaled(0.4,0.4,0.4);
glutSolidTorus(0.1,0.2,10,10);
glPopMatrix();

}
void wheel6()
{
glPushMatrix();
glTranslated(-0.16,-0.48,2.4+j);
glRotated(90.0,0.0,1.0,0.0);
glScaled(0.4,0.4,0.4);
glutSolidTorus(0.1,0.2,10,10);
glPopMatrix();

}
void wheel7()
{
glPushMatrix();
glTranslated(-0.84,-0.48,2.0+j);
glRotated(90.0,0.0,1.0,0.0);
glScaled(0.4,0.4,0.4);
glutSolidTorus(0.1,0.2,10,10);
glPopMatrix();
}
void wheel8()
{
glPushMatrix();
glTranslated(-0.84,-0.48,2.4+j);
glRotated(90.0,0.0,1.0,0.0);
glScaled(0.4,0.4,0.4);
glutSolidTorus(0.1,0.2,10,10);
glPopMatrix();
}
void yellowrod1()
{
glPushMatrix();
glTranslated(-0.1875,-0.15,0.2+i);
glScaled(1.0,1.0,60.0);
glutSolidCube(0.025);
glPopMatrix();

}
void yellowrod2()
{
glPushMatrix();
glTranslated(-0.5,-0.15,0.95+i);
glScaled(24.0,1.0,1.0);
glutSolidCube(0.025);
glPopMatrix();
}
void yellowwindow()
{
glPushMatrix();
glTranslated(-0.1875,0.05,-0.25+i);
glScaled(1.0,9.0,15);
glutSolidCube(0.025);
glPopMatrix();

}

redwindow1()
{
glPushMatrix();
glTranslated(-0.1875,-0.23,2.07+j);
glScaled(1.0,4.0,8);
glutSolidCube(0.025);
glPopMatrix();

}
redwindow2()
{
glPushMatrix();
glTranslated(-0.1875,-0.23,2.35+j);
glScaled(1.0,4.0,8);
glutSolidCube(0.025);
glPopMatrix();

}
redrod()
{
glPushMatrix();
glTranslated(-0.1875,-0.4,2.2+j);
glScaled(1.0,8.0,1.0);
glutSolidCube(0.025);
glPopMatrix();
}

void sun()
{
glPushMatrix();
glTranslated(1.0,2.2,2.5);
glutSolidSphere( 0.2, 20, 20 );
glPopMatrix();

}
void moon()
{
glPushMatrix();
glTranslated(1.0,2.2,2.5);
glutSolidSphere( 0.1, 20, 20 );
glPopMatrix();
}

void checksignal()
{

int l;
if(light==1)
	  {
for(l=0;l<=20;l++)
		{
    glColor3f(0.0,1.0,0.0);
    light3();
		}
	  }

	else if(light==0)
	  {

            for(l=0;l<=20;l++)
		{
		glColor3f(1.0,0.0,0.0);
		light1();

		}
	  }
}


void idle()
{
glClearColor(1.0,1.0,1.0,1.0);
if(light==0 && (j>=-3.0 && j<=-2.8 )&& i<-3)//condition 1 to cross road
{
    index=1;
    if(move==1)
        {
            k-=0.1;
            if(k<-2.95)
                {
                    stop=1;
                    move=2;
                    k=0.0;
                }
        }

}
if(light==0 && (i>=-0.65 && i<=-0.45 ) ) //condition 2 to cross road and first vehicle near traffic signal
 {
	index=1;
	if(move==1)
        {
            k-=0.1;
            if(k<-2.95)
            {
                stop=1;
                move=2;
                k=0.0;

            }
        }
 }

 else if(light==0 && (j>=-3.0 && j<=-2.8 ))// value of j when second vehicle is near the traffic signal
 {
	i-=SPEED/10;
	index=0;
 }

 else if(light==0)
 {
    i-=SPEED/10;
	j-=SPEED/10;
	index=0;
 }
else
 {
     i-=SPEED/10;
     j-=SPEED/10;
     index=0;
 }
if(i<-3&& j<-3)
{	i=0.0;
	j=0.0;
	index=0;
}
glutPostRedisplay();
}



void myReshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
	glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
	else
	glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
}





