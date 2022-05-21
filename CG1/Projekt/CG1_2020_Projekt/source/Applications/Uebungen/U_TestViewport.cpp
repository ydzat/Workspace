#include "U_TestViewport.h"
//------------------------------------------------------------------------------
App_TestViewport::App_TestViewport(int w, int h)
	:Application(w,h)
{
	frame_width = w;
	frame_height = h;
	context.clearColor = CGVec4(0.0f, 0.0f, 0.0f, 1.0f);
	context.bresenhamIsEnabled = true;
}
//------------------------------------------------------------------------------
void App_TestViewport::program_step()
{
	// clear the screen
	context.clear(CG_COLOR_BUFFER_BIT);

	// set the vertex attribute pointers
	context.vertexAttributePointer.position = vertexPosition_TestTriangle;
	context.vertexAttributePointer.color = vertexColor_TestTriangle;

	context.useProgram(prog);

    //context.viewport = CGRectangle(0,0, frame_width, frame_height);
    for(int i=0; i<4;i++){
    context.viewport.set((i%2)*frame_width/2,(1-i/2)*frame_height/2,frame_width/2,frame_height/2);
	context.drawArrays(CG_TRIANGLES, 0, 6); // 6 vertices for 2 triangle.
    }
}
