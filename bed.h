#pragma once

/*
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"
#include "cube.h"

void bed(Cube &cube, Shader& lightingShader, glm::mat4 als)
{

	float rotateAngle_Y = 0.0;
	glm::mat4 rotateY = glm::mat4(1.0f);
	glm::mat4 rotateZ = glm::mat4(1.0f);
	float rotateAngle_Z = 0.0f;


	glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

	//bedbody
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.0/10, (0.1 + 0.15) / 10, -12.00 / 10));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.0 / 10.0f, 2.0 / 10.0f, 8.0 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.502f, 0, 0);
	cube.setMaterialisticEimu(0.502f, 0, 0);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//bed stand1
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.9 / 10, 0.5 / 10, -5.00 / 10));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(.7 / 10.0f, 7.0 / 10.0f, 0.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//bed stand2
	translateMatrix = glm::translate(identityMatrix, glm::vec3(4.363 / 10, 0.5 / 10, -5.00 / 10));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(.7 / 10.0f, 7.0 / 10.0f, 0.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);
	//bed stand1 er nicher
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.9 / 10.0f, 0.1 / 10.0f, -5.00 / 10.0f));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(.7 / 10.0f, .5 / 10.0f, 0.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.0f, 0, 0);
	cube.setMaterialisticEimu(0.0f, 0, 0);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//bed box bottom
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.15 / 10.0f, 0.1 / 10.0f, -4.00 / 10.0f));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.25 / 10.0f, 1.5 / 10.0f, 2.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);


	//bed box middle
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.15 / 10.0f, 1.6 / 10.0f, -4.00 / 10.0f));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.25 / 10.0f, .25 / 10.0f, 2.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.0f, 0, 0);
	cube.setMaterialisticEimu(0.0f, 0, 0);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);


	//bed box top
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.15 / 10.0f, 1.75 / 10.0f, -4.00 / 10.0f));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.25 / 10.0f, .2 / 10.0f, 2.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);




	//bed stand2 er nicher
	translateMatrix = glm::translate(identityMatrix, glm::vec3(4.363 / 10.0, 0.1 / 10.0, -5.00 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(.7 / 10.0f, .5 / 10.0f, 0.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.0f, 0, 0);
	cube.setMaterialisticEimu(0.0f, 0, 0);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);


	//bed stand3
	translateMatrix = glm::translate(identityMatrix, glm::vec3(4.363 / 10.0, 0.5 / 10.0, -12.5 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(.7 / 10.0f, 7.0 / 10.0f, 0.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//bed stand4
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.9 / 10.0, 0.5 / 10.0, -12.5 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(.7f / 10.0, 7.0 / 10.0f, 0.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//bed stand3 er nicher
	translateMatrix = glm::translate(identityMatrix, glm::vec3(4.363 / 10.0, 0.1 / 10.0, -12.5 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(.7 / 10.0f, .5 / 10.0f, 0.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.0f, 0, 0);
	cube.setMaterialisticEimu(0.0f, 0, 0);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//bed stand4 er niche 
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.9 / 10.0, 0.1 / 10.0, -12.5 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(.7f / 10.0, .5 / 10.0f, 0.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.0f, 0, 0);
	cube.setMaterialisticEimu(0.0f, 0, 0);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//standupper
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.1 / 10.0, 7.4 / 10.0, -13.00 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.4 / 10.0f, 0.35 / 10.0f, 8.9 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);


	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.7123 / 10.0, 7.7 / 10.0, -4.1/ 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.7 / 10.0f, 0.1 / 10.0f, .2 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.392f, 0.196f, 0.039f);
	cube.setMaterialisticEimu(0.392f, 0.196f, 0.039f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);


	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.8 / 10.0, 7.4 / 10.0, -12.9 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.8 / 10.0f, 1.0 / 10.0f, 8.72 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.7123 / 10.0, 8.4 / 10.0, -4.2 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.7 / 10.0f, 0.1 / 10.0f, .2 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.392f, 0.196f, 0.039f);
	cube.setMaterialisticEimu(0.392f, 0.196f, 0.039f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);


	translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.1 / 10.0, 8.4 / 10.0, -13.00 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.4 / 10.0f, 0.25 / 10.0f, 8.9 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.1 / 10.0, 8.4 / 10.0, -13.0 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.4 / 10.0f, 0.25 / 10.0f, 8.9 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.545f, 0.271f, 0.039f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.039f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);


	//bed er pichon
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.0 / 10.0, (0.1 + 0.15) / 10.0, -12.00 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.0 / 10.0f, 6.7 / 10.0f, 1.0f / 10.0));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.8039f, 0, 0);
	cube.setMaterialisticEimu(0.8039f, 0, 0);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//blanket
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.0 / 10.0, 2.2 / 10.0, -12.00 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.0 / 10.0f, 0.2 / 10.0f, 3.8 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.7373f, 0.6745f, 0.5843f);
	cube.setMaterialisticEimu(0.7373f, 0.6745f, 0.5843f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//pillow
	translateMatrix = glm::translate(identityMatrix, glm::vec3(0.5 / 10.0, 2.2 / 10.0, -12.00 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0 / 10.0f, 0.6 / 10.0f, 3.0 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.8039f, 0.5216f, 0.2471f);
	cube.setMaterialisticEimu(0.8039f, 0.5216f, 0.2471f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);


	//carpet


	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.0 / 10.0, (0.1 + 0.15) / 10.0, 5.00 / 10.0));
	//rotateYMatrix = glm::rotate(identityMatrix, glm::radians(), glm::vec3(-.2f, -1.0f, 1.0f));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.0 / 10.0f, 0.4 / 10.0f, 5.0 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.502f, 0, 0);
	cube.setMaterialisticEimu(0.502f, 0, 0);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);




}


*/




