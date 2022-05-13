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

#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
// #include "Node.hpp"
#include <bits/stdc++.h>
#include <stack>
// #include <fstream>
// #include <sstream>
// #include <stdexcept>

using namespace std;
namespace ariel{

    
    // enum string_type{"LEVEL_ORDER", "REVERSE_LEVEL_ORDER", "PREORDER"};
    // template <class T>
    class Node{

    public:
        string _name;
        vector<Node*> sub_node;
        Node(string name) : _name(name), sub_node(0){}
        Node(string name, vector<Node*> sub) : _name(name), sub_node(sub){}         
    };
    // std::cout<<"205";
    // printf("%s","25");
    // vector<Node*> order_nodes_general;
    // template <class T>
    class OrgChart{
    
    // private:
    //     Node* _root;

    class Iterator{
        private:
            vector<Node*> order_nodes;
            uint curr_indx;
            // change_root(string root_name){
            //     Node<T>* root = iter_nodes.at(0);
            //     _root = new Node<T>(root_name);
            //     _root
            // }
        public:
            void level_order(Node *root){
                // Iterator iter;
                // iter.
                // cout<<"root "<<root->_name<<endl;
                order_nodes.clear();
                if(root == nullptr){
                    // cout<<"229"<<endl;
                    return;
                }else{
                    // order_nodes_general.clear();
                    queue<Node*> queue_c;
                    queue_c.push(root);
                    int size;
                    while(!queue_c.empty()){
                        size=queue_c.size();
                        // cout<<"level order: size "<<size<<endl;
                        while(size>0){
                            Node *node_p = queue_c.front();
                            // cout<<"level order: node_p "<<node_p->_name<<endl;
                            order_nodes.push_back(node_p);
                            //// order_nodes.push_back(node_p);
                            queue_c.pop();
                            for (size_t i = 0; i < node_p->sub_node.size(); i++)
                            {
                                // if(node_p->sub_node.size() > 0){
                                // cout<<"level order: node_p->sub_node.at(i) "<<node_p->sub_node.at(i)->_name<<endl;
                                // order_nodes.push_back(node_p->sub_node.at(i));
                                queue_c.push(node_p->sub_node.at(i));
                                // }
                            }
                        // cout<<"level order: 253"<<endl;
                        size--;
                        }
                        // cout<<"level order: queue_c.size(); "<<queue_c.size()<<endl;
                    }
                    // cout<<"259"<<endl;
                // order_nodes.push_back(root);
                // level_order(root->sub_node);
                // level_order_sub(root->sub_node, root->sub_node.size());
                }
                // order_nodes_general = order_nodes;
            }
            // void level_order_sub(vector<Node<T>*>sub, int size){
            //     queue<Node<T>*> queue_c;
            // }
            // void reverse_level_order(Node *root){
            //     if(root == nullptr){
            //         return;
            //     }else{
            //         // order_nodes_general.clear();
            //         order_nodes.clear();
            //         level_order(root);
            //         stack<Node*> s;
            //         for (size_t i = 0; i < order_nodes.size(); i++)
            //         {
            //             // s.push(order_nodes[i]);
            //             cout<<"order_nodes[i] "<<order_nodes[i]->_name<<endl;
            //             s.push(order_nodes[i]);
            //         }
            //         order_nodes.clear();
            //         for (size_t i = 0; i < s.size(); i++)
            //         {
            //             // order_nodes.push_back(s.pop());
            //             order_nodes.push_back(s.top());
            //             s.pop();
            //         }
            //     }

