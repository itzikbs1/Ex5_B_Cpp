#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <stack>

using namespace std;
namespace ariel{

    
    // enum string_type{"LEVEL_ORDER", "REVERSE_LEVEL_ORDER", "PREORDER"};
    // template <class T>

    /*
        the class of th organization, private variable: Node* root 
    */
class OrgChart{
    
    
    /*
        create Node class with name(string) and vector of is "child".
    */
    struct Node{

    public:
        string _name;
        vector<Node*> sub_node;
        Node(string name) : _name(move(name)), sub_node(0){}
        Node(string name, vector<Node*> sub) : _name(move(name)), sub_node(move(sub)){}         
    };

    class Iterator{
        private:
            vector<Node*> order_nodes;
            uint curr_indx;
        public:
        void level_order(Node *root);
        void reverse_level_order(Node *root);
        void preorder(Node *root);
        Iterator(Node *node, const string &order);
        Iterator();
        Iterator& operator++();
        Iterator& operator++(int n);
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        string& operator*();
        string* operator->();
        vector<Node*> get_order_nodes();
        uint get_curr_indx() const;
        void set_curr_indx(uint current);
        void set_order_nodes(Node* &node, size_t temp);
        //Constructor of Iterator
        // Iterator(Node *node, const string &order) {//}: OrgChart::Iterator::set_curr_indx(0) set_curr_indx(0){
        //     this->set_curr_indx(0);
        //     // this->order_nodes.clear();
        //     if(order == "level_order" && node != nullptr){
        //         level_order(node);
        //     }else if(order == "reverse_level_order" && node != nullptr){
        //         reverse_level_order(node);
        //     }else{
        //         if(node != nullptr){
        //             preorder(node);
        //         }
        //     }
        //     this->order_nodes.push_back(nullptr);
        // }
            //scan the organization with level order method print from up to down step by step.
            // void level_order(Node *root){
            //     if(root == nullptr){
            //         return;
            //     }else{
            //         order_nodes.clear();
            //         queue<Node*> queue_c;
            //         queue_c.push(root);
            //         int size=0;
            //         while(!queue_c.empty()){
            //             size=queue_c.size();
            //             while(size>0){
            //                 Node *node_p = queue_c.front();
            //                 order_nodes.push_back(node_p);
            //                 queue_c.pop();
            //                 for (size_t i = 0; i < node_p->sub_node.size(); i++)
            //                 {
            //                     queue_c.push(node_p->sub_node.at(i));
            //                 }
            //             size--;
            //             }
            //         }
            //     }
            // }
            // //scan the organization with reverse level order method print From the bottom up and from right to left.
            // void reverse_level_order(Node *root){
            //     if(root == nullptr){
            //         return;
            //     }else{
            //         order_nodes.clear();
            //         stack<Node*> s;
            //         queue<Node*> queue;
            //         s.push(root);
            //         queue.push(root);
            //         int size=0;
            //         while(!queue.empty()){
            //             size=queue.size();
            //             while(size>0){
            //                 Node *node_p = queue.front();
            //                 queue.pop();
            //                 for (int i = int(node_p->sub_node.size()-1); i >= 0; i--)
            //                 {
            //                     s.push(node_p->sub_node.at(size_t(i)));
            //                     queue.push(node_p->sub_node.at(size_t(i)));
            //                 }
            //             size--;
            //             }
            //         }
            //         int size_s = s.size();
            //         for (size_t i = 0; i < size_s; i++)
            //         {
            //             order_nodes.push_back(s.top());
            //             s.pop();
            //         }
            //     }
            // }
            // //scan the organization with level order method print from left to right and from up to down.
            // void preorder(Node *root){
            //     if(root == nullptr){
            //         return;
            //     }else{
            //         order_nodes.clear();
            //         stack<Node*> stack;
            //         stack.push(root);
            //         while(!stack.empty()){
            //             Node *temp = stack.top();
            //             order_nodes.push_back(temp);
            //             stack.pop();
            //             for (int i = int(temp->sub_node.size()-1); i >= 0; i--)
            //             {
            //                 stack.push(temp->sub_node.at(size_t(i)));
            //             }
            //         }
            //     }
            // }
            // //Constructor of Iterator
            // Iterator(Node *node, const string &order) : curr_indx(0){
            //     if(order == "level_order" && node != nullptr){
            //         level_order(node);
            //     }else if(order == "reverse_level_order" && node != nullptr){
            //         reverse_level_order(node);
            //     }else{
            //         if(node != nullptr){
            //             preorder(node);
            //         }
            //     }
            //     order_nodes.push_back(nullptr);
            // }
            // //enpty Constructor
            // Iterator() : curr_indx(0){}

