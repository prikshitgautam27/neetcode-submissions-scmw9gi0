class MinStack {
    stack<pair<int,int>>st;
public:
    MinStack() {
        
        

    }
    
    void push(int val) {
       
        if(st.empty()){
            st.push({val,val});

        }
        else{
            int curr_min=min(st.top().second,val);
            st.push({val,curr_min});
        }
        
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
       return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
