public class searchLinkedList {

    public static boolean search(ListNode h1,ListNode h2){
        if (h1 == null) return true;
        ListNode temp=h2;
        ListNode temp1=h1;
        while(temp!=null){
            ListNode temp2=temp;
            while(temp2!=null && temp1!=null && temp2.val==temp1.val){
                temp2=temp2.next;
                temp1=temp1.next;
            }
            if(temp1==null){
                return true;
            }
            else{
                temp1=h1;
                temp=temp.next;
            }
        }
        return false;
    }

    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        ListNode h1 = new ListNode(3);
        h1.next = new ListNode(4);
        h1.next.next = new ListNode(6);

        ListNode h2 = new ListNode(1);
        h2.next = new ListNode(2);
        h2.next.next = new ListNode(3);
        h2.next.next.next = new ListNode(4);
        h2.next.next.next.next = new ListNode(6);

        if(search(h1,h2))System.out.println("Yes");
        else System.out.println("No");
    }
}

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { this.val = x; }
}