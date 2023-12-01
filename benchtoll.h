#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"
#include "halfsphere.h"
#include "sphere.h"
#include "Cylinder.h"
#include "tableTop.h"

void benchToll(Cube& cube, Shader& lightingShader, glm::mat4 als)
{

	glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;
	float rotateAngle_Y = 22.5;
	

	//toll top
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.1f, 0.5f, 0.2f));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, .1f, -0.5f));
	model = als * translateMatrix * scaleMatrix;
	cube.setMaterialisticEimu(0.451f, 0.165f, 0.051f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);
	//drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
	//toll left leg1
	translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .5f, 0.1f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//toll left leg2
	translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, -0.25));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .5f, 0.1f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//toll right leg1
	translateMatrix = glm::translate(identityMatrix, glm::vec3(2.75, 0.0, 0.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .5f, 0.1f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//toll right leg2
	translateMatrix = glm::translate(identityMatrix, glm::vec3(2.75, 0.0, -0.25));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .5f, 0.1f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);



	//bench top
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.1, .8, -0.5));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0, .1, -.75));
	rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y), glm::vec3(1.0f, 0.0f, 0.0f));
	//rotateXMatrix = glm::rotate(identityMatrix, glm::radians(), glm::vec3(1.375f, 1.25f, -0.875f));
	model = als * translateMatrix * rotateYMatrix * scaleMatrix;
	//drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.451f, 0.165f, 0.051f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//bench left leg1
	translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, -1.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 1.05f, 0.1f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//bench left leg2
	translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, -0.75));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .95, 0.1f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//bench right leg1
	translateMatrix = glm::translate(identityMatrix, glm::vec3(2.75, 0.0, -1.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 1.05f, 0.1f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//bench right leg2
	translateMatrix = glm::translate(identityMatrix, glm::vec3(2.75, 0.0, -0.75));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .95, 0.1f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);


	//left lomba kath
	translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.2));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .1f, -1.4f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);

	//right lomba kath
	translateMatrix = glm::translate(identityMatrix, glm::vec3(2.75, 0.0, 0.2));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .1f, -1.4f));
	model = als * translateMatrix * scaleMatrix;
	//drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
	cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, model);
}



void Table(Cube& cube, Shader& lightingShader, glm::mat4 als)
{

	glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model,temp;
	float rotateAngle_Y = 22.5;


	////////TABLE MAIN
	///table top
	temp = als;
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-5.0, 2.01f, -10.0f));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, .25f, 3.0f));
	als = als * translateMatrix * scaleMatrix;
	cube.setMaterialisticEimu(0.302f, 0.169f, 0.027f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, als);
	als = temp;

	///table top things
	temp = als;
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.0, 2.26f, -9.0f));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 1.0f, 1.0f));
	als = als * translateMatrix * scaleMatrix;
	cube.setMaterialisticEimu(0.0f, 0.0f, 1.0f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, als);
	als = temp;
	

	temp = als;
	Sphere sphere(0.5);
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.5, 2.75f, -9.0f));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 1.0f, 1.0f));
	als = als * translateMatrix * scaleMatrix;
	sphere.drawSphere(lightingShader, als, 0.376f, 0.616f, 0.749f);
	als = temp;

	temp = als;
	HalfSphere halfsphere(0.5);
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-4.5, 2.25f, -9.0f));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 1.0f, 1.0f));
	als = als * translateMatrix * scaleMatrix;
	halfsphere.drawHalfSphere(lightingShader, als, 0.0f, 0.0f, 0.0f);
	als = temp;


	temp = als;
	Cylinder cylinder(0.5, 1.5);
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.5, 3.0f, -9.0f));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 1.0f, 1.0f));
	als = als * translateMatrix * scaleMatrix;
	cylinder.drawCylinder(lightingShader, als, 0.0f, 0.2f, 0.055f);
	als = temp;




	///table back left leg
	temp = als;
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-5.0, 2.01f, -10.0f));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5f, -2.0, .5f));
	als = als * translateMatrix * scaleMatrix;
	cube.setMaterialisticEimu(0.302f, 0.169f, 0.027f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, als);
	als = temp;

	///table back right leg
	temp = als;
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.5, 2.01f, -10.0f));
	//scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5f, 2.0, .5f));
	als = als * translateMatrix * scaleMatrix;
	cube.setMaterialisticEimu(0.302f, 0.169f, 0.027f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, als);
	als = temp;

	///table front left leg
	temp = als;
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-5.0, 2.01f, -7.5f));
	//scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5f, 2.0, .5f));
	als = als * translateMatrix * scaleMatrix;
	cube.setMaterialisticEimu(0.302f, 0.169f, 0.027f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, als);
	als = temp;

	///table front right leg
	temp = als;
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.5, 2.01f, -7.5f));
	//scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5f, 2.0, .5f));
	als = als * translateMatrix * scaleMatrix;
	cube.setMaterialisticEimu(0.302f, 0.169f, 0.027f);
	cube.drawCubeWithMaterialisticProperty(lightingShader, als);
	als = temp;
}

