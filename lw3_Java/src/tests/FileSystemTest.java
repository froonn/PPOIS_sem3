package tests;

import main.*;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class FileSystemTest {
    private FileSystem fileSystem;
    private User user;
    private Directory directory;

    @BeforeEach
    void setUp() {
        fileSystem = new FileSystem();
        user = new RegularUser("testUser", "password");
        directory = new Directory("testDirectory");
    }

    @Test
    void addDirectoryAddsDirectoryToFileSystem() {
        fileSystem.addDirectory(directory);
        assertTrue(fileSystem.getDirectories().contains(directory));
    }

    @Test
    void removeDirectoryRemovesDirectoryFromFileSystem() {
        fileSystem.addDirectory(directory);
        fileSystem.removeDirectory(directory);
        assertFalse(fileSystem.getDirectories().contains(directory));
    }

    @Test
    void addUserAddsUserToFileSystem() {
        fileSystem.addUser(user);
        assertTrue(fileSystem.getUsers().contains(user));
    }

    @Test
    void removeUserRemovesUserFromFileSystem() {
        fileSystem.addUser(user);
        fileSystem.removeUser(user);
        assertFalse(fileSystem.getUsers().contains(user));
    }

    @Test
    void findDirectoryByNameReturnsCorrectDirectory() {
        fileSystem.addDirectory(directory);
        assertEquals(directory, fileSystem.findDirectoryByName("testDirectory"));
    }

    @Test
    void findDirectoryByNameReturnsNullForNonExistentDirectory() {
        assertNull(fileSystem.findDirectoryByName("nonExistentDirectory"));
    }

    @Test
    void findUserByNameReturnsCorrectUser() {
        fileSystem.addUser(user);
        assertEquals(user, fileSystem.findUserByName("testUser"));
    }

    @Test
    void findUserByNameReturnsNullForNonExistentUser() {
        assertNull(fileSystem.findUserByName("nonExistentUser"));
    }
}