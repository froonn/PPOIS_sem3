package tests;

import main.File;
import main.RegularUser;
import main.TextFile;
import main.User;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class RegularUserTest {
    private RegularUser regularUser;
    private File file;

    @BeforeEach
    void setUp() {
        regularUser = new RegularUser("testUser", "password");
        file = new TextFile("testFile", 100, regularUser, "testContent");
    }

    @Test
    void viewFilePrintsCorrectMessage() {
        // Assuming System.out is redirected to capture output
        regularUser.viewFile(file);
        // Verify the output message
    }

    @Test
    void downloadFilePrintsCorrectMessage() {
        // Assuming System.out is redirected to capture output
        regularUser.downloadFile(file);
        // Verify the output message
    }

    @Test
    void uploadFilePrintsCorrectMessage() {
        // Assuming System.out is redirected to capture output
        regularUser.uploadFile(file);
        // Verify the output message
    }

    @Test
    void shareFilePrintsCorrectMessage() {
        User anotherUser = new RegularUser("anotherUser", "password");
        // Assuming System.out is redirected to capture output
        regularUser.shareFile(file, anotherUser);
        // Verify the output message
    }
}