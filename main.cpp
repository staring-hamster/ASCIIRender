#include <iostream>

#define WIDTH 200
#define HEIGHT 80

#define MAX_X WIDTH - 1
#define MAX_Y HEIGHT - 1

class Vector2D{
	public:
	double x;
	double y;
	
	Vector2D(double x, double y){
		this->x = x;
		this->y = y; 	
	}
	Vector2D operator+(Vector2D &add){
		return Vector2D(this->x + add.x, this->y + add.y);
	}
	Vector2D operator-(Vector2D &sub){
		return Vector2D(this->x - sub.x, this->y - sub.y);
	}
	Vector2D operator/(double &divisor){
		return Vector2D(this->x / divisor, this->y / divisor);
	}
	Vector2D operator*(double &multiplier){
		return Vector2D(this->x * multiplier, this->y * multiplier);
	}
};

bool matrix[HEIGHT][WIDTH];

void initMatrix(){
	for (int f = 0; f < HEIGHT; f++){ // Filas
		for (int c = 0; c < WIDTH; c++){ // Dentro de la fila
			matrix[f][c] = false;
		}
	}
}

void printMatrix(){
	for (int f = 0; f < HEIGHT; f++){ // Eje Y
		for (int c = 0; c < WIDTH; c++){ // Eje X
			if (matrix[f][c]){
				std::cout << "▄ ";
			}
			else{
				std::cout << ". ";
			}
		}
		std:: cout << std::endl;
	}
}

void setBit(int x, int y, bool value){
	if ((x >= 0 and x <= MAX_X) and (y >= 0 and y <= MAX_Y)){
		matrix[y][x] = value;	
	}
}

void drawLine(Vector2D startPoint, Vector2D endPoint){
	Vector2D originVector = endPoint - startPoint;
	for (double i = 0.01; i < 1.0; i+= 0.01){
		Vector2D scaledPoint = (originVector * i) + startPoint;
		setBit((int)scaledPoint.x, (int)scaledPoint.y, true);
	}
}

int main(){
	initMatrix();

	drawLine({10, 10}, {20, 40});
	
	printMatrix();
	
	return 0;
}
