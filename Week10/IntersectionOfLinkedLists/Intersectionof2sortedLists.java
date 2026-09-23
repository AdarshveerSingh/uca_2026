public class Intersectionof2sortedLists {
     public static ListNode intersection(ListNode head1, ListNode head2) {
        ListNode temp1=head1;
        ListNode temp2=head2;
        ListNode dummy =new ListNode(-1);
        ListNode temp=dummy;
        while(temp1!=null && temp2!=null){
            if(temp1.val==temp2.val){
                temp.next=new ListNode(temp1.val);
                temp=temp.next;
                temp1=temp1.next;
                temp2=temp2.next;
            }
            else if(temp1.val>temp2.val){
                temp2=temp2.next;
            }
            else{
                temp1=temp1.next;
            }
        }
        return dummy.next;
    }

     public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        ListNode head1 = new ListNode(1);
        head1.next = new ListNode(2);
        head1.next.next = new ListNode(3);
        head1.next.next.next = new ListNode(4);
        head1.next.next.next.next = new ListNode(6);

        ListNode head2 = new ListNode(2);
        head2.next = new ListNode(4);
        head2.next.next = new ListNode(6);
        head2.next.next.next = new ListNode(8);

        ListNode result1 = intersection(head1, head2);
        System.out.print("Intersection 1: ");
        printList(result1);

        ListNode h1 = new ListNode(1);
        h1.next = new ListNode(2);
        h1.next.next = new ListNode(2);
        h1.next.next.next = new ListNode(3);
        h1.next.next.next.next = new ListNode(4);

        ListNode h2 = new ListNode(2);
        h2.next = new ListNode(2);
        h2.next.next = new ListNode(2);
        h2.next.next.next = new ListNode(4);

        ListNode result2 = intersection(h1, h2);
        System.out.print("Intersection 2: ");
        printList(result2);
    }
   
}


class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { this.val = x; }
}