package by.motolanec.tests;

import by.motolanec.filesystem.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class DirectoryTest {
    private User user;
    private Directory directory;
    private File file;
    private Directory subDirectory;

    @BeforeEach
    void setUp() {
        user = new RegularUser("testUser", "password");
        directory = new Directory("testDirectory");
        file = new TextFile("testFile", 100, user, "content");
        subDirectory = new Directory("subDirectory");
    }

    @Test
    void getNameReturnsCorrectName() {
        assertEquals("testDirectory", directory.getName());
    }

    @Test
    void setNameUpdatesName() {
        directory.setName("newName");
        assertEquals("newName", directory.getName());
    }

    @Test
    void addFileAddsFileToDirectory() {
        directory.addFile(file);
        assertTrue(directory.getFiles().contains(file));
    }

    @Test
    void removeFileRemovesFileFromDirectory() {
        directory.addFile(file);
        directory.removeFile(file);
        assertFalse(directory.getFiles().contains(file));
    }

    @Test
    void getFilesReturnsCorrectFiles() {
        directory.addFile(file);
        assertEquals(1, directory.getFiles().size());
        assertTrue(directory.getFiles().contains(file));
    }

    @Test
    void addSubDirectoryAddsSubDirectoryToDirectory() {
        directory.addSubDirectory(subDirectory);
        assertTrue(directory.getSubDirectories().contains(subDirectory));
    }

    @Test
    void removeSubDirectoryRemovesSubDirectoryFromDirectory() {
        directory.addSubDirectory(subDirectory);
        directory.removeSubDirectory(subDirectory);
        assertFalse(directory.getSubDirectories().contains(subDirectory));
    }

    @Test
    void getSubDirectoriesReturnsCorrectSubDirectories() {
        directory.addSubDirectory(subDirectory);
        assertEquals(1, directory.getSubDirectories().size());
        assertTrue(directory.getSubDirectories().contains(subDirectory));
    }
}