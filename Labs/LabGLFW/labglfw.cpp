#include <GLFW/glfw3.h>
#include <cmath>

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")

int main2(void) {
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window)) {
		/* Render here */
		glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		int w = 1;
		int h = 1;
		glfwGetWindowSize(window, &w, &h);
		glViewport(0, 0, w, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		double ar = (double)w / (double)h;
		glOrtho(-ar, ar, -1, 1, -1, 1); // left,right,bottom,top,znear,zfar
		glMatrixMode(GL_MODELVIEW);


		glLoadIdentity();
		float angle = (float)glfwGetTime();
		float c = 0.5f * std::cos(200 * angle * 3.14159f / 180.0f);
		float s = 0.5f * std::sin(200 * angle * 3.14159f / 180.0f);
		glTranslatef(c, s, 0.0f);
		glScalef(1 + c, 1 + s, 1.0f);
		glRotatef(angle * 30.0f, 0.0f, 0.0f, 1.0f);

		glBegin(GL_TRIANGLES);
		//glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 0.0f);
		//glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 0.0f);
		//glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(0.0f, 1.0f, 0.0f);
		glColor3ub(255, 0, 0); glVertex3f(-1.0f, -1.0f, 0.0f);
		glColor3ub(0, 255, 0); glVertex3f(1.0f, -1.0f, 0.0f);
		glColor3ub(0, 0, 255); glVertex3f(0.0f, 1.0f, 0.0f);
		glEnd();


		glLoadIdentity();
		glBegin(GL_LINE_LOOP);
		for (float a = 0.0f; a < 360.0f; a += 1.0f) {
			float c = std::cos(a * 3.14159f / 180.0f);
			float s = std::sin(a * 3.14159f / 180.0f);
			glColor3f(std::abs(c), std::abs(s), 0.0f);
			glVertex3f(c, s, 0.0f);
		}
		glEnd();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}