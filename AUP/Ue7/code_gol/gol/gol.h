
struct panelParams {
	//panel dimension x
	int maxX;

	//panel dimension y
	int maxY;

	//panel dimension age (should be 2)
	int maxAge;
	
	//the part of the panel that has to be initialized
	int active;
};


enum field {dead, alive};


void init(const struct panelParams par, enum field arr[par.maxX][par.maxY][par.maxAge]);

void output(const struct panelParams par, enum field arr[par.maxX][par.maxY][par.maxAge]);

int update(const struct panelParams par, enum field arr[par.maxX][par.maxY][par.maxAge]);



