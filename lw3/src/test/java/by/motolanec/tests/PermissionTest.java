package by.motolanec.tests;

import by.motolanec.filesystem.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class PermissionTest {
    private User user;
    private File file;
    private Permission permission;

    @BeforeEach
    void setUp() {
        user = new RegularUser("testUser", "password");
        file = new TextFile("testFile", 100, user, "content");
        permission = new Permission(user, file, true, false, true);
    }

    @Test
    void getUserReturnsCorrectUser() {
        assertEquals(user, permission.getUser());
    }

    @Test
    void setUserUpdatesUser() {
        User newUser = new RegularUser("testUser", "password");
        permission.setUser(newUser);
        assertEquals(newUser, permission.getUser());
    }

    @Test
    void getFileReturnsCorrectFile() {
        assertEquals(file, permission.getFile());
    }

    @Test
    void setFileUpdatesFile() {
        File newFile = new TextFile("testFile", 100, user, "content");
        permission.setFile(newFile);
        assertEquals(newFile, permission.getFile());
    }

    @Test
    void canReadReturnsTrueWhenReadPermissionIsGranted() {
        assertTrue(permission.canRead());
    }

    @Test
    void canReadReturnsFalseWhenReadPermissionIsRevoked() {
        permission.setReadPermission(false);
        assertFalse(permission.canRead());
    }

    @Test
    void canWriteReturnsFalseWhenWritePermissionIsNotGranted() {
        assertFalse(permission.canWrite());
    }

    @Test
    void canWriteReturnsTrueWhenWritePermissionIsGranted() {
        permission.setWritePermission(true);
        assertTrue(permission.canWrite());
    }

    @Test
    void canExecuteReturnsTrueWhenExecutePermissionIsGranted() {
        assertTrue(permission.canExecute());
    }

    @Test
    void canExecuteReturnsFalseWhenExecutePermissionIsRevoked() {
        permission.setExecutePermission(false);
        assertFalse(permission.canExecute());
    }
}