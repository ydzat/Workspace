// Belegaufgabe 4, WS 2021/22: Troubles with Tribbles

typedef struct {
  unsigned int   x;
  unsigned int   y;
} dim_t;

typedef enum {
  TR_T,  // von Tribbles besetzt
  TR_U,  // unzugaenglich
  TR_V,  // viel Nahrung
  TR_W,  // wenig Nahrung
  TR_Z   // Zielort 
} trmapq_t;

int tribble(trmapq_t (*map)[], dim_t dimensions, int numstart, dim_t start[]);