#pragma once
#include <stdexcept>
#include <iostream>
#define N 10
#define NIL -1
class List { 
    struct Node { 
    int value; 
    int next; 
    };
    private:
    Node arr[N]; 
    int head; 
    int tail; 
    int size; 
    int spare; 
    public:
    List(){
        head = NIL;
        tail = NIL;
        size = 0; 
        for(int i=0; i<N-1; i++){  
            arr[i].next = i+1;
        }
        arr[N-1].next = NIL;
        spare = 0;
    }
    ~List(){
        clear();
    }
    int allocate(){
            int temp = spare;
            spare = arr[spare].next;
            return temp;
    }
    void Delete(int cursor){
        arr[cursor].next = spare;
        spare = cursor;
    }
    void push_front(int x){ 
        if(tail == NIL && head == NIL && size ==0){
            tail = spare;
            head = spare; //dopisałam
        }
        int node = allocate();
        if(node == NIL){
            throw std::out_of_range("lista jest pełna");
        }
        arr[node].value = x;
        arr[node].next = head;
        head = node;
        size++;
    } 
    void push_back(int x) {
        if(tail == NIL && head == NIL && size ==0){
            head = spare;
            tail = spare;
        }
        int node = allocate(); 
        if(node == NIL){
            throw std::out_of_range("lista jest pełna");
        }
    
        arr[node].value = x;
        arr[tail].next = node;
        arr[node].next = NIL;
        tail = node;
        size++;
    }
    int pop_back(){ 
        if(size == 0){
        throw std::out_of_range("pusta lista");
        }
        int current = head;
        int previous = NIL;

        while(arr[current].next != NIL){
            previous = current;
            current = arr[current].next;
        }

        if(previous != NIL){
            arr[previous].next = NIL;
            tail = previous; 
        }else{
            head = NIL;
            tail = NIL;
        }
        int info = arr[current].value;
        Delete(current);
        size--;
        return info;
    }
    int pop_front() {
        if (size == 0) {
            throw std::out_of_range("empty list/ pop_front");
        }
        int temp = head; 
        int info = arr[temp].value;
    
        if(arr[temp].next == NIL){
            head = NIL;
            tail = NIL;
        }else{
            head = arr[head].next; 
        }
        Delete(temp);
        size--;
        return info;
    }
    int getSize(){
        return this->size;
    }
    bool empty(){
        return this->size == 0;
    } 
    void clear(){
        while(head != NIL){
            pop_front();
        }
        return;
    } // Czyści listę
    int find(int x){
        if (head == NIL) {
            return -1;
        }
        int current = head;
        int xPosition = 0;
        int pos = 0;
        int flag = NIL;

        for(int j = 1; j <= size; j++) {

            if(arr[current].value == x){
                xPosition = pos;
                flag = 1;
                break;
            }
            current = arr[current].next;
            pos++;
        }
        if(flag == NIL){
            return -1;
        }
        if(xPosition < 0){
            return -1;
        }
        //std::cout << "pozycja x "<< xPosition << std::endl;
        return xPosition;
    } // Zwraca pozycję pierwszego elementu o wartości x
    int erase(int i){ 
        if(i < 0){
            throw std::out_of_range("element nie występuje w tablicy");
        }
        int searchedIndexPosition = i;
        if(searchedIndexPosition > size){
            throw std::out_of_range("podany indeks jest większy niż rozmiar listy");
        }
        int current = head;
        int previous = NIL;
        int valueToErase = NIL;

        for(int j = 0; j < searchedIndexPosition; j++){
            previous = current;
            current = arr[current].next;
        }
        int temp = current;
        if(size < 2){
            Delete(current);
            head = NIL; 
            tail = NIL;
            size--; 
            valueToErase = arr[temp].value;
            return valueToErase;
        }
        if(previous == NIL){
            head = arr[head].next;
        }else{
            arr[previous].next = arr[current].next;
        }
        Delete(current);
        size--;
        valueToErase = arr[temp].value;
            return valueToErase;
    } 
    void insert(int i, int x){
        if (head == NIL && tail == NIL) {
            push_front(x);
            return;
        }
        if(i == 0){ 
            push_front(x);
            return;
        }

        int current = head;
        int searchedIndexPosition = i;

        for(i = 1; i < searchedIndexPosition; i++){
            current = arr[current].next;
        }
        int node = allocate();
        arr[node].value = x; 
        arr[node].next = arr[current].next;
        arr[current].next = node;
        size++;
        return;
    } // Wstawia element `x` przed pozycję `i`
    int remove(int x){
    if (size == 0){
            throw std::out_of_range("no elements to remove");
        }
        int current = head;
        int previous = NIL;
        int xAmount = 0;
        int temp = 0;

        while (arr[current].next != NIL) {
            if(arr[current].value == x){
                if(previous != NIL){
                    arr[previous].next = arr[current].next;    
                    temp = current;               
                }
                if(previous == NIL){
                    head = arr[head].next;
                    temp = current;
                }
                xAmount++;            
            }else{
                previous = current; 
            }     
            current = arr[current].next;    
            Delete(temp); 
        }
        if(arr[current].value == x){
            arr[previous].next = NIL;
            tail=previous;
            xAmount++;
            Delete(current);
        }
        size = size - xAmount;
        if(xAmount == 0){
            throw std::out_of_range("no x-value");
        }
        return xAmount;
    }
    void show(){
        std::cout << "list is printing:" << std::endl;
        if(size == 0){
            throw std::out_of_range("empty list");
        }
        int i = head;
        int s = size;
        while(s > 0){
            std::cout << arr[i].value << "    " << arr[i].next << std::endl;
            s--;
            i = arr[i].next;
        }
    }
};
