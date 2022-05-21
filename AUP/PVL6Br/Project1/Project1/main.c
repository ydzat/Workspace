#include<stdio.h>
#include<stdlib.h>
//#include<vld.h>

long int getLen(char* p);
long int max1(long int a, long int b);
long int min1(long int a, long int b);
long int String2Int(char* str);

char* verarbeitZ(char* p1);
char** plusNull(char* x1, char* y1);
long int getCommaSum(char* x, char* y);
char* allZ(char* p);
char* endVerab(char* p1);
long int mypow(long int x, long int y);
// void freeD1(char* p);
// void freeD2(char** p, int len);

char* rechner(char* x, char* y, char* xt, char* yt, char opr, long int len, long int commaSum);
char* add(char* x1, char* y1, long int len);
char* mini(char* x1, char* y1, long int len);
char* miniR(char* x1, char* y1, long int len);
char* multi(char* xt1, char* yt1, long int len, long int commaSum);

char addTable[9][9] = {
	{ 0,1,2,3,4,5,6,7,8 },
	{ 1,2,3,4,5,6,7,8,10 },
	{ 2,3,4,5,6,7,8,10,11 },
	{ 3,4,5,6,7,8,10,11,12 },
	{ 4,5,6,7,8,10,11,12,13 },
	{ 5,6,7,8,10,11,12,13,14 },
	{ 6,7,8,10,11,12,13,14,15 },
	{ 7,8,10,11,12,13,14,15,16 },
	{ 8,10,11,12,13,14,15,16,17 }

};

char miniTable[18][18] = {
	{ 0,-1,-2,-3,-4,-5,-6,-7,-8,-10,-11,-12,-13,-14,-15,-16,-17,-18 },
	{ 1,0,-1,-2,-3,-4,-5,-6,-7,-8,-10,-11,-12,-13,-14,-15,-16,-17 },
	{ 2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-10,-11,-12,-13,-14,-15,-16 },
	{ 3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-10,-11,-12,-13,-14,-15 },
	{ 4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-10,-11,-12,-13,-14 },
	{ 5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-10,-11,-12,-13 },
	{ 6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-10,-11,-12 },
	{ 7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-10,-11 },
	{ 8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-10 },
	{ 10,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8 },
	{ 11,10,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7 },
	{ 12,11,10,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6 },
	{ 13,12,11,10,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5 },
	{ 14,13,12,11,10,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4 },
	{ 15,14,13,12,11,10,8,7,6,5,4,3,2,1,0,-1,-2,-3 },
	{ 16,15,14,13,12,11,10,8,7,6,5,4,3,2,1,0,-1,-2 },
	{ 17,16,15,14,13,12,11,10,8,7,6,5,4,3,2,1,0,-1 },
	{ 18,17,16,15,14,13,12,11,10,8,7,6,5,4,3,2,1,0 }
};


int main(int argc, char* argv[]) {
	(void)argc;
	if ((argv[2][0] < 42) || (argv[2][0] > 45) || (argv[2][0] == 44)) {
		argv[2][0] = 42;
	}
	// if ((argv[1] == NULL) || (argv[3] == NULL)) {
	//     printf("argv[1] = %s\n", argv[1]);
	//     return 1;
	// }
	//printf("argv[1] = %s,argv[2] = %c  argv[3] = %s\n", argv[1],argv[2][0], argv[3]);
	char *x0 = verarbeitZ(argv[1]), *y0 = verarbeitZ(argv[3]);
	long int lenX = getLen(x0), lenY = getLen(y0);
	char *x = (char *)malloc(sizeof(char) * (lenX + 1)), *y = (char *)malloc(sizeof(char) * (lenY + 1));
	for (int i = 0; i < lenX; i++) {
		x[i] = x0[i];
	}
	for (int i = 0; i < lenY; i++) {
		y[i] = y0[i];
	}
	x[lenX] = '\0';
	y[lenY] = '\0';
	//printf("x = %s  y = %s\n", x, y);
	char **xy = plusNull(x, y);
	//printf("======\n");
	char* xf = xy[0], *yf = xy[1];

	long int len = getLen(xf);
	long int commaSum = getCommaSum(x, y);

	char* p = rechner(xf, yf, x, y, argv[2][0], len, commaSum);
	char* p1 = endVerab(p);
	printf("%s", p1);

	free(p1);
	free(p);
	free(xy);
	free(x);
	free(y);

	return 0;
}


//-----------------------
long int getLen(char* p) {
	char* end = p;

	while (*end != '\0') {
		end++;
	}


	return end - p;
}

long int max1(long int a, long int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}

long int min1(long int a, long int b) {
	if (a <= b) {
		return a;
	}
	else {
		return b;
	}
}


//----------------------
char* verarbeitZ(char* p1) {

	long int lenP = getLen(p1), commaP = 0;
	char *p = (char *)malloc(sizeof(char) * (lenP + 1));
	for (int i = 0; i < lenP; i++) {
		p[i] = p1[i];
	}
	p[lenP] = '\0';

	char *veraP;

	for (int i = 0; i < lenP; i++) {
		commaP++;
		if (p[i] == ',') {

			break;
		}
	}

	if (commaP == lenP) {

		//veraP = (char*)calloc(lenP + 4, sizeof(char));
		veraP = (char*)malloc((lenP + 4) * sizeof(char));
		for (long int i = 0; i < lenP; i++) {
			veraP[i] = p[i];

		}
		veraP[lenP] = ',';
		veraP[lenP + 1] = '0';
		veraP[lenP + 2] = '\0';

	}
	else {
		veraP = (char*)malloc((lenP + 4) * sizeof(char));
		for (long int i = 0; i < lenP; i++) {
			veraP[i] = p[i];

		}
		veraP[lenP] = '\0';
	}

	if (veraP[0] == '0') {
		for (long int i = 0; i < commaP; i++) {
			if (veraP[i] != '0') {
				veraP[i - 1] = '+';
				//veraP = veraP + i - 1;// veraP里面的值向前移动i-1的长度
				int tempLen = getLen(veraP);
				for (int j = i - 1; j <= tempLen; j++) {
					veraP[j - i + 1] = veraP[j];
				}

				break;
			}
		}
	}

	if ((veraP[0] == '-') && (veraP[1] == '0')) {
		for (long int i = 1; i < commaP; i++) {
			if (veraP[i] != '0') {
				veraP[i - 1] = '-';
				//veraP = veraP + i - 1;
				int tempLen = getLen(veraP);
				for (int j = i - 1; j <= tempLen; j++) {
					veraP[j - i + 1] = veraP[j];
				}
				break;
			}
		}
	}

	if ((veraP[0] != '-') && (veraP[0] != '+') && (veraP[0] != '0')) {
		for (long int i = lenP + 2; i > 0; i--) {
			veraP[i] = veraP[i - 1];

		}
		veraP[0] = '+';
		veraP[lenP + 3] = '\0';

	}

	if ((veraP[0] == '+') && (veraP[1] == '0')) {
		for (long int i = 1; i < commaP; i++) {
			if (veraP[i] != '0') {
				veraP[i - 1] = '-';
				//veraP = veraP + i - 1;
				int tempLen = getLen(veraP);
				for (int j = i - 1; j <= tempLen; j++) {
					veraP[j - i + 1] = veraP[j];
				}
				break;
			}
		}
	}

	return veraP;

}

