#include "gtest/gtest.h"
#include "auth_service.h" // Include the authentication service header

class LoginTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Set up any required resources before each test
    }

    void TearDown() override {
        // Clean up resources after each test
    }
};

TEST_F(LoginTest, SuccessfulLogin) {
    AuthService auth;
    bool result = auth.login("valid_user", "valid_password");
    EXPECT_TRUE(result);
}

TEST_F(LoginTest, FailedLoginInvalidPassword) {
    AuthService auth;
    bool result = auth.login("valid_user", "invalid_password");
    EXPECT_FALSE(result);
}

TEST_F(LoginTest, FailedLoginInvalidUser) {
    AuthService auth;
    bool result = auth.login("invalid_user", "valid_password");
    EXPECT_FALSE(result);
}

TEST_F(LoginTest, EmptyCredentials) {
    AuthService auth;
    bool result = auth.login("", "");
    EXPECT_FALSE(result);
}