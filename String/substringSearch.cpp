#include <bits/stdc++.h>
using namespace std;

// writing some functions for finding whether s is contained in x as a substring

// inbuild
bool check(string x, string s)
{
  return x.find(s) != string::npos; // endofstring
}

// using Knuth-Morris-Pratt (KMP) Algorithm
// time complexity O(n+m)
// The KMP algorithm preprocesses the pattern to create a partial match table (also known as the "lps" array), which helps in avoiding redundant comparisons.
vector<int> computeLPSArray(const string &pattern)
{
  int m = pattern.length();
  vector<int> lps(m);
  int len = 0;
  lps[0] = 0;

  int i = 1;
  while (i < m)
  {
    if (pattern[i] == pattern[len])
    {
      len++;
      lps[i] = len;
      i++;
    }
    else
    {
      if (len != 0)
      {
        len = lps[len - 1];
      }
      else
      {
        lps[i] = 0;
        i++;
      }
    }
  }
  return lps;
}

// KMP search function
bool KMP(const string &text, const string &pattern)
{
  int n = text.length();
  int m = pattern.length();
  if (m == 0)
    return true;
  if (n == 0)
    return false;

  vector<int> lps = computeLPSArray(pattern);
  int i = 0; // index for text
  int j = 0; // index for pattern

  while (i < n)
  {
    if (pattern[j] == text[i])
    {
      i++;
      j++;
    }
    if (j == m)
    {
      return true; // Found pattern at index (i - j)
    }
    else if (i < n && pattern[j] != text[i])
    {
      if (j != 0)
      {
        j = lps[j - 1];
      }
      else
      {
        i++;
      }
    }
  }
  return false;
}

// Boyer-Moore Algorithm
// The Boyer-Moore algorithm preprocesses the pattern to create two tables: the bad character table and the good suffix table.
void preprocessBadCharacter(const string &pattern, unordered_map<char, int> &badChar)
{
  int m = pattern.length();
  for (int i = 0; i < m - 1; i++)
  {
    badChar[pattern[i]] = i;
  }
}

vector<int> preprocessGoodSuffix(const string &pattern)
{
  int m = pattern.length();
  vector<int> goodSuffix(m, m);
  vector<int> borderPos(m + 1, 0);
  int i = m, j = m + 1;
  borderPos[i] = j;

  while (i > 0)
  {
    while (j <= m && pattern[i - 1] != pattern[j - 1])
    {
      if (goodSuffix[j] == m)
      {
        goodSuffix[j] = j - i;
      }
      j = borderPos[j];
    }
    i--;
    j--;
    borderPos[i] = j;
  }

  j = borderPos[0];
  for (i = 0; i <= m; i++)
  {
    if (goodSuffix[i] == m)
    {
      goodSuffix[i] = j;
    }
    if (i == j)
    {
      j = borderPos[j];
    }
  }
  return goodSuffix;
}

bool BoyerMoore(const string &text, const string &pattern)
{
  int n = text.length();
  int m = pattern.length();
  if (m == 0)
    return true;
  if (n == 0)
    return false;

  unordered_map<char, int> badChar;
  preprocessBadCharacter(pattern, badChar);
  vector<int> goodSuffix = preprocessGoodSuffix(pattern);

  int s = 0; // shift of the pattern with respect to text
  while (s <= (n - m))
  {
    int j = m - 1;

    while (j >= 0 && pattern[j] == text[s + j])
    {
      j--;
    }

    if (j < 0)
    {
      return true; // Pattern found at shift s
      s += goodSuffix[0];
    }
    else
    {
      char badCharShift = text[s + j];
      int badCharIndex = (badChar.find(badCharShift) != badChar.end()) ? badChar[badCharShift] : -1;
      s += max(1, j - badCharIndex);
    }
  }
  return false;
}

int main()
{
}