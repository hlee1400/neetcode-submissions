class DynamicArray {
public:

    
    DynamicArray(int capacity)
    {
        this->currentSize = 0;
        this->maxSize = capacity;
        this->arr = new int[capacity];
    }

    ~DynamicArray()
    {
        delete[] arr;
    }


    int get(int _i) {
        for( int i = 0; i < currentSize; i++)
        {
            if(i == _i)
            {
                return arr[i];
            }
        }
        return -1;
    }

    void set(int _i, int n) {
        for(int i = 0; i < currentSize; i++)
        {
            if(i == _i)
            {
                arr[i] = n;
            }
        }
    }

    void pushback(int n) {
        if(currentSize == maxSize)
        {
            resize();
        }
        //just add to end
        arr[currentSize] = n;
        currentSize += 1;
    }

    int popback() {
        //show the last index element
        //then delete it
        //update currentSize

        int val = arr[currentSize - 1];
        this->currentSize -= 1;

        return val;

    }

    void resize() {
        int newMaxSize = maxSize * 2;
        int* newArr = new int[newMaxSize];

        //copy elements
        for(int i = 0; i < currentSize; i++)
        {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        maxSize = newMaxSize;
    }

    int getSize() {
        return this->currentSize;
    }

    int getCapacity() {
        return this->maxSize;
    }

    private:
        long currentSize;
        long maxSize;
        int* arr;
};
