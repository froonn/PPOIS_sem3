package by.motolanec.filesystem;

import java.util.ArrayList;
import java.util.List;

public class Directory {
    private String name;
    private List<File> files;
    private List<Directory> subDirectories;

    public Directory(String name) {
        this.name = name;
        this.files = new ArrayList<>();
        this.subDirectories = new ArrayList<>();
    }

    // Method to get the name of the directory
    public String getName() {
        return name;
    }

    // Method to set the name of the directory
    public void setName(String name) {
        this.name = name;
    }

    // Method to add a file to the directory
    public void addFile(File file) {
        files.add(file);
    }

    // Method to remove a file from the directory
    public void removeFile(File file) {
        files.remove(file);
    }

    // Method to get the list of files in the directory
    public List<File> getFiles() {
        return files;
    }

    // Method to add a subdirectory to the directory
    public void addSubDirectory(Directory subDirectory) {
        subDirectories.add(subDirectory);
    }

    // Method to remove a subdirectory from the directory
    public void removeSubDirectory(Directory subDirectory) {
        subDirectories.remove(subDirectory);
    }

    // Method to get the list of subdirectories in the directory
    public List<Directory> getSubDirectories() {
        return subDirectories;
    }
}