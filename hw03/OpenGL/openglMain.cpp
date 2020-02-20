/*
openglMain.cpp
Andrew Ng
Feb 16, 2020
OpenGL 1.1 Intro
for HW3
*/


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>


using std::cout;
using std::endl;


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}


void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}


int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1280, 720, "TestWindows", NULL, NULL);
	if (window == NULL) {
		cout << "failed to create windows" << endl;
		glfwTerminate();
		return 0;
	}
	glfwMakeContextCurrent(window);
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "failed to initialize GLAD" << endl;
		return 0;
	}

	glEnable(GL_DEPTH_TEST);

	glViewport(0, 0, 1280, 720);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	float angle = 0.1;
	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_MODELVIEW);

		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.3f, 0.2f); glVertex3f(0.0f, -0.25f, 0.5f);
		glColor3f(1.0f, 0.3f, 0.2f); glVertex3f(0.0f, 0.25f, 0.5f);
		glColor3f(1.0f, 0.3f, 0.2f); glVertex3f(-0.5f, 0.25f, 0.0f);
		glColor3f(1.0f, 0.3f, 0.2f); glVertex3f(-0.5f, -0.25f, 0.0f);

		glColor3f(0.1f, 0.7f, 0.3f); glVertex3f(0.0f, 0.25f, 0.5f);
		glColor3f(0.1f, 0.7f, 0.3f); glVertex3f(0.0f, -0.25f, 0.5f);
		glColor3f(0.1f, 0.7f, 0.3f); glVertex3f(0.5f, -0.25f, 0.0f);
		glColor3f(0.1f, 0.7f, 0.3f); glVertex3f(0.5f, 0.25f, 0.0f);

		glColor3f(0.2f, 0.4f, 1.0f); glVertex3f(0.5f, 0.25f, 0.0f);
		glColor3f(0.2f, 0.4f, 1.0f); glVertex3f(0.5f, -0.25f, 0.0f);
		glColor3f(0.2f, 0.4f, 1.0f); glVertex3f(0.0f, -0.25f, -0.5f);
		glColor3f(0.2f, 0.4f, 1.0f); glVertex3f(0.0f, 0.25f, -0.5f);

		glColor3f(1.0f, 0.8f, 0.2f); glVertex3f(0.0f, 0.25f, -0.5f);
		glColor3f(1.0f, 0.8f, 0.2f); glVertex3f(0.0f, -0.25f, -0.5f);
		glColor3f(1.0f, 0.8f, 0.2f); glVertex3f(-0.5f, -0.25f, 0.0f);
		glColor3f(1.0f, 0.8f, 0.2f); glVertex3f(-0.5f, 0.25f, 0.0f);
		glEnd();

		glRotatef(angle, 1.0f, 0.0f, 0.0f);
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}