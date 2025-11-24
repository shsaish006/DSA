class MyCircularDeque {
    vector<int> a;
    int n, curr, s, o;
public:
    MyCircularDeque(int k) {
        n = k;
        a.assign(n, 0);
        curr = 0;
        s = 0;
        o = n - 1;
    }
    
    bool insertFront(int val) {
        if(curr == n) return false;
        s = (s - 1 + n) % n;
        a[s] = val;
        curr++;
        return true;
    }
    
    bool insertLast(int val) {
        if(curr == n) return false;
        o = (o + 1) % n;
        a[o] = val;
        curr++;
        return true;
    }
    
    bool deleteFront() {
        if(curr == 0) return false;
        s = (s + 1) % n;
        curr--;
        return true;
    }
    
    bool deleteLast() {
        if(curr == 0) return false;
        o = (o - 1 + n) % n;
        curr--;
        return true;
    }
    
    int getFront() {
        if(curr == 0) return -1;
        return a[s];
    }
    
    int getRear() {
        if(curr == 0) return -1;
        return a[o];
    }
    
    bool isEmpty() {
        return curr == 0;
    }
    
    bool isFull() {
        return curr == n;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */