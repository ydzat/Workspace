#include "U_TestViewport.h"
//------------------------------------------------------------------------------
App_TestViewport::App_TestViewport(int w, int h)
	:Application(w, h)
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

	// U07 A2b)
	// Hinweise:
	//   - aktuell wird ein viewport auf die Gr鲞e des Framebuffers gesetzt.
	//   - 膎dern Sie die Parameter in der set Funktion um die Gr鲞e des Viewports zu 鋘dern
	//   - Achten Sie darauf, dass sie die Breite und H鰄e angeben m黶sen, nicht die rechte obere Ecke:
	//   - context.viewport.set(x_links_unten, y_links_unten, Breite, H鰄e)
	//   - Rufen Sie die beiden folgenden Befehle mehrfach auf		

	for (int i = 0; i < 4; i++) {
		context.viewport.set((i % 2) * frame_width / 2, (1 - i / 2) * frame_height / 2, frame_width / 2, frame_height / 2);
		context.drawArrays(CG_TRIANGLES, 0, 6); // 6 vertices for 2 triangle.
	}



}
