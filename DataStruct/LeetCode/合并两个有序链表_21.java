package leetcode;

public class 合并两个有序链表_21 {
}

class mergeTwoLists {
    //    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
//        ListNode head = new ListNode(0);
//        ListNode ans = head;
//        while (l1 != null && l2 != null) {
//            if (l1.val <= l2.val) {
//                head.next = l1;
//                l1 = l1.next;
//            } else {
//                head.next = l2;
//                l2 = l2.next;
//            }
//            head = head.next;
//        }
//        head.next = l1 == null ? l2 : l1;
//        return ans.next;
//    }
//}
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode ans = head;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                head.next = l1;
                l1 = l1.next;
            } else {
                head.next = l2;
                l2 = l2.next;
            }
            head = head.next;
        }
        head.next = l1 == null ? l2 : l1;
        return ans.next;
    }
}