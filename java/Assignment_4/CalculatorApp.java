import Arithmetic.*;

public class CalculatorApp {
    public static void main(String[] args) {
        Add adder = new Add();
        Sub subtractor = new Sub();
        Mul multiplier = new Mul();
        Div divider = new Div();

        double x = 20.0;
        double y = 10.0;

        System.out.println("Arithmetic Operations using Arthematic package:");
        System.out.println("Addition: " + adder.calculate(x, y));
        System.out.println("Subtraction: " + subtractor.calculate(x, y));
        System.out.println("Multiplication: " + multiplier.calculate(x, y));
        System.out.println("Division: " + divider.calculate(x, y));
    }
}
