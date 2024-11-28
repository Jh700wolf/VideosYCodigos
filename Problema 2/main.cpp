#include <iostream>
#include <string>

using namespace std;
class list;

class Node{
    private:
        Node *next;
        char Valor;
    public: 
        Node(char);

    friend class list;
};
Node::Node(char s){
    next = 0;
    Valor=s;
}
class list{
    private:
        Node *head;
    public:
        list();
        int verificarLetra(char);

};
list::list(){
    head=0;
}
int list::verificarLetra(char res){
    Node* p=head;
    while(p!=0){
        if (p->Valor==res){
            return 1;
        }
        p=p->next;
    }
    Node *newNode = new Node(res);
    if (head == 0){
        head=newNode;
        return 2;
    }
    p = head;
    while (p -> next != 0){
        p = p->next;
    }
    newNode -> next = 0;
    p -> next = newNode;
    return 2;

}
int main(){
    int t, n, res;
    string s;
    
    cin >> t;
    for(int i=0;i<t;i++){
        res=0;
        cin >> n;
        cin >> s;
        list l;
        for (int j=0; j<n;j++){
            res+=l.verificarLetra(s[j]);
        }
        cout << res << endl;
        
    }
}