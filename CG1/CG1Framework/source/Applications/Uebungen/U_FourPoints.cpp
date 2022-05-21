#include "U_FourPoints.h"
#include "Utilities/CG1Helper/CG1Helper.h"

App_FourPoints::App_FourPoints(int w, int h)
        :Application(w,h)
{
	position[0][0] = 120;
	position[0][1] = 150;
	position[0][2] = 00;

	position[1][0] = 230;
	position[1][1] = 10;
	position[1][2] = 00;

	position[2][0] = 10;
	position[2][1] = 10;
	position[2][2] = 00;

	color[0][0] = 1.0f;
	color[0][1] = 0.0f;
	color[0][2] = 0.0f;
	color[0][3] = 1.0f;

	color[1][0] = 0.0f;
	color[1][1] = 1.0f;
	color[1][2] = 0.0f;
	color[1][3] = 1.0f;

	color[2][0] = 1.0f;
	color[2][1] = 1.0f;
	color[2][2] = 0.0f;
	color[2][3] = 1.0f;


	// U01: A3a) Setup the 4th point
    position[3][0] = 120;
    position[3][1] = 60;
    position[3][2] = 00;

    color[3][0] = 1.0f;
    color[3][1] = 1.0f;
    color[3][2] = 1.0f;
    color[3][3] = 1.0f;



    context.clearColor.set(1.0f,0.8f,0.7f,1.0f);
	context.useProgram(prog);

    // U01: A4b) Set point radius
    context.pointRadius = 20;

}

void App_FourPoints::program_step()
{
	context.clear(CG_COLOR_BUFFER_BIT);
	context.vertexAttributePointer.position = &position[0][0];
	context.vertexAttributePointer.color = &color[0][0];

	// U01: A3c) Move 4th point
    float t = CG1Helper::getTime(); // time since program start
    position[3][0] = sin(t)*45 + 120.0f;
    position[3][1] = cos(t)*45 + 60.0f;

    // U01: A3b) Render 4th point
    context.drawArrays(CG_POINTS,0,4);


}
