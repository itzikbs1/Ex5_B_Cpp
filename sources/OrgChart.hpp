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
    class Node{

    public:
        string _name;
        vector<Node*> sub_node;
        Node(string name) : _name(name), sub_node(0){}
        Node(string name, vector<Node*> sub) : _name(name), sub_node(sub){}         
    };
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
                if(root == nullptr){
                    return;
                }else{
                    order_nodes.clear();
                    queue<Node*> queue_c;
                    queue_c.push(root);
                    int size;
                    while(!queue_c.empty()){
                        size=queue_c.size();
                        while(size>0){
                            Node *node_p = queue_c.front();
                            order_nodes.push_back(node_p);
                            queue_c.pop();
                            for (size_t i = 0; i < node_p->sub_node.size(); i++)
                            {
                                queue_c.push(node_p->sub_node.at(i));
                            }
                        size--;
                        }
                    }
                }
            }
            void reverse_level_order(Node *root){
                if(root == nullptr){
                    return;
                }else{
                    order_nodes.clear();
                    stack<Node*> s;
                    queue<Node*> queue;
                    s.push(root);
                    queue.push(root);
                    int size;
                    while(!queue.empty()){
                        size=queue.size();
                        while(size>0){
                            Node *node_p = queue.front();
                            order_nodes.push_back(node_p);
                            queue.pop();
                            for (int i = node_p->sub_node.size()-1; i >= 0; i--)
                            {
                                s.push(node_p->sub_node.at(size_t(i)));
                                queue.push(node_p->sub_node.at(size_t(i)));
                            }
                        size--;
                        }
                    }
                    order_nodes.clear();
                    int size_s = s.size();
                    for (size_t i = 0; i < size_s; i++)
                    {
                        order_nodes.push_back(s.top());
                        s.pop();
                    }
                }
            }
            void preorder(Node *root){
                if(root == nullptr){
                    return;
                }else{
                    order_nodes.clear();
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
                _root->sub_node.push_back(new_node);
            }
            else if(!in_sub_childs(n1)){
                throw runtime_error(n1 + "dosen`t find in this Org");
            }else{
                Node *new_node = create_new_node(n2);
                vector<Node*> vec_child = iter.get_order_nodes();
                for (size_t i = 0; i < vec_child.size(); i++)
                {
                    if(vec_child[i]->_name == n1){
                        vec_child[i]->sub_node.push_back(new_node);
                        break;
                    }
                }
            }
            return *this;
        }
        bool in_sub_childs(const string n){

            iter.level_order(this->_root);
            vector<Node*> vec = iter.get_order_nodes();
            // // cout<<vec<<endl;
            // for (size_t i = 0; i < vec.size(); i++)
            // {
            //     // cout<<"in sub child: vec["<<i<<"]"<<vec[i]->_name<<endl;
            // }
            
            // // cout<<"395"<<endl;
            // // cout<<"vec.size!! "<<vec.size()<<endl;
            for (size_t i = 0; i < vec.size(); i++)
            {
                if(vec[i]->_name == n){
                    return true;
                }
            }
            return false;
            
        }
        Iterator begin(){
            return begin_level_order();
        }
        Iterator end(){
            return end_level_order();
        }
        Iterator begin_level_order(){
            return Iterator(this->_root, "level_order");
        }
        Iterator end_level_order(){
            return Iterator(nullptr, "level_order");
        }
        Iterator begin_reverse_order(){
            return Iterator(this->_root, "reverse_level_order");
        }
        Iterator reverse_order(){
            return Iterator(nullptr, "reverse_level_order");

        }
        Iterator begin_preorder(){
            return Iterator(this->_root, "");
        }
        Iterator end_preorder(){
            return Iterator(nullptr, "");
        }

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
        //                     os <<  "        |"<<endl;
        //                     os<<"  "<<org._root->sub_node[i]->sub_node[j]->_name<<endl;
        //                 }
        //                 os<<endl;
        //             }
        //         }
        //     }
        //     return os;
        // }
        friend std::ostream& operator<<(ostream& os, OrgChart &org){

            org.iter.level_order(org._root);
            vector<Node*> nodes_order = org.iter.get_order_nodes();
            // for (size_t i = 0; i < nodes_order.size(); i++)
            // {
            //     cout<<nodes_order.at(i)->_name<< "  ";
            // }
            
            string space = "       ";
            string small_space = "     ";
            os << "                 "<<org._root->_name<<endl;
            os<<endl;
            os<<"        |---------|---------|"<<endl;
            os<<endl;
            int total_size = nodes_order.size();
            size_t k=1;
            size_t temp=1;
            bool once = false;
            while (total_size>=0 && temp < nodes_order.size())
            {
                if(!once){
                    for (size_t i = 0; i < org._root->sub_node.size(); i++)
                    {
                        os<<space<<nodes_order.at(temp++)->_name;
                        total_size--;
                    }
                once=true;
                os<<endl;
                os<<endl<<space<<" |";
                os<<space<<space<<"     |"<<endl;
                os<<endl;
                }
                for (size_t i = 1; i < org._root->sub_node.size(); i++)
                {
                    if(total_size <= 0 || temp >= nodes_order.size()){
                        break;
                    }
                    if(nodes_order.at(k)->_name == org._root->sub_node.at(i-1)->_name){
                        for (size_t j = 0; j < org._root->sub_node.at(i-1)->sub_node.size(); j++)
                        {
                            os<<small_space<<nodes_order.at(temp++)->_name;
                            total_size--;
                        }
                    }
                    os<<small_space<<" ";
                }
            }
            return os;
        }
       
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