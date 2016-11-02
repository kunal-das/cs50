<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "Quote"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["quote_symbol"]))
        {
            apologize("You must provide a symbol.");
        }

        $quote_lookup = lookup($_POST["quote_symbol"]);
        dump($quote_lookup);
        //render("quote_price.php", ["title"=>"Quote Price", "quote"=>$quote_lookup]);
    }

?>
