<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy_view.php", ["title" => "Buy"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["stock_symbol"]))
        {
            apologize("You must provide a symbol.");
        }
        else if (empty($_POST["shares"]))
        {
            apologize("You must provide how many shares you want to buy.");
        }
        else if(preg_match("/^\d+$/", $_POST["shares"]) == 0)
        {
            apologize("You must provide a non-negative number");
        }
        
        $stock = lookup($_POST["stock_symbol"]);
        $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"])[0]["cash"];
        if(($_POST["shares"]*$stock["price"]) > $cash)
        {
            apologize("Sorry !!...You can't buy this many stocks.");
        }
        else if(($_POST["shares"]*$stock["price"]) <= $cash)
        {
            $cash = $cash - ($_POST["shares"]*$stock["price"]);
            CS50::query("UPDATE users SET cash = ? WHERE id = ?", $cash, $_SESSION["id"]);
            CS50::query("INSERT INTO portfolio (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], strtoupper($_POST["stock_symbol"]), $_POST["shares"]);
            redirect("/");
        }
    }

?>
