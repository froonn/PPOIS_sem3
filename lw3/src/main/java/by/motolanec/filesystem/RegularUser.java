package by.motolanec.filesystem;

public class RegularUser extends User {
    public RegularUser(String username, String password) {
        super(username, password);
    }

    @Override
    public String getRole() {
        return "RegularUser";
    }

    // Method to view a file
    public void viewFile(File file) {
        System.out.println("Viewing file: " + file.getName());
    }

    // Method to download a file
    public void downloadFile(File file) {
        System.out.println("Downloading file: " + file.getName());
    }

    // Method to upload a file
    public void uploadFile(File file) {
        System.out.println("Uploading file: " + file.getName());
    }

    // Method to share a file with another user
    public void shareFile(File file, User user) {
        System.out.println("Sharing file: " + file.getName() + " with user: " + user.getUsername());
    }
}