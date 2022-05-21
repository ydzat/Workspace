#include "U_Project.h"

#include <algorithm>

#include "Utilities/CG1Helper/CG1Helper.h"
#include "Utilities/CGImageFile.h"

App_Project::App_Project(int w, int h) :
    Application(w, h)
{
    context.clearColor = CGVec4(0.0f, 0.0f, 0.0f, 1.0f);
    context.polygonMode = CG_FILL;
    context.depthTestIsEnabled = true;
    context.bresenhamIsEnabled = true;
    context.blendingIsEnabled = true;
    context.backFaceCullingIsEnabled = false;

    context.useProgram(prog_lit_tex);
    prog_lit_tex.uniform.light.ambient = CGVec4(0.1f);
    prog_lit_tex.uniform.light.diffuse = CGVec4(0.8f);
    prog_lit_tex.uniform.light.specular = CGVec4(0.8f);

    set_projection_matrix();

    light_sphere.create();

    load_texture();

    initialize_scene_objects();
}

App_Project::~App_Project()
{
    if (objects)
        delete[] objects;
}

void App_Project::program_step()
{
    process_input();

    calculate_view_matrix();
    calculate_light_position();

    context.clear(CG_COLOR_BUFFER_BIT | CG_DEPTH_BUFFER_BIT);

    draw_scene_objects();
    draw_light_source();
}

void App_Project::load_texture()
{
    int img_w, img_h;
    unsigned char* imgData4ub = cgImageLoad("textures/checker.tga", &img_w, &img_h, true);
    texture_checker.allocate(img_w, img_h, imgData4ub);
    texture_checker.wrapMode = CG_REPEAT;
    texture_checker.filterMode = CG_NEAREST;
    free(imgData4ub);
}

void App_Project::initialize_scene_objects()
{
    num_objects = 10;
    objects = new SceneObject[num_objects];

    // PROJEKT Aufgabe 1

    // Definition eines Objekts in der Szene:
    // objects[0].shape = new CGPlaneShape(); // Entsprechende Kindklasse von CGShape benutzen
    // objects[0].shape->create();            // Geometrie erstellen
    // objects[0].model_matrix = ...          // Modellmatrix konfigurieren
    // objects[0].texture = ...               // Textur festlegen (falls benötigt)
    // objects[0].material_ambient = ...      // Materialparameter festlegen (falls benötigt)
    // objects[0].material_diffuse = ...
    // objects[0].material_specular = ...
    // objects[0].material_shininess = ...
	
	// ...
}

void App_Project::process_input()
{
    // Picking
    if (CG1Helper::isMouseButtonReleased(0))
    {
        CGVec2 mouse_pos = CG1Helper::getMousePos();
        int closest_hit_index = -1;
        float closest_hit_distance = 1e37f;

        // PROJEKT Aufgabe 2

        // - Breite des Viewports in Pixeln:  context.viewport.width()
        // - Höhe des Viewports in Pixeln:    context.viewport.height()
        // - Model Matrix des i'ten Objekts:  objects[i].model_matrix
        // - Aktuelle View Matrix:            view_matrix
        // - Aktuelle Projektionsmatrix:      prog_lit_tex.uniform.projectionMatrix
        // - Invertieren der Matrix M:        M.invert()
        // - Normalisieren des Vektors v:     CGMath::normalize(v)
        // - Schnitttest für das i'te Objekt: objects[i].shape->intersect(...)

		// ...

        if (closest_hit_index >= 0)
        {
            std::cout << "Hit shape " << closest_hit_index << " at a distance of " << closest_hit_distance << ".\n";
            if (CG1Helper::isKeyPressed(GLFW_KEY_LEFT_SHIFT))
            {
                delete objects[closest_hit_index].shape;
                objects[closest_hit_index].shape = nullptr;
            }
        }
        else
        {
            std::cout << "Did not hit anything.\n";
        }
    }

    // Schalter für Pipelinefunktionen
    if (CG1Helper::isKeyReleased('1'))
    {
        context.polygonMode = (context.polygonMode == CG_FILL ? CG_LINE : CG_FILL);
        std::cout << "Wireframe mode " << (context.polygonMode == CG_LINE ? "enabled.\n" : "disabled.\n");
    }
    if (CG1Helper::isKeyReleased('2'))
    {
        context.depthTestIsEnabled = !context.depthTestIsEnabled;
        std::cout << "Depth test " << (context.depthTestIsEnabled ? "enabled.\n" : "disabled.\n");
    }
    if (CG1Helper::isKeyReleased('3'))
    {
        context.blendingIsEnabled = !context.blendingIsEnabled;
        std::cout << "Blending " << (context.blendingIsEnabled ? "enabled.\n" : "disabled.\n");
    }
    if (CG1Helper::isKeyReleased('4'))
    {
        texture_checker.wrapMode = (texture_checker.wrapMode == CG_REPEAT ? CG_CLAMP : CG_REPEAT);
        std::cout << "Texture wrap mode is now " << (texture_checker.wrapMode == CG_REPEAT ? "CG_REPEAT.\n" : "CG_CLAMP.\n");
    }
    if (CG1Helper::isKeyReleased('5'))
    {
        texture_checker.filterMode = (texture_checker.filterMode == CG_NEAREST ? CG_LINEAR : CG_NEAREST);
        std::cout << "Texture filter mode is now " << (texture_checker.filterMode == CG_NEAREST ? "CG_NEAREST.\n" : "CG_LINEAR.\n");
    }
    if (CG1Helper::isKeyReleased('6'))
    {
        use_orthographic_projection = !use_orthographic_projection;
        set_projection_matrix();
        std::cout << "Now using " << (use_orthographic_projection ? "orthographic projection.\n" : "perspective projection.\n");
    }
    if (CG1Helper::isKeyReleased('7'))
    {
        context.backFaceCullingIsEnabled = !context.backFaceCullingIsEnabled;
        std::cout << "Back-face culling " << (context.backFaceCullingIsEnabled ? "enabled.\n" : "disabled.\n");
    }

    // Manipulation des View Frustums
    if (CG1Helper::isKeyReleased('u'))
    {
        if (use_orthographic_projection)
            orthographic_horizontal = std::max(std::min(orthographic_horizontal + 0.8f, 16.0f), 4.0f);
        else
            perspective_horizontal = std::max(std::min(perspective_horizontal + 0.16f, 3.2f), 0.8f);
        set_projection_matrix();
    }
    if (CG1Helper::isKeyReleased('j'))
    {
        if (use_orthographic_projection)
            orthographic_horizontal = std::max(std::min(orthographic_horizontal - 0.8f, 16.0f), 4.0f);
        else
            perspective_horizontal = std::max(std::min(perspective_horizontal - 0.16f, 3.2f), 0.8f);
        set_projection_matrix();
    }
    if (CG1Helper::isKeyReleased('i'))
    {
        if (use_orthographic_projection)
            orthographic_vertical = std::max(std::min(orthographic_vertical + 0.5f, 10.0f), 2.5f);
        else
            perspective_vertical = std::max(std::min(perspective_vertical + 0.1f, 2.0f), 0.5f);
        set_projection_matrix();
    }
    if (CG1Helper::isKeyReleased('k'))
    {
        if (use_orthographic_projection)
            orthographic_vertical = std::max(std::min(orthographic_vertical - 0.5f, 10.0f), 2.5f);
        else
            perspective_vertical = std::max(std::min(perspective_vertical - 0.1f, 2.0f), 0.5f);
        set_projection_matrix();
    }

    // Kamerasteuerung
    if (CG1Helper::isKeyPressed('w'))
        camera_inclination = std::max(std::min(camera_inclination + 1.0f, 85.0f), -85.0f);
    if (CG1Helper::isKeyPressed('s'))
        camera_inclination = std::max(std::min(camera_inclination - 1.0f, 85.0f), -85.0f);
    if (CG1Helper::isKeyPressed('a'))
        camera_azimuth -= 1.0f;
    if (CG1Helper::isKeyPressed('d'))
        camera_azimuth += 1.0f;
    if (CG1Helper::isKeyPressed('q'))
        camera_radius = std::max(std::min(camera_radius + 0.1f, 100.0f), 1.0f);
    if (CG1Helper::isKeyPressed('e'))
        camera_radius = std::max(std::min(camera_radius - 0.1f, 100.0f), 1.0f);
}

