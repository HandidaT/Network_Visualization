#include <iostream>
#include <unistd.h>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <cmath>

using namespace std;

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
int no_of_lobes=30;//10
int lobe_list_len=no_of_lobes*3;//30
GLfloat lobes[90];//each point has 3 coordinate x, y and z
int ind=0;

void display();
void reshape(int,int);
void timer(int);

void init(){
    glClearColor(0.0,0.0,0.0,1.0);
}

int main(int argc, char**argv){
	int a[] = {3,6,8,33};
	int x=33;
	int index=find(a,a+4,x)-a;
	bool exists = find(begin(a),end(a),x) !=end(a);
	cout<<"###"<<index<<"###"<<find(begin(a),end(a),x)<<"######"<<exists<<"########";

	// int no_of_lobes;
	// cout<<"Enter number of lobes: ";
	// cin>>no_of_lobes;
	// int lobe_list_len=no_of_lobes*3;//Each lobe position has 3 dimensional coordinates x,y,z
	cout<<" lobe_list_len "<<lobe_list_len;
	// GLfloat lobes[lobe_list_len];
	srand(time(0));
	int counter=0;
	int ij_edges_len_and_repulsion= 3*( (no_of_lobes*(no_of_lobes-1)) /2 ); //Arithmetic series, array len 
									     //for forces and lengths between nodes
	cout<<" ij_edges "<<ij_edges_len_and_repulsion;
	GLfloat t,vectorLength[ij_edges_len_and_repulsion], repulsive_force[ij_edges_len_and_repulsion];

	for(int i=0;i<lobe_list_len;i++){// Initializing lobes with random coordinates
		if(counter==2){
			lobes[i]=-(-10 + ((static_cast <GLfloat> (rand())) / (static_cast <GLfloat> (RAND_MAX/(10-(-10))))));//z coordinate is negative
			}
		else{
		lobes[i]=-10 + ((static_cast <GLfloat> (rand())) / (static_cast <GLfloat> (RAND_MAX/(10-(-10)))));;
		};
		counter++;
		if(counter==3){
			counter=0;
			};
		cout<<endl<<i<<" "<<lobes[i]<<" ";
		}


	/*	int index=0;
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
	int repulsive_force_index;
	for(int i=0;i<no_of_lobes;i++){
	  for(int j=0;j<no_of_lobes;j++){
	   //cout<<endl<<"****"<<i<<j;
	   if(i!=j){//n*3 will be lobes index
	     for(int k=0;k<(ij_edges_len_and_repulsion)/3;k++){//finding repulsion force index for current i and j
		if(i==repulsive_force[(k*3)+1] && j==repulsive_force[(k*3)+2]
		      || j==repulsive_force[(k*3)+1] && i==repulsive_force[(k*3)+2]){
			repulsive_force_index=k*3;
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
*/


//	for(int i=0;i<lobe_list_len;i+=3){
//		GLfloat xtemp=0.0;
//		GLfloat ytemp=0.0;
//		//GLfloat ztemp=0.0;
//		cout<<i<<" "<<lobes[i]<<" "<<lobes[i+1]<<" "<<lobes[i+2]<<endl;
//		for(int j=0;j<lobe_list_len;j+=3){
//			xtemp += lobes[j];
//			ytemp += lobes[j+1];
//			//ztemp += lobes[j+2];
//			cout<<"###"<<xtemp<<" "<<ytemp<<" "<<endl;//<<ztemp<<endl;
//		}
//		lobes[i]=-xtemp;
//		lobes[i+1]=-ytemp;
//		//lobes[i+2]=ztemp;
//		cout<<i<<" "<<lobes[i]<<" "<<lobes[i+1]<<" "<<lobes[i+2]<<endl;
//	}
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(500,200);
	glutInitWindowSize(700,700);
	glutCreateWindow("Network");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0,timer,0);
	init();
	glutMainLoop();
	return 0;
}


