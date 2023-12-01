#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"
#include "sphere.h"
#include "cylinder.h"
#include "candles.h"

void wallFireHolder(Cube& cube, Shader& lightingShader, glm::mat4 als)
{

	glm::mat4 temp = glm::mat4(1.0f);
	glm::mat4 temp2 = glm::mat4(1.0f);
	glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, ztranslate, xtranslate;

	//////////////////////////////////sphere and cylinder
	Sphere sphere1 = Sphere();

	glm::mat4 modelForSphere = glm::mat4(1.0f);
	glm::mat4 modelForCylinder = glm::mat4(1.0f);

	{
		///bottom
		temp = als;
		temp2 = modelForCylinder;
		Cylinder cylinder1 = Cylinder(.1, 1.5);
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.75, 0.0f));
		rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-35.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		als = als * modelForCylinder * translateMatrix * rotateZMatrix;
		cylinder1.drawCylinder(lightingShader, als, 0.545f, 0.270f, 0.075f);
		cylinder1.drawCylinder(lightingShader, als * (glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f))), 0.545f, 0.270f, 0.075f);
		als = temp;
		modelForCylinder = temp2;


		//stand 1
		temp = als;
		temp2 = modelForCylinder;
		Cylinder cylinder2 = Cylinder(.05, .8);
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.1f, 1.1, 0.0f));
		rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		als = als * modelForCylinder * translateMatrix * rotateZMatrix;
		cylinder2.drawCylinder(lightingShader, als, 0.545f, 0.270f, 0.075f);
		cylinder2.drawCylinder(lightingShader, als * (glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f))), 0.545f, 0.270f, 0.075f);
		als = temp;
		modelForCylinder = temp2;

		temp = als;
		temp2 = modelForCylinder;
		Cylinder cylinder3 = Cylinder(.05, 0.5);
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.25f, 0.7, 0.0f));
		rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		als = als * modelForCylinder * translateMatrix * rotateZMatrix;
		cylinder3.drawCylinder(lightingShader, als, 0.545f, 0.270f, 0.075f);
		cylinder3.drawCylinder(lightingShader, als * (glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f))), 0.545f, 0.270f, 0.075f);
		als = temp;
		modelForCylinder = temp2;
	}
	//////////////////////
	/*
	float rotateAngle_Y = 0.0;
	//base
	for (float i = 0.0f; i < 360.0f; i += 2.50f) {
		//Center
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.35, 1.29, 0.0));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y + i), glm::vec3(0.0f, 1.0f, 0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.35, 0.15, 0.25));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		drawCube(cubeVAO, lightingShader, als, 0.0f, 0.0f, 0.0f); //this model is later sent to the vertex shader. //altogether is a matrix that is multiplied with every parts of the bed, so everything is part of Altogether. when rotated, everything is rotated AllTogether
		//glBindVertexArray(VAO);
		als = temp;
	}
	*/
	temp = als;
	translateMatrix = glm::translate(identityMatrix, glm::vec3(0.35 - .5 , 1.29, -.5));
	//rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y + i), glm::vec3(0.0f, 1.0f, 0.0f));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 0.15, 1.0));
	als = als * translateMatrix  * scaleMatrix;
	
	//drawCube(cubeVAO, lightingShader, als, 0.0f, 0.0f, 0.0f); //this model is later sent to the vertex shader. //altogether is a matrix that is multiplied with every parts of the bed, so everything is part of Altogether. when rotated, everything is rotated AllTogether
	
	cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, als);
	als = temp;
}