char** plusNull(char* x1, char* y1) {

	char** finalxy;
	//finalxy = (char**)calloc(2, sizeof(char*));
	finalxy = (char**)malloc(2 * sizeof(char*));

	long int lenX = getLen(x1), lenY = getLen(y1);
	char *x = (char *)malloc(sizeof(char) * (lenX + 1)), *y = (char*)malloc(sizeof(char)*(lenY + 1));
	for (int i = 0; i < lenX; i++) {
		x[i] = x1[i];

	}
	for (int i = 0; i < lenY; i++) {
		y[i] = y1[i];
	}
	x[lenX] = '\0';
	y[lenY] = '\0';

	long int ziffX = lenX - 1, ziffY = lenY - 1;
	long int commaX = 0, commaY = 0;
	while (x[ziffX] != ',') {

		ziffX--;

	}

	ziffX = lenX - ziffX - 1;
	commaX = lenX - ziffX - 1;
	while (y[ziffY] != ',') {

		ziffY--;

	}
	ziffY = lenY - ziffY - 1;
	commaY = lenY - ziffY - 1;


	for (long int i = lenX - 1; i > lenX - ziffX - 1; i--) {
		if (x[i] != '0') {

			lenX = i + 1;

			x[i + 1] = '\0';
			break;
		}
	}

	for (long int i = lenY - 1; i > lenY - ziffY - 1; i--) {
		if (y[i] != '0') {

			lenY = i + 1;
			y[i + 1] = '\0';
			break;
		}
	}

	long int ziffNeed;

	ziffX = lenX - commaX - 1;
	ziffY = lenY - commaY - 1;


	char* xt, *yt;
	if (ziffX != ziffY) {
		if (ziffX > ziffY) {

			//xt = (char*)calloc(lenX + 1, sizeof(char));
			xt = (char*)malloc((lenX + 1) * sizeof(char));
			for (long int i = 0; i < lenX; i++) {
				xt[i] = x[i];
			}
			xt[lenX] = '\0';
			ziffNeed = ziffX - ziffY;

			//yt = (char*)calloc(lenY + 1 + ziffNeed, sizeof(char));
			yt = (char*)malloc((lenY + 1 + ziffNeed) * sizeof(char));
			for (long int i = 0; i < lenY; i++) {
				yt[i] = y[i];
			}
			for (long int i = lenY; i < lenY + 1 + ziffNeed; i++) {
				yt[i] = '0';
			}
			lenY = lenY + ziffNeed;
			yt[lenY] = '\0';
		}
		else {

			//yt = (char*)calloc(lenY + 1, sizeof(char));
			yt = (char*)malloc((lenY + 1) * sizeof(char));
			for (long int i = 0; i < lenY; i++) {
				yt[i] = y[i];
			}
			yt[lenY] = '\0';
			ziffNeed = ziffY - ziffX;
			//xt = (char*)calloc(lenX + 1 + ziffNeed, sizeof(char));
			xt = (char*)malloc((lenX + 1 + ziffNeed) * sizeof(char));
			for (long int i = 0; i < lenX; i++) {
				xt[i] = x[i];
			}
			for (long int i = lenX; i < lenX + 1 + ziffNeed; i++) {
				xt[i] = '0';
			}
			lenX = lenX + ziffNeed;
			xt[lenX] = '\0';
		}
	}
	else {
		/*xt = (char*)calloc(lenY + 1, sizeof(char));
		yt = (char*)calloc(lenY + 1, sizeof(char));*/
		xt = (char*)malloc((lenX + 1) * sizeof(char));
		yt = (char*)malloc((lenY + 1) * sizeof(char));
		for (long int i = 0; i < lenX; i++) {
			xt[i] = x[i];
		}
		xt[lenX] = '\0';
		for (long int i = 0; i < lenY; i++) {
			yt[i] = y[i];
		}
		yt[lenY] = '\0';
	}

	char* xf, *yf;

	if (commaX != commaY) {
		long int zNeed;
		if (commaX < commaY) {

			//yf = (char*)calloc(lenY + 1, sizeof(char));
			yf = (char*)malloc((lenY + 1) * sizeof(char));
			for (long int i = 0; i < lenY; i++) {
				yf[i] = yt[i];

			}
			yf[lenY] = '\0';

			zNeed = commaY - commaX;

			//xf = (char*)calloc(lenX + zNeed + 1, sizeof(char));
			xf = (char*)malloc((lenX + zNeed + 1) * sizeof(char));
			for (long int i = 0; i < lenX; i++) {
				xf[lenX + zNeed - 1 - i] = xt[lenX - i - 1];

			}
			for (long int i = 1; i <= zNeed; i++) {
				xf[i] = '0';
			}
			xf[0] = xt[0];
			lenX = lenX + zNeed;
			xf[lenX] = '\0';
		}
		else {
			xf = (char*)malloc((lenX + 1) * sizeof(char));
			for (long int i = 0; i < lenX; i++) {
				xf[i] = xt[i];
			}
			xf[lenX] = '\0';

			zNeed = commaX - commaY;
			yf = (char*)malloc((lenY + zNeed + 1) * sizeof(char));
			for (long int i = 0; i < lenY; i++) {
				yf[lenY + zNeed - 1 - i] = yt[lenY - i - 1];
			}
			for (long int i = 1; i <= zNeed; i++) {
				yf[i] = '0';
			}
			yf[0] = yt[0];
			lenY = lenY + zNeed;
			yf[lenY] = '\0';

		}
	}
	else {
		/*xf = (char*)calloc(lenX + 1, sizeof(char));
		yf = (char*)calloc(lenY + 1, sizeof(char));*/
		xf = (char*)malloc((lenX + 1) * sizeof(char));
		yf = (char*)malloc((lenY + 1) * sizeof(char));
		for (long int i = 0; i < lenX; i++) {
			xf[i] = xt[i];
		}
		xf[lenX] = '\0';
		for (long int i = 0; i < lenY; i++) {
			yf[i] = yt[i];

		}
		yf[lenY] = '\0';
	}

	/*finalxy[0] = (char*)calloc(lenX + 1, sizeof(char));
	finalxy[1] = (char*)calloc(lenY + 1, sizeof(char));*/
	finalxy[0] = (char*)malloc((lenX + 1) * sizeof(char));
	finalxy[1] = (char*)malloc((lenY + 1) * sizeof(char));
	for (long int i = 0; i < lenX; i++) {
		finalxy[0][i] = xf[i];
		finalxy[1][i] = yf[i];
	}
	finalxy[0][lenX] = '\0';
	finalxy[1][lenY] = '\0';
	return finalxy;

}

