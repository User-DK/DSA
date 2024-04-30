#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode
{
  char data;
  int frequency;
  TreeNode *left, *right;

  TreeNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

struct Comparator
{
  bool operator()(const TreeNode *a, const TreeNode *b) const
  {
    return a->frequency > b->frequency;
  }
};

TreeNode *buildHuffmanTree(unordered_map<char, int> &freqMap)
{
  priority_queue<TreeNode *, vector<TreeNode *>, Comparator> pq;
  for (const auto &it : freqMap)
  {
    pq.push(new TreeNode(it.first, it.second));
  }

  while (pq.size() > 1)
  {
    TreeNode *right = pq.top();
    pq.pop();
    TreeNode *left = pq.top();
    pq.pop();

    TreeNode *parent = new TreeNode('\0', left->frequency + right->frequency);
    parent->left = left;
    parent->right = right;
    pq.push(parent);
  }

  return pq.top();
}

void generateCodes(TreeNode *root, string code, unordered_map<char, string> &codes)
{
  if (!root)
  {
    return;
  }

  if (root->data != '\0')
  {
    codes[root->data] = code;
  }

  generateCodes(root->left, code + "0", codes);
  generateCodes(root->right, code + "1", codes);
}

string huffmanEncode(const string &text, unordered_map<char, int> &freqMap, TreeNode *root)
{
  unordered_map<char, string> codes;
  generateCodes(root, "", codes);
  string encodedText;

  for (char c : text)
  {
    encodedText = encodedText + codes[c] + " ";
  }

  return encodedText;
}

string huffmanDecode(const string &encodedText, TreeNode *root)
{
  string decodedText;
  TreeNode *current = root;

  for (char bit : encodedText)
  {
    if (bit == '0')
    {
      current = current->left;
    }
    else if (bit == '1')
    {
      current = current->right;
    }

    if (current->left == nullptr && current->right == nullptr)
    {
      decodedText += current->data;
      current = root;
    }
  }

  return decodedText;
}

int main()
{
  string text;
  cout << "Enter text: ";
  cin >> text;
  unordered_map<char, int> freqMap;
  for (char c : text)
  {
    freqMap[c]++;
  }

  TreeNode *root = buildHuffmanTree(freqMap);

  string encodedText = huffmanEncode(text, freqMap, root);
  cout << "Encoded Text: " << encodedText << endl;
  string decodedText = huffmanDecode(encodedText, root);
  cout << "Decoded Text: " << decodedText << endl;
  return 0;
}
