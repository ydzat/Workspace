#include "U_LineBenchmark.h"
//------------------------------------------------------------------------------
App_LineBenchmark::App_LineBenchmark(int w, int h)
	:Application(w,h)
{
	// prepare vertex array for point a
	// U02 A3a)
    color[0][0]=1.0f;
    color[0][1]=1.0f;
    color[0][2]=1.0f;
    color[0][3]=1.0f;

    position[0][0]=0.0f;
    position[0][1]=0.0f;
    position[0][2]=0.0f;

	// prepare vertex array for point b
	// U02 A3a)
    color[1][0]=0.0f;
    color[1][1]=1.0f;
    color[1][2]=0.0f;
    color[1][3]=1.0f;

    position[1][0]=w-1;
    position[1][1]=h-1;
    position[1][2]=0.0f;


	context.clearColor = CGVec4(0.9f, 0.7f, 0.8f, 1.0f);

    // set the vertex attribute pointers
    context.vertexAttributePointer.position = &position[0][0];

	context.useProgram(prog);
	// U02 A3b)
    context.bresenhamIsEnabled = true;
}
//------------------------------------------------------------------------------
void App_LineBenchmark::program_step()
{
	// clear the screen
	context.clear(CG_COLOR_BUFFER_BIT);



	// the draw call
	// U02 A3a)
    for(int i=0; i<10000;i++){
    context.drawArrays(CG_LINES, 0, 2);
    }
}