long int getCommaSum(char* x, char* y) {
	long int sum = 0;
	long int ziffX = 0, ziffY = 0;
	long int lenX = getLen(x), lenY = getLen(y);
	while (x[ziffX] != ',') {
		ziffX++;
	}
	ziffX = lenX - ziffX - 1;
	while (y[ziffY] != ',') {
		ziffY++;
	}
	ziffY = lenY - ziffY - 1;
	if ((ziffX == 1) && (x[getLen(x) - 1] == '0')) {
		ziffX = 0;
	}
	if ((ziffY == 1) && (y[getLen(y) - 1] == '0')) {
		ziffY = 0;
	}

	sum = ziffX + ziffY;
	return sum;



	return sum;
}

char* allZ(char* p) {
	long int lenP = getLen(p);
	long int lenNew = lenP + 1;
	//char* newP = (char*)calloc(lenP + 2, sizeof(char));
	char* newP = (char*)malloc((lenP + 2) * sizeof(char));
	newP[0] = '0';
	newP[lenNew] = '\0';
	newP[lenNew - 1] = '0';
	newP[lenNew - 2] = ',';
	long int i0 = lenNew - 3;
	for (long int i = lenP - 1; i >= 0; i--) {

		if ((p[i] == ',') || ((i == lenP - 1) && (p[i] == '0'))) {
			continue;
		}
		newP[i0] = p[i];

		i0--;
	}
	if (newP[0] == '0') {
		newP = newP + 1;
	}

	return newP;
}

long int String2Int(char* str)
{
	char flag = '+';
	long res = 0;

	if (*str == '-') {
		++str;
		flag = '-';
	}

	while (*str >= 48 && *str < 57) {
		res = 10 * res + *str++ - 48;
	}

	if (flag == '-') {
		res = -res;
	}

	return (long int)res;
}