void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(angle,1.0,1.0,1.0);
    //glTranslatef(0.0,0.0,position);
    glShadeModel(GL_FLAT);

    glBegin(GL_LINES);
    glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(5, 0, 0);
    glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 5, 0);
    glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 5);
    glEnd();


    for(int i=0;i<lobe_list_len;i+=3){
		// cout<<"##########"<<endl;
		glBegin(GL_TRIANGLE_FAN);
		// glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		glVertex3f( lobes[i], lobes[i+1], lobes[i+2]);   //V0(red)  top point
		glColor3f(1.0,0.0,0.0);
		glVertex3f(lobes[i]-half_sideLength,lobes[i+1]-triangleHeight, lobes[i+2]-half_triangleHeight);//V1(green) base left
		glColor3f(1.0,0.0,0.0);
		glVertex3f( lobes[i],lobes[i+1]-triangleHeight, lobes[i+2]+half_triangleHeight);   //V2(blue) base front center 
		glColor3f(0.0,1.0,0.0);
		glVertex3f( lobes[i]+half_sideLength,lobes[i+1]-triangleHeight,lobes[i+2]-half_triangleHeight);   //V3(green) base right
		glColor3f(0.0,1.0,1.0);
		glVertex3f(lobes[i]-half_sideLength,lobes[i+1]-triangleHeight, lobes[i+2]-half_triangleHeight);//V1(green) base left
		glEnd();
	}





    // glFlush();
    // glLoadIdentity();
    // glPushMatrix();
    // gluLookAt(4, 6, 5, 0, 0, 0, 0, 0, 1);
    // glPushMatrix();
    // glPopMatrix();
    glutSwapBuffers();
    angle+=1.0;
}

void reshape(int w,int h){
    cout<<"Hey";
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,1,0.0,50.0);//changed farz from 500.0 to 50.0
    gluLookAt(0, 0, 80, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();
    // gluLookAt(4, 6, 5, 0, 0, 0, 0, 0, 1);
    // glPushMatrix();
}

