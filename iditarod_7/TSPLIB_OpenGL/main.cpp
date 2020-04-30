#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "TspSolver.h"


int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1280, 720, "TSPLIB Algorithms", nullptr, nullptr);
	if (window == nullptr) {
		std::cout << "ERROR: Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "ERROR: Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 1280, 720);

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.2f, 0.4f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	/*TspSolver random;
	random.SolveRandomly("fnl4461.tsp", 1);

	TspSolver greedy;
	greedy.SolveGreedy("fnl4461.tsp");

	TspSolver custom;
	custom.SolveMyWay("fnl4461.tsp");*/

	glfwTerminate();
	return 0;
}