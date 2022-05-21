#include "U_LineBenchmark.h"
//------------------------------------------------------------------------------
App_LineBenchmark::App_LineBenchmark(int w, int h)
	:Application(w, h)
{
	// prepare vertex array for point a
	// U02 A3a) -- Vorbereiten der Vertexdaten f黵 die beiden Punkte
	// Hinweise:
	//   - Breite und H鰄e des Viewports werden dem Konstruktor als w und h 黚ergeben.
	//   - Die Farbe sollte zwar gesetzt werden, spielt aber keine Rolle, da die Fragmentverarbeitung in Aufgabe 3c)
	//     ausgeschaltet wird.

	// ...

	// prepare vertex array for point a start
	color[0][0] = 1.0f;
	color[0][1] = 1.0f;
	color[0][2] = 1.0f;
	color[0][3] = 1.0f;

	position[0][0] = 0.0f;
	position[0][1] = 0.0f;
	position[0][2] = 0.0f;

	// prepare vertex array for point b end
	// U02 A3a)
	color[1][0] = 0.0f;
	color[1][1] = 1.0f;
	color[1][2] = 0.0f;
	color[1][3] = 1.0f;

	position[1][0] = w - 1;
	position[1][1] = h - 1;
	position[1][2] = 0.0f;

	context.clearColor = CGVec4(0.3f, 0.3f, 0.3f, 1.0f);

	context.vertexAttributePointer.position = &(position[0][0]);
	context.vertexAttributePointer.color = &(color[0][0]);

	context.useProgram(prog);

	// U02 A3b)
	context.bresenhamIsEnabled = true;
}
//------------------------------------------------------------------------------
void App_LineBenchmark::program_step()
{
	context.clear(CG_COLOR_BUFFER_BIT);

	// U02 A3a)
	// Hinweise:
	//   - Um eine Linie zu zeichnen, muss CG_LINES als Primitivtyp 黚ergeben werden
	//   - Der selbe Draw-Call soll 10000 mal durchgef黨rt werden.

	// ...

	for (int i = 0; i < 10000; i++) {
		context.drawArrays(CG_LINES, 0, 2);
	}


}