//-19 5.9 29 23 -6

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
    if(ind<lobe_list_len){
	cout<<"####"<<ind<<" "<<lobes[ind]<<" "<<lobes[ind+1]<<" "<<lobes[ind+2]<<endl;
	GLfloat xprevind=lobes[ind];
	GLfloat yprevind=lobes[ind+1];
	GLfloat zprevind=lobes[ind+2];
	GLfloat xrep=0.0;
	GLfloat yrep=0.0;
	GLfloat zrep=0.0;
	GLfloat xtemp=0.0;
	GLfloat ytemp=0.0;
	GLfloat ztemp=0.0;
	GLfloat vlentemp=0.0;
	GLfloat rpforctemp=0.0;
	for(int j=0;j<lobe_list_len;j+=3){
	   cout<<"*******"<<j<<" "<<lobes[j]<<" "<<lobes[j+1]<<" "<<lobes[j+2]<<endl;
	   xrep = lobes[j]-xprevind;//Repositioning lobe coordinates according to ind lobe
	   yrep = lobes[j+1]-yprevind;//which is positioned as origin
	   zrep = lobes[j+2]-zprevind;
	   xtemp += xrep;
	   ytemp += yrep;
	   ztemp += zrep;
	   vlentemp=sqrt(pow(xrep,2)+pow(yrep,2)+pow(zrep,2));
	   if(vlentemp!=0){
	   rpforctemp+=0.06647/pow(vlentemp,2);
	    }
	   cout<<"**************"<<lobes[j]<<" "<<xprevind<<" "<<xrep<<" "<<xtemp<<endl;
	   }

	//GLfloat parllelvec[3]={-xtemp-xtemp,-ytemp-ytemp,-ztemp-ztemp};//j to i
	//cout<<parllelvec[0]<<" "<<rpforctemp<<endl;
	lobes[ind]=-xtemp;//xtemp+(parllelvec[0]*(rpforctemp/no_of_lobes));//rpforctemp as t
	lobes[ind+1]=-ytemp;//ytemp+(parllelvec[1]*(rpforctemp/no_of_lobes));
	lobes[ind+2]=-ztemp;//ztemp+(parllelvec[2]*(rpforctemp/no_of_lobes));
	lobes[ind]+=xprevind;
	lobes[ind+1]+=yprevind;
	lobes[ind+2]+=zprevind;

	GLfloat radveclen=sqrt(pow(lobes[ind],2)+pow(lobes[ind+1],2)+pow(lobes[ind+2],2));
	GLfloat radiusparlvec[3]={-lobes[ind],-lobes[ind+1],-lobes[ind+2]};
	GLfloat t=1;//Initializing parametric variable t randomly as 1

	GLfloat prevradveclen2=radveclen+1;//randomly creating prevradveclen2 by adding 1 to radveclen
	GLfloat prevradveclen1=radveclen;
	while(prevradveclen1!=radius){//Keeping distance from the origin equal to radius
	   //sleep(1);
	   cout<<endl<<"    In while loop     "<<prevradveclen1;
	   //t=prevradveclen2-prevradveclen1;
	   cout<<endl<<"[0] "<<lobes[ind]<<" "<<radiusparlvec[0];//##############################################3
	   cout<<endl<<"[1] "<<lobes[ind+1]<<" "<<radiusparlvec[1];
	   cout<<endl<<t;
	   if(prevradveclen1<radius){
	      if(abs(prevradveclen2-prevradveclen1)>abs(prevradveclen1-radius)){
  		t=t-(t/2);
		cout<<" ifif "<<t;
		lobes[ind]=lobes[ind]+(radiusparlvec[0]*(-t));
	   	lobes[ind+1]=lobes[ind+1]+(radiusparlvec[1]*(-t));
		lobes[ind+2]=lobes[ind+2]+(radiusparlvec[2]*(-t));}
	      if(abs(prevradveclen2-prevradveclen1)<abs(prevradveclen1-radius)){
		t=t+(t/2);
		cout<<" ifelse "<<t;
	   	lobes[ind]=lobes[ind]+(radiusparlvec[0]*(-t));
	   	lobes[ind+1]=lobes[ind+1]+(radiusparlvec[1]*(-t));
		lobes[ind+2]=lobes[ind+2]+(radiusparlvec[2]*(-t));}
			}
	   if(prevradveclen1>radius){
	      if(abs(prevradveclen2-prevradveclen1)>abs(prevradveclen1-radius)){
  		t=t-(t/2);
		cout<<" elseif "<<t;
	   	lobes[ind]=lobes[ind]+(radiusparlvec[0]*t);
	   	lobes[ind+1]=lobes[ind+1]+(radiusparlvec[1]*t);
		lobes[ind+2]=lobes[ind+2]+(radiusparlvec[2]*t);}
	      if(abs(prevradveclen2-prevradveclen1)<abs(prevradveclen1-radius)){
		t=t+(t/70);//t/20 to avoid exploding values
		cout<<" elseelse "<<t;
	   	lobes[ind]=lobes[ind]+(radiusparlvec[0]*t);
	   	lobes[ind+1]=lobes[ind+1]+(radiusparlvec[1]*t);
		lobes[ind+2]=lobes[ind+2]+(radiusparlvec[2]*t);}
		}
	   //t=repulsive_force[repulsive_force_index]-repulsive_force[k*3];
	   //lobes[ind]=lobes[ind]+(radiusparlvec[0]*t);
	   //lobes[ind+1]=lobes[ind+1]+(radiusparlvec[1]*t);

	   GLfloat temp=prevradveclen1;
           prevradveclen2=temp;
	   prevradveclen1=sqrt(pow(lobes[ind],2)+pow(lobes[ind+1],2)+pow(lobes[ind+2],2));
	   cout<<endl<<lobes[ind]<<" "<<pow(lobes[ind],2)<<" "<<lobes[ind+1]<<" "<<pow(lobes[ind+1],2)<<" ";
	   cout<<pow(lobes[ind],2)+pow(lobes[ind+1],2)<<" "<<sqrt(pow(lobes[ind],2)+pow(lobes[ind+1],2))<<" "<<prevradveclen1;
	    }

	//lobes[(j*3)+2]=lobes[(j*3)+2]+(parllelvec[2]*t);

	ind+=3;
	if(ind==lobe_list_len){ind=0;}
	//ind+=3;
	}
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
