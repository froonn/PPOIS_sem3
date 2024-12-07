package main;

public class ExceptionHandler extends Throwable {
    public static void handle(Exception e) {
        // Handle exceptions
        System.err.println("Error: " + e.getMessage());
    }
}