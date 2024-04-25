class Tree
{
  Tree *left;
  Tree *right;
  int val;

public:
  Tree() : val(0), left(NULL), right(NULL) {}
  Tree(int val) : val(val), left(NULL), right(NULL) {}
  Tree(int val, Tree *left, Tree *right) : val(val), left(left), right(right) {}
};