char* endVerab(char* p1) {
	long int lenP = getLen(p1);
	char *p = (char *)malloc(sizeof(char) * (lenP + 1));
	for (int i = 0; i < lenP; i++) {
		p[i] = p1[i];
	}
	p[lenP] = '\0';

	int cutNull = 0;
	while (p[cutNull + 1] == '0') {
		cutNull++;
	}

	if (p[0] == '+') {
		//p = p + cutNull + 1;//p的值向左移动cutNull+1位
		for (int i = cutNull + 1; i <= lenP; i++) {
			p[i - cutNull - 1] = p[i];
		}
		lenP = lenP - cutNull - 1;
	}

	if (p[0] == '-') {
		int i = 1;
		if ((p[i] == '0') && (p[i + 1] != ',')) {
			//p = p + cutNull;
			for (int i = cutNull; i <= lenP; i++) {
				p[i - cutNull] = p[i];
			}
			p[0] = '-';
			lenP = lenP - cutNull;
		}
	}

	if (p[lenP - 1] == '0') {

		long int t = lenP - 1;
		while (p[t] == '0') {
			p[t] = '\0';
			t--;
		}
		if (p[t] == ',') {
			p[t] = '\0';
			t--;
		}
	}

	return p;
}


long int mypow(long int x, long int y)
{
	long int result = 1;
	while (y--) {
		result *= x;
	}

	return result;
}

// void freeD1(char* p) {
//    if (*p != '\0') {
//        free(p);
//    }
//    p = NULL;
// }
// void freeD2(char** p, int len) {
//    for (int i = 0; i < len; i++) {
//        if (*p[i] != '\0') {
//            freeD1(p[i]);

//        }

//    }
//    if (**p != '\0') {
//        free(p);
//        //p = NULL;
//    }
// }

