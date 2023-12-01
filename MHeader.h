#pragma once
#ifndef MHEADER_H
#define MHEADER_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<stack>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "bed.h"
#include "shader.h"
#include "camera.h"
#include "basic_camera.h"
#include "pointLight.h"
#include "directionalLight.h"
#include "SpotLight.h"
#include "walls.h"
#include "roundTable.h"
#include "sofa.h"
#include "chair.h"
#include "Lamp.h"
#include "Pillow.h"
#include <iostream>
#include "dining.h"
#include "almari.h"
#include "bookShelf.h"
#include "benchtoll.h"
#include "diningwithoutchair.h"
#include "sofatable.h"
#include "staircase.h"
#include "sphere.h"
#include "cylinder.h"
#include "stb_image.h"
#include "cube.h"
#include "GreatHall.h"
#include "Library.h"
#include "librarybenchtool.h"
#include "wallFireHolder.h"
#include "bedroom.h"
#include "floorlampholder.h"
#include "classroom.h"
#include "CustomObject.h"
#include "Triangle.h"
#include "halfcylinder.h"
#include "Trapezium.h"
#include "parabola.h"
#include "potionClassroom.h"
#include "Castle.h"
#include "pyramid.h"
#include "sphere2.h"
#include "flying.h"

// settings
const unsigned int SCR_WIDTH = 1400;
const unsigned int SCR_HEIGHT = 800;

// modelling transform
float rotateAngle_X = 0.0;
float rotateAngle_Y = 0.0;
float rotateAngle_Z = 0.0;
float rotateAxis_X = 0.0;
float rotateAxis_Y = 0.0;
float rotateAxis_Z = 1.0;
float translate_X = 0.0;
float translate_Y = 0.0;
float translate_Z = 0.0;
float scale_X = 1.0;
float scale_Y = 1.0;
float scale_Z = 1.0;

bool doorOpen = false;

//bookshelf er jonno code
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<double> dis(0.0, 1.0);

float colorArray[300];
// bottle er jonno code
int binaryArray[300];