            // //operator++ after the promotion
            // Iterator& operator++(){
            //     this->curr_indx++;
            //     return *this;
            // }
            // //operator++ before the promotion
            // Iterator& operator++(int n){
            //     Iterator& iter = *this;
            //     this->curr_indx++;
            //     return iter;
            // }
            // //operator== check the address of specific node* in the vector
            // bool operator==(const Iterator& other) const{
            //     return this->order_nodes[this->curr_indx] == other.order_nodes[other.curr_indx];
            // }
            // //operator !=
            // bool operator!=(const Iterator& other) const{
            //     return !((*this) == other);
            // }
            // // bool operator!=(const Iterator& other) const{//?????????????????????????????????????????????????????????????
            // //     return !((*this) == other.end_level_order());
            // // }
            // //operator* go one step inside
            // string& operator*(){
            //     return this->order_nodes[this->curr_indx]->_name;
            // }
            // //operator-> take the address of the variable
            // string* operator->(){
            //     return &(order_nodes[curr_indx]->_name);
            // }
            // //getters and setters
            // vector<Node*> get_order_nodes(){
            //     return order_nodes;
            // }
            // uint get_curr_indx() const{
            //     return curr_indx;
            // }
            // void set_curr_indx(uint current){
            //     this->curr_indx = current;
            // }
            // void set_order_nodes(Node* &node, size_t temp){
            //     order_nodes.at(temp)->sub_node.push_back(node);
            // }
    };
    private:
        Node* _root;
    public:
    //default constructor
    OrgChart();
    // OrgChart(const OrgChart &org);
    // ~OrgChart();
    OrgChart& add_root(const string &root_name);
    static Node* create_new_node(const string &n);
    OrgChart& add_sub(const string &n1, const string &n2);
    // bool in_sub_childs(const string &n);
    Node* get_root() const;
    Iterator begin();
    static Iterator end();
    Iterator begin_level_order();
    static Iterator end_level_order();
    Iterator begin_reverse_order();
    static Iterator reverse_order();
    Iterator begin_preorder();
    static Iterator end_preorder();
    friend std::ostream& operator<<(ostream& os,const OrgChart &org);
        // OrgChart(){
        //     this->_root = nullptr;
        // }
        //copy constructor
        // OrgChart(const OrgChart &org) : _root(new Node(org._root->_name, org._root->sub_node)){}
            
        // //distructor    
        // ~OrgChart(){
        //     delete _root;
        // }
        // //check if root is null add to him else rape the old one and create new one
        // OrgChart& add_root(const string &root_name){
        //     if(this->_root == nullptr){
        //         this->_root = create_new_node(root_name);
        //     }else{
        //         this->_root->_name = root_name;
        //     }
        //     return *this;
        // }
        // //create new Node
        // static Node* create_new_node(const string &n){
        //     Node *temp = new Node{n};
        //     return temp;
        // }
        // //add new for the organization if n1 in the org
        // OrgChart& add_sub(const string &n1, const string &n2){
        //     //if the root null than throw exception
        //     if(this->_root == nullptr){
        //         throw runtime_error(n1 + "dosen`t find in this Org");
        //     }
        //     //if we want to crete new one for the root than do it
        //     if(_root->_name == n1){
        //         Node *new_node = create_new_node(n2);
        //         _root->sub_node.push_back(new_node);
        //     }
        //     //if n1 dosent find in the org than throw exception
        //     else if(!in_sub_childs(n1)){
        //         throw runtime_error(n1 + "dosen`t find in this Org");

