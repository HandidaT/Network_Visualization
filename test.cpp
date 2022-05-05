#include <iostream>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <cmath>
// // #include <GL/glew.h>

using namespace std;

// void display() {

//   glClear(GL_COLOR_BUFFER_BIT);

//   // Draw a white torus of outer radius 3, inner radius 0.5 with 15 stacks
//   // and 30 slices.
// //   glColor3f(1.0, 1.0, 1.0);
// //   glutWireTorus(0.5, 3, 5, 30);

//   // Draw a red x-axis, a green y-axis, and a blue z-axis.  Each of the
//   // axes are ten units long.
//   glBegin(GL_LINES);
//     glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(10, 0, 0);
//     glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 10, 0);
//     glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 10);
//   glEnd();

//   glFlush();
// }

// // Sets up global attributes like clear color and drawing color, and sets up
// // the desired projection and modelview matrices.
// void init() {

//   // Set the current clear color to black and the current drawing color to
//   // white.
//   glClearColor(0.0, 0.0, 0.0, 1.0);
// //   glColor3f(1.0, 1.0, 1.0);

//   // Set the camera lens to have a 60 degree (vertical) field of view, an
//   // aspect ratio of 4/3, and have everything closer than 1 unit to the
//   // camera and greater than 40 units distant clipped away.
//   glMatrixMode(GL_PROJECTION);
//   glLoadIdentity();
//   gluPerspective(60.0, 4.0/3.0, 1, 40);

//   // Position camera at (4, 6, 5) looking at (0, 0, 0) with the vector
//   // <0, 1, 0> pointing upward.
//   glMatrixMode(GL_MODELVIEW);
//   glLoadIdentity();
//   gluLookAt(4, 6, 5, 0, 0, 0, 0, 1, 0);
// }

// // Initializes GLUT, the display mode, and main window; registers callbacks;
// // does application initialization; enters the main event loop.
// int main(int argc, char** argv) {
//   glutInit(&argc, argv);
//   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//   glutInitWindowPosition(80, 80);
//   glutInitWindowSize(800, 600);
//   glutCreateWindow("A Simple Torus");
//   glutDisplayFunc(display);
//   init();
//   glutMainLoop();
// }












// #include <iostream>
// #include <GL/glu.h>
// #include <GL/glut.h>
// #include <GL/gl.h>
// // // #include <GL/glew.h>

// using namespace std;

// // // "${workspaceFolder}/**"
// // // enter program name, for example ${workspaceFolder}/a.out
// // // "${workspaceFolder}/DLBcpp1/a.out"
// // // 
// // // The commands needed to compile and execute are:
// // // To Compile
// // // g++ ./filename.cpp -o filename -lGL -lGLU -lglut
// // // '-lGL -lGLU -lglut' will link the libraries
// // // To Execute
// // // ./test




// // // class

GLfloat angle = 0.1;
int state = 1;
// float position = -7.0;
GLfloat position = -13.0;
GLfloat sideLength=1.0;
GLfloat half_sideLength=sideLength/2;
GLfloat triangleHeight = sqrt( sideLength*sideLength - (half_sideLength*half_sideLength) );
GLfloat half_triangleHeight=triangleHeight/2;

void display();
void reshape(int,int);
void timer(int);

void init(){
    glClearColor(0.0,0.0,0.0,1.0);
}


int main(int argc,char**argv){
// int main(){
    // GLint type = 132;
    // typedef struct _starRec {
    // GLint type;
    // float x[2], y[2], z[2];
    // float offsetX, offsetY, offsetR, rotation;
    // } starRec;

    // starRec star[600];
    // cout<<"Opengl ggg fuck! "<<type<<endl<<star<<"  "<<5+-1;
    // cin.get();
    float xx,yy;
    xx=0.0000000000000000000000000000000000005; //37 zeros 38th 5 uln
    yy=-0.00000000000000000000000000000000000049; //37 zeros 38th 5 uln
    cout<<xx<<endl<<yy<<endl<<xx+yy;
    float num1=10;
    float sqroot= sqrt(num1);
    int randnum=rand();
    cout<<endl<<sqroot<<endl<<randnum<<" "<<(randnum) % 100;
    


    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(500,200);
    glutInitWindowSize(700,700);
    glutCreateWindow("Tesseract");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    init();
    glutMainLoop();
    return 0;
}

