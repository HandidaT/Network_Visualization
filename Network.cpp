#include <iostream>
#include <cstdlib>
#include <ctime>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <cmath>
//#include <armadillo>
using namespace std;
//using namespace arma;

//   compile
// g++ Network.cpp -o Network -DARMA_USE_WRAPPER -lopenblas -llapack -L/usr/lib/x86_64-linux-gnu/hdf5/serial -lhdf5
// execute
// ./Network


GLfloat angle = 0.1;
int state = 1;
// float position = -7.0;
GLfloat position = -13.0;
GLfloat sideLength=1.0;
GLfloat half_sideLength=sideLength/2;
GLfloat triangleHeight = sqrt( sideLength*sideLength - (half_sideLength*half_sideLength) );
GLfloat half_triangleHeight=triangleHeight/2;
const int positive_fixed_repulsion[3]={5,0,0};
GLfloat radius=30.0;

void display();
void reshape(int,int);
void timer(int);

void init(){
    glClearColor(0.0,0.0,0.0,1.0);
}

int main(int argc, char**argv){
	int no_of_lobes;
	cout<<"Enter number of lobes: ";
	cin>>no_of_lobes;
	int lobe_list_len=no_of_lobes*3;//Each lobe position has 3 dimensional coordinates x,y,z
	cout<<" lobe_list_len "<<lobe_list_len;
	GLfloat lobes[lobe_list_len];
	srand(time(0));
	int counter=0;
	int ij_edges_len_and_repulsion= 3*( (no_of_lobes*(no_of_lobes-1)) /2 ); //Arithmetic series, array len 
									     //for forces and lengths between nodes
	cout<<" ij_edges "<<ij_edges_len_and_repulsion;
	GLfloat t,vectorLength[ij_edges_len_and_repulsion], repulsive_force[ij_edges_len_and_repulsion];

	for(int i=0;i<lobe_list_len;i++){// Initializing lobes with random coordinates
		if(counter==1){
			lobes[i]=-(static_cast <GLfloat> (rand())) / (static_cast <GLfloat> (RAND_MAX/30));//y coordinate is negative
			}
		else{
			lobes[i]=(static_cast <GLfloat> (rand())) / (static_cast <GLfloat> (RAND_MAX/30));
		};
		counter++;
		if(counter==3){
			counter=0;
			};
		cout<<endl<<lobes[i]<<" ";
		}

	int index=0;
//	for(int i=0;i<ij_edges_len_and_repulsion;i+=3){// Initializing edges with random repulsion and length values
	for(int j=0;j<no_of_lobes;j++){
		if(j==no_of_lobes){break;}
		for(int k=j+1;k<no_of_lobes;k++){
			vectorLength[index]=(static_cast <GLfloat> (rand())) / (static_cast <GLfloat> (RAND_MAX/radius));
			vectorLength[index+1]=j;
			vectorLength[index+2]=k;

			repulsive_force[index]=6647/pow(vectorLength[index],2);
			repulsive_force[index+1]=j;
			repulsive_force[index+2]=k;

			cout<<endl<<endl<<vectorLength[index]<<" "<<vectorLength[index+1]<<" "<<vectorLength[index+2];
			cout<<endl<<repulsive_force[index]<<" "<<repulsive_force[index+1]<<" "<<repulsive_force[index+2];
			index+=3;
			}
	}

	cout<<endl<<"ij_edges_len_and_repulsion "<<ij_edges_len_and_repulsion<<endl<<"index "<<index;


//	for(int j=0;j<10;j++){
//		cout<<endl<<RAND_MAX;
//		}

	cout<<endl<<"no_of_lobes "<<no_of_lobes;
	for(int i=0;i<no_of_lobes;i++){
	  for(int j=0;j<no_of_lobes;j++){
	   //cout<<endl<<"****"<<i<<j;
	   if(i!=j){//n*3 will be lobes index
	     for(int k=0;k<(ij_edges_len_and_repulsion)/3;k++){//finding repulsion force index for current i and j
		if(i==repulsive_force[(k*3)+1] && j==repulsive_force[(k*3)+2]
		      || j==repulsive_force[(k*3)+1] && i==repulsive_force[(k*3)+2]){
			GLfloat repulsive_force_index=k*3;
			}
		}

	     for(int k=0;k<(ij_edges_len_and_repulsion)/3;k++){
		if(i!=repulsive_force[(k*3)+1] && j==repulsive_force[(k*3)+2]//comparing force between node j and all other nodes
		      || j==repulsive_force[(k*3)+1] && i!=repulsive_force[(k*3)+2]){
			while(repulsive_force[repulsive_force_index]>repulsive_force[k*3]){
//			    int prev_repulsion2=;
//			    int prev_repulsion1;
//			    if((prev_repulsion2-prev_repulsion1)>(prev_repulsion1-repulsive_force[k*3])){
//				t=-(t-something);}
//			    else{t=-(t+something);}
			    //t=repulsive_force[repulsive_force_index]-repulsive_force[k*3];
//GLfloat parallel_vector[3]={lobes[i*3]-lobes[j*3],lobes[(i*3)+1]-lobes[(j*3)+1],lobes[(i*3)+2]-lobes[(j*3)+2]};//j to i
			    GLfloat parallel_vector[3]={lobes[i*3]-lobes[j*3],lobes[(i*3)+1]-lobes[(j*3)+1],lobes[(i*3)+2]-lobes[(j*3)+2]};//j to i
			    
	     		    lobes[j*3]=lobes[j*3]+(parallel_vector[0]*t);
	     		    lobes[(j*3)+1]=lobes[(j*3)+1]+(parallel_vector[1]*t);
	     		    lobes[(j*3)+2]=lobes[(j*3)+2]+(parallel_vector[2]*t);
	     		    cout<<endl<<"#####"<<i<<j;
	     		    vectorLength[repulsive_force_index]=sqrt(pow(lobes[i]-lobes[j],2)+pow(lobes[i+1]-lobes[j+1],2)+pow(lobes[i+2]-lobes[j+2],2));
			    repulsive_force[repulsive_force_index]=6647/pow(vectorLength[repulsive_force_index],2);
				}
			}
		}
	     //vectorLength=sqrt(pow(lobes[i]-lobes[j],2)+pow(lobes[i+1]-lobes[j+1],2)+pow(lobes[i+2]-lobes[j+2],2));
	     //repulsive_force=6647/pow(vectorLength,2);
	     }
	    }
	   }

//	glutInit(&argc,argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
//	glutInitWindowPosition(500,200);
//	glutInitWindowSize(700,700);
//	glutCreateWindow("Tesseract");
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutTimerFunc(0,timer,0);
//	init();
//	glutMainLoop();
	return 0;
}


void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glShadeModel(GL_FLAT);

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
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
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
}
