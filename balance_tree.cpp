struct node // структура для представления узлов дерева
{
    int key;
    unsigned char height;
    node* left;
    node* right;
    int leftSize, rightSize;
    node(int k) { key = k; left = right = 0; height = 1; leftSize = 0; rightSize = 0; }
};

node* root1, *root2;

unsigned char height(node* p)
{
    return p?p->height:0;
}

int sizeLeft(node* p) {
    return p?p->leftSize:0;
}

int sizeRight(node* p) {
    return p?p->rightSize:0;
}

int bfactor(node* p)
{
    return height(p->right)-height(p->left);
}

void fixheight(node* p)
{
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    p->height = (hl>hr?hl:hr)+1;
}

void fixSizes(node* p)
{
    p->leftSize = sizeLeft(p->left) + sizeRight(p->left) + (p->left? 1 : 0);
    p->rightSize = sizeLeft(p->right) + sizeRight(p->right) + (p->right? 1 : 0);
}

node* rotateright(node* p) // правый поворот вокруг p
{
    node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixSizes(p);
    fixSizes(q);
    fixheight(p);
    fixheight(q);
    return q;
}

node* rotateleft(node* q) // левый поворот вокруг q
{
    node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixSizes(q);
    fixSizes(p);
    fixheight(q);
    fixheight(p);
    return p;
}


node* balance(node* p) // балансировка узла p
{
    fixheight(p);
    fixSizes(p);
    if( bfactor(p)==2 )
    {
        if( bfactor(p->right) < 0 )
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if( bfactor(p)==-2 )
    {
        if( bfactor(p->left) > 0  )
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p; // балансировка не нужна
}


node* insert(node* p, int k) // вставка ключа k в дерево с корнем p
{
    if( !p ) return new node(k);
    if( k<p->key )
        p->left = insert(p->left,k);
    else
        p->right = insert(p->right,k);
    return balance(p);
}


void find2(node*p, int k, int& ans) {
    if( k<p->key ) {
        find2(p->left, k, ans);
    } else if (k > p->key) {
        ans += p->leftSize + 1;
        find2(p->right, k, ans);
    } else {
        ans += p->leftSize;
    }
}

void find1(node*p, int k, int& ans) {
    if( k<p->key ) {
        ans += p->rightSize + 1;
        find1(p->left, k, ans);
    } else if (k > p->key) {
        find1(p->right, k, ans);
    } else {
        ans += p->rightSize;
    }
}



int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; cin >> n;
    vector <int> a;
    vector <int> first(n), second(n);
    for (int i = 0; i < n; ++i) {
        int b; cin >> b;
        a.push_back(b);
    }
    for (int i = 0; i < n; ++i) {
        root2 = insert(root2, a[i]);
        find1(root2, a[i], first[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        root1 = insert(root1, a[i]);
        find2(root1, a[i], second[i]);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (long long)(first[i])*(long long)(second[i]);
    }
    cout << ans;
    return 0;
}