void ceilLight(Cube& cube, Shader& lightingShader, glm::mat4 als)
{

	glm::mat4 temp = glm::mat4(1.0f);
	glm::mat4 temp2 = glm::mat4(1.0f);
	glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, ztranslate, xtranslate;

	//bottom round bairer and vitorer circle
	{
		Cylinder bottomRoundBairer = Cylinder(1.5, .5);
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 6.0f, 0.0f));
		als = als * translateMatrix;
		bottomRoundBairer.drawCylinder(lightingShader, als, 0.545f, 0.270f, 0.075f);
		als = temp;
	}
	//bottom round vitorer and vitorer circle
	{
		Cylinder bottomRoundVitorer = Cylinder(1.25, .5);
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 6.0f, 0.0f));
		als = als * translateMatrix;
		bottomRoundVitorer.drawCylinder(lightingShader, als, 0.545f, 0.270f, 0.075f);
		als = temp;
	}
	//top round bairer and vitorer circle
	{
		Cylinder topRoundBairer = Cylinder(1.0, .5);
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 7.0f, 0.0f));
		als = als * translateMatrix;
		topRoundBairer.drawCylinder(lightingShader, als, 0.545f, 0.270f, 0.075f);
		als = temp;
	}
	//top round vitorer and vitorer circle
	{
		Cylinder topRoundVitorer = Cylinder(.75, .5);
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 7.0f, 0.0f));
		als = als * translateMatrix;
		topRoundVitorer.drawCylinder(lightingShader, als, 0.545f, 0.270f, 0.075f);
		als = temp;
	}
	//CANDLES
	//bottom round candles
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(1.3f, 3.2f, 0.0f));
		als = als * translateMatrix;
		candle(cube, lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.3f, 3.2f, 0.0f));
		als = als * translateMatrix;
		candle(cube, lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 3.2f, 1.3f));
		als = als * translateMatrix;
		candle(cube, lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 3.2f, -1.3f));
		als = als * translateMatrix;
		candle(cube, lightingShader, als);
		als = temp;

		///beka gula
		
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(1.0f, 3.2f, 1.0f));
		als = als * translateMatrix;
		candle(cube, lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(1.0f, 3.2f, -1.0f));
		als = als * translateMatrix;
		candle(cube, lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.0f, 3.2f, 1.0f));
		als = als * translateMatrix;
		candle(cube, lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.0f, 3.2f, -1.0f));
		als = als * translateMatrix;
		candle(cube, lightingShader, als);
		als = temp;

	}

	//top round candles
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.8f, 4.2f, 0.0f));
		als = als * translateMatrix;
		candle(cube, lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.8f, 4.2f, 0.0f));
		als = als * translateMatrix;
		candle(cube, lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 4.2f, 0.8f));
		als = als * translateMatrix;
		candle(cube, lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 4.2f, -0.8f));
		als = als * translateMatrix;
		candle(cube, lightingShader, als);
		als = temp;

	}

	//cross
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.4, 6.0f, 0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.8f, .1, 0.25));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 6.0f,-1.4f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.25, .1, 2.8f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.9, 7.0f, 0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.8f, .1, 0.25));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 7.0f, -0.9f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.25, .1, 1.8f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;
	}

	//SPIKES
	//bottom round 
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(1.3f, 6.0f, 0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 3.0f, .1f));
		rotateZMatrix = glm::rotate(identityMatrix, glm::radians(22.5f), glm::vec3(0.0f, 0.0f, 1.0f));
		als = als * translateMatrix * rotateZMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.3f, 6.0f, 0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 3.0f, .1f));
		rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-22.5f), glm::vec3(0.0f, 0.0f, 1.0f));
		als = als * translateMatrix * rotateZMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 6.0f, 1.3f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 3.0f, .1f));
		rotateXMatrix = glm::rotate(identityMatrix, glm::radians(-22.5f), glm::vec3(1.0f, 0.0f, 0.0f));
		als = als * translateMatrix * rotateXMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 6.0f, -1.3f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 3.0f, .1f));
		rotateXMatrix = glm::rotate(identityMatrix, glm::radians(22.5f), glm::vec3(1.0f, 0.0f, 0.0f));
		als = als * translateMatrix * rotateXMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);;
		als = temp;

		///beka gula

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(1.0f, 6.0f, 1.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 3.0f, .1f));
		rotateXMatrix = glm::rotate(identityMatrix, glm::radians(-22.5f), glm::vec3(1.0f, 0.0f, 0.0f));
		rotateZMatrix = glm::rotate(identityMatrix, glm::radians(22.5f), glm::vec3(0.0f, 0.0f, 1.0f));
		als = als * translateMatrix * rotateXMatrix * rotateZMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(1.0f, 6.0f, -1.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 3.0f, .1f));
		rotateXMatrix = glm::rotate(identityMatrix, glm::radians(22.5f), glm::vec3(1.0f, 0.0f, 0.0f));
		rotateZMatrix = glm::rotate(identityMatrix, glm::radians(22.5f), glm::vec3(0.0f, 0.0f, 1.0f));
		als = als * translateMatrix * rotateXMatrix * rotateZMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.0f, 6.0f, 1.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 3.0f, .1f));
		rotateXMatrix = glm::rotate(identityMatrix, glm::radians(-22.5f), glm::vec3(1.0f, 0.0f, 0.0f));
		rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-22.5f), glm::vec3(0.0f, 0.0f, 1.0f));
		als = als * translateMatrix * rotateXMatrix * rotateZMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.0f, 6.0f, -1.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 3.0f, .1f));
		rotateXMatrix = glm::rotate(identityMatrix, glm::radians(22.5f), glm::vec3(1.0f, 0.0f, 0.0f));
		rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-22.5f), glm::vec3(0.0f, 0.0f, 1.0f));
		als = als * translateMatrix * rotateXMatrix * rotateZMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

	}

	//main stand line
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.25f, 8.25f, -0.25f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5f, 2.0f, .5f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;
	}
}

#pragma once