// camera
Camera camera(glm::vec3(3.0f, 8.0f, 137.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
float lastZ = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

float eyeX = 0.0, eyeY = 1.0, eyeZ = 3.0;
float lookAtX = 0.0, lookAtY = 0.0, lookAtZ = 0.0;
glm::vec3 V = glm::vec3(0.0f, 1.0f, 0.0f);
BasicCamera basic_camera(eyeX, eyeY, eyeZ, lookAtX, lookAtY, lookAtZ, V);
const int NR_POINT_LIGHTS = 28;

// positions of the point lights
glm::vec3 pointLightPositions[] = {
    glm::vec3(-21.0f,  4.8f,  7.0f),
    glm::vec3(70.0f,  15.0f,  72.0f),
    glm::vec3(-60.0f,  15.0f, 72.0f),
    glm::vec3(-34.5f,  4.8f,  5.0f),
    glm::vec3(-8.0f,  4.8f,  5.0f),
    glm::vec3(-8.0f,  4.8f,  25.0f),
    glm::vec3(5.0f,  4.8f,  7.0f),
    glm::vec3(5.0f,  4.8f,  35.0f),
    glm::vec3(28.0f,  11.0f,  2.5f),
    glm::vec3(31.0f,  11.0f,  -6.0f),
    glm::vec3(21.0f,  25.0f,  -5.0f),
    glm::vec3(21.0f,  25.0f,  4.0f),

    glm::vec3(-17.0f,  14.5f,  10.0f),
    glm::vec3(-17.0f,  14.5f,  -5.0f),
    glm::vec3(-37.5f,  14.5f,  10.0f),
    glm::vec3(-37.5f,  14.5f,  -5.0f),
    glm::vec3(-11.0f,  14.5f,  10.0f),
    glm::vec3(-11.0f,  14.5f,  -5.0f),
    glm::vec3(8.0f,  14.5f,  10.0f),
    glm::vec3(8.0f,  14.5f,  -5.0f),

    glm::vec3(0.0f,  15.0f, 72.0f),
    glm::vec3(-10.0f,  15.0f,  72.0f),
    glm::vec3(-30.0f,  15.0f,  72.0f),
    glm::vec3(-50.0f,  15.0f, 72.0f),

    glm::vec3(10.0f,  15.0f,  72.0f),
    glm::vec3(30.0f,  15.0f, 72.0f),
    glm::vec3(50.0f,  15.0f,  72.0f),
    glm::vec3(60.0f,  15.0f,  72.0f)
};

PointLight pointlights[NR_POINT_LIGHTS+2];
bool pointLightInit = false;
void initPointLights(){
    if(pointLightInit) return;
    pointLightInit = true;
    for(int i=0;i<NR_POINT_LIGHTS;i++){
        pointlights[i] = PointLight(
            pointLightPositions[i].x, pointLightPositions[i].y, pointLightPositions[i].z,  // position
            0.3f, 0.3f, 0.3f,     // diffuse
            1.0f, 1.0f, 1.0f,
            1.0f, 1.0f, 1.0f,        // specular
            1.0f,   //k_c
            0.09f,  //k_l
            0.032f, //k_q
            i      // light number
        );
    }
}


/*

DirLight dirLight(
        -0.2f, -1.0f, -0.3f,
        0.3f, 0.3f, 0.3f,
        1.0f, 1.0f, 1.0f,     // diffuse
        1.0f, 1.0f, 1.0f
);
*/
SpotLight spotLight(5.0f, 9.8f, 2.5f,
    0, -1.0f, 0, 0.05f,
    0.05f, 0.05f,
    0.8f, 0.8f, 0.8f,
    1.0f, 1.0f, 1.0f, glm::cos(glm::radians(12.5f)), glm::cos(glm::radians(21.5f)));
/*
SpotLight spotLight(
    -3.50f, 4.0f, -2.0f,
    0.6f, -1.0f, 0.5f,
    0.5f, 0.0f, 0.5f,
    1.0f, 0.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,
    0.09f,
    0.032f,
    12.5f,
    15.0f
);
*/
DirLight dirLight(
    -0.2f, -1.0f, -0.3f,
    0.05f, 0.05f, 0.05f,
    .5f, 0.5f, 0.5f,     // diffuse
    0.5f, 0.5f, 0.5f
);

// light settings
bool PointToggle1 = true;
bool PointToggle3 = true;
bool ambientToggle = true;
bool diffuseToggle = true;
bool specularToggle = true;


// timing
float deltaTime = 0.0f;    // time between current frame and last frame
float lastFrame = 0.0f;

string diffuseMapPath = "Texture/container2.png";
string specularMapPath = "Texture/container2_specular.png";

string woodtablediffMapPath = "Texture/wood_table_001_diff_4k.jpg";
string woodtablespecMapPath = "Texture/wood_table_001_disp_4k.png";
string brickdiffMapPath = "Texture/patio_tiles_diff_4k.png";
string brickspecMapPath = "Texture/patio_tiles_disp_4k.png";
string bedroomtilesdiffMapPath = "Texture/woodfloordiff.png";
string bedroomtilesspecMapPath = "Texture/woodfloordisp.png";

string woodfloordiffMapPath = "Texture/dark_wood_diff_4k.jpg";
string woodfloorspecMapPath = "Texture/dark_wood_disp_4k.png";

string potionroomwalltilesdiffMapPath = "Texture/japanese_stone_wall_diff_4k.png";
string potionroomwalltilesspecMapPath = "Texture/japanese_stone_wall_disp_4k.png";
string potionroomwallMapPath = "Texture/5a381e73887138.2523300715136272515589.png";

string classroomwalltilesdiffMapPath = "Texture/floor_tiles_04_diff_4k.jpg";
string classroomwalltilesspecMapPath = "Texture/floor_tiles_04_disp_4k.png";
string classroomwoodfloordiffMapPath = "Texture/patio_tiles_diff_4k.png";
string classroomwoodfloorspecMapPath = "Texture/patio_tiles_disp_4k.png";
string windowdiffMapPath = "Texture/kisspng-door-wood.png";
string akashiwindowMapPath = "Texture/akashiwindow.png";
string bedroomakashiwindowMapPath = "Texture/akashiwindowbedroom.png";

string backgroundMapPath = "Texture/window.jpeg";
string redcarpetMapPath = "Texture/redcarpet.png";
string greencarpetMapPath = "Texture/greencarpet.png";
string bedroomAgunMapPath = "Texture/agun (1).png";
string bedroomPhotoFrame1 = "Texture/photoframe1.jpg";
string bedroomPhotoFrame2 = "Texture/photoframe2.jpg";

string castleWallMapPath = "Texture/castle wall.jpg";
string grassMapPath = "Texture/grass.jpg";
string castleDoor = "Texture/castledoor.jpg";


unsigned int castleWallMap;
unsigned int diffMap;
unsigned int specMap;
unsigned int woodtablediffMap;
unsigned int woodtablespecMap;
unsigned int brickdiffMap;
unsigned int brickspecMap;
unsigned int bedroomtilesdiffMap;
unsigned int bedroomtilesspecMap;
unsigned int windowdiffMap;
unsigned int akashiwindowMap;
unsigned int woodfloordiffMap;
unsigned int woodfloorspecMap;
unsigned int potionroomwalltilesdiffMap;
unsigned int potionroomwalltilesspecMap;
unsigned int potionroomwallMap;
unsigned int classroomwalltilesdiffMap;
unsigned int classroomwalltilesspecMap;
unsigned int classroomwoodfloordiffMap;
unsigned int classroomwoodfloorspecMap;

unsigned int backgroundMap;
unsigned int redcarpetMap;
unsigned int greencarpetMap;
unsigned int bedroomakashiwindowMap;
unsigned int bedroomAgunMap;
unsigned int bedroomPhotoFrame1Map;
unsigned int bedroomPhotoFrame2Map;
unsigned int grassMap;
unsigned int castleDoorMap;

unsigned int loadTexture(char const* path, GLenum textureWrappingModeS, GLenum textureWrappingModeT, GLenum textureFilteringModeMin, GLenum textureFilteringModeMax)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format = GL_RED;
        //cout << nrComponents << endl;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);



        (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, textureWrappingModeS);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, textureWrappingModeT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, textureFilteringModeMin);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, textureFilteringModeMax);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        assert(false); //fail the code
        stbi_image_free(data);
    }

    return textureID;
}