            void reverse_level_order(Node *root){
                order_nodes.clear();
                if(root == nullptr){
                    // cout<<"229"<<endl;
                    return;
                }else{
                    // order_nodes_general.clear();
                    // cout<<"299"<<endl;
                    stack<Node*> s;
                    // stack<Node*> stack_temp;
                    queue<Node*> queue;
                    s.push(root);
                    // stack_temp.push(root);
                    queue.push(root);
                    int size;
                    while(!queue.empty()){
                        size=queue.size();
                        // cout<<"reverse level order: size "<<size<<endl;
                        while(size>0){
                            Node *node_p = queue.front();
                            // cout<<"reverse level order: node_p "<<node_p->_name<<endl;
                            order_nodes.push_back(node_p);
                            //// order_nodes.push_back(node_p);
                            // queue_c.pop();
                            // stack.pop();
                            queue.pop();
                            for (int i = node_p->sub_node.size()-1; i >= 0; i--)
                            {
                                // if(node_p->sub_node.size() > 0){
                                //     cout<<"i "<<i<<endl;
                                // cout<<"reverse level order: node_p->sub_node.at(i) "<<node_p->sub_node.at(size_t(i))->_name<<endl;
                                // order_nodes.push_back(node_p->sub_node.at(i));
                                s.push(node_p->sub_node.at(size_t(i)));
                                queue.push(node_p->sub_node.at(size_t(i)));
                                // }
                            }
                        // cout<<"level order: 253"<<endl;
                        size--;
                        }
                        // cout<<"level order: queue_c.size(); "<<queue_c.size()<<endl;
                    }
                    order_nodes.clear();
                    // cout<<"s.size! "<<s.size() <<endl;
                    int size_s = s.size();
                    for (size_t i = 0; i < size_s; i++)
                    {
                        // cout<<"s.size "<<s.size() <<endl;
                        // cout<<"s.top "<<s.top()->_name<<endl;
                        order_nodes.push_back(s.top());
                        s.pop();
                    }
                    
                    // order_nodes.clear();

                // order_nodes_general = order_nodes;
                // level_order(root);
                // vector<Node<T>*> reverse_order;
                // for (auto i = order_nodes.size()-1; i >= 0; i--)
                // {
                //     reverse_order.push_back(i);
                // }
                // order_nodes = reverse_order;
            }
            }
            void preorder(Node *root){
                if(root == nullptr){
                    return;
                }else{
                    // order_nodes_general.clear();
                    stack<Node*> stack;
                    stack.push(root);
                    while(!stack.empty()){
                        Node *temp = stack.top();
                        order_nodes.push_back(temp);
                        stack.pop();
                        for (int i = temp->sub_node.size()-1; i >= 0; i--)
                        {
                            stack.push(temp->sub_node.at(size_t(i)));
                        }
                    }
                }
                // order_nodes_general = order_nodes;
            }
            Iterator(Node *node, string order) : curr_indx(0){
                if(order == "level_order" && node != nullptr){
                    level_order(node);
                }else if(order == "reverse_level_order" && node != nullptr){
                    reverse_level_order(node);
                }else{
                    if(node != nullptr){
                        preorder(node);
                    }
                }
                order_nodes.push_back(nullptr);
            }
            Iterator() : curr_indx(0){}

