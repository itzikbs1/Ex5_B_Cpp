// #include <iostream>
// #include <stdlib.h>
// #include <string>
// #include <OrgChart.hpp>

// using namespace std;
// using namespace ariel;

// OrgChart::OrgChart(){

// }
// OrgChart OrgChart::add_root(string root_name){
//     return *this;
// }
// OrgChart OrgChart::add_sub(string str1, string str2){
//     return *this;
// }
// vector<string>::iterator OrgChart::begin_level_order(){
//     vector<string>::iterator vec;
//     return vec;
// }
// vector<string>::iterator OrgChart::end_level_order(){
//     vector<string>::iterator vec;
//     return vec;
// }

// vector<string>::iterator OrgChart::begin_reverse_order(){
//     vector<string>::iterator vec;
//     return vec;
// }
// vector<string>::iterator OrgChart::reverse_order(){
//     vector<string>::iterator vec;
//     return vec;
// }
// vector<string>::iterator OrgChart::begin_preorder(){
//     vector<string>::iterator vec;
//     return vec;
// }
// vector<string>::iterator OrgChart::end_preorder(){
//     vector<string>::iterator vec;
//     return vec;
// }

// ostream& operator<<(ostream& os,const OrgChart &org){
//     return os;
// }


// #include <iostream>
// #include <stdlib.h>
// #include <string>
// #include <vector>
// // #include "Node.hpp"
// #include <bits/stdc++.h>
// #include <stack>
// // #include <fstream>
// // #include <sstream>
// // #include <stdexcept>

// using namespace std;
// namespace ariel{

//     enum iter_type{LEVEL_ORDER, REVERSE_LEVEL_ORDER, PREORDER};
//     template <class T>
//     class Node{

//     public:
//         T _obj;
//         vector<Node<T>*> sub_node;
//         Node(T obj) : _obj(obj), sub_node(NULL){}
//         Node(T obj, vector<Node<T>*> sub) : _obj(obj), sub_node(sub){}         
//     };
//     template <class T>
//     class OrgChart{

//     private:
//         Node<T> *_root;

//     class Iterator{
//         private:
//             vector<Node<T>*> order_nodes;
//             uint curr_indx;
//             // change_root(string root_name){
//             //     Node<T>* root = iter_nodes.at(0);
//             //     _root = new Node<T>(root_name);
//             //     _root
//             // }
//         public:
//             void level_order(Node<T> *root){
//                 if(root == NULL){
//                     return;
//                 }else{
//                     queue<Node<T>*> queue_c;
//                     queue_c.push(root);
//                     int size;
//                     while(!queue_c.empty()){
//                         size=queue_c.size();
//                         while(size>0){
//                             Node<T> *node = queue_c.front();
//                             order_nodes.push_back(queue_c.pop());
//                             for (size_t i = 0; i < size; i++)
//                             {
//                                 order_nodes.push_back(node->sub_node.at(i));
//                             }
//                         size--;
//                         }
//                     }
//                 // order_nodes.push_back(root);
//                 // level_order(root->sub_node);
//                 // level_order_sub(root->sub_node, root->sub_node.size());
//                 }
//             }
//             // void level_order_sub(vector<Node<T>*>sub, int size){
//             //     queue<Node<T>*> queue_c;
//             // }
//             void reverse_level_order(Node<T> *root){
//                 if(root == NULL){
//                     return;
//                 }else{
//                     order_nodes.clear();
//                     level_order(root);
//                     stack<T> s;
//                     for (size_t i = 0; i < order_nodes.size(); i++)
//                     {
//                         s.push(order_nodes[i]);
//                     }
//                     order_nodes.clear();
//                     for (size_t i = 0; i < s.size(); i++)
//                     {
//                         order_nodes.push_back(s.pop());
//                         //  order_nodes.push_back(s.top());
//                         // s.pop();
//                     }
//                 }
//                 // level_order(root);
//                 // vector<Node<T>*> reverse_order;
//                 // for (auto i = order_nodes.size()-1; i >= 0; i--)
//                 // {
//                 //     reverse_order.push_back(i);
//                 // }
//                 // order_nodes = reverse_order;
//             }
//             void preorder(Node<T> *root){
//                 if(root == NULL){
//                     return;
//                 }else{
//                     stack<T> stack;
//                     stack.push(root);
//                     while(!stack.empty()){
//                         Node<T> *temp = stack.top();
//                         order_nodes.push_back(stack.pop());
//                         for (int i = temp->sub_node.size() ; i >= 0; i--)
//                         {
//                             stack.push(temp->sub_node[i]);
//                         }
//                     }
//                 }
//             }
//             Iterator(Node<T> *node, T order) : curr_indx(0){
//                 if(order == LEVEL_ORDER && node != nullptr){
//                     level_order(node);
//                 }else if(order == REVERSE_LEVEL_ORDER && node != nullptr){
//                     reverse_level_order(node);
//                 }else{
//                     if(node != nullptr){
//                     preorder(node);
//                     }
//                 }
//             }
//             Iterator& operator++(){
//                 this->curr_indx++;
//                 return *this;
//             }
//             Iterator& operator++(int n){
//                 Iterator iter = *this;
//                 this->curr_indx++;
//                 return iter;
//             }
//             bool operator==(const Iterator& other) const{
//                 return this->order_nodes[this->curr_indx] == other.order_nodes[other.curr_indx];
//             }
//             bool operator!=(const Iterator& other) const{
//                 return !(*this==other)
//             }
//             T& operator*(){
//                 return this->order_nodes[this->curr_indx]->_obj;
//             }
//             T* operator->(){
//                 return &(order_nodes[curr_indx]->_obj);
//             }
//     };
//     public:
//         OrgChart();
//         OrgChart& add_root(const T& root_name);
//         OrgChart& add_sub(const T& n1, const T& n2);
//         vector<string>::iterator begin();
//         vector<string>::iterator end();
//         vector<string>::iterator begin_level_order();
//         vector<string>::iterator end_level_order();
//         vector<string>::iterator begin_reverse_order();
//         vector<string>::iterator reverse_order();
//         vector<string>::iterator begin_preorder();
//         vector<string>::iterator end_preorder();

//         friend std::ostream& operator<<(ostream& os,const OrgChart &org);
//         OrgChart(){

//         }
//         OrgChart& OrgChart::add_root(const T& root_name){

//         }
//         OrgChart& OrgChart::add_sub(const T& n1, const T& n2);
//         vector<string>::iterator begin();
//         vector<string>::iterator end();
//         vector<string>::iterator begin_level_order();
//         vector<string>::iterator end_level_order();
//         vector<string>::iterator begin_reverse_order();
//         vector<string>::iterator reverse_order();
//         vector<string>::iterator begin_preorder();
//         vector<string>::iterator end_preorder();
//         friend ostream& operator<<(ostream& os,const OrgChart &org){
//         return os;
//         }
// };
// }
