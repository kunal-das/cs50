<?php
    
    //configuration
    require("../includes/config.php");
    
    //if user reached page via GET request by clicking link or redirect method
    if($_SERVER["REQUEST_METHOD"] == "GET")
    {
        //render the view of the page
        render("add_cash_view.php", ["title" => "Add Cash"]);
    }
    //if user reached page via POST request by submitting a form
    else if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        //check if the amount field is empty
        if(empty($_POST["amount"]))
        {
            apologize("You must enter some cash amount");
        }
        
        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $_POST["amount"], $_SESSION["id"]);
        redirect("/");
    }
?>