void App_Project::calculate_view_matrix()
{
    static const CGVec4 center(0.0f, 0.0f, 0.0f);
    static const CGVec4 up(0.0f, 1.0f, 0.0f);
    static const float deg_to_rad = 3.141592f / 180.0f;
    const float azimuth_rad = camera_azimuth * deg_to_rad;
    const float inclination_rad = camera_inclination * deg_to_rad;
    const CGVec4 eye(sin(azimuth_rad) * cos(inclination_rad) * camera_radius,
                     sin(inclination_rad) * camera_radius,
                     cos(azimuth_rad) * cos(inclination_rad) * camera_radius);
    view_matrix = CGMatrix4x4::getLookAt(eye, center, up);
}

void App_Project::calculate_light_position()
{
    static const float light_radius = 9.0f;
    float anim = 0.5f * CG1Helper::getTime();
    light_position = CGVec4(cosf(anim) * light_radius, 2.5f, sinf(anim) * light_radius, 1.0f);
    prog_lit_tex.uniform.light.position_es = view_matrix * light_position;
}

void App_Project::draw_scene_objects()
{
    context.useProgram(prog_lit_tex);

    for (int i = 0; i < num_objects; i++)
    {
        if (objects[i].shape == nullptr)
            continue;

        prog_lit_tex.uniform.modelViewMatrix = view_matrix * objects[i].model_matrix;
        prog_lit_tex.uniform.updateNormalMatrix();
        prog_lit_tex.uniform.texture = objects[i].texture;
        prog_lit_tex.uniform.material.ambient = objects[i].material_ambient;
        prog_lit_tex.uniform.material.diffuse = objects[i].material_diffuse;
        prog_lit_tex.uniform.material.specular = objects[i].material_specular;
        prog_lit_tex.uniform.material.shininess = objects[i].material_shininess;
        objects[i].shape->draw(context);
    }
}

void App_Project::draw_light_source()
{
    context.useProgram(prog_unlit);
    prog_unlit.uniform.modelViewMatrix = view_matrix *
        CGMatrix4x4::getTranslationMatrix(light_position.x, light_position.y, light_position.z) *
        CGMatrix4x4::getScaleMatrix(0.1f, 0.1f, 0.1f);
    light_sphere.draw(context);
}

void App_Project::set_projection_matrix()
{
    prog_lit_tex.uniform.projectionMatrix = use_orthographic_projection ?
        CGMatrix4x4::getOrtho(-orthographic_horizontal, orthographic_horizontal, -orthographic_vertical, orthographic_vertical, projection_near, projection_far) :
        CGMatrix4x4::getFrustum(-perspective_horizontal, perspective_horizontal, -perspective_vertical, perspective_vertical, projection_near, projection_far);
    prog_unlit.uniform.projectionMatrix = prog_lit_tex.uniform.projectionMatrix;
}
