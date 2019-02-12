class MyStack {
public:
    stack<int> a;
    stack<int> max, min;
    void push(int b) {
        a.push(b);
        if (max.empty() || max.top() <= b) {
            max.push(b);
        }
        if (min.empty() || min.top() >= b) {
            min.push(b);
        }
    }

    void pop() {
        int b = a.top();
        a.pop();
        if (b == max.top()) max.pop();
        if (b == min.top()) min.pop();
    }

    int maxi() {
        if (a.empty()) return 0;
        return max.top();
    }

    int mini() {
        if (a.empty()) return INT_MAX;
        return min.top();
    }

    int size() {
        return a.size();
    }

    bool empty() {
        return a.empty();
    }

    int top() {
        return a.top();
    }
};


class MyQueue {
public:
    MyStack a, b;
    void push(int c) {
        a.push(c);
    }

    void pop() {
        if (b.empty()) {
            while (!a.empty()) {
                int k = a.top();
                a.pop();
                b.push(k);
            }
        }
        b.pop();
    }

    int max() {
        return std::max(a.maxi(), b.maxi());
    }

    int min() {
        return std::min(a.mini(), b.mini());
    }

    bool empty() {
        return (a.empty() && b.empty());
    }

    int size() {
        return a.size() + b.size();
    }
};

