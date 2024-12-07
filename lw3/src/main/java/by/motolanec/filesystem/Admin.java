package by.motolanec.filesystem;

public class Admin extends User {
    public Admin(String username, String password) {
        super(username, password);
    }

    @Override
    public String getRole() {
        return "Admin";
    }

    // Method to create a new user
    public void createUser(String username, String password, String role) {
        // Implementation to create a new user
        System.out.println("Creating user: " + username);
    }

    // Method to delete a user
    public void deleteUser(String username) {
        // Implementation to delete a user
        System.out.println("Deleting user: " + username);
    }

    // Method to change a user's role
    public void changeUserRole(String username, String newRole) {
        // Implementation to change a user's role
        System.out.println("Changing role for user: " + username + " to " + newRole);
    }

    // Method to reset a user's password
    public void resetUserPassword(String username) {
        // Implementation to reset a user's password
        System.out.println("Resetting password for user: " + username);
    }
}