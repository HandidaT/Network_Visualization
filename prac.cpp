#include <iostream>
//#include <GL/glew.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//g++ prac.cpp glad.c -o prac -lGL -GLU -lX11 -lXrandr -lpthread -lXi -ldl -L/usr/lib/x86_64-linux-gnu -lglfw

const unsigned int SCR_WIDTH=800;
const unsigned int SCR_HEIGHT=600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
	glViewport(0,0,width,height);
	}

void processInput(GLFWwindow *window){
	if(glfwGetKey(window, GLFW_KEY_ESCAPE)==GLFW_PRESS)
	   {glfwSetWindowShouldClose(window, true);}
	}

const char *vertexShaderSource="#version 330 core\n"
	"layout (location=0) in vec3 aPos;\n"
	"void main()\n"
	"{\n"
	"   gl_Position=vec4(aPos.x,aPos.y,aPos.z,1.0);\n"
	"}\0";
const char *fragmentShaderSource="#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
	"   FragColor=vec4(1.0f,0.5f,0.2f,1.0f);\n"
	"}\n\0";

//int main(int argc, char *argv[]){
int main(){
	/*glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
*/
	GLFWwindow* window;
	
	if(!glfwInit()){
		return -1;}
 
	window=glfwCreateWindow(800,600,"Tesseract",NULL,NULL);
//	glfwMakeContextCurrent(window);
	if(window==NULL){
	std::cout<<"Failed to create window"<<std::endl;
	glfwTerminate();
	return -1;
	}
	glfwMakeContextCurrent(window);

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{std::cout<<"Failed to initialize GLAD"<<std::endl;
	return -1;
	}

	int vertexShader=glCreateShader(GL_VERTEX_SHADER);//build and compile shader program
	glShaderSource(vertexShader,1,&vertexShaderSource,NULL);//vertex shader
	glCompileShader(vertexShader);
	int success;//check for shader compile errors
	char infoLog[512];
	glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&success);
	if(!success){
	   glGetShaderInfoLog(vertexShader,512,NULL,infoLog);
	   std::cout<<"ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"<<infoLog<<std::endl;
		}

	int fragmentShader=glCreateShader(GL_FRAGMENT_SHADER);//fragment shader
	glShaderSource(fragmentShader,1,&fragmentShaderSource,NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&success);//check for shader compile errors
	if(!success){
	   glGetShaderInfoLog(fragmentShader,512,NULL,infoLog);
	   std::cout<<"ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"<<infoLog<<std::endl;
		}

	int shaderProgram=glCreateProgram();//link shaders
	glAttachShader(shaderProgram,vertexShader);
	glAttachShader(shaderProgram,fragmentShader);
	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram,GL_LINK_STATUS,&success);//check for linking errors
	if(!success){
	   glGetProgramInfoLog(shaderProgram,512,NULL,infoLog);
	   std::cout<<"ERROR::SHADER::PROGRAM::LINKING_FAILED\n"<<infoLog<<std::endl;
		}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	float vertices[]={
		0.5f, 0.5f, 0.0f, //top right
		0.5f,-0.5f,0.0f,  //bottom right
		-0.5f,-0.5f,0.0f, //bottom left
		-0.5f,0.5f,0.0f}; //top left

	unsigned int VBO;
	glGenBuffers(1,&VBO);

	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

	glViewport(0,0,800,600);
	
	glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);
	while(!glfwWindowShouldClose(window)){
	processInput(window);
	glClearColor(0.2f,0.3f,0.3f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
/*	glBegin(GL_TRIANGLES);
	glVertex2f(0.5f,-0.5f);
	glVertex2f(0.0f,0.5f);
	glVertex2f(0.5f,-0.5f);
	glEnd();*/
	glfwSwapBuffers(window);
	glfwPollEvents();
	}
	
	glfwTerminate();
	std::cout<<"Hello World"<<std::endl;
	//std::cin.get();
	return 0;
}