void potionTable(Cube& cube, Shader& lightingShader, glm::mat4 als, float colorArray[])
{

	glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model, temp, ytranslate, ttranslate;
	float rotateAngle_Y = 22.5;


	////////TABLE MAIN
	///table top
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 3.0f, 0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0, .1f, 3.0f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.435f, 0.243f, 0.145f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;
		//DESIGN1
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2f, 2.75f, 0.2f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.6, .25f, 2.6f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.302f, 0.169f, 0.027f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		//DESIGN2
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 2.65f, 0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0, .1f, 3.0f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.435f, 0.243f, 0.145f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;
	}

	///table BOTTOM
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 1.25f, 0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0, .1f, 3.0f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.435f, 0.243f, 0.145f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;
		//DESIGN1
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2f, 1.0f, 0.2f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.6, .25f, 2.6f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.302f, 0.169f, 0.027f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		//DESIGN2
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, .85f, 0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0, .1f, 3.0f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.435f, 0.243f, 0.145f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;
	}


	//legs
	{
		//left behind
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2f, 2.65f, .2f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5, -2.75f, .5f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.302f, 0.169f, 0.027f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als * glm::translate(identityMatrix, glm::vec3(6.2f, 0.0f, 0.0f)));
		als = temp;

		//right behind
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2f, 2.65f, 2.3f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5, -2.75f, .5f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.302f, 0.169f, 0.027f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als * glm::translate(identityMatrix, glm::vec3(6.2f, 0.0f, 0.0f)));
		als = temp;
	}

	//table drawyers
	{
		//bottom 
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(1.4f, 1.35f, 0.2f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.25f, .35f, 2.6f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.302f, 0.169f, 0.027f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(1.4f, 1.35f + .35f, 0.2f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.25f, .1f, 2.6f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		//middle
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(1.4f, 1.35f + .35f + .1, 0.2f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.25f, .35f, 2.6f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.302f, 0.169f, 0.027f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(1.4f, 1.35f + .35f +.1 + .35, 0.2f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.25f, .1f, 2.6f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;
		//top
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(1.4f, 1.35f + .35f + .1 + .35 + .1, 0.2f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.25f, .35f, 2.6f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.302f, 0.169f, 0.027f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		// handle
		Sphere handle(0.1);
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(1.4f + .625, 1.35f + (.35/2.0), 0.2f + 2.6));
		als = als * translateMatrix;
		handle.drawSphere(lightingShader, als, 0.0f, 0.0f, 0.0f);
		handle.drawSphere(lightingShader, als* glm::translate(identityMatrix, glm::vec3(0.0, .45, 0.0)), 0.0f, 0.0f, 0.0f);
		handle.drawSphere(lightingShader, als* glm::translate(identityMatrix, glm::vec3(0.0, .9, 0.0)), 0.0f, 0.0f, 0.0f);
		als = temp;
	}

	//logs at left
	{
		temp = als;
		int index = 0;
		for(float j = 1.0; j < 4.0f; j = j + 1.0f)
		{
			for (float i = 0.0f; i < 3.0f; i = i + 1.0f)
			{
				index = index + 1;
				Cylinder logs = Cylinder(0.1, colorArray[index]);
				translateMatrix = glm::translate(identityMatrix, glm::vec3(1.4f + 1.3 + .1 + (.2 * i), 1.35f + colorArray[index] * .5, 0.2f + 2.6));
				logs.drawCylinder(lightingShader, als * translateMatrix * glm::translate(identityMatrix, glm::vec3(0.0, 0.0, - .2 * j)), 0.302f, 0.169f, 0.027f);
			}
		}
	}
	als = temp;


	//books at right
	int index = 0;
	temp = als;
	for (float j = 0; j < 2.0; j = j + 1.0)
	{
		ytranslate = glm::translate(identityMatrix, glm::vec3(0.0f, static_cast<float>(j), 0.0f));
		for (float i = 0.0; i < 6.0; i = i + 1.2)
		{
			ttranslate = glm::translate(identityMatrix, glm::vec3(static_cast<float>(i), 0.0f, 0.0f));
			translateMatrix = glm::translate(identityMatrix, glm::vec3(.75f, 1.35f, 2.1f));
			scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1, .45, .45));
			rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-5.0f), glm::vec3(0.0f, 0.0f, 1.0f));
			model = als * translateMatrix * scaleMatrix;
			cube.setMaterialisticEimu(colorArray[index], colorArray[index + 1], colorArray[index + 2]);
			cube.drawCubeWithMaterialisticProperty(lightingShader, model  *  ttranslate * ytranslate * rotateZMatrix);
			index = index + 3;
		}
	}
	als = temp;

	//TABLE TOP THINGS

	//hari
	{
		for(float i =0.0; i < 2.0; i = i + 1.0)
		{
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(0.5f + i * 3.0, 3.35f, 2.5f));
			scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.8f, 0.8f, 0.8f));
			als = als * translateMatrix * scaleMatrix;
			hari(cube, lightingShader, als);
			als = temp;
		}
	}

	//hari on stand
	{
		for (float i = 0.0; i < 1.0; i = i + 1.0)
		{
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(1.75f + i * 2.0, 3.0f, 2.0f));
			als = als * translateMatrix ;
			harionStand(cube, lightingShader, als);
			als = temp;
		}
	}

	//gamla on stand
	{
		for (float i = 0.0; i < 2.0; i = i + 1.0)
		{
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(0.5f + i * 2.0, 3.0f, .75f));
			als = als * translateMatrix;
			gamlaonStand(cube, lightingShader, als);
			als = temp;
		}
	}

	//bottle on table
	{
		for (float i = 0.0; i < 4.0; i = i + 3.0)
		{
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(1.0f + i * .55, 3.0f, 2.5f));
			scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.5f, 0.5f, 0.5f));
			als = als * translateMatrix * scaleMatrix;
			bottleonTable(cube, lightingShader, als);
			als = temp;
		}
	}
	

	
}