char* add(char* x1, char* y1, long int len) {
	//char* res = (char*)calloc(len + 3, sizeof(char));
	char* res = (char*)malloc((len + 3) * sizeof(char));
	long int lenR = len + 1;
	char *x = (char *)malloc(sizeof(char) * (len + 1)), *y = (char *)malloc(sizeof(char) * (len + 1));

	for (long int i = 0; i < lenR; i++)
	{
		res[i] = '0';
		x[i] = x1[i];
		y[i] = y1[i];
	}
	x[len] = '\0';
	y[len] = '\0';
	//printf("x = %s, y = %s\n", x, y);
	res[len + 1] = '\0';

	long int fstShortZ = 1;
	if (x[1] == '0') {
		while (x[fstShortZ] == '0') {
			fstShortZ++;
		}
	}
	if (y[1] == '0') {
		while (y[fstShortZ] == '0') {
			fstShortZ++;
		}
	}

	if (x[0] == y[0]) {

		res[0] = x[0];
		int flag = 0;
		long int i0 = 0;

		for (long int i = len - 1; i >= fstShortZ; i--) {

			int t;
			if (x[i] == ',') {
				res[i + 1] = ',';
				i0++;
				continue;
			}
			if (flag == 1) {

				t = addTable[x[i] - 48][y[i] - 48];

				int t1;
				if (t >= 9) {
					t1 = t / 1 % 10;
					t1 = addTable[t1][1];
					flag = 1;
				}
				else {
					t1 = t;
					t1 = addTable[t1][1];
					flag = 0;
				}
				res[i + 1] = '0' + t1;
				i0++;
			}
			else {

				t = addTable[x[i] - 48][y[i] - 48];
				int t1;


				if (t >= 9) {
					t1 = t / 1 % 10;
					flag = 1;
				}
				else {
					t1 = t;
					flag = 0;
				}

				res[i + 1] = '0' + t1;

				i0++;


			}

		}

		if ((fstShortZ == 1) && (flag == 1)) {
			res[1] = '1';
		}

		int flag2 = 0;

		for (int i = 1; i < len; i++) {
			if (x[i] < y[i]) {
				flag2 = 1;
				break;
			}

		}
		if (x[1] == '0') {
			flag2 = 1;
		}
		if (y[1] == '0') {
			flag2 = 0;
		}

		if ((flag == 1) && (fstShortZ != 1)) {
			if (flag2 == 0) {

				for (int i = fstShortZ; i > 1; i--) {
					if (x[i - 1] == '8') {
						for (int j = i - 1; j > 0; j--) {
							if (x[j] == '8') {
								x[j] = '0';
							}
							else {
								x[j] = x[j] + 1;

								break;
							}

						}
						if (x[1] == '0') {
							res[1] = '1';
						}
						res[i] = x[i - 1];

					}
					else {
						x[i - 1] = x[i - 1] + 1;

						for (int j = i; j > 0; j--) {
							res[j] = x[j - 1];
						}

						res[1] = res[0];
						//res++;//res左移1位
						long int lenRe = getLen(res);
						for (int i = 1; i < lenRe; i++) {
							res[i - 1] = res[i];
						}

						break;
					}
				}
			}
			else {
				for (int i = fstShortZ; i > 1; i--) {
					if (x[i - 1] == '8') {
						for (int j = i - 1; j > 0; j--) {
							if (x[j] == '8') {
								x[j] = '0';

							}
							else {
								x[j] = x[j] + 1;

								break;
							}

						}
						if (x[1] == '0') {
							res[1] = '1';
						}
						res[i] = x[i - 1];

					}
					else {
						x[i - 1] = x[i - 1] + 1;
						for (int j = i; j > 0; j--) {
							res[i] = x[i - 1];
						}
						res[1] = res[0];

						//res++;
						long int lenRe = getLen(res);
						for (int i = 1; i < lenRe; i++) {
							res[i - 1] = res[i];
						}
						break;
					}
				}
			}


		}
		if ((flag == 0) && (fstShortZ != 1)) {
			if (flag2 == 0) { //x>y
				for (int i = fstShortZ; i > 0; i--) {
					res[i] = x[i - 1];
				}
				res[1] = res[0];
				//res++;
				long int lenRe = getLen(res);
				for (int i = 1; i < lenRe; i++) {
					res[i - 1] = res[i];
				}

			}
			else {
				for (int i = fstShortZ; i > 0; i--) {
					res[i] = y[i - 1];
				}
				res[1] = res[0];
				//res++;
				long int lenRe = getLen(res);
				for (int i = 1; i < lenRe; i++) {
					res[i - 1] = res[i];
				}

			}
		}

		//去除后导0
		long int lenRe = getLen(res);
		if ((res[lenRe - 2] != ',') && (res[lenRe - 1] == '0'))
		{
			long int i0 = 0;
			for (int i = lenRe - 1; i > 0; i--) {
				if ((res[i] == '0') && (res[i - 1] != ',')) {
					i0++;
				}
				if ((res[i] != '0') || (res[i - 1] == ',')) {
					break;
				}
			}
			res[lenRe - i0] = '\0';
		}

		return res;
	}
	else {

		if (x[0] == '-') {
			x[0] = '+';
			return mini(y, x, len);
		}
		if (x[0] == '+') {
			y[0] = '+';

			return mini(x, y, len);
		}

	}
	return 0;
}

char* mini(char* x1, char* y1, long int len) {

	char* res;

	char *x = (char *)malloc(sizeof(char) * (len + 1)), *y = (char *)malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++) {
		x[i] = x1[i];
		y[i] = y1[i];
	}
	x[len] = '\0';
	y[len] = '\0';

	//int flag = 0;
	if (x[0] == y[0])
	{
		if (x[0] == '+')
		{

			char *t = miniR(x, y, len);
			long int lenT = getLen(t);
			//res = (char*)calloc(lenT + 1, sizeof(char));
			res = (char *)malloc((lenT + 1) * sizeof(char));
			res[lenT] = '\0';
			for (long int i = 0; i < lenT; i++)
			{
				res[i] = t[i];
			}
		}
		else
		{
			x[0] = '+';
			y[0] = '+';
			char *t = miniR(y, x, len);
			long int lenT = getLen(t);
			//res = (char*)calloc(lenT + 1, sizeof(char));
			res = (char *)malloc((lenT + 1) * sizeof(char));
			res[lenT] = '\0';
			for (long int i = 0; i < lenT; i++)
			{
				res[i] = t[i];
			}
		}
	}
	else
	{

		if (x[0] == '+')
		{
			y[0] = '+';
			return add(x, y, len);
		}
		else
		{

			x[0] = '+';
			y[0] = '+';
			char *t = add(x, y, len);

			long int lenT = getLen(t);

			//res = (char*)calloc(lenT + 1, sizeof(char));
			res = (char *)malloc((lenT + 1) * sizeof(char));
			res[0] = '-';
			res[lenT] = '\0';

			for (long int i = 1; i < lenT; i++)
			{
				res[i] = t[i];
			}
		}
	}


	return res;
}

