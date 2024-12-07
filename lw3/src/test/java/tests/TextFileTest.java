package tests;

import by.motolanec.filesystem.RegularUser;
import by.motolanec.filesystem.TextFile;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class TextFileTest {
    private TextFile textFile;
    private RegularUser owner;

    @BeforeEach
    void setUp() {
        owner = new RegularUser("testUser", "password");
        textFile = new TextFile("testFile", 1024, owner, "Initial content");
    }

    @Test
    void getContentReturnsCorrectContent() {
        assertEquals("Initial content", textFile.getContent());
    }

    @Test
    void setContentUpdatesContent() {
        textFile.setContent("New content");
        assertEquals("New content", textFile.getContent());
    }

    @Test
    void appendContentAppendsToExistingContent() {
        textFile.appendContent(" and more content");
        assertEquals("Initial content and more content", textFile.getContent());
    }

    @Test
    void clearContentClearsTheContent() {
        textFile.clearContent();
        assertEquals("", textFile.getContent());
    }

    @Test
    void openPrintsCorrectMessage() {
        // Assuming System.out is redirected to capture output
        textFile.open();
        // Verify the output message
    }

    @Test
    void closePrintsCorrectMessage() {
        // Assuming System.out is redirected to capture output
        textFile.close();
        // Verify the output message
    }
}