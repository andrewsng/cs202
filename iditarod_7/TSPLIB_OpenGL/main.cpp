/*
	main.cpp
	Andrew Ng
	Apr 30, 2020
	main for OpenGL TSPLIB display
*/


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "TspSolver.h"
#include <iostream>
#include <vector>
#include <string>


const char* vtxShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main()\n"
"{\n"
"    gl_Position = projection * view * model * vec4(aPos.x, aPos.y, 0.0f, 1.0f);\n"
"}\0";


const char* ptFragShaderSource =
"#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"    FragColor = vec4(0.5f, 0.75f, 0.75f, 1.0f);\n"
"}\0";


const char* lnFragShaderSource =
"#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"    FragColor = vec4(1.0f, 0.0f, 0.4f, 1.0f);\n"
"}\0";


enum class alg { random, greedy, custom };


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}


bool processQuit(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		return true;
	}
	return false;
}


bool processMode(GLFWwindow* window, alg& alg) {
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS && alg != alg::random) {
		alg = alg::random;
		return true;
	}
	else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS && alg != alg::greedy) {
		alg = alg::greedy;
		return true;
	}
	else if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS && alg != alg::custom) {
		alg = alg::custom;
		return true;
	}
	return false;
}


int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1920, 1080, "TSPLIB Algorithms", NULL, NULL);
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

	glEnable(GL_DEPTH_TEST);
	glPointSize(2.0f);

	glViewport(0, 0, 1920, 1080);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	alg algToRun = alg::random;
	std::string fileName = "dsj1000.tsp";

	bool running = true;
	while (running) {
		glfwSetWindowShouldClose(window, false);
		TspSolver solver;

		switch (algToRun) {
		case alg::random:
			solver.randomInit(fileName);
			break;
		case alg::greedy:
			solver.greedyInit(fileName);
			break;
		case alg::custom:
			solver.customInit(fileName);
			break;
		default:
			solver.randomInit(fileName);
			break;
		}

		std::vector<float> pointData;
		std::vector<float> lineData;

		solver.outputPoints(1530, 900, 1920, 1080, pointData);
		solver.outputLines(1530, 900, 1920, 1080, lineData);

		unsigned int ptVAO;
		glGenVertexArrays(1, &ptVAO);
		unsigned int lnVAO;
		glGenVertexArrays(1, &lnVAO);
		unsigned int ptVBO;
		glGenBuffers(1, &ptVBO);
		unsigned int lnVBO;
		glGenBuffers(1, &lnVBO);

		glBindVertexArray(ptVAO);
		glBindBuffer(GL_ARRAY_BUFFER, ptVBO);
		glBufferData(GL_ARRAY_BUFFER, pointData.size() * sizeof(float), &pointData.front(), GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

		glBindVertexArray(lnVAO);
		glBindBuffer(GL_ARRAY_BUFFER, lnVBO);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);


		unsigned int vtxShader;
		vtxShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vtxShader, 1, &vtxShaderSource, NULL);
		glCompileShader(vtxShader);

		unsigned int ptFragShader;
		ptFragShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(ptFragShader, 1, &ptFragShaderSource, NULL);
		glCompileShader(ptFragShader);

		unsigned int lnFragShader;
		lnFragShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(lnFragShader, 1, &lnFragShaderSource, NULL);
		glCompileShader(lnFragShader);

		unsigned int ptProgram;
		ptProgram = glCreateProgram();
		glAttachShader(ptProgram, vtxShader);
		glAttachShader(ptProgram, ptFragShader);
		glLinkProgram(ptProgram);

		unsigned int lnProgram;
		lnProgram = glCreateProgram();
		glAttachShader(lnProgram, vtxShader);
		glAttachShader(lnProgram, lnFragShader);
		glLinkProgram(lnProgram);


		while (!glfwWindowShouldClose(window)) {
			if (processQuit(window)) {
				running = false;
				break;
			}

			if (processMode(window, algToRun)) {
				glfwSetWindowShouldClose(window, true);

				glDeleteVertexArrays(1, &ptVAO);
				glDeleteVertexArrays(1, &lnVAO);
				glDeleteBuffers(1, &ptVBO);
				glDeleteBuffers(1, &lnVBO);
				glDeleteShader(vtxShader);
				glDeleteShader(ptFragShader);
				glDeleteShader(lnFragShader);
				glDeleteProgram(ptProgram);
				glDeleteProgram(lnProgram);
			}

			lineData.clear();
			solver.outputLines(1530, 900, 1920, 1080, lineData);
			switch (algToRun) {
			case alg::random:
				solver.randomStep();
				break;
			case alg::greedy:
				solver.greedyStep();
				break;
			case alg::custom:
				solver.customStep();
				break;
			default:
				solver.randomStep();
				break;
			}

			float modelPt[16] = {
			1,   0,   0,   0,
			0,   1,   0,   0,
			0,   0,   1,   0,
			0,   0,  -1,   1 };

			float modelLn[16] = {
			1,   0,   0,   0,
			0,   1,   0,   0,
			0,   0,   1,   0,
			0,   0,   0,   1 };

			float view[16] = {
				1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				0, 0, -5, 1
			};

			int w = 1;
			int h = 1;
			glfwGetWindowSize(window, &w, &h);
			float n = 0.01f;
			float f = 10.0f;
			float t = h;
			float b = 0;
			float r = w;
			float l = 0;
			float m00 = 2.0f / (r - l);
			float m11 = 2.0f / (t - b);
			float m22 = -2.0f / (f - n);
			float m03 = (r + l) / (l - r);
			float m13 = (t + b) / (b - t);
			float m23 = (f + n) / (n - f);
			float projection[16] = {
				m00,   0,   0,   0,
				  0, m11,   0,   0,
				  0,   0, m22,   0,
				m03, m13, m23,   1
			};

			glClearColor(0.05f, 0.1f, 0.2f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glUseProgram(ptProgram);
			int modelLoc = glGetUniformLocation(ptProgram, "model");
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, modelPt);
			int viewLoc = glGetUniformLocation(ptProgram, "view");
			glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view);
			int projectionLoc = glGetUniformLocation(ptProgram, "projection");
			glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, projection);
			glBindVertexArray(ptVAO);
			glDrawArrays(GL_POINTS, 0, pointData.size() / 2);

			if (lineData.size() != 0) {
				glUseProgram(lnProgram);
				modelLoc = glGetUniformLocation(lnProgram, "model");
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, modelLn);
				viewLoc = glGetUniformLocation(lnProgram, "view");
				glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view);
				projectionLoc = glGetUniformLocation(lnProgram, "projection");
				glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, projection);
				glBindVertexArray(lnVAO);
				glBindBuffer(GL_ARRAY_BUFFER, lnVBO);
				glBufferData(GL_ARRAY_BUFFER, lineData.size() * sizeof(float), &lineData.front(), GL_STREAM_DRAW);
				glDrawArrays(GL_LINES, 0, lineData.size() / 2 + 1);
			}

			glfwSwapBuffers(window);
			glfwPollEvents();

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
		}
	}

	glfwTerminate();
	return 0;
}