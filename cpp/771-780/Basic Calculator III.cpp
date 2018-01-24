class Solution {
    
    void apply(stack<int>&s, char c)
    {
        int b = s.top();s.pop();
        int a = s.top();s.pop();
        if(c == '+') s.push(a+b);
        else if(c == '-') s.push(a-b);
        else if(c == '*') s.push(a*b);
        else s.push(a/b);
    }
    
public:
    int calculate(string s) {
        
        stack<char> symbol;
        stack<int>ss;
        int v = 0;
        bool number = false;
        for(auto e : s)
        {
            if( number && (e < '0' || e > '9'))
            {
                ss.push(v);
                v = 0;
                number = false;
            }
            
            if(e == ' ') continue;
            else if(e == ')')
            {
                while(symbol.top() != '(')
                {
                    char c = symbol.top();
                    apply(ss, c);
                    symbol.pop();
                }
                symbol.pop();
            } else if(e == '(') {
                symbol.push('(');
            } else if(e >= '0' && e <= '9') {
                v = 10*v + (e-'0');
                number = true;
            } else if(e == '+' || e == '-') {
                if(symbol.empty())
                    symbol.push(e);
                else {
                    while(!symbol.empty() && symbol.top() != '(')
                    {
                        char c = symbol.top();
                        symbol.pop();
                        apply(ss, c);
                    }
                    symbol.push(e);
                }
            } else if(e == '*' || e == '/') {
                if(symbol.empty())
                    symbol.push(e);
                else {
                    while(!symbol.empty() && (symbol.top() == '*' || symbol.top() == '/') )
                    {
                        char c = symbol.top();
                        symbol.pop();
                        apply(ss, c);
                    }
                    symbol.push(e);
                }
            }
        }
        
        if( number )
            ss.push(v);
        
        while(!symbol.empty())
        {
            char c = symbol.top();
            apply(ss,c);
            symbol.pop();
        }
        
        return ss.top();
    }
};
