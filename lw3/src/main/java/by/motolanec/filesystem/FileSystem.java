package by.motolanec.filesystem;

import java.util.ArrayList;
import java.util.List;

public class FileSystem {
    private List<Directory> directories;
    private List<User> users;

    public FileSystem() {
        this.directories = new ArrayList<>();
        this.users = new ArrayList<>();
    }

    // Method to add a directory to the file system
    public void addDirectory(Directory directory) {
        directories.add(directory);
    }

    // Method to remove a directory from the file system
    public void removeDirectory(Directory directory) {
        directories.remove(directory);
    }

    // Method to get the list of directories in the file system
    public List<Directory> getDirectories() {
        return directories;
    }

    // Method to add a user to the file system
    public void addUser(User user) {
        users.add(user);
    }

    // Method to remove a user from the file system
    public void removeUser(User user) {
        users.remove(user);
    }

    // Method to get the list of users in the file system
    public List<User> getUsers() {
        return users;
    }

    // Method to find a directory by name
    public Directory findDirectoryByName(String name) {
        for (Directory directory : directories) {
            if (directory.getName().equals(name)) {
                return directory;
            }
        }
        return null;
    }

    // Method to find a user by name
    public User findUserByName(String name) {
        for (User user : users) {
            if (user.getUsername().equals(name)) {
                return user;
            }
        }
        return null;
    }
}