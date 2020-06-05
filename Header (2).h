#include <stdio.h>  
#include<string>
#include<fstream>
#include<iostream>

using namespace std;
//point1 - name of the city, numb - number of the city
struct node {
	int numb;
	string point1;
};
//  node in adjacency list 
struct ListNode
{
	node dest;
	int cost;
	ListNode* next;
};

//  adjacency list 
struct AdjList
{
	ListNode* head;
};

// A structure of a graph with array of adjacency lists
struct Graph
{
	int V;
	AdjList* array;
};


//checking trilogy

//check a string in array
bool checking(string check[], string check1) {
	int i = 0;
	for (int i = 0; i < sizeof(check); i++) {
		string help = check[i];
		if (check[i] == check1)
			return false;
	}
	return true;
}

//find an index of string
int checking2(string check[100], string str) {
	int i = 0;
	for (i = 0; i < 100; i++) {
		if (check[i] == str)
			return i;
	}
}

//check string in array
bool checking3(string check[100], string str) {
	int i = 0;
	for (i = 0; i < sizeof(check); i++) {
		if (check[i] == str)
			return true;
	}
	check[i] = str;
	return false;
}


ListNode* newListNode(int dest1, int cost, string destination)
{
	ListNode* newNode = new ListNode;

	newNode->dest.point1 = destination;
	newNode->dest.numb = dest1;
	newNode->cost = cost;
	newNode->next = NULL;
	return newNode;
}

//  creates a graph with V vertices 
Graph* createGraph(int V)
{
	Graph* graph = new Graph;
	graph->V = V;

	graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

	for (int i = 0; i < V; ++i)
		graph->array[i].head = NULL;

	return graph;
}

// Adds an edge 
void addEdge(Graph* graph, int src, int dest, int cost, int cost2, string source, string destination)
{

	ListNode* newNode = newListNode(dest, cost, destination);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	newNode = newListNode(src, cost2, source);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

// min heap node 
struct MinHeapNode
{
	int  v;
	int cost;
};

// min heap 
struct MinHeap
{
	int size;
	int capacity;
	int* pos;     // This is needed for decreaseKey() 
	MinHeapNode** array;
};

// create a new Min Heap Node 
MinHeapNode* newMinHeapNode(int v, int cost)
{
	MinHeapNode* minHeapNode = new MinHeapNode;
	minHeapNode->v = v;
	minHeapNode->cost = cost;
	return minHeapNode;
}

//create a Min Heap 
MinHeap* createMinHeap(int capacity)
{
	MinHeap* minHeap = new MinHeap;
	minHeap->pos = new int[capacity];
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (MinHeapNode**)malloc(capacity * sizeof(MinHeapNode*));
	return minHeap;
}

// swap two nodes of min heap
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b)
{
	MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

// heapify at given idx 
void minHeapify(MinHeap* minHeap, int idx)
{
	int smallest, left, right;
	smallest = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < minHeap->size &&
		minHeap->array[left]->cost < minHeap->array[smallest]->cost)
		smallest = left;

	if (right < minHeap->size &&
		minHeap->array[right]->cost < minHeap->array[smallest]->cost)
		smallest = right;

	if (smallest != idx)
	{

		MinHeapNode* smallestNode = minHeap->array[smallest];
		MinHeapNode* idxNode = minHeap->array[idx];


		minHeap->pos[smallestNode->v] = idx;
		minHeap->pos[idxNode->v] = smallest;

		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

		minHeapify(minHeap, smallest);
	}
}

// Heap Empty or not
bool isEmpty(MinHeap* minHeap)
{
	return minHeap->size == 0;
}

// extract minimum node from heap 
MinHeapNode* extractMin(MinHeap* minHeap)
{
	if (isEmpty(minHeap))
		return NULL;


	MinHeapNode* root = minHeap->array[0];


	MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
	minHeap->array[0] = lastNode;


	minHeap->pos[root->v] = minHeap->size - 1;
	minHeap->pos[lastNode->v] = 0;

	minHeap->size--;
	minHeapify(minHeap, 0);

	return root;
}

