#include "CGRasterizer.h"
#include "CGProgramInterface.h"
#include "CGFragmentOperations.h"
#include <algorithm>
void CGStupidLineRasterizer::rasterize(const CGVaryings& A,const CGVaryings& B)
{
	// Start- und Endpunkt der Linie als 2D-Ganzzahlvektoren
	CGVec2i start,end;
	start.set((int)A.position.x,
	          (int)A.position.y);
	end.set((int)B.position.x,
	        (int)B.position.y);

	// Sicherstellen, dass von links nach rechts rasterisiert wird!
	if (start[0] > end[0]) {
		std::swap(start, end);
	}

	// U02 A2a) & A2b)
	// Hinweise:
	//   - Es gen�gt, die Varyings einmalig mit fragment.set(A) auf die Attribute des ersten Vertex zu setzen. In jedem
	//     Schleifendurchlauf m�ssen dann nur noch die Fragmentkoordinaten gesetzt und das Fragment zur Weiterverarbeitung
	//     eingereiht werden (fragment.coordinates.set(...) und m_frag_ops.push_fragment(fragment)).
	//   - Beachten Sie, dass Pixelzentren im Window-Space auf "Komma 5" liegen (siehe Vorlesung, Kapitel 5, Folie 4)
	//   - Wenn Sie die Koordinatenachsen vertauschen, ergibt sich auch ein anderer Anstieg (delta_y / delta_x) der Linie.

	CGFragmentData fragment;
	
	// Rasterisierung als zwei Punkte. Entfernen Sie dies vor dem Bearbeiten der Aufgabe
	fragment.set(A);
	fragment.coordinates.set((int)A.position.x,(int)A.position.y);
	m_frag_ops.push_fragment(fragment);
	fragment.set(B);
	fragment.coordinates.set((int)B.position.x,(int)B.position.y);
	m_frag_ops.push_fragment(fragment);

	// Alle eingereihten Fragmente verarbeiten
	m_frag_ops.flush_fragments();
}
