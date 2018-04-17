#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};


int calculateHeight(Node *head);

int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;

  std::vector<Node> nodes;
  nodes.resize(n);

 int parentIndex = 0;

  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);
   else parentIndex = child_index;
    nodes[child_index].key = child_index;
  }


  // Replace this code with a faster implementation
  int maxHeight = 0;
  maxHeight = calculateHeight(&nodes[parentIndex]);

  std::cout << maxHeight << std::endl;
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return main_with_large_stack_space();
}


int arrMax(int arr[],int numOfelements)
{
    int max=0;
    for(int i=0; i<numOfelements ;i++)
        if(arr[i]>max) max = arr[i];
    return max;
}



int calculateHeight(Node *head)
{
 	int kidsNum = head->children.size();
 	int *countt= (int*)calloc(kidsNum,sizeof(int));

	if(kidsNum == 0) return 1;
    else
    for(int i=0; i < kidsNum ; i++)
        countt[i] = 1+calculateHeight(head->children[i]);

     return (arrMax(countt,kidsNum));
}

