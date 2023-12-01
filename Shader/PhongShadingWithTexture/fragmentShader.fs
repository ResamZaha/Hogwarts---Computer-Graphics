#version 330 core
out vec4 FragColor;

struct Texture {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct PointLight {
    vec3 position;
    
    float k_c;  // attenuation factors
    float k_l;  // attenuation factors
    float k_q;  // attenuation factors
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct DirLight {
    vec3 direction;
	
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct SpotLight{
    vec3 position;
    vec3 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float cutoff;
    float outcutoff;
};


#define NR_POINT_LIGHTS 28

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

uniform vec3 viewPos;

uniform PointLight pointLights[NR_POINT_LIGHTS];
uniform DirLight dirLight;
uniform SpotLight spotLight;

uniform Material material;
uniform Texture textures;
uniform bool drawWithTexture;
// function prototypes
vec3 CalcPointLight(Texture textures, PointLight light, vec3 N, vec3 fragPos, vec3 V);
vec3 CalcPointLight(Material material, PointLight light, vec3 N, vec3 fragPos, vec3 V);    //calculation of PointLight

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir); //calculation of DirectionalLight

vec3 CalcSpotLight(Texture textures, SpotLight light, vec3 N,vec3 fragPos, vec3 V);
vec3 CalcSpotLight(Material material, SpotLight light, vec3 N,vec3 fragPos, vec3 V);

void main()
{
    // properties
    vec3 N = normalize(Normal);
    vec3 V = normalize(viewPos - FragPos);
    
    vec3 result = CalcDirLight(dirLight, N, V);
    if(drawWithTexture){
    // point lights
        for(int i = 0; i < NR_POINT_LIGHTS; i++)
            result += CalcPointLight(textures, pointLights[i], N, FragPos, V);
        result = result + CalcSpotLight(textures, spotLight, N, FragPos, V);
    
    }
    else{
        // point lights
        for(int i = 0; i < NR_POINT_LIGHTS; i++)
            result += CalcPointLight(material, pointLights[i], N, FragPos, V);
        result = result + CalcSpotLight(material, spotLight, N, FragPos, V);
    }
    FragColor = vec4(result, 1.0);
}

// calculates the color when using a point light.
vec3 CalcPointLight(Texture textures, PointLight light, vec3 N, vec3 fragPos, vec3 V)
{
    vec3 L = normalize(light.position - fragPos);
    vec3 R = reflect(-L, N);
    
    // attenuation
    float d = length(light.position - fragPos);
    float attenuation = ( 1.0 / (light.k_c + light.k_l * d + light.k_q * (d * d)));
    
    vec3 ambient = vec3(texture(textures.diffuse, TexCoords)) * light.ambient;
    vec3 diffuse = vec3(texture(textures.diffuse, TexCoords)) * max(dot(N, L), 0.0) * light.diffuse;
    vec3 specular = vec3(texture(textures.specular, TexCoords)) * pow(max(dot(V, R), 0.0), textures.shininess) * light.specular;
    
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    
    return (ambient + diffuse + specular);
}

// calculates the color when using a point light.
vec3 CalcPointLight(Material material, PointLight light, vec3 N, vec3 fragPos, vec3 V) 
{
    vec3 L = normalize(light.position - fragPos);  //
    vec3 R = reflect(-L, N); //this is a built in function, surface normal and L is passed as parameter, here the direction of L is toward light, hence L is minused
    
    //setting the materialistic property
    vec3 K_A = material.ambient;
    vec3 K_D = material.diffuse;
    vec3 K_S = material.specular;
    
    // attenuation
    float d = length(light.position - fragPos);  //distance of light and object is calculated using built-in function
    float attenuation = 1.0 / (light.k_c + light.k_l * d + light.k_q * (d * d));
    
    vec3 ambient = K_A * light.ambient;
    vec3 diffuse = K_D * max(dot(N, L), 0.0) * light.diffuse;
    vec3 specular = K_S * pow(max(dot(V, R), 0.0), material.shininess) * light.specular;
    
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
 
    return (ambient + diffuse + specular);
}
//direction light use kore
vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // combine results
    vec3 ambient = light.ambient * vec3((material.diffuse));
    vec3 diffuse = light.diffuse * diff * vec3((material.diffuse ));
    vec3 specular = light.specular * spec * vec3((material.specular));
    return (ambient + diffuse + specular);
}

vec3 CalcSpotLight(Material material, SpotLight light, vec3 N,vec3 fragPos, vec3 V)
{
    vec3 L = normalize(light.position - fragPos);
    float theta = dot(L, normalize(-light.direction));
    float epsilon   = light.cutoff - light.outcutoff;
    float intensity = clamp((theta - light.outcutoff) / epsilon, 0.0, 1.0);
    
    vec3 R = reflect(-L, N);
    
    vec3 K_A = material.ambient;
    vec3 K_D = material.diffuse;
    vec3 K_S = material.specular;
    
   
    
    vec3 ambient = intensity*K_A * light.ambient;
    vec3 diffuse = intensity*K_D * max(dot(N, L), 0.0) * light.diffuse;
    vec3 specular = intensity*K_S * pow(max(dot(V, R), 0.0), material.shininess) * light.specular;

    
    return (ambient + diffuse + specular);
    
}
vec3 CalcSpotLight(Texture textures, SpotLight light, vec3 N,vec3 fragPos, vec3 V)
{
    vec3 L = normalize(light.position - fragPos);
    float theta = dot(L, normalize(-light.direction));
    float epsilon   = light.cutoff - light.outcutoff;
    float intensity = clamp((theta - light.outcutoff) / epsilon, 0.0, 1.0);
    
    vec3 R = reflect(-L, N);
    
    vec3 K_A = vec3(texture(textures.diffuse, TexCoords));
    vec3 K_D = vec3(texture(textures.diffuse, TexCoords));
    vec3 K_S = vec3(texture(textures.specular, TexCoords));
    
   
    
    vec3 ambient = intensity*K_A * light.ambient;
    vec3 diffuse = intensity*K_D * max(dot(N, L), 0.0) * light.diffuse;
    vec3 specular = intensity*K_S * pow(max(dot(V, R), 0.0), material.shininess) * light.specular;

    
    return (ambient + diffuse + specular);
    

}