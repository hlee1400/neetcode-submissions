class LinkedList {
public:
    LinkedList() 
    {
        
        head = nullptr;
        tail = nullptr;
    }

    int get(int index) {
        //Move step-by-step:
        //for each step:
        //if current == nullptr → return -1
        Node* current = head;

        for ( int i = 0; i < index; i++)
        {
            if(current == nullptr)
        {
            return -1;
        }
            
            current = current->next;
        }
        if(current == nullptr)
        {
            return -1;
        }

        return current->val;


    }

    void insertHead(int val) {
        
        if(head == nullptr)
        {
            Node* newNode = new Node;
            newNode->val = val;
            newNode->next = nullptr;
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {   
            Node* newNode = new Node;
            newNode->val = val;

            newNode->next = head;   
            this->head = newNode;
        }
        
    }
    
    void insertTail(int val) {
        Node* newNode = new Node;
        newNode->val = val;
        
        //If empty → head = tail = newNode
        if(this->head == nullptr)
        {
            newNode->next = nullptr;
            this->head = newNode;
            this->tail = newNode;
        }
        //Else → normal append
        else
        {
            newNode->next = nullptr;       
            this->tail->next = newNode;
            this->tail = newNode;
        
        }
    }

    bool remove(int index) {

        Node* current = head;

        //empty list
        if(this->head == nullptr)
        {
            return false;
        }

        //case 1: remove head
        if(index == 0)
        {
            Node* current = head;
            head = head->next;

            //if list becomes empty
            if(this->head == nullptr)
            {
                this->tail = nullptr;
            }

            delete current;
            return true;
        }


        //case 2: remove middle node
        
        for( int i = 0; i < index - 1; i++)
        {
            if(current == nullptr || current -> next == nullptr)
            {
                return false;
            }
            current = current->next;
        }
        //at target
        Node* targetNode = current->next;
        if(targetNode == nullptr)
        {
            return false;
        }
        current->next = targetNode->next;

        //case 3: if removing tail
        if(targetNode == tail)
        {
            tail = current;
        }
        
        delete targetNode;
        return true;
    }



    vector<int> getValues() {
        vector<int> result;
        Node* current = head;
        while(current != nullptr)
        {
            result.push_back(current->val);
            current = current->next;
        }
        return result;
    }

    private:
    struct Node
    {
        int val;
        Node* next;
    };

    Node* head;
    Node* tail;

    
     
};
