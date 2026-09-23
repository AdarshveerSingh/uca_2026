public class ReverseLinkedListRecursion {

    public static Node reverseList(Node head) {
        if(head==null)return head;
        if(head!=null && head.next==null)return head;
        Node x=head.next;
        head.next=null;
        Node z= reverseList(x);
        x.next=head;
        return z;
    }
    public static void main(String[] args) {
        Node head=new Node(1);
        Node a=new Node(2);
        Node b=new Node(3);
        Node c=new Node(4);
        Node d=new Node(5);
        head.next=a;
        a.next=b;
        b.next=c;
        c.next=d;
        Node temp=reverseList(head);
        while(temp!=null){
            System.out.print(temp.val+" ");
            temp=temp.next;
        }

    }

}
class Node{
    int val;
    Node next;
    Node(int val){
        this.val=val;
        this.next=null;
    }
}