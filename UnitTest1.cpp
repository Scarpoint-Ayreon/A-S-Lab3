#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\user\source\repos\4.3\4.3\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(NewListNode)
		{
			int one = 1;
			int cost = 10;
			string destination = "Moscow";
			ListNode* test = newListNode(one, cost, destination);
			Assert::AreEqual(1, test->dest.numb);
			Assert::AreEqual((string)"Moscow", test->dest.point1);
			Assert::AreEqual(10, test->cost);
		}
		TEST_METHOD(CreateGraph)
		{
			int V = 9;
			Graph* graph = createGraph(V);
			Assert::AreEqual(9, graph->V);
		}
		TEST_METHOD(Addedge)
		{
			int V = 9;
			Graph* graph = createGraph(V);
			int point11 = 1;
			int point12 = 2;
			int cost = 10;
			int cost2 = 15;
			string point1 = "Saint-P";
			string point2 = "Moscow";

			addEdge(graph, point11, point12, 10, 15, point1, point2);
			Assert::AreEqual(graph->array[1].head->cost, 10);
			Assert::AreEqual(graph->array[1].head->dest.point1, (string)"Moscow");
			Assert::AreEqual(graph->array[1].head->dest.numb, 2);
			Assert::AreEqual(graph->array[2].head->cost, 15);
			Assert::AreEqual(graph->array[2].head->dest.point1, (string)"Saint-P");
			Assert::AreEqual(graph->array[2].head->dest.numb, 1);
		}
		TEST_METHOD(newheapnode)
		{
			int V = 9;
			int cost = 15;
			MinHeapNode* save = newMinHeapNode(V, cost);
			Assert::AreEqual(9, save->v);
			Assert::AreEqual(15, save->cost);
		}
		TEST_METHOD(newheap)
		{
			int V = 9;
			//int cost = 15;
			MinHeap* save = createMinHeap(V);
			Assert::AreEqual(9, save->capacity);
			Assert::AreEqual(0, save->size);
		}

		TEST_METHOD(swap)
		{
			int V = 9;
			int cost = 15;
			MinHeapNode* save = newMinHeapNode(V, cost);
			int V1 = 12;
			int cost1 = 17;
			MinHeapNode* save1 = newMinHeapNode(V1, cost1);
			swapMinHeapNode(&save, &save1);
			Assert::AreEqual(12, save->v);
			Assert::AreEqual(17, save->cost);
			Assert::AreEqual(9, save1->v);
			Assert::AreEqual(15, save1->cost);
		}
		TEST_METHOD(Heapify)
		{
			int V = 9;
			int cost = 15;
			MinHeapNode* save = newMinHeapNode(V, cost);
			int V1 = 12;
			int cost1 = 17;
			MinHeapNode* save1 = newMinHeapNode(V1, cost1);
			MinHeap* test = createMinHeap(V);
			for (int v = 0; v < 5; v++)
			{
				test->array[v] = newMinHeapNode(v, v + 1);
				test->pos[v] = v;
			}

			minHeapify(test, 0);
			Assert::AreEqual(0, test->array[0]->v);
			Assert::AreEqual(1, test->array[0]->cost);
		}

		TEST_METHOD(Empty)
		{
			int V = 9;
			int cost = 15;
			MinHeap* save = createMinHeap(V);
			bool test = isEmpty(save);
			Assert::AreEqual(test, true);
		}
		TEST_METHOD(Empty2)
		{
			int V = 9;
			int cost = 15;
			MinHeap* save = createMinHeap(V);
			for (int i = 0; i < 5; i++) {
				save->array[i] = newMinHeapNode(i, i + 1);
				save->size++;
			}

			bool test = isEmpty(save);
			Assert::AreEqual(test, false);
		}
		TEST_METHOD(Extract)
		{
			int V = 9;
			int cost = 15;
			MinHeap* save = createMinHeap(V);
			for (int i = 0; i < 5; i++) {
				save->array[i] = newMinHeapNode(i, i + 1);
				save->size++;
			}

			MinHeapNode* test = extractMin(save);
			Assert::AreEqual(test->v, 0);
			Assert::AreEqual(test->cost, 1);
		}
		TEST_METHOD(decrease)
		{
			int V = 9;
			int cost = 15;
			MinHeap* save = createMinHeap(V);
			for (int i = 0; i < 5; i++) {
				save->array[i] = newMinHeapNode(i, i + 1);
				save->pos[i] = i;
				save->size++;
			}
			decreaseKey(save, 1, 2);
			Assert::AreEqual(save->array[0]->v, 0);
			Assert::AreEqual(save->array[0]->cost, 1);
		}
		TEST_METHOD(ismin)
		{
			int V = 9;
			int cost = 15;
			MinHeap* save = createMinHeap(V);
			for (int i = 0; i < 5; i++) {
				save->array[i] = newMinHeapNode(i, i + 1);
				save->pos[i] = i;
				save->size++;
			}
			bool test = isInMinHeap(save, 1);
			Assert::AreEqual(test, true);
		}

		TEST_METHOD(finding_test)
		{
			string test[5];
			test[0] = "zero";
			test[1] = "one";
			test[2] = "two";
			test[3] = "three";
			test[4] = "four";
			//	test[5] = "five";
			string testing = finding(1, test);
			Assert::AreEqual(testing, (string)"one");
		}

		TEST_METHOD(checking_test)
		{
			string test[5];
			test[0] = "zero";
			test[1] = "one";
			test[2] = "two";
			test[3] = "three";
			test[4] = "four";
			//	test[5] = "five";
			bool testing = checking(test, test[1]);
			Assert::AreEqual(testing, false);
		}
		TEST_METHOD(count_test)
		{
			int test = count();
			Assert::AreEqual(5, test);
		}
		TEST_METHOD(checking3_test)
		{
			string test[5];
			test[0] = "zero";
			test[1] = "one";
			test[2] = "two";
			test[3] = "three";
			test[4] = "four";
			//	test[5] = "five";
			bool testing = checking3(test, test[1]);
			Assert::AreEqual(testing, true);
		}
		TEST_METHOD(checking2_test)
		{
			string test[5];
			test[0] = "zero";
			test[1] = "one";
			test[2] = "two";
			test[3] = "three";
			test[4] = "four";
			//	test[5] = "five";
			int testing = checking2(test, "one");
			Assert::AreEqual(1, testing);
		}

	};
}