        //     //if is find in the org search him and and put n2 in the right place    
        //     }else{
        //         size_t temp=0;
        //         Node *new_node = OrgChart::create_new_node(n2);
        //         for(Iterator iter = this->begin_level_order(); iter != this->end_level_order(); iter++)
        //         {
        //             if((*iter) == n1){
        //                 iter.set_order_nodes(new_node, temp);
        //                 iter.get_order_nodes().clear();
        //                 break;
        //             }
        //             temp++;
        //         }
        //     }
        //     return *this;
        // }
        // //check if n available in the organization
        // bool in_sub_childs(const string &n){
        //     for(Iterator iter = this->begin_level_order(); iter != this->end_level_order(); iter++)
        //     {
        //         if((*iter) == n){
        //             return true;
        //             iter.get_order_nodes().clear();
        //         }
        //     }

        //     return false;
            
        // }
        // //Iterator using the scan
        // Node* get_root() const{
        //     return _root;
        // }

        // Iterator begin(){
        //     return begin_level_order();
        // }
        // static Iterator end(){
        //     return end_level_order();
        // }
        // Iterator begin_level_order(){
        //     return Iterator(this->_root, "level_order");
        // }
        // static Iterator end_level_order(){
        //     return Iterator(nullptr, "level_order");
        // }
        // Iterator begin_reverse_order(){
        //     return Iterator(this->_root, "reverse_level_order");
        // }
        // static Iterator reverse_order(){
        //     return Iterator(nullptr, "reverse_level_order");

        // }
        // Iterator begin_preorder(){
        //     return Iterator(this->_root, "");
        // }
        // static Iterator end_preorder(){
        //     return Iterator(nullptr, "");
        // }
        // // //print the org with some scan
        // friend std::ostream& operator<<(ostream& os,const OrgChart &org){
        //     os << "                "<<org._root->_name<<endl;
        //     os<<endl;
        //     os<<"        |--------|--------|"<<endl;
        //     string space = "       ";
        //     for (size_t i = 0; i < org._root->sub_node.size(); i++)
        //     {
        //         if(org._root->sub_node.size() - i> 0){
        //             os<<space<<org._root->sub_node[i]->_name<<"             "<<endl;
        //             if(!org._root->sub_node[i]->sub_node.empty()){
        //                 for (size_t j = 0; j < org._root->sub_node[i]->sub_node.size(); j++)
        //                 {
        //                     os <<"        |"<<endl;
        //                     os<<"      "<<org._root->sub_node[i]->sub_node[j]->_name<<endl;
        //                 }
        //                 os<<endl;
        //             }
        //         }
        //     }
        //     return os;
        // }
        // //print the org with some scan
        // friend std::ostream& operator<<(ostream& os,const OrgChart &org){
        //     os << "                "<<org._root->_name<<endl;
        //     os<<endl;
        //     os<<"        |--------|--------|"<<endl;
        //     string space = "       ";
        //     for (size_t i = 0; i < org._root->sub_node.size(); i++)
        //     {
        //         if(org._root->sub_node.size() - i> 0){
        //             for (size_t k = 0; k < org._root->sub_node.size(); k++)
        //             {
        //             os<<space<<org._root->sub_node[k]->_name<<"             "<<endl;
        //             if(!org._root->sub_node[i]->sub_node.empty()){
        //                 for (size_t j = 0; j < org._root->sub_node[i]->sub_node.size(); j++)
        //                 {
        //                     os <<"        |"<<endl;
        //                     os<<"      "<<org._root->sub_node[i]->sub_node[j]->_name<<endl;
        //                 }
        //                 os<<endl;
        //             }
        //             }
        //         }
        //     }
        //     return os;
        // }
        // }


