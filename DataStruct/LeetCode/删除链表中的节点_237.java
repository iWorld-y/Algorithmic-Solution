package leetcode;

public class 删除链表中的节点_237 {
}

class deleteNode {
    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
}