char* miniR(char* x1, char* y1, long int len) {

	char *x = (char *)malloc(sizeof(char) * (len + 1)), *y = (char *)malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++) {
		x[i] = x1[i];
		y[i] = y1[i];
	}
	x[len] = '\0';
	y[len] = '\0';

	long int commaX = 0, commaY = 0;
	while (x[commaX] != ',') {
		commaX++;
	}
	while (y[commaY] != ',') {
		commaY++;
	}
	long int fstNumX = 1, fstNumY = 1;
	while (x[fstNumX] == '0') {
		fstNumX++;
	}
	while (y[fstNumY] == '0') {
		fstNumY++;
	}
	//long int longX = commaX - fstNumX, longY = commaY - fstNumY;
	//long int longZ = max(longX,longY),shortZ = min(longX,longY);

	/*char* res = (char*)calloc(len + 1, sizeof(char));*/
	char* res = (char*)malloc((len + 1) * sizeof(char));
	res[len] = '\0';

	long int flag2 = 0, i0 = 0;

	if (x[1] > y[1]) {
		flag2 = 0;
	}
	if (x[1] == y[1]) {
		for (long int i = 2; i < len; i++) {
			if (i == commaX) {
				continue;
			}
			if (x[i] < y[i]) {
				flag2 = 1;
				break;
			}
			if ((i == len - 1) && (x[i] >= y[i])) {
				flag2 = 0;
			}
		}

	}
	if (x[1] < y[1]) {
		flag2 = 1;
	}

	if (flag2 == 1) {
		for (long int j = 0; j < len; j++) {
			char temp = y[j];
			y[j] = x[j];
			x[j] = temp;
		}
	}

	for (long int i = len - 1; i > 0; i--) {
		if (x[i] == ',') {
			res[len - i0 - 1] = ',';
			i0++;
			continue;
		}

		int t;
		if (x[i] < y[i]) {
			int xNum = x[i] - 48;
			xNum = xNum + 9;
			t = miniTable[xNum][y[i] - 48];


			if ((x[i - 1] == '0') || ((x[i - 1] == ',') && (x[i - 2] == '0'))) {
				long int start = 1;
				while (x[start] == '0') {
					start++;
				}
				for (long int j = start; j <= i - 1; j++) {
					if (x[j] > '0') {
						x[j] = x[j] - 1;
					}
					if (x[j] == '0') {
						x[j] = 57;
					}
				}
			}
			if ((x[i - 1] != '0') && (x[i - 1] != ',')) {
				x[i - 1] = x[i - 1] - 1;
			}
			if ((x[i - 1] == ',') && (x[i - 2] != '0')) {
				x[i - 2] = x[i - 2] - 1;
			}


		}
		else {
			t = miniTable[x[i] - 48][y[i] - 48];


		}
		res[len - i0 - 1] = '0' + t;
		i0++;

	}

	if ((res[0] != '+') && (res[0] != '-')) {
		i0 = 1;
		while ((res[i0] == '-') || (res[i0] == '+')) {
			i0++;
		}
		//res = res + i0 - 1;//向左移动i0-1位
		long int lenRe = getLen(res);
		for (int i = i0 - 1; i <= lenRe; i++) {
			res[i - i0 + 1] = res[i];
		}
	}
	if (flag2 == 1) {
		res[0] = '-';
	}
	else {
		res[0] = '+';
	}

	//printf("res = %s\n",res);
	return res;
}


