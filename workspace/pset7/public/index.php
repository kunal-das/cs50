<?php

    // configuration
    require("../includes/config.php"); 

    $holdings=[];
    $rows= CS50::query("SELECT * FROM portfolio WHERE user_id= ?", $_SESSION["id"]);
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
            "shares" => $row["shares"]
            ];
        }
        
    }
    //dump($holdings);
    
    //Getting the balance cash from the user
    $user= CS50::query("SELECT * from users WHERE id = ?", $_SESSION["id"]);
    $cash = $user[0]["cash"];
    
    //dump($cash);
    //render portfolio
    render("portfolio.php", ["title" => "Portfolio", "holdings" => $holdings, "cash" => $cash]);

?>
