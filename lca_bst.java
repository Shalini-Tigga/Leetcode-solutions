class lca_bst{
    // T.C O(H)
    // S.C O(H)
    TreeNode root;
    TreeNode findLCA(TreeNode root,TreeNode nodeA,TreeNode nodeB){
        if(root==null){
            return root;
        }
        if(nodeA.val<root.val && nodeB.val<root.val){
            return findLCA(root.left, nodeA, nodeB);
        }
        if(nodeA.val>root.val && nodeB.val>root.val){
            return findLCA(root.right, nodeA, nodeB);
        }
        return root;
    }
    TreeNode findLCAIterative(TreeNode root,TreeNode nodeA,TreeNode nodeB){
        //T.C O(H)
        //S.C O(1)
        if(root==null){
            return root;
        }
        TreeNode curr=root;
        while(curr!=null){
            if(nodeA.val<curr.val && nodeB.val<curr.val){
                curr=curr.left;
            }
            else if(nodeA.val>curr.val && nodeB.val>curr.val){
                curr=curr.right;
            }
            else{
                return curr;
            }
        }
        return root;
    }
    public static void main(String args[]){
        lca_bst tree=new lca_bst();
        tree.root=new TreeNode(50);
        tree.root.left=new TreeNode(40);
        tree.root.right=new TreeNode(55);
        tree.root.left.left=new TreeNode(35);
        tree.root.left.right=new TreeNode(45);
        tree.root.left.left.left=new TreeNode(25);
        tree.root.left.left.right=new TreeNode(38);
        tree.root.left.right.right=new TreeNode(48);
        tree.root.right.left=new TreeNode(52);
        tree.root.right.right=new TreeNode(60);
        tree.root.right.right.right=new TreeNode(65);
        System.out.println( tree.findLCA(tree.root,tree.root.right,tree.root.right.left).val);
    }
}