// decrease dist value of a given vertex v
void decreaseKey(MinHeap* minHeap, int v, int cost)
{

	int i = minHeap->pos[v];


	minHeap->array[i]->cost = cost;


	while (i && minHeap->array[i]->cost < minHeap->array[(i - 1) / 2]->cost)
	{

		minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
		minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
		swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

		i = (i - 1) / 2;
	}
}


// 'v' is in min heap or not 
bool isInMinHeap(MinHeap* minHeap, int v)
{
	if (minHeap->pos[v] < minHeap->size)
		return true;
	return false;
}
//find a string with given index
string finding(int src, string help[100]) {
	return help[src];
}
//print the solution 
void print(string help[100], int cost[], int n, int src)
{
	string helping = finding(src, help);
	cout << "source is" << " " << helping << endl;
	cout << endl;
	for (int i = 0; i < n; i++) {
		if (cost[i] != 0)
			cout << finding(i, help) << " " << cost[i] << endl;
	}
}


// The main function that calulates distances of shortest paths from src to all
void dijkstra(string help[100], Graph* graph, int src)
{
	int V = graph->V - 1;
	int* cost = new int[V];

	MinHeap* minHeap = createMinHeap(V);

	for (int v = 0; v < V; ++v)
	{
		cost[v] = INT_MAX;
		minHeap->array[v] = newMinHeapNode(v, cost[v]);
		minHeap->pos[v] = v;
	}

	minHeap->array[src] = newMinHeapNode(src, cost[src]);
	minHeap->pos[src] = src;
	cost[src] = 0;
	decreaseKey(minHeap, src, cost[src]);

	minHeap->size = V;

	while (!isEmpty(minHeap))
	{

		MinHeapNode* minHeapNode = extractMin(minHeap);
		int u = minHeapNode->v;

		struct ListNode* pCrawl = graph->array[u].head;
		while (pCrawl != NULL)
		{
			int v = pCrawl->dest.numb;


			if (isInMinHeap(minHeap, v) && cost[u] != INT_MAX && pCrawl->cost + cost[u] < cost[v])
			{
				cost[v] = cost[u] + pCrawl->cost;

				decreaseKey(minHeap, v, cost[v]);
			}
			pCrawl = pCrawl->next;
		}
	}

	print(help, cost, V, src);
}

//count a number of cities in given file
int count() {
	fstream source;
	source.open("ooo.txt", ios::in);
	int j = 0;
	int i = 0;
	int k = 0;
	int checks = 0;
	int counting = 0;
	char check = ' ';
	string check1[100];
	char* save = new char[100];
	while (!source.eof())
	{
		i = 0;
		while ((check != '\0') && (!source.eof()))
		{
			checks = 0;
			source.get(check);
			if (check == ';') {
				j++;
				save[k] = '\0';
				string help = (string)save;
				if (checking(check1, help) == true)
					counting++;
				check1[i] = help;
				i++;
				memset(save, 0, sizeof(save) / sizeof(save[0]));
				checks = 1;
				k = -1;
			}
			if (j == 2) {
				while (((check == '0') || (check == '1')
					|| (check == '2') || (check == '3')
					|| (check == '4') || (check == '5')
					|| (check == '6') || (check == '7')
					|| (check == '8') || (check == '9')
					|| (check == ';') || (check == '/')
					|| (check == 'A') || (check == 'N'))
					&& (!source.eof()))source.get(check);
				j = 0;
				k = 0;
				checks = 0;
			}
			if (checks == 0)
				save[k] = check;
			k++;
		}
		string help = (string)save;
		if (checking(check1, check1[k]) == true)
			counting++;
		check1[i] = help;
		i++;
	}
	return counting;
}

