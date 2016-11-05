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
        render("sell_view.php", ["title" => "Quote", "holdings" => $holdings]);
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

        
        //render("quote_price.php", ["title"=>"Quote Price", "quote"=>$quote_lookup]);
    }

?>