void potionToll(Cube& cube, Shader& lightingShader, glm::mat4 als, float colorArray[])
{

	glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model, temp, ytranslate, ttranslate;
	float rotateAngle_Y = 22.5;

	//SPIKES
	
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(1.8f, 0.0f, 0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 1.5f, .1f));
		rotateZMatrix = glm::rotate(identityMatrix, glm::radians(15.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		als = als * translateMatrix * rotateZMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(.2f, 0.0f, 0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 1.5f, .1f));
		rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-15.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		als = als * translateMatrix * rotateZMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(1.0f, 0.0f, .8f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 1.5f, .1f));
		rotateXMatrix = glm::rotate(identityMatrix, glm::radians(-15.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		als = als * translateMatrix * rotateXMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(1.0f, 0.0f, -.8f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 1.5f, .1f));
		rotateXMatrix = glm::rotate(identityMatrix, glm::radians(15.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		als = als * translateMatrix * rotateXMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);;
		als = temp;

		//toolseat
		{
			temp = als;
			Sphere toolseat(.8f);
			translateMatrix = glm::translate(identityMatrix, glm::vec3(1.0f, 1.5f, 0.0f));
			scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, .2f, 1.0f));
			als = als * translateMatrix * scaleMatrix;
			toolseat.drawSphere(lightingShader, als, 0.0f, 0.0f, 0.0f);
			als = temp;
		}
	}

}

#pragma once
