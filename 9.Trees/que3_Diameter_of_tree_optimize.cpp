// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
pair<int, int> fastDiameter(Node *root)
{
    // code here
    if (root == NULL)
    {
        return {0, 0};
    }
    pair<int, int> left = fastDiameter(root->left);
    pair<int, int> right = fastDiameter(root->right);
    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + right.second + 1;

    int height = max(left.second, right.second) + 1;
    int diameter = max(opt1, max(opt2, opt3));

    pair<int, int> ans;
    ans.first = diameter;
    ans.second = height;
    return ans;
}
int diameter(Node *root)
{
    // Your code here
    return fastDiameter(root).first;
}