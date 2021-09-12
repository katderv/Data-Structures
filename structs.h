
struct students {
    char AM[9];
    char name[13];
    char surname[17];
    float grade;
};
typedef struct students students;


struct bin_tree {
    students data;
    struct bin_tree *right, *left, *inside;

};
typedef struct bin_tree node;

void insert(node **tree, students num) {
    node *temp = NULL;


    if (!(*tree)) {
        temp = (node *) malloc(sizeof(node));
        temp->left = NULL;
        temp->right = NULL;
        temp->data = num;
        *tree = temp;
        return;
    }

    int ret = memcmp(num.AM, (*tree)->data.AM, 9);

    if (ret < 0) {
        insert(&(*tree)->left, num);
    } else if (ret > 0) {
        insert(&(*tree)->right, num);
    }


}

node* minValueNode( node* nod)
{
    node* current = nod;

    //loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}


node* maxValueNode( node* nod)
{
    node* current = nod;

    //loop down to find the leftmost leaf
    while (current && current->right != NULL)
        current = current->right;

    return current;
}


node* deleteNode(node* root, char del[])
{
    // base case
    if (root == NULL) return root;

     int re = memcmp(del , root->data.AM, 9);

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( re < 0)
        root->left = deleteNode(root->left, del);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (re > 0)
        root->right = deleteNode(root->right, del);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        //No Children
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left==NULL || root->right==NULL)
        {
            node *temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, del);
    }
    return root;
}



node *search(node **tree, char AM[]) {
    if (!(*tree)) {
        return NULL;

    }

    int retu = memcmp(AM, (*tree)->data.AM, 9);

    if (retu < 0) {
        return search(&(*tree)->left, AM);
    }
    else if (retu > 0) {
        return search(&(*tree)->right, AM);
    }
    else if (retu == 0) {
       return *tree;
    }
    else

        return NULL;
}

void print_inorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("AM: %s\t",tree->data.AM);
        printf("Name: %s\t",tree->data.name);
        printf("Surname: %s\t",tree->data.surname);
        printf("Grade: %.2f\n",tree->data.grade);
        print_inorder(tree->right);
    }
}
void insertGrade(node **tree, students num) {
    node *temp = NULL;


    if (!(*tree)) {
        temp = (node *) malloc(sizeof(node));
        temp->left = NULL;
        temp->right = NULL;
        temp->inside = NULL;
        temp->data = num;
        *tree = temp;
        return;
    }

    if ((*tree)->data.grade > num.grade ) {
        insertGrade(&(*tree)->left, num);
    }
    else if ((*tree)->data.grade < num.grade) {
        insertGrade(&(*tree)->right, num);
    }
    else if((*tree)->data.grade == num.grade){
        insertGrade(&(*tree)->inside, num);

    }


}

