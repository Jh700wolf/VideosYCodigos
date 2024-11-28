#include <iostream>
#include <vector>

using namespace std;
void merge(vector<int> &x, vector<int> &y, int low, int mid, int high){
    int i=low, j=mid+1,k=low;
        while (i<=mid && j<= high){
        if(x[i]<x[j]){
            y[k]=x[i];
            i++;
        }
        else{
            y[k]=x[j];
            j++;
        }
        k++;
    }
    if (i>mid){
        for(;j<=high;j++){
            y[k++]=x[j];
        }
    }
    else{
        for(;i<=mid;i++){
            y[k++]=x[i];
        }
    }
}
void pass(vector<int> &x, vector<int> &y, int low, int high){
    for(int i=low;i<=high;i++){
        x[i]=y[i];
    }
}
void split(vector<int> &x, vector<int> &y, int low, int high){
    if((high-low)<1){
        return;
    }
    int mid=(high+low)/2;
    split(x,y,low,mid);
    split(x,y,mid+1,high);
    merge(x,y,low,mid,high);
    pass(x,y,low,high);
}

void Sort(vector<int> &l, int n){
    vector<int> aux(n);
    split(l,aux,0,n-1);
}

int main(){
    int n, k, x=2, cont = 1;
    vector<int> students;
    
    cin >> n >> k;

    while (cont <= n){
        int a;
        cin >> a;
        students.push_back(a);
        cont++;
    }
    if (n<3){
        cout<<0;
        return 0;
    }
    Sort(students,n);
    cont=0;
    while (x+1<=n){
        if(students[x]+k>5){
            break;
        }
        cont+=1;
        x+=3;
    }
    cout << cont;
}