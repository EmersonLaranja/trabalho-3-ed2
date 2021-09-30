#include "tst.h"
#define MAX 50

struct tst
{
  Page **pages;
  unsigned char letter;
  unsigned isEndOfString;
  Tst *left, *mid, *right;
  int indexPage;
};

// A utility function to create a new ternary search tree Tst
Tst *initTst(char letter, int numberPages)
{
  Tst *newTst = (Tst *)malloc(sizeof(Tst));
  newTst->letter = letter;
  newTst->isEndOfString = 0;
  newTst->left = NULL;
  newTst->mid = NULL;
  newTst->right = NULL;
  newTst->pages = (Page **)malloc(sizeof(Page *) * numberPages);
  newTst->indexPage = 0;
  for (int i = 0; i < numberPages; i++)
  {
    newTst->pages[i] = NULL;
  }

  return newTst;
}

// Function to insert a new word in a Ternary Search Tree
void insert(Tst **root, char *word, int numberPages, Page *page)
{
  if (*word >= 'A' && *word <= 'Z')
  {
    *word = *word + ('a' - 'A');
  }

  if (!(*root))
  {
    *root = initTst(*word, numberPages);
  }

  if ((*word) < (*root)->letter)
    insert(&((*root)->left), word, numberPages, page);
  else if ((*word) > (*root)->letter)
    insert(&((*root)->right), word, numberPages, page);
  else
  {
    if (*(word + 1))
      insert(&((*root)->mid), word + 1, numberPages, page);
    else
    {

      (*root)->isEndOfString = 1;
      for (int i = 0; i < (*root)->indexPage; i++)
      {
        if (!strcmp(getPageName(page), getPageName((*root)->pages[i])))
          return;
      }
      (*root)->pages[(*root)->indexPage] = page;
      (*root)->indexPage++;
    }
  }
}

// A recursive function to traverse Ternary Search Tree
void traverseTSTUtil(Tst *root, char *buffer, int depth)
{

  if (root)
  {

    // First traverse the left subtree
    traverseTSTUtil(root->left, buffer, depth);

    // Store the character of this Tst
    buffer[depth] = root->letter;
    if (root->isEndOfString)
    {
      buffer[depth + 1] = '\0';
    }

    // Traverse the subtree using equal pointer (middle subtree)
    traverseTSTUtil(root->mid, buffer, depth + 1);

    // Finally Traverse the right subtree
    traverseTSTUtil(root->right, buffer, depth);
  }
}

// The main function to traverse a Ternary Search Tree.
// It mainly uses traverseTSTUtil()
void traverseTst(Tst *root)
{
  char buffer[MAX];
  traverseTSTUtil(root, buffer, 0);
}

// Function to search a given word in TST
Page **searchTST(Tst *root, char *word)
{
  if (!root)
    return 0;

  if (*word < (root)->letter)
    return searchTST(root->left, word);
  else if (*word > (root)->letter)
    return searchTST(root->right, word);
  else
  {
    if (*(word + 1) == '\0')
    {
      if (root->isEndOfString == 1)
      {
        return root->pages;
      }
      return NULL;
    }

    return searchTST(root->mid, word + 1);
  }
}

void destroyTST(Tst *root)
{
  if (root)
  {
    free(root->pages);
    destroyTST(root->left);
    destroyTST(root->mid);
    destroyTST(root->right);
    free(root);
  }
}