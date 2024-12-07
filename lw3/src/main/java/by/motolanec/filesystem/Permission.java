package by.motolanec.filesystem;

public class Permission {
    private User user;
    private File file;
    private boolean canRead;
    private boolean canWrite;
    private boolean canExecute;

    public Permission(User user, File file, boolean canRead, boolean canWrite, boolean canExecute) {
        this.user = user;
        this.file = file;
        this.canRead = canRead;
        this.canWrite = canWrite;
        this.canExecute = canExecute;
    }

    // Method to get the user
    public User getUser() {
        return user;
    }

    // Method to set the user
    public void setUser(User user) {
        this.user = user;
    }

    // Method to get the file
    public File getFile() {
        return file;
    }

    // Method to set the file
    public void setFile(File file) {
        this.file = file;
    }

    // Method to check if the user can read the file
    public boolean canRead() {
        return canRead;
    }

    // Method to set read permission
    public void setReadPermission(boolean canRead) {
        this.canRead = canRead;
    }

    // Method to check if the user can write to the file
    public boolean canWrite() {
        return canWrite;
    }

    // Method to set write permission
    public void setWritePermission(boolean canWrite) {
        this.canWrite = canWrite;
    }

    // Method to check if the user can execute the file
    public boolean canExecute() {
        return canExecute;
    }

    // Method to set execute permission
    public void setExecutePermission(boolean canExecute) {
        this.canExecute = canExecute;
    }
}