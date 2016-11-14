<?php
    //configuration
    require("../includes/config.php");
    
    $user_password = CS50::query("SELECT hash FROM users WHERE id = ?", $_SESSION["id"])[0]["hash"];
    
    //if user reached page via GET request(by clicking the link or by redirect method)
    if($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("password_change_form.php", ["title" => "Change Password"]);
    }
    //if user reaches the page via POST request(by submitting form to the page)
    else if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if(empty($_POST["current_password"]))
        {
            apologize("Please enter your current password");
        }
        if(empty($_POST["new_password"]))
        {
            apologize("Please enter the new password");
        }
        else if(empty($_POST["confirm_password"]))
        {
            apologize("Please re-enter the new password");
        }
        else if(!password_verify($_POST["current_password"], $user_password))
        {
            apologize("You're current password is incorrect");
        }
        else if($_POST["new_password"] != $_POST["confirm_password"])
        {
            apologize("Mismatch !!...Please re-type the new password");
        }
        
        CS50::query("UPDATE users SET hash = ? WHERE id = ?", password_hash($_POST["new_password"], PASSWORD_DEFAULT), $_SESSION["id"]);
        render("password_change_success.php", ["title" => "Password Changed Successfully"]);
    }
?>