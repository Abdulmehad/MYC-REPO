int getArraySize(int arr[]) {   
    int size = 0;
    
    while (arr[size] != -1) {
        size++;
    }
    return size;
}
