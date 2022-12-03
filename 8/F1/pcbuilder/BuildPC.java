public class BuildPC {
    public static void main (String[] args) {
        Processor p = new Ryzen7();
        System.out.println(p.name() + "\n" + p.price());
    }
}
