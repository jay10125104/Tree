struct data_struct{
    multiset<int>m;
    data_struct(){

    }
    void insert(int x){
        m.insert(x);
    }
    void remove(int x){
        m.erase(m.find(x));
    }
    void erase(int x){
        m.erase(x);
    }
    bool count(int x){
        return m.count(x);
    }
    int size(){
        return m.size();
    }
    int lower_bound(int x){
        auto it =  m.lower_bound(x);
        if(it==m.end()){
            return -1;
        }
        else{
            return *it;
        }
    }
    auto upper_bound(int x){
        auto it =  m.upper_bound(x);
        if(it==m.end()){
            return -1;
        }
        else{
            return *it;
        }
    }
    int max(){
        return *(--m.end());
    }
    int min(){
        return *(m.begin());
    }
};
