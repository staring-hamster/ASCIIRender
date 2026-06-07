#include <iostream>

#define width 200
#define height 80

class Vector2D{
	public:
	double x;
	double y;
	
	Vector2D(double x, double y){
		this->x = x;
		this->y = y; 	
	}

	Vector2D operator-(Vector2D &sub){
		return Vector2D(this->x - sub.x, this->y - sub.y);
	}

	Vector2D operator/(float &divisor){
		return Vector2D(this->x / divisor, this->y / divisor);
	}
};

bool matrix[height][width];

void initMatrix(){
	for (int f = 0; f < height; f++){ // Filas
		for (int c = 0; c < width; c++){ // Dentro de la fila
			matrix[f][c] = false;
		}
	}
}

void printMatrix(){
	for (int f = 0; f < height; f++){ // Eje Y
		for (int c = 0; c < width; c++){ // Eje X
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
	matrix[y][x] = value;
}

void drawLine(Vector2D start, Vector2D end){
	Vector2D originVector = end - start;
	for (double i = 0.01; i < 1.0; i+= 0.01){
		double x = (originVector.x * i) + start.x;
		double y = (originVector.y * i) + start.y;
		setBit((int)x, (int)y, true);
	}
}

int main(){
	initMatrix();

	drawLine({10, 10}, {20, 40});
	
	printMatrix();
	
	return 0;
}
