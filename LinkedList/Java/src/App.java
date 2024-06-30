public class App {
    public static void main(String[] args) throws Exception {
        LinkedList linkedList = new LinkedList();
        for (int i = 0; i < 10; i++) {
            linkedList.addHead(i);
        }
        linkedList.printList();
    }
}
