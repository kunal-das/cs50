<?php

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];

    // TODO: search database for places matching $_GET["geo"], store in $places
    
    if($_SERVER["REQUEST_METHOD"] == "GET")
    {
        //print if $GET[geo] is empty
        if(empty($_GET["geo"]))
        {
            //$_GET["geo"] is empty and is printed
            //echo("There is no location specified in the GET request.");
        }
        //the code in else block splits $_GET["get"] on ',' and retrieves the place name/postal code
        else
        {
            $get_request = $_GET["geo"];
            $get_parameters = explode(",", $get_request);
            print_r("<p>".print_r($get_parameters)."</p>");
            //NOTE : the variable $place_name can contain both the name of the place or the postal code.
            $place_name = $get_parameters[0];
            print("<p>{$place_name}</p>");
            //$places = CS50::query("SELECT * FROM places WHERE MATCH(postal_code, place_name) AGAINST(?)", $place_name);
        }
    }
    

    // output places as JSON (pretty-printed for debugging convenience)
    //header("Content-type: application/json");
    //print(json_encode($places, JSON_PRETTY_PRINT));

?>