            Iterator& operator++(){
                this->curr_indx++;
                return *this;
            }
            Iterator& operator++(int n){
                Iterator& iter = *this;
                this->curr_indx++;
                return iter;
            }
            bool operator==(const Iterator& other) const{
                return this->order_nodes[this->curr_indx] == other.order_nodes[other.curr_indx];
            }
            bool operator!=(const Iterator& other) const{
                return !((*this) == other);
            }
            string& operator*(){
                return this->order_nodes[this->curr_indx]->_name;
            }
            string* operator->(){
                return &(order_nodes[curr_indx]->_name);
            }
            vector<Node*> get_order_nodes(){
                return order_nodes;
            }
            uint get_curr_indx(){
                return curr_indx;
            }
            void set_curr_indx(uint current){
                this->curr_indx = current;
            }
    };
    private:
        Node* _root;
        Iterator iter;
    public:
        OrgChart(){
            this->_root = nullptr;
            this->iter = Iterator();
        }
        ~OrgChart(){
            delete _root;
        }
        OrgChart& add_root(const string root_name){
            if(this->_root == nullptr){
                this->_root = create_new_node(root_name);
                // this->_root->sub_node = {};
            }else{
                this->_root->_name = root_name;
            }
            return *this;
        }
        Node* create_new_node(const string n){
            Node *temp = new Node{n};
            return temp;
        }
        OrgChart& add_sub(const string n1, const string n2){
            if(this->_root == nullptr){
                throw runtime_error(n1 + "dosen`t find in this Org");
            }
            if(_root->_name == n1){
                Node *new_node = create_new_node(n2);
                // cout<<"!"<<endl;
                _root->sub_node.push_back(new_node);
            }
            else if(!in_sub_childs(n1)){
                // cout<<"371"<<endl;
                throw runtime_error(n1 + "dosen`t find in this Org");
            }else{
                // cout<<"380! "<<endl;
                Node *new_node = create_new_node(n2);
                // if(_root->_name == n1){
                //     cout<<"!"<<endl;
                //     _root->sub_node.push_back(new_node);
                // }
                // else{
                // Iterator iter;
                vector<Node*> vec_child = iter.get_order_nodes();
                // cout<<"vec_child size "<<vec_child.size()<<endl;
                for (size_t i = 0; i < vec_child.size(); i++)
                {
                    // cout<<"vec_child[i] "<<vec_child[i]->_name<<endl;
                    if(vec_child[i]->_name == n1){
                        // cout<<"405"<<endl;
                        vec_child[i]->sub_node.push_back(new_node);
                        break;
                    }
                }
            // }
        }
            return *this;
        }
        bool in_sub_childs(const string n){
            // OrgChart::Iterator::level_order(this->_root);
            
            
            // Iterator(this->_root,"");
            // cout<<"388"<<endl;
            // Iterator iter;
            // cout<<"300"<<endl;
            iter.level_order(this->_root);
            // iter.preorder(this->_root);
            // cout<<"394"<<endl;
            vector<Node*> vec = iter.get_order_nodes();
            // cout<<vec<<endl;
            for (size_t i = 0; i < vec.size(); i++)
            {
                // cout<<"in sub child: vec["<<i<<"]"<<vec[i]->_name<<endl;
            }
            
            // cout<<"395"<<endl;
            // cout<<"vec.size!! "<<vec.size()<<endl;
            for (size_t i = 0; i < vec.size(); i++)
            {
                // cout<<"i: "<<i<<endl;
                // cout<<"vec[i]->_namee "<<vec[i]->_name<<endl;
                if(vec[i]->_name == n){
                    // cout<<"return true"<<endl;
                    return true;
                }
            }
            return false;
            // for (size_t i = 0; i < sub_child.size(); i++)
            // {
            //     if(sub_child[i]->_name == n){
            //         return true;
            //     }
            // }
            // return false;
            
        }
        Iterator begin(){
            // vector<string>::iterator vec;
            // iter.
            // for (size_t i = 0; i < _root->sub_node.size(); i++)
            // {
            //     vec.push_back(_root->sub_node[i]->_name);
            // }
            return begin_level_order();
        }
        Iterator end(){
            // vector<string>::iterator vec;
            // return vec;
            return end_level_order();
        }
        Iterator begin_level_order(){
            // vector<string>::iterator vec;
            // return vec;
            return Iterator(this->_root, "level_order");
        }
        Iterator end_level_order(){
            // vector<string>::iterator vec;
            // return vec;
            return Iterator(nullptr, "level_order");
        }
        Iterator begin_reverse_order(){
            // vector<string>::iterator vec;
            // return vec;
            return Iterator(this->_root, "reverse_level_order");
        }
        Iterator reverse_order(){
            // vector<string>::iterator vec;
            // return vec;
            return Iterator(nullptr, "reverse_level_order");

        }
        Iterator begin_preorder(){
            // vector<string>::iterator vec;
            // return vec;
            return Iterator(this->_root, "");
            // return iter;
        }
        Iterator end_preorder(){
            // vector<string>::iterator vec;
            // return vec;
            return Iterator(nullptr, "");
            // return iter;
        }

        friend std::ostream& operator<<(ostream& os,const OrgChart &org){
            os << org._root->_name<<endl;
            for (size_t i = 0; i < org._root->sub_node.size(); i++)
            {
                if(org._root->sub_node.size() - i> 0){
                    os<< org._root->sub_node[i]->_name<<endl;
                    if(!org._root->sub_node[i]->sub_node.empty()){
                        for (size_t j = 0; j < org._root->sub_node[i]->sub_node.size(); j++)
                        {
                            os << org._root->sub_node[i]->sub_node[j]->_name<<endl;
                        }
                    }
                }
            }
            return os;
        }
        // friend std::ostream& operator<<(ostream& os,const vector<Node*> vec){
        //     // os << org.<<endl;
        //     for (size_t i = 0; i < vec.size(); i++)
        //     {
        //         os << vec.at(i)<<endl;
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