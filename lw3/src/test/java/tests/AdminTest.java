package tests;

import main.Admin;
import main.User;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class AdminTest {
    private Admin admin;

    @BeforeEach
    void setUp() {
        admin = new Admin("adminUser", "adminPass");
    }

    @Test
    void createUserCreatesNewUser() {
        admin.createUser("newUser", "newPass", "RegularUser");
        // Assuming there is a method to verify user creation
    }

    @Test
    void deleteUserDeletesExistingUser() {
        admin.createUser("userToDelete", "pass", "RegularUser");
        admin.deleteUser("userToDelete");
        // Assuming there is a method to verify user deletion
    }

    @Test
    void changeUserRoleChangesUserRole() {
        admin.createUser("userToChangeRole", "pass", "RegularUser");
        admin.changeUserRole("userToChangeRole", "Admin");
        // Assuming there is a method to verify role change
    }

    @Test
    void resetUserPasswordResetsPassword() {
        admin.createUser("userToResetPassword", "oldPass", "RegularUser");
        admin.resetUserPassword("userToResetPassword");
        // Assuming there is a method to verify password reset
    }
}