class kStacks {

    // main array to store elements
    int *arr;
    int *top;
    int *next;
    
    int n,s;
    
    int freeSpot;

  public:
    kStacks(int n, int s) {
        // initialize data structures for k stacks
        this->n = n;
        this->s = s;
        arr = new int[n];
        top = new int[s];
        next = new int[n];
        
        for(int i=0;i<s;i++){
            top[i]=-1;
        }
        for(int i=0;i<n;i++){
            next[i]=i+1;
        }
        next[n-1] = -1;
        
        freeSpot = 0;
    }

    void push(int x, int i) {
        // push element x into stack i
        
        if(i < 0 || i >= s) return;

        if(freeSpot == -1) return;
        
        int index = freeSpot;
        
        freeSpot = next[index];
        
        arr[index] = x;
        
        next[index] = top[i];
        
        top[i] =index;
    }

    int pop(int i) {
        // pop element from stack i
        if(i < 0 || i >= s) return -1;

        if(top[i] == -1){
            return -1;
        }
        
        int index = top[i];
        
        top[i] = next[index];
        
        next[index] = freeSpot;
        
        freeSpot = index;
        
        return arr[index];
    }
};