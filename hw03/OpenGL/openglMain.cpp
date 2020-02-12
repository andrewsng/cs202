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

	glViewport(0, 0, 1280, 720);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	float angle = 0.0;
	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(0.0f, -0.5f, 0.5f);
		glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(0.0f, 0.5f, 0.5f);
		glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-0.5f, 0.5f, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.0f);

		glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.0f, 0.5f, 0.5f);
		glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.0f, -0.5f, 0.5f);
		glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.5f, 0.5f, 0.0f);

		glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(0.5f, -0.5f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(0.0f, -0.5f, -0.5f);
		glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(0.0f, 0.5f, -0.5f);

		glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(0.0f, 0.5f, -0.5f);
		glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(0.0f, -0.5f, -0.5f);
		glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.0f);
		glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(-0.5f, 0.5f, 0.0f);
		glEnd();

		glRotatef(angle, 1.0f, 0.0f, 0.0f);

		angle += 0.00001;
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}