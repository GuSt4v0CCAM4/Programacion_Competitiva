#include "iostream"

using namespace std;
void aux(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int particion(int arr[],int low, int high){
    int pivote = arr[high];
    int i = low -1;
    for(int j = low; j < high; j++){
        if (arr[j] <= pivote){
            i++;
            aux(arr, i, j);
        }
    }
    aux(arr, i+1, high);
    return i+1;
}
void quicksort(int arr[], int low, int high){
    if(low < high){
        int index = particion(arr, low, high);
        quicksort(arr, low, index-1);
        quicksort(arr, index+1, high);
    }
}
void mod(int arr[], int n){

}
int main(){
    int n, m;
    cin>>n>>m;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        arr[i] = arr[i] % m;
    }
    quicksort(arr, 0, n - 1);


    return 0;
}