#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"
#include "Cylinder.h"
#include "sphere.h"
#include "cube.h"


void bed(Cube& cube, Shader& lightingShader, glm::mat4 als, float r, float g, float b)
{

	float rotateAngle_Y = 0.0;
	glm::mat4 rotateY = glm::mat4(1.0f);
	glm::mat4 rotateZ = glm::mat4(1.0f);
	float rotateAngle_Z = 0.0f;


	glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

	//bedbody wood
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.0 / 10, (0.1 + 0.15) / 10, -12.00 / 10));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.0 / 10.0f, 1.0 / 10.0f, 8.0 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.502f, 0, 0);
	cube.setMaterialisticEimu(0.451f, 0.165f, 0.051f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//bedbody
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.0 / 10, (0.1 + 0.15 + 1.0) / 10, -12.00 / 10));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.0 / 10.0f, 1.0 / 10.0f, 8.0 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.502f, 0, 0);
	cube.setMaterialisticEimu(r, g, b);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//bed stand1
	translateMatrix = glm::translate(identityMatrix, glm::vec3((-1.9 / 10) + .05, (0.5 / 10) + .33, -5.00 / 10));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(.7 / 10.0f, 7.0 / 10.0f, 0.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.545f, 0.271f, 0.075f);
	Cylinder stand1 = Cylinder(.5, 1.0);
	stand1.drawCylinder(lightingShader, model, 0.247f, 0.114f, 0.043f);


	//bed stand2
	translateMatrix = glm::translate(identityMatrix, glm::vec3((4.363 / 10) + .025, (0.5 / 10) + .33, -5.00 / 10));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(.7 / 10.0f, 7.0 / 10.0f, 0.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.545f, 0.271f, 0.075f);
	Cylinder stand2 = Cylinder(.5, 1.0);
	stand2.drawCylinder(lightingShader, model, 0.247f, 0.114f, 0.043f);

	//bed stand1 er nicher
	translateMatrix = glm::translate(identityMatrix, glm::vec3((-1.75 / 10), 0.1 / 10.0f, -5.30 / 10.0f));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(.7 / 10.0f, .5 / 10.0f, 0.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.0f, 0, 0);
	cube.setMaterialisticEimu(0.0f, 0, 0);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//bed box bottom
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.15 / 10.0f, 0.1 / 10.0f, -4.00 / 10.0f));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.25 / 10.0f, 1.5 / 10.0f, 2.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.302f, 0.169f, 0.027f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//bed box middle
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.15 / 10.0f, 1.6 / 10.0f, -4.00 / 10.0f));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.25 / 10.0f, .25 / 10.0f, 2.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.0f, 0, 0);
	cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//bed box top
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.15 / 10.0f, 1.75 / 10.0f, -4.00 / 10.0f));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.25 / 10.0f, .2 / 10.0f, 2.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.302f, 0.169f, 0.027f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);




	//bed stand2 er nicher
	translateMatrix = glm::translate(identityMatrix, glm::vec3((4.275 / 10), 0.1 / 10.0, -5.35 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(.7 / 10.0f, .5 / 10.0f, 0.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.0f, 0, 0);
	cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//bed stand3
	translateMatrix = glm::translate(identityMatrix, glm::vec3((4.275 / 10) + .025, (0.5 / 10.0) + .33, -12.5 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(.7 / 10.0f, 7.0 / 10.0f, 0.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.545f, 0.271f, 0.075f);
	Cylinder stand3 = Cylinder(.5, 1.0);
	stand3.drawCylinder(lightingShader, model, 0.247f, 0.114f, 0.043f);

	//bed stand4
	translateMatrix = glm::translate(identityMatrix, glm::vec3((-1.9 / 10.0) + .0625, (0.5 / 10.0) + .33, -12.5 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(.7f / 10.0, 7.0 / 10.0f, 0.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.545f, 0.271f, 0.075f);
	Cylinder stand4 = Cylinder(.5, 1.0);
	stand4.drawCylinder(lightingShader, model, 0.247f, 0.114f, 0.043f);

	//bed stand3 er nicher
	translateMatrix = glm::translate(identityMatrix, glm::vec3((4.5 / 10) - .025, 0.1 / 10.0, -12.75 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(.7 / 10.0f, .5 / 10.0f, 0.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.0f, 0, 0);
	cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//bed stand4 er niche 
	translateMatrix = glm::translate(identityMatrix, glm::vec3((-1.0 / 10.0) - .0625, 0.1 / 10.0, -12.75 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(.7f / 10.0, .5 / 10.0f, 0.7 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.0f, 0, 0);
	cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//standupper
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.1 / 10.0, 7.4 / 10.0, -13.00 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.4 / 10.0f, 0.35 / 10.0f, 8.9 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);


	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.7123 / 10.0, 7.7 / 10.0, -4.1 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.7 / 10.0f, 0.1 / 10.0f, .2 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.392f, 0.196f, 0.039f);
	cube.setMaterialisticEimu(0.451f, 0.165f, 0.051f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);


	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.8 / 10.0, 7.4 / 10.0, -12.9 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.8 / 10.0f, 1.0 / 10.0f, 8.72 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.7123 / 10.0, 8.4 / 10.0, -4.2 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.7 / 10.0f, 0.1 / 10.0f, .2 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.392f, 0.196f, 0.039f);
	cube.setMaterialisticEimu(0.451f, 0.165f, 0.051f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);


	translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.1 / 10.0, 8.4 / 10.0, -13.00 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.4 / 10.0f, 0.25 / 10.0f, 8.9 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.1 / 10.0, 8.4 / 10.0, -13.0 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.4 / 10.0f, 0.25 / 10.0f, 8.9 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.545f, 0.271f, 0.039f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.039f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);


	//bed er pichon
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.0 / 10.0, (0.1 + 0.15) / 10.0, -12.00 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.0 / 10.0f, 7.3 / 10.0f, 1.0f / 10.0));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.8039f, 0, 0);
	cube.setMaterialisticEimu(r, g, b);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//blanket
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.0 / 10.0, 2.2 / 10.0, -8.00 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.0 / 10.0f, 0.2 / 10.0f, 3.8 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.7373f, 0.6745f, 0.5843f);
	cube.setMaterialisticEimu(0.7373f, 0.6745f, 0.5843f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//pillow
	translateMatrix = glm::translate(identityMatrix, glm::vec3(1.5 / 10.0, 2.5 / 10.0, -10.00 / 10.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0 / 10.0f, 0.6 / 10.0f, 3.0 / 10.0f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cube, lightingShader, model, 0.8039f, 0.5216f, 0.2471f);
	Sphere pillow = Sphere(1.0);
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, .45f, .45));
	pillow.drawSphere(lightingShader, model * scaleMatrix, 0.8039f, 0.5216f, 0.2471f);

}