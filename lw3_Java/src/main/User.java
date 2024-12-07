package main;

public abstract class User {
    protected String username;
    protected String password;

    public User(String username, String password) {
        this.username = username;
        this.password = password;
    }

    // Method to get the username
    public String getUsername() {
        return username;
    }

    // Method to set the username
    public void setUsername(String username) {
        this.username = username;
    }

    // Method to get the password
    public String getPassword() {
        return password;
    }

    // Method to set the password
    public void setPassword(String password) {
        this.password = password;
    }

    // Method to check if the password is correct
    public boolean checkPassword(String password) {
        return this.password.equals(password);
    }

    // Abstract method to get the user role
    public abstract String getRole();
}