void display(){
    cout<<" In display"<<endl;
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    // glTranslatef(0.0,0.0,-11.0);
    glTranslatef(0.0,0.0,position);
    glRotatef(angle,0.0,1.0,0.0);
    glShadeModel(GL_FLAT);
    // glPointSize(10.0);
    // glBegin(GL_TRIANGLES);
    // glVertex3f(3.5,-1.0,10.0);
    // glVertex3f(3.43,-1.07,10.0);
    // glVertex3f(3.57,-1.07,10.0);
    // glEnd();
// 00000000000000000000000000000000000
// 99999999999999999999999999999999999
    // float i;
    // for(i=0.0;i<=0.1;i+=0.00000001){
    //   glBegin(GL_TRIANGLES);
    //   glVertex3f((i+-0.5),(i+-0.0),(i+10.0));
    // //   glVertex3f((i+-0.5000000000000000000000000000000000001),(i-0.0000000000000000000000000000000000001),(i+10.0));
    // //   glVertex3f((i+-0.4999999999999999999999999999999999999),(i+-0.0000000000000000000000000000000000001),(i+10.0));
    //   glVertex3f((i+-0.5001),(i-0.0001),(i+10.0));
    //   glVertex3f((i+-0.4999),(i+-0.0001),(i+10.0));
    //   glEnd();
    //   }

    glBegin(GL_LINES);
    glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(5, 0, 0);
    glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 5, 0);
    glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 5);
    glEnd();


    GLfloat point = 1.0;
    glBegin(GL_TRIANGLE_FAN);
    // glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex3f( point, point, point);   //V0(red)  top point
    glColor3f(1.0,0.0,0.0);
    glVertex3f(point-half_sideLength,point-triangleHeight, point-half_triangleHeight);//V1(green) base left
    glColor3f(1.0,0.0,0.0);
    glVertex3f( point,point-triangleHeight, point+half_triangleHeight);   //V2(blue) base front center 
    glColor3f(0.0,1.0,0.0);
    glVertex3f( point+half_sideLength,point-triangleHeight,point-half_triangleHeight);   //V3(green) base right
    glColor3f(0.0,0.0,1.0);
    glVertex3f(point-half_sideLength,point-triangleHeight, point-half_triangleHeight);//V1(green) base left
    glEnd();



    GLfloat point = 1.0;
    for(int i=0;
    	glBegin(GL_TRIANGLE_FAN);
    	// glBegin(GL_POLYGON);
    	glColor3f(1.0,0.0,0.0);
    	glVertex3f( point, point, point);   //V0(red)  top point
    	glColor3f(1.0,0.0,0.0);
    	glVertex3f(point-half_sideLength,point-triangleHeight, point-half_triangleHeight);//V1(green) base left
    	glColor3f(1.0,0.0,0.0);
    	glVertex3f( point,point-triangleHeight, point+half_triangleHeight);   //V2(blue) base front center 
    	glColor3f(0.0,1.0,0.0);
    	glVertex3f( point+half_sideLength,point-triangleHeight,point-half_triangleHeight);   //V3(green) base right
    	glColor3f(0.0,0.0,1.0);
    	glVertex3f(point-half_sideLength,point-triangleHeight, point-half_triangleHeight);//V1(green) base left
    	glEnd();




    // glFlush();
    // glLoadIdentity();
    // glPushMatrix();
    // gluLookAt(4, 6, 5, 0, 0, 0, 0, 0, 1);
    // glPushMatrix();
    // glPopMatrix();
    glutSwapBuffers();
    angle+=0.05;
}

void reshape(int w,int h){
    cout<<"Hey";
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,1,0.0,50.0);//changed farz from 500.0 to 50.0
    gluLookAt(5, 3, 6, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();
    // gluLookAt(4, 6, 5, 0, 0, 0, 0, 0, 1);
    // glPushMatrix();
}

void timer(int){
    cout<<"In timer ";
    glutPostRedisplay();
    cout<<"func callback ";
    glutTimerFunc(1000/60,timer,0);
    cout<<"after func callback, during switch";
    switch(state){
        case 1:
            if(position<-6.5)
                position+=0.10;
            else
            {
                state=-1;
            }
            break;
        case -1:
            if(position>-18)
                position-=0.10;
            else
            {
                state=1;
            }
            break;
    }
    cout<<" After switch";
}
