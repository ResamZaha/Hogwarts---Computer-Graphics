#include "MHeader.h"
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);
float doorAngle = 0.0f;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "CSE 4208: Computer Graphics Laboratory", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile our shader zprogram
    // ------------------------------------
    Shader lightingWithTextureShader("Shader/PhongShadingWithTexture/vertexShader.vs", "Shader/PhongShadingWithTexture/fragmentShader.fs");
    Shader lightingShader("Shader/PhongShading/vertexShader.vs", "Shader/PhongShading/fragmentShader.fs");
    Shader ourShader("Shader/vertexShader.vs", "Shader/fragmentShader.fs");

    std::vector<float> customObjectPoints = {
    -1.4600, 2.2050, 5.1000,
    -1.4500, 1.2800, 5.1000,
    -1.4600, 0.2400, 5.1000,
    -1.3800, 0.5800, 5.1000,
    -1.2450, 0.9300, 5.1000,
    -1.0650, 1.2550, 5.1000,
    -0.8350, 1.5300, 5.1000,
    -0.5950, 1.7600, 5.1000,
    -0.3400, 1.9500, 5.1000,
    -0.0850, 2.0850, 5.1000,
    0.2550, 2.2050, 5.1000,
    0.5500, 2.2500, 5.1000,
    -0.0650, 2.2650, 5.1000,
    -0.7150, 2.2600, 5.1000,
    -1.1800, 2.2450, 5.1000,
    -1.4550, 2.2200, 5.1000,
    };

    loadAllTextures();


    Cube cube = Cube(diffMap, specMap, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    
    //////////////////////////////////sphere and cylinder
    Sphere sphere = Sphere();
    Cylinder cylinder = Cylinder();
    CustomObject customObject(customObjectPoints, glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.5f, 0.5f, 0.5f), 32.0f);
    // Create a vertically half cylinder
    HalfPipe halfpipie = HalfPipe();
    Triangle triangle = Triangle();
    Trapezium trapezium = Trapezium();
    ParabolicSurface parabolicSurface = ParabolicSurface();
    //Sphere2  sphere2 = Sphere2(15.0f, 144, 72, glm::vec3(0.898f, 0.459f, 0.125f), glm::vec3(0.898f, 0.459f, 0.125f), glm::vec3(0.5f, 0.5f, 0.5f), 32.0f, classroomwoodfloorspecMap, classroomwoodfloorspecMap, 0.0f, 0.0f, 1.0f, 1.0f);

    
    ////////////////////////////////////////////////////////////////////////////////////////
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);



    //ourShader.use();
    //lightingShader.use();

    //bookshelf er code
    bool firstcall = true;
    for (int i = 0; i < 300; i++)
    {
        colorArray[i] = dis(gen);
    }
    //bottle er jonno code
    for (int i = 0; i < 300; ++i) {
        // Generate either 1 or 0
        binaryArray[i] = (dis(gen) < 0.5) ? 0 : 1;
    }

    float rotate1 = 0.0f;
    float move1 = 0.0f;
    float move2 = 0.0f;
    float rotationSpeed = 5.0f;
    float maxRotation = 180.0f;
    float currentRotation = 75.0f;
    bool isRotatingForward = true;
    float stairCount2 = 15.0f;
    float count = 0.0f;
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        
        // per-frame time logic
        // --------------------
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.667f, 0.855f, 0.929f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // be sure to activate shader when setting uniforms/drawing objects
        lightingWithTextureShader.use();
        lightingWithTextureShader.setVec3("viewPos", camera.Position);
        
        setupLightInShader(lightingWithTextureShader);

        /*
        lightingShader.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
        lightingShader.setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
        lightingShader.setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
        lightingShader.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
        */
        // activate shader

        lightingWithTextureShader.use();

        // pass projection matrix to shader (note that in this case it could change every frame)
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        //glm::mat4 projection = glm::ortho(-2.0f, +2.0f, -1.5f, +1.5f, 0.1f, 100.0f);
        lightingWithTextureShader.setMat4("projection", projection);

        // camera/view transformation
        glm::mat4 view = camera.GetViewMatrix();
        //glm::mat4 view = basic_camera.createViewMatrix();
        lightingWithTextureShader.setMat4("view", view);

        // Modelling Transformation
        glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model, temp, tempx,tempy;

        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X, translate_Y, translate_Z));
        rotateXMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(scale_X, scale_Y, scale_Z));
        model = translateMatrix * rotateXMatrix * rotateYMatrix * rotateZMatrix * scaleMatrix;
        lightingWithTextureShader.setMat4("model", model);
        temp = model;
        for (unsigned int i = 0; i < 1; i++)
        {

            model = glm::mat4(1.0f);
            model =  glm::scale(model, glm::vec3(.5f, .5f, .5f)); // Make it a smaller cube
            model =  glm::translate(model, pointLightPositions[i] *  glm::vec3(2.0f, 2.0f, 2.0f));
            //model = model * glm::scale(model, glm::vec3(.5, .5f, .5f)); // Make it a smaller cube
            //lightingWithTextureShader.setMat4("model", model);
            //lightingWithTextureShader.setVec3("color", glm::vec3(0.0, 0.0, 0.0));
            //cube.drawCubeWithMaterialisticProperty(lightingWithTextureShader, model);
            //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
            //cube.drawCube(ourShader, model, .8f, .8f, .8f);
            //lightingWithTextureShader.setMat4("model", model);
            cube.setMaterialisticEimu(1.0f, 1.0f, 1.0f);
            cube.drawCubeWithMaterialisticProperty(lightingWithTextureShader, model);
        }

        model = temp;

        //glBindVertexArray(cubeVAO);
        //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        //glDrawArrays(GL_TRIANGLES, 0, 36);
       // bed(cubeVAO, lightingShader, model); 
       //here the model matrix is the alTogether matrix

        // Draw the top half of the cylinder
        //halfpipie.drawHalfPipe(lightingWithTextureShader, model);

        // Draw the bottom half of the cylinder
        //halfpipie.drawHalfPipe(lightingWithTextureShader, model);
        //cylinder.drawCylinder(lightingWithTextureShader, model, 1.5f, 0.0f, 0.5f);
        

        //Sphere sphere = Sphere();
        //sphere2.setRadius(10.0f);
        //sphere.drawSphere(lightingShader, model, 0.0f, 1.0f, 0.0f);
        //sphere2.drawSphereWithTexture(lightingWithTextureShader, model);

                ///brooomStick
        {
            tempx = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, -20.0));
            tempy = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 20.0));
            temp = model;
            rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-60.0f), glm::vec3(0.0f, 0.0f, 1.0f));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-count), glm::vec3(0.0f, 1.0f, 0.0f));
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 10.0, 60.0));
            model = model * translateMatrix * tempx * rotateYMatrix * tempy * rotateZMatrix;
            broomStick(cube, lightingWithTextureShader, model);
            model = temp;

            temp = model;
            rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-60.0f), glm::vec3(0.0f, 0.0f, 1.0f));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(count + 100), glm::vec3(0.0f, 1.0f, 0.0f));
            translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.0, 10.0, 75.0));
            model = model * translateMatrix * tempx * rotateYMatrix * tempy * rotateZMatrix;
            broomStick(cube, lightingWithTextureShader, model);
            model = temp;


            temp = model;
            rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-60.0f), glm::vec3(0.0f, 0.0f, 1.0f));
            rotateYMatrix = glm::rotate(identityMatrix, glm::radians(count + 150), glm::vec3(0.0f, 1.0f, 0.0f));
            translateMatrix = glm::translate(identityMatrix, glm::vec3(10.0, 10.0, 70.0));
            model = model * translateMatrix * tempx * rotateYMatrix * tempy * rotateZMatrix;
            broomStick(cube, lightingWithTextureShader, model);
            model = temp;
            count = count + 5.0f;

        }


        //greatHall
        {
            temp = model;
            translateMatrix = glm::translate(identityMatrix, glm::vec3(-23.5, 7.2, 0.0));
            model = model * translateMatrix;
            greatHall(cube, lightingWithTextureShader, model, bedroomtilesdiffMap, bedroomtilesspecMap, brickdiffMap, brickspecMap, woodtablediffMap, woodtablespecMap, backgroundMap);
            model = temp;
        }


        //library
        {
            temp = model;
            translateMatrix = glm::translate(identityMatrix, glm::vec3(1.5, 7.2, 0.0));
            model = model * translateMatrix;
            library(cube, lightingWithTextureShader, model, colorArray, bedroomtilesdiffMap, bedroomtilesspecMap, brickdiffMap, brickspecMap, woodtablediffMap, woodtablespecMap);
            model = temp;

        }
        //bedroom 1
        {
            temp = model;
            translateMatrix = glm::translate(identityMatrix, glm::vec3(-7.5, 0.0, 7.5));
            model = model * translateMatrix;
            float houseName = 1.0f;
            bedroom(cube, lightingWithTextureShader, model, colorArray , houseName, bedroomakashiwindowMap, bedroomAgunMap , bedroomPhotoFrame1Map, bedroomPhotoFrame2Map,bedroomtilesdiffMap, bedroomtilesspecMap, brickdiffMap, brickspecMap, woodtablediffMap, woodtablespecMap, redcarpetMap, greencarpetMap);
            model = temp;
        }
        //bedroom 2
        {
            temp = model;
            translateMatrix = glm::translate(identityMatrix, glm::vec3(-34.0, 0.0, 7.5));
            model = model * translateMatrix;
            float houseName = 2.0f;
            bedroom(cube, lightingWithTextureShader, model, colorArray , houseName, bedroomakashiwindowMap, bedroomAgunMap , bedroomPhotoFrame1Map, bedroomPhotoFrame2Map,bedroomtilesdiffMap, bedroomtilesspecMap, brickdiffMap, brickspecMap, woodtablediffMap, woodtablespecMap, redcarpetMap, greencarpetMap);
            model = temp;
        }
        {
            temp = model;
            //translateMatrix = glm::translate(identityMatrix, glm::vec3(-54.1, 0.0, -1.0));
            translateMatrix = glm::translate(identityMatrix, glm::vec3(19.1f, 15.2, -1.0));
            model = model * translateMatrix;
            potionClassroom(cube, lightingWithTextureShader, model, colorArray, binaryArray, potionroomwallMap, woodfloordiffMap, woodfloorspecMap, potionroomwalltilesdiffMap, potionroomwalltilesspecMap);
            model = temp;
        }
        {
            temp = model;
            translateMatrix = glm::translate(identityMatrix, glm::vec3(34.6f, 0.0, -.75));
            model = model * translateMatrix;
            classroom(cube, lightingWithTextureShader, model, windowdiffMap, akashiwindowMap, woodfloordiffMap, woodfloorspecMap, classroomwalltilesdiffMap, classroomwalltilesspecMap);
            model = temp;
        }
        {
            //temp = model;
            //translateMatrix = glm::translate(identityMatrix, glm::vec3(34.6f, 0.0, -1.0));
            //model = model * translateMatrix;
             castle(cube, lightingWithTextureShader, model, potionroomwalltilesdiffMap, potionroomwalltilesspecMap, woodfloordiffMap, woodfloorspecMap, classroomwalltilesdiffMap, classroomwalltilesspecMap,doorAngle, castleWallMap, grassMap, castleDoorMap);
            //model = temp;
        }
        
        //SIRI 1
        tempx = glm::translate(identityMatrix, glm::vec3(-1.5, 0.0, 0.0));
        tempy = glm::translate(identityMatrix, glm::vec3(1.5, 0.0, 0.0));
        float stairCount = 26.0f;
        //////////staircase
        {
            //////////staircase
            {
                temp = model;
                translateMatrix = glm::translate(identityMatrix, glm::vec3(-16.5, 0.0, 27.5));
                if (rotate1 < 6.0f) {
                    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(currentRotation), glm::vec3(0.0f, 1.0f, 0.0f));
                    currentRotation += rotationSpeed;
                    rotate1 = rotate1 + 1.0f;
                    //cout<<currentRotation<<endl;
                }
                else if (rotate1 >= 6.0f && rotate1 < 12.0f) {
                    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(currentRotation), glm::vec3(0.0f, 1.0f, 0.0f));
                    currentRotation -= rotationSpeed;
                    rotate1 = rotate1 + 1.0f;
                    //cout << currentRotation << endl;
                }
                if (rotate1 >= 12.0f) {
                    rotate1 = 0.0f;
                    currentRotation = 75.0f;
                }
                model = model * translateMatrix * tempy * rotateYMatrix * tempx;
                stairCase(cube, lightingWithTextureShader, model, stairCount);

                model = temp;
            }
        }


        //SIRI 2
        tempx = glm::translate(identityMatrix, glm::vec3(-1.5, 0.0, 0.0));
        tempy = glm::translate(identityMatrix, glm::vec3(1.5, 0.0, 0.0));

        //////////staircase
        {
            //////////staircase
            {
                temp = model;
                rotateZMatrix = glm::rotate(identityMatrix, glm::radians(20.0f), glm::vec3(0.0f, 0.0f, 1.0f));
                rotateXMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                if (move1 < 11.0f) {
                    stairCount2 = stairCount2 + 2;
                    move2 = move2 + 1.5f;
                    move1 = move1 + 1.0f;
                    //cout<<stairCount2<<endl;
                }
                else if (move1 >= 11.0f) {
                    stairCount2 = stairCount2 - 2;
                    move2 = move2 - 1.5f;
                    move1 = move1 + 1.0f;
                    //cout << stairCount2 << endl;
                }
                if (move1 >= 22.0f) {
                    move2 = 0.0f;
                    move1 = 0.0f;
                    stairCount2 = 15.0f;
                }
                translateMatrix = glm::translate(identityMatrix, glm::vec3(11.5 + move2, 0.0, 27.5));
                model = model * translateMatrix * rotateXMatrix * rotateZMatrix;
                stairCase(cube, lightingWithTextureShader, model, stairCount2);

                model = temp;
            }
        }

       

        //Sphere er code
        ////////////////////////////////////////////////////////////////////////////////////////
        glm::mat4 modelForSphere = glm::mat4(1.0f);
        modelForSphere = glm::translate(model, glm::vec3(1.5f, 1.2f, 0.5f));
        sphere.setRadius(1.5);
        //sphere.drawSphere(lightingShader, modelForSphere, 1.5f, 1.2f, 0.5f);

        //cylinder er code
        ///////////////////////////////////////////////////////////////////////////////////////
        //cylinder 1
        //glm::mat4 translate = glm::mat4(1.0f);
        //glm::mat4 scale = glm::mat4(1.0f);
        //scale = glm::scale(model, glm::vec3(.1f, .4f, .1f));
        //translate = glm::translate(model, glm::vec3(-8.0f, 1.0f, -4.5f));
        Cylinder cylinder1 = Cylinder(3.0);
        //cylinder1.setRadius(3.5);
        //cylinder1.drawCylinder(lightingShader, modelForSCylinder, 1.5f, 0.0f, 0.5f);
        //cylinder.drawCylinder(lightingShader, modelForSCylinder * rotateYMatrix, 1.5f, 0.0f, 0.5f);


        


        /*
        //////////bench tolls
        {
            temp = model;
            translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.25, 0.0, -5.0));
            model = model * translateMatrix;
            //benchToll(cube, lightingWithTextureShader, model);
            model = temp;
        }

        ////////////////bed
        {
            temp = model;
            translateMatrix = glm::translate(identityMatrix, glm::vec3(3.0, 0.0, -1.0));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0, 4.0, 4.0));
            model = model * translateMatrix * scaleMatrix;
            //bed(cube, lightingWithTextureShader, model);
            model = temp;
        }
        

        ////////////////////////almari
        {
            temp = model;
            translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, -6.25));
            model = model * translateMatrix;
            //almari(cube, lightingWithTextureShader, model);
            model = temp;
        }
        

        //////////////bookshelf
        {
			temp = model;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.25, 0.0, -6.25));
			model = model * translateMatrix;
			//bookShelf(cube, lightingWithTextureShader, model, colorArray, woodtablediffMap, woodtablespecMap);
			model = temp;
		}
        if (firstcall)
        {
            // This is the first call to the loop
            firstcall = false;
        }
        */
        /*
        ///////////////////dining table
        {
            temp = model;
            //dining(cubeVAO, lightingShader, model);
            translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, 0.0, 4.0));
            model = model * translateMatrix;
            glm::mat4 ttranslateMatrix = translateMatrix;
            for (int j = 0; j < 2; j++) {
                for (int i = 0; i < 6; i++)
                {
                    ttranslateMatrix = ttranslateMatrix * glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, -0.5f));
                    dining(cube, lightingWithTextureShader, model*ttranslateMatrix);
                }
                ttranslateMatrix = ttranslateMatrix * glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, -1.0f));
            }
            //model = temp;
            ttranslateMatrix = translateMatrix * glm::translate(identityMatrix, glm::vec3(2.5f, 0.0f, -0.0f));
            for (int j = 0; j < 2; j++) {
                for (int i = 0; i < 6; i++)
                {
                    ttranslateMatrix = ttranslateMatrix * glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, -0.5f));
                    dining(cube, lightingWithTextureShader, model*ttranslateMatrix);
                }
                ttranslateMatrix = ttranslateMatrix * glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, -1.0f));
            }
            
            //model = temp;
            ttranslateMatrix = translateMatrix * glm::translate(identityMatrix, glm::vec3(5.0f, 0.0f, -0.0f));
            for (int j = 0; j < 2; j++) {
                for (int i = 0; i < 6; i++)
                {
                    ttranslateMatrix = ttranslateMatrix * glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, -0.5f));
                    dining(cube, lightingWithTextureShader, model * ttranslateMatrix);
                }
                ttranslateMatrix = ttranslateMatrix * glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, -1.0f));
            }
            //model = temp;
            ttranslateMatrix = translateMatrix * glm::translate(identityMatrix, glm::vec3(-2.5f, 0.0f, -0.0f));
            for (int j = 0; j < 2; j++) {
                for (int i = 0; i < 6; i++)
                {
                    ttranslateMatrix = ttranslateMatrix * glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, -0.5f));
                    dining(cube, lightingWithTextureShader, model * ttranslateMatrix);
                }
                ttranslateMatrix = ttranslateMatrix * glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, -1.0f));
            }
            model = temp;
        }


        ////////////SIRI dining er
        {
            temp = model;
            translateMatrix = glm::translate(identityMatrix, glm::vec3(6.25, 0.0, -6.25));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(11.0, .25, 5.0));
            model = model   * translateMatrix * scaleMatrix;
            //drawCube(cubeVAO, lightingWithTextureShader, model, 0.396f, 0.263f, 0.129f);
            cube.setMaterialisticEimu(0.396f, 0.263f, 0.129f);
            cube.drawCubeWithMaterialisticProperty(lightingWithTextureShader, model);

            model = temp;
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(11.0, .16, 5.5));
            model = model * translateMatrix * scaleMatrix;
            //drawCube(cubeVAO, lightingWithTextureShader, model, 0.396f, 0.263f, 0.129f);
            cube.setMaterialisticEimu(0.396f, 0.263f, 0.129f);
            cube.drawCubeWithMaterialisticProperty(lightingWithTextureShader, model);

            model = temp;
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(11.0, .08, 6.0));
            model = model * translateMatrix * scaleMatrix;
            //drawCube(cubeVAO, lightingWithTextureShader, model, 0.396f, 0.263f, 0.129f);
            cube.setMaterialisticEimu(0.396f, 0.263f, 0.129f);
            cube.drawCubeWithMaterialisticProperty(lightingWithTextureShader, model);

            model = temp;

        }
        //chair 6ta
        {
            temp = model;
            glm::mat4 ttranslateMatrix = translateMatrix;
            translateMatrix = glm::translate(identityMatrix, glm::vec3(7.25, 0.25, -4.25));
            for (float i = 0; i < 10; i = i + 2)
            {
                //temp = model;
                //translateMatrix = glm::translate(identityMatrix, glm::vec3(6.25, 0.0, -4.25));
                //scaleMatrix = glm::scale(identityMatrix, glm::vec3(11.0, .25, 5.0));
                ttranslateMatrix = glm::translate(identityMatrix, glm::vec3(static_cast<float>(i), 0.0f,0.0f));
                model = model * translateMatrix;
                chair(cube, lightingWithTextureShader, model * ttranslateMatrix );
                model = temp;
            
            }
            model = temp;
        }


        //professor der dining
        {
            temp = model;
            translateMatrix = glm::translate(identityMatrix, glm::vec3(7.25, 0.25, -4.00));
            model = model * translateMatrix;
            diningWithoutChair(cube, lightingWithTextureShader, model);
            model = temp;
        }
        */
        /*

        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X, translate_Y, -0.6));
        model = model * translateMatrix;
        //chair(cubeVAO, lightingShader, model*translateMatrix);
        rotateXMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        translateMatrix = glm::translate(identityMatrix, glm::vec3(1.8, translate_Y, -1.5));

        model = model *translateMatrix* rotateXMatrix;
        //sofa(cubeVAO, lightingShader, model);
        //pillow(cubeVAO, lightingShader, model);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.55, translate_Y,translate_Z));
        model = model * translateMatrix;
        //pillow(cubeVAO, lightingShader, model);
        //lamp(cubeVAO, lightingShader, model);
        

        rotateXMatrix = glm::rotate(identityMatrix, glm::radians(-120.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        translateMatrix = glm::translate(identityMatrix, glm::vec3(1.8, translate_Y, 2.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.45f, 1.0, 1.0f));

        model = model * translateMatrix * rotateXMatrix;
        //sofa(cubeVAO, lightingShader, model);


        */
        /*
        // also draw the lamp object(s)
        ourShader.use();
        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);

        // we now draw as many light bulbs as we have point lights.
        //glBindVertexArray(lightCubeVAO);
        for (unsigned int i = 0; i < 4; i++)
        {
        
            //model = glm::mat4(1.0f);
            model = model * glm::translate(model, pointLightPositions[i]);
            model = model * glm::scale(model, glm::vec3(.5,.5f,.5f)); // Make it a smaller cube
            //lightingWithTextureShader.setMat4("model", model);
            //lightingWithTextureShader.setVec3("color", glm::vec3(0.0, 0.0, 0.0));
            //cube.drawCubeWithMaterialisticProperty(lightingWithTextureShader, model);
            //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
            cube.drawCube(ourShader, model, .8f, .8f, .8f);
                        
        }
        */


        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    //glDeleteVertexArrays(1, &cubeVAO);
    //glDeleteVertexArrays(1, &lightCubeVAO);
    //glDeleteBuffers(1, &cubeVBO);
    //glDeleteBuffers(1, &cubeEBO);
    //delete cube;

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}




// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        camera.ProcessKeyboard(FORWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        camera.ProcessKeyboard(LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        camera.ProcessKeyboard(RIGHT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
        camera.ProcessKeyboard(YAW_L, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
        camera.ProcessKeyboard(YAW_R, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
        camera.ProcessKeyboard(PITCH_L, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS) {
        camera.ProcessKeyboard(PITCH_R, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_SLASH) == GLFW_PRESS) {
        camera.ProcessKeyboard(ROLL_R, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_PERIOD) == GLFW_PRESS) {
        camera.ProcessKeyboard(ROLL_L, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        camera.ProcessKeyboard(UP, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_COMMA) == GLFW_PRESS) {
        camera.ProcessKeyboard(DOWN, deltaTime);
    }
    /*
    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
    {

        if (doorOpen)
            doorOpen = false;
        else if(!doorOpen)
			doorOpen = true;
    }
    */

    if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
    {

        if (doorAngle == 0.0f) {
            doorAngle = 90.0f;
        }

    }
    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
    {
        if (doorAngle == 90.0f) {
            doorAngle = 0.0f;
        }
    }



    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
    {
        if (rotateAxis_X) rotateAngle_X -= 0.1;
        else if (rotateAxis_Y) rotateAngle_Y -= 0.1;
        else rotateAngle_Z -= 0.1;
    }
    if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS) translate_Y += 0.001;
    if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS) translate_Y -= 0.001;
    if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) translate_X += 0.001;
    if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) translate_X -= 0.001;
    //if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS) translate_Z += 0.001;
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) translate_Z -= 0.001;
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) scale_X += 0.001;
    if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS) scale_X -= 0.001;
    if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) scale_Y += 0.001;
    //if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS) scale_Y -= 0.001;
    //if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS) scale_Z += 0.001;
    if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS) scale_Z -= 0.001;

    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
    {
        rotateAngle_X += 0.1;
        rotateAxis_X = 1.0;
        rotateAxis_Y = 0.0;
        rotateAxis_Z = 0.0;
    }
    if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
    {
        rotateAngle_Y += 0.1;
        rotateAxis_X = 0.0;
        rotateAxis_Y = 1.0;
        rotateAxis_Z = 0.0;
    }
    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
    {
        rotateAngle_Z += 0.1;
        rotateAxis_X = 0.0;
        rotateAxis_Y = 0.0;
        rotateAxis_Z = 1.0;
    }
    /*
    if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
    {
        eyeX += 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);
    }
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
    {
        eyeX -= 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);
    }
    if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
    {
        eyeZ += 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);
    }
    if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
    {
        eyeZ -= 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);
    }
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    {
        eyeY += 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    {
        eyeY -= 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);
    }
    */
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
    {
        turnonPointLights();
    }
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
    {
        turnoffPointLights();
    }
    if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS)
    {
        turnoffPointLights();
        dirLight.turnOff();
        spotLight.turnOn();
        //dirLight.turnDiffuseOn();

    }
    if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS)
    {

        turnonPointLights();
        dirLight.turnOn();
        spotLight.turnOff();

    }

    if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
    {
        dirLight.turnOn();

    }
    if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
    {
        dirLight.turnOff();
    }
    if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
    {
        spotLight.turnOn();

    }
    if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS)
    {
        spotLight.turnOff();
    }
    if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS)
    {
        turnOnAmbient();
    }
    if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS)
    {
        turnOnSpecular();
    }
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);
    //float zpos = static_cast<float>(zposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        //lastZ = zpos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
    //float zoffset = lastZ - zpos;

    lastX = xpos;
    lastY = ypos;
    //lastZ = zpos;   

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}
