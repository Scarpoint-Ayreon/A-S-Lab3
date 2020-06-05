#include "Header.h"



int main() {
	fstream source;
	int f = 0;
	source.open("ooo.txt", ios::in);
	int V = count();
	Graph* Graph = createGraph(V);
	char help[100];
	string helping[100];
	int j = 0;
	while (!source.eof()) {
		string point1, point2 = "";
		int i = 1;
		if (j == 0)
			i = 0;
		int cost, cost2 = 0;
		char check = ' ';
		while (check != ';') {
			source >> check;
			if (check == ';')
				break;
			help[i] = check;
			i++;
		}
		help[i] = '\0';
		point1 = (string)help;
		check = ' ';
		i = 0;
		while (check != ';') {
			//i = 0;
			source >> check;
			if (check == ';')
				break;
			help[i] = check;
			i++;
		}
		help[i] = '\0';
		point2 = (string)help;
		check = ' ';
		i = 0;
		while (check != ';') {
			//i = 0;
			source >> check;
			if (check == ';')
				break;
			help[i] = check;
			i++;
		}
		help[i] = '\0';
		if ((help[0] == 'N') && (help[1] == '/') && (help[2] == 'A')) {
			cost = INT_MAX;
		}
		else
			cost = stoi(help);
		source >> check;
		i = 0;
		while (((check == '0') || (check == '1')
			|| (check == '2') || (check == '3')
			|| (check == '4') || (check == '5')
			|| (check == '6') || (check == '7')
			|| (check == '8') || (check == '9')
			|| (check == ';') || (check == '/')
			|| (check == 'A') || (check == 'N'))
			&& (!source.eof())) {
			//i = 0;
			if (check == ';')
				break;
			help[i] = check;
			i++;
			if (((check == '0') || (check == '1')
				|| (check == '2') || (check == '3')
				|| (check == '4') || (check == '5')
				|| (check == '6') || (check == '7')
				|| (check == '8') || (check == '9')
				|| (check == ';') || (check == '/')
				|| (check == 'A') || (check == 'N'))
				&& (!source.eof()))
				source >> check;
		}
		help[i] = '\0';
		if ((help[0] == 'N') && (help[1] == '/') && (help[2] == 'A')) {
			cost2 = INT_MAX;
		}
		else
			cost2 = stoi(help);
		int point11, point12 = 0;
		if (checking3(helping, point1) == true)
			point11 = checking2(helping, point1);
		else {
			helping[f] = point1;
			point11 = f;
			f++;
		}
		if (checking3(helping, point2) == true)
			point12 = checking2(helping, point2);
		else {
			helping[f] = point2;
			point12 = f;
			f++;
		}
		addEdge(Graph, point11, point12, cost, cost2, point1, point2);
		help[0] = check;
		j++;
	}
	source.close();
	string city;
	cout << "enter a city" << endl;
	getline(cin, city);
	if (checking3(helping, city) == false)
		return 0;
	int index = checking2(helping, city);
	dijkstra(helping, Graph, index);
}
