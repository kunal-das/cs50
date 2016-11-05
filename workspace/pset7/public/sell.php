<?php

    // configuration
    require("../includes/config.php"); 

    $holdings=[];
    $rows= CS50::query("SELECT symbol FROM portfolio WHERE user_id= ?", $_SESSION["id"]);
    //dump($rows);
    foreach($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if($stock != false)
        {
            $holdings[] = [
            "name" => $stock["name"],
            "price" => $stock["price"],
            "symbol" => $row["symbol"],
            ];
        }
        
    }

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("sell_view.php", ["title" => "Sell", "holdings" => $holdings]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        //dump($_POST);
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide select a stock to sell.");
        }
        else
        {
            $symbols = $_POST["symbol"];
            
            foreach($symbols as $symbol)
            {
                $shares = CS50::query("SELECT shares FROM portfolio WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $symbol);
                $shares = $shares[0]["shares"];
                $stock_price = lookup($symbol)["price"];
                $returns = $shares * $stock_price;
                $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"])[0]["cash"];
                CS50::query("UPDATE users SET cash = ? WHERE id = ?", ($cash+$returns), $_SESSION["id"]);
                CS50::query("DELETE FROM portfolio WHERE user_id=? AND symbol=?", $_SESSION["id"], $symbol);
            }
        }
        redirect("/");
    }

?>
