<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["username"]))
        {
            apologize("You must provide your username.");
        }
        else if (empty($_POST["password"]))
        {
            apologize("You must provide your password.");
        }
        else if(empty($_POST["confirmation"]))
        {
            apologize("You must retype your password");
        }
        else if(empty($_POST["email"]))
        {
            apologize("Please enter a valid email address");
        }
        else if($_POST["password"] != $_POST["confirmation"])
        {
            apologize("Password Mismatch !!...You must type the same password in both the password fields");
        }

        // query database for user
        $rows = CS50::query("INSERT IGNORE INTO users (username, hash, cash, email) VALUES(?, ?, 10000.00, ?)", $_POST["username"], password_hash($_POST["password"], PASSWORD_DEFAULT), $_POST["email"]);
        
        // Check if the insertion worked correctly, only 1 row should be added and 1 should be returned.
        if ($rows == 1)
        {
            $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
            $ID = $rows[0]["id"];
            $_SESSION["id"] = $ID;
            //call render to show "Successfull registration" page to the user.   
            render("register_success.php", ["title" => "Registration Successfull"]);    
        }
        else if ($rows == false)
        {
            apologize("Username already exists !!...Please enter some other username.");
        }
        else
        {
            apologize("Sorry...An unknown error occurred");
        }
    }

?>
