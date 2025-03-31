

public class BoundryTraversal {
    static boolean isLeaf(TreeNode root){
        return root.left==null && root.right==null;
    }
    static void CollectLeftNodes(TreeNode root){
        if(root==null||isLeaf(root)){
            return;
        }
        System.out.print(root.val+" ");
        if(root.left!=null){
            CollectLeftNodes(root.left);
        }
        else if(root.right!=null){
            CollectLeftNodes(root.right);
        }
    }
    static void CollectLeafNodes(TreeNode root){
        if(root==null){
            return;
        }
        if(isLeaf(root)){
            System.out.print(root.val+" ");
            return;
        }
        CollectLeafNodes(root.left);
        CollectLeafNodes(root.right);
    }
    static void CollectRightNodes(TreeNode root){
        if(root==null||isLeaf(root)){
            return;
        }
        if(root.right!=null){
            CollectRightNodes(root.right);
        }
        else if(root.left!=null){
            CollectRightNodes(root.left);
        }
        System.out.print(root.val+" ");
    }
    public static void main(String args[]){
        // Hardcoded Binary tree
        //        20
        //       /  \
        //      8    22
        //     / \     \
        //    4   12    25
        //       /  \
        //      10   14
        TreeNode root = new TreeNode(20);
        root.left = new TreeNode(8);
        root.right = new TreeNode(22);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(12);
        root.left.right.left = new TreeNode(10);
        root.left.right.right = new TreeNode(14);
        root.right.right = new TreeNode(25);
        System.out.print(root.val+" ");
        CollectLeftNodes(root.left);
        CollectLeafNodes(root);
        CollectRightNodes(root.right);
    }
}
