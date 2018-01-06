#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int size = 5;
char map[size][size];

struct Node2D{
	int row;
	int col;
};

class Astar{
private:
	//the distance ignore the blocking
	int heristic;
	//the distance consider the blocking
	int movement;
	//total
	int total;
	//the minimum distance sourrond the current node
	Node2D parent;
	bool visit;
	void calTotal(){
		total = heristic + movement;
		//visit = true;
	}
public:
	//initial all
	Astar(){
		heristic = 32767;
		movement = 32767;
		total = 32767;
		parent.row = 0;
		parent.col = 0;
		visit = false;
	}
	void setHeristic(int heristic_){heristic = heristic_;}
	void setMovement(int movement_){
		movement = movement_;
		calTotal();
	}
	void setParent(Node2D parent_){
		parent.row = parent_.row;
		parent.col = parent_.col;
	}

	int getHeristic(){return heristic;}
	int getMovement(){return movement;}
	int getTotal(){return total;}
	Node2D getParent(){return parent;}

	void printHerstic(){cout << ' ' << heristic << " ";}
	void printTotal(){cout << ' ' << total << " ";}
	void printMovement(){cout << ' ' << movement << " ";}

};

Astar hidden[size][size];

void getMap(){
	srand(14322);
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(rand() % 3 == 1) map[i][j] = 'X';
			else map[i][j] = '-';
		}
	}
}

void printMap(){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cout << ' ' << map[i][j] << " ";
		}
		cout << endl;
	}
}

void printAllHerstic(){
	for(int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			hidden[i][j].printHerstic();
		}
		cout << endl;
	} 
}

void printMove(){
	for(int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if(hidden[i][j].getMovement() == 32767){
				cout << " - " ;
			}
			else hidden[i][j].printMovement();
		}
		cout << endl;
	} 
}
void printAll(){
	for(int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if(hidden[i][j].getTotal() == 32767){
				cout << " - " ;
			}
			else hidden[i][j].printTotal();
		}
		cout << endl;
	} 
}

//heristic is the distance from everyNode to destination
void allHeristic(Node2D end){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(map[i][j] == 'X'){ 
				hidden[i][j].setHeristic(0);
				continue;
			}
			Node2D start;
			int heristic = 0;
			start.row = i;
			start.col = j;
			//check from all direction
			while(start.row < end.row) {
				heristic++;
				start.row++;
			}
			while(start.row > end.row) {
				heristic++;
				start.row--;
			}
			while(start.col < end.col) {
				start.col++;
				heristic++;
			}
			while(start.col > end.col) {
				start.col--;
				heristic++;
			}
			hidden[i][j].setHeristic(heristic);
		}
	}
}

bool finish = false;

void checkMovement(Node2D start, Node2D end){
	//if we reach the destination
	if(finish == true) return;
	//if we beyond the map
	if(start.row < 0 || start.row >= size || start.col < 0 || start.col >= size) return;
	//if node the visited
	if(map[start.row][start.col] == 'X' || map[start.row][start.col] == 'V') return;
	if(start.row == end.row && start.col == end.col){
		finish = true;
		return;
	}

	int parentRow = 0;
	int parentCol = 0;
	int cost = hidden[start.row][start.col].getTotal();
	//go through vertical direction
	for(int i = -1; i < 2; i = i + 2){
		if((start.row + i) < 0 || (start.row + i) >= size 
			|| (start.col) < 0 || (start.col) >= size){}
		else if(map[start.row + i][start.col] == 'X' 
			|| map[start.row + i][start.col] == 'V'){}
		else {
			if(hidden[start.row + i][start.col].getMovement() > hidden[start.row][start.col].getMovement()){
				hidden[start.row + i][start.col].setMovement(
				hidden[start.row][start.col].getMovement() + 3); 
			}
			/************************************************
			 * ok if the adjacent node has smaller cost 	*
			 * than current set the current node as parent 	*
			 * for adjacent node 							*
			 ************************************************/
			if(cost < hidden[start.row + i][start.col].getTotal()){
				Node2D parent;
				parent.row = start.row;
				parent.col = start.col;
				//cout << parent.row << endl;
				hidden[start.row + i][start.col].setParent(parent);
			}
			
		}
	}
	
	//go through horizontal direction
	for(int j = -1; j < 2; j = j + 2){
		if((start.row) < 0 || (start.row) >= size 
			|| (start.col + j) < 0 || (start.col + j) >= size){}
		else if(map[start.row][start.col + j] == 'X' 
			|| map[start.row][start.col + j] == 'V'){}
		else {
			if(hidden[start.row][start.col + j].getMovement() > hidden[start.row][start.col].getMovement()){
				hidden[start.row][start.col + j].setMovement(
				hidden[start.row][start.col].getMovement() + 3); 
			}

			/************************************************
			 * ok if the adjacent node has smaller cost 	*
			 * than current set the current node as parent 	*
			 * for adjacent node 							*
			 ************************************************/
			if(cost < hidden[start.row][start.col + j].getTotal()){
				Node2D parent;
				parent.row = start.row;
				parent.col = start.col;
				//cout << parent.row << endl;
				hidden[start.row][start.col + j].setParent(parent);
			}
			
		}
	}

	//ok we visited this node
	map[start.row][start.col] = 'V';


	//take recursion for 4 direction
	Node2D temp = start;
	temp.row++;
	checkMovement(temp, end);
	temp = start;
	temp.row--;
	checkMovement(temp, end);
	temp = start;
	temp.col++;
	checkMovement(temp, end);
	temp = start;
	temp.col--;
	checkMovement(temp, end);
	temp = start;
}

//find the path depend on parent
void findPath(Node2D start){
	cout << hidden[start.row][start.col].getParent().row << endl;
	if(map[start.row][start.col] == 'A') return;
	if(hidden[start.row][start.col].getParent().row == 32767) return;
	map[start.row][start.col] = 'A';
	findPath(hidden[start.row][start.col].getParent());
}

int main(int argc, char const *argv[]){
	getMap();
	printMap();
	//int row, col;
	Node2D start, end;
	cout << "choose your destination" << endl;
	//cin >> end.row >> end.col;
	end.row = 1;
	end.col = 1;
	map[end.row][end.col] = 'B';

	cout << "choose your location" << endl;
	//cin >> start.row >> start.col;
	start.row = 3;
	start.col = 3;
	map[start.row][start.col] = 'A';
	allHeristic(end);
	printMap();
	printAllHerstic();
	hidden[start.row][start.col].setMovement(0);
	cout << endl;
	checkMovement(start, end);
	printMove();
	cout << endl;
	printAll();

	map[start.row][start.col] = 'A';

	findPath(end);
	printMap();

	return 0;
} 