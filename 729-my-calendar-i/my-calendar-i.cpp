class Tree{
    public:
    Tree* left;
    Tree* right;
    int start,end;

    Tree(int start,int end){
        this->start = start;
        this->end = end;
        left = nullptr;
        right = nullptr;
    }

    bool insert(int start,int end){
        Tree* curr = this;
        while(true){

            if(start>= curr->end){
                if(!curr->right){
                    curr->right = new Tree(start,end);
                    return true;
                }
                curr = curr->right;
            }else if(end<=curr->start){
                if(!curr->left){
                    curr->left = new Tree(start,end);
                    return true;
                }
                curr = curr->left;
            }else{
                return false;
            }
        }

    }
};
class MyCalendar {
public:
    Tree* root;
    MyCalendar() {
        root = nullptr;
    }
    
    bool book(int start, int end) {
        
        if(!root){
            root = new Tree(start,end);
            return true;
        }

        return root->insert(start,end);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */