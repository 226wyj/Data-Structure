import java.util.ArrayList;
import java.util.List;

public class LinkedList {
    private Node head;
    private Node tail;
    private int length;

    public LinkedList() {
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    public LinkedList(Node node) {
        this.head = node;
        this.tail = node;
        this.length = 1;
    }

    public Node getHead() {
        return head;
    }

    public Node getTail() {
        return tail;
    }

    public int getLength() {
        return length;
    }

    public List<Integer> getValues() {
        final List<Integer> result = new ArrayList<>();
        Node current = head;
        while (current != null) {
            result.add(current.getValue());
            current = current.getNext();
        }
        return result;
    }

    public void printList() {
        final List<Integer> values = getValues();
        System.out.println(values);
    }

    public void addTail(int value) {
        Node newNode = new Node(value);
        if (head == null) {
            head = newNode;
            tail = newNode;
        } else {
            tail.setNext(newNode);
            tail = tail.getNext();
        }
        length++;
    }

    public void addHead(int value) {
        Node newNode = new Node(value);
        newNode.setNext(head);
        head = newNode;
        length++;
    }
}
