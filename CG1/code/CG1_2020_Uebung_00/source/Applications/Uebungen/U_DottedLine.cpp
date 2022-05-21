#include "U_DottedLine.h"
#include "Utilities/CG1Helper/CG1Helper.h"

App_DottedLine::App_DottedLine(int w, int h) :
	Application(w, h)
{
	// Start- und Endpunkt der zu rendernden Strecke als 3D-Vektoren
	const float startPoint[] = { 20.0f, 150.0f, 0.0f };
	const float endPoint[] = { 230.0f, 10.0f, 0.0f };

	// RGBA-Farbwerte der Strecke am Start- und Endpunkt
	const float startColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	const float endColor[] = { 1.0f, 0.0f, 1.0f, 1.0f };

	// Anzahl der Samples entlang der Strecke - so viele Punkte sollen entstehen
	// U01.1 A2d)
	numSamples = 100;

	// U01.1 A2a)
	// Hinweise:
	//   - malloc nimmt einen Parameter entgegen: die Anzahl der zu reservierenden Bytes
	//   - malloc gibt einen Zeiger auf den allozierten Speicher zur點k (als void*, position
	//     und color sind aber vom Typ float*)
	//   - sizeof(float) liefert die Anzahl Bytes in einem einzelnen float zur點k

	//position = ...
	//color = ...
	position = static_cast<float*> (malloc(numSamples * sizeof(float) * 3));
	color = static_cast<float*> (malloc(numSamples * sizeof(float) * 4));





	// U01.1 A2b) & A3)
	// Hinweise:
	//   - Die Variablen position und color k鰊nen wie Arrays benutzt werden. So verweist z.B.
	//     position[0] auf den ersten float-Wert im Array - die X-Koordinate des ersten
	//     Positionswerts; position[1] ist die Y-Koordinate der ersten Position, position[3]
	//     die X-Koordinate der zweiten Position usw.
	//   - Analog gilt f黵 color: color[0] ist der Rot-Wert der ersten Farbe, color[2] der
	//     Blau-Wert der ersten Farbe, color[4] der Gr黱-Wert der zweiten Farbe usw.
	//   - Nutzen Sie eine Schleife, die f黵 jedes Sample einen Positions- und Farbwert
	//     generiert. 
	//   - Die Schleifenvariable kann ebenfalls in die Berechnungen einbezogen werden.

	//...


	if (position && color) {
		float dx_position = (endPoint[0] - startPoint[0]) / (numSamples - 1);
		float dy_position = (endPoint[1] - startPoint[1]) / (numSamples - 1);
		float d0_color = (endColor[0] - startColor[0]) / (numSamples - 1);
		float d1_color = (endColor[1] - startColor[1]) / (numSamples - 1);
		float d2_color = (endColor[2] - startColor[2]) / (numSamples - 1);

		for (int i = 0; i < numSamples * 3; i += 3) {
			position[i] = startPoint[0] + dx_position * (int)(i / 3);
			position[i + 1] = startPoint[1] + dy_position * (int)(i / 3);
			position[i + 2] = startPoint[2];
		}

		for (int i = 0; i < numSamples * 4; i += 4) {
			color[i] = startColor[0] + d0_color * (int)(i / 4);
			color[i + 1] = startColor[1] + d1_color * (int)(i / 4);
			color[i + 2] = startColor[2] + d2_color * (int)(i / 4);
			color[i + 3] = startColor[3];
		}

	}


	context.clearColor.set(0.0f, 0.0f, 0.0f, 1.0f);
	context.useProgram(prog);
	context.pointRadius = 0;
}

App_DottedLine::~App_DottedLine()
{
	if (position)
		free(position);
	if (color)
		free(color);
}

void App_DottedLine::program_step()
{
	// Vor dem Renderdurchlauf wird der Color Buffer mit der aktuellen Hintergrundfarbe 黚erschrieben.
	context.clear(CG_COLOR_BUFFER_BIT);

	// Renderkommandos (z.B. CGContext::drawArrays) beziehen ihre Daten aus den Vertexattributzeigern.
	context.vertexAttributePointer.position = position;
	context.vertexAttributePointer.color = color;

	// U01.1 A2c)
	// Hinweise:
	//   - CGContext::drawArrays nimmt folgende Parameter entgegen:
	//     . Den zu rendernden Primitivtyp (in diesem Fall Punkte, sp鋞er u.a. Dreiecke)
	//     . Den Index des ersten zu bearbeitenden Vertex
	//     . Die Anzahl der zu bearbeitenden Vertices
	//   - Die Daten zum Rendern stammen aus den aktuell festgelegten Vertexattributzeigern (s.o.)
	context.drawArrays(CG_POINTS, 0, numSamples);
}
