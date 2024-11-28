#include <iostream>
#include <string>
using namespace std;

class bst;
class node{
  private:
    node *l, *r;
    int valnumir, valenter;
  public:
    node(int, int);
    void addNode(int, int);
    long int translate(int);
};
node::node(int n, int e){
  l=r=0;
  valenter=e;
  valnumir=n;
}
void node::addNode(int n, int e){
  if (valnumir != n){
    if (valnumir>n){
      if (l != 0){
        l->addNode(n,e);
      }
      else{
        l = new node(n,e);
      }
    }
    else{
      if (r != 0){
        r->addNode(n,e);
      }
      else{
        r = new node(n,e);
      }
    }
  }
}
long int node::translate(int x){
  if (valnumir==x){
    return valenter;
  }
  else{
    if (valnumir>x){
      if (l != 0){
        return l->translate(x);
      }
      else{
        return -9999999999999;
      }
    }
    else{
      if (r != 0){
        return r->translate(x);
      }
      else{
        return -9999999999999;
      }
    }
  }
}


class bst{
  private:
    node *root;
  public:
    bst();
    void addNodeT(int,int);
    string translateT(int);
};

bst::bst(){
  root=0;
}

void bst::addNodeT(int n, int e){
  if(root!=0){
    root->addNode(n,e);
  }
  else{
    root=new node(n,e);
  }
}
string bst::translateT(int x){
  long int res;
  string transl;
  res=root->translate(x);
  if (res==-9999999999999){
    transl="C?";
  }
  else{
    transl=to_string(res);
  }
  return transl;
}

int main() {
  int d,w,n,e,x;
  string res;
  cin >> d;
  cin >> w;
  bst diccionario;
  for (int i=0; i<d; i++){
    cin >>n;
    cin >>e;
    diccionario.addNodeT(n,e);
  }
  for (int j=0; j<w;j++){
    cin >> x;
    res=diccionario.translateT(x);
    cout << res << endl;
  }
}