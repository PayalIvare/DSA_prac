#include <iostream>
using namespace std;

class Heap_op
{
    int maxHeap[10];
    int minHeap[10];
    int n, x;

public:
    void create()
    {
        cout << "Enter the number of students: ";
        cin >> n;
        maxHeap[0] = 0;
        minHeap[0] = 0;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter the mark of student " << i + 1 << ": ";
            cin >> x;
            max_insert(maxHeap, x);
            min_insert(minHeap, x);
        }
    }
    void max_insert(int maxHeap[], int data)
    {
        int t = maxHeap[0];
        maxHeap[t + 1] = data;
        maxHeap[0] = t + 1;
        up_adjust(maxHeap, t + 1);
    }
    void up_adjust(int maxHeap[], int i)
    {
        int temp;
        while (i > 1 && maxHeap[i] > maxHeap[i / 2])
        {
            temp = maxHeap[i];
            maxHeap[i] = maxHeap[i / 2];
            maxHeap[i / 2] = temp;
            i = i / 2;
        }
    }
    void display_max()
    {
        cout << "Highest mark is: " << maxHeap[1] << endl;
        cout << "Max heap tree traversal: ";
        for (int i = 1; i <= maxHeap[0]; i++)
        {
            cout << maxHeap[i] << " ";
        }
        cout << endl;
    }

    void min_insert(int minHeap[], int data)
    {
        int t = minHeap[0];
        minHeap[t + 1] = data;
        minHeap[0] = t + 1;
        down_adjust(minHeap, t + 1);
    }
    void down_adjust(int minHeap[], int i)
    {
        int temp;
        while (i > 1 && minHeap[i] < minHeap[i / 2])
        {
            temp = minHeap[i];
            minHeap[i] = minHeap[i / 2];
            minHeap[i / 2] = temp;
            i = i / 2;
        }
    }
    void display_min()
    {
        cout << "Lowest mark is: " << minHeap[1] << endl;
        cout << "Min heap tree traversal: ";
        for (int i = 1; i <= minHeap[0]; i++)
        {
            cout << minHeap[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Heap_op obj;
    obj.create();
    obj.display_max();
    obj.display_min();
    return 0;
}
