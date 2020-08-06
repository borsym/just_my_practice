import java.util.*;

public class Main {
    public static void main(String[] args) {
        System.out.println("How many players do we have?");
        while (true) {
            try {
                Scanner sc = new Scanner(System.in);
                ChainWords chain = new ChainWords(sc.nextInt());
                break;
            } catch (InputMismatchException err) {
                System.out.println("I need a number!");
            }
        }



    }
}
