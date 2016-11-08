<?php
    require("../includes/config.php");
    
    $rows = CS50::query("SELECT * FROM history WHERE user_id = ?", $_SESSION["id"]);
    $user_history = [];
    foreach($rows as $row)
    {
       $user_history[] =  [
           "transaction" => $row["transaction"],
           "symbol" => $row["symbol"],
           "shares" => $row["shares"],
           "price" => $row["price"],
           "time" => $row["time"]
           ];
    }
    dump($user_history);
?>