void loadAllTextures() {
    castleWallMap = loadTexture(castleWallMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    grassMap = loadTexture(grassMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    castleDoorMap = loadTexture(castleDoor.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

    diffMap = loadTexture(diffuseMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    specMap = loadTexture(specularMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    woodtablediffMap = loadTexture(woodtablediffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    woodtablespecMap = loadTexture(woodtablespecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    brickdiffMap = loadTexture(brickdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    brickspecMap = loadTexture(brickspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    bedroomtilesdiffMap = loadTexture(bedroomtilesdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    bedroomtilesspecMap = loadTexture(bedroomtilesdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    windowdiffMap = loadTexture(windowdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    akashiwindowMap = loadTexture(akashiwindowMapPath.c_str(), GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    woodfloordiffMap = loadTexture(woodfloordiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    woodfloorspecMap = loadTexture(woodfloorspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    potionroomwalltilesdiffMap = loadTexture(potionroomwalltilesdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    potionroomwalltilesspecMap = loadTexture(potionroomwalltilesspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    potionroomwallMap = loadTexture(potionroomwallMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    classroomwalltilesdiffMap = loadTexture(classroomwalltilesdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    classroomwalltilesspecMap = loadTexture(classroomwalltilesspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    classroomwoodfloordiffMap = loadTexture(classroomwoodfloordiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    classroomwoodfloorspecMap = loadTexture(classroomwoodfloorspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

    backgroundMap = loadTexture(backgroundMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    redcarpetMap = loadTexture(redcarpetMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    greencarpetMap = loadTexture(greencarpetMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    bedroomakashiwindowMap = loadTexture(bedroomakashiwindowMapPath.c_str(), GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    bedroomAgunMap = loadTexture(bedroomAgunMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    bedroomPhotoFrame1Map = loadTexture(bedroomPhotoFrame1.c_str(), GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    bedroomPhotoFrame2Map = loadTexture(bedroomPhotoFrame2.c_str(), GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    
}

void setupLightInShader(Shader& lightingWithTextureShader) {
    initPointLights();
    for(int i=0;i<NR_POINT_LIGHTS;i++){
        pointlights[i].setUpPointLight(lightingWithTextureShader);
    }


    dirLight.setUpDirLight(lightingWithTextureShader);
    spotLight.setUpSpotLight(lightingWithTextureShader);
}
void turnoffPointLights(){
    for(int i=0;i<NR_POINT_LIGHTS;i++){
        pointlights[i].turnOff();
    }
}
void turnonPointLights() {
    for (int i = 0; i < NR_POINT_LIGHTS; i++) {
        pointlights[i].turnOn();
    }
}
void turnOffAmbient() {
    ambientToggle = false;
    dirLight.turnAmbientOff();
    spotLight.turnAmbientOff();
    for (int i = 0; i < NR_POINT_LIGHTS; i++) {
        pointlights[i].turnAmbientOff();
    }
}
void turnOnAmbient() {
    ambientToggle = true;
    dirLight.turnAmbientOn();
    spotLight.turnAmbientOn();
    for (int i = 0; i < NR_POINT_LIGHTS; i++) {
        pointlights[i].turnAmbientOn();
    }
}
void turnOffDiffuse() {
    diffuseToggle = false;
    dirLight.turnDiffuseOff();
    spotLight.turnDiffuseOff();
    for (int i = 0; i < NR_POINT_LIGHTS; i++) {
        pointlights[i].turnDiffuseOff();
    }
}
void turnOnDiffuse() {
    diffuseToggle = true;
    dirLight.turnDiffuseOn();
    spotLight.turnDiffuseOn();
    for (int i = 0; i < NR_POINT_LIGHTS; i++) {
        pointlights[i].turnDiffuseOn();
    }
}
void turnOffSpecular() {
    specularToggle = false;
    dirLight.turnSpecularOff();
    spotLight.turnSpecularOff();
    for (int i = 0; i < NR_POINT_LIGHTS; i++) {
        pointlights[i].turnSpecularOff();
    }
}
void turnOnSpecular() {
    specularToggle = true;
    dirLight.turnSpecularOn();
    spotLight.turnSpecularOn();
    for (int i = 0; i < NR_POINT_LIGHTS; i++) {
        pointlights[i].turnSpecularOn();
    }
}

#endif // MHEADER_H