        //print the org with some scan
        // friend std::ostream& operator<<(ostream& os,const OrgChart &org){
        //     os << "                "<<org._root->_name<<endl;
        //     os<<endl;
        //     os<<"        |--------|--------|"<<endl;
            // string space = "       ";
            // for (size_t i = 0; i < org._root->sub_node.size(); i++)
            // {
            //     if(org._root->sub_node.size() - i> 0){
            //         os<<space<<org._root->sub_node[i]->_name<<"             "<<endl;
            //         if(!org._root->sub_node[i]->sub_node.empty()){
            //             for (size_t j = 0; j < org._root->sub_node[i]->sub_node.size(); j++)
            //             {
            //                 os <<  "        |"<<endl;
            //                 os<<"  "<<org._root->sub_node[i]->sub_node[j]->_name<<endl;
            //             }
            //             os<<endl;
            //         }
            //     }
            // }
        //     print_orgChart(os, org._root);
        //     return os;
        // }
        // static void print_orgChart(ostream &os, Node *root){
        //     // os << "                "<<root->_name<<endl;
        //     // os<<endl;
        //     // os<<"        |--------|--------|"<<endl;
        //     bool flag = false;
        //     if(flag){
        //         os<<"       |"<<endl;
        //         // os<<""
        //     }
        //     int size = int(root->sub_node.size());
        //     cout<<"size "<<size<<endl;
        //     uint i=0;
        //     uint j=0;
        //     while(size>0){
        //         os<<"       "<<root->sub_node.at(i)->_name;
        //         i++;
        //         size--;
        //     }
        //     flag=true;
        //     os<<endl;
        //     // i=0;
        //     print_orgChart(os, root->sub_node.at(j));
        //     j++;
        // }
        // friend std::ostream& operator<<(ostream& os, OrgChart &org){

        //     // org.iter.level_order(org._root);
        //     // vector<Node*> nodes_order = org.iter.get_order_nodes();
        //     // for (size_t i = 0; i < nodes_order.size(); i++)
        //     // {
        //     //     cout<<nodes_order.at(i)->_name<< "  ";
        //     // }
            
        //     string space = "       ";
        //     string small_space = "     ";
        //     os << "                 "<<org._root->_name<<endl;
        //     os<<endl;
        //     os<<"        |---------|---------|"<<endl;
        //     os<<endl;
        //     // int total_size = nodes_order.size();

        //     int total_size = 0;
        //     size_t k=1;
        //     size_t temp=1;
        //     bool once = false;
        //     while (total_size>=0 && temp < nodes_order.size())
        //     {
        //         if(!once){
        //             for (size_t i = 0; i < org._root->sub_node.size(); i++)
        //             {
        //                 os<<space<<nodes_order.at(temp++)->_name;
        //                 // total_size--;
        //             }
        //         once=true;
        //         os<<endl;
        //         os<<endl<<space<<" |";
        //         os<<space<<space<<"     |"<<endl;
        //         os<<endl;
        //         }
        //         for (size_t i = 1; i < org._root->sub_node.size(); i++)
        //         {
        //             if(total_size <= 0 || temp >= nodes_order.size()){
        //                 break;
        //             }
        //             if(nodes_order.at(k)->_name == org._root->sub_node.at(i-1)->_name){
        //                 for (size_t j = 0; j < org._root->sub_node.at(i-1)->sub_node.size(); j++)
        //                 {
        //                     os<<small_space<<nodes_order.at(temp++)->_name;
        //                     // total_size--;
        //                 }
        //             }
        //             os<<small_space<<" ";
        //         }
        //     }
        //     return os;
        // }
       
        // OrgChart(){

        // }
        // OrgChart& OrgChart::add_root(const string root_name){

        // }
        // OrgChart& OrgChart::add_sub(const string n1, const string n2){

        // }
        // vector<string>::iterator OrgChart::begin(){
        //     return this->_root->sub_node;
        // }
        // vector<string>::iterator OrgChart::end(){
        //     return this->_root->sub_node;
        // }
        // vector<string>::iterator OrgChart::begin_level_order(){
        //     return this->_root->sub_node;
        // }
        // vector<string>::iterator OrgChart::end_level_order(){
        //     return this->_root->sub_node;
        // }
        // vector<string>::iterator OrgChart::begin_reverse_order(){
        //     return this->_root->sub_node;
        // }
        // vector<string>::iterator OrgChart::reverse_order(){
        //     return this->_root->sub_node;
        // }
        // vector<string>::iterator OrgChart::begin_preorder(){
        //     return this->_root->sub_node;
        // }
        // vector<string>::iterator OrgChart::end_preorder(){
        //     return this->_root->sub_node;
        // }
        // friend ostream& operator<<(ostream& os,const OrgChart &org){
        // return os;
        // }
};
}
// }