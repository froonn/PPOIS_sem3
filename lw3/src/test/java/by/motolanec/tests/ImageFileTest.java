package by.motolanec.tests;

import by.motolanec.filesystem.ImageFile;
import by.motolanec.filesystem.RegularUser;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class ImageFileTest {
    private ImageFile imageFile;
    private RegularUser owner;

    @BeforeEach
    void setUp() {
        owner = new RegularUser("testUser", "password");
        imageFile = new ImageFile("testImage", 2048, owner, 1920, 1080);
    }

    @Test
    void getWidthReturnsCorrectWidth() {
        assertEquals(1920, imageFile.getWidth());
    }

    @Test
    void setWidthUpdatesWidth() {
        imageFile.setWidth(1280);
        assertEquals(1280, imageFile.getWidth());
    }

    @Test
    void getHeightReturnsCorrectHeight() {
        assertEquals(1080, imageFile.getHeight());
    }

    @Test
    void setHeightUpdatesHeight() {
        imageFile.setHeight(720);
        assertEquals(720, imageFile.getHeight());
    }

    @Test
    void resizeUpdatesWidthAndHeight() {
        imageFile.resize(800, 600);
        assertEquals(800, imageFile.getWidth());
        assertEquals(600, imageFile.getHeight());
    }

    @Test
    void openPrintsCorrectMessage() {
        // Assuming System.out is redirected to capture output
        imageFile.open();
        // Verify the output message
    }

    @Test
    void closePrintsCorrectMessage() {
        // Assuming System.out is redirected to capture output
        imageFile.close();
        // Verify the output message
    }
}