char* multi(char* xt1, char* yt1, long int len, long int commaSum) {

	char** res;
	char *xt = (char *)malloc(sizeof(char) * (len + 1)), *yt = (char *)malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++) {
		xt[i] = xt1[i];
		yt[i] = yt1[i];
	}
	xt[len] = '\0';
	yt[len] = '\0';

	char *y = allZ(yt);
	long int lenR = getLen(y) - 3, lenX = getLen(xt);
	/*char* y0 = (char*)calloc(lenR + 1, sizeof(char));*/
	char* y0 = (char*)malloc((lenR + 1) * sizeof(char));
	y0[lenR] = '\0';
	for (long int i = 1; i < lenR + 1; i++) {
		y0[i - 1] = y[i];
	}

	lenR = (long int)String2Int(y0) - 1;

	if (lenR < 0) {
		lenR = lenR * (-1);
	}
	long int t = lenR, n = 0, lenR9 = 0;
	while (t) {
		t = t / 10;
		n++;
	}

	for (long int i = 1; i <= n; i++) {

		lenR9 = lenR9 + ((lenR + 1) / mypow(10, i - 1) % 10) * mypow(9, i - 1);
	}
	lenR = lenR9 - 1;
	/*res = (char**)calloc(2, sizeof(char*));
	res[0] = (char*)calloc(2 * len, sizeof(char));
	res[1] = (char*)calloc(2 * len, sizeof(char));*/
	res = (char**)malloc(2 * sizeof(char*));
	res[0] = (char*)malloc((2 * len) * sizeof(char));
	res[1] = (char*)malloc((2 * len) * sizeof(char));
	int count = 1;

	int flag0 = 0;
	if (xt[0] == yt[0]) {
		xt[0] = '+';
		yt[0] = '+';
		flag0 = 0;
	}
	else {
		xt[0] = '+';
		yt[0] = '+';
		flag0 = 1;

	}

	for (long int i = 0; i < lenR; i++) {
		long int lenRt;

		if (i != 0) {

			char** xy = plusNull(verarbeitZ(res[count]), verarbeitZ(xt));

			lenRt = getLen(xy[0]);

			xy[0][0] = '+';
			xy[1][0] = '+';
			//printf("xy[0] = %s, xy[1] = %s\n", xy[0], xy[1]);
			char *t = add(xy[0], xy[1], lenRt);

			long int lenT = getLen(t);
			//printf("lenT === %d, t= %s\n", lenT,t);
			if (res[!count][0] != '\0')
			{

				res[!count][lenT] = '\0';
			}

			for (long int j = 0; j < lenT; j++) {

				res[!count][j] = t[j];
			}
			res[!count][lenT] = '\0';
			//printf("res[!count] = %s\n", res[!count]);
			//printf("lenT = %d\n", lenT);
			count = !count;
		}
		else {

			char* t = add(xt, xt, lenX);
			long int lenT = getLen(t);

			for (long int j = 0; j < lenT; j++) {
				res[0][j] = t[j];
			}
			res[0][lenT] = '\0';
			//printf("lenT0 = %d\n", lenT);
			count = 0;
		}

	}

	if (flag0 == 0) {
		res[count][0] = '+';
	}
	else {
		res[count][0] = '-';
	}

	long int lenRes = getLen(res[count]);
	if (res[count][lenRes - 1] != '0') {
		commaSum--;
	}





	for (long int i = lenRes - 2; i > lenRes - 2 - commaSum; i--) {
		res[count][i] = res[count][i - 1];
	}
	res[count][lenRes - 2 - commaSum] = ',';

	return res[count];
}

char* rechner(char* x, char* y, char* xt, char* yt, char opr, long int len, long int commaSum) {
	//char* res = (char*)malloc((len + 2)* sizeof(char));
	switch (opr) {

	case '+':

		return add(x, y, len);
	case '-':


		return mini(x, y, len);
	case '*':

		return multi(xt, yt, len, commaSum);
	}
	return NULL;
}