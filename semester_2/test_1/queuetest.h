#pragma once
#include "QObject"
#include "QtTest/QTest"
#include "priorityqueue.h"
#include "iostream"


class QueueTest : public QObject
{
	Q_OBJECT
	public:
		explicit QueueTest(QObject* parent = 0) : QObject(parent) {}
	private slots:

		void init()
		{
			queue = new PriorityQueue <int>;
		}

		void cleanup()
		{
			delete queue;
		}

		void testEnqueue()
		{
			queue->enqueue(10, 1);
			QVERIFY(queue->getSize() == 1);
		}

		void testDequeue()
		{
			queue->enqueue(10, 1);
			QVERIFY(queue->dequeue() == 10);
		}

		void testEmptyCheck()
		{
			try
			{
				queue->dequeue();
			}
			catch(QueueError)
			{
				std::cout << "queue is empty" << std::endl;
			}
		}

		void testEnqueueSort() /// test will tell us, does elements sort correctly
		{
			queue->enqueue(10, 1);
			queue->enqueue(1, 2);
			QVERIFY(queue->dequeue() == 1);
		}

		void testIsEmpty()
		{
			QVERIFY(queue->getSize() == 0);
		}

		void testDequeue2() /// test will tell us, does elements delete correctly
		{
			queue->enqueue(10, 1);
			queue->enqueue(1, 2);
			QVERIFY(queue->dequeue() == 1);
			QVERIFY(queue->dequeue() == 10);
		}

		void testFull()
		{
			queue->enqueue(10, 1);
			queue->enqueue(1, 2);
			queue->enqueue(2, 5);
			queue->enqueue(8, 4);
			QVERIFY(queue->getSize() == 4);
			QVERIFY(queue->dequeue() == 2);
			QVERIFY(queue->getSize() == 3);
			QVERIFY(queue->dequeue() == 8);
			QVERIFY(queue->dequeue() == 1);
			QVERIFY(queue->dequeue() == 10);
		}

	private:
		PriorityQueue <int> *queue;

};
