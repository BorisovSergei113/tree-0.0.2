#include<iostream>
using namespace std;

template <class T>

class tree_t
{
private:
    struct node_t
    {
        node_t * left;
        node_t * right;
        T value;
        
        node_t()
        {
            left = right = nullptr;
            value = 0;
        }
        
        node_t(T value1)
        {
            value = value1;
            left = right = nullptr;
        }
        
     
        void add_element (T value)
        {
           
            if (this->value > value)
            {
                if (left == nullptr)
                {
                    left = new node_t();
                    left->value = value;
                }
                else left->add_element(value);
            }
            else if (this->value < value) {
                if (right == nullptr){
                    right = new node_t;
                    right->value = value;
                }
                else right->add_element(value);
            }
        }
        
        bool search_element (T value) const
        {
            if ( this->value == value)
            {
                return true;
            }
            if (value < this->value)
            {
                if (left)
                {
                    return left->search_element(value);
                }
                else return false;
            }
            if (value > this-> value)
            {
                if (right)
                {
                    return right->search_element(value);
                }
                else return false;
            }
            return false;
        }
        
        void print_tree (int level, ostream &stream) const
        {
            if (right) {
                right->print_tree(level + 4, stream);
            }
            for (int i = 0; i < level + 4; i++) {
                stream <<'-';
            }
            stream <<value<<'\n';
            if (left) {
                left->print_tree( level + 4 , stream);
            }
        }

    
    };
private:
    node_t * root_;
    
public:
    tree_t()
    {
        root_=nullptr;
    }
    
    ~tree_t()
    {
        delete_el (root_);
    }
    
    void delete_el(node_t * node)
    {
        if (root_ != nullptr) {
            if (node->left) delete_el (node->left);
            if (node->right) delete_el (node->right);
            delete node;
        }
    }
    
    void insert(T value)
    {
        if (root_ == nullptr)
        {
            root_ = new node_t;
            root_->value = value;
        }
        root_->add_element(value);
    }
    
    bool find(T value) const
    {
        if(root_){
            return root_->search_element(value);
        }
        return false;
    }
    void print(std::ostream & stream) const
    {
        if(root_) root_->print_tree(0,stream);
        else
        { cout<<"Tree is empty!!!"<<endl;
          throw "Tree is empty!!!";
        }
    }
    
    
    bool remove(T key)
    {
        if (root_==nullptr) {
            cout<<"Tree is empty!!!"<<endl;
            throw "Tree is empty!!!";
            return false;
        }
            node_t* p = root_;
            node_t* parent  = nullptr;
            
            while((p != nullptr) && (p->value != key))
            {
                parent = p;
                if(key < (p->value))
                    p = p->left;
                else
                    p = p->right;
            }
            
            if(p != nullptr)
            {
                node_t* removed = nullptr;
                
                if ((p->left == nullptr) || (p->right == nullptr))
                {
                    node_t* child = nullptr;
                    removed = p;
                    
                    if((p->left) != nullptr)
                        child = p->left;
                    else if((p->right) != nullptr)
                        
                        child = p->right;
                    
                    if(parent == nullptr)
                        root_ = child;
                    else
                    {
                        if((parent->left) == p)
                            parent->left = child;
                        else
                            parent->right = child;
                    }
                }
                 if (p->left != nullptr && p->right != nullptr)
                {
                    node_t* mostLeft = p->right;
                    node_t* mostLeftParent = p;
                    
                    while ((mostLeft->left) != nullptr)
                    {
                        mostLeftParent = mostLeft;
                        mostLeft = mostLeft->left;
                    }
                    
                    p->value = mostLeft->value;
                    removed = mostLeft;
                    
                    if((mostLeftParent->left) == mostLeft)
                        mostLeftParent->left = nullptr;
                    else
                        mostLeftParent->right = mostLeft->right;
                }
                delete removed;
                return true;
            }
        return false ;
        }
    
    bool compare (node_t* first,node_t* second) const
    {
        if(first == second ) return true; // null=null -> true
        if(first == nullptr || second == nullptr) return false;
        return ((first->value == second->value) && compare (first->left,  second->left ) && compare (first->right, second->right));
    }
    
    node_t* get_root() const 
    {
        return root_;
    }
    
    auto operator == (tree_t const & other) const //возвращвет тип bool
    {
        return compare(root_, other.get_root());
    }
    
    tree_t (std::initializer_list<T> keys)
    {
        root_=nullptr;
        size_t length = keys.size(); 
        T buffer_el;
        for (size_t i = 0; i<length; i++)
        {
            buffer_el = *(keys.begin()+i);
            insert(buffer_el);
        }
    }
};

